#pragma once
#include <bits/stdc++.h>
#include "line_segment.hpp"
#include "intersection.hpp"
#include "event.hpp"
#include "Custom_priority_queue.hpp"
namespace GeometricVision::LineSegmentIntersection{
        template<typename dtype,size_t dim=DIM2>
    static std::pair<std::vector<line_seg_weak_ptr>,std::vector<line_seg_weak_ptr>> get_lset_cset(
        std::set<line_seg_weak_ptr,EventComparator<dtype>>&status,Point::point_2d_weak_ptr<dtype,dim> sweep_point);
        template<typename dtype>
        void intersections(std::list<line_seg_weak_ptr> &segments_list,
            std::list<IntersectionPoint<dtype>>);
        template<typename dtype,size_t dim=DIM2>
        static bool is_left(line_seg_weak_ptr cur,line_seg_weak_ptr other,Point::point_2d_weak_ptr<dtype,dim>ref);
        template<typename dtype>
        using sweep_line_iter=std::set<line_seg_weak_ptr,EventComparator<dtype>>::iterator;
    }