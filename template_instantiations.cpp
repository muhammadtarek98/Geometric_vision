// template_instantiations.cpp
// MUST be compiled ONCE – do NOT include in any header.

#include "vector.hpp"
#include "point.hpp"
#include "line.hpp"
#include "plane.hpp"
#include "angles.hpp"
#include "distance.hpp"
#include "geo_utils.hpp"
#include "intersection.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Face.hpp"
#include "Polygon.hpp"
#include "vertex3D.hpp"
#include "Edge3D.hpp"
#include "face.hpp"

using namespace GeometricVision;

// ============================================================================
// Vector class (already in vector.cpp for float/double, we add int)
// ============================================================================
namespace GeometricVision::vector {
    template class Vector<int, 2>;
    template class Vector<int, 3>;

    // Free functions (missing from vector.cpp)
    template float cross_product_2D<float>(vect2D<float>, vect2D<float>);
    template double cross_product_2D<double>(vect2D<double>, vect2D<double>);
    template int cross_product_2D<int>(vect2D<int>, vect2D<int>);

    template vect3D<float> cross_product_3D<float>(vect3D<float>, vect3D<float>);
    template vect3D<double> cross_product_3D<double>(vect3D<double>, vect3D<double>);
    template vect3D<int> cross_product_3D<int>(vect3D<int>, vect3D<int>);

    template double scalar_triple_dot_product<float>(const vect3D<float>&, const vect3D<float>&, const vect3D<float>&);
    template double scalar_triple_dot_product<double>(const vect3D<double>&, const vect3D<double>&, const vect3D<double>&);
    template double scalar_triple_dot_product<int>(const vect3D<int>&, const vect3D<int>&, const vect3D<int>&);

    template double areaTriangle2D<float>(const vect2D<float>&, const vect2D<float>&, const vect2D<float>&);
    template double areaTriangle2D<double>(const vect2D<double>&, const vect2D<double>&, const vect2D<double>&);
    template double areaTriangle2D<int>(const vect2D<int>&, const vect2D<int>&, const vect2D<int>&);

    template int orientation2D<float>(const vect2D<float>&, const vect2D<float>&, const vect2D<float>&);
    template int orientation2D<double>(const vect2D<double>&, const vect2D<double>&, const vect2D<double>&);
    template int orientation2D<int>(const vect2D<int>&, const vect2D<int>&, const vect2D<int>&);
}

// ============================================================================
// Point sorting functions
// ============================================================================
namespace GeometricVision::Point {
    template bool sort_point2d_left_right_top_bottom<float>(const point2d<float>&, const point2d<float>&);
    template bool sort_point2d_left_right_top_bottom<double>(const point2d<double>&, const point2d<double>&);
    template bool sort_point2d_left_right_top_bottom<int>(const point2d<int>&, const point2d<int>&);

    template bool sort_point2d_top_bottom_left_right<float>(const point2d<float>&, const point2d<float>&);
    template bool sort_point2d_top_bottom_left_right<double>(const point2d<double>&, const point2d<double>&);
    template bool sort_point2d_top_bottom_left_right<int>(const point2d<int>&, const point2d<int>&);

    template bool sort_point2d_by_x<float>(const point2d<float>&, const point2d<float>&);
    template bool sort_point2d_by_x<double>(const point2d<double>&, const point2d<double>&);
    template bool sort_point2d_by_x<int>(const point2d<int>&, const point2d<int>&);

    template bool sort_point2d_by_y<float>(const point2d<float>&, const point2d<float>&);
    template bool sort_point2d_by_y<double>(const point2d<double>&, const point2d<double>&);
    template bool sort_point2d_by_y<int>(const point2d<int>&, const point2d<int>&);

    template bool sort_point3d_top_bottom_left_right<float>(const point3d<float>&, const point3d<float>&);
    template bool sort_point3d_top_bottom_left_right<double>(const point3d<double>&, const point3d<double>&);
    template bool sort_point3d_top_bottom_left_right<int>(const point3d<int>&, const point3d<int>&);
}

// ============================================================================
// Line class
// ============================================================================
namespace GeometricVision::Line {
    template class Line<float, 2>;
    template class Line<float, 3>;
    template class Line<double, 2>;
    template class Line<double, 3>;
    template class Line<int, 2>;
    template class Line<int, 3>;
}

