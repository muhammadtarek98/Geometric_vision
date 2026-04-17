#pragma once
#include "Edge.h"
#include "vector.h"
namespace GeometricVision
{
    namespace DCEL
    {
        template<class type=float,size_t dim=DIM3>
        class Vertex
        {
        private:
            vector::Vector<type,dim> point;
            std::weak_ptr<Edge<type,dim>>edge;
        public:
            Vertex();
            Vertex(vector::Vector<type,dim>point,
                           const std::weak_ptr<Edge<type,dim>>&edge);
            Vertex(const vector::Vector<type,dim>&point, const std::weak_ptr<Edge<type,dim>>&edge);
            Vertex(const vector::Vector<type,dim>&&point, const std::weak_ptr<Edge<type,dim>>&edge);
            vector::Vector<type,dim>get_point();
            std::weak_ptr<Edge<type,dim>>get_edge();
            virtual ~Vertex()    = default;
        };
    }
}