#pragma once
#include "line.hpp"
#include "point.hpp"
#include"plane.hpp"
namespace GeometricVision
{
        namespace Distance
        {
                template<typename dtype,size_t dim>
                dtype squared_distance(vector::Vector<dtype,dim>&v1,vector::Vector<dtype,dim>&v2);
                template<typename dtype>
                float distance_line_and_point(const Line::line3d<dtype> &l, const Point::point3d<dtype> &p);
                template<typename dtype>
                float distance_point_plane(const Point::point3d<dtype>& point,const plane::Plane3D<dtype>& p);
        }
}