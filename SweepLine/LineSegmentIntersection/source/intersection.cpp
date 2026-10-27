#include "intersection.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template <typename dtype>
    IntersectionPoint<dtype>::~IntersectionPoint()
    {

    }
    template <typename dtype>
    IntersectionPoint<dtype>::IntersectionPoint(IntersectionPoint&& p) noexcept:
    intersection_point(std::move(p.intersection_point))
    {
    }

    template <typename dtype>
    IntersectionPoint<dtype>::IntersectionPoint(const IntersectionPoint& p):intersection_point(p.intersection_point)
    {}

    template <typename dtype>
    IntersectionPoint<dtype>& IntersectionPoint<dtype>::operator=(const IntersectionPoint& p)
    {
        if (this!=&p)
        {
            intersection_point=p.intersection_point;
        }
        return *this;

    }

    template <typename dtype>
    IntersectionPoint<dtype>& IntersectionPoint<dtype>::operator=(IntersectionPoint&& p) noexcept
    {
        if (this!=p)
        {
            intersection_point=std::move(p.intersection_point);
        }
        return *this;
    }


    template<typename dtype>
    IntersectionPoint<dtype>::IntersectionPoint():intersection_point(Point::DEFAULT_POINT_2D)
    {
    }
    template<typename dtype>

    IntersectionPoint<dtype>::IntersectionPoint(Point::point2d<dtype> p):intersection_point(p)
    {
    }
    template<typename dtype>
    void IntersectionPoint<dtype>::set_point(Point::point2d<dtype> p)
    {
        intersection_point=p;
    }
}