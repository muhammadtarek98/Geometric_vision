#include "angles.hpp"
namespace GeometricVision::Angle
{
    template<class T,size_t dim>
    static double get_angle(vector::Vector<T,dim>v1,vector::Vector<T,dim>v2)
    {
        auto dot=vector::Vector<T,dim>::dot_product(v1,v2);
        auto rad_angle{acos(dot)};
        return RadToDeg(rad_angle);
    }
    double calculate_angle_lines_2d(const Line::line2d& l1, const Line::line2d& l2)
    {
        return get_angle(l1.Get_direction(),l2.Get_direction());
    }

    double calculate_angle_lines_3d(const Line::line3d& l1, const Line::line3d& l2)
    {
        return get_angle(l1.Get_direction(),l2.Get_direction());
    }

    double calculate_angle_plane_and_line(const plane::Plane3D &p,const Line::line3d &l)
    {
        auto theta=get_angle(l.Get_direction(),p.get_normal());
        return 90.0-theta;
    }
    double calculate_angle_plane_and_plane(const plane::Plane3D &p1,const plane::Plane3D &p2)
    {
        return get_angle(p1.get_normal(),p2.get_normal());
    }

    double polar_angle_2D(const Point::point2d &src, const Point::point2d &dst)
    {
        auto _x=src[X]-dst[X];
        auto _y=src[Y]-dst[Y];
        if (is_equal(_x,0.0)&&is_equal(_y,0.0))
        {
            return -1.0;
        }
        if (is_equal(_x,0.0))
        {
            return _y>0.0?90.0:270.0;
        }
        auto theta=atan(_y/_x);
        theta=RadToDeg(theta);
        if (_x>0.0)
        {
            return _y>=0.0?theta:360.0+theta;
        }
        return 180.0+theta;
    }
}
