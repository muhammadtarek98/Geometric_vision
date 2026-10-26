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
                 edge_weak_ptr<dtype,dim>twin,
                 edge_weak_ptr<dtype,dim>next,
                 edge_weak_ptr<dtype,dim>prev,
                 face_weak_ptr<dtype,dim>face);
            Edge(const vertex_weak_ptr<dtype,dim>&origin,
                 const edge_weak_ptr<dtype,dim>&twin,
                 const edge_weak_ptr<dtype,dim>&next,
                 const edge_weak_ptr<dtype,dim>&prev,
                 const face_weak_ptr<dtype,dim>&face);
            Edge(const vertex_shared_ptr<dtype,dim>&origin,
                 const edge_shared_ptr<dtype,dim>&twin,
                 const edge_shared_ptr<dtype,dim>&next,
                 const edge_shared_ptr<dtype,dim>&prev,
                 const face_shared_ptr<dtype,dim>&face);

            Edge(const vertex_shared_ptr<dtype,dim>&origin,
     const edge_shared_ptr<dtype,dim>&twin,
      edge_weak_ptr<dtype,dim>next,
      edge_weak_ptr<dtype,dim>prev,
      face_weak_ptr<dtype,dim>face);

            Edge(const vertex_weak_ptr<dtype,dim>&origin,
                 const edge_weak_ptr<dtype,dim>&twin,
                  edge_weak_ptr<dtype,dim>next,
                  edge_weak_ptr<dtype,dim>prev,
                  face_weak_ptr<dtype,dim>face);

            Edge(vertex_shared_ptr<dtype,dim>origin);
            Edge(vertex_weak_ptr<dtype,dim> origin);
            Edge(const vertex_weak_ptr<dtype,dim>&origin);
            edge_weak_ptr<dtype,dim> get_destination();
            edge_weak_ptr<dtype,dim> get_next();
            edge_weak_ptr<dtype,dim> get_prev();
            edge_weak_ptr<dtype,dim> get_twin();
            vertex_weak_ptr<dtype,dim>get_point();

            virtual  ~Edge()=default;
        };
    }
}