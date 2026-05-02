#include "gift_warpping.hpp"
namespace GeometricVision::ConvexHull
{
    std::vector<Point::point2d> gift_wrapping2D(const std::vector<Point::point2d>& point_set)
    {
        std::vector<Point::point2d> convex_hull;
        if (point_set.size()<=3)
        {
            return convex_hull;
        }
        auto bottom_pt=point_set[0];
        for (auto & point :point_set)
        {
            if (point[Y]<bottom_pt[Y]||((point[Y]==bottom_pt[Y]) &&(point[X]<bottom_pt[X])))
            {
                bottom_pt=point;
            }
        }
        auto min_polar_pt=point_set[0];
        auto curr_polar_angle= 360.0;
        for (auto &point :point_set)
        {
             auto polar_angle=Angle::polar_angle_2D(point,bottom_pt);
            if (bottom_pt!=point&&curr_polar_angle>polar_angle)
            {
                curr_polar_angle=polar_angle;
                min_polar_pt=point;
            }
        }
        convex_hull.push_back(bottom_pt);
        convex_hull.push_back(min_polar_pt);
        auto ref_pt=min_polar_pt;
        int idx_before_last=0;
         while (true)
         {
             curr_polar_angle=360.0;
             for (auto &point:point_set)
             {
                 Point::point2d vec1=ref_pt-convex_hull[idx_before_last];
                 Point::point2d vec2=point-ref_pt;
                 auto vec_1_vec_2_angle=Angle::get_angle(vec1,vec2);
                 if (ref_pt!=point&& curr_polar_angle&&curr_polar_angle>vec_1_vec_2_angle)
                 {
                     curr_polar_angle=vec_1_vec_2_angle;
                     min_polar_pt=point;
                 }
             }
             if (min_polar_pt==bottom_pt)
             {
                 break;
             }
             idx_before_last++;
             convex_hull.push_back(min_polar_pt);
             ref_pt=min_polar_pt;
         }
        return convex_hull;
    }
}