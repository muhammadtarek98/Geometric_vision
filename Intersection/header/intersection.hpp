#pragma once
#include <bits/stdc++.h>
#include "core.hpp"
#include "line.hpp"
#include "point.hpp"
#include "geo_utils.hpp"
#include "plane.hpp"
namespace GeometricVision::Intersection{
        template<typename dtype>
        bool intersection(const std::tuple<const Point::point2d<dtype>,const Point::point2d<dtype>> &l1,
        const std::tuple<const Point::point2d<dtype>,const Point::point2d<dtype>> &pl2);
        template<typename dtype>
        bool intersection(const Point::point2d<dtype> &p1,const Point::point2d<dtype> &p2,const Point::point2d<dtype> &p3,const Point::point2d<dtype>&p4);
        template<typename dtype>
        bool intersection(const Point::point2d<dtype> &p1,const Point::point2d<dtype> &p2,const Point::point2d<dtype> &p3,const Point::point2d<dtype>&p4,Point::point2d<dtype> &intersection_point);
        template<typename dtype>
        bool intersection(const Line::line2d<dtype> &l1,const Line::line2d<dtype> &l2, Point::point2d<dtype> &intersection_point);
        template<typename dtype>
        bool intersection(const Line::line3d<dtype> &l1,const Line::line3d<dtype> &l2, Point::point3d<dtype> &intersection_point);
        template<typename dtype>
        Point::point3d<dtype> plane_line_intersection(const Line::line3d<dtype> &l,const plane::Plane3D<dtype> &p);
        template<typename dtype>
        Line::line3d<dtype> plane_plane_intersection(const plane::Plane3D<dtype> &p1,const plane::Plane3D<dtype> &p2);
    }