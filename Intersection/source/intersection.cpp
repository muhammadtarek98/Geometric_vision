#include "intersection.hpp"
namespace GeometricVision::Intersection
{
    template<typename dtype>
    bool intersection(const std::tuple<Point::point2d<dtype>,Point::point2d<dtype>>& l1,
                      const std::tuple<Point::point2d<dtype>,Point::point2d<dtype>>& l2)
    {
        auto p11=std::get<0>(l1), p12=std::get<1>(l1);
        auto p21=std::get<0>(l2),p22=std::get<1>(l2);
        // compare the point 3 against line 1_2
        auto orient_1_2_3=orientation2D(p11,p12,p21);
        // compare the point 4 against line 1_2
        auto orient_1_2_4=orientation2D(p11,p12,p22);
        // compare the point 1 against line 3_4
        auto orient_3_4_1=orientation2D(p21,p22,p11);
        // compare the point 2 against line 3_4
        auto orient_3_4_2=orientation2D(p22,p21,p12);
        bool test_1=orient_1_2_3==static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN)||
            orient_1_2_3==static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN)||
            orient_1_2_3==static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
        bool test_2=orient_1_2_4==static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN)||
            orient_1_2_4==static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN)||
            orient_1_2_4==static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
        bool test_3=orient_3_4_1==static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN)||
            orient_3_4_1==static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN)||
            orient_3_4_1==static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
        bool  test_4=orient_3_4_2==static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN)||
            orient_3_4_2==static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN)||
            orient_3_4_2==static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
        if (test_1||test_2||test_3||test_4)
        {
            return true;
        }
        auto left_1_2_3=orient_1_2_3==static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
        auto left_1_2_4=orient_1_2_4==static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
        auto left_3_4_1=orient_3_4_1==static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
        auto left_3_4_2=orient_3_4_2==static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
        return _xor(left_1_2_3,left_1_2_4)&& _xor(left_3_4_1,left_3_4_2);}
    template<typename dtype>

    bool intersection(const Point::point2d<dtype> &p1,const Point::point2d<dtype> &p2,const Point::point2d<dtype> &p3,const Point::point2d<dtype> &p4)
    {
        std::tuple<Point::point2d<dtype>,Point::point2d<dtype>> l1{std::make_tuple(p1,p2)};
        std::tuple<Point::point2d<dtype>,Point::point2d<dtype>> l2{std::make_tuple(p3,p4)};
        return intersection(l1,l2);
    }
    template<typename dtype>
    bool intersection(const Point::point2d<dtype> &p1,const Point:: point2d<dtype> &p2, const Point::point2d<dtype>& p3,
        const Point::point2d<dtype> &p4,Point::point2d<dtype> &intersection_point)
    {
        vector::vect2D<dtype> p12=p2-p1;
        vector::vect2D<dtype> p34=p4-p3;
        vector::vect2D<dtype> normal{p34[Y],-p34[X]};
        auto dem=vector::vect2D<dtype>::dot_product(normal,p12);
        if (!is_equal(dem,0.0))
        {
            auto p13=p3-p1;
            auto num= vector::vect2D<dtype>::dot_product(normal,p13);
            auto t=num/dem;
            auto x=p1[X]+t*p12[X];
            auto y=p1[Y]+t*p12[Y];
            intersection_point.assign(X,x);
            intersection_point.assign(Y,y);
            return true;
        }
             return false;
    }
    template<typename dtype>

    bool intersection(const Line::line2d<dtype> &l1,const Line::line2d<dtype> &l2, Point::point2d <dtype>& intersection_point)
    {
        Point::point2d<dtype> start_l1 = l1.Get_point();
        Point::point2d<dtype> end_l1 = start_l1 + l1.Get_direction();
        Point::point2d<dtype> start_l2 = l2.Get_point();
        Point::point2d<dtype> end_l2 = start_l2 + l2.Get_direction();
        return intersection(start_l1, end_l1, start_l2, end_l2, intersection_point);
    }
    template<typename dtype>

    bool intersection(const Line::line3d<dtype> &l1,const Line::line3d<dtype> &l2, Point::point3d <dtype>&intersection_point)
    {
        auto p1 = l1.Get_point();
        auto d1 = l1.Get_direction();
        auto p2 = l2.Get_point();
        auto d2 = l2.Get_direction();

        auto d1xd2 = vector::cross_product_3D<dtype>(d1, d2);
        auto mag2 = d1xd2.magnitude() * d1xd2.magnitude();

        if (is_equal(mag2, 0.0)) {
            return false;
        }

        auto p2p1 = p2 - p1;
        auto num = vector::scalar_triple_dot_product<dtype>(p2p1, d2, d1xd2);
        auto t = num / mag2;

        auto p_on_l1 = p1 + d1 * t;
        auto p2p_on_l1 = p_on_l1 - p2;
        auto dist = vector::cross_product_3D<dtype>(p2p_on_l1, d2).magnitude();

        if (is_equal(dist, 0.0)) {
            intersection_point = p_on_l1;
            return true;
        }
        return false;
    }
    template<typename dtype>

    Point::point3d<dtype> plane_line_intersection(const Line::line3d<dtype> &l, const plane::Plane3D<dtype> &p)
    {
        auto plane_normal=p.get_normal();
        auto line_origin=l.Get_point();
        auto line_dir=l.Get_direction();
        auto d=p.GetD();
        if ( vector::vect3D<dtype>::dot_product(plane_normal,line_dir)==0)
        {
            return vector::vect3D<dtype>(INFINITY,INFINITY,INFINITY);

        }
        auto t1=((-1*vector::vect3D<dtype>::dot_product(plane_normal,
                                                 line_origin)+d)/vector::vect3D<dtype>::dot_product(plane_normal,line_dir));
        auto x=line_origin[X]+line_dir[X]*t1;
        auto y=line_origin[Y]+line_dir[Y]*t1;
        auto z=line_origin[Z]+line_dir[Z]*t1;
        return Point::point3d<dtype>(x,y,z);
    }
    template<typename dtype>

    Line::line3d<dtype> plane_plane_intersection(const plane::Plane3D<dtype> &p1, const plane::Plane3D<dtype> &p2)
    {
        auto n1=p1.get_normal(),n2=p2.get_normal();
        auto d1=p1.GetD(),d2=p2.GetD();
        auto line_dir=vector::cross_product_3D<dtype>(n1,n2);
        if (is_equal(line_dir.magnitude(),0.0))
        {
            Point::point3d<dtype> inf_pt(INFINITY, INFINITY, INFINITY);
            return Line::line3d<dtype>(inf_pt, inf_pt);
        }
        auto dot=vector::vect3D<dtype>::dot_product(n1,n2);
        auto n1xn2=pow(dot,2);
        auto a=(d2*n1xn2-d1)/(dot-1);
        auto b=(d1*n1xn2-d1)/(n1xn2-1);
        auto point=n1*a+n2*b;
        Line::line3d<dtype> l;
        l.set_point(point);
        line_dir.normalization();
        l.set_direction(line_dir);
        return l;
    }
