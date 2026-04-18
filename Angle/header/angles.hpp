#pragma once
#include "line.hpp"
#include "plane.hpp"
#include "core.hpp"
namespace GeometricVision::Angle
{    template<class T,size_t dim>
    static double get_angle(vector::Vector<T,dim>&v1,vector::Vector<T,dim>&v2);
    double calculate_angle_lines_2d(Line::line2d & l1, Line::line2d& l2);
    double calculate_angle_lines_3d(Line::line3d & l1, Line::  line3d& l2);
    double calculate_angle_plane_and_line(const plane::Plane3D &p,const Line::line3d &l);
    double calculate_angle_plane_and_plane(const plane::Plane3D &p1,const plane::Plane3D &p2);
}
