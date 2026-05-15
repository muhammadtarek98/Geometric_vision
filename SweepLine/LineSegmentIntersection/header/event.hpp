#pragma once
#include<bits/stdc++.h>
#include "point.hpp"
#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    class Event
    {
    private:
        std::weak_ptr<Point::point2d> point;
    public:
        Event();
        Event(const Event &e);
        Event(const std::weak_ptr<Point::point2d>&p);
        bool operator==(Event &other);
        std::weak_ptr<Point::point2d>get_point();
    };
    template<typename dtype>
struct EventComparator
    {
        bool operator ()(const dtype&e1,const dtype&e2)
        {
            std::weak_ptr<Point::point2d>pt=((dtype&)e1).get_point();
            std::weak_ptr<Point::point2d>other_pt=((dtype&)e2).get_point();
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