#pragma once
#include "vector.hpp"
namespace GeometricVision
{
    namespace Point{
        typedef vector::vect2D point2d;
        typedef vector::vect3D point3d;
        static const point2d DEFAULT_POINT_2D(FLT_MAX,FLT_MAX);
        static const point3d DEFAULT_POINT_3D(FLT_MAX,FLT_MAX,FLT_MAX);
        bool sort_point2d_top_bottom_left_right(const point2d &a,const point2d &b);
        bool sort_point2d_left_right_top_bottom(const point2d &a,const point2d &b);
        bool sort_point3d_top_bottom_left_right(const point3d &a,const point3d &b);
        bool sort_point2d_by_x(const point2d &a,const point2d &b);
        bool sort_point2d_by_y(const point2d &a,const point2d &b);
        typedef std::weak_ptr<point2d> point_2d_weak_ptr;
        typedef std::shared_ptr<point2d> point_2d_shared_ptr;
        typedef std::unique_ptr<point2d> point_2d_unique_ptr;
    }
}