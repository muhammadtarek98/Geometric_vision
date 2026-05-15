#pragma once
#include "DCEL.hpp"
namespace GeometricVision
{
    namespace DCEL{
        template<typename dtype,size_t dim>
        class Face
        {
        private:
            edge_weak_ptr<dtype,dim>outer_edge;
            std::vector<edge_weak_ptr<dtype,dim>>inner_edges;
        public:
            Face()=default;
            std::vector<edge_weak_ptr<dtype,dim>>get_edges();
            std::vector<vector::Vector<dtype,dim>> get_points();
            virtual ~Face()=default;
        };
    }
}