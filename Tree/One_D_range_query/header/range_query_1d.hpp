#pragma once
#include "BST.hpp"
#include <vector>
#include <memory>
namespace GeometricVision::Tree::OneDimRangeQuery
{
    template<typename dtype>
    std::vector<dtype> find_range(dtype min,dtype max,BST<dtype>&tree);
    template<typename dtype>
    void follow_left_boundry_path(dtype comp_val,std::vector<dtype>&v,BST<dtype>&tree,std::weak_ptr<Node<dtype>>node);
    template<typename dtype>
    void follow_right_boundry_path(dtype comp_val,std::vector<dtype>&v,BST<dtype>&tree,std::weak_ptr<Node<dtype>>node);

}