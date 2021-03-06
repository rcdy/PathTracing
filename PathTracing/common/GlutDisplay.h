#ifndef __GLUT_DISPLAY_H__
#define __GLUT_DISPLAY_H__
#include "glut/glut.h"
#include "../raytracer/RayTracer.h"

class GlutDisplay
{
public:
	static void setRayTracer(RayTracer* rayTracer);
	static void loop(); 
	static void update();
private:
	static void render();
	static void reshape(int w, int h);

	static void motionCallBack(int x, int y );
	static void mouseCallBack(int button, int state, int x, int y);

	static RayTracer* rayTracer;
	static Camera* camera;
	static bool bMouseDown;
	static int mouseX;
	static int mouseY;
};

#endif

