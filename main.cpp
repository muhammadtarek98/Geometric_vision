#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "vector.h"
#include "point.h"
#include "line.h"
#include "plane.h"
#include "angles.h"
#include "distance.h"
#include "geo_utils.h"
#include "intersection.h"
#include "core.h"
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include "Polygon.h"
using namespace GeometricVision;
TEST(CoreTest, IsEqual) {
    EXPECT_TRUE(GeometricVision::is_equal(1.0, 1.0 + TOL/2.0));
    EXPECT_FALSE(GeometricVision::is_equal(1.0, 1.0 + TOL*2.0));
}

TEST(CoreTest, Xor) {
    EXPECT_TRUE(_xor(true, false));
    EXPECT_TRUE(_xor(false, true));
    EXPECT_FALSE(_xor(true, true));
    EXPECT_FALSE(_xor(false, false));
}

TEST(CoreTest, RadToDeg) {
    EXPECT_NEAR(RadToDeg(M_PI), 180.0, 1e-6);
    EXPECT_NEAR(RadToDeg(M_PI / 2.0), 90.0, 1e-6);
}

// ============================================================================
// vector namespace tests
// ============================================================================

TEST(VectorTest, Constructor2D) {
    vector::Vector<double, DIM2> v(1.0, 2.0);
    EXPECT_DOUBLE_EQ(v[0], 1.0);
    EXPECT_DOUBLE_EQ(v[1], 2.0);
}

TEST(VectorTest, Constructor3D) {
    vector::Vector<double, DIM3> v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v[0], 1.0);
    EXPECT_DOUBLE_EQ(v[1], 2.0);
    EXPECT_DOUBLE_EQ(v[2], 3.0);
}

TEST(VectorTest, EqualityOperators) {
    vector::Vector<double, DIM2> v2a(1.0, 2.0);
    vector::Vector<double, DIM2> v2b(1.0, 2.0);
    vector::Vector<double, DIM2> v2c(3.0, 4.0);
    EXPECT_TRUE(v2a == v2b);
    EXPECT_FALSE(v2a == v2c);
    EXPECT_TRUE(v2a != v2c);
}

TEST(VectorTest, ComparisonOperators) {
    vector::Vector<double, DIM3> v3a(1.0, 2.0, 3.0);
    vector::Vector<double, DIM3> v3b(1.0, 2.0, 4.0);
    vector::Vector<double, DIM3> v3c(0.0, 0.0, 0.0);
    EXPECT_TRUE(v3a < v3b);
    EXPECT_TRUE(v3b > v3a);
    EXPECT_TRUE(v3c < v3a);
}

TEST(VectorTest, Arithmetic) {
    vector::Vector<double, DIM3> v1(1.0, 2.0, 3.0);
    vector::Vector<double, DIM3> v2(4.0, 5.0, 6.0);
    auto sum = v1 + v2;
    auto diff = v1 - v2;
    auto prod = v1 * v2;
    auto scaled = v1 * 2.0;

    EXPECT_DOUBLE_EQ(sum[0], 5.0);
    EXPECT_DOUBLE_EQ(sum[1], 7.0);
    EXPECT_DOUBLE_EQ(sum[2], 9.0);

    EXPECT_DOUBLE_EQ(diff[0], -3.0);
    EXPECT_DOUBLE_EQ(diff[1], -3.0);
    EXPECT_DOUBLE_EQ(diff[2], -3.0);

    EXPECT_DOUBLE_EQ(prod[0], 4.0);
    EXPECT_DOUBLE_EQ(prod[1], 10.0);
    EXPECT_DOUBLE_EQ(prod[2], 18.0);

    EXPECT_DOUBLE_EQ(scaled[0], 2.0);
    EXPECT_DOUBLE_EQ(scaled[1], 4.0);
    EXPECT_DOUBLE_EQ(scaled[2], 6.0);
}

TEST(VectorTest, DotProduct) {
    vector::Vector<double, DIM3> v1(1.0, 0.0, 0.0);
    vector::Vector<double, DIM3> v2(0.0, 1.0, 0.0);
    double dot = vector::Vector<double, DIM3>::dot_product(v1, v2);
    EXPECT_DOUBLE_EQ(dot, 0.0);

    vector::Vector<double, DIM3> v3(2.0, 3.0, 4.0);
    vector::Vector<double, DIM3> v4(1.0, -1.0, 2.0);
    dot = vector::Vector<double, DIM3>::dot_product(v3, v4);
    EXPECT_DOUBLE_EQ(dot, 7.0);
}

