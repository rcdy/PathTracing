#include "Parser.h"

void Parser::parse(const char* fileName,Scene* scene)
{
	Camera* camera = new Camera;
	camera->setAspect(scene->getWidth()/scene->getHeight());
	scene->camera = camera;

	IPrimitive* sphere = new Sphere(Point3(2,0,-5),1);
	MaterialAttribute attr;
	attr.color = Color3(1,0,0);
	attr.ka = Vec3(0.19,0.07,0.02);
	attr.kd = Vec3(0.70,0.27,0.08);
	attr.ks = Vec3(0.26,0.18,0.06);
	attr.roughness = 12.8;
	sphere->attr = attr;
	scene->primitives.push_back(sphere);

	IPrimitive* cube = new Cube();
	cube->rotate(-30,Vec3(0,1,0));
	cube->rotate(-20,Vec3(1,0,0));
	cube->translate(-1,0,-3);
	MaterialAttribute attr2;
	attr2.color = Color3(0,0,1);
	attr2.ka = Vec3(0.19,0.19,0.19);
	attr2.kd = Vec3(0.51,0.51,0.51);
	attr2.ks = Vec3(0.51,0.51,0.51);
	attr2.roughness = 51.2;
	cube->attr = attr2;
	scene->primitives.push_back(cube);

	Plane* plane = new Plane(Point3(-100,-5,0),Vec3(1000,0,0),Vec3(0,0,-1000));
	Plane* plane2 = new Plane(Point3(-5,-5,0),Vec3(0,0,-1000),Vec3(0,1000,0));
	Plane* plane3 = new Plane(Point3(-100,-5,-10),Vec3(1000,0,0),Vec3(0,1000,0));

	MaterialAttribute attr3;
	attr3.color = Color3(1,1,1);
	attr3.ka = Vec3(0, 0, 0);
	attr3.kd = Vec3(0.5, 0.5, 0.5);
	attr3.ks = Vec3(0,0,0);
	attr3.roughness = 89.6;
	plane->attr = attr3;
	plane2->attr = attr3;
	plane3->attr = attr3;

	scene->primitives.push_back(plane);
	scene->primitives.push_back(plane2);
	scene->primitives.push_back(plane3);

	PointLight* pointLight = new PointLight(Vec3(0,5,0),Vec3::WHITE,10);
	scene->primitives.push_back(pointLight);

}