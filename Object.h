#ifndef OBJECT_H_
#define OBJECT_H_

#include "Graphics.h"
#include "Matrix.h"
#include "Vector.h"
#include "Transformation.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

using namespace std;


struct Vertex{
    Vec3 v;
    vector <Vec3> normals;
};


class Object3d{
    private:
        vector <Vertex> vertBuffer;   //List of Vertices
        vector <Vec2> textureBuffer; //List of textures
        vector <Vec3> normBuffer;   //List of normals
        vector <Vec3> surfaceBuffer; //list of Surfaces(vert,texture,norm)
        bool texture;

    public:
        Object3d(){texture = false;}

        void addVertex(Vec3& v){
            vertBuffer.push_back(Vertex());
            unsigned int index = vertBuffer.size()-1;
            vertBuffer[index].v = v;
        }
        void addVertex(unsigned int index, Vec3 norm){
            vertBuffer[index].normals.push_back(norm);
        }
    
        void addSurface(Vec3& v){surfaceBuffer.push_back(v);}
        void addNormal(Vec3& v){normBuffer.push_back(v);}
        void addTexture(Vec2& v){textureBuffer.push_back(v);}
        void drawWire(Screen* , Vec3& camera,Vec3& LookTo);
        void LoadObject(string filename);
};



#endif // OBJECT_H_

