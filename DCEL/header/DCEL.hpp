#pragma once
#include "vector.hpp"
#include <bits/stdc++.h>
namespace GeometricVision
{
    namespace DCEL{
        template<typename  dtype, size_t dim> class Vertex;
        template<typename  dtype, size_t dim> class Edge;
        template<typename  dtype, size_t dim> class Face;
        template<typename  dtype,size_t dim>class Polygon;
        template<typename  dtype,size_t dim>
        using vertex_weak_ptr= std::weak_ptr<Vertex<dtype,dim>>;
        template<typename dtype,size_t dim>
        using vertex_shared_ptr = std::shared_ptr<Vertex<dtype,dim>>;
        template<typename dtype,size_t dim>
        using vertex_unique_ptr = std::unique_ptr<Vertex<dtype,dim>>;
        template<typename dtype,size_t dim>
        using edge_weak_ptr = std::weak_ptr<Edge<dtype,dim>>;
        template<typename dtype,size_t dim>
        using edge_shared_ptr = std::shared_ptr<Edge<dtype,dim>>;
        template<typename dtype,size_t dim>
        using edge_unique_ptr = std::unique_ptr<Face<dtype,dim>>;
        template<typename dtype,size_t dim>
        using face_weak_ptr = std::weak_ptr<Face<dtype,dim>>;
        template<typename dtype,size_t dim>
        using face_shared_ptr = std::shared_ptr<Face<dtype,dim>>;
        template<typename dtype,size_t dim>
        using face_unique_ptr = std::unique_ptr<Face<dtype,dim>>;
        template<typename dtype,size_t dim>
        using poly_weak_ptr = std::weak_ptr<Polygon<dtype,dim>>;
        template<typename dtype,size_t dim>
        using poly_shared_ptr = std::shared_ptr<Polygon<dtype,dim>>;
        template<typename dtype,size_t dim>
        using poly_unique_ptr = std::unique_ptr<Polygon<dtype,dim>>;


    }
}