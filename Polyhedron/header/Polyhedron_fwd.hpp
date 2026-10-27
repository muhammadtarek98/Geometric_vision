#pragma once
#include <bits/stdc++.h>
namespace GeometricVision::PolyHedron
    {
        // Forward declarations of classes
        template<typename dtype> class Vertex3D;
        template<typename dtype> class Edge3D;
        template<typename dtype> class Face3D;
        template<typename dtype>
        using vertex_3d_shared_ptr = std::shared_ptr<Vertex3D<dtype>>;
        template<typename dtype>
        using vertex_3d_unique_ptr = std::unique_ptr<Vertex3D<dtype>>;
        template<typename dtype>
        using vertex_3d_weak_ptr = std::weak_ptr<Vertex3D<dtype>>;

        template<typename dtype>
        using edge_3d_shared_ptr = std::shared_ptr<Edge3D<dtype>>;
        template<typename dtype>
        using edge_3d_unique_ptr = std::unique_ptr<Edge3D<dtype>>;
        template<typename dtype>
        using edge_3d_weak_ptr = std::weak_ptr<Edge3D<dtype>>;

        template<typename dtype>
        using face_shared_ptr = std::shared_ptr<Face3D<dtype>>;
        template<typename dtype>
        using face_unique_ptr = std::unique_ptr<Face3D<dtype>>;
        template<typename dtype>
        using face_weak_ptr = std::weak_ptr<Face3D<dtype>>;
    }
