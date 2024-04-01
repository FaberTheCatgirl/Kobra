#include "stdafx.h"
#include "Vector.h"

Vector2::Vector2() : X(0.0), Y(0.0) {}

Vector2::Vector2(double x, double y) : X(x), Y(y) {}

Vector3::Vector3() : Z(0.0) {}

Vector3::Vector3(double x, double y, double z) : Vector2(x, y), Z(z) {}

Vector3 Vector3::Cross(const Vector3& left, const Vector3& right)
{
    Vector3 returnValue;

    returnValue.X = left.Y * right.Z - left.Z * right.Y;
    returnValue.Y = left.Z * right.X - left.X * right.Z;
    returnValue.Z = left.X * right.Y - left.Y * right.X;

    return returnValue;
}

Vector4::Vector4() : W(0.0) {}

Vector4::Vector4(double x, double y, double z, double w) : Vector3(x, y, z), W(w) {}

Vector3 Vector4::ToEuler()
{
    Vector3 result;

    double t0 = 2.0 * (W * X + Y * Z);
    double t1 = 1.0 - 2.0 * (X * X + Y * Y);
    result.X = atan2(t0, t1);

    double t2 = 2.0 * (W * Y - Z * X);
    t2 = t2 > 1.0 ? 1.0 : t2;
    t2 = t2 < -1.0 ? -1.0 : t2;
    result.Y = asin(t2);

    double t3 = +2.0 * (W * Z + X * Y);
    double t4 = +1.0 - 2.0 * (Y * Y + Z * Z);
    result.Z = atan2(t3, t4);

    return result;
}