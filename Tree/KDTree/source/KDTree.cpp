#include "KDTree.hpp"
namespace GeometricVision::Tree
{
    template <typename dtype>
    KDRegionVect2D<dtype>::KDRegionVect2D()
    {
        this->h_bound=vector::vect2D<dtype>(0.0,0.0);
        this->v_bound=vector::vect2D<dtype>(0.0,0.0);
    }

    template <typename dtype>
    KDRegionVect2D<dtype>::KDRegionVect2D(vector::vect2D<dtype>v_bound,vector::vect2D<dtype>h_bound):
    v_bound(v_bound),h_bound(h_bound){}
    template<typename dtype>
    KDRegionVect2D<dtype>::KDRegionVect2D(KDRegionVect2D&&vect)noexcept
    {
        this->h_bound=std::move(vect.h_bound);
        this->v_bound=std::move(vect.v_bound);
    }
    template<typename dtype>
    KDRegionVect2D<dtype>::KDRegionVect2D(const KDRegionVect2D&vect):
    h_bound(vect.h_bound),v_bound(vect.v_bound){}
    template <typename dtype>
    KDRegionVect2D<dtype>& KDRegionVect2D<dtype>::operator=(const KDRegionVect2D& vect)
    {
        if (this!=&vect)
        {
            this->h_bound=vect.h_bound;
            this->v_bound=vect.v_bound;
        }
        return *this;
    }

    template <typename dtype>
    KDRegionVect2D<dtype>& KDRegionVect2D<dtype>::operator=(KDRegionVect2D&&vect)noexcept
    {
        if (this!=&vect)
        {
            this->h_bound=std::move(vect.h_bound);
            this->v_bound=std::move(vect.v_bound);
        }
        return *this;
    }

    KDRegion2D::KDRegion2D(double l, double r, double b, double t):left(l),right(r),top(t),bottom(b)
    {}
    KDRegion2D::KDRegion2D()
    {
        this->left=0.0;
        this->right=0.0;
        this->bottom=0.0;
        this->top=0.0;
    }

