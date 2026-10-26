#include "distance.hpp"
namespace GeometricVision::Distance
{
    template<typename dtype,size_t dim>
    dtype squared_distance(vector::Vector<dtype,dim>&v1,vector::Vector<dtype,dim>&v2)
    {
        if (dim!=DIM3||dim!=DIM2)
        {
            std::cerr<<"only handle 2D and 3D vectors\n";
            return vector::Vector<dtype,dim>() ;
        }
        auto x_dist=(v1[X]-v2[X])*(v1[X]-v2[X]);
        auto y_dist=(v1[Y]-v2[Y])*(v1[Y]-v2[Y]);
        return dim==DIM2?x_dist+y_dist:((v1[Z]-v2[Z])*v1[Z]-v2[Z])+x_dist+y_dist;
    }
    template<typename dtype>
    float distance_line_and_point(const Line::line3d<dtype>& l, const Point::point3d<dtype>& p)
    {
        auto vect=p-l.Get_point();
        auto t=vector::vect3D<dtype>::dot_product(l.Get_direction(),vect);
        auto xt=l.Get_point()+l.Get_direction()*t;
        return (xt-p).magnitude();
    }
    template<typename dtype>
    float distance_point_plane(const Point::point3d<dtype>& point,const plane::Plane3D<dtype>& p)
    {
        auto result=vector::vect3D<dtype>::dot_product(p.get_normal(),point)-p.GetD();
        return result;
    }
    template float distance_line_and_point<float>(const Line::line3d<float>&, const Point::point3d<float>&);
    template float distance_line_and_point<double>(const Line::line3d<double>&, const Point::point3d<double>&);
    template float distance_line_and_point<int>(const Line::line3d<int>&, const Point::point3d<int>&);

    template float distance_point_plane<float>(const Point::point3d<float>&, const plane::Plane3D<float>&);
    template float distance_point_plane<double>(const Point::point3d<double>&, const plane::Plane3D<double>&);
    template float distance_point_plane<int>(const Point::point3d<int>&, const plane::Plane3D<int>&);
}
