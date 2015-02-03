#ifndef VECTOR_H
#define VECTOR_H

#include<cmath>

class Vec2
{
    public: float x, y ;
    public: Vec2(){}
            Vec2(float xx, float yy): x(xx) ,y(yy) {}
            Vec2(const Vec2& in):x(in.x),y(in.y){}
            void operator = (const Vec2& );

            Vec2 operator + (const Vec2& ) const ;
            Vec2 operator - (const Vec2& ) const ;
            Vec2 operator / (const float& ) const ;
            Vec2 operator * (const float& ) const ;
};

class Vec3
{
    public: float x,y,z;
    public: Vec3(){}
            Vec3(float xx, float yy, float zz): x(xx) ,y(yy), z(zz) {}
            
            void operator = (const Vec3& );
            Vec3 operator + (const Vec3& ) const;
            Vec3 operator - (const Vec3& ) const;
            Vec3 operator / (const float& ) const;
            Vec3 operator * (const float& ) const;
            Vec3 crossProduct (const Vec3& ) const;
            float dotProduct (const Vec3& ) const;
            float norm() const;
            float magnitude() const;
            float& operator [] (int );
};






#endif
