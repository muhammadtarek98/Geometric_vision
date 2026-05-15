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
        bool operator==(const Vector& vect)const;
        signed int num_dims();
        auto get_dtype();
        bool operator!=(const Vector&vect);
        bool operator<(const Vector& vect) const;
        bool operator>(const Vector&vect)const;
        Vector operator+(const Vector& vect)const;
        Vector operator-(const Vector& vect)const;
        Vector operator*(const Vector&vect);
        Vector operator*(const dtype scalar);
        dtype operator[](int idx)const;
        //assign dim value
        void assign(int dim,dtype val);
        //dot product operation
        static double dot_product(const Vector &vect1,const Vector &vect2);
        //magnitude
        float magnitude() const;
        //normalization
        void normalization();

        virtual ~Vector()=default;
    };
    typedef Vector<double,DIM2> vect2D;
    typedef Vector<double> vect3D;
    float cross_product_2D(vect2D v1, vect2D v2);
    vect3D cross_product_3D(vect3D v1, vect3D v2);
    double dot_product(const vect3D &vect1,const vect3D &vect2);
    double dot_product(const vect2D &vect1,const vect2D &vect2);
    double scalar_triple_dot_product(const vect3D &v1,const vect3D &v2,const vect3D &v3);
    double areaTriangle2D(const vect2D &point1,const vect2D &point2,const vect2D &point3);
    int orientation2D(const vect2D& point1, const vect2D& point2, const vect2D& point3);
    template<typename dtype,size_t dim>
    using vector_weak_ptr=std::weak_ptr<Vector<dtype,dim>>;
    template<typename dtype,size_t dim>
    using vector_shared_ptr=std::shared_ptr<Vector<dtype,dim>>;
    template<typename dtype,size_t dim>
    using vector_unique_ptr=std::unique_ptr<Vector<dtype,dim>>;

}
