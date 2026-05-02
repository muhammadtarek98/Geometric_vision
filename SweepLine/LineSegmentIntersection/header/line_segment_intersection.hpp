#pragma once
#include <bits/stdc++.h>
#include "line_segment.hpp"
#include "intersection.hpp"
#include "event.hpp"
#include "Custom_priority_queue.hpp"
namespace GeometricVision
{
    namespace LineSegmentIntersection{
        template<typename T>
    static std::pair<std::vector<line_seg_weak_ptr>,std::vector<line_seg_weak_ptr>> get_lset_cset(
        std::set<line_seg_weak_ptr,EventComparator<T>>&status,Point::point_2d_weak_ptr sweep_point);
        void intersections(std::list<line_seg_weak_ptr> &segments_list,
            std::list<IntersectionPoint>);
        static bool is_left(line_seg_weak_ptr cur,line_seg_weak_ptr other,Point::point_2d_weak_ptr);
        template<typename T>
        using sweep_line_iter=std::set<line_seg_weak_ptr,EventComparator<T>>::iterator;
    }
}