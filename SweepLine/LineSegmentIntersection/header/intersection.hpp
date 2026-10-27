#pragma once
#include "point.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename dtype>
    class IntersectionPoint {
    private:
        Point::point2d<dtype> intersection_point;
    public:
        IntersectionPoint(const IntersectionPoint&p);
        IntersectionPoint(IntersectionPoint&&p)noexcept;
        IntersectionPoint&operator=(const IntersectionPoint&p);
        IntersectionPoint&operator=(IntersectionPoint&&p)noexcept;
        IntersectionPoint();
        ~IntersectionPoint();
        IntersectionPoint(Point::point2d<dtype> p);
        void set_point(Point::point2d<dtype>);
    };
}