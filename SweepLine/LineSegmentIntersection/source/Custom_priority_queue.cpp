#include "Custom_priority_queue.hpp"
#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template <typename T>
    void CustomPriorityQueue<T>::push(T& val)
    {
        std::vector<std::weak_ptr<Segment2D>>v;
        auto second=std::vector<std::weak_ptr<Segment2D>>(val,v);
        this->base_map.insert(std::pair<T,std::vector<std::weak_ptr<Segment2D>>> (val,v));
;
    }

    template <typename T>
    void CustomPriorityQueue<T>::push(T& val, std::weak_ptr<Segment2D> seg)
    {
        std::vector<std::weak_ptr<Segment2D>>v;
        v.push_back(seg);
        std::pair<std::map<T,std::vector<std::weak_ptr<Segment2D>>::iterator>,bool> ret=this->base_map.insert(std::pair<T,
            std::vector<std::weak_ptr<Segment2D>>>(val,v));
        if (false==ret.second)
            ret.first->push_bakc(seg);
        return;
    }

    template <typename T>
    std::vector<std::weak_ptr<Segment2D>> CustomPriorityQueue<T>::top_seglist()
    {
        return base_map.begin()->second;
    }

    template<typename T>
    void CustomPriorityQueue<T>::pop()
    {
        base_map.erase(base_map.begin());
    }

    template <typename T>
    bool CustomPriorityQueue<T>::empty()
    {
        return base_map.empty();
    }

    template <typename T>
    T CustomPriorityQueue<T>::top_event()
    {
        return base_map.begin();
    }
}
