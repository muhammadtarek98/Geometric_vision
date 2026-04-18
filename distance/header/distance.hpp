#pragma once
#include "line.hpp"
#include "point.hpp"
#include"plane.hpp"
namespace GeometricVision::Distance
{
    float distance_line_and_point(Line::line3d &l,point::point3d &p);
    float distance_point_plane(point::point3d &point,plane::Plane3D &p);
}
