#include "vertex3D.hpp"
namespace GeometricVision::PolyHedron
{
    template<typename dtype>
    Vertex3D<dtype>::Vertex3D()
    {
        this->point.lock()=nullptr;
        this->processed=false;
    }
    template<typename dtype>
    Vertex3D<dtype>::Vertex3D(Point::point_3d_weak_ptr<dtype>point,bool processed):point(point),
    processed(processed){}
}