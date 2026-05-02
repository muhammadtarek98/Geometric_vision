#include "event.hpp"
namespace GeometricVision::LineSegmentIntersection
{
    Event::Event():point(){}
    Event::Event(const Event& e):point(e.point){}
    Event::Event(const std::weak_ptr<Point::point2d>& p):point(p){}
    bool Event::operator==(Event& other)
    {
        return point.lock()==other.get_point().lock();
    }
    std::weak_ptr<Point::point2d> Event::get_point()
    {
        return point;
    }
}
