#pragma once
#include "point.hpp"
#include "vector.hpp"
namespace GeometricVision::plane
{
    template<class coord_type>
    class Plane
    {
    private:
        vector::vect3D normal;
        float d;
    public:
        Plane()=default;
        Plane(const vector::vect3D &vect,float constant);
        Plane(vector::vect3D &&vect,float constant);
        Plane(const point::point3d& p1,const point::point3d &p2,const point::point3d &p3);
        Plane(point::point3d &&p1,point::point3d &&p2,point::point3d &&p3);
        vector::vect3D get_normal() const;
        float GetD() const;
        virtual ~Plane()=default;
    };
    typedef Plane<float> Plane3D;

}
