#pragma once
#include "DCEL.hpp"
namespace GeometricVision::DCEL{
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
            Edge(vertex_weak_ptr <dtype,dim>origin,edge_weak_ptr<dtype,dim>twin,
                 edge_weak_ptr<dtype,dim>next,edge_weak_ptr<dtype,dim>prev,
                 face_weak_ptr<dtype,dim>face);
            Edge(const vertex_weak_ptr<dtype,dim>&origin,const edge_weak_ptr<dtype,dim>&twin,
                 const edge_weak_ptr<dtype,dim>&next,const edge_weak_ptr<dtype,dim>&prev,
                 const face_weak_ptr<dtype,dim>&face);
            Edge(const vertex_shared_ptr<dtype,dim>&origin,const edge_shared_ptr<dtype,dim>&twin,
                 const edge_shared_ptr<dtype,dim>&next,const edge_shared_ptr<dtype,dim>&prev,
                 const face_shared_ptr<dtype,dim>&face);
            Edge(const vertex_shared_ptr<dtype,dim>&origin,const edge_shared_ptr<dtype,dim>&twin,
                edge_weak_ptr<dtype,dim>next,edge_weak_ptr<dtype,dim>prev,face_weak_ptr<dtype,dim>face);
            Edge(const vertex_weak_ptr<dtype,dim>&origin,const edge_weak_ptr<dtype,dim>&twin,
                  edge_weak_ptr<dtype,dim>next,edge_weak_ptr<dtype,dim>prev,face_weak_ptr<dtype,dim>face);
            Edge(vertex_shared_ptr<dtype,dim>origin);
            Edge(vertex_weak_ptr<dtype,dim> origin);
            Edge(const vertex_weak_ptr<dtype,dim>&origin);
            Edge(vertex_shared_ptr<dtype,dim>&&origin,edge_shared_ptr<dtype,dim>&&twin,
                edge_shared_ptr<dtype,dim>&&next,edge_shared_ptr<dtype,dim>&&prev,
                face_shared_ptr<dtype,dim>&&face);
            Edge(vertex_weak_ptr<dtype,dim>&&origin,edge_weak_ptr<dtype,dim>&&twin,
                edge_weak_ptr<dtype,dim>&&next,edge_weak_ptr<dtype,dim>&&prev,
                face_weak_ptr<dtype,dim>&&face);
            Edge(vertex_weak_ptr<dtype,dim>&&origin)noexcept;
            Edge(const Edge &e);
            Edge(Edge&&e)noexcept;
            Edge&operator=(const Edge&e);
            Edge&operator=(Edge&&e)noexcept;
            edge_weak_ptr<dtype,dim> get_destination();
            edge_weak_ptr<dtype,dim> get_next();
            edge_weak_ptr<dtype,dim> get_prev();
            edge_weak_ptr<dtype,dim> get_twin();
            vertex_weak_ptr<dtype,dim>get_point();

            ~Edge()=default;
        };
    }