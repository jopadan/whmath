#pragma once

namespace tri
{
	template<sca::enm mode = GL_CCW>
	struct idx : vec::idx<3>
	{
		inline constexpr idx<N, GL_CCW> ccw() { return mode == GL_CCW ? (*this) : (*this).permute(2, 1, 0); }
		inline constexpr idx<N, GL_CW>   cw() { return mode == GL_CW  ? (*this) : (*this).permute(2, 1, 0); }
	};

	template<size_t N, sca::enm mode = GL_CCW>
	struct f32 : mat::f32<N, 3>
	{
		inline constexpr f32<N, GL_CCW> ccw() { return mode == GL_CCW ? (*this) : (*this).permute_rows(2, 1, 0); }
		inline constexpr f32<N, GL_CW>   cw() { return mode == GL_CW  ? (*this) : (*this).permute_rows(2, 1, 0); }
	};

};
