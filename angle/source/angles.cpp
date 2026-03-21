#include "angles.h"
namespace angle
{
    template<class T,size_t dim>
    static double get_angle(vector::Vector<T,dim>v1,vector::Vector<T,dim>v2)
    {
        auto dot=vector::Vector<T,dim>::dot_product(v1,v2);
        auto rad_angle{acos(dot)};
        return RadToDeg(rad_angle);
    }
    template<class T,size_t dim>
    static double get_angle(vector::Vector<T,dim>&v1,vector::Vector<T,dim>&v2)
    {
        auto dot=vector::Vector<T,dim>::dot_product(v1,v2);
        auto rad_angle{acos(dot)};
        return RadToDeg(rad_angle);
    }
    double calculate_angle_lines_2d( line::line2d& l1, line::line2d& l2)
    {
        return get_angle(l1.Get_direction(),l2.Get_direction());
    }

    double calculate_angle_lines_3d(line::line3d& l1, line::line3d& l2)
    {
        return get_angle(l1.Get_direction(),l2.Get_direction());
    }

    double calculate_angle_plane_and_line(const plane::Plane3D &p,const line::line3d &l)
    {
        auto theta=get_angle(l.Get_direction(),p.get_normal());
        return 90.0-theta;
    }
    double calculate_angle_plane_and_plane(const plane::Plane3D &p1,const plane::Plane3D &p2)
    {
        return get_angle(p1.get_normal(),p2.get_normal());
    }
}
