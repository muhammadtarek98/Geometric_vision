#include "line.h"
namespace line
{
    template<class coord_type,size_t dim>
    Line<coord_type,dim>::Line(vector::Vector<coord_type,dim>&p1,vector::Vector<coord_type,dim>&p2)
    {
        direction=p2-p1;
        direction.normalization();
        point=p1;
    }

    template <class coord_type, size_t dim>
    void Line<coord_type, dim>::set_direction(vector::Vector<coord_type, dim>& dir)
    {
        this->direction.assign(X,dir[X]);
        this->direction.assign(Y,dir[Y]);
        this->direction.assign(Z,dir[Z]);
    }

    template <class coord_type, size_t dim>
    void Line<coord_type, dim>::set_point(point::point3d& point)
    {
        this->point.assign(X,point[X]);
        this->point.assign(Y,point[Y]);
        this->point.assign(Z,point[Z]);
    }


    template <class coord_type, size_t dim>
    vector::Vector<coord_type,dim> Line<coord_type, dim>::Get_direction()   const
    {
        return this->direction;
    }
    template <class coord_type, size_t dim>
    vector::Vector<coord_type, dim> Line<coord_type, dim>::Get_point() const
    {
        return this->point;
    }
    template class Line<double, 2>;
    template class Line<double, 3>;
}
