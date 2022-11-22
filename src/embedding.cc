#include <embedding.hh>
#include <math.h>
float Embedding::dot_product(const Embedding &other) const
{
    // TODO: Implementar
    // El producto punto entre dos vectores es la suma de los productos de los elementos
    // en la misma posición.
    // Ejemplo:
    // [1, 2, 3] . [4, 5, 6] = 1*4 + 2*5 + 3*6 = 32
    float product = 0.0;
    for (size_t i = 0; i < this->embedding.size(); i++)
    {
        product += this->embedding[i] * other.embedding[i];
    }
    return product;
}

float Embedding::norm() const
{
    // TODO: Implementar
    // La norma de un vector es la raíz cuadrada de la suma de los cuadrados de sus eleme
    // Ejemplo:
    // ||[1, 2, 3]|| = sqrt(1^2 + 2^2 + 3^2) = sqrt(14) = 3.7416573867739413
    // Noten que la norma de un vector es la raiz cuadrada de su producto punto consigo m
    float norm = this->dot_product(*this);
    return sqrt(norm);
}

float Embedding::cosine_similarity(const Embedding &other) const
{
    // TODO: Implementar
    // Cuando usamos word embeddings queremos comparar la similitud entre palabras.
    // Una forma de hacerlo es usando el coseno del ángulo entre los vectores:
    // si la similitud de coseno es 1 entonces el ángulo es el mismo y si es -1
    // entonces el ángulo es opuesto.
    //
    // La fórmula de la similitud de coseno es:
    // cos(theta) = (A . B) / (||A|| * ||B||)
    // Tips:
    // - Usen la función dot_product para calcular el producto punto entre los vectores.
    // - Usen la función norm para calcular la norma de los vectores.
    // - this es un puntero a la instancia actual de la clase, por lo que para acceder a
    // métodos de la clase se usa this->método().
    // - other se pasa como referencia, por lo que se accede a sus métodos con other.método
    float product = this->dot_product(other);
    float multNorm = this->norm() * other.norm();
    return product / multNorm;
}