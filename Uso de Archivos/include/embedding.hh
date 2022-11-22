#ifndef EMBEDDING_HH
#define EMBEDDING_HH
#include <vector>
class Embedding
{
protected:
    std::vector<float> embedding;

public:
    Embedding() = default;
    Embedding(std::vector<float> &embedding) : embedding(embedding) {}
    float dot_product(const Embedding &other) const;
    float norm() const;
    float cosine_similarity(const Embedding &other) const;
};
#endif // EMBEDDING_HH