#include "line.hpp"
namespace GeometricVision::Line
{
    template<typename dtype,size_t dim>
    Line<dtype,dim>::Line()
    {
        direction=vector::Vector<dtype,dim>();
        point=vector::Vector<dtype,dim>();
    }
    template<typename dtype,size_t dim>
    Line<dtype,dim>::Line(const vector::Vector<dtype,dim>&p1,const vector::Vector<dtype,dim>&p2):point(p1)
    {
        direction=p2-p1;
        direction.normalization();
    }
    template <typename dtype, size_t dim>
    void Line<dtype, dim>::set_direction(vector::Vector<dtype, dim>& dir)
    {
        this->direction.assign(X,dir[X]);
        this->direction.assign(Y,dir[Y]);
        this->direction.assign(Z,dir[Z]);
    }

    template <typename dtype, size_t dim>
    Line<dtype, dim>& Line<dtype, dim>::operator=(Line&& l)noexcept
    {
        if (&l!=this)
        {
            this->direction=std::move(l.direction);
            this->point=std::move(l.point);
        }

        return *this;
    }
    template <typename dtype, size_t dim>
    Line<dtype, dim>& Line<dtype, dim>::operator=(const Line&l)
    {
        if (&l!=this)
        {
            this->direction=l.direction;
            this->point=l.point;
        }

        return *this;
    }
    template<typename dtype,size_t dim>
    Line<dtype,dim>::Line(const Line& other):point(other.point),direction(other.direction)
    {
    }
    template<typename dtype,size_t dim>
    Line<dtype,dim>::Line( Line&& other)noexcept:point(std::move(other.point)),
    direction(std::move(other.direction)){}


    template <typename dtype, size_t dim>
    Line<dtype, dim>::~Line()
    {

    }


    template <typename dtype, size_t dim>
    void Line<dtype, dim>::set_point(vector::Vector<dtype,dim> &point)
    {
        this->point.assign(X,point[X]);
        this->point.assign(Y,point[Y]);
        this->point.assign(Z,point[Z]);
    }
    template <typename dtype, size_t dim>
    vector::Vector<dtype,dim> Line<dtype, dim>::Get_direction()   const
    {
        return this->direction;
    }
    template <typename dtype, size_t dim>
    vector::Vector<dtype, dim> Line<dtype, dim>::Get_point() const
    {
        return this->point;
    }
    template class Line<float, 2>;
    template class Line<float, 3>;
    template class Line<double, 2>;
    template class Line<double, 3>;
    template class Line<int, 2>;
    template class Line<int, 3>;
}
