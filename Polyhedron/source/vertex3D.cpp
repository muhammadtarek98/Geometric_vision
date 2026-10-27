#include "vertex3D.hpp"
namespace GeometricVision::PolyHedron
{
    template <typename dtype>
    Vertex3D<dtype>::~Vertex3D()
    {

    }

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
    Vertex3D<dtype>::Vertex3D(const Vertex3D& v):point(v.point),processed(v.processed){}
    template <typename dtype>
    Vertex3D<dtype>::Vertex3D(Vertex3D&& v)noexcept:point(std::move(v.point)),processed(std::move(v.processed)){}
    template <typename dtype>
    Vertex3D<dtype>& Vertex3D<dtype>::operator=(const Vertex3D& v)
    {
        if (this!=&v)
        {
            point=v.point;
            processed=v.processed;
        }
        return *this;
    }
    template<typename dtype>
    Vertex3D<dtype>& Vertex3D<dtype>::operator=(Vertex3D&& v)noexcept
    {
        if (this!=&v)
        {
            point=std::move(v.point);
            processed=std::move(v.processed);
        }
        return *this;
    }

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
