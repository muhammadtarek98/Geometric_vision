#include "partitioning.hpp"
namespace GeometricVision::PolygonPartition
{

    template <class type, size_t dim>
    SweepLine<type, dim>::SweepLine(std::shared_ptr<point::point2d> pt):point(pt)
    {}

    template <typename type, size_t dim>
    bool SweepLine<type,dim>::operator()(std::unique_ptr<const EdgeWrapper<type, dim>> ref1, std::unique_ptr<const EdgeWrapper<type, dim>> ref2)
    {
        return ref1->computeX(point)<ref2->computeX(point);
    }
    template<class type,size_t dim>
    void handle_start_vert(VertexWrapper<type,dim>&vert,
                           std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                    SweepLine<type,dim>>&sweep_line,
                           std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                    EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly)
    {
        std::weak_ptr<EdgeWrapper<type,dim>>edge(vert.vert->edge,vert);
        sweep_line.insert(edge);
        edge_mapper[vert.vert->edge]=edge;

    }
    template<class type,size_t dim>
    void handle_end_vert(VertexWrapper<type,dim>&vert,
                         std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                  SweepLine<type,dim>>&sweep_line,
                         std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                  EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly)
    {
        auto edge_wrap=edge_mapper[vert.vert->edge->prev];
        auto found=sweep_line.find(edge_wrap);
        auto helper_vert=(*found)->helper_vert;
        if (helper_vert.category==VERTEX_CATEGORY::MERGE)
        {
            poly->spilt(vert.vert,helper_vert.vert);
        }
        sweep_line.erase(found);
    }
    template<class type,size_t dim>
    void handle_split_vert(VertexWrapper<type,dim>&vert,
                           std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                    SweepLine<type,dim>>&sweep_line,
                           std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                    EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly){
        std::weak_ptr<EdgeWrapper<type,dim>> edge{EdgeWrapper<type,dim>(vert.vert->edge,vert)};
        auto found=sweep_line.lower_bound(edge);
        std::unique_ptr<EdgeWrapper<type,dim>>ej;
        if (found==sweep_line.end())
        {
            if (sweep_line.size()>0)
            {
                ej=*(--found);
                poly->split(vert.vert,ej->helper_vert.vert);
                ej->helper_vert=vert;
            }
        }
        else if (found!=sweep_line.begin())
        {
            ej=*(--found);
            poly->split(vert.vert,ej->helper_vert->vert);
            ej->helper_vert=vert;
        }
        sweep_line.insert(edge);
        edge_mapper[vert.vert->edge]=edge;
    }
    template<class type,size_t dim>
    void handle_merge_vert(VertexWrapper<type,dim>&vert,
                           std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                    SweepLine<type,dim>>&sweep_line,
                           std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                    EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly){
        auto edge_wrapper=edge_mapper[vert.vert->edge->prev];
        if (edge_wrapper->helper_vert.category==VERTEX_CATEGORY::MERGE)
        {
            poly->split(vert.vert,edge_wrapper->helper_vert.vert);
        }
        auto found=sweep_line.find(edge_wrapper);
        if (found!=sweep_line.end())
        {
            sweep_line.erase(found);
        }
        std::weak_ptr<EdgeWrapper<type,dim>>edge{EdgeWrapper<type,dim>(vert.vert->edge,vert)};
        std::unique_ptr<EdgeWrapper<type,dim>>ej;
        found=sweep_line.lower_bound(edge);
        if (found==sweep_line.end())
        {
            if (sweep_line.size()>0)
            {
                ej=*(--found);
                if (ej->helper_vert.category==VERTEX_CATEGORY::MERGE)
                {
                    poly.split(vert.vert,ej->helper_vert.vert);
                }
                ej->helper_vert=vert;
            }
        }
        else if (found!=sweep_line.begin())
        {
            ej=*(--found);
            if (ej->helper_vert.category==VERTEX_CATEGORY::MERGE)
            {
                poly->split(vert.vert,ej->helper_vert.vert);
            }
            ej->helper_vert=vert;
        }
    }

