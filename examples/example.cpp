#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <iostream>

#include <whmath/math.hpp>

using namespace math;

int main(int argc, char** argv)
{
	mat::f32<4, 3> m = { { 1.0f, 2.0f, 3.0f, 4.0f }, { 5.0f, 6.0f, 7.0f, 8.0f }, { 9.0f, 10.0f, 11.0f, 12.0f } };

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
	do {
		std::cout << p << std::endl;
		p = p.next();
	} while(p != m[0]);

	std::cout << "pancake: " << std::endl;
	std::cout << p.pancake_sort() << std::endl;
	exit(EXIT_SUCCESS);
}

