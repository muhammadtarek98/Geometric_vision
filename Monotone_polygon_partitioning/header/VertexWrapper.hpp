#pragma once
#include "vertex_type.hpp"
namespace GeometricVision::PolygonPartition
{
    template<class type,size_t dim>
    class VertexWrapper
    {
    private:
        std::weak_ptr<DCEL::Vertex<type,dim>> vert;
        VERTEX_CATEGORY category;
    public:
        VertexWrapper(std::shared_ptr<DCEL::Vertex<type,dim>>vert,
                      VERTEX_CATEGORY category);
    };
    template<class type,size_t dim>
    struct VertexWrapperComparator{
        bool operator()(VertexWrapper<type,dim>&cur,
                        VertexWrapper<type,dim>&ref);
    };
}
