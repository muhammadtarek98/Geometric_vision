#include "BST.hpp"
namespace GeometricVision::Tree
{
    template <typename dtype>
    BST<dtype>::BST()
    {
        this->root.get()=nullptr;

    }

    template <typename dtype>
    BST<dtype>::BST(std::vector<dtype>& v, int index)
    {
        this->root=std::make_shared<Node>(v[index]);
        for (int i=0;i<v.size();i++)
        {
            if (i!=index)
            {
                this->insert(v[i]);
            }
        }
    }

    template <typename dtype>
    void BST<dtype>::inorder_traverse(std::shared_ptr<Node<dtype>> node, std::vector<dtype>& traverse_vector)
    {
        if (node.get()==nullptr)
        {
            return;
        }
        inorder_traverse(node->get_left(),traverse_vector);
        traverse_vector.push_back(node->get_val());
        inorder_traverse(node->get_right(),traverse_vector);
    }

    template <typename dtype>
    void BST<dtype>::postorder_traverse(std::shared_ptr<Node<dtype>> node, std::vector<dtype>& traverse_vector)
    {
        if (node.get()==nullptr)
        {
            return;
        }
        postorder_traverse(node->get_left(),traverse_vector);
        postorder_traverse(node->get_right(),traverse_vector);
        traverse_vector.push_back(node->get_val());
    }

    template <typename dtype>
    void BST<dtype>::preorder_traverse(std::shared_ptr<Node<dtype>> node,std::vector<dtype> &traverse_vector)
    {
        if (node.get()==nullptr)
        {
            return ;
        }
        traverse_vector.push_back(node->get_val());
        preorder_traverse(node.get()->get_left(),traverse_vector);
        preorder_traverse(node.get()->get_right(),traverse_vector);
    }

    template <typename dtype>
    dtype BST<dtype>::get_node_value()
    {
        if (this->root)
        {
            return this->root->get_val();
        }
        return static_cast<dtype>(INTMAX_MAX);
    }

    template <typename dtype>
    bool BST<dtype>::isleaf()
    {
        if (this->root.get()==nullptr)
        {
            return true;
        }
        return false;
    }
    template<typename dtype>
    void BST<dtype>::insert(dtype val)
    {
        if (this->root.get()==nullptr)
        {
            root=std::make_shared<Node>>(val);
            return;
        }
        else
        {
            auto temp=root;
            if (val==temp.get()->get_val())
            {
                return;
            }
            while (temp.get()!=nullptr)
            {
                if (val<temp->get_val())
                {
                    if (temp->get_left())
                    {
                        temp=temp->get_left();
                    }
                    else
                    {
                        temp->get_left()=std::make_shared<Node>(val);
                        break;
                    }
                }
                else
                {
                    if (temp->get_right())
                    {
                        temp=temp->get_right();
                    }
                    else
                    {
                        temp->get_right()=std::make_shared<Node>(val);
                        break;
                    }
                }
            }
        }
    }

    template <typename dtype>
    bool BST<dtype>::find(dtype val)
    {
        if (root->get_val()==val)
        {
            return true;
        }
        if (root.get()==nullptr||root->get_val()!=val)
        {
            return false;
        }
        auto r=find(root->get_right()->get_val());
        auto l=find(root->get_left().get_val);
        return r||l;
    }
    template<typename dtype>
    dtype BST<dtype>::maximum(std::shared_ptr<Node<dtype>>node)
    {
        if (node.get()==nullptr)
        {
            return node.get()->get_val();
        }
        return maximum(node.get()->get_right());
    }
    template <typename dtype>
    dtype BST<dtype>::minimum(std::shared_ptr<Node<dtype>> node)
    {
        if (node.get()==nullptr)
        {
            return node.get()->get_val();
        }
        return minimum(node->get_left());
    }

    template <typename dtype>
    bool BST<dtype>::successor(dtype val ,dtype &successor_val)
    {


    }
    template<typename dtype>
    bool BST<dtype>::predeccessor(dtype val,dtype &pred_val)
    {
        auto v=find(val);
        if (!val)
        {
            return false;
        }



    }

    template <typename dtype>
    std::shared_ptr<Node<dtype>> BST<dtype>::successor(std::shared_ptr<Node<dtype>> node)
    {
        if (node->get_right())
        {
            return minimum(node->get_right());
        }


    }
}
