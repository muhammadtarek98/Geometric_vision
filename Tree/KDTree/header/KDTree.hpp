#pragma once
#include "vector.hpp"
#include "distance.hpp"
#include <vector>
#include <memory>
namespace GeometricVision::Tree
{
    template<typename dtype>
    struct KDRegionVect2D
    {
        vector::vect2D<dtype>v_bound;
        vector::vect2D<dtype>h_bound;
    public:
        KDRegionVect2D();
        KDRegionVect2D(KDRegionVect2D &&vect)noexcept;
        KDRegionVect2D(const KDRegionVect2D &vect);
        KDRegionVect2D&operator=(KDRegionVect2D &&vect)noexcept;
        KDRegionVect2D&operator=(const KDRegionVect2D &vect);
        ~KDRegionVect2D()=default;
        KDRegionVect2D(vector::vect2D<dtype>v_bound,vector::vect2D<dtype>h_bound);
    };
    struct KDRegion2D
    {
        double left,right,bottom,top;
        KDRegion2D();
        KDRegion2D(double l,double r,double b,double t);
    };
    template<typename dtype>
    struct KDNode
    {
    private:
        vector::vect2D<dtype> value;
        std::shared_ptr<KDNode>left;
        std::shared_ptr<KDNode>right;
        dtype  spilt_val;
        KDRegion2D boundry;

    public:
        KDNode();
        ~KDNode();
        KDNode(const KDNode&n);
        KDNode(KDNode&&n)noexcept;
        KDNode&operator=(KDNode&&n)noexcept;
        KDNode&operator=(const KDNode&n);
        explicit KDNode(dtype _spilt_val,KDRegion2D boundry={-10.0,10.0,-10.0,10.0},
                        std::shared_ptr<KDNode>left=nullptr,
                        std::shared_ptr<KDNode>right=nullptr);
        explicit KDNode(vector::vect2D<dtype> val,std::shared_ptr<KDNode>left=nullptr,
                        std::shared_ptr<KDNode>right=nullptr);
        std::weak_ptr<KDNode>get_left();
        std::weak_ptr<KDNode>get_right();
        vector::vect2D<dtype>get_value();
        KDRegion2D get_boundry() const;
        dtype get_spilt_val();

    };
    template<typename dtype>
    class KDTree
    {
    private:
        KDRegion2D INVALID{0.0,0.0,0.0,0.0};
        KDRegion2D DEFAULT{-10.0,10.0,-10.0,10.0};
        std::shared_ptr<KDNode<dtype>> root;
        std::shared_ptr<KDNode<dtype>> construct_kdtree(std::vector<vector::vect2D<dtype>> &data,int depth=0);
    public:
        KDTree();
        KDTree(KDTree&&t)noexcept;
        KDTree(const KDTree&t);
        KDTree &operator=(KDTree&&t)noexcept;
        KDTree &operator=(const KDTree&t);
        ~KDTree();
        bool isleaf(std::weak_ptr<KDNode<dtype>> node);
        KDTree(std::vector<vector::vect2D<dtype>>&data);
        std::weak_ptr<KDNode<dtype>> get_root();

        void preprocess_boundaries(std::weak_ptr<KDNode<dtype>>node,bool iseven);
    };
    template<typename dtype>
    bool isleaf(std::weak_ptr<KDNode<dtype>> node);
    template<typename dtype>
    bool x_comparator(vector::vect2D<dtype> a,vector::vect2D<dtype> b);
    template<typename dtype>
    bool y_comparator(vector::vect2D<dtype> a,vector::vect2D<dtype> b);
    template<typename dtype>
    void traverse_kdtree(std::weak_ptr<KDNode<dtype>> node,std::vector<vector::vect2D<dtype>>&list);
    bool isinside(const KDRegion2D &r1,const KDRegion2D&r2);
    bool intersection(const KDRegion2D&r1,const KDRegion2D&r2);
    template<typename dtype>
    bool intersection(KDRegionVect2D<dtype>&r1,KDRegionVect2D<dtype>&r2);
    template<typename dtype>
    bool inrange(vector::vect2D<dtype> &v,KDRegionVect2D<dtype> &r);
    template<typename dtype>
    bool inrange(vector::vect2D<dtype> &v,KDRegion2D &r);
    template<typename dtype>
    void searchKDTree(std::weak_ptr<KDNode<dtype>>node,KDRegion2D range,std::vector<vector::vect2D<dtype>>&vec);

    template<typename dtype>
    std::tuple<std::weak_ptr<KDNode<dtype>>,vector::vect2D<dtype>,dtype>nearest_neighbour(
        std::weak_ptr<KDNode<dtype>> node,vector::vect2D<dtype>&search_node,dtype &curr_dist,bool is_even_depth,
        vector::vect2D<dtype>&curr_mn_nn);
}