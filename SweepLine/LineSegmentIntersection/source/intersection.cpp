#include "intersection.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    IntersectionPoint::IntersectionPoint():intersection_point(Point::DEFAULT_POINT_2D)
    {
    }
    IntersectionPoint::IntersectionPoint(Point::point2d p):intersection_point(p)
    {
    }
    void IntersectionPoint::set_point(Point::point2d p)
    {
        intersection_point=p;
    }
}