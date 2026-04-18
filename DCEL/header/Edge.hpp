#pragma once
#include "DCEL.hpp"
namespace GeometricVision::DCEL
{
    template<class type=float,size_t dim=DIM3>
    class Edge
    {
    private:
        std::weak_ptr<Vertex<type,dim>>origin;
        std::weak_ptr<Edge>twin;
        std::weak_ptr<Edge>next;
        std::weak_ptr<Edge>prev;
        std::weak_ptr<Face<type,dim>>face;
        int id;
    public:
        Edge();
        Edge(std::weak_ptr<Vertex<type,dim>>origin,
             std::weak_ptr<Edge>twin, std::weak_ptr<Edge>next, std::weak_ptr<Edge>prev,
             std::weak_ptr<Face<type,dim>>face);
        Edge(const std::weak_ptr<Vertex<type,dim>>&origin,
             const std::weak_ptr<Edge>&twin,
             const std::weak_ptr<Edge>&next,
             const std::weak_ptr<Edge>&prev,
             const std::weak_ptr<Face<type,dim>>&face);
        Edge( std::weak_ptr<Vertex<type,dim>>origin);
        Edge(const std::weak_ptr<Vertex<type,dim>>&origin);
        std::weak_ptr<Vertex<type,dim>>get_destination();
        std::weak_ptr<Vertex<type,dim>>get_next();
        std::weak_ptr<Vertex<type,dim>>get_prev();
        std::weak_ptr<Vertex<type,dim>>get_twin();
        virtual  ~Edge()=default;
    };
}
