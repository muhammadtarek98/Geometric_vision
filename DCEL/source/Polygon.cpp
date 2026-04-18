#include "Polygon.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Face.hpp"
namespace GeometricVision::DCEL
{
    template <class type, size_t dim>
    Polygon<type, dim>::Polygon() {}

    template<class type,size_t dim>
    Polygon<type,dim>::Polygon(std::vector<vector::Vector<type,dim>>& points) {}

    template <class type, size_t dim>
    void Polygon<type, dim>::GetEdgesWithTheSameFaceGivenOrigins(std::weak_ptr<Vertex<type, dim>> v1,
                                                                 std::weak_ptr<Vertex<type, dim>> v2, std::weak_ptr<Edge<type, dim>> e1, std::weak_ptr<Edge<type, dim>> e2) {}

    template <class type, size_t dim>
    bool Polygon<type, dim>::split(std::weak_ptr<Vertex<type, dim>> v1, std::weak_ptr<Vertex<type, dim>> v2) {
        return false;
    }

    template <class type, size_t dim>
    bool Polygon<type, dim>::join(std::weak_ptr<Vertex<type, dim>> v1, std::weak_ptr<Vertex<type, dim>> v2) {
        return false;
    }

    template <class type, size_t dim>
    std::vector<std::weak_ptr<Vertex<type, dim>>> Polygon<type, dim>::get_vertex_list() {
        return vertex_list;
    }

    template <class type, size_t dim>
    std::vector<std::weak_ptr<Edge<type, dim>>> Polygon<type, dim>::get_edge_list() {
        return edge_list;
    }

    template <class type, size_t dim>
    std::vector<std::weak_ptr<Face<type, dim>>> Polygon<type, dim>::get_face_list() {
        return face_list;
    }

    template <class type, size_t dim>
    std::weak_ptr<Vertex<type, dim>> Polygon<type, dim>::get_vertex(vector::Vector<type, dim>& point) {
        return {};
    }

    template class Polygon<double, DIM3>;
    template class Polygon<float, DIM3>;
    template class Polygon<double, DIM2>;
    template class Polygon<float, DIM2>;


}
