#pragma once
#include "point.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename dtype,size_t dim>
    class LineSegment {
    private:
        vector::Vector<dtype,dim> p1;
        vector::Vector<dtype,dim> p2;
    public:
        LineSegment(vector::Vector<dtype,dim> p1,vector::Vector<dtype,dim> p2);
        LineSegment();
        double get_x(double y)const;
        vector::Vector<dtype,dim> get_p1();
        vector::Vector<dtype,dim> get_p2();
        vector::vector_weak_ptr<dtype,dim> get_p2_weak_ptr();
        std::weak_ptr<vector::Vector<dtype,dim>> get_p1_weak_ptr();
    };
    typedef LineSegment<double,DIM2> Segment2D;
    typedef LineSegment<double,DIM3> Segment3D;
    typedef std::weak_ptr<LineSegment<double,DIM2>> line_seg_weak_ptr;
    typedef std::shared_ptr<LineSegment<double,DIM2>> line_seg_shared_ptr;
    typedef std::unique_ptr<LineSegment<double,DIM2>> line_seg_unique_ptr;
}