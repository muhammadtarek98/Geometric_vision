#pragma once
#define TOL 0.0000001
namespace GeometricVision{
enum class RELATIVE_POINT_POSITION
{
    LEFT,RIGHT,BEHIND,BEYOND,BETWEEN,ORIGIN,DESTINATION
};
bool is_equal(double x,double y);
bool _xor(bool x,bool y);
float RadToDeg(double rad_angle);
}