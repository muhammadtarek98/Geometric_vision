#include "line.hpp"
namespace GeometricVision::Line
{
    template<class dtype,size_t dim>
    Line<dtype,dim>::Line(vector::Vector<dtype,dim>&p1,vector::Vector<dtype,dim>&p2)
    {
        direction=p2-p1;
        direction.normalization();
        point=p1;
    }

    template <class dtype, size_t dim>
    void Line<dtype, dim>::set_direction(vector::Vector<dtype, dim>& dir)
    {
        this->direction.assign(X,dir[X]);
        this->direction.assign(Y,dir[Y]);
        this->direction.assign(Z,dir[Z]);
    }

    template <class dtype, size_t dim>
    void Line<dtype, dim>::set_point(Point::point3d& point)
    {
        this->point.assign(X,point[X]);
        this->point.assign(Y,point[Y]);
        this->point.assign(Z,point[Z]);
    }


    template <class dtype, size_t dim>
    vector::Vector<dtype,dim> Line<dtype, dim>::Get_direction()   const
    {
        return this->direction;
    }
    template <class dtype, size_t dim>
    vector::Vector<dtype, dim> Line<dtype, dim>::Get_point() const
    {
        return this->point;
    }
    template class Line<double, DIM2>;
    template class Line<double, DIM3>;
}
