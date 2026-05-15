#pragma once
#include "DCEL.hpp"
namespace GeometricVision
{
    namespace DCEL{
        template<class dtype,size_t dim>
        class Polygon
        {
        private:
            std::vector<vertex_weak_ptr<dtype,dim>>vertex_list;
            //the edge list has all edges related to the polygon include half-edges and their twin edges
            std::vector<edge_weak_ptr<dtype,dim>>edge_list;
            std::vector<face_weak_ptr<dtype,dim>>face_list;
            edge_weak_ptr<dtype,dim>empty_edge;
        public:
            explicit Polygon();
            explicit Polygon(std::vector<vector::Vector<dtype,dim>>&points);
            bool split(vertex_weak_ptr<dtype,dim>v1,vertex_weak_ptr<dtype,dim>v2);
            bool join(vertex_weak_ptr<dtype,dim>v1,vertex_weak_ptr<dtype,dim>v2);
            std::vector<vertex_weak_ptr<dtype,dim>> get_vertex_list();
            std::vector<face_weak_ptr<dtype,dim>> get_face_list();
            std::vector<edge_weak_ptr<dtype,dim>> get_edge_list();
            vertex_weak_ptr<dtype,dim>get_vertex(vector::Vector<dtype,dim>&point);
            void GetEdgesWithTheSameFaceGivenOrigins(vertex_weak_ptr<dtype,dim>v1,
                                                     vertex_weak_ptr<dtype,dim> v2,
                                                     edge_weak_ptr<dtype,dim> e1,
                                                     edge_weak_ptr<dtype,dim> e2);
            virtual ~Polygon()=default;
        };
    }
}