#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename dtype,size_t dim  >
    LineSegment<dtype,dim>::LineSegment()
    {
        if (dim==DIM3)
        {
            p1=Point::DEFAULT_POINT_2D;
            p2=Point::DEFAULT_POINT_2D;
        }
        else
        {
            p1=Point::DEFAULT_POINT_3D;
            p2=Point::DEFAULT_POINT_3D;
        }
    }

    template <typename dtype, size_t dim>
    LineSegment<dtype,dim>::LineSegment(vector::Vector<dtype,dim> p1,
        vector::Vector<dtype,dim> p2):p1(p1),p2(p2)
    {
    }

    template <typename dtype, size_t dim>
    double LineSegment<dtype, dim>::get_x(double y) const
    {
        double x=0.0;
        if (dim==DIM2)
        {
            auto x1=p1[X];
            auto x2=p2[X];
            auto y1=p1[Y];
            auto y2=p2[Y];
            auto diff_y=y2-y1;
            auto diff_x=x2-x1;
            x=y*diff_x/diff_y+(y2*x1-y1*x2)/diff_y;
        }
        else if (dim==DIM3)
        {
            auto x1=p1[X];
            auto x2=p2[X];
            auto y1=p1[Y];
            auto y2=p2[Y];
            auto diff_y=y2-y1;
            auto diff_x=x2-x1;
            x = y * diff_x / diff_y+ (y2 * x1 - y1 * x2) / diff_y;
        }
        return x;
    }
    template<typename dtype,size_t dim>
    vector::Vector<dtype,dim> LineSegment<dtype,dim>::get_p1(){
    return p1;
    }
    template<typename dtype,size_t dim>
vector::Vector<dtype,dim> LineSegment<dtype,dim>::get_p2(){
        return p2;
    }
    template<typename dtype,size_t dim>
    vector::vector_weak_ptr<dtype,dim> LineSegment<dtype,dim>::get_p1_weak_ptr(){
        return p1;
    }
    template<typename dtype,size_t dim>
    vector::vector_weak_ptr<dtype,dim> LineSegment<dtype,dim>::get_p2_weak_ptr(){
        return std::weak_ptr<vector::Vector<dtype,dim>>(p2);
    }
}
