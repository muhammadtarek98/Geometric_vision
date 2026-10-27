#pragma once
#include "point.hpp"
#include "vector.hpp"
namespace GeometricVision::plane
{
    template<typename dtype>
    class Plane
    {
    private:
        vector::vect3D<dtype> normal;
        dtype d;
    public:
        Plane()=default;
        Plane(const vector::vect3D<dtype> &vect,float constant);
        Plane(vector::vect3D<dtype>  &&vect,float constant);
        Plane(const Point::point3d<dtype>& p1,const Point::point3d<dtype> &p2,const Point::point3d<dtype> &p3);
        Plane(Point::point3d<dtype> &&p1,Point::point3d<dtype> &&p2,Point::point3d<dtype> &&p3);
        Plane(const Plane &other);
        Plane (Plane &&other)noexcept;
        Plane& operator=(const Plane&other);
        Plane& operator=(Plane&&other)noexcept;
        vector::vect3D<dtype> get_normal() const;
        float GetD() const;
        virtual ~Plane()=default;
    };
    template<typename dtype>
    using Plane3D=Plane<dtype>;
}