    template <typename dtype>
    KDNode<dtype>::~KDNode()
    {

    }

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
    KDNode<dtype>::KDNode(dtype _spilt_val,KDRegion2D boundry, std::shared_ptr<KDNode> left,
        std::shared_ptr<KDNode> right):spilt_val(_spilt_val),left(left),right(right),boundry((boundry))
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
        this->boundry={0.0,0.0,0.0,0.0};
        this->spilt_val=static_cast<dtype>(0.0);
    }

    template <typename dtype>
    KDNode<dtype>::KDNode(const KDNode& n)
    {
        value=n.value;
        left=n.left;
        right=n.right;
        spilt_val=n.spilt_val;
        boundry=n.boundry;
    }
    template <typename dtype>
    KDNode<dtype>::KDNode(KDNode&& n)noexcept
    {
        value=std::move(n.value);
        left=std::move(n.left);
        right=std::move(n.right);
        spilt_val=std::move(n.spilt_val);
        boundry=std::move(n.boundry);
    }
    template <typename dtype>
    KDNode<dtype>& KDNode<dtype>::operator=(KDNode&& n)noexcept
    {
        if (this!=&n)
        {
            value=std::move(n.value);
            left=std::move(n.left);
            right=std::move(n.right);
            spilt_val=std::move(n.spilt_val);
            boundry=std::move(n.boundry);
        }
        return *this;
    }
    template <typename dtype>
    KDNode<dtype>& KDNode<dtype>::operator=(const KDNode& n)
    {
        if (this!=&n)
        {
            value=n.value;
            left=n.left;
            right=n.right;
            spilt_val=n.spilt_val;
            boundry=n.boundry;
        }
        return *this;
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
    bool KDTree<dtype>::isleaf(std::weak_ptr<KDNode<dtype>> node)
    {
        auto left=node.lock()->get_left();
        auto right=node.lock()->get_right();
        if (!right&&!left)
        {
            return true;
        }
        return false;
    }
    template<typename dtype>
    bool isleaf(std::weak_ptr<KDNode<dtype>> node)
    {
        auto left=node.lock()->get_left();
        auto right=node.lock()->get_right();
        if (!right&&!left)
        {
            return true;
        }
        return false;
    }
    template <typename dtype>
    KDTree<dtype>::KDTree()
    {
        this->root=std::move(KDNode<dtype>());
    }

    template <typename dtype>
    KDRegion2D KDNode<dtype>::get_boundry() const
    {
        return this->boundry;
    }

    template <typename dtype>
    KDTree<dtype>::KDTree(std::vector<vector::vect2D<dtype>>& data)
    {
        this->root=this->construct_kdtree(data,0);
        root.get()->boundry=this->DEFAULT;
        this->preprocess_boundaries(this->root,true);
    }
    template <typename dtype>
    KDTree<dtype>::KDTree(KDTree&&t)noexcept:root(std::move(t.root)),INVALID(std::move(t.INVALID)),DEFAULT(std::move(t.DEFAULT))
    {}
    template <typename dtype>
    KDTree<dtype>::KDTree(const KDTree&t):root(t.root),INVALID(t.INVALID),DEFAULT(t.DEFAULT)
    {}
    template <typename dtype>
    KDTree<dtype>&KDTree<dtype>::operator=(KDTree&&t)noexcept
    {
        if (this!=&t)
        {
            root=std::move(t.root);
            INVALID=std::move(t.INVALID);
            DEFAULT=std::move(t.DEFAULT);
        }
        return *this;
    }

    template <typename dtype>
    KDTree<dtype>::~KDTree()
    {

    }

    template <typename dtype>
    KDTree<dtype>&KDTree<dtype>::operator=(const KDTree&t)
    {
        if (this!=&t)
        {
            root=t.root;
            INVALID=t.INVALID;
            DEFAULT=t.DEFAULT;
        }
        return *this;

    }
    template<typename dtype>
    void KDTree<dtype>::preprocess_boundaries(std::weak_ptr<KDNode<dtype>>node,bool iseven)
    {
        if (!node.lock().get()||isleaf(node))
        {
            return;
        }
        if (iseven)
        {
            auto left=node.lock()->get_left();
            auto right=node.lock()->get_right();
            if (left.lock().get())
            {
                left.lock().get()->get_boundry()=node.lock()->get_boundry();
                left.lock().get()->get_boundry().right=node.lock()->get_value();
                preprocess_boundaries(left,!iseven);
            }
            if (right.lock().get())
            {
                right.lock()->get_boundry()=node.lock()->get_boundry();
                right.lock()->get_boundry().left=node.lock()->get_value();
                preprocess_boundaries(right,!iseven);
            }
        }
        else
        {
            auto left=node.lock()->get_left();
            auto right=node.lock()->get_right();
            if (left.lock().get())
            {
                left.lock().get()->get_boundry()=node.lock()->get_boundry();
                left.lock().get()->get_boundry().top=node.lock()->get_value();
                preprocess_boundaries(left,!iseven);
            }
            if (right.lock().get())
            {
                right.lock()->get_boundry()=node.lock()->get_boundry();
                right.lock()->get_boundry().boto=node.lock()->get_value();
                preprocess_boundaries(right,!iseven);
            }

        }

    }
    template <typename dtype>
    std::shared_ptr<KDNode<dtype>> KDTree<dtype>::construct_kdtree(std::vector<vector::vect2D<dtype, 2>>& data, int depth)
    {
        if (data.size()==1)
        {
            return std::make_shared<KDNode<dtype>>(data.front());
        }
        depth%2==0?std::sort(data.begin(),data.end(),x_comparator):
            std::sort(data.begin(),data.end(),y_comparator);
        auto mid=data.size()/2;
        auto mid_ptr=data.begin();
        std::advance(mid_ptr,mid);
        auto left_vec=std::vector<vector::vect2D<dtype>>(data.begin(),mid_ptr);
        auto right_vec=std::vector<vector::vect2D<dtype>>(mid_ptr,data.end());
        auto left_subtree=construct_kdtree(left_vec,depth+1);
        auto right_subtree=construct_kdtree(right_vec,depth+1);
        return std::make_shared<KDNode<dtype>>((*mid_ptr)[depth%2],left_subtree,right_subtree);
    }
    template<typename dtype>
    void traverse_kdtree(std::weak_ptr<KDNode<dtype>>node,std::vector<vector::vect2D<dtype>>&list)
    {
        if (!node.lock().get())
        {
            return;
        }
        traverse_kdtree(node.lock()->get_left(),list);
        if (isleaf(node))
        {
            list.push_back(node.lock()->get_value());
        }
        traverse_kdtree(node.lock()->get_right(),list);
    }

    bool isinside(const KDRegion2D& r1, const KDRegion2D& r2)
    {
        auto left_comp=r1.left>=r2.left;
        auto right_comp=r1.right<=r2.right;
        auto top_comp=r1.top<=r2.top;
        auto bottom_comp=r1.bottom>=r2.bottom;
        return left_comp&&right_comp&&top_comp&&bottom_comp;
    }

    bool intersection(const KDRegion2D& r1, const KDRegion2D& r2)
    {
        auto rl_comp=r1.right<r2.left;
        auto lr_comp=r1.left>r2.right;
        auto tb_comp=r1.top<r2.bottom;
        auto bt_comp=r1.bottom>r2.top;

        if (rl_comp||lr_comp)
        {
            return false;
        }
        if (tb_comp||bt_comp)
        {
            return false;
        }
        return true;
    }
    template<typename dtype>
    bool in_range(vector::vect2D<dtype>&v,KDRegion2D &r)
    {
        auto x_min_comp=v[X]>=r.bottom,x_mx_comp=v[X]<=r.top;
        auto y_min_comp=v[Y]>=r.left,y_mx_comp=v[Y]<=r.right;
        return x_min_comp&&x_mx_comp&&y_min_comp&&y_mx_comp;
    }
    template<typename dtype>
    void searchKDTree(std::weak_ptr<KDNode<dtype>>node,KDRegion2D range,std::vector<vector::vect2D<dtype>>&vec)
    {
        if (isleaf(node))
        {
            auto node_val=node.lock()->get_value();
            if (in_range(node,range))
            {
                vec.push_back(node_val);
            }
        }
        else
        {
            auto left_child=node.lock()->get_left();
            auto left_child_bound=left_child.lock()->get_boundry();
            auto right_child=node.lock()->get_right();
            auto right_child_bound=right_child.lock()->get_boundry();
            if (left_child!=nullptr)
            {
                if (isinside(left_child_bound,range))
                {
                    traverse_kdtree(left_child,vec);
                }
                else if (intersection(left_child_bound,range))
                {
                    searchKDTree(left_child,range,vec);
                }
            }
            if (right_child!=nullptr)
            {
                if (isinside(right_child_bound,range))
                {
                    traverse_kdtree(right_child,vec);
                }
                else if (intersection(right_child_bound,range))
                {
                    searchKDTree(right_child,range,vec );
                }
            }
        }
    }


    template<typename dtype>
std::tuple<std::weak_ptr<KDNode<dtype>>,vector::vect2D<dtype>,dtype>nearest_neighbour(
    std::weak_ptr<KDNode<dtype>> node,vector::vect2D<dtype>&search_node_val,dtype &curr_dist,bool is_even_depth,
    vector::vect2D<dtype>&curr_mn_nn)
    {
        auto curr_node_val=node.lock()->get_value();
        auto dist=Distance::squared_distance<dtype,DIM2>(search_node_val,curr_node_val);
        if (isleaf(node))
        {
            if (dist<curr_dist)
            {
                return std::make_tuple<std::weak_ptr<KDNode<dtype>>,
                vector::vect2D<dtype>,dtype>(node,curr_node_val,dist);
            }
        }
        auto idx=is_even_depth?X:Y;
        //TODO: fix and optimize the function
    }
    //template<typename dtype>
    //void searchKDTree(std::weak_ptr<KDNode<dtype>> _node, KDRegion2D _range, std::list<vector::vect2D<dtype>>& _list) {
    //    if (isleaf(_node)) {
    //        if (isinside(_node->data, _range))
    //            _list.push_back(_node->data);
    //    }
    //    else {
    //        if (isContained(_node->left->boundary, _range)) {
    //            traverse(_node->left, _list);
    //        }
    //        else if (isIntersect(_node->left->boundary, _range)) {
    //            searchKDTree(_node->left, _range, _list);
    //        }
    //
    //        if (isContained(_node->right->boundary, _range)) {
    //            traverse(_node->right, _list);
    //        }
    //        else if (isIntersect(_node->right->boundary, _range)) {
    //            searchKDTree(_node->right, _range, _list);
    //        }
    //    }
    //}
}
