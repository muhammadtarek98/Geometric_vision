#include "line_segment_intersection.hpp"

namespace GeometricVision::LineSegmentIntersection{
    static bool is_left(line_seg_weak_ptr cur,line_seg_weak_ptr other,Point::point_2d_weak_ptr ref)
    {
        auto ref_pt=ref.lock();
        return cur.lock()->get_x((*ref_pt)[Y])<other.lock()->get_x((*ref_pt)[Y]);
    }
    template<typename T>

    static std::pair<std::vector<line_seg_weak_ptr>,std::vector<line_seg_weak_ptr>> get_lset_cset(
    std::set<line_seg_weak_ptr,EventComparator<T>>&status,
    Point::point_2d_weak_ptr sweep_point)
    {
        std::vector<line_seg_weak_ptr>l_set,c_set;
        for (auto seg:status)
        {
            auto pos=GeometricVision::vector::orientation2D(seg.lock().get()->get_p1(),seg.lock().get()->get_p2(),sweep_point);
            if (pos==RELATIVE_POINT_POSITION::DESTINATION)
            {
                l_set.push_back(seg);
            }
            else if (pos==RELATIVE_POINT_POSITION::BETWEEN)
            {
                c_set.push_back(seg);
            }
        }
        return std::make_pair(l_set,c_set);

    }
    template<typename T>
    void intersections(std::list<line_seg_weak_ptr> &segments_list,
        std::list<IntersectionPoint> intersection_points){
        CustomPriorityQueue<Event> queue;
        Point::point2d sweep_pt(0.0,0.0);
        Point::point2d prev_pt(0.0,0.0);
        EventComparator<T> comp(&sweep_pt);
        std::set<line_seg_weak_ptr,EventComparator<T>> status_struct(comp);
        for (auto seg:segments_list)
        {
            Event top(seg.lock()->get_p1_weak_ptr());
            Event bot(seg.lock()->get_p2_weak_ptr());
            queue.push(top,seg);
            queue.push(bot);
        }
        Event e;
        std::vector<line_seg_weak_ptr> uset;
        std::vector<line_seg_weak_ptr> lset;
        std::vector<line_seg_weak_ptr> cset;
        if (!queue.empty())
        {
            sweep_pt.assign(X,(*queue.top_event().get_point().lock())[X]);
            sweep_pt.assign(Y,(*queue.top_event().get_point().lock())[Y]);
        }
        while (!queue.empty())
        {
            e=queue.top_event();
            uset=queue.top_seglist();
            prev_pt.assign(X,sweep_pt[X]);
            prev_pt.assign(Y,sweep_pt[Y]);
            sweep_pt.assign(X,(*e.get_point().lock())[X]);
            sweep_pt.assign(Y,(*e.get_point().lock())[Y]);
            auto lset_cset=get_lset_cset(status_struct,sweep_pt);
            lset=lset_cset.first;
            cset=lset_cset.second;
            auto total_size=uset.size()+lset.size()+cset.size();
            if (total_size>1)
            {
                IntersectionPoint intersection_pt;
                intersection_pt.set_point(sweep_pt);
                //intersection_points.erase( )
            }
            sweep_pt.assign(Y,prev_pt[Y]);
            sweep_pt.assign(X,prev_pt[X]);
            std::list<std::pair<sweep_line_iter<T>,sweep_line_iter<T>>> l_pairs;
            
        }

        }
};