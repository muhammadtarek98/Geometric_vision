#pragma once
#include "Polyhedron_fwd.hpp" // Changed from Polyhedron.hpp
#include <bits/stdc++.h>
#include "plane.hpp"
namespace GeometricVision::PolyHedron
    {
        template<typename dtype>
        class Face3D
        {
            std::vector<edge_3d_weak_ptr<dtype>>edges;
            std::vector<vertex_3d_weak_ptr<dtype>>vertices;
            plane::Plane<dtype> plane_;
            bool visible;
            bool normal_switch_needed;
        public:
            Face3D(vertex_3d_weak_ptr<dtype> p1, vertex_3d_weak_ptr<dtype> p2, vertex_3d_weak_ptr<dtype> p3);
            Face3D(const Face3D &f);
            Face3D(Face3D &&f)noexcept;
            Face3D&operator=(const Face3D&f);
            Face3D&operator=(Face3D&&f)noexcept;
            bool operator==(const Face3D& _other);
            Face3D()=default;
            ~Face3D();
            void add_edge(edge_3d_weak_ptr<dtype> edge);
            bool get_normal_switch();
            void set_face_visibility(bool vis);
            bool get_face_visibility();

            
        };
    }
