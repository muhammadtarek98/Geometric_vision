#include "face.hpp"
namespace GeometricVision::PolyHedron
{
    template <typename dtype>
    Face3D<dtype>::Face3D(vertex_3d_weak_ptr<dtype> p1, vertex_3d_weak_ptr<dtype> p2, vertex_3d_weak_ptr<dtype> p3)
    {
        vertices[0]=p1;
        vertices[1]=p2;
        vertices[2]=p3;
        plane_=plane_(p1->point,p2->point,p3->point);
        visible = false;
        normal_switch_needed=false;
    }

    template <typename dtype>
    Face3D<dtype>::~Face3D()
    {

    }

    template <typename dtype>
    bool Face3D<dtype>:: operator==(const Face3D& _other)
    {
        if (vertices.size()!=_other.vertices.size())
        {
            return false;
        }
        bool ret=true;
        for (auto i=0;i<vertices.size();i++)
        {
            if (vertices[i]->point!=_other.vertices[i]->point)
            {
                ret=false;
                break;
            }
        }
        return ret;
    }

    template <typename dtype>
    void Face3D<dtype>::add_edge(edge_3d_weak_ptr<dtype> edge)
    {
        edges.push_back(edge);
    }
    template<typename dtype>
    bool Face3D<dtype>::get_normal_switch()
    {
        return this->normal_switch_needed;
    }

    template <typename dtype>
    void Face3D<dtype>::set_face_visibility(bool vis)
    {
        this->visible=vis;
    }

    template <typename dtype>
    bool Face3D<dtype>::get_face_visibility()
    {
        return this->visible;
    }

    template <typename dtype>
    Face3D<dtype>::Face3D(Face3D&& f) noexcept
    {
        edges=std::move(f.edges);
        vertices=std::move(f.vertices);
        plane_=std::move(f.plane_);
        normal_switch_needed=std::move(f.normal_switch_needed);
        visible=std::move(f.visible);
    }
    template <typename dtype>
        Face3D<dtype>::Face3D(const Face3D& f):edges(f.edges),vertices(f.vertices),plane_(f.plane_)
    ,normal_switch_needed(f.normal_switch_needed),visible(f.vertices)
    {}
    template <typename dtype>
    Face3D<dtype>& Face3D<dtype>::operator=(const Face3D& f)
    {
     if (this!=&f)
     {
      edges=f.edges;
         vertices=f.vertices;
         plane_=f.plane_;
         visible=f.visible;
         normal_switch_needed=f.normal_switch_needed;

     }
        return *this;
    }
    template <typename dtype>
    Face3D<dtype>& Face3D<dtype>::operator=(Face3D&& f)noexcept
    {
        if (this!=&f)
        {
            edges=std::move(f.edges);
            vertices=std::move(f.vertices);
            plane_=std::move(f.plane_);
            normal_switch_needed=std::move(f.normal_switch_needed);
            visible=std::move(f.visible);
        }
        return *this;

    }
}
