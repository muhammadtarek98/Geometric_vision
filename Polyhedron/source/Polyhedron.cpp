#include "Polyhedron.hpp"
namespace GeometricVision
{
    namespace PolyHedron
    {
        template <typename dtype>
        std::map<Face3D<dtype>,edge_3d_weak_ptr<dtype>> Polyhedron<dtype>::get_edges()
        {
            std::map<Face3D<dtype>,edge_3d_weak_ptr<dtype>>poly_edges;
            for (const auto &i:this->faces)
            {
                auto edges=i.edges;
                for (const auto & edge:edges)
                {
                    poly_edges[i]=edge;
                }
            }
            return poly_edges;
        }

        template <typename dtype>
        std::vector<Face3D<dtype>> Polyhedron<dtype>::get_faces()
        {
            return this->faces;
        }
        template<typename dtype>
        void Polyhedron<dtype>::set_faces(std::vector<PolyHedron::face_weak_ptr<dtype>> &f)
        {
            if (this->faces.empty())
            {
             this->faces=f;
            }
            else
            {
                this->faces.insert(faces.end(),f.begin(),f.end());
            }

        }

        template <typename dtype>
        std::map<Face3D<dtype>,Vertex3D<dtype>> Polyhedron<dtype>::get_vertices()
        {
            std::map<Face3D<dtype>,Vertex3D<dtype>> verts;
            for (const auto & i:this->faces)
            {
                auto vertices=i.vertices;
                for (const auto &vert:vertices)
                {
                    verts[i]=vert;
                }
            }
            return verts;
        }


        template<typename dtype>
        static bool incident_face_check(face_weak_ptr<dtype> face,edge_3d_weak_ptr<dtype>edge)
        {
            auto r1=std::find(face.lock()->vertices.begin(),
                face.lock()->vertices.end(),edge.lock()->vertices[0]);
            auto r2=std::find(face.lock()->vertices.begin(),
                face.lock()->vertices.end(),edge.lock()->vertices[ 1]);
            bool r1_check=(r1!=std::end(face.lock()->vertices));
            bool r2_check=(r2!=std::end(face.lock()->vertices));
            if (r1_check &&r2_check)
            {
                return true;
            }
            return false;
        }

        template<typename dtype>
        static void adjust_face_normal(face_weak_ptr<dtype> face,Point::point3d<dtype> &ref_pt)
        {
            int order=GeometricUtils::check_face_visibility<dtype,ref_pt.num_dims()>(*face.lock(),ref_pt);
            if (order<0)
            {
                face.lock()->normal_switch_needed=true;
            }
        }

        template<typename dtype>
        static std::tuple<std::vector<face_weak_ptr<dtype>>,std::vector<edge_3d_weak_ptr<dtype>>> construct_polyhedron(std::vector<vertex_3d_weak_ptr<dtype>> &v,
            int pt_idx,Point::point3d<dtype> &ref_pt)
        {
            std::vector<face_weak_ptr<dtype>> faces;
            std::vector<edge_3d_weak_ptr<dtype>>edges;
            //polyhedron faces construction
            auto f0=face_weak_ptr<dtype>(v[pt_idx+0],v[pt_idx+1],v[pt_idx+2]);
            auto f1=face_weak_ptr<dtype>(v[pt_idx+0],v[pt_idx+1],v[pt_idx+3]);
            auto f2=face_weak_ptr<dtype>(v[pt_idx+1],v[pt_idx+2],v[pt_idx+3]);
            auto f3=face_weak_ptr<dtype>(v[pt_idx+2],v[pt_idx+0],v[pt_idx+3]);

            faces.push_back(f0),faces.push_back(f1),faces.push_back(f2),faces.push_back(f3);
            //polyhedron edges construction
            auto e0=edge_3d_unique_ptr<dtype>(v[pt_idx+0],v[pt_idx+1]);
            auto e1=edge_3d_unique_ptr<dtype>(v[pt_idx+1],v[pt_idx+2]);
            auto e2=edge_3d_unique_ptr<dtype>(v[pt_idx+2],v[pt_idx+0]);
            auto e3=edge_3d_unique_ptr<dtype>(v[pt_idx+0],v[pt_idx+3]);
            auto e4=edge_3d_unique_ptr<dtype>(v[pt_idx+1],v[pt_idx+3]);
            auto e5=edge_3d_unique_ptr<dtype>(v[pt_idx+2],v[pt_idx+3]);
            edges.push_back(e0),edges.push_back(e1),edges.push_back(e2),edges.push_back(e3),edges.push_back(e4),edges.push_back(e5);
            //adjust the normals to the reference point
            for (const auto &i:faces)
            {
                adjust_face_normal(i,ref_pt);
            }
            //set the boundaries
            faces[0].add_edge(edges[0]);
            faces[0].add_edge(edges[1]);
            faces[0].add_edge(edges[2]);

            faces[1].add_edge(edges[0]);
            faces[1].add_edge(edges[3]);
            faces[1].add_edge(edges[4]);

            faces[2].add_edge(edges[1]);
            faces[2].add_edge(edges[4]);
            faces[2].add_edge(edges[5]);
            faces[3].add_edge(edges[2]);
            faces[3].add_edge(edges[5]);
            faces[3].add_edge(edges[3]);
            edges[0].lock()->face[0]=faces[0];
            edges[0].lock()->face[1]=faces[1];
            edges[1].lock()->face[0]=faces[0];
            edges[1].lock()->face[1]=faces[2];
            edges[2].lock()->face[0]=faces[0];
            edges[2].lock()->face[1]=faces[3];
            edges[3].lock()->face[0]=faces[1];
            edges[3].lock()->face[1]=faces[3];

            edges[4].lock()->face[0]=faces[2];
            edges[4].lock()->face[1]=faces[1];

            edges[5].lock()->face[0]=faces[3];
            edges[5].lock()->face[1]=faces[2];

        return std::make_tuple(faces,edges);
        }

    }
}