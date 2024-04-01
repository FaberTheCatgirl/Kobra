#include "stdafx.h"
#include "Rotation.h"

Vector4 Rotation::Matrix::ToQuaternion() const
{
    Vector4 result(0, 0, 0, 1.0);

    double divisor;
    double transRemain = Values[0] + Values[5] + Values[10];

    if (transRemain > 0)
    {
        divisor = std::sqrt(transRemain + 1.0) * 2.0;
        result.W = 0.25 * divisor;
        result.X = (Values[6] - Values[9]) / divisor;
        result.Y = (Values[8] - Values[2]) / divisor;
        result.Z = (Values[1] - Values[4]) / divisor;
    }
    else if ((Values[0] > Values[5]) && (Values[0] > Values[10]))
    {
        divisor = std::sqrt(1.0 + Values[0] - Values[5] - Values[10]) * 2.0;
        result.W = (Values[6] - Values[9]) / divisor;
        result.X = 0.25 * divisor;
        result.Y = (Values[4] + Values[1]) / divisor;
        result.Z = (Values[8] + Values[2]) / divisor;
    }
    else if (Values[5] > Values[10])
    {
        divisor = std::sqrt(1.0 + Values[5] - Values[0] - Values[10]) * 2.0;
        result.W = (Values[8] - Values[2]) / divisor;
        result.X = (Values[4] + Values[1]) / divisor;
        result.Y = 0.25 * divisor;
        result.Z = (Values[9] + Values[6]) / divisor;
    }
    else
    {
        divisor = std::sqrt(1.0 + Values[10] - Values[0] - Values[5]) * 2.0;
        result.W = (Values[1] - Values[4]) / divisor;
        result.X = (Values[8] + Values[2]) / divisor;
        result.Y = (Values[9] + Values[6]) / divisor;
        result.Z = 0.25 * divisor;
    }

    return result;
}

Vector3 Rotation::Matrix::ToEuler() const
{
    Vector4 quaternion = ToQuaternion();
    Vector3 result;

    double t0 = 2.0 * (quaternion.W * quaternion.X + quaternion.Y * quaternion.Z);
    double t1 = 1.0 - 2.0 * (quaternion.X * quaternion.X + quaternion.Y * quaternion.Y);

    result.X = std::atan2(t0, t1);

    double t2 = 2.0 * (quaternion.W * quaternion.Y - quaternion.Z * quaternion.X);

    t2 = t2 > 1.0 ? 1.0 : t2;
    t2 = t2 < -1.0 ? -1.0 : t2;
    result.Y = std::asin(t2);

    double t3 = +2.0 * (quaternion.W * quaternion.Z + quaternion.X * quaternion.Y);
    double t4 = +1.0 - 2.0 * (quaternion.Y * quaternion.Y + quaternion.Z * quaternion.Z);

    result.Z = std::atan2(t3, t4);

    return result;
}

double Rotation::ToDegrees(double value)
{
    return (value / (2 * std::acos(-1))) * 360;
}

Vector3 Rotation::ToDegrees(Vector3 value)
{
    return Vector3(ToDegrees(value.X), ToDegrees(value.Y), ToDegrees(value.Z));
}