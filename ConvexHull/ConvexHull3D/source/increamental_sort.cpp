#include "increamental_sort.hpp"
namespace GeometricVision::ConvexHull::ConvexHull3D
{
    template<typename dtype>
    bool noncoplanar_check(Point::point3d<dtype>&pts,size_t &i)
    {

        bool flag=false;
        for (i=0;i<pts.size()-3;i++)
        {
            auto pt1=pts[i];
            auto pt2=pts[i+1];
            auto pt3=pts[i+2];
            auto pt4=pts[i+3];
            auto coplanar=GeometricUtils::coplanar(pt1,pt2,pt3,pt4);
            if (!coplanar)
            {
                flag=true;
                break;
            }
        }
        return flag;
    }
    template<typename dtype>
    bool CCW_check(float volume,bool face_normal_switch)
    {
        return (!face_normal_switch&&volume<0.0)||(face_normal_switch&&volume>0.0);
    }
    template<typename dtype>
    Point::point3d<dtype> get_reference_point(std::vector<Point::point3d<dtype>> &pts,int &s_idx)
    {
        auto p1=pts[s_idx];
        auto p2=pts[s_idx+1];
        auto p3=pts[s_idx+2];
        auto p4=pts[s_idx+3];

        auto x=(p1[X]+p2[X]+p3[X]+p4[X])/4.0;
        auto y=(p1[Y]+p2[Y]+p3[Y]+p4[Y])/4.0;
        auto z=(p1[Z]+p2[Z]+p3[Z]+p4[Z])/4.0;
        return Point::point3d<dtype>(x,y,z);

    }


    template<typename dtype>
    PolyHedron::Polyhedron<dtype> increamental_sort(std::vector<Point::point3d<dtype>> &pts,
        std::vector<PolyHedron::face_weak_ptr<dtype>> faces)
    {

        PolyHedron::Polyhedron<dtype> convex_hull;
        std::vector<PolyHedron::vertex_3d_weak_ptr<dtype>> verts;
        for (int i=0;i<pts.size();i++)
        {
            auto vert=PolyHedron::vertex_3d_weak_ptr<dtype>(pts[i]);
            verts.push_back(vert);
        }
        size_t i=0,j=0;
        bool noncoplanar=noncoplanar_check<dtype>(pts,i);
        if (!noncoplanar)
        {
            std::cout<<"can't construct polyhedron\n";
            return convex_hull;
        }
        auto ref_pt=get_reference_point<dtype>(pts,i);
        auto init_polyhedron=PolyHedron::construct_polyhedron(verts,i,ref_pt);
        faces=init_polyhedron[0];
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>edges{init_polyhedron[1]};
        verts[i].lock()->set_processed(true);
        verts[i+1].lock()->set_processed(true);
        verts[i+2].lock()->set_processed(true);
        verts[i+3].lock()->set_processed(true);
        for (int i=0;i<verts.size();i++)
        {
            auto curr_pt=verts[i];
            if (verts[i].lock()->get_processed())
            {
                continue;
            }
            auto visible_faces=get_visible_faces<dtype>(faces,curr_pt);
            if (visible_faces.empty())
            {
                continue;
            }
            auto borders=set_boarder_for_polyhedron(visible_faces);
            auto boarder_sz=borders.size();
            auto edges_tobe_removed=remove_edges_from_polyhedron(visible_faces);
            auto unique_verts=get_unique_vertices<dtype>(borders);
            auto iter=unique_verts.begin();
            auto news=create_new_polyhedron<dtype>(unique_verts,borders,curr_pt);
            std::vector<PolyHedron::face_weak_ptr<dtype>>new_faces=news[0];
            std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> new_edges=news[1];
            for (int j=0;j<boarder_sz;j++)
            {
                auto curr_face=new_faces[j];
                PolyHedron::adjust_face_normal(curr_face,ref_pt);
            }
            add_faces_2_edges(new_faces,new_edges);
            add_edges_2_faces(new_faces,new_edges,borders);
            for (auto k=0;k<edges_tobe_removed.size();k++)
            {
                auto curr_to_del_edge=edges_tobe_removed[k];
                for (auto j=0;j<edges.size();j++)
                {
                    auto curr_edge=edges[j];
                    if (curr_to_del_edge.lock()==curr_edge)
                    {
                        edges.erase(edges+j);
                    }
                }
            }

            for (auto k=0;k<visible_faces.size();k++)
            {
                auto curr_vis_face=edges_tobe_removed[k];
                for (auto j=0;j<faces.size();j++)
                {
                    auto curr_face=edges[j];
                    if (curr_vis_face.lock()==curr_face)
                    {
                        edges.erase(faces+j);
                    }
                }
            }
            faces.insert(faces.end(),new_faces.begin(),new_faces.end());
            edges.insert(edges.end(),new_edges.begin(),new_edges.end());
        }
        convex_hull.faces=faces;
        return convex_hull;
    }
    template<typename dtype>
    void add_edges_2_faces(std::vector<PolyHedron::face_weak_ptr<dtype>> &new_faces,
            std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> &new_edges,
            std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> &boarder_edges)
    {
        auto new_eds_sz=new_edges.size();
        auto new_faces_sz=new_faces.size();
        auto boarder_sz=boarder_edges.size();
        for (auto j=0;j<boarder_sz;j++)
        {
            auto curr_face=new_faces[j];
            auto curr_boarder_edge=boarder_edges[j];
            curr_face.lock()->add_edge(curr_boarder_edge);
            for (auto k=0;k<new_eds_sz;k++)
            {
                auto curr_new_edges=new_edges[k];
                auto face_verts_begin=curr_face.lock()->vertices.begin();
                auto face_verts_end=curr_face.lock()->vertices.end();
                auto r1=std::find(face_verts_begin,face_verts_end,curr_new_edges.lock()->vertices[0]);
                auto r2=std::find(face_verts_begin,face_verts_end,curr_new_edges.lock()->vertices[1]);
                if (PolyHedron::incident_face_check(curr_face,curr_new_edges))
                {
                    curr_face.lock()->add_edge(curr_new_edges);
                }
            }
        }
    }
    template<typename dtype>
    void add_faces_2_edges(std::vector<PolyHedron::face_weak_ptr<dtype>> &faces,
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> &edges)
    {
        auto eds_sz=edges.size();
        auto faces_sz=faces.size();
        for (auto j=0;j<eds_sz;j++)
        {
            auto curr_edge=edges[j];
            std::vector<PolyHedron::face_weak_ptr<dtype>> incident_faces;
            for (auto k=0;k<faces_sz;k++)
            {
                auto curr_face=faces[k];
                if (PolyHedron::incident_face_check(curr_face,curr_edge))
                {
                    incident_faces.push_back(curr_face);
                }
            }
            curr_edge.lock()->face[0]=std::move(incident_faces[0]);
            curr_edge.lock()->face[0]=std::move(incident_faces[1]);
        }
    }

