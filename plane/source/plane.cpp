#include "plane.h"
namespace GeometricVision::plane
{
    template <class coord_type>
    Plane<coord_type>::Plane(const point::point3d& p1,const  point::point3d& p2,const  point::point3d& p3)
    {
        auto p12=p2-p1;
        auto p23=p3-p2;
        this->normal=cross_product_3D(p12,p23);
        this->normal.normalization();
        this->d=vector::vect3D::dot_product(this->normal,p1);
    }
    /*template <class coord_type>
        Plane<coord_type>::Plane(point::point3d p1,point::point3d p2,point::point3d p3)
        {
            auto p12=p2-p1;
            auto p23=p3-p2;
            this->normal=cross_product_3D(p12,p23);
            this->normal.normalization();
            this->d=vector::vect3D::dot_product(this->normal,p1);
        }*/
    template <class coord_type>
    Plane<coord_type>::Plane(point::point3d &&p1, point::point3d &&p2, point::point3d &&p3)
    {
        auto p12=p2-p1;
        auto p23=p3-p2;
        this->normal=cross_product_3D(p12,p23);
        this->normal.normalization();
        this->d=vector::vect3D::dot_product(this->normal,p1);
    }
    template <class coord_type>
    Plane<coord_type>::Plane(const vector::vect3D& vect, float constant):normal(vect),d(constant)
    {
        this->normal.normalization();
    }
    template <class coord_type>
    Plane<coord_type>::Plane(vector::vect3D&& vect, float constant):normal(vect),d(constant)
    {
        this->normal.normalization();
    }
    template <class coord_type>
    float Plane<coord_type>::GetD() const
    {
        return this->d;
    }

    template <class coord_type>
    vector::vect3D Plane<coord_type>::get_normal() const
    {
        return this->normal;
    }

    template class Plane<float>;

}
