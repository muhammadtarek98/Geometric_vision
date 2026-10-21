#include "Edge3D.hpp"
namespace GeometricVision::PolyHedron
{
    template <typename dtype>
    Edge3D<dtype>::Edge3D(vertex_3d_weak_ptr<dtype> p1, vertex_3d_weak_ptr<dtype> p2)
    {
        vertices[0]=p1;
        vertices[1]=p2;
        face={nullptr,nullptr};
    }

    template <typename dtype>
    Edge3D<dtype>::Edge3D()
    {
        vertices={nullptr,nullptr};
        face={nullptr,nullptr};
    }
    template <typename dtype>
    bool  Edge3D<dtype>::operator==(const Edge3D<dtype>& other) {
        if ((this->vertices[0]->point==other.vertices[0]->point)&&
            (this->vertices[1]->point==other.vertices[1]->point))
        {
            return true;
        }
        return false;
    }
}
