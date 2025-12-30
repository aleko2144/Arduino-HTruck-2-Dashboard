#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>

class Vector3D
{
public:
    float x;
    float y;
    float z;

    Vector3D();
    Vector3D(float _x, float _y, float _z);
    Vector3D operator+ (Vector3D a1);
    Vector3D operator+ (float a1);
    Vector3D operator- (Vector3D a1);
    Vector3D operator- (float a1);
    Vector3D operator* (Vector3D a1);
    Vector3D operator* (float a1);
    //Vector3D operator* (Matrix a1);
    Vector3D operator/ (Vector3D a1);
    Vector3D operator/ (float a1);
    Vector3D operator= (Vector3D a1);
    Vector3D operator= (float a1);
    Vector3D operator+= (Vector3D a1);
    Vector3D operator+= (float a1);
    Vector3D operator-= (Vector3D a1);
    Vector3D operator-= (float a1);
    float GetLength();
};

#endif
