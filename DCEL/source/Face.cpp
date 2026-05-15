#include "Face.hpp"
#include "Edge.hpp"
#include "Vertex.hpp"
#include "point.hpp"
#include "vector.hpp"
#include "DCEL.hpp"
namespace GeometricVision::DCEL
{

    template <class dtype, size_t dim>
    std::vector<edge_weak_ptr<dtype, dim>> Face<dtype, dim>::get_edges()
    {
        std::vector<edge_weak_ptr<dtype,dim>> edges;
        if (this->outer_edge.lock())
        {
            edge_weak_ptr<dtype,dim> edge_ptr=outer_edge;
            vertex_weak_ptr<dtype,dim>  next_edge=outer_edge.lock()->get_next();
            edges.push_back(edge_ptr);
            while (edge_ptr.lock()->get_next().lock()->get_point()!=next_edge.lock()->get_point())
            {


            }
        }
        return edges;
    }

    template <class dtype, size_t dim>
    std::vector<vector::Vector<dtype, dim>> Face<dtype, dim>::get_points()
    {
        std::vector<vector::Vector<dtype, dim>> points;
        return points;
    }

    template class Face<double, DIM3>;
    template class Face<double, DIM2>;
    template class Face<float, DIM3>;
    template class Face<float, DIM2>;
}
