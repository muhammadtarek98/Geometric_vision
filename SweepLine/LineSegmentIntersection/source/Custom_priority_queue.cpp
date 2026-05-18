#include "Custom_priority_queue.hpp"
#include "line_segment.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template <typename T>
    void CustomPriorityQueue<T>::push(T& val)
    {
        // Insert the event 'val' with an empty vector of segments.
        // If 'val' already exists, this does nothing.
        this->base_map.insert({val, std::vector<std::weak_ptr<Segment2D>>()});
    }

    template <typename T>
    void CustomPriorityQueue<T>::push(T& val, std::weak_ptr<Segment2D> seg)
    {
        // Find or insert the event 'val' with an empty vector if it doesn't exist.
        // 'it' is an iterator to the element, 'inserted' is true if a new element was inserted.
        auto [it, inserted] = this->base_map.insert({val, std::vector<std::weak_ptr<Segment2D>>()});

        // Add the segment to the vector associated with 'val'
        it->second.push_back(seg);
    }

    template <typename T>
    std::vector<std::weak_ptr<Segment2D>> CustomPriorityQueue<T>::top_seglist()
    {
        // Check if the map is empty before dereferencing begin()
        if (base_map.empty()) {
            // Depending on desired behavior, could throw an exception or return an empty vector.
            // For now, returning an empty vector for safety.
            return {};
        }
        return base_map.begin()->second;
    }

    template<typename T>
    void CustomPriorityQueue<T>::pop()
    {
        if (!base_map.empty()) {
            base_map.erase(base_map.begin());
        }
    }

    template <typename T>
    bool CustomPriorityQueue<T>::empty()
    {
        return base_map.empty();
    }

    template <typename T>
    T CustomPriorityQueue<T>::top_event()
    {
        // Check if the map is empty before dereferencing begin()
        if (base_map.empty()) {
            // Depending on desired behavior, could throw an exception or return a default-constructed T.
            // For now, assuming T is default constructible or caller ensures map is not empty.
            // A more robust solution might involve returning std::optional<T>.
            return T(); // Return a default-constructed T if empty
        }
        return base_map.begin()->first;
    }
}
