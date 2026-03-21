#include "vector.h"
#include <bits/stdc++.h>
#include "core.h"
namespace vector
{
    template <class coordinate_type, size_t dim>
    bool Vector<coordinate_type, dim>::operator==(const Vector<coordinate_type, dim>&other) const
    {
        for (size_t i=0;i<dim;i++)
        {
            if (!is_equal(this->coords[i],other.coords[i]))
            {
                return false;
            }
        }
        return true ;
    }

    template <class coordinate_type, size_t dim>
    bool Vector<coordinate_type, dim>::operator!=(const Vector<coordinate_type, dim>& vect)
    {
        return !(*this==vect);
    }

    template <class coordinate_type, size_t dim>
    Vector<coordinate_type, dim> Vector<coordinate_type, dim>::operator+(const Vector<coordinate_type, dim>& vect) const
    {
        std::array<coordinate_type,dim> coords;
        for (size_t i=0;i<dim;i++)
        {
            coords[i]=this->coords[i]+vect[i];
        }
        return Vector<coordinate_type,dim>(coords);
    }
    template <class coordinate_type, size_t dim>
Vector<coordinate_type, dim> Vector<coordinate_type, dim>::operator-(const Vector<coordinate_type, dim>& other) const
    {
        std::array<coordinate_type,dim> coords;
        for (size_t i=0;i<dim;i++)
        {
            coords[i]=this->coords[i]-other[i];
        }
        return Vector(coords);
    }

    template <class coordinate_type, size_t dims>
    Vector<coordinate_type, dims> Vector<coordinate_type, dims>::operator*(const Vector<coordinate_type, dims>& vect)
    {
        std::array<coordinate_type,dims> coords;
        for (size_t i=0;i<dims;i++)
        {
            coords[i]=this->coords[i]*vect[i];
        }
        return Vector(coords);
    }
    template <class coordinate_type, size_t dims>
    Vector<coordinate_type, dims> Vector<coordinate_type, dims>::operator*(const coordinate_type scalar)
    {
        std::array<coordinate_type,dims> coords;
        for (size_t i=0;i<dims;i++)
        {
            coords[i]=this->coords[i]*scalar;
        }
        return Vector(coords);
    }

    template <class coordinate_type, size_t dim>
    bool Vector<coordinate_type, dim>::operator>(const Vector<coordinate_type, dim>& vect) const
    {
        for (auto i=0;i<dim;i++)
        {
            if (this->coords[i]>vect.coords[i])
            {
                return true;
            }
            else if (this->coords[i]<vect.coords[i])
            {
                return false;
            }
        }
        return false;

    }

    template <class coordinate_type, size_t dim>
    bool Vector<coordinate_type, dim>::operator<(const Vector<coordinate_type, dim>& vect) const
    {
        for (auto i=0;i<dim;i++)
        {
            if (this->coords[i]<vect.coords[i])
            {
                return true;
            }
            else if (this->coords[i]>vect.coords[i])
            {
                return false;
            }
        }
        return false;
    }

    template<class coordinate_type,size_t dims>
    coordinate_type Vector<coordinate_type,dims>::operator[](int idx) const
    {
        if (idx>this->coords.size())
        {
            return coordinate_type();
        }
        return this->coords[idx];
     }
    template<class coordinate_type,size_t dims>
    void Vector<coordinate_type, dims>::assign(int dim, coordinate_type val)
    {
     if (dim>this->coords.size())
     {
         std::cout<<"dim index error\n";
     }
        this->coords[dim]=val;
    }

    template <class coordinate_type, size_t dims>
    double Vector<coordinate_type, dims>::dot_product(const Vector<coordinate_type, dims>& vect1,
                                                     const Vector<coordinate_type, dims>& vect2)
    {
        if (vect1.coords.size()!=vect2.coords.size())
        {
            return FLT_MIN;
        }
        float prod=0.0;
        for (auto i=0;i<vect1.coords.size();i++)
        {
            prod=prod+vect1[i]*vect2[i];
        }
        return prod;
    }
    template<class coordinate_type,size_t dims>
    float Vector<coordinate_type,dims>::magnitude() const
    {
        float mag=0.0;
        for (auto i =0;i<dims;i++)
        {
            mag+=pow(this->coords[i],2);
        }
        return sqrtf(mag);
    }

    template <class coordinate_type, size_t dims>
    void Vector<coordinate_type, dims>::normalization()
    {
        const float mag=this->magnitude();

        for (auto i=0;i<dims;i++)
        {
            this->assign(i,this->coords[i]/mag);
        }
    }

    float cross_product_2D(vect2D v1,vect2D v2)
    {
        return v1[X]*v2[Y]-v1[Y]*v2[X];
    }
    vect3D cross_product_3D(vect3D v1,vect3D v2)
{
    float x = v1[Y] * v2[Z] - v1[Z] * v2[Y];
    float y = v1[Z] * v2[X] - v1[X] * v2[Z];
    float z = v1[X] * v2[Y] - v1[Y] * v2[X];
    return vect3D(x, y, z);
}

    double areaTriangle2D(const vect2D& point1, const vect2D& point2, const vect2D& point3)
    {
        auto point12=point2-point1;
        auto point13=point3-point1;
        return  cross_product_2D(point12,point13)/2;
    }
    int orientation2D(const vect2D& point1, const vect2D& point2, const vect2D& point3)
    {
        auto point12=point2-point1;
        auto point23=point3-point1;
        auto area=areaTriangle2D(point1,point2,point3);
        if (area>0&&area<TOL)
        {
            area=0;
        }
        if (area<0&&area>TOL)
        {
            area=0;
        }
        if (area>0)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
        }
        if (area<0)
        {
              return static_cast<int>(RELATIVE_POINT_POSITION::RIGHT);
        }
        if ((point12[X]*point23[X]<0)||(point12[Y]*point23[Y]<0))
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::BEHIND);

        }
        if (point12.magnitude()<point23.magnitude())
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);
        }
        if (point1==point3)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN);
        }
        if (point2==point3)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
        }
        return 0;
    }

    double scalar_triple_dot_product(const vect3D& v1, const vect3D& v2, const vect3D& v3)
    {
        auto v2_v3_cross_product=cross_product_3D(v2,v3);
        return vect3D::dot_product(v1,v2_v3_cross_product);
    }


    template class Vector<double, 3>;
    template class Vector<double, 2>;
    template class Vector<float, 3>;
    template class Vector<float, 2>;

} // jmk