TEST(VectorTest, Magnitude) {
    vector::Vector<double, DIM3> v(3.0, 0.0, 4.0);
    EXPECT_FLOAT_EQ(v.magnitude(), 5.0f);
}

TEST(VectorTest, Normalization) {
    vector::Vector<double, DIM3> v(3.0, 0.0, 4.0);
    v.normalization();
    EXPECT_NEAR(v.magnitude(), 1.0, 1e-6);
    EXPECT_NEAR(v[0], 0.6, 1e-6);
    EXPECT_NEAR(v[1], 0.0, 1e-6);
    EXPECT_NEAR(v[2], 0.8, 1e-6);
}

TEST(VectorTest, CrossProduct2D) {
    vector::vect2D v1(1.0, 0.0);
    vector::vect2D v2(0.0, 1.0);
    float cross = vector::cross_product_2D(v1, v2);
    EXPECT_FLOAT_EQ(cross, 1.0f);
}

TEST(VectorTest, CrossProduct3D) {
    vector::vect3D v1(1.0, 0.0, 0.0);
    vector::vect3D v2(0.0, 1.0, 0.0);
    vector::vect3D cross = vector::cross_product_3D(v1, v2);
    EXPECT_DOUBLE_EQ(cross[0], 0.0);
    EXPECT_DOUBLE_EQ(cross[1], 0.0);
    EXPECT_DOUBLE_EQ(cross[2], 1.0);
}

TEST(VectorTest, ScalarTripleProduct) {
    vector::vect3D v1(1.0, 0.0, 0.0);
    vector::vect3D v2(0.0, 1.0, 0.0);
    vector::vect3D v3(0.0, 0.0, 1.0);
    double triple = vector::scalar_triple_dot_product(v1, v2, v3);
    EXPECT_DOUBLE_EQ(triple, 1.0);
}

TEST(VectorTest, AreaTriangle2D) {
    vector::vect2D p1(0.0, 0.0);
    vector::vect2D p2(1.0, 0.0);
    vector::vect2D p3(0.0, 1.0);
    double area = vector::areaTriangle2D(p1, p2, p3);
    EXPECT_DOUBLE_EQ(area, 0.5);
}

TEST(VectorTest, Orientation2D) {
    using vector::orientation2D;
    using enum RELATIVE_POINT_POSITION;
    vector::vect2D p1(0,0), p2(1,0), p3(0,1);
    EXPECT_EQ(orientation2D(p1, p2, p3), static_cast<int>(LEFT));

    vector::vect2D p4(0,0), p5(1,0), p6(2,0);
    EXPECT_EQ(orientation2D(p4, p5, p6), static_cast<int>(BEYOND));

    vector::vect2D p7(0,0), p8(1,0), p9(0,0);
    EXPECT_EQ(orientation2D(p7, p8, p9), static_cast<int>(ORIGIN));
}

// ============================================================================
// point namespace tests
// ============================================================================

TEST(PointTest, Sorting) {
    std::vector<point::point2d> pts = {
        {3,1}, {1,3}, {2,2}, {1,1}
    };

    // left-right top-bottom (x asc, y asc)
    std::sort(pts.begin(), pts.end(), point::sort_point2d_left_right_top_bottom);
    std::vector<point::point2d> expected_lrtb = {{1,1}, {1,3}, {2,2}, {3,1}};
    for (size_t i = 0; i < pts.size(); ++i) {
        EXPECT_DOUBLE_EQ(pts[i][0], expected_lrtb[i][0]);
        EXPECT_DOUBLE_EQ(pts[i][1], expected_lrtb[i][1]);
    }

    // top-bottom left-right (y desc, x asc)
    std::sort(pts.begin(), pts.end(), point::sort_point2d_top_bottom_left_right);
    std::vector<point::point2d> expected_tblr = {{1,3}, {2,2}, {1,1}, {3,1}};
    for (size_t i = 0; i < pts.size(); ++i) {
        EXPECT_DOUBLE_EQ(pts[i][0], expected_tblr[i][0]);
        EXPECT_DOUBLE_EQ(pts[i][1], expected_tblr[i][1]);
    }

    // sort by x only
    std::sort(pts.begin(), pts.end(), point::sort_point2d_by_x);
    std::vector<point::point2d> expected_x = {{1,3}, {1,1}, {2,2}, {3,1}};
    for (size_t i = 0; i < pts.size(); ++i) {
        EXPECT_DOUBLE_EQ(pts[i][0], expected_x[i][0]);
    }

    // sort by y only
    std::sort(pts.begin(), pts.end(), point::sort_point2d_by_y);
    std::vector<point::point2d> expected_y = {{1,1}, {3,1}, {2,2}, {1,3}};
    for (size_t i = 0; i < pts.size(); ++i) {
        EXPECT_DOUBLE_EQ(pts[i][1], expected_y[i][1]);
    }
}

