#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <iostream>

#include <whmath/math.hpp>

using namespace math;

int main(int argc, char** argv)
{
	mat::f32<4, 3> m = { { 1.0f, 2.0f, 3.0f, 4.0f }, { 5.0f, 6.0f, 7.0f, 8.0f }, { 9.0f, 10.0f, 11.0f, 12.0f } };
	mat::f32<3, 3> m3 = { { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } };
	//m[0].hodge_dual(m[1], m[2]);

	std::cout << "input:" << std::endl;
	std::cout << m << std::endl;
	std::cout << "rotate columns:" << std::endl;
	std::cout << m.rot_cols(1, -2, -5, 4) << std::endl;
	std::cout << "rotate row:" << std::endl;
	std::cout << m.rot_rows(-1, 2, 5) << std::endl;
	std::cout << "transpose: " << std::endl;
	std::cout << m.transpose() << std::endl;
	std::cout << "permutations: input[0]" << std::endl;
	com::permutation<sca::f32, 4> p = m[0];
	size_t swap_count = 0;
	do {
		std::cout << p.parity() << ": " << p.bubble_sort(&swap_count) << " " << swap_count <<  " -> " << p.pancake_sort(&swap_count) << " " << swap_count << std::endl;
		p = p.next();
	} while(p != m[0]);
	std::cout << m3[0].vector_product_3d(m3[1]) << std::endl;
	exit(EXIT_SUCCESS);
}

