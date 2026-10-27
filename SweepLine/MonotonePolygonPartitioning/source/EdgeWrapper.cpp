#include "EdgeWrapper.hpp"
namespace GeometricVision::PolygonPartition
{
    template <typename dtype, size_t dim>
    EdgeWrapper<dtype, dim>& EdgeWrapper<dtype, dim>::operator=(EdgeWrapper&& e) noexcept
    {
        if (this!=&e)
        {
            this->des=std::move(e.des);
            this->edge=std::move(e.edge);
            this->helper_vert=std::move(e.helper_vert);
            this->origin=std::move(e.origin);
        }
        return *this;
    }

    template <typename dtype, size_t dim>
    EdgeWrapper<dtype, dim>::EdgeWrapper(const EdgeWrapper& e)
    {
        this->des=e.des;
        this->edge=e.edge;
        this->helper_vert=e.helper_vert;
        this->origin=e.origin;
    }

    template <typename dtype, size_t dim>
    EdgeWrapper<dtype, dim>::EdgeWrapper(EdgeWrapper&& e) noexcept
    {
        this->des=std::move(e.des);
        this->edge=std::move(e.edge);
        this->helper_vert=std::move(e.helper_vert);
        this->origin=std::move(e.origin);
    }

    template <typename dtype, size_t dim>
    EdgeWrapper<dtype, dim>& EdgeWrapper<dtype, dim>::operator=(const EdgeWrapper& e)
    {
        if (this!=&e)
        {
            this->des=e.des;
            this->edge=e.edge;
            this->helper_vert=e.helper_vert;
            this->origin=e.origin;
        }
        return *this;
    }

    template <typename dtype, size_t dim>
    EdgeWrapper<dtype, dim>::~EdgeWrapper()
    {

    }

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