// ============================================================================
// Plane class
// ============================================================================
namespace GeometricVision::plane {
    template class Plane<float>;
    template class Plane<double>;
    template class Plane<int>;
}

// ============================================================================
// Angle functions
// ============================================================================
namespace GeometricVision::Angle {
    template double calculate_angle_lines_2d<float>(const Line::line2d<float>&, const Line::line2d<float>&);
    template double calculate_angle_lines_2d<double>(const Line::line2d<double>&, const Line::line2d<double>&);
    template double calculate_angle_lines_2d<int>(const Line::line2d<int>&, const Line::line2d<int>&);

    template double calculate_angle_lines_3d<float>(const Line::line3d<float>&, const Line::line3d<float>&);
    template double calculate_angle_lines_3d<double>(const Line::line3d<double>&, const Line::line3d<double>&);
    template double calculate_angle_lines_3d<int>(const Line::line3d<int>&, const Line::line3d<int>&);

    template double calculate_angle_plane_and_line<float>(const plane::Plane3D<float>&, const Line::line3d<float>&);
    template double calculate_angle_plane_and_line<double>(const plane::Plane3D<double>&, const Line::line3d<double>&);
    template double calculate_angle_plane_and_line<int>(const plane::Plane3D<int>&, const Line::line3d<int>&);

    template double calculate_angle_plane_and_plane<float>(const plane::Plane3D<float>&, const plane::Plane3D<float>&);
    template double calculate_angle_plane_and_plane<double>(const plane::Plane3D<double>&, const plane::Plane3D<double>&);
    template double calculate_angle_plane_and_plane<int>(const plane::Plane3D<int>&, const plane::Plane3D<int>&);
}

// ============================================================================
// Distance functions
// ============================================================================
namespace GeometricVision::Distance {
    template float distance_line_and_point<float>(const Line::line3d<float>&, const Point::point3d<float>&);
    template float distance_line_and_point<double>(const Line::line3d<double>&, const Point::point3d<double>&);
    template float distance_line_and_point<int>(const Line::line3d<int>&, const Point::point3d<int>&);

    template float distance_point_plane<float>(const Point::point3d<float>&, const plane::Plane3D<float>&);
    template float distance_point_plane<double>(const Point::point3d<double>&, const plane::Plane3D<double>&);
    template float distance_point_plane<int>(const Point::point3d<int>&, const plane::Plane3D<int>&);
}

// ============================================================================
// GeometricUtils functions
// ============================================================================
namespace GeometricVision::GeometricUtils {
    // 2D
    template int orientation2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
    template int orientation2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
    template int orientation2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

    template bool left2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
    template bool left2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
    template bool left2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

    template bool right2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
    template bool right2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
    template bool right2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

    template bool left_or_beyond_2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
    template bool left_or_beyond_2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
    template bool left_or_beyond_2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

    template double area_triangle_2d<float>(const Point::point2d<float>&, const Point::point2d<float>&, const Point::point2d<float>&);
    template double area_triangle_2d<double>(const Point::point2d<double>&, const Point::point2d<double>&, const Point::point2d<double>&);
    template double area_triangle_2d<int>(const Point::point2d<int>&, const Point::point2d<int>&, const Point::point2d<int>&);

    // 3D
    template int orientation3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
    template int orientation3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
    template int orientation3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

    template bool left3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
    template bool left3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
    template bool left3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

    template bool right3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
    template bool right3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
    template bool right3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

    template bool left_or_beyond_3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
    template bool left_or_beyond_3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
    template bool left_or_beyond_3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

    template bool left_or_between_3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
    template bool left_or_between_3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
    template bool left_or_between_3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

    template double area_triangle_3d<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
    template double area_triangle_3d<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
    template double area_triangle_3d<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

    template bool collinear<float>(const vector::vect3D<float>&, const vector::vect3D<float>&);
    template bool collinear<double>(const vector::vect3D<double>&, const vector::vect3D<double>&);
    template bool collinear<int>(const vector::vect3D<int>&, const vector::vect3D<int>&);

