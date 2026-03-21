#include "point.h"

namespace  point
{
    bool sort_point2d_left_right_top_bottom(const point2d& a, const point2d& b)
    {
        auto x1=a[X],y1=a[Y],x2=b[X],y2=b[Y];
        if ((x1<x2)||((x1==x2)&&y1<y2))
        {
            return true;
        }
        return false;
    }

    bool sort_point2d_top_bottom_left_right(const point2d& a, const point2d& b)
    {
        auto x1=a[X],y1=a[Y],x2=b[X],y2=b[Y];
        if ((y1>y2)||((y1==y2)&&(x1<x2)))
        {
            return true;
        }
        return false;
    }

    bool sort_point2d_by_y(const point2d& a, const point2d& b)
    {
        auto y1=a[Y],y2=b[Y];
        if (y1<y2)
        {
            return true;
        }
        return false;
    }

    bool sort_point2d_by_x(const point2d& a, const point2d& b)
    {
        auto x1=a[X],x2=b[X];
        if (x1<x2)
        {
            return true;
        }
        return false;
    }

    bool sort_point3d_top_bottom_left_right(const point3d& a, const point3d& b)
    {
        auto x1=a[X],y1=a[Y];
        auto x2=a[X],y2=b[Y];
        if ((y1>y2)||((y1==y2)&&(x1<x2)))
        {
            return true;
        }
        return false;
    }
}
