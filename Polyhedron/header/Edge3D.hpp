#pragma once
#include <bits/stdc++.h>
#include "Polyhedron_fwd.hpp" // Changed from Polyhedron.hpp
namespace GeometricVision
{
    namespace PolyHedron
    {
        template<typename dtype>
        class Edge3D
        {
            std::array<vertex_3d_weak_ptr<dtype>,2> vertices;
            std::array<face_weak_ptr<dtype>,2> face;
        public:
            Edge3D(vertex_3d_weak_ptr<dtype>p1,vertex_3d_weak_ptr<dtype>p2);
            Edge3D();
            bool operator ==(const Edge3D<dtype> &other);

        };
    }
}