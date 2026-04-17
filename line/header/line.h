#pragma once
#include "geo_utils.h"
#include "vector.h"
namespace GeometricVision::Line
{
    template<class coord_type,size_t dim=DIM3>
    class Line
    {
    private:
        vector::Vector<coord_type,dim>point;
        vector::Vector<coord_type,dim>direction;
    public:
        Line()=default;
        Line(vector::Vector<coord_type,dim>&p1,vector::Vector<coord_type,dim>&p2);
        Line(vector::Vector<coord_type,dim>&&p1,vector::Vector<coord_type,dim>&&p2);
        void set_direction(vector::Vector<coord_type,dim> &dir);
        void set_point(point::point3d &point);
        vector::Vector<coord_type,dim> Get_direction() const;
        vector::Vector<coord_type,dim>Get_point() const;
        virtual ~Line()=default;


    };
    typedef Line<double,DIM2> line2d;
    typedef Line<double,DIM3> line3d;
}
