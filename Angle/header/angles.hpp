#pragma once
#include "line.hpp"
#include "plane.hpp"
#include "core.hpp"
namespace GeometricVision::Angle{
        template<typename dtype,size_t dim>
        double get_angle(vector::Vector<dtype,dim>v1,vector::Vector<dtype,dim>v2);
        template<typename dtype>
        double calculate_angle_lines_2d(const Line::line2d<dtype> & l1, const Line::line2d<dtype>& l2);
        template<typename dtype>
        double calculate_angle_lines_3d(const Line::line3d<dtype> & l1, const Line::line3d<dtype> &l2);
        template<typename dtype>
        double calculate_angle_plane_and_line(const plane::Plane3D<dtype> &p,const Line::line3d<dtype> &l);
        template<typename dtype>
        double calculate_angle_plane_and_plane(const plane::Plane3D<dtype> &p1,const plane::Plane3D<dtype> &p2);
        template<typename dtype>
        double polar_angle_2D(const Point::point2d<dtype> &src, const Point::point2d<dtype> &dst);
    }