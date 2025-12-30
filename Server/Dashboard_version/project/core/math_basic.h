#ifndef MATH_BASIC_H
#define MATH_BASIC_H

#include <math.h>
#include "../core/Vector3D.h"

int random_in_range(int min, int max);
float interp(float min, float max, float power);
float random_single();
float deg2rad(float deg);
float rad2deg(float rad);
Vector3D rot2vecX(float rotation);
Vector3D rot2vecY(float rotation);
Vector3D rot2vecZ(float rotation);
Vector3D rot2vec(Vector3D rotation, float power);

#endif
