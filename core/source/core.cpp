#include "core.h"
#include <cmath>

bool GeometricVision::is_equal(double x,double y)
{
    return fabs(x-y)<TOL;
}

bool GeometricVision::_xor(bool x, bool y)
{
    return x ^ y;
}

float GeometricVision::RadToDeg(double rad_angle)
{
		return static_cast<float>(rad_angle) * 180 / ( M_PI);
}
