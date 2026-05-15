#pragma once
#include "point.hpp"
#include "core.hpp"
#include "line.hpp"
#include "Face.hpp"
typedef GeometricVision::vector::Vector<double,DIM2> point2d;
typedef GeometricVision::vector::vect3D point3d;
namespace GeometricVision
{
    namespace GeometricUtils
    {
        int orientation3d(const Point::point3d &p1,const Point::point3d &p2,const Point::point3d &p3);
        int orientation2d(const Point::point2d &p1, const Point::point2d &p2,const Point::point2d &p3);
        bool left2d(const Point::point2d &p1, const Point::point2d &p2,const Point::point2d &p3);
        bool left3d(const Point::point3d &p1, const Point::point3d &p2,const Point::point3d &p3);
        bool right2d(const Point::point2d& p1, const Point::point2d& p2, const Point::point2d& p3);
        bool right3d(const Point::point3d &p1, const Point::point3d &p2,const Point::point3d &p3);
        bool left_or_beyond_2d(const Point::point2d &p1, const Point::point2d &p2,const Point::point2d &p3);
        bool left_or_beyond_3d(const Point::point3d &p1, const Point::point3d &p2,const Point::point3d &p3);
        bool left_or_between_3d(const Point::point3d &p1, const Point:: point3d &p2,const Point::point3d &p3);
        double area_triangle_2d(const Point::point2d &p1,const Point::point2d &p2,const  Point::point2d &p3);
        double area_triangle_3d(const Point::point3d &p1,const Point::point3d &p2,const  Point::point3d &p3);
        bool collinear(const vector::vect3D &v1,const vector::vect3D &v2);
        bool collinear(const Point::point3d &p1,const Point::point3d &p2,const Point::point3d &p3);
        bool coplanar(const Point::point3d &p1,const Point::point3d &p2,const Point::point3d &p3,const Point::point3d &p4);
        bool coplanar(const vector::vect3D& v1, const vector::vect3D& v2, const vector::vect3D& v3);
        template<typename dtype,size_t dim>
        float signed_visibility_tetrahedron(const DCEL::Face<dtype,dim> &face,const Point::point3d &p);
    }
}
