#pragma once
#include "vector.hpp"
namespace GeometricVision::Point{
        template<typename dtype=double>
        using  point2d=vector::vect2D<dtype>;
        template<typename dtype=double>
        using  point3d=vector::vect3D<dtype>;
        static const point2d DEFAULT_POINT_2D(FLT_MAX,FLT_MAX);
        static const point3d DEFAULT_POINT_3D(FLT_MAX,FLT_MAX,FLT_MAX);
        template<typename dtype=double>
        bool sort_point2d_top_bottom_left_right(const point2d<dtype> &a,const point2d<dtype> &b);
        template<typename dtype=double>
        bool sort_point2d_left_right_top_bottom(const point2d<dtype> &a,const point2d<dtype> &b);
        template<typename dtype=double>
        bool sort_point3d_top_bottom_left_right(const point3d<dtype> &a,const point3d<dtype> &b);
        template<typename dtype=double>
        bool sort_point2d_by_x(const point2d<dtype> &a,const point2d<dtype> &b);
        template<typename dtype=double>
        bool sort_point2d_by_y(const point2d<dtype> &a,const point2d<dtype> &b);
        template<typename dtype,size_t dim=DIM2>
        using point_2d_weak_ptr=std::weak_ptr<vector::Vector<dtype,dim>>;
        template<typename dtype,size_t dim=DIM2>
        using point_2d_shared_ptr=std::shared_ptr<vector::Vector<dtype,dim>>;
        template<typename dtype,size_t dim=DIM2>
        using point_2d_unique_ptr=std::unique_ptr<vector::Vector<dtype,dim>>;
        template<typename dtype,size_t dim=DIM3>
        using point_3d_weak_ptr=std::weak_ptr<vector::Vector<dtype,dim>>;
        template<typename dtype,size_t dim=DIM3>
        using point_3d_shared_ptr=std::shared_ptr<vector::Vector<dtype,dim>>;
        template<typename dtype,size_t dim=DIM3>
        using point_3d_unique_ptr=std::unique_ptr<vector::Vector<dtype,dim>>;
    }