#pragma once

class Vector2
{
public:
    double X;
    double Y;

    Vector2();
    Vector2(double x, double y);
};

class Vector3 : public Vector2
{
public:
    double Z;

    Vector3();
    Vector3(double x, double y, double z);

    static Vector3 Cross(const Vector3& left, const Vector3& right);
};

class Vector4 : public Vector3
{
public:
    double W;

    Vector4();
    Vector4(double x, double y, double z, double w);

    Vector3 ToEuler();
};
