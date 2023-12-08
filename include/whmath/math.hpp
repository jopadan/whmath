#pragma once

#include <cstdlib>
#include <cstdio>
#include <experimental/simd>
#include <complex>
#include <array>
#include <utility>
#include <ranges>
#include <algorithm>
#include <ostream>
#include <type_traits>

using namespace std::experimental::parallelism_v2;

namespace math
{
	namespace sca
	{
		#include <whmath/sca.hpp>

	        using f32    = GLfloat;
		using f64    = GLdouble;
		using c8     = GLchar;
		using i8     = GLbyte;
		using u8     = GLubyte;
		using i16    = GLshort;
		using u16    = GLushort;
		using i32    = GLint;
		using u32    = GLuint;
		using i64    = GLint64;
		using u64    = GLuint64;
		using ssz    = khronos_ssize_t;
		using usz    = khronos_usize_t;
		using iptr   = khronos_intptr_t;
		using uptr   = khronos_uintptr_t;
		using stime  = khronos_stime_nanoseconds_t;
		using utime  = khronos_utime_nanoseconds_t;
		using idx    = GLuint;
	};

	namespace vec
	{
		template<typename T, size_t N>
		using wide = std::conditional_t<(N > 1), std::array<T,N>, T>;

		template<typename T, size_t N>
		struct vec;

		template<typename T, size_t N>
		using type = std::conditional_t<(N > 1), vec<T,N>, T>;

		template<size_t N>
		using f32 = type<sca::f32, N>;
		template<size_t N>
		using f64 = type<sca::f64, N>;

		template<size_t N>
		using  i8 = type<sca:: i8, N>;
		template<size_t N>
		using i16 = type<sca::i16, N>;
		template<size_t N>
		using i32 = type<sca::i32, N>;
		template<size_t N>
		using i64 = type<sca::i64, N>;

		template<size_t N>
		using  u8 = type<sca:: u8, N>;
		template<size_t N>
		using u16 = type<sca::u16, N>;
		template<size_t N>
		using u32 = type<sca::u32, N>;
		template<size_t N>
		using u64 = type<sca::u64, N>;

		#include <whmath/vec.hpp>
	};

	namespace mat
	{
		template<typename T, size_t N, size_t ROWS = N>
		using wide = std::array<vec::type<T, N>, ROWS>;

		template<typename T, size_t COLS, size_t ROWS>
		struct mat;

		template<typename T, size_t N, size_t ROWS = N>
		using type = mat<T, N, ROWS>;

		template<size_t N, size_t ROWS>
		using f32 = type<sca::f32, N, ROWS>;
		template<size_t N, size_t ROWS>
		using f64 = type<sca::f64, N, ROWS>;

		template<size_t N, size_t ROWS>
		using  i8 = type<sca:: i8, N, ROWS>;
		template<size_t N, size_t ROWS>
		using i16 = type<sca::i16, N, ROWS>;
		template<size_t N, size_t ROWS>
		using i32 = type<sca::i32, N, ROWS>;
		template<size_t N, size_t ROWS>
		using i64 = type<sca::i64, N, ROWS>;

		template<size_t N, size_t ROWS>
		using  u8 = type<sca:: u8, N, ROWS>;
		template<size_t N, size_t ROWS>
		using u16 = type<sca::u16, N, ROWS>;
		template<size_t N, size_t ROWS>
		using u32 = type<sca::u32, N, ROWS>;
		template<size_t N, size_t ROWS>
		using u64 = type<sca::u64, N, ROWS>;

		#include <whmath/mat.hpp>
	};

	namespace qut
	{
		template<typename T>
		using wide = std::array<T, 4>;

		template<typename T>
		struct qut;

		template<typename T>
		using type = qut<T>;

		using f32 = type<sca::f32>;
		using f64 = type<sca::f64>;

		using  i8 = type<sca:: i8>;
		using i16 = type<sca::i16>;
		using i32 = type<sca::i32>;
		using i64 = type<sca::i64>;

		using  u8 = type<sca:: u8>;
		using u16 = type<sca::u16>;
		using u32 = type<sca::u32>;
		using u64 = type<sca::u64>;

		#include <whmath/qut.hpp>
	};

	namespace uqv
	{
		template<typename T>
		using wide = std::array<T, 4>;

		template<typename T>
		struct uqv;

		template<typename T>
		using type = uqv<T>;

		using f32 = type<sca::f32>;
		using f64 = type<sca::f64>;

