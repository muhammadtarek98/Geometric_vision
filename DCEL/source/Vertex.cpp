#include "Vertex.hpp"
namespace GeometricVision::DCEL
{
    template<class dtype,size_t dim>
    Vertex<dtype,dim>::Vertex(const vector::Vector<dtype,dim>&point,
                             const edge_weak_ptr<dtype,dim>&edge):point(point),edge(edge){};

    template <class dtype, size_t dim>
    Vertex<dtype,dim>::Vertex()    {
        for (int i=0;i<dim;i++)
        {
            this->point.assign(i,INFINITY);
        }
    }
    template <class dtype, size_t dim>
    vector::Vector<dtype, dim> Vertex<dtype, dim>::get_point()
    {
        return this->point;
    }
    template <class dtype, size_t dim>
    edge_weak_ptr<dtype,dim>Vertex<dtype, dim>::get_edge()
    {
        return this->edge;
    }
    template<class dtype,size_t dim>
    Vertex<dtype,dim>::Vertex(const vector::Vector<dtype,dim>point,
                             const edge_weak_ptr<dtype,dim>&edge):point(point),edge(edge){};
    template<class dtype,size_t dim>
    Vertex<dtype, dim>::Vertex(const vector::Vector<dtype, dim>&& point,
                              const edge_weak_ptr<dtype,dim> &edge) : point(std::move(point)), edge(edge)
    {
    };

    template class Vertex<double, DIM3>;
    template class Vertex<double, DIM2>;
    template class Vertex<float, DIM3>;
    template class Vertex<float, DIM2>;
}
