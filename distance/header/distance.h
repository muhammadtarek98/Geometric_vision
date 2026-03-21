#pragma once
#include "line.h"
#include "point.h"
#include"plane.h"
namespace distance
{
    float distance_line_and_point(line::line3d &l,point::point3d &p);
    float distance_point_plane(point::point3d &point,plane::Plane3D &p);
}