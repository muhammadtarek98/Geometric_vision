#pragma once
#include <vector>
#include "Polyhedron.hpp"
#include "core.hpp"
#include "geo_utils.hpp"
#include "point.hpp"


namespace GeometricVision::ConvexHull::ConvexHull3D
{
    template<typename dtype>
    PolyHedron::Polyhedron<dtype> increamental_sort(std::vector<Point::point3d<dtype>> &pts,
        std::vector<PolyHedron::face_weak_ptr<dtype>> faces);
    template<typename dtype>
    bool noncoplanar_check(Point::point3d<dtype>&pts,size_t &i);
    template<typename dtype>
    Point::point3d<dtype> get_reference_point(std::vector<Point::point3d<dtype>> &pts,int &s_idx);
    template<typename dtype>
    bool CCW_check(float volume,bool face_normal_switch);
    template<typename dtype>
    std::vector<PolyHedron::face_weak_ptr<dtype>> get_visible_faces(std::vector<PolyHedron::face_weak_ptr<dtype>> &faces,PolyHedron::vertex_3d_weak_ptr<dtype>&curr_pt);
    template<typename dtype>
    std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> remove_edges_from_polyhedron(std::vector<PolyHedron::face_weak_ptr<dtype>>&faces);
    template<typename dtype>
    std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> set_boarder_for_polyhedron(std::vector<PolyHedron::face_weak_ptr<dtype>>&faces);
    template<typename dtype>
    std::unordered_set<PolyHedron::vertex_3d_weak_ptr<dtype>> get_unique_vertices(std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>&borders);

    template<typename dtype>
    std::tuple<std::vector<PolyHedron::face_weak_ptr<dtype>>,std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>> create_new_polyhedron(std::unordered_set<PolyHedron::vertex_3d_weak_ptr<dtype>> &uniq_verts,
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>>&edges,PolyHedron::vertex_3d_weak_ptr<dtype>&vert);
    template<typename dtype>
    void add_faces_2_edges(std::vector<PolyHedron::face_weak_ptr<dtype>> &faces,
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> &edges);
    template<typename dtype>
    void add_edges_2_faces(std::vector<PolyHedron::face_weak_ptr<dtype>> &new_faces,
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> &new_edges,
        std::vector<PolyHedron::edge_3d_weak_ptr<dtype>> &boarder_edges);


}
