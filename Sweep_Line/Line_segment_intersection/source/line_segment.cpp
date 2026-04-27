#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename T,size_t DIM>
    LineSegment<T,DIM>::LineSegment()
    {
        if (DIM==DIM3)
        {
            p1=point::DEFAULT_POINT_2D;
            p2=point::DEFAULT_POINT_2D;
        }
        else
        {
            p1=point::DEFAULT_POINT_3D;
            p2=point::DEFAULT_POINT_3D;
        }
    }

    template <typename T, size_t DIM>
    LineSegment<T, DIM>::LineSegment(vector::Vector<T, DIM> p1,
        vector::Vector<T, DIM> p2):p1(p1),p2(p2)
    {
    }

    template <typename T, size_t DIM>
    double LineSegment<T, DIM>::get_x(double y) const
    {
        double x=0.0;
        if (DIM==DIM2)
        {
            auto x1=p1[X];
            auto x2=p2[X];
            auto y1=p1[Y];
            auto y2=p2[Y];
            auto diff_y=y2-y1;
            auto diff_x=x2-x1;
            x=y*diff_x/diff_y+(y2*x1-y1*x2)/diff_y;
        }
        else if (DIM==DIM3)
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
}
