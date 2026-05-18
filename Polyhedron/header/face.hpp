#pragma once
#include "Polyhedron_fwd.hpp" // Changed from Polyhedron.hpp
#include <bits/stdc++.h>
#include "plane.hpp"
namespace GeometricVision
{
    namespace PolyHedron
    {
        template<typename dtype>
        class Face3D
        {
            std::vector<edge_3d_weak_ptr<dtype>>edges;
            std::array<vertex_3d_weak_ptr<dtype>,3>vertices;
            plane::Plane<dtype> plane_;
            bool visible;
            bool normal_switch_needed;
        public:
            Face3D(vertex_3d_weak_ptr<dtype> p1, vertex_3d_weak_ptr<dtype> p2, vertex_3d_weak_ptr<dtype> p3);
            bool operator==(const Face3D& _other);
            Face3D();
            void add_edge(edge_3d_weak_ptr<dtype> edge);
            
        };
    }
}