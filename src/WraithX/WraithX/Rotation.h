#pragma once

#include "Vector.h"

class Rotation
{
public:
    class Matrix
    {
    public:
        double Values[16];

        Vector4 ToQuaternion() const;
        Vector3 ToEuler() const;
    };

    static double ToDegrees(double value);
    static Vector3 ToDegrees(Vector3 value);
};
