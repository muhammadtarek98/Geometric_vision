#pragma once
#include <bits/stdc++.h>
#include "core.hpp"
#include "line.hpp"
#include "point.hpp"
#include "geo_utils.hpp"
#include "plane.hpp"
namespace GeometricVision::Intersection
{
    bool intersection(const std::tuple<const point::point2d,const point::point2d> &l1,const std::tuple<const point::point2d,const point::point2d> &pl2);
    bool intersection(const point::point2d &p1,const point::point2d &p2,const point::point2d &p3,const point::point2d &p4);
    bool intersection(const point::point2d &p1,const point::point2d &p2,const point::point2d &p3,const point::point2d &p4,point::point2d &intersection_point);
    bool intersection(const Line::line2d &l1,const Line::line2d &l2, point::point2d &intersection_point);
    bool intersection(const Line::line3d &l1,const Line::line3d &l2, point::point3d &intersection_point);
    point::point3d plane_line_intersection(const Line::line3d &l,const plane::Plane3D &p);
    Line::line3d plane_plane_intersection(const plane::Plane3D &p1,const plane::Plane3D &p2);
}
