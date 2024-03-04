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
#include <numeric>

using namespace std::experimental::parallelism_v2;

namespace math
{

namespace sca
{
	#include <whmath/sca.hpp>

	using f32    = GLfloat;
	using f64    = GLdouble;
	using c8     = GLchar;
	using s8     = GLbyte;
	using u8     = GLubyte;
	using s16    = GLshort;
	using u16    = GLushort;
	using s32    = GLint;
	using u32    = GLuint;
	using s64    = GLint64;
	using u64    = GLuint64;
	using ssz    = khronos_ssize_t;
	using usz    = khronos_usize_t;
	using sptr   = khronos_intptr_t;
	using uptr   = khronos_uintptr_t;
	using stime  = khronos_stime_nanoseconds_t;
	using utime  = khronos_utime_nanoseconds_t;
	using idx    = GLuint;
	using enm    = GLenum;
};

namespace vec
{
	template<typename T, size_t N>
	using wide = std::conditional_t<(N > 1), std::array<T,N>, T>;

	template<typename T, size_t N>
	struct [[nodiscard]] vec;

	template<typename T, size_t N>
	using type = std::conditional_t<(N > 1), vec<T,N>, T>;

	template<size_t N>
	using f32 = type<sca::f32, N>;
	template<size_t N>
	using f64 = type<sca::f64, N>;

	template<size_t N>
	using  s8 = type<sca:: s8, N>;
	template<size_t N>
	using s16 = type<sca::s16, N>;
	template<size_t N>
	using s32 = type<sca::s32, N>;
	template<size_t N>
	using s64 = type<sca::s64, N>;

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

namespace com
{
	template<typename T, size_t N>
	struct permutation;

	template<typename T, size_t N>
	using type = std::conditional_t<(N > 1), permutation<T, N>, T>;

	template<size_t N>
	using f32 = type<sca::f32, N>;
	template<size_t N>
	using f64 = type<sca::f64, N>;

	template<size_t N>
	using  s8 = type<sca:: s8, N>;
	template<size_t N>
	using s16 = type<sca::s16, N>;
	template<size_t N>
	using s32 = type<sca::s32, N>;
	template<size_t N>
	using s64 = type<sca::s64, N>;

	template<size_t N>
	using  u8 = type<sca:: u8, N>;
	template<size_t N>
	using u16 = type<sca::u16, N>;
	template<size_t N>
	using u32 = type<sca::u32, N>;
	template<size_t N>
	using u64 = type<sca::u64, N>;

	#include <whmath/per.hpp>
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
	using  s8 = type<sca:: s8, N, ROWS>;
	template<size_t N, size_t ROWS>
	using s16 = type<sca::s16, N, ROWS>;
	template<size_t N, size_t ROWS>
	using s32 = type<sca::s32, N, ROWS>;
	template<size_t N, size_t ROWS>
	using s64 = type<sca::s64, N, ROWS>;

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
	struct qut : wide<T>
	{
	};

	template<typename T>
	using type = qut<T>;

	using f32 = type<sca::f32>;
	using f64 = type<sca::f64>;

	using  s8 = type<sca:: s8>;
	using s16 = type<sca::s16>;
	using s32 = type<sca::s32>;
	using s64 = type<sca::s64>;

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

	using  s8 = type<sca:: s8>;
	using s16 = type<sca::s16>;
	using s32 = type<sca::s32>;
	using s64 = type<sca::s64>;

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

	using  s8 = type<sca:: s8>;
	using s16 = type<sca::s16>;
	using s32 = type<sca::s32>;
	using s64 = type<sca::s64>;

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
	using  s8 = ten<sca:: s8, N, ROWS>;
	template<size_t N, size_t ROWS>
	using s16 = ten<sca::s16, N, ROWS>;
	template<size_t N, size_t ROWS>
	using s32 = ten<sca::s32, N, ROWS>;
	template<size_t N, size_t ROWS>
	using s64 = ten<sca::s64, N, ROWS>;

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

