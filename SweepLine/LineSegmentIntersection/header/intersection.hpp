#pragma once
#include "point.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    class IntersectionPoint {
    private:
        Point::point2d intersection_point;
    public:
        IntersectionPoint();
        IntersectionPoint(Point::point2d p);
        void set_point(Point::point2d);
    };
}