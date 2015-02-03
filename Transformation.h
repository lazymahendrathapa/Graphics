#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Vector.h"
#include "Matrix.h"


Vec3 World_To_Pixel(const Vec3& source ,          //World pofloat to convert floato pixel pofloat
                        const Vec3& camera,       //Point from where you are watching
                        const Vec3& LookTo);       //Where are we looking at from the camera pos


#endif

