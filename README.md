# Geometric Vision

A comprehensive C++ library for computational geometry primitives and algorithms. This project provides a robust set of tools for handling geometric objects in 2D and 3D space, including vectors, points, lines, planes, and more complex structures like DCEL (Doubly Connected Edge List).

## Features

The library is modularized into several namespaces, each covering specific geometric concepts:

### Core Primitives
- **Vector**: Template-based vector class supporting 2D and 3D operations.
  - Arithmetic operations (+, -, *, scalar multiplication)
  - Dot product, Cross product (2D/3D), Scalar triple product
  - Magnitude and Normalization
- **Point**: 2D and 3D point representations with various sorting utilities (e.g., top-bottom-left-right, by X, by Y).
- **Line**: 2D and 3D line representations defined by a point and a direction vector.
- **Plane**: 3D plane representation defined by a normal vector and a constant, or by three points.

### Geometric Operations
- **Angles**: Calculate angles between:
  - Two lines (2D and 3D)
  - A plane and a line
  - Two planes
- **Distance**: Calculate Euclidean distances:
  - Point to Line
  - Point to Plane
- **Intersection**: Determine intersections for:
  - Two lines (2D and 3D)
  - Plane and Line
  - Two Planes
- **Geometric Utils**: Helper functions for:
  - Orientation tests (2D and 3D)
  - Collinearity and Coplanarity checks
  - Triangle area calculation
  - Relative point positioning (Left, Right, Beyond, Between)

### Data Structures
- **DCEL**: Implementation of the Doubly Connected Edge List data structure, suitable for representing planar graphs, polygons, and meshes. Includes classes for `Vertex`, `Edge`, `Face`, and `Polygon`.

## Requirements

- **C++ Standard**: C++20
- **CMake**: Version 3.20 or higher
- **Dependencies**: GoogleTest (for running tests)

## Build Instructions

To build the project, use standard CMake commands:

```bash
mkdir build
cd build
cmake ..
make
```

## Testing

The project uses GoogleTest for unit testing. After building, you can run the tests using `ctest` or by executing the binary directly.

```bash
# Inside the build directory
ctest
# OR
./geometric_vision
```

## Usage Examples

### Vector Operations
```cpp
#include "vector.h"

vector::vect3D v1(1.0, 0.0, 0.0);
vector::vect3D v2(0.0, 1.0, 0.0);

// Cross product
vector::vect3D cross = vector::cross_product_3D(v1, v2); // Result: (0, 0, 1)

// Dot product
double dot = vector::dot_product(v1, v2); // Result: 0.0
```

### Intersection
```cpp
#include "intersection.h"
#include "line.h"

// Define two lines in 3D
point::point3d p1(0,0,0), p2(2,2,2);
point::point3d p3(0,2,0), p4(2,0,2);
line::line3d l1(p1, p2);
line::line3d l2(p3, p4);

point::point3d result;
if (intersection::intersection(l1, l2, result)) {
    // result contains the intersection point (1, 1, 1)
}
```

### Plane Construction
```cpp
#include "plane.h"

// Define a plane using 3 points
point::point3d p1(1,0,0);
point::point3d p2(0,1,0);
point::point3d p3(0,0,1);
plane::Plane3D myPlane(p1, p2, p3);

vector::vect3D normal = myPlane.get_normal();
```
