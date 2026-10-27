#include "Edge.hpp"
namespace GeometricVision::DCEL
{
    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge()
    {
        this->id=0;
    }

    template <class dtype, size_t dim>
    Edge<dtype, dim>::Edge(vertex_weak_ptr<dtype,dim>origin,  edge_weak_ptr<dtype,dim> twin,
                           edge_weak_ptr<dtype,dim> next,  edge_weak_ptr<dtype,dim> prev, face_weak_ptr<dtype,dim> face) :
        origin(origin),
        twin(twin), next(next), prev(prev), face(face), id(0)
    {
        ++id;
    }

    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge(const vertex_shared_ptr<dtype,dim>&origin,
     const edge_shared_ptr<dtype,dim>&twin,
      edge_weak_ptr<dtype,dim>next,
      edge_weak_ptr<dtype,dim>prev,
      face_weak_ptr<dtype,dim>face):origin(origin),twin(twin),next(next),prev(prev),face(face)
    {
        ++(this->id);
    }
    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge(const vertex_shared_ptr<dtype,dim>&origin,
                 const edge_shared_ptr<dtype,dim>&twin,
                 const edge_shared_ptr<dtype,dim>&next,
                 const edge_shared_ptr<dtype,dim>&prev,
                 const face_shared_ptr<dtype,dim>&face):origin(origin),twin(twin),next(next),prev(prev),face(face)
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
    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge(const vertex_weak_ptr<dtype,dim>&origin,
                 const edge_weak_ptr<dtype,dim>&twin,
                  edge_weak_ptr<dtype,dim>next,
                  edge_weak_ptr<dtype,dim>prev,
                  face_weak_ptr<dtype,dim>face):origin(origin),twin(twin),next(next),prev(prev),face(face)
    {
        ++(this->id);
    }
    template <class dtype, size_t dim>
    Edge<dtype, dim>::Edge(vertex_shared_ptr<dtype,dim>origin):origin(origin)
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
    edge_weak_ptr<dtype,dim>Edge<dtype, dim>::get_destination()
    {
        return this->get_twin();
    }

    template <class dtype, size_t dim>
    edge_weak_ptr<dtype,dim>Edge<dtype, dim>::get_prev()
    {
        if (auto p = this->prev.lock()) return this->prev;
        return edge_weak_ptr<dtype,dim>();
    }
    template <class dtype, size_t dim>
    vertex_weak_ptr<dtype,dim>Edge<dtype,dim>::get_point()
    {
        return this->origin;
    }

    template <class dtype, size_t dim>
    edge_weak_ptr<dtype,dim>Edge<dtype, dim>::get_twin()
    {
        if (auto t = this->twin.lock()) return this->twin;
        return edge_weak_ptr<dtype,dim>();
    }

    template <class dtype, size_t dim>
    edge_weak_ptr<dtype,dim>Edge<dtype, dim>::get_next()
    {
        if (auto n = this->next.lock()) return this->next;
        return edge_weak_ptr<dtype, dim>();
    }
    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge(vertex_shared_ptr<dtype,dim>&&origin,edge_shared_ptr<dtype,dim>&&twin,
        edge_shared_ptr<dtype,dim>&&next,edge_shared_ptr<dtype,dim>&&prev, face_shared_ptr<dtype,dim>&&face)
    {
        this->origin=std::move(origin);
        this->next=std::move(next);
        this->twin=std::move(twin);
        this->face=std::move(face);
        this->prev=std::move(prev);

    }
    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge(vertex_weak_ptr<dtype,dim>&&origin)noexcept
    {
        this->origin = std::move(origin);
        ++id;
    }
    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge(const Edge &e)
    {
        this->face=e.face;
        this->id=e.id;
        this->origin=e.origin;
        this->twin=e.twin;
        this->next=e.next;
        this->prev=e.prev;
    }
    template<class dtype,size_t dim>
    Edge<dtype,dim>::Edge(Edge&&e)noexcept
    {
        this->face=std::move(e.face);
        this->id=e.id;
        this->origin=std::move(e.origin);
        this->twin=std::move(e.twin);
        this->next=std::move(e.next);
        this->prev=std::move(e.prev);
    }
    template<class dtype,size_t dim>
    Edge<dtype,dim>& Edge<dtype,dim>::operator=(const Edge&e)
    {
        if (this!=&e)
        {
            this->face=e.face;
            this->id=e.id;
            this->origin=e.origin;
            this->twin=e.twin;
            this->next=e.next;
            this->prev=e.prev;
        }
            return *this;
    }
    template<class dtype,size_t dim>
    Edge<dtype,dim>& Edge<dtype,dim>::operator=(Edge&&e)noexcept
    {
        if (this!=&e)
        {
            this->face=std::move(e.face);
            this->id=e.id;
            this->origin=std::move(e.origin);
            this->twin=std::move(e.twin);
            this->next=std::move(e.next);
            this->prev=std::move(e.prev);
        }
        return *this;

    }


    template class Edge<double, DIM3>;
    template class Edge<double, DIM2>;
    template class Edge<float, DIM3>;
    template class Edge<float, DIM2>;
}