	using  s8 = sed<sca:: s8>;
	using s16 = sed<sca::s16>;
	using s32 = sed<sca::s32>;
	using s64 = sed<sca::s64>;

	using  u8 = sed<sca:: u8>;
	using u16 = sed<sca::u16>;
	using u32 = sed<sca::u32>;
	using u64 = sed<sca::u64>;

	#include <whmath/sed.hpp>
};

namespace col
{
	template<typename T, size_t N>
	struct vc3;

	template<typename T, size_t N>
	struct vc4;

	template<typename T, const sca::u8 c0_bits, const sca::u8 c1_bits, const sca::u8 c2_bits>
	struct bf3;

	template<typename T, const sca::u8 c0_bits, const sca::u8 c1_bits, const sca::u8 c2_bits, const sca::u8 c3_bits>
	struct bf4;

	template<size_t N>
	using u8 = std::conditional<N == 3, vc3<sca::u8, N>, vc4<sca::u8, N>>::type;

	template<const sca::u8 c0_bits, const sca::u8 c1_bits, const sca::u8 c2_bits, const sca::u8 c3_bits = 0>
	using u16 = std::conditional<c3_bits == 0, bf3<sca::u16, c0_bits, c1_bits, c2_bits>, bf4<sca::u16, c0_bits, c1_bits, c2_bits, c3_bits>>::type;

	template<const sca::u8 c0_bits, const sca::u8 c1_bits,  const sca::u8 c2_bits, const sca::u8 c3_bits>
	using u32 = std::conditional<c3_bits == 0, bf3<sca::u32, c0_bits, c1_bits, c2_bits>, bf4<sca::u32, c0_bits, c1_bits, c2_bits, c3_bits>>::type;

	template<size_t N>
	using f32 = std::conditional<N == 3, vc3<sca::f32, N>, vc4<sca::f32, N>>::type;

	template<size_t N>
	using f64 = std::conditional<N == 3, vc3<sca::f32, N>, vc4<sca::f32, N>>::type;

	#include <whmath/col.hpp>
};

namespace prd
{
	template<typename T, size_t N,
	typename = std::enable_if<N == 2, bool>::type>
	vec::type<T, N> cross(vec::type<T, N> src, sca::enm mode = GL_CCW)
	{
		return { mode == GL_CW ? vec::type<T,N>{ src[1], -src[0] } : vec::type<T, N>{ -src[1], src[0] } };
	}

	template<typename T, size_t N,
	typename = std::enable_if<N == 3, bool>::type>
	vec::type<T, N> cross(vec::type<T,N> a, vec::type<T,N> b)
	{
		return (a * b.rotl(1) - b * a.rotl(1)).rotl(1);
	}

	template<typename T, size_t N,
	typename = std::enable_if<N == 4, bool>::type>
	vec::type<T, N> cross(vec::type<T,N> a, vec::type<T,N> b, vec::type<T, N> c)
	{
		return {
				-mat::type<T,3,3>(a.yzw(), b.yzw(), c.yzw()).det3(),
				 mat::type<T,3,3>(a.xzw(), b.xzw(), c.xzw()).det3(),
				-mat::type<T,3,3>(a.xyw(), b.xyw(), c.xyw()).det3(),
				 mat::type<T,3,3>(a.xyz(), b.xyz(), c.xyz()).det3()
		};
	}

/*c
	template<typename T, size_t N,
	typename = std::enable_if<N >= 5, bool>::type>
	vec::type<T, N> hodge(std::array<vec::type<T,N>, N - 1> src)
	{
	}

	template<typename T, size_t N,
	typename = 
	vec::type<T, N> wedge(vec::type<T,N> a, vec::type<T,N> b)
	{
	}

	template<typename T, size_t N,
	vec::type<T, N> paffian(vec::type<T,N> a, vec::type<T,N> b)
	{
	}

	geo
	inn
	ext
	out
*/
};

};
