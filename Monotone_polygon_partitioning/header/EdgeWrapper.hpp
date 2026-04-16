#pragma once
#include "vertex_type.hpp"
#include "VertexWrapper.hpp"
namespace PolygonPartition
{
    template<class type,size_t dim>
    class EdgeWrapper
    {
    private:
        std::weak_ptr<DCEL::Edge<type,dim>> edge;
        VertexWrapper<type,dim> helper_vert;
        point::point2d origin,des;
    public:
        EdgeWrapper(std::shared_ptr<DCEL::Edge<type,dim>> edge_,
            VertexWrapper<type,dim>&helper);
        /*
         * this computeX used to calculate the x value given y coord
         */
        const float computeX(const point::point2d &pt);
    };
}