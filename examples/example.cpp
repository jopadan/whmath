#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <format>
#include <whmath/math.hpp>

using namespace math;
using namespace math::col;
int main(int argc, char** argv)
{
	/* output matrix element manipulation */
	mat::f32<4, 3> m = { { 1.0f, 2.0f, 3.0f, 4.0f }, { 5.0f, 6.0f, 7.0f, 8.0f }, { 9.0f, 10.0f, 11.0f, 12.0f } };

	std::cout << "input:" << std::endl;
	std::cout << m << std::endl;

	std::cout << "rotate columns:" << std::endl;
	std::cout << m.rot_cols(1, -2, -5, 4) << std::endl;

	std::cout << "rotate row:" << std::endl;
	std::cout << m.rot_rows(-1, 2, 5) << std::endl;

	std::cout << "transpose: " << std::endl;
	std::cout << m.transpose() << std::endl;

	/* output permutations with different sort */
	std::cout << "permutations: input[0]" << std::endl;
	com::permutation<sca::f32, 4> p = m[0];

	size_t swap_count = 0;
	do {
		std::cout << p.parity() << ": " << p << " -> ";
		std::cout << " bubble sort " << p.bubble_sort(&swap_count);
		std::cout << std::format(" {:>8} ", swap_count);
		std::cout << std::endl;
		p = p.next();
	} while(p != m[0]);

	std::cout << std::endl;

	swap_count = 0;
	do {
		std::cout << p.parity() << ": " << p << " -> ";
		std::cout << "pancake sort " << p.pancake_sort(&swap_count);
		std::cout << std::format(" {:>8} ", swap_count);
		std::cout << std::endl;
		p = p.next();
	} while(p != m[0]);

	/* output 3-dimensional vector product */
	std::cout << std::endl;
	std::cout << "vector_product: " << std::endl;

	mat::f32<2, 2> m2 = mat::f32<2,2>::identity();
	m2[1] = prd::cross<sca::f32, 2>(m2[0], GL_CCW);
	std::cout << "GL_CCW: " << m2[1] << std::endl;
	m2[1] = prd::cross<sca::f32, 2>(m2[0], GL_CW);
	std::cout << "GL_CW : "  << m2[1] << std::endl;

	mat::f32<3, 3> m3 = mat::f32<3,3>::identity();
	m3[2] = prd::cross<sca::f32, 3>(m3[0], m3[1]);
	std::cout << m3[0] << " x " << m3[1] << " = " << m3[2] << std::endl;

	mat::f32<4, 4> m4 = mat::f32<4,4>::identity();
	m4[3] = prd::cross<sca::f32, 4>(m4[0], m4[1], m4[2]);
	std::cout << m4[0] << " x " << m4[1] << " x " << m4[2] << " = " << m4[3] << std::endl;

	/* output bitfield/vector color types and size */
	std::cout << std::endl;
	std::cout << "color types: " << std::endl;
	std::cout << "RGBAF32: ";

	col::f32<4> g = { 144, 234, 241, 100 };
	std::cout << g << ": " << sizeof(g) * 8 << std::endl;
	std::cout << "RGBA8888: ";

	col::u8<4> h = { 144, 234, 241, 100 };
	std::cout << h << ": " << sizeof(h) * 8 << std::endl;
	std::cout << "RGBA4444: ";

	col::u16<4,4,4,4> c = { 14, 12, 15, 11 };
	std::cout << c << ": " << sizeof(c) * 8 << std::endl;
	std::cout << "RGB565: ";

	col::u16<5,6,5> d = { 24, 34, 25 };
	std::cout << d << ": " << sizeof(d) * 8 << std::endl;

	exit(EXIT_SUCCESS);
}

