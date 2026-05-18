#pragma once
#include "geo_utils.hpp"
#include "vector.hpp"
namespace GeometricVision::Line
{
    template<typename dtype,size_t dim>
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
        void set_point(vector::Vector<dtype,dim> &point); // Changed from Point::point3d<dtype>
        vector::Vector<dtype,dim> Get_direction() const;
        vector::Vector<dtype,dim>Get_point() const;
        virtual ~Line()=default;
    };
    template<typename dtype>
    using line2d=Line<dtype,DIM2>;
    template<typename dtype>
    using  line3d=Line<dtype,DIM3>;
}
