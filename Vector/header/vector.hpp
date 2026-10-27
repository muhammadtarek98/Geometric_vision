#pragma once
#include <bits/stdc++.h>
#include "core.hpp"
#include <typeinfo>
#define DIM3 3
#define DIM2 2
#define X 0
#define Y 1
#define Z 2
namespace GeometricVision::vector
{

    template<typename dtype,size_t dims=DIM3>
    class Vector
    {
        static_assert(std::is_arithmetic_v<dtype>,"vector has to be integer or float");
        static_assert(dims>=DIM2,"vector has to be 2D or more");
    private:
        std::array<dtype,dims> coords;
    public:
        Vector()=default;
        Vector(std::array<dtype,dims>_coords):coords(_coords){};
        template<size_t D = dims, typename = typename std::enable_if<D == 3>::type>
        Vector(dtype x,dtype y,dtype z):coords({x,y,z}){};
        template<size_t D = dims, typename = typename std::enable_if<D == 2>::type>
        Vector(dtype x,dtype y):coords({x,y}){};
        Vector(const Vector&vec):coords(vec.coords){};
        Vector(Vector &&vec)noexcept;
        Vector&operator=(const Vector&vec);
        Vector&operator=(Vector&&vec) noexcept ;
        signed int num_dims()const ;
        const char* get_dtype() ;
        const bool operator==(const Vector& vect)const;
         const bool operator!=(const Vector&vect)const;
         const bool operator<(const Vector& vect)const;
         const bool operator>(const Vector&vect)const;
        Vector operator+(const Vector& vect)const;
        Vector operator-(const Vector& vect)const;
        Vector operator*(const Vector&vect)const;
        Vector operator*(dtype scalar)const;
        const dtype operator[](int idx)const;
        //assign dim value
        void assign(int dim,dtype val);
        //dot product operation
        static dtype dot_product(const Vector<dtype, dims> &vect1,const Vector<dtype, dims> &vect2);
        //magnitude
        dtype magnitude() const;
        //normalization
        void normalization();
        ~Vector()=default;

    };
    template<typename dtype,size_t dim=DIM2>
    using vect2D=Vector<dtype,dim>;
    template<typename dtype,size_t dim=DIM3>
    using vect3D=Vector<dtype,dim>;
    template<typename dtype,size_t dim>
    using vector_weak_ptr=std::weak_ptr<Vector<dtype,dim>>;
    template<typename dtype,size_t dim>
    using vector_shared_ptr=std::shared_ptr<Vector<dtype,dim>>;
    template<typename dtype,size_t dim>
    using vector_unique_ptr=std::unique_ptr<Vector<dtype,dim>>;
    template<typename dtype>
    dtype cross_product_2D(vect2D<dtype> v1, vect2D<dtype> v2);
    template<typename dtype>
    vect3D<dtype> cross_product_3D(vect3D<dtype> v1, vect3D<dtype> v2);
    template<typename dtype>
    dtype dot_product(const vect3D<dtype> &vect1,const vect3D<dtype> &vect2);
    template<typename dtype>
    dtype dot_product(const vect2D<dtype> &vect1,const vect2D<dtype> &vect2);
    template<typename dtype>
    dtype scalar_triple_dot_product(const vect3D<dtype> &v1,const vect3D<dtype> &v2,const vect3D<dtype> &v3);
    template<typename dtype>
    double areaTriangle2D(const vect2D<dtype> &point1,const vect2D<dtype> &point2,const vect2D<dtype> &point3);
    template<typename dtype>
    int orientation2D(const vect2D<dtype>& point1, const vect2D<dtype>& point2, const vect2D<dtype>& point3);
    template<typename dtype,size_t dim>
    dtype scalar_triple_dot_product(const Vector<dtype,dim> &v1,const Vector<dtype,dim> &v2,const Vector<dtype,dim>  &v3);
}
