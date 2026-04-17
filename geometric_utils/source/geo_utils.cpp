#include "geo_utils.h"

#include "core.h"
namespace GeometricVision
{
    namespace GeometricUtils
    {
        int orientation2d(const point2d& p1, const point2d& p2, const point2d& p3)
        {
            auto area=area_triangle_2d(p1,p2,p3);
            if (area>0&&area<TOL)
            {
                area=0;
            }
            if (area<0&&area>TOL)
            {
                area=0;
            }
            auto p12=p2-p1;
            auto p13=p3-p1;
            if (area>0.0)
            {
                return  static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
            }
            if (area<0.0)
            {
                return  static_cast<int>(RELATIVE_POINT_POSITION::RIGHT);
            }
            if ((p12[X]*p13[X]<0.0)||(p12[Y]*p13[Y]<0.0))
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::BEHIND);
            }
            if (p12.magnitude(),p13.magnitude())
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);
            }
            if (p1==p3)
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN);
            }
            if (p2==p3)
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
            }
            return static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN);
        }

        int orientation3d(const point3d& p1, const point3d& p2, const point3d& p3)
        {
            auto area=area_triangle_3d(p1,p2,p3);
            if (area>0&&area<TOL)
            {
                area=0;
            }
            if (area<0&&area>TOL)
            {
                area=0;
            }
            auto p1x=p1[X];
            auto p1y=p1[Y];
            auto p1z=p1[Z];

            auto p2x=p2[X];
            auto p2y=p2[Y];
            auto p2z=p2[Z];

            auto p3x=p3[X];
            auto p3y=p3[Y];
            auto p3z=p3[Z];
            if (area>0.0)
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::LEFT);
            }
            if (area<0.0)
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::RIGHT);
            }
            if ((p1x*p2x<0.0)||(p1y*p2y<0.0))
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::BEHIND);
            }
            if (p1.magnitude()<p2.magnitude())
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);
            }
            if (p1==p3)
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::ORIGIN);
            }
            if (p2==p3)
            {
                return static_cast<int>(RELATIVE_POINT_POSITION::DESTINATION);
            }
            return static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN);

        }

        bool left2d(const point2d& p1, const point2d& p2, const point2d& p3)
        {
            return orientation2d(p1,p2,p3)==static_cast<bool>(RELATIVE_POINT_POSITION::LEFT);
        }

        bool left3d(const point3d& p1, const point3d& p2, const point3d& p3)
        {
            return  orientation3d(p1,p2,p3)==static_cast<int>(RELATIVE_POINT_POSITION::LEFT);

        }

        bool right3d(const point3d& p1, const point3d& p2, const point3d& p3)
        {
            return orientation3d(p1,p2,p3)==static_cast<int>(RELATIVE_POINT_POSITION::RIGHT);

        }

        double area_triangle_2d(const point2d& p1, const point2d& p2, const point2d& p3)
        {
            return 0.5 * ((p2[X] - p1[X]) * (p3[Y] - p1[Y]) - (p3[X] - p1[X]) * (p2[Y] - p1[Y]));

        }

        double area_triangle_3d(const point3d& p1, const point3d& p2, const point3d& p3)
        {
            auto p12 = p2 - p1;
            auto p13 = p3 - p1;
            auto x = p12[Y] * p13[Z] - p12[Z] * p13[Y];
            auto y = p12[X] * p13[Z] - p12[Z] * p13[X];
            auto z = p12[X] * p13[Y] - p12[Y] * p13[X];
            float sum_of_powers = pow(x,2.0) + pow(y, 2.0) + pow(z, 2.0);
            return  sqrt(sum_of_powers)/ 2;
        }


        bool left_or_between_3d(const point3d& p1, const point3d& p2, const point3d& p3)
        {
            auto position=orientation3d(p1,p2,p3);
            return position==static_cast<int>(RELATIVE_POINT_POSITION::LEFT)||position==static_cast<int>(RELATIVE_POINT_POSITION::BETWEEN);
        }

        bool left_or_beyond_2d(const point2d& p1, const point2d& p2, const point2d& p3)
        {
            auto position=orientation2d(p1,p2,p3);
            return position==static_cast<int>(RELATIVE_POINT_POSITION::LEFT)||position==static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);

        }

        bool left_or_beyond_3d(const point3d& p1, const point3d& p2, const point3d& p3)
        {
            auto position=orientation3d(p1,p2,p3);
            return position==static_cast<int>(RELATIVE_POINT_POSITION::LEFT)||position==static_cast<int>(RELATIVE_POINT_POSITION::BEYOND);
        }

        bool collinear(const vector::vect3D& v1, const vector::vect3D& v2)
        {
            auto x1=v1[X],y1=v1[Y],z1=v1[Z];
            auto x2=v2[X],y2=v2[Y],z2=v2[Z];
            auto cond1=x1*y2-x2*y1;
            auto cond2=y1*z2-y2*z1;
            auto cond3=x1*z2-x2*z1;
            return is_equal(cond1,0.0) &&is_equal(cond2,0.0)&&is_equal(cond3,0.0);
        }

        bool collinear(const point3d& p1, const point3d& p2, const point3d& p3)
        {
            auto v1=p2-p1;
            auto v2=p3-p1;
            return collinear(v1,v2);
        }

        bool coplanar(vector::vect3D& v1, vector::vect3D& v2, vector::vect3D& v3)
        {
            auto triple_product=scalar_triple_dot_product(v1,v2,v3);
            return is_equal(triple_product,0.0);
        }

        bool coplanar(const point::point3d& p1, const point::point3d& p2, const point::point3d& p3, const point::point3d& p4)
        {
            auto l1=(p2-p1);
            auto l2=(p3-p1);
            auto l3=(p4-p1);
            return coplanar(l1,l2,l3);
        }
    }
}