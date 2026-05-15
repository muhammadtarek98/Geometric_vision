#pragma once
#include "geo_utils.hpp"
#include "vector.hpp"
namespace GeometricVision::Line
{
    template<class dtype,size_t dim=DIM3>
    class Line
    {
    private:
        vector::Vector<dtype,dim>point;
        vector::Vector<dtype,dim>direction;
    public:
        Line()=default;
        Line(vector::Vector<dtype,dim>&p1,vector::Vector<dtype,dim>&p2);
        Line(vector::Vector<dtype,dim>&&p1,vector::Vector<dtype,dim>&&p2);
        void set_direction(vector::Vector<dtype,dim> &dir);
        void set_point(Point::point3d &point);
        vector::Vector<dtype,dim> Get_direction() const;
        vector::Vector<dtype,dim>Get_point() const;
        virtual ~Line()=default;


    };
    typedef Line<double,DIM2> line2d;
    typedef Line<double,DIM3> line3d;
}
