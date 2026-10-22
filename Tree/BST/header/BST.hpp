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
        Node(dtype val,std::shared_ptr<Node>l=nullptr,
            std::shared_ptr<Node>r=nullptr,std::shared_ptr<Node>p=nullptr):value(val),left(l),right(r),parent(p){}
        Node()
        {
            value=static_cast<dtype>(0.0);
            left=nullptr;
            right=nullptr;
            parent=nullptr;
        }
        std::weak_ptr<Node> get_left()
        {
            return std::weak_ptr<Node>(this->left);
        }
        std::weak_ptr<Node>get_right()
        {
            return std::weak_ptr<Node>(this->right);
        }
        dtype get_val()
        {
            return this->value;
        }
        std::weak_ptr<Node> get_parent()
        {
            return this->parent;
        }
    };
    template<typename dtype>
    class BST
    {
    private:
        std::shared_ptr<Node<dtype>> root;
        std::shared_ptr<Node<dtype>> successor(std::shared_ptr<Node<dtype>>node);
        std::shared_ptr<Node<dtype>> predeccessor(std::shared_ptr<Node<dtype>>node);
    public:
        BST();
        BST(std::vector<dtype>&v,int index=0);
        bool isleaf();
        void insert(dtype val);
        dtype get_node_value();
        bool find(dtype val);
        void preorder_traverse(std::shared_ptr<Node<dtype>> node,std::vector<dtype> &traverse_vector);
        void postorder_traverse(std::shared_ptr<Node<dtype>> node,std::vector<dtype>&traverse_vector);
        void inorder_traverse(std::shared_ptr<Node<dtype>>node,std::vector<dtype>&traverse_vector);
        dtype maximum(std::shared_ptr<Node<dtype>> node);
        dtype minimum(std::shared_ptr<Node<dtype>> node);
        bool successor(dtype val ,dtype &successor_val);
        bool predeccessor(dtype val,dtype &pred_val);
    };


}