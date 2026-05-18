#include "EdgeWrapper.hpp"
namespace GeometricVision::PolygonPartition
{
    template <typename dtype, size_t dim>
    EdgeWrapper<dtype, dim>::EdgeWrapper(std::shared_ptr<DCEL::Edge<dtype, dim>> edge_,
        VertexWrapper<dtype, dim>& helper)
    {
        this->edge=edge_;
        this->helper_vert=helper;
        this->origin=this->edge->origin->point;
        this->des=this->edge->twin->origin->point;
    }

    template <typename dtype, size_t dim>
    const float EdgeWrapper<dtype, dim>::computeX(const Point::point2d<dtype>& pt)
    {
        auto deno=(des[Y]-origin[Y]);
        if (deno!=0)
        {
            return (pt[Y]-origin[Y])*(des[X]-origin[X])/deno+origin[X];
        }
        return pt[X];
    }
}