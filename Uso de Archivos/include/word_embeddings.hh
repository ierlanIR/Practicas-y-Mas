#ifndef WORD_EMBEDDINGS_HH
#define WORD_EMBEDDINGS_HH
#include <string>
#include <unordered_map>
#include <vector>
#include <iterator>
#include <embedding.hh>
#include <algorithm>

class WordEmbeddings
{
public:
    WordEmbeddings(const std::string &filename);
    // Returns the embedding for a given word.
    const Embedding &Get(const std::string &word) const;
    // Returns the embedding for the unknown word.
    const bool IsUnknown(Embedding &) const;
    // Returns the dimensionality of the embeddings.
    int Dim() const;
    // Returns the number of words in the vocabulary.
    int NumWords() const;
    // Get similar words
    std::vector<std::string> GetSimilarWords(const std::string &word, size_t n) const;

private:
    int dim;
    int num_words;
    std::unordered_map<std::string, Embedding> embeddings;
    Embedding unknown;
};
#endif // WORD_EMBEDDINGS_HH