#pragma once
#include "line.h"
#include "plane.h"
#include "core.h"
namespace angle
{    template<class T,size_t dim>
    static double get_angle(vector::Vector<T,dim>&v1,vector::Vector<T,dim>&v2);
    double calculate_angle_lines_2d(line::line2d & l1, line::line2d& l2);
    double calculate_angle_lines_3d(line::line3d & l1, line::  line3d& l2);
    double calculate_angle_plane_and_line(const plane::Plane3D &p,const line::line3d &l);
    double calculate_angle_plane_and_plane(const plane::Plane3D &p1,const plane::Plane3D &p2);
}
