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
            edge_weak_ptr<dtype,dim>  next_edge=outer_edge.lock()->get_next();
            edges.push_back(edge_ptr);
            while (edge_ptr.lock()!=next_edge.lock())
            {
                edges.push_back(next_edge);
                next_edge.lock()=next_edge.lock()->get_next().lock();
            }
        }
        return edges;
    }

    template <class dtype, size_t dim>
    std::vector<vector::Vector<dtype, dim>> Face<dtype, dim>::get_points()
    {
        std::vector<vector::Vector<dtype, dim>> points;
        if (this->outer_edge.lock())
        {
            auto edge_ptr=outer_edge.lock();
            auto next_ptr=outer_edge.lock()->get_next();
            points.push_back(edge_ptr->get_point().lock()->get_point());
            while (next_ptr.lock()->get_point().lock()->get_point()!=edge_ptr->get_point().lock()->get_point())
            {
                points.push_back(next_ptr.lock()->get_point().lock()->get_point());
                next_ptr=next_ptr.lock()->get_next();
            }
        }
        return points;
    }

    template class Face<double, DIM3>;
    template class Face<double, DIM2>;
    template class Face<float, DIM3>;
    template class Face<float, DIM2>;
}
