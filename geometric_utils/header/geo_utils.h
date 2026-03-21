#pragma once
#include "point.h"
#include "core.h"
#include "line.h"
namespace geometric_utils
{
    int orientation3d(const point::point3d &p1,const point::point3d &p2,const point::point3d &p3);
    int orientation2d(const point::point2d &p1, const point::point2d &p2,const point::point2d &p3);
    bool left2d(const point::point2d &p1, const point::point2d &p2,const point::point2d &p3);
    bool left3d(const point::point3d &p1, const point::point3d &p2,const point::point3d &p3);
    //bool right2d(const point2d &p1, const point2d &p2,const point2d &p3);
    bool right3d(const point::point3d &p1, const point::point3d &p2,const point::point3d &p3);
    bool left_or_beyond_2d(const point::point2d &p1, const point::point2d &p2,const point::point2d &p3);
    bool left_or_beyond_3d(const point::point3d &p1, const point::point3d &p2,const point::point3d &p3);
    //bool left_or_between_2d(const point2d &p1, const point2d &p2,const point2d &p3);
    bool left_or_between_3d(const point::point3d &p1, const point:: point3d &p2,const point::point3d &p3);
    double area_triangle_2d(const point::point2d &p1,const point::point2d &p2,const  point::point2d &p3);
    double area_triangle_3d(const point::point3d &p1,const point::point3d &p2,const  point::point3d &p3);
    bool collinear(const vector::vect3D &v1,const vector::vect3D &v2);
    bool collinear(const point::point3d &p1,const point::point3d &p2,const point::point3d &p3);
    bool coplanar(const point::point3d &p1,const point::point3d &p2,const point::point3d &p3,const point::point3d &p4);
    bool coplanar(const vector::vect3D &v1,const vector::vect3D &v2,const vector::vect3D &v3);

    typedef vector::Vector<double,DIM2> point2d;
    typedef vector::vect3D point3d;

}
