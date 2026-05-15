#include "Edge.hpp"
namespace GeometricVision::DCEL
{
    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge()
    {
        this->id=0;
    }

    template <class dtype, size_t dim>
    Edge<dtype, dim>::Edge( vertex_weak_ptr<dtype,dim>origin,  edge_weak_ptr<dtype,dim> twin,
                           edge_weak_ptr<dtype,dim> next,  edge_weak_ptr<dtype,dim> prev, face_weak_ptr<dtype,dim> face):origin(origin),
        twin(twin),next(next),prev(prev),face(face)
    {
        ++(this->id);
    }
    template <class dtype, size_t dim>
    Edge<dtype, dim>::Edge(const vertex_weak_ptr<dtype,dim>&origin,
                          const edge_weak_ptr<dtype,dim>&twin, const edge_weak_ptr<dtype,dim>& next,
                          const edge_weak_ptr<dtype,dim> &prev,const face_weak_ptr<dtype,dim>& face) : origin(origin),
        twin(twin),next(next),prev(prev),face(face)
    {
        ++(this->id);
    }

    template <class dtype, size_t dim>
    Edge<dtype, dim>::Edge(vertex_weak_ptr<dtype,dim>origin):origin(origin)
    {
        ++(this->id);
    }
    template <class dtype, size_t dim>
    Edge<dtype, dim>::Edge(const vertex_weak_ptr<dtype,dim>&origin):origin(origin)
    {
        ++(this->id);
    }

    template <class dtype, size_t dim>
    vertex_weak_ptr<dtype,dim>Edge<dtype, dim>::get_destination()
    {
        return this->get_twin();
    }

    template <class dtype, size_t dim>
    vertex_weak_ptr<dtype,dim>Edge<dtype, dim>::get_prev()
    {
        if (auto p = this->prev.lock()) return p->origin;
        return vertex_weak_ptr<dtype,dim>();
    }

    template <class dtype, size_t dim>
    vertex_weak_ptr<dtype,dim>Edge<dtype, dim>::get_twin()
    {
        if (auto t = this->twin.lock()) return t->origin;
        return vertex_weak_ptr<dtype,dim>();
    }

    template <class dtype, size_t dim>
    vertex_weak_ptr<dtype,dim>Edge<dtype, dim>::get_next()
    {
        if (auto n = this->next.lock()) return n->origin;
        return vertex_weak_ptr<dtype, dim>();
    }

    template class Edge<double, DIM3>;
    template class Edge<double, DIM2>;
    template class Edge<float, DIM3>;
    template class Edge<float, DIM2>;
}
