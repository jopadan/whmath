#pragma once

template<typename T, size_t N>
struct vc3
{
	T c0;
	T c1;
	T c2;
	T& operator[](size_t i)
	{
		switch(i % N)
		{
			case 0: return c0;
			case 1: return c1;
			case 2: return c2;
		}
	}
	void print_u8()
	{
		printf("[%hhu %hhu %hhu]: %zu\n", c0, c1, c2, sizeof(*this) * 8);
	}
	void print_f32()
	{
		printf("[%f %f %f]: %zu\n", c0, c1, c2, sizeof(*this) * 8);
	}
};

template<typename T, size_t N>
struct vc4
{
	T c0;
	T c1;
	T c2;
	T c3;
	T& operator[](size_t i)
	{
		switch(i % N)
		{
			case 0: return c0;
			case 1: return c1;
			case 2: return c2;
			case 3: return c3;
		}
	}
	void print_u8()
	{
		printf("[%hhu %hhu %hhu %hhu]: %zu\n", c0, c1, c2, c3, sizeof(*this) * 8);
	}
	void print_f32()
	{
		printf("[%f %f %f %f]: %zu\n", c0, c1, c2, c3, sizeof(*this) * 8);
	}
};

template<typename T, const sca::u8 c0_bits, const sca::u8 c1_bits, const sca::u8 c2_bits>
struct bf3
{
	T c0 : c0_bits;
	T c1 : c1_bits;
	T c2 : c2_bits;

	T operator[](size_t i)
	{
		switch(i)
		{
			case 0: return c0;
			case 1: return c1;
			case 2: return c2;
		}
	}
	operator u8<4>()
	{
		return u8<4>(
				((c0 * 255 + (1 << (c0_bits - 1)) - 1) / (1 << c0_bits) - 1),
				((c1 * 255 + (1 << (c1_bits - 1)) - 1) / (1 << c1_bits) - 1),
				((c2 * 255 + (1 << (c2_bits - 1)) - 1) / (1 << c2_bits) - 1),
				0);
	}
	void print_u8()
	{
		printf("[%hhu %hhu %hhu]: %zu\n", c0, c1, c2, sizeof(*this) * 8);
	}
};

template<typename T, const sca::u8 c0_bits, const sca::u8 c1_bits, const sca::u8 c2_bits, const sca::u8 c3_bits>
struct bf4
{
	T c0 : c0_bits;
	T c1 : c1_bits;
	T c2 : c2_bits;
	T c3 : c3_bits;

	T operator[](size_t i)
	{
		switch(i)
		{
			case 0: return c0;
			case 1: return c1;
			case 2: return c2;
			case 3: return c3;
		}
	}
	operator u8<4>()
	{
		return u8<4>(
				((c0 * 255 + (1 << (c0_bits - 1)) - 1) / (1 << c0_bits) - 1),
				((c1 * 255 + (1 << (c1_bits - 1)) - 1) / (1 << c1_bits) - 1),
				((c2 * 255 + (1 << (c2_bits - 1)) - 1) / (1 << c2_bits) - 1),
				((c3 * 255 + (1 << (c3_bits - 1)) - 1) / (1 << c3_bits) - 1));
	}
	void print_u8()
	{
		printf("[%hhu %hhu %hhu %hhu]: %zu\n", c0, c1, c2, c3, sizeof(*this) * 8);
	}
};

