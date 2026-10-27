#include "event.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    template <typename dtype>
    Event<dtype>::Event(Event&& e)noexcept:point(std::move(e.point)){}

    template <typename dtype>
    Event<dtype>& Event<dtype>::operator=(const Event& e)
    {
     if (this!=&e)
     {
         this->point=e.point;
     }
        return *this;
    }
    template <typename dtype>
    Event<dtype>& Event<dtype>::operator=(Event&& e)noexcept
    {
        if (this!=&e)
        {
            this->point=std::move(e.point);
        }
        return *this;
    }
    template<typename dtype>
    Event<dtype>::Event():point(){}
    template<typename dtype>
    Event<dtype>::Event(const Event& e):point(e.point){}
    template<typename dtype>
    Event<dtype>::Event(const Point::point_2d_weak_ptr<dtype>& p):point(p){}
    template<typename dtype>
    bool Event<dtype>::operator==(Event& other)
    {
        return point.lock()==other.get_point().lock();
    }
    template<typename dtype>
    Point::point_2d_weak_ptr<dtype> Event<dtype>::get_point()
    {
        return point;
    }
}
