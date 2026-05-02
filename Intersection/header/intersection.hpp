#pragma once
#include <bits/stdc++.h>
#include "core.hpp"
#include "line.hpp"
#include "point.hpp"
#include "geo_utils.hpp"
#include "plane.hpp"
namespace GeometricVision
{
    namespace Intersection{
        bool intersection(const std::tuple<const Point::point2d,const Point::point2d> &l1,const std::tuple<const Point::point2d,const Point::point2d> &pl2);
        bool intersection(const Point::point2d &p1,const Point::point2d &p2,const Point::point2d &p3,const Point::point2d &p4);
        bool intersection(const Point::point2d &p1,const Point::point2d &p2,const Point::point2d &p3,const Point::point2d &p4,Point::point2d &intersection_point);
        bool intersection(const Line::line2d &l1,const Line::line2d &l2, Point::point2d &intersection_point);
        bool intersection(const Line::line3d &l1,const Line::line3d &l2, Point::point3d &intersection_point);
        Point::point3d plane_line_intersection(const Line::line3d &l,const plane::Plane3D &p);
        Line::line3d plane_plane_intersection(const plane::Plane3D &p1,const plane::Plane3D &p2);
    }
}