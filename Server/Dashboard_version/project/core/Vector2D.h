#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
    float x;
    float y;

    Vector2D();
    Vector2D(float _x, float _y);
    void operator+ (Vector2D a1);
    void operator+ (float a1);
    void operator- (Vector2D a1);
    void operator- (float a1);
    void operator* (Vector2D a1);
    void operator* (float a1);
    void operator/ (Vector2D a1);
    void operator/ (float a1);
    void operator= (Vector2D a1);
    void operator= (float a1);
};

#endif
