#include "grahams.hpp"
namespace GeometricVision::ConvexHull::ConvexHull2D
{
    bool SortComparator::operator()(Point::point2d p1, Point::point2d p2)
    {
        if ((p1[X]<p2[X])||((p1[X]==p2[X]) &&(p1[Y]<p2[Y])))
        {
            return true;
        }
        return false;
    }

    std::vector<Point::point2d> upper_hull_constructions(std::vector<Point::point2d>& points)
    {
        std::vector<Point::point2d> upper_hull_pts;
        if (points.size()<=3)
        {
            return upper_hull_pts;
        }
        std::sort(points.begin(),points.end(),SortComparator());
        upper_hull_pts.push_back(*points.begin());
        upper_hull_pts.push_back(*(std::next(points.begin())));

        int idx=0;
        for (auto i=2;i<points.size();i++)
        {
            idx=upper_hull_pts.size();
            auto next_pt=points[i];
            while (upper_hull_pts.size()>1&&GeometricUtils::left2d(upper_hull_pts[idx-2],upper_hull_pts[idx-1],next_pt))
            {
                upper_hull_pts.pop_back();
                idx=upper_hull_pts.size();
            }
            upper_hull_pts.push_back(next_pt);
        }
        upper_hull_pts.pop_back();
        return upper_hull_pts;
    }

    std::vector<Point::point2d> lower_hull_constructions(std::vector<Point::point2d>& points)
    {
            std::vector<Point::point2d> lower_hull_pts;
            if (points.size()<=3)
            {
                return lower_hull_pts;
            }
        std::sort(points.begin(),points.end(),SortComparator());
        std::reverse(points.begin(),points.end());
        lower_hull_pts.push_back(*points.begin());
        lower_hull_pts.push_back(*(std::next(points.begin())));
        int idx=0;

        for (auto i=2;i<points.size();i++)
        {
            idx=lower_hull_pts.size();
            auto next_pt=points[i];
            while (lower_hull_pts.size()>1&&GeometricUtils::left2d(lower_hull_pts[idx-2],lower_hull_pts[idx-1],next_pt))
            {
                lower_hull_pts.pop_back();
                idx=lower_hull_pts.size();
            }
            lower_hull_pts.push_back(next_pt);
        }
        lower_hull_pts.pop_back();
        return lower_hull_pts;
    }

    std::vector<Point::point2d> graham_convex_hull_construction(std::vector<Point::point2d>& points)
    {
        std::vector<Point::point2d> convex_hull;
        auto upper_hull=upper_hull_constructions(points);
        auto lower_hull=lower_hull_constructions(points);
        convex_hull.insert(convex_hull.end(),upper_hull.begin(),upper_hull.end());
        convex_hull.insert(convex_hull.end(),lower_hull.begin(),lower_hull.end());
        return convex_hull;
    }
}
