#pragma once
#include <bits/stdc++.h>
#include "event.hpp"
#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template<typename T>
    class CustomPriorityQueue
    {
    private:
        std::map<T,std::vector<std::weak_ptr<Segment2D>>,EventComparator<T>> base_map;
    public:
        void push (T&val);
        void push(T &val,std::weak_ptr<Segment2D>set);
        T top_event();
        std::vector<std::weak_ptr<Segment2D>> top_seglist();
        void pop();
        bool empty();
    };
}