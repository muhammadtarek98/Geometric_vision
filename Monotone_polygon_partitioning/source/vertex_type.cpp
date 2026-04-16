#include "vertex_type.hpp"

template <class type, size_t dim>
PolygonPartition::VERTEX_CATEGORY PolygonPartition::vertex_category(DCEL::Vertex<type, dim>* v)
{
    auto v_prev=v->edge->prev->origin;
    auto v_next=v->edge->next->origin;
    if (!v_prev||!v_next)
    {
        return VERTEX_CATEGORY::INVALID;
    }
    auto p_prev=v_prev->point;
    auto p_curr=v->point;
    auto p_next=v_next->point;
    bool is_left=geometric_utils::left2d(p_prev,p_curr,p_next);
    //convexity check
    if (p_curr[Y]>p_prev[Y]&&p_curr[Y]>p_next[Y])
    {
        //check for start or spilt
        if (is_left)
        {
            return VERTEX_CATEGORY::START;
        }
        else
        {
            return VERTEX_CATEGORY::SPLIT;
        }
    }
    // check for reflex angle
    else if (p_curr[Y]<p_prev[Y]&&p_curr[Y]<p_next[Y])
    {
        if (is_left)
        {
            return VERTEX_CATEGORY::END;
        }
        else
        {
            return VERTEX_CATEGORY::MERGE;
        }
    }
    else
    {
        return VERTEX_CATEGORY::REGULAR;
    }
}


