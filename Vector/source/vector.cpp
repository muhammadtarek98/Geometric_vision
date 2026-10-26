#include "vector.hpp"
namespace GeometricVision::vector
{
    template <typename  dtype, size_t dim>
    Vector<dtype, dim>& Vector<dtype, dim>::operator=(const Vector<dtype, dim>& vec)
    {
        if (&vec==this)
        {
            return *this;
        }

        this->coords=vec.coords;
        return *this;

    }

    template <typename dtype, size_t dims>
    Vector<dtype, dims>& Vector<dtype, dims>::operator=(Vector&& vec)noexcept
    {
        if (this==&vec)
        {
            return *this;
        }
        this->coords.swap(vec.coords);
        return *this;
    }

    template <typename  dtype, size_t dim>
     const bool Vector<dtype, dim>::operator==(const Vector&other)const
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
     const bool Vector<dtype, dim>::operator!=(const Vector& vect)const
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
    signed int Vector<dtype, dim>::num_dims()const
    {
        return this->coords.size();
    }

    template <typename dtype, size_t dim>
    const char* Vector<dtype, dim>::get_dtype()
    {
        return typeid(this->coords[0]).name();
    }

    template <typename dtype, size_t dim>
    Vector<dtype, dim> Vector<dtype, dim>::operator*(const Vector & vect) const
    {
        std::array<dtype,dim> coords;
        for (size_t i=0;i<dim;i++)
        {
            coords[i]=this->coords[i]*vect[i];
        }
        return Vector(coords);
    }
    template <typename dtype, size_t dim>
    Vector<dtype, dim> Vector<dtype, dim>::operator*(dtype scalar)const
    {
        std::array<dtype,dim> coords;
        for (size_t i=0;i<dim;i++)
        {
            coords[i]=this->coords[i]*scalar;
        }
        return Vector(coords);
    }

    template <typename dtype, size_t dim>
     const bool Vector<dtype, dim>::operator>(const Vector& vect)const
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
     const bool Vector<dtype, dim>::operator<(const Vector& vect)const
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
    const dtype Vector<dtype,dim>::operator[](int idx)const
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
    dtype Vector<dtype, dim>::dot_product(const Vector<dtype, dim>& vect1,const Vector<dtype, dim>& vect2)
    {
        if (vect1.coords.size()!=vect2.coords.size())
        {
            return FLT_MIN;
        }
        dtype prod=0.0;
        for (auto i=0;i<vect1.coords.size();i++)
        {
            prod=prod+vect1[i]*vect2[i];
        }
        return prod;
    }
    template<typename dtype>
dtype dot_product(const vect3D<dtype> &vect1, const vect3D<dtype> &vect2) {
        return Vector<dtype, DIM3>::dot_product(vect1, vect2);
    }

    template<typename dtype>
    dtype dot_product(const vect2D<dtype> &vect1, const vect2D<dtype> &vect2) {
        return Vector<dtype, DIM2>::dot_product(vect1, vect2);
    }


    template<typename dtype,size_t dim>
    dtype Vector<dtype,dim>::magnitude() const
    {
        dtype mag=0.0;
        for (auto i =0;i<dim;i++)
        {
            mag+=pow(this->coords[i],2);
        }
        return sqrtf(mag);
    }

    template <typename dtype, size_t dim>
    void Vector<dtype, dim>::normalization()
    {
        const dtype mag=this->magnitude();

        for (auto i=0;i<dim;i++)
        {
            this->assign(i,this->coords[i]/mag);
        }
    }

    template<typename dtype>
    dtype cross_product_2D(vect2D<dtype> v1, vect2D<dtype> v2)
    {
        return v1[X]*v2[Y]-v1[Y]*v2[X];
    }
    template<typename dtype>
vect3D<dtype> cross_product_3D(vect3D<dtype> v1, vect3D<dtype> v2)
    {
        dtype x = v1[Y] * v2[Z] - v1[Z] * v2[Y];
        dtype y = v1[Z] * v2[X] - v1[X] * v2[Z];
        dtype z = v1[X] * v2[Y] - v1[Y] * v2[X];
        return vect3D<dtype>(x, y, z);
    }
    template<typename dtype>
double areaTriangle2D(const vect2D<dtype> &point1,const vect2D<dtype> &point2,const vect2D<dtype> &point3)
    {
        auto point12=point2-point1;
        auto point13=point3-point1;
        return  cross_product_2D<dtype>(point12,point13)/2;
    }

    template<typename dtype>
    int orientation2D(const vect2D<dtype>& point1, const vect2D<dtype>& point2, const vect2D<dtype>& point3)
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

    template<typename dtype>
    dtype scalar_triple_dot_product(const vect3D<dtype> &v1,const vect3D<dtype> &v2,const vect3D<dtype> &v3)
    {
        auto v2_v3_cross_product=cross_product_3D<dtype>(v2,v3);
        return vect3D<dtype>::dot_product(v1,v2_v3_cross_product);
    }
    // ========== Explicit instantiations for free functions ==========
    template float cross_product_2D<float>(vect2D<float>, vect2D<float>);
    template double cross_product_2D<double>(vect2D<double>, vect2D<double>);
    template int cross_product_2D<int>(vect2D<int>, vect2D<int>);
    template vect3D<float> cross_product_3D<float>(vect3D<float>, vect3D<float>);
    template vect3D<double> cross_product_3D<double>(vect3D<double>, vect3D<double>);
    template vect3D<int> cross_product_3D<int>(vect3D<int>, vect3D<int>);

    template float scalar_triple_dot_product<float>(const vect3D<float>&, const vect3D<float>&, const vect3D<float>&);
    template double scalar_triple_dot_product<double>(const vect3D<double>&, const vect3D<double>&, const vect3D<double>&);
    template int scalar_triple_dot_product<int>(const vect3D<int>&, const vect3D<int>&, const vect3D<int>&);

    template double areaTriangle2D<float>(const vect2D<float>&, const vect2D<float>&, const vect2D<float>&);
    template double areaTriangle2D<double>(const vect2D<double>&, const vect2D<double>&, const vect2D<double>&);
    template double areaTriangle2D<int>(const vect2D<int>&, const vect2D<int>&, const vect2D<int>&);

    template int orientation2D<float>(const vect2D<float>&, const vect2D<float>&, const vect2D<float>&);
    template int orientation2D<double>(const vect2D<double>&, const vect2D<double>&, const vect2D<double>&);
    template int orientation2D<int>(const vect2D<int>&, const vect2D<int>&, const vect2D<int>&);
template float dot_product<float>(const vect3D<float>&, const vect3D<float>&);
template double dot_product<double>(const vect3D<double>&, const vect3D<double>&);
template int dot_product<int>(const vect3D<int>&, const vect3D<int>&);
    template float dot_product<float>(const vect2D<float>&, const vect2D<float>&);
    template double dot_product<double>(const vect2D<double>&, const vect2D<double>&);
    template int dot_product<int>(const vect2D<int>&, const vect2D<int>&);

    template class Vector<float, 2>;
    template class Vector<float, 3>;
    template class Vector<double, 2>;
    template class Vector<double, 3>;
    template class Vector<int, 2>;
    template class Vector<int, 3>;

}