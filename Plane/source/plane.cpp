#include "plane.hpp"
namespace GeometricVision::plane
{
    template <class dtype>
    Plane<dtype>::Plane(const Point::point3d& p1,const  Point::point3d& p2,const  Point::point3d& p3)
    {
        auto p12=p2-p1;
        auto p23=p3-p2;
        this->normal=cross_product_3D(p12,p23);
        this->normal.normalization();
        this->d=vector::vect3D::dot_product(this->normal,p1);
    }
    /*template <class dtype>
        Plane<dtype>::Plane(Point::point3d p1,Point::point3d p2,Point::point3d p3)
        {
            auto p12=p2-p1;
            auto p23=p3-p2;
            this->normal=cross_product_3D(p12,p23);
            this->normal.normalization();
            this->d=vector::vect3D::dot_product(this->normal,p1);
        }*/
    template <class dtype>
    Plane<dtype>::Plane(Point::point3d &&p1, Point::point3d &&p2, Point::point3d &&p3)
    {
        auto p12=p2-p1;
        auto p23=p3-p2;
        this->normal=cross_product_3D(p12,p23);
        this->normal.normalization();
        this->d=vector::vect3D::dot_product(this->normal,p1);
    }
    template <class dtype>
    Plane<dtype>::Plane(const vector::vect3D& vect, float constant):normal(vect),d(constant)
    {
        this->normal.normalization();
    }
    template <class dtype>
    Plane<dtype>::Plane(vector::vect3D&& vect, float constant):normal(vect),d(constant)
    {
        this->normal.normalization();
    }
    template <class dtype>
    float Plane<dtype>::GetD() const
    {
        return this->d;
    }

    template <class dtype>
    vector::vect3D Plane<dtype>::get_normal() const
    {
        return this->normal;
    }

    template class Plane<float>;

}
