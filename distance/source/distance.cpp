#include "distance.h"
namespace GeometricVision::Distance
{
    float distance_line_and_point(Line::line3d& l,point::point3d& p)
    {
        auto vect=p-l.Get_point();
        auto t=vector::vect3D::dot_product(l.Get_direction(),vect);
        auto xt=l.Get_point()+l.Get_direction()*t;
        return (xt-p).magnitude();
    }

    float distance_point_plane(point::point3d& point, plane::Plane3D& p)
    {
        auto result=vector::vect3D::dot_product(p.get_normal(),point)-p.GetD();
        return result;
    }

}
