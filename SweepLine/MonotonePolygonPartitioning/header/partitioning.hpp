#pragma once
#include "vertex_type.hpp"
#include "VertexWrapper.hpp"
#include "point.hpp"
#include "Edge.hpp"
#include "EdgeWrapper.hpp"
namespace GeometricVision::PolygonPartition
    {
        template<typename dtype,size_t dim>
        class SweepLine
        {
        private:
            Point::point_2d_weak_ptr<dtype> point;
        public:
            ~SweepLine();
            SweepLine(const SweepLine&l);
            SweepLine(SweepLine&&l)noexcept;
            SweepLine&operator=(const SweepLine&l);
            SweepLine&operator=( SweepLine&&l)noexcept;

            SweepLine(Point::point_2d_shared_ptr<dtype> pt);
            bool operator()(std::unique_ptr<const EdgeWrapper<dtype,dim>> ref1,
                            std::unique_ptr<const EdgeWrapper<dtype,dim>>ref2);
        };
        template<class type,size_t dim>
        void get_monotone_polygon(std::shared_ptr<DCEL::Polygon<type,dim>> poly,
                                  std::vector<std::shared_ptr<DCEL::Polygon<type,dim>>> mono_polys);
        template<class type,size_t dim>
        void handle_start_vert(VertexWrapper<type,dim>&vert,
                               std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                        SweepLine<type,dim>>&sweep_line,
                               std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                        EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly);

        template<class type,size_t dim>
        void handle_end_vert(VertexWrapper<type,dim>&vert,
                             std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                      SweepLine<type,dim>>&sweep_line,
                             std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                      EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly);

        template<class type,size_t dim>
        void handle_split_vert(VertexWrapper<type,dim>&vert,
                               std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                        SweepLine<type,dim>>&sweep_line,
                               std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                        EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly);
        template<class type,size_t dim>
        void handle_merge_vert(VertexWrapper<type,dim>&vert,
                               std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                        SweepLine<type,dim>>&sweep_line,
                               std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                        EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly);

        template<class type,size_t dim>
        void handle_regular_vert(VertexWrapper<type,dim>&vert,
                                 std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                          SweepLine<type,dim>>&sweep_line,
                                 std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                          EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly);

    }