    template<typename dtype>
    std::vector<PolyHedron::face_weak_ptr<dtype>> get_visible_faces(std::vector<PolyHedron::face_weak_ptr<dtype>> &faces,PolyHedron::vertex_3d_weak_ptr<dtype>&curr_pt)
    {
        std::vector<PolyHedron::face_weak_ptr<dtype>>visible_faces;
            for (int j=0;j<faces.size();j++)
            {
                auto curr_face=faces[j];
                float vol=GeometricUtils::check_face_visibility(curr_face,
                    curr_pt.lock());
                if (CCW_check<dtype>(vol,curr_face.lock()->get_normal_switch()))
                {
                    curr_face.lock()->set_face_visibility(true);
                    visible_faces.push_back(curr_face);
                }
            }
        return visible_faces;

    }
    template<typename dtype>
    std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> remove_edges_from_polyhedron(std::vector<PolyHedron::face_weak_ptr<dtype>>&faces)
    {
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>edges;
        for (int k=0;k<faces.size();k++)
        {
            auto curr_face=faces[k];
            auto curr_face_edges=curr_face.lock()->edges;
            for (int j=0;j<curr_face_edges.size();j++)
            {
                auto f1_vis=curr_face_edges[j].lock()->face[0].lock()->get_face_visibility();
                auto f2_vis=curr_face_edges[j].lock()->face[1].lock()->get_face_visibility();
                if (f1_vis&&f2_vis)
                {
                    edges.push_back(curr_face_edges[j]);
                }
            }
        }
        return edges;

    }
    template<typename dtype>
    std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> set_boarder_for_polyhedron(std::vector<PolyHedron::face_weak_ptr<dtype>>&faces)
    {
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> edges;
        for (int k=0;k<faces.size();k++)
        {
            auto curr_face=faces[k];
            auto curr_face_edges=curr_face.lock()->edges;
            for (int j=0;j<curr_face_edges.size();j++)
            {
                auto f1_vis=curr_face_edges[j].lock()->face[0].lock()->get_face_visibility();
                auto f2_vis=curr_face_edges[j].lock()->face[1].lock()->get_face_visibility();
                if (!(f1_vis&&f2_vis))
                {
                    edges.push_back(curr_face_edges[j]);
                }
            }
        }
        return edges;
    }
    template<typename dtype>
    std::unordered_set<PolyHedron::vertex_3d_weak_ptr<dtype>> get_unique_vertices(std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>&borders)
    {
        auto boarder_sz=borders.size();
        std::unordered_set<PolyHedron::vertex_3d_weak_ptr<dtype>> uniq_verts;
        for (int j=0;j<boarder_sz;j++)
        {
            uniq_verts.insert(borders[j].lock()->vertices[0]);
            uniq_verts.insert(borders[j].lock()->vertices[1]);
        }
        return uniq_verts;
    }
    template<typename dtype>
    std::tuple<std::vector<PolyHedron::face_weak_ptr<dtype>>,std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>> create_new_polyhedron(std::unordered_set<PolyHedron::vertex_3d_weak_ptr<dtype>> &uniq_verts,
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>&boarders,PolyHedron::vertex_3d_weak_ptr<dtype>&vert)
    {
        std::vector<PolyHedron::face_weak_ptr<dtype>>faces;
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>edges;
        typename std::unordered_set<PolyHedron::vertex_3d_weak_ptr<dtype>>::iterator iter;
        auto boarder_sz=boarders.size();
        for (int j=0;j<boarder_sz;j++)
        {
            auto curr_boarder_edge=boarders[j];
            iter=uniq_verts.begin();
            std::advance(iter,j);
            auto edge=PolyHedron::edge_3d_weak_ptr<dtype>(*iter,vert);
            edges.push_back(edge);
            auto face=PolyHedron::face_weak_ptr<dtype>(curr_boarder_edge.lock()->vertices[0],vert,curr_boarder_edge.lock()->vertices[1]);
            faces.push_back(face);
            if (curr_boarder_edge.lock()->face[0].lock()->get_face_visibility())
            {
                curr_boarder_edge.lock()->face[0]=faces[faces.size()-1];
            }
            else
            {
                curr_boarder_edge.lock()->face[1]=faces[faces.size()-1];
            }
        }
        return std::make_tuple(faces,edges);
    }
}