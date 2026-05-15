#include "vector.hpp"
namespace GeometricVision::vector
{
    template <typename  dtype, size_t dim>
    bool Vector<dtype, dim>::operator==(const Vector&other) const
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

    template <typename dtype, size_t dim>
    bool Vector<dtype, dim>::operator!=(const Vector& vect)
    {
        return !(*this==vect);
    }

    template <typename dtype, size_t dim>
    Vector<dtype, dim> Vector<dtype, dim>::operator+(const Vector& vect) const
    {
        std::array<dtype,dim> coords;
        for (size_t i=0;i<dim;i++)
        {
            coords[i]=this->coords[i]+vect[i];
        }
        return Vector<dtype,dim>(coords);
    }
    template <typename dtype, size_t dim>
    Vector<dtype, dim> Vector<dtype, dim>::operator-(const Vector& other) const
    {
        std::array<dtype,dim> coords;
        for (size_t i=0;i<dim;i++)
        {
            coords[i]=this->coords[i]-other[i];
        }
        return Vector(coords);
    }
    template<typename dtype,size_t dim>
    signed int Vector<dtype, dim>::num_dims()
    {
        return this->coords.size();
    }

    template <typename dtype, size_t dim>
    auto Vector<dtype, dim>::get_dtype()
    {
        return typeid(this->coords[0]).name();
    }

    template <typename dtype, size_t dim>
    Vector<dtype, dim> Vector<dtype, dim>::operator*(const Vector & vect)
    {
        std::array<dtype,dim> coords;
        for (size_t i=0;i<dim;i++)
        {
            coords[i]=this->coords[i]*vect[i];
        }
        return Vector(coords);
    }
    template <typename dtype, size_t dim>
    Vector<dtype, dim> Vector<dtype, dim>::operator*(const dtype scalar)
    {
        std::array<dtype,dim> coords;
        for (size_t i=0;i<dim;i++)
        {
            coords[i]=this->coords[i]*scalar;
        }
        return Vector(coords);
    }

    template <typename dtype, size_t dim>
    bool Vector<dtype, dim>::operator>(const Vector& vect) const
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

    template <typename dtype, size_t dim>
    bool Vector<dtype, dim>::operator<(const Vector& vect) const
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

    template<typename dtype,size_t dim>
    dtype Vector<dtype,dim>::operator[](int idx) const
    {
        if (idx>this->coords.size())
        {
            return dtype();
        }
        return this->coords[idx];
    }
    template<typename dtype,size_t dim>
    void Vector<dtype, dim>::assign(int idx, dtype val)
    {
        if (idx>this->coords.size())
        {
            std::cout<<"dim index error\n";
        }
        this->coords[idx]=val;
    }

    template <typename dtype, size_t dim>
    double Vector<dtype, dim>::dot_product(const Vector& vect1,
                                            const Vector& vect2)
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
    double dot_product(const vect3D &vect1,const vect3D &vect2)
    {
        return Vector<double>::dot_product(vect1,vect2);
    }
    double  dot_product(const vect2D &vect1,const vect2D &vect2)
    {
        return Vector<double,DIM2>::dot_product(vect1,vect2);
    }

    template<class dtype,size_t dim>
    float Vector<dtype,dim>::magnitude() const
    {
        float mag=0.0;
        for (auto i =0;i<dim;i++)
        {
            mag+=pow(this->coords[i],2);
        }
        return sqrtf(mag);
    }

    template <class dtype, size_t dim>
    void Vector<dtype, dim>::normalization()
    {
        const float mag=this->magnitude();

        for (auto i=0;i<dim;i++)
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
        if ((area>0&&area<TOL)||(area<0&&area>TOL))
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

}
