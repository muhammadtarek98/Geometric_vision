#pragma once
#include <bits/stdc++.h>
#include "point.hpp"
#include "geo_utils.hpp"
namespace GeometricVision
{
    namespace ConvexHull
    {
        namespace ConvexHull2D
        {
            struct SortComparator
            {
                bool operator()(Point::point2d p1,Point::point2d p2);
            };
            std::vector<Point::point2d> upper_hull_constructions(std::vector<Point::point2d> &points);
            std::vector<Point::point2d> lower_hull_constructions(std::vector<Point::point2d> &points);
            std::vector<Point::point2d> graham_convex_hull_construction(std::vector<Point::point2d> &points);
        }
    }
}