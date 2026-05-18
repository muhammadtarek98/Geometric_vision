#include "point.hpp"
namespace GeometricVision::Point
{
    template<typename dtype>
    bool sort_point2d_left_right_top_bottom(const point2d<dtype>& a, const point2d<dtype>& b)
    {
        auto x1=a[X],y1=a[Y],x2=b[X],y2=b[Y];
        if ((x1<x2)||((x1==x2)&&y1<y2))
        {
            return true;
        }
        return false;
    }
    template<typename dtype>
    bool sort_point2d_top_bottom_left_right(const point2d<dtype>& a, const point2d<dtype>& b)
    {
        auto x1=a[X],y1=a[Y],x2=b[X],y2=b[Y];
        if ((y1>y2)||((y1==y2)&&(x1<x2)))
        {
            return true;
        }
        return false;
    }
    template<typename dtype>
    bool sort_point2d_by_y(const point2d<dtype>& a, const point2d<dtype>& b)
    {
        auto y1=a[Y],y2=b[Y];
        if (y1<y2)
        {
            return true;
        }
        return false;
    }
    template<typename dtype>
    bool sort_point2d_by_x(const point2d<dtype>& a, const point2d<dtype>& b)
    {
        auto x1=a[X],x2=b[X];
        if (x1<x2)
        {
            return true;
        }
        return false;
    }
    template<typename dtype>
    bool sort_point3d_top_bottom_left_right(const point3d<dtype>& a, const point3d<dtype>& b)
    {
        auto x1=a[X],y1=a[Y];
        auto x2=a[X],y2=b[Y];
        if ((y1>y2)||((y1==y2)&&(x1<x2)))
        {
            return true;
        }
        return false;
    }
    template bool sort_point2d_left_right_top_bottom<float>(const point2d<float>&, const point2d<float>&);
    template bool sort_point2d_left_right_top_bottom<double>(const point2d<double>&, const point2d<double>&);
    template bool sort_point2d_left_right_top_bottom<int>(const point2d<int>&, const point2d<int>&);

    template bool sort_point2d_top_bottom_left_right<float>(const point2d<float>&, const point2d<float>&);
    template bool sort_point2d_top_bottom_left_right<double>(const point2d<double>&, const point2d<double>&);
    template bool sort_point2d_top_bottom_left_right<int>(const point2d<int>&, const point2d<int>&);

    template bool sort_point2d_by_x<float>(const point2d<float>&, const point2d<float>&);
    template bool sort_point2d_by_x<double>(const point2d<double>&, const point2d<double>&);
    template bool sort_point2d_by_x<int>(const point2d<int>&, const point2d<int>&);

    template bool sort_point2d_by_y<float>(const point2d<float>&, const point2d<float>&);
    template bool sort_point2d_by_y<double>(const point2d<double>&, const point2d<double>&);
    template bool sort_point2d_by_y<int>(const point2d<int>&, const point2d<int>&);

    template bool sort_point3d_top_bottom_left_right<float>(const point3d<float>&, const point3d<float>&);
    template bool sort_point3d_top_bottom_left_right<double>(const point3d<double>&, const point3d<double>&);
    template bool sort_point3d_top_bottom_left_right<int>(const point3d<int>&, const point3d<int>&);

}
