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
    bool Face3D<dtype>::operator==(const Face3D& _other)
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
}
