#include "Edge.h"

namespace DCEL
{
    template<class type,size_t dim>
    Edge<type,dim>::Edge()
    {
        this->id=0;
    }

    template <class type, size_t dim>
    Edge<type, dim>::Edge( std::weak_ptr<Vertex<type, dim>>origin,  std::weak_ptr<Edge> twin,
         std::weak_ptr<Edge> next,  std::weak_ptr<Edge> prev, std::weak_ptr<Face<type,dim>> face):origin(origin),
    twin(twin),next(next),prev(prev),face(face)
    {
        ++(this->id);
    }
    template <class type, size_t dim>
 Edge<type, dim>::Edge(const std::weak_ptr<Vertex<type, dim>>&origin,
     const std::weak_ptr<Edge> &twin, const std::weak_ptr<Edge>& next,
     const std::weak_ptr<Edge>& prev,const std::weak_ptr<Face<type, dim>>& face) : origin(origin),
                                                    twin(twin),next(next),prev(prev),face(face)
    {
        ++(this->id);
    }

    template <class type, size_t dim>
    Edge<type, dim>::Edge(std::weak_ptr<Vertex<type, dim>>origin):origin(origin)
    {
        ++(this->id);
    }
    template <class type, size_t dim>
    Edge<type, dim>::Edge(const std::weak_ptr<Vertex<type, dim>>&origin):origin(origin)
    {
        ++(this->id);
    }

    template <class type, size_t dim>
    std::weak_ptr<Vertex<type, dim>> Edge<type, dim>::get_destination()
    {
        return this->get_twin();
    }

    template <class type, size_t dim>
    std::weak_ptr<Vertex<type, dim>> Edge<type, dim>::get_prev()
    {
        if (auto p = this->prev.lock()) return p->origin;
        return std::weak_ptr<Vertex<type, dim>>();
    }

    template <class type, size_t dim>
    std::weak_ptr<Vertex<type, dim>> Edge<type, dim>::get_twin()
    {
        if (auto t = this->twin.lock()) return t->origin;
        return std::weak_ptr<Vertex<type, dim>>();
    }

    template <class type, size_t dim>
    std::weak_ptr<Vertex<type, dim>> Edge<type, dim>::get_next()
    {
        if (auto n = this->next.lock()) return n->origin;
        return std::weak_ptr<Vertex<type, dim>>();
    }

    template class Edge<double, 3>;
    template class Edge<double, 2>;
    template class Edge<float, 3>;
    template class Edge<float, 2>;
} // DCEL