TEST(PointTest, Sorting3D) {
    std::vector<point::point3d> pts = {
        {3,1,0}, {1,3,0}, {2,2,0}, {1,1,0}
    };
    std::sort(pts.begin(), pts.end(), point::sort_point3d_top_bottom_left_right);
    // Based on implementation: y desc, x asc
    // (1,3,0), (2,2,0), (1,1,0), (3,1,0)
    EXPECT_DOUBLE_EQ(pts[0][1], 3.0);
    EXPECT_DOUBLE_EQ(pts[1][1], 2.0);
    EXPECT_DOUBLE_EQ(pts[2][1], 1.0);
    EXPECT_DOUBLE_EQ(pts[3][1], 1.0);
}

// ============================================================================
// line namespace tests
// ============================================================================

TEST(LineTest, Construction2D) {
    vector::vect2D p1(0,0), p2(3,4);
    Line::Line<double,2> l(p1, p2);
    auto dir = l.Get_direction();
    auto pt = l.Get_point();
    EXPECT_DOUBLE_EQ(pt[0], 0);
    EXPECT_DOUBLE_EQ(pt[1], 0);
    EXPECT_NEAR(dir.magnitude(), 1.0, 1e-6);
    EXPECT_NEAR(dir[0], 0.6, 1e-6);
    EXPECT_NEAR(dir[1], 0.8, 1e-6);
}

TEST(LineTest, Construction3D) {
    vector::vect3D p1(1,2,3), p2(4,6,8);
    Line::Line<double,3> l(p1, p2);
    auto dir = l.Get_direction();
    auto pt = l.Get_point();
    EXPECT_DOUBLE_EQ(pt[0], 1);
    EXPECT_DOUBLE_EQ(pt[1], 2);
    EXPECT_DOUBLE_EQ(pt[2], 3);
    EXPECT_NEAR(dir.magnitude(), 1.0, 1e-6);
    EXPECT_NEAR(dir[0], 3.0/7.071, 1e-3);
    EXPECT_NEAR(dir[1], 4.0/7.071, 1e-3);
    EXPECT_NEAR(dir[2], 5.0/7.071, 1e-3);
}

TEST(LineTest, Setters) {
    Line::line3d l;
    vector::vect3D p(1,1,1);
    vector::vect3D d(1,0,0);
    l.set_point(p);
    l.set_direction(d);
    EXPECT_DOUBLE_EQ(l.Get_point()[0], 1.0);
    EXPECT_DOUBLE_EQ(l.Get_direction()[0], 1.0);
}

// ============================================================================
// plane namespace tests
// ============================================================================

TEST(PlaneTest, ConstructionFromNormal) {
    vector::vect3D normal(0,0,1);
    float constant=5.0;
    plane::Plane<float> p(normal,constant);
    EXPECT_DOUBLE_EQ(p.get_normal()[0], 0);
    EXPECT_DOUBLE_EQ(p.get_normal()[1], 0);
    EXPECT_DOUBLE_EQ(p.get_normal()[2], 1);
    EXPECT_FLOAT_EQ(p.GetD(), 5.0f);
}

TEST(PlaneTest, ConstructionFromPoints) {
    point::point3d p1(1,0,0);
    point::point3d p2(0,1,0);
    point::point3d p3(0,0,1);
    plane::Plane<float> plane(p1, p2, p3);

    auto n = plane.get_normal();
    double d = plane.GetD();

    // Check that the normal is normalized (unit length)
    double len = sqrt(n[0]*n[0] + n[1]*n[1] + n[2]*n[2]);
    EXPECT_NEAR(len, 1.0, 1e-6);

    // Check that each point satisfies the plane equation n·x = d
    EXPECT_NEAR(n[0]*p1[0] + n[1]*p1[1] + n[2]*p1[2], d, 1e-4);
    EXPECT_NEAR(n[0]*p2[0] + n[1]*p2[1] + n[2]*p2[2], d, 1e-4);
    EXPECT_NEAR(n[0]*p3[0] + n[1]*p3[1] + n[2]*p3[2], d, 1e-4);
}

// ============================================================================
// angle namespace tests
// ============================================================================

TEST(AngleTest, Lines2D) {
    point::point2d l1s(0,3), l1e(2,4);
    point::point2d l2s(0,5), l2e(-2,6);
    Line::line2d l1(l1s, l1e);
    Line::line2d l2(l2s, l2e);
    double ang = Angle::calculate_angle_lines_2d(l1, l2);
    // Expected angle between direction vectors (2,1) and (-2,1) after normalization:
    // dot = -0.6, acos = 126.87°
    EXPECT_NEAR(ang, 126.87, 0.01);
}

