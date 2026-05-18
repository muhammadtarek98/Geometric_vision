#pragma once
#include "point.hpp"
#include "core.hpp"
#include "line.hpp"
#include "Face.hpp"
namespace GeometricVision
{
    namespace GeometricUtils
    {
        template<typename dtype>
        int orientation3d(const Point::point3d<dtype> &p1,const Point::point3d<dtype> &p2,const Point::point3d<dtype> &p3);
        template<typename dtype>

        int orientation2d(const Point::point2d<dtype> &p1, const Point::point2d<dtype> &p2,const Point::point2d<dtype> &p3);
        template<typename dtype>

        bool left2d(const Point::point2d<dtype> &p1, const Point::point2d<dtype> &p2,const Point::point2d<dtype> &p3);
        template<typename dtype>

        bool left3d(const Point::point3d<dtype> &p1, const Point::point3d<dtype> &p2,const Point::point3d<dtype> &p3);
        template<typename dtype>

        bool right2d(const Point::point2d<dtype>& p1, const Point::point2d<dtype>& p2, const Point::point2d<dtype>& p3);
        template<typename dtype>

        bool right3d(const Point::point3d<dtype> &p1, const Point::point3d<dtype> &p2,const Point::point3d<dtype> &p3);
        template<typename dtype>

        bool left_or_beyond_2d(const Point::point2d<dtype> &p1, const Point::point2d<dtype> &p2,const Point::point2d<dtype> &p3);
        template<typename dtype>

        bool left_or_beyond_3d(const Point::point3d <dtype>&p1, const Point::point3d<dtype> &p2,const Point::point3d<dtype> &p3);
        template<typename dtype>

        bool left_or_between_3d(const Point::point3d<dtype> &p1, const Point:: point3d <dtype>&p2,const Point::point3d<dtype> &p3);
        template<typename dtype>

        double area_triangle_2d(const Point::point2d<dtype> &p1,const Point::point2d<dtype> &p2,const  Point::point2d<dtype> &p3);
        template<typename dtype>

        double area_triangle_3d(const Point::point3d<dtype> &p1,const Point::point3d<dtype> &p2,const  Point::point3d<dtype> &p3);
        template<typename dtype>

        bool collinear(const vector::vect3D<dtype> &v1,const vector::vect3D<dtype> &v2);
        template<typename dtype>

        bool collinear(const Point::point3d<dtype> &p1,const Point::point3d<dtype> &p2,const Point::point3d<dtype> &p3);
        template<typename dtype>

        bool coplanar(const Point::point3d<dtype> &p1,const Point::point3d<dtype> &p2,const Point::point3d<dtype> &p3,
            const Point::point3d<dtype> &p4);
        template<typename dtype>

        bool coplanar(const vector::vect3D<dtype>& v1, const vector::vect3D<dtype>& v2, const vector::vect3D<dtype>& v3);
        template<typename dtype,size_t dim>
        float signed_visibility_tetrahedron(const DCEL::Face<dtype,dim> &face,const Point::point3d<dtype> &p);
    }
}
