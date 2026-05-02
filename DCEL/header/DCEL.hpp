#pragma once
#include "vector.hpp"
#include <bits/stdc++.h>
namespace GeometricVision
{
    namespace DCEL{
        template<class type, size_t dim> class Vertex;
        template<class type, size_t dim> class Edge;
        template<class type, size_t dim> class Face;
        template<class type,size_t dim>class Polygon;
        template<class type,size_t dim>
        using vertex_weak_ptr = std::weak_ptr<Vertex<type,dim>>;
        template<class type,size_t dim>
        using vertex_shared_ptr = std::shared_ptr<Vertex<type,dim>>;
        template<class type,size_t dim>
        using vertex_unique_ptr = std::unique_ptr<Vertex<type,dim>>;

        template<class type,size_t dim>
        using edge_weak_ptr = std::weak_ptr<Edge<type,dim>>;
        template<class type,size_t dim>
        using edge_shared_ptr = std::shared_ptr<Edge<type,dim>>;
        template<class type,size_t dim>
        using edge_unique_ptr = std::unique_ptr<Edge<type,dim>>;

        template<class type,size_t dim>
        using face_weak_ptr = std::weak_ptr<Polygon<type,dim>>;
        template<class type,size_t dim>
        using face_shared_ptr = std::shared_ptr<Polygon<type,dim>>;
        template<class type,size_t dim>
        using face_unique_ptr = std::unique_ptr<Polygon<type,dim>>;
        template<class type,size_t dim>
        using poly_weak_ptr = std::weak_ptr<Polygon<type,dim>>;
        template<class type,size_t dim>
        using poly_shared_ptr = std::shared_ptr<Polygon<type,dim>>;
        template<class type,size_t dim>
        using poly_unique_ptr = std::unique_ptr<Polygon<type,dim>>;
    }
}