		using  i8 = type<sca:: i8>;
		using i16 = type<sca::i16>;
		using i32 = type<sca::i32>;
		using i64 = type<sca::i64>;

		using  u8 = type<sca:: u8>;
		using u16 = type<sca::u16>;
		using u32 = type<sca::u32>;
		using u64 = type<sca::u64>;

		#include <whmath/uqv.hpp>
	};

	namespace oct
	{
		template<typename T>
		using wide = std::array<T, 8>;

		template<typename T>
		struct oct;

		template<typename T>
		using type = oct<T>;

		using f32 = type<sca::f32>;
		using f64 = type<sca::f64>;

		using  i8 = type<sca:: i8>;
		using i16 = type<sca::i16>;
		using i32 = type<sca::i32>;
		using i64 = type<sca::i64>;

		using  u8 = type<sca:: u8>;
		using u16 = type<sca::u16>;
		using u32 = type<sca::u32>;
		using u64 = type<sca::u64>;

		#include <whmath/oct.hpp>
	};

	namespace ten
	{
		template<typename T, size_t N, size_t ROWS = N>
		using wide = std::array<vec::wide<T, N>, ROWS>;

		template<typename T, size_t N, size_t ROWS = N>
		struct ten;

		template<typename T, size_t N, size_t ROWS = N>
		using type = ten<T, N, ROWS>;

		template<size_t N, size_t ROWS>
		using f32 = ten<sca::f32, N, ROWS>;
		template<size_t N, size_t ROWS>
		using f64 = ten<sca::f64, N, ROWS>;

		template<size_t N, size_t ROWS>
		using  i8 = ten<sca:: i8, N, ROWS>;
		template<size_t N, size_t ROWS>
		using i16 = ten<sca::i16, N, ROWS>;
		template<size_t N, size_t ROWS>
		using i32 = ten<sca::i32, N, ROWS>;
		template<size_t N, size_t ROWS>
		using i64 = ten<sca::i64, N, ROWS>;

		template<size_t N, size_t ROWS>
		using  u8 = ten<sca:: u8, N, ROWS>;
		template<size_t N, size_t ROWS>
		using u16 = ten<sca::u16, N, ROWS>;
		template<size_t N, size_t ROWS>
		using u32 = ten<sca::u32, N, ROWS>;
		template<size_t N, size_t ROWS>
		using u64 = ten<sca::u64, N, ROWS>;

		#include <whmath/ten.hpp>
	};

	namespace sed
	{
		template<typename T>
		using wide = std::array<T, 16>;

		template<typename T>
		struct sed;

		template<typename T>
		using type = sed<T>;

		using f32 = sed<sca::f32>;
		using f64 = sed<sca::f64>;

		using  i8 = sed<sca:: i8>;
		using i16 = sed<sca::i16>;
		using i32 = sed<sca::i32>;
		using i64 = sed<sca::i64>;

		using  u8 = sed<sca:: u8>;
		using u16 = sed<sca::u16>;
		using u32 = sed<sca::u32>;
		using u64 = sed<sca::u64>;

		#include <whmath/sed.hpp>
	};

	namespace col
	{
		template<typename T, size_t N>
		using wide = std::array<T, N>;

		template<typename T, size_t N, size_t C, const vec::u8<C> bits, const vec::u8<C> channels>
		struct col;

		template<typename T, size_t N, size_t C, const vec::u8<C> bits, const vec::u8<C> channels>
		using type = col<T, N, C, bits, channels>;

		using RGB888     = type<sca:: u8, 3, 3, {  8,  8,  8 }, { 0, 1, 2 }>;
		using RGBF32C3   = type<sca::f32, 3, 3, { 32, 32, 32 }, { 0, 1, 2 }>;
		using RGB565     = type<sca::u16, 1, 3, {  5,  6,  5 }, { 0, 1, 2 }>;
		using RGBA4444   = type<sca::u16, 1, 4, {  4,  4,  4,  4 }, { 0, 1, 2, 3 }>;
		using RGBA8888   = type<sca:: u8, 4, 4, {  8,  8,  8,  8 }, { 0, 1, 2, 3 }>;
		using ARGB8888   = type<sca:: u8, 4, 4, {  8,  8,  8,  8 }, { 3, 0, 1, 2 }>;
		using BGRA8888   = type<sca:: u8, 4, 4, {  8,  8,  8,  8 }, { 2, 1, 0, 3 }>;
		using RGBAF32C4  = type<sca::f32, 4, 4, { 32, 32, 32, 32 }, { 0, 1, 2, 3 }>;

		#include <whmath/col.hpp>
	};

};

