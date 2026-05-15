#pragma once
#include "vertex_type.hpp"
#include "VertexWrapper.hpp"
namespace GeometricVision
{
    namespace PolygonPartition{
        template<typename  dtype,size_t dim>
        class EdgeWrapper
        {
        private:
            DCEL::edge_weak_ptr<dtype,dim> edge;
            VertexWrapper<dtype,dim> helper_vert;
            Point::point2d origin,des;
        public:
            EdgeWrapper(DCEL::edge_shared_ptr<dtype,dim> edge_,VertexWrapper<dtype,dim>&helper);
            const float computeX(const Point::point2d &pt);
        };
    }
}