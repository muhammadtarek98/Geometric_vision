#pragma once
#include "DCEL.hpp"
namespace GeometricVision::DCEL{
        template<typename dtype,size_t dim>
        class Face
        {
        private:
            edge_weak_ptr<dtype,dim>outer_edge;
            std::vector<edge_weak_ptr<dtype,dim>>inner_edges;
        public:
            Face()=default;
            Face(const Face&f);
            Face(Face&&f)noexcept;
            Face&operator=(const Face&f);
            Face&operator=(Face&&f)noexcept;
            std::vector<edge_weak_ptr<dtype,dim>>get_edges();
            std::vector<vector::Vector<dtype,dim>> get_points();
            virtual ~Face()=default;
        };
    }