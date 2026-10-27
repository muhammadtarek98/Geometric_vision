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

    template <typename dtype, size_t dim>
    Face<dtype, dim>::Face(const Face& f)
    {
        this->outer_edge=f.outer_edge;
        this->inner_edges=f.inner_edges;
    }

    template <typename dtype, size_t dim>
    Face<dtype, dim>::Face(Face&& f)noexcept
    {
        this->outer_edge=std::move(f.outer_edge);
        this->inner_edges=std::move(f.inner_edges);
    }
    template <typename dtype, size_t dim>
    Face<dtype, dim>& Face<dtype,dim>::operator=(const Face& f)
    {
        if (this!=&f)
        {
            this->outer_edge=f.outer_edge;
            this->inner_edges=f.inner_edges;
        }
        return *this;
    }
    template <typename dtype, size_t dim>
    Face<dtype, dim>& Face<dtype,dim>::operator=(Face&& f)noexcept
    {
        if (this!=&f)
        {
            this->outer_edge=std::move(f.outer_edge);
            this->inner_edges=std::move(f.inner_edges);
        }
        return *this;
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
}
