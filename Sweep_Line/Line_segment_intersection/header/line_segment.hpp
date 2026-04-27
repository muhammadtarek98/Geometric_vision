#pragma once
#include "point.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename T,size_t DIM>
    class LineSegment {
    private:
        vector::Vector<T,DIM> p1;
        vector::Vector<T,DIM> p2;
    public:
        LineSegment(vector::Vector<T,DIM> p1,vector::Vector<T,DIM> p2);
        LineSegment();
        double get_x(double y)const;
    };
    typedef LineSegment<double,DIM2> Segment2D;
    typedef LineSegment<double,DIM3> Segment3D;
}