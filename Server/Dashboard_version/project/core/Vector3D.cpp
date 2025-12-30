#include "Vector3D.h"

Vector3D::Vector3D(){
    x = 0;
    y = 0;
    z = 0;
};

Vector3D::Vector3D(float _x, float _y, float _z){
    x = _x;
    y = _y;
    z = _z;
    //return *this;
};

Vector3D Vector3D::operator+ (Vector3D a1){
    x += a1.x;
    y += a1.y;
    z += a1.z;
    //return *this;
};
Vector3D Vector3D::operator+ (float a1){
    x += a1;
    y += a1;
    z += a1;
    //return *this;
};

Vector3D Vector3D::operator- (Vector3D a1){
    x -= a1.x;
    y -= a1.y;
    z -= a1.z;
    //return *this;
};
Vector3D Vector3D::operator- (float a1){
    x -= a1;
    y -= a1;
    z -= a1;
    //return *this;
};

Vector3D Vector3D::operator* (Vector3D a1){
    x *= a1.x;
    y *= a1.y;
    z *= a1.z;
    //return *this;
};
Vector3D Vector3D::operator* (float a1){
    x *= a1;
    y *= a1;
    z *= a1;
    //return *this;
};
/*Vector3D Vector3D::operator* (Matrix a1){
    x = x * a1.m0.x * a1.m0.y * a1.m0.z;
    y = y * a1.m1.x * a1.m1.y * a1.m1.z;
    z = z * a1.m2.x * a1.m2.y * a1.m2.z;
};*/

Vector3D Vector3D::operator/ (Vector3D a1){
    x /= a1.x;
    y /= a1.y;
    z /= a1.z;
    //return *this;
};
Vector3D Vector3D::operator/ (float a1){
    x /= a1;
    y /= a1;
    z /= a1;
    //return *this;
};

Vector3D Vector3D::operator= (Vector3D a1){
    x = a1.x;
    y = a1.y;
    z = a1.z;
};
Vector3D Vector3D::operator= (float a1){
    x = a1;
    y = a1;
    z = a1;
};

Vector3D Vector3D::operator+= (Vector3D a1){
    x += a1.x;
    y += a1.y;
    z += a1.z;
    //return *this;
};
Vector3D Vector3D::operator+= (float a1){
    x += a1;
    y += a1;
    z += a1;
    //return *this;
};

Vector3D Vector3D::operator-= (Vector3D a1){
    x -= a1.x;
    y -= a1.y;
    z -= a1.z;
};
Vector3D Vector3D::operator-= (float a1){
    x -= a1;
    y -= a1;
    z -= a1;
};
float Vector3D::GetLength(){
    return sqrt(x*x + y*y + z*z);
};
