#include "distance.hpp"
namespace GeometricVision::Distance
{
    float distance_line_and_point(const Line::line3d& l, const Point::point3d& p)
    {
        auto vect=p-l.Get_point();
        auto t=vector::vect3D::dot_product(l.Get_direction(),vect);
        auto xt=l.Get_point()+l.Get_direction()*t;
        return (xt-p).magnitude();
    }

    float distance_point_plane(const Point::point3d& point,const plane::Plane3D& p)
    {
        auto result=vector::vect3D::dot_product(p.get_normal(),point)-p.GetD();
        return result;
    }

}
