#pragma once
#include "vertex_type.hpp"
#include "VertexWrapper.hpp"
namespace GeometricVision::PolygonPartition{
        template<typename  dtype,size_t dim>
        class EdgeWrapper
        {
        private:
            DCEL::edge_weak_ptr<dtype,dim> edge;
            VertexWrapper<dtype,dim> helper_vert;
            Point::point2d<dtype> origin,des;
        public:
            ~EdgeWrapper();
            EdgeWrapper(const EdgeWrapper&e);
            EdgeWrapper(EdgeWrapper&&e)noexcept;
            EdgeWrapper&operator=(const EdgeWrapper&e);
            EdgeWrapper&operator=(EdgeWrapper&&e)noexcept;
            EdgeWrapper(DCEL::edge_shared_ptr<dtype,dim> edge_,VertexWrapper<dtype,dim>&helper);
            const dtype computeX(const Point::point2d<dtype> &pt);
        };
    }