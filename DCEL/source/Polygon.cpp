#include "Polygon.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Face.hpp"
namespace GeometricVision::DCEL
{
    template <class dtype, size_t dim>
    Polygon<dtype, dim>::Polygon() {}

    template<class dtype,size_t dim>
    Polygon<dtype,dim>::Polygon(std::vector<vector::Vector<dtype,dim>>& points) {}

    template <class dtype, size_t dim>
    void Polygon<dtype, dim>::GetEdgesWithTheSameFaceGivenOrigins(vertex_weak_ptr<dtype,dim>v1,
                                                     vertex_weak_ptr<dtype,dim> v2,
                                                     edge_weak_ptr<dtype,dim> e1,
                                                     edge_weak_ptr<dtype,dim> e2) {}

    template <class dtype, size_t dim>
    bool Polygon<dtype, dim>::split(vertex_weak_ptr<dtype,dim>v1,vertex_weak_ptr<dtype,dim>v2){
        return false;
    }

    template <class dtype, size_t dim>
    bool Polygon<dtype, dim>::join(vertex_weak_ptr<dtype,dim>v1,vertex_weak_ptr<dtype,dim>v2) {
        return false;
    }

    template <class dtype, size_t dim>
    std::vector<vertex_weak_ptr<dtype,dim>> Polygon<dtype, dim>::get_vertex_list() {
        return this->vertex_list;
    }

    template <class dtype, size_t dim>
   std::vector<edge_weak_ptr<dtype,dim>>  Polygon<dtype, dim>::get_edge_list() {
        return this->edge_list;
    }

    template <class dtype, size_t dim>
    std::vector<face_weak_ptr<dtype,dim>> Polygon<dtype, dim>::get_face_list() {
        return face_list;
    }

    template <class dtype, size_t dim>
    vertex_weak_ptr<dtype,dim> Polygon<dtype, dim>::get_vertex(vector::Vector<dtype, dim>& point) {
        return {};
    }

    template class Polygon<double, DIM3>;
    template class Polygon<float, DIM3>;
    template class Polygon<double, DIM2>;
    template class Polygon<float, DIM2>;


}
