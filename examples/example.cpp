#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <iostream>

#include <whmath/math.hpp>

using namespace math;

int main(int argc, char** argv)
{
	mat::f32<4, 3> m = { { 1.0f, 2.0f, 3.0f, 4.0f }, { 5.0f, 6.0f, 7.0f, 8.0f }, { 9.0f, 10.0f, 11.0f, 12.0f } };
	qut::f32       q = { 1.0f, 2.0f, 3.0f, 4.0f };
	uqv::f32       v = { 1.0f, 2.0f, 3.0f, 4.0f };
	col::RGB565 c = { 13 << 0 | 23 << 5 | 12 << 6 };
	std::cout << m << std::endl;
	std::cout << m.transpose() << std::endl;
	std::cout << m.rot_cols(1, -2, -5, 4) << std::endl;
	std::cout << m.rot_rows(-1, 2, 5) << std::endl;
/*
	vec::f32<4> u = vec::f32<4>::identity(0);
	vec::f32<4> v = vec::f32<4>::identity(1);
	vec::f32<4> w = vec::f32<4>::identity(2);
	u.vector_product(v,w).print();
	puts("\n");

	mat::f32<3,3> m = mat::f32<3,3>::identity();
	m.print();
	puts("\n");
	m.rot_rows(-1, -2, -3).print();
	puts("\n");
	m.rot_cols(-1,-1,-4).print();
*/
	exit(EXIT_SUCCESS);
}

