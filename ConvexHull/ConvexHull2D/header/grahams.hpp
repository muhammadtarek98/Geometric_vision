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
                template<typename dtype>
                bool operator()(Point::point2d<dtype> p1,Point::point2d<dtype> p2);
            };
            template<typename dtype>
            std::vector<Point::point2d<dtype>> upper_hull_constructions(std::vector<Point::point2d<dtype>> &points);
            template<typename dtype>
            std::vector<Point::point2d<dtype>> lower_hull_constructions(std::vector<Point::point2d<dtype>> &points);
            template<typename dtype>
            std::vector<Point::point2d<dtype>> graham_convex_hull_construction(std::vector<Point::point2d<dtype>> &points);
        }
    }
}