    template<class type,size_t dim>
    void handle_regular_vert(VertexWrapper<type,dim>&vert,
                             std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                                      SweepLine<type,dim>>&sweep_line,
                             std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                                      EdgeWrapper<type,dim>>&edge_mapper,std::shared_ptr<DCEL::Polygon<type,dim>>poly)
    {
        auto prev_y=vert.vert->edge->prev->origin->point[Y];
        auto curr_y=vert.vert->point[Y];
        auto next_y=vert.vert->edge->next->origin->point[Y];
        std::shared_ptr<EdgeWrapper<type,dim>> edge{EdgeWrapper<type,dim>(vert.vert->edge->prev,vert)};
        if (prev_y>=curr_y&&curr_y>=next_y)
        {
            auto edge_wrapper=edge_mapper[vert.vert->edge->prev];
            if (edge_wrapper->helper_vert.category==VERTEX_CATEGORY::MERGE)
            {
                poly->spilt(vert.vert,edge_wrapper->helper_vert);
            }
            auto found=sweep_line.find(edge_wrapper);
            if (found!=sweep_line.end())
            {
                sweep_line.erase(found);
            }
            sweep_line.insert(edge);
            edge_mapper[vert.vert->edge]=edge;
        }
        else
        {
            auto found=sweep_line.lower_bound(edge);
            std::unique_ptr<EdgeWrapper<type,dim>> ej;
            if (found==sweep_line.end())
            {
                if (sweep_line.size()>0)
                {
                    ej=*(--found);
                    if (ej->helper_vert.category==VERTEX_CATEGORY::MERGE)
                    {
                        poly->split(vert.vert,ej->helper_vert.vert);
                    }
                    ej->helper_vert=vert;
                }
            }
            else if (found!=sweep_line.begin())
            {
                ej=*(--found);
                if (ej->helper_vert.category==VERTEX_CATEGORY::MERGE)
                {
                    poly->split(vert.vert,ej->helper_vert.vert);
                }
                ej->helper_vert=vert;
            }
        }

    }


    template<class type,size_t dim>
    void get_monotone_polygon(std::shared_ptr<DCEL::Polygon<type,dim>> poly,
                              std::vector<std::shared_ptr<DCEL::Polygon<type,dim>>> mono_polys){
        std::vector<VertexWrapper<type,dim>> verts;
        for (auto vert:poly->get_vertex_list())
        {
            verts.push_back(VertexWrapper<type,dim>{vert,vertex_category(vert)});
        }
        std::sort(verts.begin(),verts.end(),VertexWrapper<type,dim>());
        std::shared_ptr<point::point2d> sweep_pt;
        sweep_pt->assign(X,verts[0].vert->point[X]);
        sweep_pt->assign(Y,verts[0].vert->point[Y]);
        SweepLine<type,dim> comp(sweep_pt);
        std::set<std::shared_ptr<EdgeWrapper<type,dim>>,
                 SweepLine<type,dim>> sweep_line(comp);
        std::map<std::weak_ptr<DCEL::Edge<type,dim>>,
                 std::shared_ptr<EdgeWrapper<type,dim>>> edge_mapper;
        for (auto vert:verts)
        {
            sweep_pt->assign(X,vert.vert->point[X]);
            sweep_pt->assign(Y,vert.vert->point[Y]);
            auto curr_pt_cart=vert.category;
            if (curr_pt_cart==VERTEX_CATEGORY::START)
            {
                handle_start_vert(vert,sweep_line,edge_mapper,poly);

            }
            else if (curr_pt_cart==VERTEX_CATEGORY::END)
            {
                handle_end_vert(vert,sweep_line,edge_mapper,poly);
            }
            else if (curr_pt_cart==VERTEX_CATEGORY::REGULAR)
            {
                handle_regular_vert(vert,sweep_line,edge_mapper,poly);

            }
            else if (curr_pt_cart==VERTEX_CATEGORY::SPLIT)
            {
                handle_split_vert(vert,sweep_line,edge_mapper,poly);
            }
            else if (curr_pt_cart==VERTEX_CATEGORY::MERGE)
            {
                handle_merge_vert(vert,sweep_line,edge_mapper,poly);
            }
            else if (curr_pt_cart==VERTEX_CATEGORY::INVALID)
            {
                return;
            }
        }
    std::vector<std::vector<point::point2d>>poly_verts;
        for (auto face_ptr:poly->get_face_list())
        {
            auto first_edge=face_ptr->outer;
            if (first_edge)
            {
                std::vector<point::point2d>verts;
                verts.push_back(first_edge->origin->point);
                auto next_edge=first_edge->next;
                while (next_edge!=first_edge)
                {
                    verts.push_back(next_edge->origin->point);
                }
                poly_verts.push_back(verts);
            }
        }
        for (auto poly_vert:poly_verts)
        {
            mono_polys.push_back(std::make_shared<DCEL::Polygon<type,dim>>(poly));
        }
    }
}
