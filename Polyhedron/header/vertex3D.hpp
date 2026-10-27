#pragma once
#include <bits/stdc++.h>
#include "point.hpp"
namespace GeometricVision:: PolyHedron
    {
        template<typename dtype>
        class Vertex3D
        {
            Point::point_3d_weak_ptr<dtype> point;
            bool processed;
        public:
            Vertex3D();
            ~Vertex3D();
            Vertex3D(const Vertex3D&v);
            Vertex3D(Vertex3D&&v)noexcept;
            Vertex3D &operator=(Vertex3D&&v)noexcept;
            Vertex3D &operator=(const Vertex3D&v);
            Vertex3D(Point::point_3d_weak_ptr<dtype>point,bool processed=false);
            void set_processed(bool f);
            bool get_processed();
        };
    }