TEST(AngleTest, PlaneAndLine) {
    point::point3d l1s(-3,-4,-5), l1e(4,4,5);
    Line::line3d l(l1s, l1e);  // correct: two points

    vector::vect3D plane_norm(-14.26, 9.32, 18.89);
    // Normalize the normal (plane constructor does not normalize)
    double mag = sqrt(plane_norm[0]*plane_norm[0] + plane_norm[1]*plane_norm[1] + plane_norm[2]*plane_norm[2]);
    vector::vect3D norm_norm = plane_norm * (1.0/mag);
    plane::Plane3D p(norm_norm, 0.0f);  // plane passes through origin

    double ang = Angle::calculate_angle_plane_and_line(p, l);
    // Expected value: 90° - angle between line direction and plane normal
    // Computed as 26.17°
    EXPECT_NEAR(ang, 26.17, 0.1);
}

TEST(AngleTest, Lines3D) {
    point::point3d l1s(0,0,0), l1e(1,0,0);
    point::point3d l2s(0,0,0), l2e(0,1,0);
    Line::line3d l1(l1s, l1e);
    Line::line3d l2(l2s, l2e);
    double ang = Angle::calculate_angle_lines_3d(l1, l2);
    EXPECT_NEAR(ang, 90.0, 1e-6);
}

TEST(AngleTest, PlaneAndPlane) {
    vector::vect3D n1(1,0,0);
    vector::vect3D n2(0,1,0);
    plane::Plane3D p1(n1, 0.0f);
    plane::Plane3D p2(n2, 0.0f);
    double ang = Angle::calculate_angle_plane_and_plane(p1, p2);
    EXPECT_NEAR(ang, 90.0, 1e-6);
}

// ============================================================================
// distance namespace tests
// ============================================================================

TEST(DistanceTest, PointToLine) {
    point::point3d p(1,2,3);
    point::point3d l1(0,0,0), l2(1,0,0);
    Line::line3d l(l1, l2);
    float d = Distance::distance_line_and_point(l, p);
    EXPECT_NEAR(d, std::sqrt(13.0), 1e-4);
}

TEST(DistanceTest, PointToPlane) {
    point::point3d point(2,3,4);
    vector::vect3D normal(1,0,0);
    plane::Plane3D p(normal, 5.0f);
    float d = Distance::distance_point_plane(point, p);
    EXPECT_FLOAT_EQ(d, -3.0f);
}

// ============================================================================
// geometric_utils namespace tests
// ============================================================================

TEST(GeoUtilsTest, Orientation3D) {
    using GeometricUtils::orientation3d;
    using enum RELATIVE_POINT_POSITION;
    point::point3d p1(0,0,0), p2(1,0,0), p3(0,1,0);
    EXPECT_EQ(orientation3d(p1, p2, p3), static_cast<int>(LEFT));

    point::point3d p4(0,0,0), p5(1,0,0), p6(2,0,0);
    EXPECT_EQ(orientation3d(p4, p5, p6), static_cast<int>(BEYOND));
}

TEST(GeoUtilsTest, LeftRight) {
    using GeometricUtils::left3d;
    using GeometricUtils::right3d;
    point::point3d p1(0,0,0), p2(1,0,0), p3(0,1,0);
    EXPECT_TRUE(left3d(p1, p2, p3));
    EXPECT_FALSE(right3d(p1, p2, p3));
}

TEST(GeoUtilsTest, AreaTriangle3D) {
    point::point3d p1(0,0,0), p2(1,0,0), p3(0,1,0);
    double area = GeometricUtils::area_triangle_3d(p1, p2, p3);
    EXPECT_DOUBLE_EQ(area, 0.5);
}

TEST(GeoUtilsTest, Collinear) {
    point::point3d p1(0,0,0), p2(1,0,0), p3(2,0,0);
    EXPECT_TRUE(GeometricUtils::collinear(p1, p2, p3));
    point::point3d p4(0,0,0), p5(1,0,0), p6(0,1,0);
    EXPECT_FALSE(GeometricUtils::collinear(p4, p5, p6));
    // Note: This test currently fails because of a bug in collinear implementation.
    // The function uses an incorrect cross product term (x1*y2 - x2 - y1).
}

