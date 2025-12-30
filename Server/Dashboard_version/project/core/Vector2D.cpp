#include "Vector2D.h"

Vector2D::Vector2D(){
    x = 0;
    y = 0;
};

Vector2D::Vector2D(float _x, float _y){
    x = _x;
    y = _y;
};

void Vector2D::operator+ (Vector2D a1){
    x += a1.x;
    y += a1.y;
};
void Vector2D::operator+ (float a1){
    x += a1;
    y += a1;
};

void Vector2D::operator- (Vector2D a1){
    x -= a1.x;
    y -= a1.y;
};
void Vector2D::operator- (float a1){
    x -= a1;
    y -= a1;
};

void Vector2D::operator* (Vector2D a1){
    x *= a1.x;
    y *= a1.y;
};
void Vector2D::operator* (float a1){
    x *= a1;
    y *= a1;
};

void Vector2D::operator/ (Vector2D a1){
    x /= a1.x;
    y /= a1.y;
};
void Vector2D::operator/ (float a1){
    x /= a1;
    y /= a1;
};

void Vector2D::operator= (Vector2D a1){
    x = a1.x;
    y = a1.y;
};
void Vector2D::operator= (float a1){
    x = a1;
    y = a1;
};
