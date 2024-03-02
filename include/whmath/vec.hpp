#pragma once

template<typename T, size_t N> 
std::ostream& operator<<(std::ostream& stream, const vec<T, N>& rhs)
{
	using PrintT = std::conditional_t<std::is_same_v<T, uint8_t>, int, T>;
	stream << "[ " << static_cast<PrintT>(rhs[0]);

	for (std::size_t i = 1; i < N; ++i)
		stream << ", " << static_cast<PrintT>(rhs[i]);

	stream << " ]";

	return stream;
}

template<typename T, size_t N>
struct vec : wide<T, N>
{
	enum { x, y, z, w };
	enum { r, g, b, a };
	enum { u, v };
	enum { s, t };
	constexpr explicit vec(const vec<T, N + 1>& rhs) noexcept { for(int i = 0; i < (*this).size(); i++) (*this)[i] = rhs[i]; }
	constexpr explicit vec(const vec<T, N - 1>& rhs, T val) noexcept { for(int i = 0; i < rhs.size(); i++) (*this)[i] = rhs[i]; (*this)[rhs.size()] = val; }
	constexpr vec() noexcept = default;
	constexpr vec(const T val) noexcept : wide<T, N>{ val } {}
	constexpr vec(std::initializer_list<T> l) noexcept { std::copy(l.begin(), l.end(), (*this).begin()); }
	constexpr vec(const vec& v) noexcept : wide<T, N>(v) { }

