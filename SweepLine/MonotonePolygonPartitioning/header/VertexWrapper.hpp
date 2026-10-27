#pragma once
#include "vertex_type.hpp"
namespace GeometricVision::PolygonPartition
{
    template<class type,size_t dim>
    class VertexWrapper
    {
    private:
        DCEL::vertex_weak_ptr<type,dim> vert;
        VERTEX_CATEGORY category;
    public:
        ~VertexWrapper();
        VertexWrapper(VertexWrapper&&v)noexcept;
        VertexWrapper(const VertexWrapper&v);
        VertexWrapper& operator=(const VertexWrapper&v);
        VertexWrapper& operator=(VertexWrapper&&v)noexcept;
        VertexWrapper(DCEL::vertex_shared_ptr<type,dim>vert,
                      VERTEX_CATEGORY category);
    };
    template<class type,size_t dim>
    struct VertexWrapperComparator{
        bool operator()(VertexWrapper<type,dim>&cur,
                        VertexWrapper<type,dim>&ref);
    };
}
