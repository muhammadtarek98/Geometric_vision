#pragma once
#include "line.hpp"
#include "point.hpp"
#include"plane.hpp"
namespace GeometricVision
{
        namespace Distance
        {
                float distance_line_and_point(const Line::line3d &l, const Point::point3d &p);
                float distance_point_plane(const Point::point3d& point,const plane::Plane3D& p);

        }
}