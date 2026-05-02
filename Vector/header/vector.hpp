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

    template<class coordinate_type,size_t dims=DIM3>
    class Vector
    {
        static_assert(std::is_arithmetic_v<coordinate_type>,"vector has to be integer or float");
        static_assert(dims>=DIM2,"vector has to be 2D or more");
    private:
        std::array<coordinate_type,dims> coords;
    public:
        Vector()=default;
        Vector(std::array<coordinate_type,dims>_coords):coords(_coords){};
        template<size_t D = dims, typename = typename std::enable_if<D == 3>::type>
        Vector(coordinate_type x,coordinate_type y,coordinate_type z):coords({x,y,z}){};
        template<size_t D = dims, typename = typename std::enable_if<D == 2>::type>
        Vector(coordinate_type x,coordinate_type y):coords({x,y}){};
        bool operator==(const Vector& vect)const;
        signed int num_dims();
        auto dtype();
        bool operator!=(const Vector&vect);
        bool operator<(const Vector& vect) const;
        bool operator>(const Vector&vect)const;
        Vector operator+(const Vector& vect)const;
        Vector operator-(const Vector& vect)const;
        Vector operator*(const Vector&vect);
        Vector operator*(const coordinate_type scalar);
        coordinate_type operator[](int idx)const;
        //assign dim value
        void assign(int dim,coordinate_type val);
        //dot product operation
        static double dot_product(const Vector &vect1,const Vector &vect2);
        //magnitude
        float magnitude() const;
        //normalization
        void normalization();

        virtual ~Vector()=default;
    };
    typedef Vector<double,DIM2> vect2D;
    typedef Vector<double,DIM3> vect3D;
    float cross_product_2D(vect2D v1, vect2D v2);
    vect3D cross_product_3D(vect3D v1, vect3D v2);
    double dot_product(const vect3D &vect1,const vect3D &vect2);
    double dot_product(const vect2D &vect1,const vect2D &vect2);
    double scalar_triple_dot_product(const vect3D &v1,const vect3D &v2,const vect3D &v3);
    double areaTriangle2D(const vect2D &point1,const vect2D &point2,const vect2D &point3);
    int orientation2D(const vect2D& point1, const vect2D& point2, const vect2D& point3);
}
