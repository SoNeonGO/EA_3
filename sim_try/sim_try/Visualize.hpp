#pragma once
#define GL_SILENCE_DEPRECATION
#define GLFW_INCLUDE_NONE
//#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/freeglut.h>
#endif
#include "ground.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "SimulatorBase.hpp"
#include <stdio.h>

extern GLfloat color[8][3];



// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class Visualizer{
    public:
    static void init(int argc, char **argv);
    
    //注册函数
    static void specialKeys(int key, int x, int y);
    static void mouseButton(int buttom, int state, int x, int y);
    static void display();
    static void timerFunction(int value);
    static void idleFunction();
    static void processNormalKeys(unsigned char key, int xx, int yy);
    static void releaseKey(int key, int x, int y);
    //工具函数
    static void mouseMove(int x, int y);

    //绘制函数
    // static void colorcube();
    // static void quad(int a, int b, int c, int d);
    static void drawRobot();
    static void drawBoxRobot(int i );
    static void drawQuadfromPVA(int i, int a, int b, int c, int d);

    //成员变量
    static Simulator* sim;
    static CubeSimulator* cubesim;

    static GLfloat point_sizes[2];
    static GLfloat point_step;
    static GLfloat cur_point_size;
    static GLfloat line_widths[2];
    static GLfloat cur_line_width;
    //  鼠标
    static float deltaAngle;
    static float deltaMove;
    static int xOrigin;
    // 相机相关
    static float angle;
    static float pos_x;
    static float pos_z;
    static double rotate_z;
    static double rotate_x;
};



