#pragma once
#include "point.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename dtype>
    class IntersectionPoint {
    private:
        Point::point2d<dtype> intersection_point;
    public:
        IntersectionPoint();
        IntersectionPoint(Point::point2d<dtype> p);
        void set_point(Point::point2d<dtype>);
    };
}