    template bool collinear<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
    template bool collinear<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
    template bool collinear<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);

    template bool coplanar<float>(const vector::vect3D<float>&, const vector::vect3D<float>&, const vector::vect3D<float>&);
    template bool coplanar<double>(const vector::vect3D<double>&, const vector::vect3D<double>&, const vector::vect3D<double>&);
    template bool coplanar<int>(const vector::vect3D<int>&, const vector::vect3D<int>&, const vector::vect3D<int>&);

    template bool coplanar<float>(const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&, const Point::point3d<float>&);
    template bool coplanar<double>(const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&, const Point::point3d<double>&);
    template bool coplanar<int>(const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&, const Point::point3d<int>&);
}

// ============================================================================
// Intersection functions
// ============================================================================
namespace GeometricVision::Intersection {
    // 4-point intersection with output
    template bool intersection<float>(const Point::point2d<float>&, const Point::point2d<float>&,
                                      const Point::point2d<float>&, const Point::point2d<float>&,
                                      Point::point2d<float>&);
    template bool intersection<double>(const Point::point2d<double>&, const Point::point2d<double>&,
                                       const Point::point2d<double>&, const Point::point2d<double>&,
                                       Point::point2d<double>&);
    template bool intersection<int>(const Point::point2d<int>&, const Point::point2d<int>&,
                                    const Point::point2d<int>&, const Point::point2d<int>&,
                                    Point::point2d<int>&);

    // line2d + line2d
    template bool intersection<float>(const Line::line2d<float>&, const Line::line2d<float>&, Point::point2d<float>&);
    template bool intersection<double>(const Line::line2d<double>&, const Line::line2d<double>&, Point::point2d<double>&);
    template bool intersection<int>(const Line::line2d<int>&, const Line::line2d<int>&, Point::point2d<int>&);

    // line3d + line3d
    template bool intersection<float>(const Line::line3d<float>&, const Line::line3d<float>&, Point::point3d<float>&);
    template bool intersection<double>(const Line::line3d<double>&, const Line::line3d<double>&, Point::point3d<double>&);
    template bool intersection<int>(const Line::line3d<int>&, const Line::line3d<int>&, Point::point3d<int>&);

    // plane + line
    template Point::point3d<float> plane_line_intersection<float>(const Line::line3d<float>&, const plane::Plane3D<float>&);
    template Point::point3d<double> plane_line_intersection<double>(const Line::line3d<double>&, const plane::Plane3D<double>&);
    template Point::point3d<int> plane_line_intersection<int>(const Line::line3d<int>&, const plane::Plane3D<int>&);

    // plane + plane
    template Line::line3d<float> plane_plane_intersection<float>(const plane::Plane3D<float>&, const plane::Plane3D<float>&);
    template Line::line3d<double> plane_plane_intersection<double>(const plane::Plane3D<double>&, const plane::Plane3D<double>&);
    template Line::line3d<int> plane_plane_intersection<int>(const plane::Plane3D<int>&, const plane::Plane3D<int>&);
}

// ============================================================================
// DCEL classes
// ============================================================================
namespace GeometricVision::DCEL {
    template class Vertex<float, 2>;
    template class Vertex<float, 3>;
    template class Vertex<double, 2>;
    template class Vertex<double, 3>;
    template class Vertex<int, 2>;
    template class Vertex<int, 3>;

    template class Edge<float, 2>;
    template class Edge<float, 3>;
    template class Edge<double, 2>;
    template class Edge<double, 3>;
    template class Edge<int, 2>;
    template class Edge<int, 3>;

    template class Face<float, 2>;
    template class Face<float, 3>;
    template class Face<double, 2>;
    template class Face<double, 3>;
    template class Face<int, 2>;
    template class Face<int, 3>;

    template class Polygon<float, 2>;
    template class Polygon<float, 3>;
    template class Polygon<double, 2>;
    template class Polygon<double, 3>;
    template class Polygon<int, 2>;
    template class Polygon<int, 3>;
}

// ============================================================================
// PolyHedron classes
// ============================================================================
namespace GeometricVision::PolyHedron {
    template class Vertex3D<float>;
    template class Vertex3D<double>;
    template class Vertex3D<int>;

    template class Edge3D<float>;
    template class Edge3D<double>;
    template class Edge3D<int>;

    template class Face3D<float>;
    template class Face3D<double>;
    template class Face3D<int>;
}