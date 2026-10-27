#pragma once
#include <bits/stdc++.h>
#include "Polyhedron_fwd.hpp" // Changed from Polyhedron.hpp
namespace GeometricVision::PolyHedron
{
        template<typename dtype>
        class Edge3D
        {
            std::array<vertex_3d_weak_ptr<dtype>,2> vertices;
            std::array<face_weak_ptr<dtype>,2> face;
        public:
            Edge3D(vertex_3d_weak_ptr<dtype>p1,vertex_3d_weak_ptr<dtype>p2);
            Edge3D();
            Edge3D(const Edge3D &e);
            Edge3D(Edge3D &&e)noexcept;
            Edge3D&operator=(const Edge3D&e);
            Edge3D&operator=(Edge3D&&e)noexcept;
            ~Edge3D();
            bool operator ==(const Edge3D<dtype> &other);

        };
}