#pragma once
#include<bits/stdc++.h>
#include "point.hpp"
#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename dtype>
    class Event
    {
    private:
        Point::point_2d_weak_ptr<dtype>point;
    public:
        Event();
        Event(const Event &e);
        Event(const Point::point_2d_weak_ptr<dtype>&p);
        bool operator==(Event &other);
        Point::point_2d_weak_ptr<dtype>get_point();
    };
    template<typename dtype>
struct EventComparator
    {
        bool operator ()(const dtype&e1,const dtype&e2)
        {
            Point::point_2d_weak_ptr<dtype>pt=((dtype&)e1).get_point();
            Point::point_2d_weak_ptr<dtype>other_pt=((dtype&)e2).get_point();
            if ((*pt.lock())[Y]>(*other_pt.lock())[Y])
            {
                return true;
            }
            else if (is_equal((*pt.lock())[Y],(*other_pt.lock())[Y])&&((*pt.lock())[X]<(*other_pt.lock())[X]))
            {
                return true;
            }
            return false;
        }
    };


}