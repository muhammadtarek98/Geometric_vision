#pragma once
#include "DCEL.hpp"
namespace GeometricVision
{
    namespace DCEL{
        template<class type,size_t dim>
        class Polygon
        {
        private:
            std::vector<std::weak_ptr<Vertex<type,dim>>>vertex_list;
            //the edge list has all edges related to the polygon include half-edges and their twin edges
            std::vector<std::weak_ptr<Edge<type,dim>>>edge_list;
            std::vector<std::weak_ptr<Face<type,dim>>>face_list;
            std::weak_ptr<Edge<type,dim>>empty_edge;
        public:
            explicit Polygon();
            explicit Polygon(std::vector<vector::Vector<type,dim>>&points);
            bool split(std::weak_ptr<Vertex<type,dim>>v1,std::weak_ptr<Vertex<type,dim>>v2);
            bool join(std::weak_ptr<Vertex<type,dim>>v1,std::weak_ptr<Vertex<type,dim>>v2);
            std::vector<std::weak_ptr<Vertex<type,dim>>> get_vertex_list();
            std::vector<std::weak_ptr<Face<type,dim>>> get_face_list();
            std::vector<std::weak_ptr<Edge<type,dim>>> get_edge_list();
            std::weak_ptr<Vertex<type,dim>>get_vertex(vector::Vector<type,dim>&point);
            void GetEdgesWithTheSameFaceGivenOrigins(std::weak_ptr<Vertex<type,dim>> v1,
                                                     std::weak_ptr<Vertex<type,dim>> v2,
                                                     std::weak_ptr<Edge<type,dim>> e1,
                                                     std::weak_ptr<Edge<type,dim>> e2);
            virtual ~Polygon()=default;
        };
    }
}