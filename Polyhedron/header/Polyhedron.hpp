#pragma once
#include "Polyhedron_fwd.hpp" // Include forward declarations and type aliases
#include "vertex3D.hpp"
#include "face.hpp"
#include "Edge3D.hpp"
#include "point.hpp"
#include "geo_utils.hpp"
#include <vector> // Consider replacing with more specific includes if possible
#include<map>
namespace GeometricVision
{
    namespace PolyHedron
    {
        // The actual class definitions will be in their respective headers.
        // No need for forward declarations or using aliases here anymore as they are in Polyhedron_fwd.hpp
        template<typename dtype>
        class Polyhedron
        {
            std::vector<Face3D<dtype>> faces;
        public:
            void set_faces(std::vector<PolyHedron::face_weak_ptr<dtype>>&f);
            std::map<Face3D<dtype>,edge_3d_weak_ptr<dtype>>get_edges();
            std::vector<Face3D<dtype>>get_faces();
            std::map<Face3D<dtype>,Vertex3D<dtype>>get_vertices();
        };
        template<typename dtype>
        bool incident_face_check(face_weak_ptr<dtype> face,edge_3d_weak_ptr<dtype>edge);
        template<typename dtype>
        void adjust_face_normal(face_weak_ptr<dtype>,Point::point3d<dtype> &ref_pt);
        template<typename dtype>
        static std::tuple<std::vector<face_weak_ptr<dtype>>,std::vector<edge_3d_weak_ptr<dtype>>> construct_polyhedron(std::vector<vertex_3d_weak_ptr<dtype>> &v,
            int pt_idx,Point::point3d<dtype> &ref_pt);


    }
}