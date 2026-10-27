#include "VertexWrapper.hpp"
namespace GeometricVision::PolygonPartition
{
    template <class type, size_t dim>
    VertexWrapper<type, dim>& VertexWrapper<type, dim>::operator=(const VertexWrapper& v)
    {
     if (this!=&v)
     {
         this->category=v.category;
         this->vert=v.vert;
     }
        return *this;
    }

    template <class type, size_t dim>
    VertexWrapper<type, dim>& VertexWrapper<type, dim>::operator=(VertexWrapper&& v) noexcept
    {
        if (this!=&v)
        {
            this->category=std::move(v.category);
            this->vert=std::move(v.vert);
        }
        return *this;
    }

    template <class type, size_t dim>
    VertexWrapper<type, dim>::VertexWrapper(const VertexWrapper& v):vert(v.vert),category(v.category){}

    template <class type, size_t dim>
    VertexWrapper<type, dim>::VertexWrapper(VertexWrapper&& v)noexcept:
    vert(std::move(v.vert)),category(std::move(v.category)){}

    template <class type, size_t dim>
    VertexWrapper<type, dim>::~VertexWrapper()
    {
    }


    template<typename type,size_t dim>
    VertexWrapper<type,dim>::VertexWrapper(
        std::shared_ptr<DCEL::Vertex<type,dim>>vert_,
        VERTEX_CATEGORY category):vert(vert_),category(category){
    }
    template <class type, size_t dim>
    bool VertexWrapperComparator<type,dim>::operator()
    (VertexWrapper<type, dim>& cur, VertexWrapper<type, dim>& ref)
    {
        auto cur_pt=cur.vert->point;
        auto ref_pt=cur.vert->point;
        if ((cur_pt[Y]>ref_pt[Y])||(cur_pt[Y]==ref_pt[Y])&&(cur_pt[X]<ref_pt[X]))
        {
            return true;
        }
        return false;
    }
}
