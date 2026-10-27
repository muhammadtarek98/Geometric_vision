#pragma once
#include "Edge.hpp"
#include "vector.hpp"
namespace GeometricVision::DCEL
    {
        template<class dtype=float,size_t dim=DIM3>
        class Vertex
        {
        private:
            vector::Vector<dtype,dim> point;
            edge_weak_ptr<dtype,dim>edge;
        public:
            Vertex();
            Vertex(const Vertex&v);
            Vertex(Vertex&&v)noexcept;
            Vertex(const vector::Vector<dtype,dim>&point,
                const edge_weak_ptr<dtype,dim>&edge);
            Vertex(const vector::Vector<dtype,dim>&&point,
                const edge_weak_ptr<dtype,dim>&&edge);
            Vertex&operator=(const Vertex&vert);
            Vertex&operator=(Vertex&&vert)noexcept;
            vector::Vector<dtype,dim>get_point();
            edge_weak_ptr<dtype,dim>get_edge();
            ~Vertex()    = default;
        };
    }