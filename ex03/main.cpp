#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	// Define triangle vertices
	Point a(0.f, 0.f);
	Point b(10.f, 0.f);
	Point c(5.f, 10.f);

	// Test cases
	Point p1(5.f, 5.f);      // Inside the triangle
	Point p2(0.f, 0.f);      // On vertex A
	Point p3(5.f, 0.f);      // On edge AB
	Point p4(15.f, 15.f);    // Outside the triangle
	Point p5(5.f, 3.f);      // Inside the triangle
	Point p6(7.5f, 5.f);	 // On edge BC
	Point p7(2.5f, 5.f);    // On edge AC

	std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl;
	std::cout << std::endl;

	std::cout << "Test 1 - Point(5, 5) inside: " << (bsp(a, b, c, p1) ? "Inside" : "Not Inside") << std::endl;
	std::cout << "Test 2 - Point(0, 0) on vertex: " << (bsp(a, b, c, p2) ? "Inside" : "Not Inside") << std::endl;
	std::cout << "Test 3 - Point(5, 0) on edge: " << (bsp(a, b, c, p3) ? "Inside" : "Not Inside") << std::endl;
	std::cout << "Test 4 - Point(15, 15) outside: " << (bsp(a, b, c, p4) ? "Inside" : "Not Inside") << std::endl;
	std::cout << "Test 5 - Point(5, 3) inside: " << (bsp(a, b, c, p5) ? "Inside" : "Not Inside") << std::endl;
	std::cout << "Test 6 - Point(7.5, 5) on edge: " << (bsp(a, b, c, p6) ? "Inside" : "Not Inside") << std::endl;
	std::cout << "Test 7 - Point(2.5, 5) on edge: " << (bsp(a, b, c, p7) ? "Inside" : "Not Inside") << std::endl;

	return 0;
}