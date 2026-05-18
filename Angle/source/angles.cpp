#include "angles.hpp"
namespace GeometricVision::Angle
{
    template<typename  dtype,size_t dim>
     double get_angle(vector::Vector<dtype,dim>v1,vector::Vector<dtype,dim>v2)
    {
        auto dot=vector::Vector<dtype,dim>::dot_product(v1,v2);
        auto rad_angle{acos(dot)};
        return RadToDeg(rad_angle);
    }
    template<typename dtype>

    double calculate_angle_lines_2d(const Line::line2d<dtype>& l1, const Line::line2d<dtype>& l2)
    {
        return get_angle(l1.Get_direction(),l2.Get_direction());
    }
    template<typename dtype>

    double calculate_angle_lines_3d(const Line::line3d<dtype>& l1, const Line::line3d<dtype>& l2)
    {
        return get_angle(l1.Get_direction(),l2.Get_direction());
    }
    template<typename dtype>

    double calculate_angle_plane_and_line(const plane::Plane3D<dtype> &p,const Line::line3d<dtype> &l)
    {
        auto theta=get_angle(l.Get_direction(),p.get_normal());
        return 90.0-theta;
    }

    template<typename dtype>
    double calculate_angle_plane_and_plane(const plane::Plane3D<dtype> &p1,const plane::Plane3D<dtype> &p2)
    {
        return get_angle(p1.get_normal(),p2.get_normal());
    }

    template<typename dtype>
    double polar_angle_2D(const Point::point2d<dtype> &src, const Point::point2d<dtype> &dst)    {
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
    // ========== Explicit instantiations ==========
    // get_angle is called internally; its instantiations are covered by the functions below.
    // But if you use get_angle directly, instantiate it for dim=2 and 3.

    template double calculate_angle_lines_2d<float>(const Line::line2d<float>&, const Line::line2d<float>&);
    template double calculate_angle_lines_2d<double>(const Line::line2d<double>&, const Line::line2d<double>&);
    template double calculate_angle_lines_2d<int>(const Line::line2d<int>&, const Line::line2d<int>&);

    template double calculate_angle_lines_3d<float>(const Line::line3d<float>&, const Line::line3d<float>&);
    template double calculate_angle_lines_3d<double>(const Line::line3d<double>&, const Line::line3d<double>&);
    template double calculate_angle_lines_3d<int>(const Line::line3d<int>&, const Line::line3d<int>&);

    template double calculate_angle_plane_and_line<float>(const plane::Plane3D<float>&, const Line::line3d<float>&);
    template double calculate_angle_plane_and_line<double>(const plane::Plane3D<double>&, const Line::line3d<double>&);
    template double calculate_angle_plane_and_line<int>(const plane::Plane3D<int>&, const Line::line3d<int>&);

    template double calculate_angle_plane_and_plane<float>(const plane::Plane3D<float>&, const plane::Plane3D<float>&);
    template double calculate_angle_plane_and_plane<double>(const plane::Plane3D<double>&, const plane::Plane3D<double>&);
    template double calculate_angle_plane_and_plane<int>(const plane::Plane3D<int>&, const plane::Plane3D<int>&);

    template double polar_angle_2D<float>(const Point::point2d<float>&, const Point::point2d<float>&);
    template double polar_angle_2D<double>(const Point::point2d<double>&, const Point::point2d<double>&);
    template double polar_angle_2D<int>(const Point::point2d<int>&, const Point::point2d<int>&);
}
