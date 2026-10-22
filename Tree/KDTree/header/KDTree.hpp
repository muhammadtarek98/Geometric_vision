#pragma once
#include "vector.hpp"
#include <vector>
#include <memory>
namespace GeometricVision::Tree
{
    template<typename dtype>
    struct KDNode
    {
    private:
        vector::vect2D<dtype> value;
        std::shared_ptr<KDNode>left;
        std::shared_ptr<KDNode>right;
       dtype  spilt_val;
    public:
        KDNode();
        KDNode(dtype _spilt_val,std::shared_ptr<KDNode>left=nullptr,std::shared_ptr<KDNode>right=nullptr);
        KDNode(vector::vect2D<dtype> val,std::shared_ptr<KDNode>left=nullptr,std::shared_ptr<KDNode>right=nullptr);
        std::weak_ptr<KDNode>get_left();
        std::weak_ptr<KDNode>get_right();
        vector::vect2D<dtype>get_value();
        dtype get_spilt_val();

    };
    template<typename dtype>
    class KDTree
    {
    private:
        std::shared_ptr<KDNode<dtype>> root;
        std::shared_ptr<KDNode<dtype>> construct_kdtree(std::vector<vector::vect2D<dtype>> &data,int depth=0);

    public:
        KDTree();
        KDTree(std::vector<vector::vect2D<dtype>>&data);
        std::weak_ptr<KDNode<dtype>> get_root();
    };
    template<typename dtype>
    bool x_comparator(vector::vect2D<dtype> a,vector::vect2D<dtype> b);
    template<typename dtype>
    bool y_comparator(vector::vect2D<dtype> a,vector::vect2D<dtype> b);

}