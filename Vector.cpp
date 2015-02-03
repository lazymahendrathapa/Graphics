#include "Vector.h"


           
void Vec2::operator = (const Vec2& in){
                x = in.x;
                y = in.y;
            }

Vec2 Vec2::operator + (const Vec2& vec) const 
       {return Vec2(x+vec.x,y+vec.y); }

Vec2 Vec2::operator - (const Vec2& vec) const 
       {return Vec2(x-vec.x,y-vec.y); }

Vec2 Vec2::operator / (const float& d) const 
       {return Vec2(x/d,y/d);}

Vec2 Vec2::operator * (const float& d) const 
      {return Vec2(x*d,y*d);}


void Vec3::operator = (const Vec3& vec){
                      x = vec.x;
                      y = vec.y;
                      z = vec.z;
            }

           
    
Vec3 Vec3::operator + (const Vec3& vec) const 
    {return Vec3(x+vec.x,y+vec.y,z+vec.z); }

Vec3 Vec3::operator - (const Vec3& vec) const 
     {return Vec3(x-vec.x,y-vec.y,z-vec.z); }

Vec3 Vec3::operator / (const float& d) const 
     {return Vec3(x/d,y/d,z/d);}

Vec3 Vec3::operator * (const float& d) const 
      {return Vec3(x*d,y*d,z*d);}

Vec3 Vec3::crossProduct (const Vec3& v) const 
     {return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);}

float Vec3::dotProduct (const Vec3& v) const 
      {return x * v.x + y * v.y + z * v.z;}

float Vec3::norm() const 
{return x*x + y*y + z*z ;}

float Vec3::magnitude() const 
{return sqrt(norm());}

float& Vec3::operator [] (int i)
{return (&x)[i];}

