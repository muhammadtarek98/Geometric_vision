#include "geo_utils.hpp"
namespace GeometricVision::GeometricUtils
{
    template<typename dtype>

    int orientation2d(const Point::point2d<dtype>& p1, const Point::point2d<dtype>& p2, const Point::point2d<dtype>& p3)
    {
        auto area=area_triangle_2d(p1,p2,p3);
        if (area>0&&area<TOL)
        {
            area=0;
        }
        if (area<0&&area>TOL)
        {
            area=0;
        }
        auto p12=p2-p1;
        auto p13=p3-p1;
        if (area>0.0)
        {
            return  static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
        }
        if (area<0.0)
        {
            return  static_cast<int>(RELATIVE_POINT_POSITION::RIGHT);
        }
        if ((p12[X]*p13[X]<0.0)||(p12[Y]*p13[Y]<0.0))
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::BEHIND);
        }
        if (p12.magnitude(),p13.magnitude())
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);
        }
        if (p1==p3)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN);
        }
        if (p2==p3)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
        }
        return static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN);
    }
    template<typename dtype>

    int orientation3d(const Point::point3d<dtype>& p1, const Point::point3d<dtype>& p2, const Point::point3d<dtype>& p3)
    {
        auto area=area_triangle_3d(p1,p2,p3);
        if ((area>0&&area<TOL)||(area<0&&area>TOL))
        {
            area=0.0;
        }
        auto p1x=p1[X];
        auto p1y=p1[Y];
        auto p2x=p2[X];
        auto p2y=p2[Y];
        if (area>0.0)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
        }
        if (area<0.0)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::RIGHT);
        }
        if ((p1x*p2x<0.0)||(p1y*p2y<0.0))
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::BEHIND);
        }
        if (p1.magnitude()<p2.magnitude())
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);
        }
        if (p1==p3)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN);
        }
        if (p2==p3)
        {
            return static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
        }
        return static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN);

    }
    template<typename dtype>

    bool left2d(const Point::point2d<dtype>& p1, const Point::point2d<dtype>& p2, const Point::point2d<dtype>& p3)
    {
        return orientation2d(p1,p2,p3)==static_cast<bool>(RELATIVE_POINT_POSITION::LEFT);
    }
    template<typename dtype>

    bool left3d(const Point::point3d<dtype>& p1, const Point::point3d<dtype>& p2, const Point::point3d<dtype>& p3)
    {
        return  orientation3d(p1,p2,p3)==static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
    }
    template<typename dtype>

    bool right2d(const Point::point2d<dtype>& p1, const Point::point2d<dtype>& p2, const Point::point2d<dtype>& p3)
    {
        return orientation2d(p1,p2,p3)==static_cast<int>(RELATIVE_POINT_POSITION::RIGHT);
    }
    template<typename dtype>

    bool right3d(const Point::point3d<dtype>& p1, const Point::point3d<dtype>& p2, const Point::point3d<dtype>& p3)
    {
        return orientation3d(p1,p2,p3)==static_cast<int>(RELATIVE_POINT_POSITION::RIGHT);

    }
    template<typename dtype>

    double area_triangle_2d(const Point::point2d<dtype>& p1, const Point::point2d<dtype>& p2, const Point::point2d<dtype>& p3)
    {
        return 0.5 * ((p2[X] - p1[X]) * (p3[Y] - p1[Y]) - (p3[X] - p1[X]) * (p2[Y] - p1[Y]));

    }
    template<typename dtype>

    double area_triangle_3d(const Point::point3d<dtype>& p1, const Point::point3d<dtype>& p2, const Point::point3d<dtype>& p3)
    {
        auto p12 = p2 - p1;
        auto p13 = p3 - p1;
        auto x = p12[Y] * p13[Z] - p12[Z] * p13[Y];
        auto y = p12[X] * p13[Z] - p12[Z] * p13[X];
        auto z = p12[X] * p13[Y] - p12[Y] * p13[X];
        float sum_of_powers = pow(x,2.0) + pow(y, 2.0) + pow(z, 2.0);
        return  sqrt(sum_of_powers)/ 2;
    }

    template<typename dtype>

    bool left_or_between_3d(const Point::point3d<dtype>& p1, const Point::point3d<dtype>& p2, const Point::point3d<dtype>& p3)
    {
        auto position=orientation3d(p1,p2,p3);
        return position==static_cast<int>(RELATIVE_POINT_POSITION::LEFT)||position==static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN);
    }
    template<typename dtype>

    bool left_or_beyond_2d(const Point::point2d<dtype>& p1, const Point::point2d<dtype>& p2, const Point::point2d<dtype>& p3)
    {
        auto position=orientation2d(p1,p2,p3);
        return position==static_cast<int>(RELATIVE_POINT_POSITION::LEFT)||position==static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);

    }
    template<typename dtype>

    bool left_or_beyond_3d(const Point::point3d<dtype>& p1, const Point::point3d<dtype>& p2, const Point::point3d<dtype>& p3)
    {
        auto position=orientation3d(p1,p2,p3);
        return position==static_cast<int>(RELATIVE_POINT_POSITION::LEFT)||position==static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);
    }
    template<typename dtype>

    bool collinear(const vector::vect3D<dtype>& v1, const vector::vect3D<dtype>& v2)
    {
        auto x1=v1[X],y1=v1[Y],z1=v1[Z];
        auto x2=v2[X],y2=v2[Y],z2=v2[Z];
        auto cond1=x1*y2-x2*y1;
        auto cond2=y1*z2-y2*z1;
        auto cond3=x1*z2-x2*z1;
        return is_equal(cond1,0.0) &&is_equal(cond2,0.0)&&is_equal(cond3,0.0);
    }
    template<typename dtype>

    bool collinear(const Point::point3d<dtype>& p1, const Point::point3d<dtype>& p2, const Point::point3d<dtype>& p3)
    {
        auto v1=p2-p1;
        auto v2=p3-p1;
        return collinear<dtype>(v1,v2);
    }
    template<typename dtype>

    bool coplanar(const vector::vect3D<dtype>& v1,const vector::vect3D<dtype>& v2,const vector::vect3D<dtype>& v3)
    {
        auto triple_product=vector::scalar_triple_dot_product<dtype>(v1,v2,v3);
        return is_equal(triple_product,0.0);
    }
    template<typename dtype>

    bool coplanar(const Point::point3d<dtype>& p1, const Point::point3d<dtype>& p2, const Point::point3d<dtype>& p3, const Point::point3d<dtype>& p4)
    {
        auto l1=(p2-p1);
        auto l2=(p3-p1);
        auto l3=(p4-p1);
        return coplanar<dtype>(l1,l2,l3);
    }
    template<typename dtype,size_t dim>
    float signed_visibility_tetrahedron(const DCEL::Face<dtype,dim> &face,const Point::point3d<dtype> &p)
    {
        Point::point3d p1,p2,p3;
    }
