//
//  main.cpp
//  jellyphysics
//
//  Created by Paul on 15/06/2012.
//  Copyright (c) 2012 Paul. All rights reserved.
//

#include <iostream>
#include "World.h"
#include "SpringBody.h"
#include "PressureBody.h"
using namespace JellyPhysics;

#define pi 3.14159265

double degreeToRadian(double degree)
{
	double radian = 0;
	radian = degree * (pi/180);
	return radian;
}

int main(int argc, const char * argv[])
{

    World mWorld;
    
    // static ground object.
    ClosedShape groundShape;
    groundShape.begin();
    groundShape.addVertex(Vector2(-20.0f, -12.0f));
    groundShape.addVertex(Vector2(-20.0f, 12.0f));
    groundShape.addVertex(Vector2(20.0f, 12.0f));
    groundShape.addVertex(Vector2(20.0f, -12.0f));
    groundShape.finish();
    
    // make the body.
    Body groundBody = Body(&mWorld, groundShape, INFINITY, Vector2(0.0f, -19.0f), 2, Vector2::One, false);
    
    
    ClosedShape shape;
    shape.begin();
    
    for (int i = 0; i < 360; i += 20)
    {
        shape.addVertex(Vector2((float)cos(degreeToRadian((float)-i)), (float)sin(degreeToRadian((float)-i))));
    }
    
    shape.finish();
    
    PressureBody *body = new PressureBody(&mWorld, groundShape, 1.0f, 40.0f, 10.0f, 1.0f, 200.0f, 20.0f,
                                      Vector2(5, 55), 0, Vector2::One, false);
    
    
    for (int i = 0; i <180; i++)
    {        
        
        mWorld.update(1.0f / 30.0f);
        body->debugDraw();
        printf("update\n");
        
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}

