#pragma once
#include <bits/stdc++.h>
#include "point.hpp"
#include "angles.hpp"
namespace GeometricVision
{
    namespace ConvexHull
    {
        namespace ConvexHull2D
        {
            template<typename dtype>
            std::vector<Point::point2d<dtype>> gift_wrapping2D(const std::vector<Point::point2d<dtype>>& point_set);
        }
    }
}