// 2D
template int orientation2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
template int orientation2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
template int orientation2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

template bool left2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
template bool left2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
template bool left2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

template bool right2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
template bool right2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
template bool right2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

template bool left_or_beyond_2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
template bool left_or_beyond_2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
template bool left_or_beyond_2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

template double area_triangle_2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
template double area_triangle_2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
template double area_triangle_2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

// 3D
template int orientation3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
template int orientation3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
template int orientation3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

template bool left3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
template bool left3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
template bool left3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

template bool right3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
template bool right3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
template bool right3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

template bool left_or_beyond_3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
template bool left_or_beyond_3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
template bool left_or_beyond_3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

template bool left_or_between_3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
template bool left_or_between_3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
template bool left_or_between_3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

template double area_triangle_3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
template double area_triangle_3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
template double area_triangle_3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

template bool collinear<float>(const vector::vect3D<float>&, const vector::vect3D<float>&);
template bool collinear<double>(const vector::vect3D<double>&, const vector::vect3D<double>&);
template bool collinear<int>(const vector::vect3D<int>&, const vector::vect3D<int>&);

template bool collinear<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
template bool collinear<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
template bool collinear<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

template bool coplanar<float>(const vector::vect3D<float>&, const vector::vect3D<float>&, const vector::vect3D<float>&);
template bool coplanar<double>(const vector::vect3D<double>&, const vector::vect3D<double>&, const vector::vect3D<double>&);
template bool coplanar<int>(const vector::vect3D<int>&, const vector::vect3D<int>&, const vector::vect3D<int>&);

template bool coplanar<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
template bool coplanar<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
template bool coplanar<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

}
