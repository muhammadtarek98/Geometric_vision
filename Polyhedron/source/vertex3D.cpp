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

    template <typename dtype>
    void Vertex3D<dtype>::set_processed(bool f)
    {
        this->processed=f;
    }

    template <typename dtype>
    bool Vertex3D<dtype>::get_processed()
    {
        return this->processed;
    }


}
