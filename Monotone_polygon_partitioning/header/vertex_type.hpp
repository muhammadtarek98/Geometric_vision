#pragma once
#include<bits/stdc++.h>
#include "Vertex.h"
#include "point.h"
#include"angles.h"
namespace GeometricVision::PolygonPartition
{
    enum class VERTEX_CATEGORY
    {
        START,
        END,
        REGULAR,
        SPLIT,
        MERGE,
        INVALID
    };
    template<class type,size_t dim>
    VERTEX_CATEGORY vertex_category(DCEL::Vertex<type,dim> *v);
}