// 4-point intersection
template bool intersection<float>(const Point::point2d<float>&, const Point::point2d<float>&,
                                  const Point::point2d<float>&, const Point::point2d<float>&,
                                  Point::point2d<float>&);
template bool intersection<double>(const Point::point2d<double>&, const Point::point2d<double>&,
                                   const Point::point2d<double>&, const Point::point2d<double>&,
                                   Point::point2d<double>&);
template bool intersection<int>(const Point::point2d<int>&, const Point::point2d<int>&,
                                const Point::point2d<int>&, const Point::point2d<int>&,
                                Point::point2d<int>&);

// line2d + line2d
template bool intersection<float>(const Line::line2d<float>&, const Line::line2d<float>&, Point::point2d<float>&);
template bool intersection<double>(const Line::line2d<double>&, const Line::line2d<double>&, Point::point2d<double>&);
template bool intersection<int>(const Line::line2d<int>&, const Line::line2d<int>&, Point::point2d<int>&);

// line3d + line3d
template bool intersection<float>(const Line::line3d<float>&, const Line::line3d<float>&, Point::point3d<float>&);
template bool intersection<double>(const Line::line3d<double>&, const Line::line3d<double>&, Point::point3d<double>&);
template bool intersection<int>(const Line::line3d<int>&, const Line::line3d<int>&, Point::point3d<int>&);

// plane + line
template Point::point3d<float> plane_line_intersection<float>(const Line::line3d<float>&, const plane::Plane3D<float>&);
template Point::point3d<double> plane_line_intersection<double>(const Line::line3d<double>&, const plane::Plane3D<double>&);
template Point::point3d<int> plane_line_intersection<int>(const Line::line3d<int>&, const plane::Plane3D<int>&);

// plane + plane
template Line::line3d<float> plane_plane_intersection<float>(const plane::Plane3D<float>&, const plane::Plane3D<float>&);
template Line::line3d<double> plane_plane_intersection<double>(const plane::Plane3D<double>&, const plane::Plane3D<double>&);
template Line::line3d<int> plane_plane_intersection<int>(const plane::Plane3D<int>&, const plane::Plane3D<int>&);
}
