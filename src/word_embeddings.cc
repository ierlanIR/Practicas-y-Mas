#include <embedding.hh>
#include <fstream>
#include <iostream>
#include <word_embeddings.hh>
// Loads the word embeddings from a file in binary format
WordEmbeddings::WordEmbeddings(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file " + filename);
    }
    // Read the number of words and the dimensionality
    file >> num_words >> dim;
    // Read the embeddings
    for (int i = 0; i < num_words; i++)
    {
        // Read the word, that is delimited by a space
        std::string word;
        char c;
        while (file.read(&c, sizeof(char)) && c != ' ')
        {
            word += c;
        }
        // Read the embedding
        std::vector<float> embedding(dim);
        // The next line only works if this program is executed in a little-endian
        // machine. If this is not the case, the embeddings will be read in the
        // wrong order.
        // Intel processors are little-endian, while ARM processors are
        file.read(reinterpret_cast<char *>(embedding.data()), dim * sizeof(float));
        // Store the embedding
        embeddings[word] = Embedding(embedding);
    }
}

// Returns the embedding for a given word.
const Embedding &WordEmbeddings::Get(const std::string &word) const
{
    auto it = embeddings.find(word);
    if (it == embeddings.end())
    {
        return unknown;
    }
    else
    {
        return it->second;
    }
}

// Determines if the embedding is unknown
const bool WordEmbeddings::IsUnknown(Embedding &embedding) const
{
    return &embedding == &unknown;
}

// Returns the dimensionality of the embeddings.
int WordEmbeddings::Dim() const
{
    return dim;
}

// Returns the number of words in the vocabulary.
int WordEmbeddings::NumWords() const
{
    return num_words;
}

// Get similar words
std::vector<std::string> WordEmbeddings::GetSimilarWords(
    const std::string &word,
    size_t n) const
{
    // Primero, buscamos el word embedding de la palabra, para evitar
    // buscarlo en cada iteración del bucle.
    Embedding embedding = Get(word);
    // Si el word embedding no está en el diccionario, devolvemos un vector vacío
    if (IsUnknown(embedding))
    {
        return std::vector<std::string>();
    }
    // Creamos una función de comparación de embeddings. Como vamos a usar
    // un max-heap queremos que los elementos menos similares estén en el
    // tope del heap.
    // Un max-heap es una estructura de datos que permite extraer rápidamente
    // el elemento con mayor valor.
    // Para lograrlo, necesitamos que la función de comparación devuelva
    // true si el primer elemento es más similar que el segundo. Es decir, es
    // un max-heap pero ordenado "al revés".
    auto comparison_function = [&embedding](
                                   const std::pair<std::string, Embedding> &a,
                                   const std::pair<std::string, Embedding> &b)
    {
        return embedding.cosine_similarity(a.second) >
               embedding.cosine_similarity(b.second);
    };
    std::vector<std::pair<std::string, Embedding>> similar_words;
    std::vector<std::string> similar_words_strings;
    // Usamos la función make_heap para crear un max-heap
    // en el vector similar_words.
    std::make_heap(similar_words.begin(), similar_words.end(),
                   comparison_function);
    // Iteramos sobre todos los embeddings del diccionario
    for (auto it = embeddings.begin(); it != embeddings.end(); it++)
    {
        // Si la palabra es la misma que la que estamos buscando, entonces la ignoramos
        if (it->first != word)
        {
            // Insertamos la palabra en el heap.
            similar_words.push_back(*it);
            std::push_heap(similar_words.begin(), similar_words.end(),
                           comparison_function);
            // Si el heap tiene más de n elementos, entonces sacamos el elemento
            // con menor similitud.
            if (similar_words.size() > n)
            {
                std::pop_heap(similar_words.begin(), similar_words.end(),
                              comparison_function);
                similar_words.pop_back();
            }
        }
    }
    // Ordenamos el heap de menos similar a más similar
    std::sort_heap(similar_words.begin(), similar_words.end(),
                   comparison_function);
    // Copiamos solamente las palabras a un vector de strings.
    // Noten que en este caso estamos iterando en reversa, pues las palabras
    // más similares quedaron al final.
    for (auto it = similar_words.rbegin(); it != similar_words.rend(); it++)
    {
        similar_words_strings.push_back(it->first);
    }
    return similar_words_strings;
}