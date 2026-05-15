#pragma once
#include <bits/stdc++.h>
#include "event.hpp"
#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename dtype>
    class CustomPriorityQueue
    {
    private:
        std::map<dtype,std::vector<std::weak_ptr<Segment2D>>,EventComparator<dtype>> base_map;
    public:
        void push (dtype&val);
        void push(dtype &val,std::weak_ptr<Segment2D>set);
        dtype top_event();
        std::vector<std::weak_ptr<Segment2D>> top_seglist();
        void pop();
        bool empty();
    };
}