TEST(GeoUtilsTest, Coplanar) {
    point::point3d p1(0,0,0), p2(1,0,0), p3(0,1,0), p4(1,1,0);
    EXPECT_TRUE(GeometricUtils::coplanar(p1, p2, p3, p4));
    point::point3d p5(0,0,0), p6(1,0,0), p7(0,1,0), p8(0,0,1);
    EXPECT_FALSE(GeometricUtils::coplanar(p5, p6, p7, p8));
}

TEST(GeoUtilsTest, More2D) {
    point::point2d p1(0,0), p2(1,0), p3(0,1);
    EXPECT_EQ(GeometricUtils::orientation2d(p1, p2, p3), static_cast<int>(RELATIVE_POINT_POSITION::LEFT));
    EXPECT_TRUE(GeometricUtils::left2d(p1, p2, p3));
    EXPECT_TRUE(GeometricUtils::left_or_beyond_2d(p1, p2, p3));
    EXPECT_DOUBLE_EQ(GeometricUtils::area_triangle_2d(p1, p2, p3), 0.5);
}

TEST(GeoUtilsTest, More3D) {
    point::point3d p1(0,0,0), p2(1,0,0), p3(0,1,0);
    EXPECT_TRUE(GeometricUtils::left_or_beyond_3d(p1, p2, p3));
    EXPECT_TRUE(GeometricUtils::left_or_between_3d(p1, p2, p3));
}

// ============================================================================
// intersection namespace tests
// ============================================================================

TEST(IntersectionTest, Lines2D_Intersect) {
    point::point2d p1(0,0), p2(2,2);
    point::point2d p3(0,2), p4(2,0);
    point::point2d result;
    bool ok = Intersection::intersection(p1, p2, p3, p4, result);
    EXPECT_TRUE(ok);
    EXPECT_NEAR(result[0], 1.0, 1e-6);
    EXPECT_NEAR(result[1], 1.0, 1e-6);
}

TEST(IntersectionTest, Lines2D_Parallel) {
    point::point2d p1(0,0), p2(1,0);
    point::point2d p3(0,1), p4(1,1);
    point::point2d result;
    bool ok = Intersection::intersection(p1, p2, p3, p4, result);
    EXPECT_FALSE(ok);
}

TEST(IntersectionTest, PlaneLine) {
    point::point3d l1(0,0,0), l2(1,1,1);
    Line::line3d l(l1, l2);
    vector::vect3D normal(1,0,0);
    plane::Plane3D p(normal, 2.0f);
    point::point3d ip = Intersection::plane_line_intersection(l, p);
    EXPECT_NEAR(ip[0], 2.0, 1e-6);
    EXPECT_NEAR(ip[1], 2.0, 1e-6);
    EXPECT_NEAR(ip[2], 2.0, 1e-6);
}

TEST(IntersectionTest, PlanePlane) {
    vector::vect3D n1(1,0,0);
    vector::vect3D n2(0,1,0);
    plane::Plane3D p1(n1, 0.0f);
    plane::Plane3D p2(n2, 0.0f);
    Line::line3d l = Intersection::plane_plane_intersection(p1, p2);
    auto dir = l.Get_direction();
    EXPECT_NEAR(dir[0], 0.0, 1e-6);
    EXPECT_NEAR(dir[1], 0.0, 1e-6);
    EXPECT_NEAR(dir[2], 1.0, 1e-6);
    auto pt = l.Get_point();
    EXPECT_NEAR(pt[0], 0.0, 1e-6);
    EXPECT_NEAR(pt[1], 0.0, 1e-6);
    EXPECT_NEAR(pt[2], 0.0, 1e-6);
}

TEST(IntersectionTest, Lines3D) {
    point::point3d p1(0,0,0), p2(2,2,2);
    point::point3d p3(0,2,0), p4(2,0,2);
    point::point3d result;
    bool ok = Intersection::intersection(Line::line3d(p1,p2), Line::line3d(p3,p4), result);
    EXPECT_TRUE(ok);
    EXPECT_NEAR(result[0], 1.0, 1e-6);
    EXPECT_NEAR(result[1], 1.0, 1e-6);
    EXPECT_NEAR(result[2], 1.0, 1e-6);
}

// ============================================================================
// DCEL namespace tests
// ============================================================================

TEST(DCELTest, VertexBasic) {
    DCEL::Vertex<double, DIM3> v;
    EXPECT_TRUE(std::isinf(v.get_point()[0]));
    EXPECT_EQ(v.get_edge().lock(), nullptr);
}

TEST(DCELTest, EdgeBasic) {
    DCEL::Edge<double, DIM3> e;
    EXPECT_EQ(e.get_twin().lock(), nullptr);
}

// ============================================================================
// main
// ============================================================================
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}