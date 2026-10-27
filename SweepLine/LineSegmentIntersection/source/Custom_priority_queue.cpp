#include "Custom_priority_queue.hpp"
#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template <typename dtype>
    CustomPriorityQueue<dtype>::CustomPriorityQueue(const CustomPriorityQueue& q):
    base_map(q.base_map){}

    template <typename dtype>
    CustomPriorityQueue<dtype>::CustomPriorityQueue(CustomPriorityQueue&& q) noexcept:
    base_map(std::move(base_map)){}

    template <typename dtype>
    CustomPriorityQueue<dtype>& CustomPriorityQueue<dtype>::operator=(const CustomPriorityQueue& q)
    {
        if (this!=&q)
        {
            base_map=q.base_map;
        }
        return *this;
    }

    template <typename dtype>
    CustomPriorityQueue<dtype>& CustomPriorityQueue<dtype>::operator=(CustomPriorityQueue&& q) noexcept
    {
        if (this!=&q)
        {
            base_map=std::move(q.base_map);
        }
        return *this;
    }

    template <typename dtype>
    void CustomPriorityQueue<dtype>::push(dtype& val)
    {
        // Insert the event 'val' with an empty vector of segments.
        // If 'val' already exists, this does nothing.
        this->base_map.insert({val, std::vector<std::weak_ptr<Segment2D>>()});
    }

    template <typename dtype>
    void CustomPriorityQueue<dtype>::push(dtype& val, std::weak_ptr<Segment2D> seg)
    {
        // Find or insert the event 'val' with an empty vector if it doesn't exist.
        // 'it' is an iterator to the element, 'inserted' is true if a new element was inserted.
        auto [it, inserted] = this->base_map.insert({val, std::vector<std::weak_ptr<Segment2D>>()});

        // Add the segment to the vector associated with 'val'
        it->second.push_back(seg);
    }

    template <typename dtype>
    std::vector<std::weak_ptr<Segment2D>> CustomPriorityQueue<dtype>::top_seglist()
    {
        // Check if the map is empty before dereferencing begin()
        if (base_map.empty()) {
            // Depending on desired behavior, could throw an exception or return an empty vector.
            // For now, returning an empty vector for safety.
            return {};
        }
        return base_map.begin()->second;
    }

    template<typename dtype>
    void CustomPriorityQueue<dtype>::pop()
    {
        if (!base_map.empty()) {
            base_map.erase(base_map.begin());
        }
    }

    template <typename dtype>
    bool CustomPriorityQueue<dtype>::empty()
    {
        return base_map.empty();
    }

    template <typename dtype>
    dtype CustomPriorityQueue<dtype>::top_event()
    {
        // Check if the map is empty before dereferencing begin()
        if (base_map.empty()) {
            // Depending on desired behavior, could throw an exception or return a default-constructed T.
            // For now, assuming T is default constructible or caller ensures map is not empty.
            // A more robust solution might involve returning std::optional<dtype>.
            return dtype(); // Return a default-constructed T if empty
        }
        return base_map.begin()->first;
    }
}
