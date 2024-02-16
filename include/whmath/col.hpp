#pragma once

template<typename T, size_t N> 
std::ostream& operator<<(std::ostream& stream, const vc3<T, N>& rhs)
{
	if(std::is_floating_point<T>::value)
		stream << "[ " << rhs.c0 << ", " << rhs.c1 << ", " << rhs.c2 << ", " << rhs.c3 << " ]";
	else
		stream << "[ " << (size_t)rhs.c0 << ", " << (size_t)rhs.c1 << ", " << (size_t)rhs.c2 << ", " << (size_t)rhs.c3 << " ]";
	return stream;
}

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


	friend std::ostream& operator<< <>(std::ostream& stream, const vc3<T, N>& rhs);
};

template<typename T, size_t N> 
std::ostream& operator<<(std::ostream& stream, const vc4<T, N>& rhs)
{
	if(std::is_floating_point<T>::value)
		stream << "[ " << rhs.c0 << ", " << rhs.c1 << ", " << rhs.c2 << ", " << rhs.c3 << " ]";
	else
		stream << "[ " << (size_t)rhs.c0 << ", " << (size_t)rhs.c1 << ", " << (size_t)rhs.c2 << ", " << (size_t)rhs.c3 << " ]";
	return stream;
}

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

	friend std::ostream& operator<< <>(std::ostream& stream, const vc4<T, N>& rhs);
};

template<typename T, const sca::u8 c0_bits, const sca::u8 c1_bits, const sca::u8 c2_bits> 
std::ostream& operator<<(std::ostream& stream, const bf3<T, c0_bits, c1_bits, c2_bits>& rhs)
{
	if(std::is_floating_point<T>::value)
		stream << "[ " << rhs.c0 << ", " << rhs.c1 << ", " << rhs.c2 << " ]";
	else
		stream << "[ " << (size_t)rhs.c0 << ", " << (size_t)rhs.c1 << ", " << (size_t)rhs.c2 << " ]";
	return stream;
}

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

	friend std::ostream& operator<< <>(std::ostream& stream, const bf3<T, c0_bits, c1_bits, c2_bits>& rhs);
};

template<typename T, const sca::u8 c0_bits, const sca::u8 c1_bits, const sca::u8 c2_bits, const sca::u8 c3_bits> 
std::ostream& operator<<(std::ostream& stream, const bf4<T, c0_bits, c1_bits, c2_bits, c3_bits>& rhs)
{
	if(std::is_floating_point<T>::value)
		stream << "[ " << rhs.c0 << ", " << rhs.c1 << ", " << rhs.c2 << ", " << rhs.c3 << " ]";
	else
		stream << "[ " << (size_t)rhs.c0 << ", " << (size_t)rhs.c1 << ", " << (size_t)rhs.c2 << ", " << (size_t)rhs.c3 << " ]";
	return stream;
}
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

	friend std::ostream& operator<< <>(std::ostream& stream, const bf4<T, c0_bits, c1_bits, c2_bits, c3_bits>& rhs);

};

