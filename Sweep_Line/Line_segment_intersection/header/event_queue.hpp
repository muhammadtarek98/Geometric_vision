#pragma once
#include<bits/stdc++.h>
#include "point.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    class EventQueue
    {
    private:
        std::unique_ptr<point::point2d> point;
    };
}