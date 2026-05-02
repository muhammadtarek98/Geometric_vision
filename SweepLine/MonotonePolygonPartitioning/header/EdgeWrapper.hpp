#pragma once
#include "vertex_type.hpp"
#include "VertexWrapper.hpp"
namespace GeometricVision
{
    namespace PolygonPartition{
        template<class type,size_t dim>
        class EdgeWrapper
        {
        private:
            std::weak_ptr<DCEL::Edge<type,dim>> edge;
            VertexWrapper<type,dim> helper_vert;
            Point::point2d origin,des;
        public:
            EdgeWrapper(std::shared_ptr<DCEL::Edge<type,dim>> edge_,
                        VertexWrapper<type,dim>&helper);
            const float computeX(const Point::point2d &pt);
        };
    }
}