#include <iostream>
#include <vector>
#include <cmath>

struct geometricObjects
{
public:
	struct cicle
	{
		long double radius;
	} cicle;
	struct ellipse
	{
		long double a, b;
	} ellipse;
	struct sphere
	{
		long double radius;
	} sphere;

	long double areaCicle() {
		return 3.14 * pow(cicle.radius, 2);
	}
	long double areaEllipse() {
		return 3.14 * ellipse.a * ellipse.b;
	}
	long double areaSphere() {
		return 4 * 3.14 * pow(sphere.radius, 2);
	}
	geometricObjects(long double radiusCicle, long double a, long double b, long double radiusSphere) {
		cicle.radius = radiusCicle;
		ellipse.a = a;
		ellipse.b = b;
		sphere.radius = radiusSphere;
	}
};
long double randDoubleNumber() {
	return (double)rand() / (double)RAND_MAX + rand() % RAND_MAX;
}
void initVec(std::vector <geometricObjects>& vector_storing_objects, int numberObjects) {
	for (int i = 0; i < numberObjects; i++)
	{
		geometricObjects temp(randDoubleNumber(), randDoubleNumber(), randDoubleNumber(), randDoubleNumber());
		vector_storing_objects.push_back(temp);
	}
}
long double areaObj(std::vector <geometricObjects> vector_storing_objects, int numberObjects) {
	long double temp_areaObj = 0;
	for (int i = 0; i < numberObjects; i++)
	{
		geometricObjects temp_obj = vector_storing_objects[i];
		temp_areaObj = temp_obj.areaCicle() + temp_obj.areaEllipse() + temp_obj.areaSphere();
	}
	return temp_areaObj;
}
int main() {
	std::vector <geometricObjects> vector_storing_objects;
	int numberObjects = rand() % 1000;
	initVec(vector_storing_objects, numberObjects);

	std::cout << "number of geometric objects: " << numberObjects << std::endl;
	std::cout << "sum of areas: " << areaObj(vector_storing_objects, numberObjects);
	return 0;
}
