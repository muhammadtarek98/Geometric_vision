#include "range_query_1d.hpp"
namespace GeometricVision::Tree::OneDimRangeQuery
{
    template<typename dtype>
    std::vector<dtype> find_range(dtype min,dtype max,BST<dtype>&tree)
    {
        std::vector<dtype>range;
        auto spilt_node=tree.get_split_node(min,max);
        if (spilt_node.lock().get()!=nullptr)
        {
            auto val=spilt_node.lock()->get_val();
            if (tree.isleaf(spilt_node))
            {
                if (val>=min&&val<max)
                {
                    range.push_back(val);
                }
            }
            else
            {
                follow_left_boundry_path(min,range,tree,spilt_node);
                follow_right_boundry_path(max,range,tree,spilt_node);
            }
        }
        return range;
    }

    template<typename dtype>
    void follow_left_boundry_path(dtype comp_val,std::vector<dtype>&v,BST<dtype>&tree,std::weak_ptr<Node<dtype>>node)
    {
        if (tree.isleaf(node))
        {
            return;
        }
        auto left_child=node.lock()->get_left();
        if (left_child.lock()->get_val()>=comp_val)
        {
            v.push_back(left_child.lock()->get_val());
            return;
        }
        if (comp_val<=left_child.lock()->get_val())
        {
            tree.inorder_traverse(left_child.lock()->get_right(),v);
            v.push_back(left_child.lock()->get_val());
        }
        else
        {
            left_child=left_child.lock()->get_right();
        }
        follow_left_boundry_path(comp_val,v,tree,left_child);
    }
    template<typename dtype>
    void follow_right_boundry_path(dtype comp_val,std::vector<dtype>&v,BST<dtype>&tree,std::weak_ptr<Node<dtype>>node)
    {
        auto right_child=node.lock()->get_right();
        if (tree.isleaf(right_child))
        {
            return;
        }
        if (comp_val>=right_child.lock()->get_val())
        {
            tree.inorder_traverse(right_child.lock()->get_left(),v);
            right_child=right_child.lock()->get_right();
        }
        else
        {
            right_child=right_child.lock()->get_left();
        }
        follow_right_boundry_path(comp_val,v,tree,right_child);
        if (right_child.lock()->get_val()<=comp_val)
        {
            v.push_back(right_child.lock()->get_val());
        }
    }

}
