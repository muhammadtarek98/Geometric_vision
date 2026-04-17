#pragma once
#include "DCEL.h"
namespace GeometricVision::DCEL
{
    template<class type=float,size_t dim=DIM3>
    class Face
    {
    private:
        std::weak_ptr<Edge<type,dim>>outer_edges;
        std::vector<std::weak_ptr<Edge<type,dim>>>inner_edges;
    public:
        Face()=default;
        std::vector<std::weak_ptr<Edge<type,dim>>>get_edges();
        std::vector<vector::Vector<type,dim>> get_points();
        virtual  ~Face()=default;

    };
}
