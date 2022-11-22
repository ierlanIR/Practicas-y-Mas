#include <iostream>
#include <word_embeddings.hh>
#include <sstream>

int main()
{
    std::cout << "Diccionario de sinónimos" << std::endl;
    std::cout << "========================" << std::endl;
    std::cout << std::endl;
    // Cambien el path según el nombre de su archivo. Asegúrense que esté
    // descomprimido.
    WordEmbeddings word_embeddings("data/GoogleNews-vectors-negative300.bin");
    std::cout << "Número de palabras en el diccionario: "
              << word_embeddings.NumWords() << std::endl;
    std::cout << "Dimensión de los vectores de palabras: "
              << word_embeddings.Dim() << std::endl;
    bool continue_loop = true;
    while (continue_loop)
    {
        std::cout << "Ingrese una palabra: ";
        std::string user_line;
        std::getline(std::cin, user_line);
        if (user_line.empty())
        {
            continue_loop = false;
        }
        else
        {
            std::istringstream iss(user_line);
            std::string word;
            iss >> word;
            // Mostramos las 10 palabras más similares
            std::vector<std::string> similar_words = word_embeddings.GetSimilarWords(word, 10);
            if (similar_words.empty())
            {
                // Si la palabra no está en el diccionario, se muestra un mensaje de
                std::cout << "La palabra '" << word << "' no está en el diccionario" << std::endl;
            }
            else
            {
                std::cout << "Sinónimos de '" << word << "':" << std::endl;
                for (const std::string &similar : similar_words)
                {
                    std::cout << " " << similar << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }
}