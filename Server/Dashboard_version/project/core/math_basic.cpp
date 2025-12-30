#include <iostream>
#include "math_basic.h"

using namespace std;

int random_in_range(int min, int max){
    return rand() % (max - min + min);
}

float interp(float min, float max, float power){
    return min + power * (max - min);
}

float random_single(){
    return rand() / 32767.0;
}

float deg2rad(float deg){
    return deg * M_PI / 180;
}

float rad2deg(float rad){
    return rad * 180 / M_PI;
}

Vector3D rot2vecX(float rotation){
    Vector3D result;
    float angle = deg2rad(rotation);

    result.x = 1;
    result.y = cos(angle) - sin(angle);
    result.z = sin(angle) + cos(angle);

    return result;
};

Vector3D rot2vecY(float rotation){
    Vector3D result;
    float angle = deg2rad(rotation);

    result.x = cos(angle) + sin(angle);
    result.y = 1;
    result.z = -sin(angle) + cos(angle);

    return result;
};

Vector3D rot2vecZ(float rotation){
    Vector3D result;
    float angle = deg2rad(rotation);

    result.x = cos(angle) - sin(angle);
    result.y = sin(angle) + cos(angle);
    result.z = 1;

    return result;
};

Vector3D rot2vec(Vector3D rotation, float power){
    Vector3D result;
    result = power;

    //https://grafika.me/node/82
    //по X
    result.x = result.x;
    result.y = result.y * cos(deg2rad(rotation.x)) + result.z * sin(deg2rad(rotation.x));
    result.z = -result.y * sin(deg2rad(rotation.x)) + result.z * cos(deg2rad(rotation.x));
    //по Y
    result.x = result.x * cos(deg2rad(rotation.y)) + result.z * sin(deg2rad(rotation.y));
    result.y = result.y;
    result.z = -result.x * sin(deg2rad(rotation.y)) + result.z * cos(deg2rad(rotation.y));
    //по Z
    result.x = result.x * cos(deg2rad(rotation.z)) - result.y * sin(deg2rad(rotation.z));
    result.y = -result.x * sin(deg2rad(rotation.z)) + result.y * cos(deg2rad(rotation.z));
    result.z = result.z;

    //result.x = (a0.x * a1.m0.x) + (a0.y * a1.m0.y) + (a0.z * a1.m0.z);
    //result.y = (a0.x * a1.m1.x) + (a0.y * a1.m1.y) + (a0.z * a1.m1.z);
    //result.z = (a0.x * a1.m2.x) + (a0.y * a1.m2.y) + (a0.z * a1.m2.z);

    return result;
};