	template<typename... A,
		typename = std::enable_if_t<(sizeof...(A) <= N) && (sizeof...(A) > 1)>,
		typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, T> && ...)>>
	constexpr explicit vec(A&&... args) noexcept : wide<T, N>{ static_cast<T>(args)... } {}

	template<typename OT = T>
	operator vec<OT, N>() const
	{
		vec<OT, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i];
		return dst;
	}
	friend std::ostream& operator<< <>(std::ostream& stream, const vec<T, N>& rhs);

	vec<T, N> operator+( T rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] + rhs;
		return dst;
	}
	vec<T, N> operator-( T rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] - rhs;
		return dst;
	}
	vec<T, N> operator*( T rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] * rhs;
		return dst;
	}
	template<typename OT>
	vec<T, N> operator*( OT rhs  )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] * rhs;
		return dst;
	}
	vec<T, N> operator/( T rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] / rhs;
		return dst;
	}
	vec<T, N> operator%( T rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] % rhs;
		return dst;
	}
	template<typename OT = T>
	vec<T, N> operator+( vec<OT, N> rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] + rhs[i];
		return dst;
	}
	vec<T, N> operator-()
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = -(*this)[i];
		return dst;
	}
	vec<T, N> operator-( vec<T, N> rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] - rhs[i];
		return dst;
	}
	template<typename OT = T>
	vec<T, N> operator*( vec<OT, N> rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] * rhs[i];
		return dst;
	}
	vec<T, N> operator/( vec<T, N> rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] / rhs[i];
		return dst;
	}
	vec<T, N> operator&( vec<T, N> rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] & rhs[i];
		return dst;
	}
	vec<T, N> operator%( vec<T, N> rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] % rhs[i];
		return dst;
	}
	vec<T, N>& operator+=( T rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] + rhs;
		return (*this);
	}
	vec<T, N>& operator-=( T rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] - rhs;
		return (*this);
	}
	template<typename... A,
		typename = std::enable_if_t<(sizeof...(A) <= N)>,
		typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, T> && ...)>>
	vec<T, N>& operator*=( A&&... args )
	{
		vec<T, sizeof...(A)> p = { static_cast<T>(args)... };
		for(size_t i = 0; i < std::min(sizeof...(A), N); i++)
			(*this)[i] *= p[i];
		return (*this);
	}
	vec<T, N>& operator/=( T rhs )
	{
		for(int i = 0; i < N; i++)
			(*this)[i] = (*this)[i] / rhs;
		return (*this);
	}
	vec<T, N>& operator%=( T rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] % rhs;
		return (*this);
	}
	vec<T, N>& operator+=( vec<T, N> rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] + rhs[i];
		return (*this);
	}
	vec<T, N>& operator-=( vec<T, N> rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] - rhs[i];
		return (*this);
	}
	vec<T, N>& operator*=( vec<T, N> rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] * rhs[i];
		return (*this);
	}
	vec<T, N>& operator/=( vec<T, N> rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] / rhs[i];
		return (*this);
	}
	vec<T, N>& operator%=( vec<T, N> rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] % rhs[i];
		return (*this);
	}
	vec<T, N> abs()
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = __builtin_abs((*this)[i]);
		return dst;
	}
	template<typename O = T>
	O scalar_product(const vec& rhs) const noexcept
	{
		O dst {};
		for(size_t i = 0; i < N; i++)
			dst += static_cast<O>((*this)[i]) * static_cast<O>(rhs[i]);
		return dst;
	}
	template<typename O = T>
	O sum() const noexcept
	{
		O dst {};
		for(size_t i = 0; i < N; i++)
			dst += static_cast<O>((*this)[i]);
		return dst;
	}

	/* default elements */
	template<typename... A,
	         typename = std::enable_if_t<sizeof...(A) <= N && (sizeof...(A) > 1)>,
	         typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, size_t> && ...)>>
	static inline constexpr vec<T, N> identity( A&&... args ) { return { static_cast<T>(args ? 1 : 0)... }; }
	static inline constexpr vec<T, N> identity( size_t n ) { vec<T,N> dst = vec<T, N>::neutral(); dst[n % N] = 1; return dst; }
	static inline constexpr vec<T, N> neutral() { vec<T, N> dst; dst.fill(0); return dst; }
	inline constexpr vec<T, N> neutral( size_t n ) { vec<T, N> dst = (*this); dst[n % N] = 0; return dst; }
	static inline constexpr vec<T, N> set1( T lhs ) { vec<T, N> dst; dst.fill(lhs); return dst; }
	/* shuffle operations */
	vec<T, N> rotl(size_t n) { vec<T, N> dst; for(size_t i = 0; i < N; i++) dst[i] = (*this)[(n + i) % N]; return dst; }
	vec<T, N> rotr(size_t n) { vec<T, N> dst; for(size_t i = 0; i < N; i++) dst[i] = (*this)[(N - n + i) % N]; return dst; }
	vec<T, N> rot(ssize_t n) { return n < 0 ? rotl(std::abs(n)) : rotr(n); }
	template<typename... Components,
	         typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<Components>, size_t> && ...)>>
	inline constexpr vec<T, std::min(sizeof...(Components), N)> permute(Components&&... components) { return { (*this)[components % N]... }; }
	inline constexpr vec<T, 3> xyz() { return permute(0,1,2); }
	inline constexpr vec<T, 3> yzw() { return permute(1,2,3); }
	inline constexpr vec<T, 3> xzw() { return permute(0,2,3); }
	inline constexpr vec<T, 3> xyw() { return permute(0,1,3); }


	inline constexpr vec<T, 3>  xz() { return permute(0,2); }
	inline constexpr vec<T, 3>  zx() { return permute(2,0); }
	inline constexpr vec<T, 3>  yx() { return permute(1,0); }
	inline constexpr vec<T, 3>  xy() { return permute(0,1); }
	inline constexpr vec<T, 3>  yz() { return permute(1,2); }
	inline constexpr vec<T, 3>  zy() { return permute(2,1); }
	inline constexpr vec<T, 3>  wz() { return permute(3,2); }
	inline constexpr vec<T, 3>  zw() { return permute(2,3); }
	inline constexpr vec<T, 3>  wx() { return permute(3,0); }
	inline constexpr vec<T, 3>  xw() { return permute(0,3); }
	inline constexpr vec<T, 3>  wy() { return permute(3,1); }
	inline constexpr vec<T, 3>  yw() { return permute(1,3); }
};

template<typename T, size_t N, typename OT = T>
inline constexpr vec<T, N> operator*( const OT& rhs, const vec<T,N>& lhs  )
{
	vec<T, N> dst;
	for(size_t i = 0; i < N; i++)
		dst[i] = lhs[i] * rhs;
	return dst;
}


template<typename T, typename... A>
vec(T, A... args) -> vec<T, sizeof...(args) + 1>;

