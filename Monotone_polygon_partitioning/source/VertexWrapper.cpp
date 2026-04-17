#include "VertexWrapper.hpp"
namespace GeometricVision
{
    namespace  PolygonPartition
    {
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
}