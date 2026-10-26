#include "BST.hpp"
namespace GeometricVision::Tree
{
    template<typename dtype>
    Node<dtype>::Node()
    {
        value=static_cast<dtype>(0.0);
        left=nullptr;
        right=nullptr;
        parent=nullptr;
    }
    template<typename dtype>
    Node<dtype>::Node(dtype val,std::shared_ptr<Node>l,
            std::shared_ptr<Node>r,std::shared_ptr<Node>p):value(val),left(l),right(r),parent(p){}
    template<typename dtype>
    std::weak_ptr<Node<dtype>>Node<dtype>::get_left()
    {return std::weak_ptr<Node>(this->left);}
    template<typename dtype>
    std::weak_ptr<Node<dtype>>Node<dtype>::get_right()
    {return std::weak_ptr<Node>(this->right);}
    template<typename dtype>
    dtype Node<dtype>::get_val()
    {return this->value;}
    template<typename dtype>
    std::weak_ptr<Node<dtype>> Node<dtype>::get_parent()
    {return this->parent;}
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
    dtype BST<dtype>::get_root_value()
    {
        if (this->root)
        {
            return this->root->get_val();
        }
        return static_cast<dtype>(INTMAX_MAX);
    }

    template <typename dtype>
    bool BST<dtype>::isleaf(std::weak_ptr<Node<dtype>>node)
    {
        if (node.lock().get()==nullptr)
        {
            return true;
        }
        return false;
    }

    template <typename dtype>
    std::weak_ptr<Node<dtype>> BST<dtype>::get_root()
    {
        if (this->root.get()==nullptr)
        {
            return std::weak_ptr<Node<dtype>>(nullptr);
        }
        return std::weak_ptr<Node<dtype>>(this->root);
    }
    template<typename dtype>
    std::weak_ptr<Node<dtype>> BST<dtype>::get_split_node(dtype left_bound,dtype right_bound,std::weak_ptr<Node<dtype>> node)
    {
        if (node.lock().get()==nullptr)
        {
            node=this->root;
        }
        auto node_val=node.lock()->get_val();
        auto left_child=node.lock()->get_left();
        auto right_child=node.lock()->get_right();
        if (this->isleaf(node)&&(right_bound>node_val||left_bound<node))
        {
            return node;
        }
        return right_bound<=node_val?this->get_split_node(left_child,left_bound,right_bound):
        this->get_split_node(right_child,left_bound,right_bound);

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
    std::tuple<dtype,std::weak_ptr<Node<dtype>>>  BST<dtype>::find(dtype val,std::weak_ptr<Node<dtype>>src_node)
    {
        if (src_node->get_val()==val)
        {
            return std::make_tuple(true,src_node);
        }

        if (src_node.get()==nullptr||src_node->get_val()!=val)
        {
            return std::make_tuple(false,std::weak_ptr<Node<dtype>>(nullptr));
        }
        return find_val(src_node->get_right()->get_val(),src_node)||
            find_val(src_node->get_left()->get_val(),src_node);
    }
    template<typename dtype>
    std::tuple<dtype,std::weak_ptr<Node<dtype>>> BST<dtype>::maximum(std::shared_ptr<Node<dtype>>node)
    {
        if (node.get()==nullptr)
        {
            return std::make_tuple( node.get()->get_val(),std::weak_ptr<Node<dtype>>(node));
        }
        return maximum(node.get()->get_right());
    }
    template <typename dtype>
    std::tuple<dtype,std::weak_ptr<Node<dtype>>>  BST<dtype>::minimum(std::shared_ptr<Node<dtype>> node)
    {
        if (node.get()==nullptr)
        {
            return std::make_tuple(node.get()->get_val(),std::weak_ptr<Node<dtype>>(node));
        }
        return minimum(node->get_left());
    }

    template <typename dtype>
    bool BST<dtype>::successor(dtype val ,dtype &successor_val)
    {
        auto [found,node]=find(val);
        if (!found||!node)
        {
            return false;
        }
        auto _succ=this->successor(node);
        successor_val=_succ.lock()->get_val();
        return true;
    }
    template <typename dtype>
    std::weak_ptr<Node<dtype>> BST<dtype>::successor(std::shared_ptr<Node<dtype>> node)
    {
        if (node->get_right())
        {
            return minimum(node->get_right())[1];
        }
        if (node->get_parent() && node==node->get_parent().lock()->get_right())
        {
            return this->successor(node->get_parent()).lock()->get_parent();
        }
    }

    template <typename dtype>
    bool BST<dtype>::predecessor(dtype val, dtype& pred_val)
    {
        auto [found,node]=find(val);
        if (!found||!node)
        {
            return false;
        }
        auto _pred=this->predecessor(node);
        pred_val=_pred.lock()->get_val();
        return true;
    }

    template<typename dtype>
    std::weak_ptr<Node<dtype>> BST<dtype>::predecessor(std::shared_ptr<Node<dtype>>node)
    {
        if (node->get_left())
        {
            return maximum(node->get_left())[1];
        }
        if (node->get_parent()&&node==node->get_parent().lock()->get_left())
            return predecessor(node->get_parent()).lock()->get_parent();
    }
    template<typename dtype>
    void BST<dtype>::transparent(std::weak_ptr<Node<dtype>> u,std::weak_ptr<Node<dtype>> v)
    {
        if (!u.lock()->get_parent())
            root=v;
        else if (u==u.lock()->get_parent().lock()->get_left())
        {
            u.lock()->get_parent().lock()->get_left()=v;
        }
        else{
            u.lock()->get_parent().lock()->get_left()=v;
        }
        if (v)
        {
            v.lock()->get_parent().lock()=u.lock()->get_parent();
        }
    }

    template <typename dtype>
    bool BST<dtype>::remove(dtype val)
    {
        auto [found,node]=find(val);

        if (!node||!found)
        {
            return false;
        }
        auto r=node.lock()->get_right();
        auto l=node.lock()->get_left();
        if (isleaf(node))
        {
            transparent(node,nullptr);

        }
        else if (!l)
        {
         transparent(node,r);
        }
        else if (!r)
        {
            transparent(node,l);
        }
        else
        {
            auto r_min=minimum(r)[1];
            if (r_min.get()->get_parent()!=node)
            {
                transparent(r_min,r_min.get()->get_right);
                r_min->get_right()=node->get_right();
                r_min->get_right()->get_parent=r_min;
            }
            transparent(node,r_min);
            r_min.get()->get_left()=node->get_left();
            r_min.get()->get_left().get()->get_parent()=r_min;
        }
        return true;
    }
}
