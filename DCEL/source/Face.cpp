#include "Face.h"
#include "Edge.h"
#include "Vertex.h"
#include "point.h"
namespace GeometricVision
{
    namespace DCEL
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

        template class Face<double, 3>;
        template class Face<double, 2>;
        template class Face<float, 3>;
        template class Face<float, 2>;
    } // DCEL
}