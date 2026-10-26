#pragma once
#include <vector>
#include <memory>
namespace GeometricVision::Tree
{
    template<typename dtype>
    struct Node
    {
    private:
        dtype value;
        std::shared_ptr<Node>left;
        std::shared_ptr<Node>right;
        std::shared_ptr<Node>parent;
    public:
        Node(dtype val,std::shared_ptr<Node>l=nullptr,std::shared_ptr<Node>r=nullptr,std::shared_ptr<Node>p=nullptr);
        Node();
        std::weak_ptr<Node> get_left();
        std::weak_ptr<Node>get_right();
        dtype get_val();
        std::weak_ptr<Node> get_parent();
    };
    template<typename dtype>
    class BST
    {
    private:
        std::shared_ptr<Node<dtype>> root;
        std::weak_ptr<Node<dtype>> successor(std::shared_ptr<Node<dtype>>node);
        std::weak_ptr<Node<dtype>> predecessor(std::shared_ptr<Node<dtype>>node);
    public:
        BST();
        ~BST();
        BST(std::vector<dtype>&v,int index=0);
        bool isleaf(std::weak_ptr<Node<dtype>>node);
        std::weak_ptr<Node<dtype>>get_root();
        std::weak_ptr<Node<dtype>> get_split_node(dtype left_bound,dtype  right_bound,std::weak_ptr<Node<dtype>> node=nullptr);
        void insert(dtype val);
        dtype get_root_value();
        std::tuple<dtype,std::weak_ptr<Node<dtype>>>find(dtype val,std::weak_ptr<Node<dtype>>src_node=nullptr);
        void preorder_traverse(std::shared_ptr<Node<dtype>> node,std::vector<dtype> &traverse_vector);
        void postorder_traverse(std::shared_ptr<Node<dtype>> node,std::vector<dtype>&traverse_vector);
        void inorder_traverse(std::shared_ptr<Node<dtype>>node,std::vector<dtype>&traverse_vector);
        std::tuple<dtype,std::weak_ptr<Node<dtype>>> maximum(std::shared_ptr<Node<dtype>> node);
        std::tuple<dtype,std::weak_ptr<Node<dtype>>>  minimum(std::shared_ptr<Node<dtype>> node);
        bool successor(dtype val ,dtype &successor_val);
        bool predecessor(dtype val,dtype &pred_val);
        bool remove(dtype val);
        void transparent(std::weak_ptr<Node<dtype>> u,std::weak_ptr<Node<dtype>> v);
    };


}