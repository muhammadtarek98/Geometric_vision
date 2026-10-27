#include "plane.hpp"
namespace GeometricVision::plane
{
    template <typename dtype>
    Plane<dtype>::Plane(const Point::point3d<dtype>& p1,const  Point::point3d<dtype>& p2,const  Point::point3d<dtype>& p3)
    {
        auto p12=p2-p1;
        auto p23=p3-p2;
        this->normal=vector::cross_product_3D<dtype>(p12,p23);
        this->normal.normalization();
        this->d=vector::vect3D<dtype>::dot_product(this->normal,p1);
    }
    template <typename dtype>
    Plane<dtype>::Plane(Point::point3d<dtype> &&p1, Point::point3d<dtype> &&p2, Point::point3d<dtype> &&p3)
    {
        auto p12=p2-p1;
        auto p23=p3-p2;
        this->normal=vector::cross_product_3D<dtype>(p12,p23);
        this->normal.normalization();
        this->d=vector::dot_product(this->normal,p1);
    }

    template <typename dtype>
    Plane<dtype>& Plane<dtype>::operator=(const Plane& other)
    {
        if (this!=&other)
        {
            this->normal=other.normal;
            this->d=other.d;
        }
        return *this;

    }
    template <typename dtype>
    Plane<dtype>& Plane<dtype>::operator=(Plane&&other)noexcept
    {
        if (this!=&other)
        {
            this->normal=std::move(other.normal);
            this->d=std::move(other.d);
        }
        return *this;

    }
    template <typename dtype>
    Plane<dtype>::Plane(const Plane<dtype>&other):normal(other.normal),d(other.d)
    {}
    template<typename dtype>
    Plane<dtype>::Plane(Plane&&other)noexcept:normal(std::move(other.normal)),d(std::move(other.d))
    {}

    template <typename dtype>
    Plane<dtype>::Plane(const vector::vect3D<dtype> & vect, float constant):normal(vect),d(constant)
    {
        this->normal.normalization();
    }
    template <typename dtype>
    Plane<dtype>::Plane(vector::vect3D<dtype> && vect, float constant):normal(vect),d(constant)
    {
        this->normal.normalization();
    }
    template <typename dtype>
    float Plane<dtype>::GetD() const
    {
        return this->d;
    }

    template <typename dtype>
    vector::vect3D<dtype> Plane<dtype>::get_normal() const
    {
        return this->normal;
    }

    template class Plane<float>;
    template class Plane<double>;
    template class Plane<int>;   // if you use int planes
}
