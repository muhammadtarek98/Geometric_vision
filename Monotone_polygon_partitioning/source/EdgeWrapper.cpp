#include "EdgeWrapper.hpp"
namespace GeometricVision::PolygonPartition
{
    template <class type, size_t dim>
    EdgeWrapper<type, dim>::EdgeWrapper(std::shared_ptr<DCEL::Edge<type, dim>> edge_,
        VertexWrapper<type, dim>& helper)
    {
        this->edge=edge_;
        this->helper_vert=helper;
        this->origin=this->edge->origin->point;
        this->des=this->edge->twin->origin->point;
    }

    template <class type, size_t dim>
    const float EdgeWrapper<type, dim>::computeX(const point::point2d& pt)
    {
        auto deno=(des[Y]-origin[Y]);
        if (deno!=0)
        {
            return (pt[Y]-origin[Y])*(des[X]-origin[X])/deno+origin[X];
        }
        return pt[X];
    }
}