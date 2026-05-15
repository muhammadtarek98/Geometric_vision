#pragma once
#include "DCEL.hpp"
namespace GeometricVision
{
    namespace DCEL{
        template<class dtype,size_t dim>
        class Edge
        {
        private:
            vertex_weak_ptr<dtype,dim>origin;
            edge_weak_ptr<dtype,dim> twin;
            edge_weak_ptr<dtype,dim> next;
            edge_weak_ptr<dtype,dim>prev;
            face_weak_ptr <dtype,dim>face;
            int id;
        public:
            Edge();
            Edge(vertex_weak_ptr <dtype,dim>origin,
                 edge_weak_ptr<dtype,dim>twin, edge_weak_ptr<dtype,dim>next, edge_weak_ptr<dtype,dim>prev,
                 face_weak_ptr<dtype,dim>face);
            Edge(const vertex_weak_ptr<dtype,dim>&origin,
                 const edge_weak_ptr<dtype,dim>&twin,
                 const edge_weak_ptr<dtype,dim>&next,
                 const edge_weak_ptr<dtype,dim>&prev,
                 const face_weak_ptr<dtype,dim>&face);
            Edge( vertex_weak_ptr<dtype,dim>origin);
            Edge(const vertex_weak_ptr<dtype,dim>&origin);
            vertex_weak_ptr<dtype,dim> get_destination();
            vertex_weak_ptr<dtype,dim> get_next();
            vertex_weak_ptr<dtype,dim> get_prev();
            vertex_weak_ptr<dtype,dim> get_twin();
            virtual  ~Edge()=default;
        };
    }
}