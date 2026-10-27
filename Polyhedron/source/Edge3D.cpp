#include "Edge3D.hpp"
namespace GeometricVision::PolyHedron
{
    template <typename dtype>
    Edge3D<dtype>::Edge3D(vertex_3d_weak_ptr<dtype> p1, vertex_3d_weak_ptr<dtype> p2)
    {
        vertices[0]=p1;
        vertices[1]=p2;
        face={face_weak_ptr<dtype>(),face_weak_ptr<dtype>()};
    }

    template <typename dtype>
    Edge3D<dtype>::Edge3D()
    {
        vertices={vertex_3d_weak_ptr<dtype>(),vertex_3d_weak_ptr<dtype>()};
        face={face_weak_ptr<dtype>(),face_weak_ptr<dtype>()};
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

    template <typename dtype>
    Edge3D<dtype>::~Edge3D()
    {

    }

    template <typename dtype>
    Edge3D<dtype>::Edge3D(Edge3D&& e)noexcept
    {
        vertices=std::move(e.vertices);
        face=std::move(e.face);
    }

    template <typename dtype>
    Edge3D<dtype>::Edge3D(const Edge3D& e):vertices(e.vertices),face(e.face){}

    template <typename dtype>
    Edge3D<dtype>& Edge3D<dtype>::operator=(const Edge3D& e)
    {
        if (this!=&e)
        {
            vertices=e.vertices;
            face=e.face;
        }
        return *this;
    }
    template <typename dtype>
    Edge3D<dtype>& Edge3D<dtype>::operator=(Edge3D&&e)noexcept
    {
        if (this!=&e)
        {
            vertices=std::move(e.vertices);
            face=std::move(e.face);
        }
        return *this;
    }
}
