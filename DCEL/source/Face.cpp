#include "Face.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"
#include "point.hpp"
#include "vector.hpp"
namespace GeometricVision::DCEL
{

    template <class type, size_t dim>
    std::vector<std::weak_ptr<Edge<type, dim>>> Face<type, dim>::get_edges()
    {
        std::vector<std::weak_ptr<Edge<type, dim>>> edges;
        return edges;
    }

    template <class type, size_t dim>
    std::vector<vector::Vector<type, dim>> Face<type, dim>::get_points()
    {
        std::vector<vector::Vector<type, dim>> points;
        return points;
    }

    template class Face<double, DIM3>;
    template class Face<double, DIM2>;
    template class Face<float, DIM3>;
    template class Face<float, DIM2>;
}
