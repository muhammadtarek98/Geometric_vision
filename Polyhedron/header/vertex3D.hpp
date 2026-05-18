#pragma once
#include <bits/stdc++.h>
#include "point.hpp"
namespace GeometricVision
{
    namespace PolyHedron
    {
        template<typename dtype>
        class Vertex3D
        {
            Point::point_3d_weak_ptr<dtype> point;
            bool processed;
        public:
            Vertex3D();
            Vertex3D(Point::point_3d_weak_ptr<dtype>point,bool processed=false);
        };
    }
}
