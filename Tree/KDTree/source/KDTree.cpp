#include "KDTree.hpp"
namespace GeometricVision::Tree
{
    template <typename dtype>
    bool x_comparator(vector::vect2D<dtype> a, vector::vect2D<dtype, 2> b)
    {
        return a[X]<b[X];
    }

    template <typename dtype>
    bool y_comparator(vector::vect2D<dtype> a, vector::vect2D<dtype> b)
    {
        return a[Y]<b[Y];
    }

    template <typename dtype>
    KDNode<dtype>::KDNode(dtype _spilt_val, std::shared_ptr<KDNode> left,
        std::shared_ptr<KDNode> right):spilt_val(_spilt_val),left(left),right(right)
    {}

    template <typename dtype>
    KDNode<dtype>::KDNode(vector::vect2D<dtype> val,
        std::shared_ptr<KDNode> left, std::shared_ptr<KDNode> right):right(right),left(left),value(val)
    {

    }
    template <typename dtype>
    KDNode<dtype>::KDNode()
    {
        this->left.get()=nullptr;
        this->right.get()=nullptr;
        this->spilt_val=static_cast<dtype>(0.0);
    }

    template <typename dtype>
    vector::vect2D<dtype> KDNode<dtype>::get_value()
    {
        return this->value;
    }

    template <typename dtype>
    dtype KDNode<dtype>::get_spilt_val()
    {
        return this->spilt_val;
    }

    template <typename dtype>
    std::weak_ptr<KDNode<dtype>> KDNode<dtype>::get_right()
    {
        return std::weak_ptr<KDNode>(this->right);
    }
    template <typename dtype>
    std::weak_ptr<KDNode<dtype>> KDNode<dtype>::get_left()
    {
        return std::weak_ptr<KDNode>(this->left);
    }

    template <typename dtype>
    std::weak_ptr<KDNode<dtype>> KDTree<dtype>::get_root()
    {
        return std::weak_ptr<KDNode<dtype>>(this->root);
    }

    template <typename dtype>
    KDTree<dtype>::KDTree()
    {
        this->root=std::move(KDNode<dtype>());
    }

    template <typename dtype>
    KDTree<dtype>::KDTree(std::vector<vector::vect2D<dtype>>& data)
    {
        this->root=this->construct_kdtree(data);
    }

    template <typename dtype>
    std::shared_ptr<KDNode<dtype>> KDTree<dtype>::construct_kdtree(std::vector<vector::vect2D<dtype, 2>>& data, int depth)
    {
        if (data.size()==1)
        {
            return std::make_shared<KDNode<dtype>>(data.front());
        }
        if (depth%2==0)
        {
            std::sort(data.begin(),data.end(),x_comparator);
        }
        else
        {
            std::sort(data.begin(),data.end(),y_comparator);
        }
        auto mid=data.size();
        auto mid_ptr=data.begin();
        std::advance(mid_ptr,mid);
        auto left_vec=std::vector<vector::vect2D<dtype>>(data.begin(),mid_ptr);
        auto right_vec=std::vector<vector::vect2D<dtype>>(mid_ptr,data.end());
        auto left_subtree=construct_kdtree(left_vec,depth+1);
        auto right_subtree=construct_kdtree(right_vec,depth+1);
        return std::make_shared<KDNode<dtype>>((*mid_ptr)[depth%2],left_subtree,right_subtree);
    }
}
