#pragma once

template<typename T, size_t N, size_t C, const vec::u8<C> bits, const vec::u8<C> channels>
struct col : wide<T, N>
{

};

/*
template<typename T, size_t N>
struct fmt
{
	vec::u8<N> bits;
	vec::u8<N> channels;
	vec::u8<N> shift;
	mat::mxn<typename t::value_type, sizeof(t) / sizeof(typename t::value_type), n> mask;
	fmt() = default;
	fmt(vec::u8<n> _bits, vec::u8<n> _channels) { };
	~fmt() {}
};
template<size_t _size, typename _type, size_t _type_size>
struct fmt
{
vec::u8<_size> bits;
vec::u8<_size> colors;
vec::u8<_size> shift;
mat::mxn<_type, _type_size, _size> mask;
fmt() = default;
fmt(vec::u8<_size> _bits, vec::u8<_size> _colors) : bits(_bits), colors(_colors)
{
mask = { 0 };
sca::u8 count;
for(sca::u8 i; i < _size; i++, count += bits[i - 1])
{
shift[i] = count;
if(_type_size > 1)
mask[i][i] = ((std::make_unsigned_t<__int_for_sizeof_t<_type>>)UINTMAX_MAX);
else
mask[i][0] = (_type)(((1 << bits[i]) - 1) << count);
}
}
};

*/
