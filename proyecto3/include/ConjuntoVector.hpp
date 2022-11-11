#ifndef CONJUNTOVECTOR_HPP
#define CONJUNTOVECTOR_HPP
#include "IConjunto.hpp"
#include <vector>
#include <algorithm>
template <typename T>
class ConjuntoVector : public IConjunto<T>
{
private:
    std::vector<T> elementos;

public:
    void insertar(const T &elemento)
    {
        if (!pertenece(elemento))
        {
            elementos.push_back(elemento);
        }
    }
    void eliminar(const T &elemento)
    {
        auto it= std::find(elementos.begin(), elementos.end(),elemento);
        if (it != elementos.end())
        {
            elementos.erase(it);
        }
        
        /*
        for (auto it = elementos.begin(); it != elementos.end(); ++it)
        {
            if (*it == elemento)
            {
                elementos.erase(it);
                break;
            }
        }*/

    }
    bool pertenece(const T &elemento) const
    {
        auto it= std::find(elementos.begin(), elementos.end(),elemento);
        if(it != elementos.end()){
            return true;
        }
        return false;
        /*
        for (const auto &e : elementos)
        {
            if (e == elemento)
            {
                return true;
            }
        }
        return false;
        */
        
    }
};
#endif