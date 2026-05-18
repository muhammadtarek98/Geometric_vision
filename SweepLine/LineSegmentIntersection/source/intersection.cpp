#include "intersection.hpp"
namespace GeometricVision::LineSegmentIntersection
{
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