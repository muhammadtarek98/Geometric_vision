#include "Vertex.hpp"
namespace GeometricVision::DCEL
{
    template<class type,size_t dim>
    Vertex<type,dim>::Vertex(const vector::Vector<type,dim>&point,
                             const std::weak_ptr<Edge<type,dim>>&edge):point(point),edge(edge){};

    template <class type, size_t dim>
    Vertex<type,dim>::Vertex()    {
        for (int i=0;i<dim;i++)
        {
            this->point.assign(i,INFINITY);
        }
    }
    template <class type, size_t dim>
    vector::Vector<type, dim> Vertex<type, dim>::get_point()
    {
        return this->point;
    }
    template <class type, size_t dim>
    std::weak_ptr<Edge<type, dim>>Vertex<type, dim>::get_edge()
    {
        return this->edge;
    }
    template<class type,size_t dim>
    Vertex<type,dim>::Vertex(const vector::Vector<type,dim>point,
                             const std::weak_ptr<Edge<type,dim>>&edge):point(point),edge(edge){};
    template<class Type,size_t Dim>
    Vertex<Type, Dim>::Vertex(const vector::Vector<Type, Dim>&& point,
                              const std::weak_ptr<Edge<Type, Dim>> &edge) : point(std::move(point)), edge(edge)
    {
    };

    template class Vertex<double, DIM3>;
    template class Vertex<double, DIM2>;
    template class Vertex<float, DIM3>;
    template class Vertex<float, DIM2>;
}
