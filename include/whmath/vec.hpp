#pragma once

template<typename T, size_t N>
struct vec : wide<T, N>
{
	enum { x, y, z, w };
	enum { r, g, b, a };
	enum { u, v };
	enum { s, t };
	constexpr explicit vec(const vec<T, N + 1>& rhs) noexcept { for(int i = 0; i < (*this).size(); i++) (*this)[i] = rhs[i]; }
	constexpr explicit vec(const vec<T, N - 1>& rhs, T val) noexcept { for(int i = 0; i < rhs.size(); i++) (*this)[i] = rhs[i]; (*this)[rhs.size()] = val; }
	constexpr vec(const T val) noexcept : wide<T, N>{ val } {}

	template<typename... A,
		typename = std::enable_if_t<sizeof...(A) <= N>,
		typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, T> && ...)>>
			constexpr vec(A&&... args) noexcept : wide<T, N>{ static_cast<T>(args)... } {}

	constexpr vec(const vec&) noexcept = default;
	constexpr vec(vec&&) noexcept = default;
	constexpr vec() noexcept = default;
	friend std::ostream& operator<< <>(std::ostream& stream, const vec<T, N>& rhs);
	constexpr vec<T, N>& operator=(const vec<T, N>& rhs) { return *(vec<T,N>*)std::memcpy(this, &rhs, N * sizeof(T)); }

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
	vec<T, N> operator+( vec<T, N> rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] + rhs[i];
		return dst;
	}
	vec<T, N> operator-( vec<T, N> rhs )
	{
		vec<T, N> dst;
		for(size_t i = 0; i < N; i++)
			dst[i] = (*this)[i] - rhs[i];
		return dst;
	}
	vec<T, N> operator*( vec<T, N> rhs )
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
	vec<T, N>& operator*=( T rhs )
	{
		for(size_t i = 0; i < N; i++)
			(*this)[i] = (*this)[i] * rhs;
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
			dst[i] = std::abs((*this)[i]);
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
/*
	template<typename... A,
	         typename = std::enable_if_t<(sizeof...(A) <= N) && (sizeof...(A) > 1)>,
		 typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, size_t> && ...)>>
	inline constexpr vec<T, N> permute(A&&... a) { return { static_cast<T>( a )... }; }
	template<typename... A,
	         typename = std::enable_if_t<(sizeof...(A) <= N) && (sizeof...(A) > 1)>,
		 typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, size_t> && ...)>>
	ssize_t levi_civita(A&&... a) { std::next_permutation(a...); }
	template<typename... A,
	         typename = std::enable_if_t<sizeof...(A) < N>,
	         typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, vec<T, N> && ...)>>
	constexpr vec<T, N> hodge_dual( A&&... args )
	{
		std::array<vec<T, N>, N - 1> v = { static_cast<vec<T, N>>(args)... };
		if(N == 3) { (*this).rotl v[0].rotl( }
	}
*/
	template<typename... A,
	         typename = std::enable_if_t<sizeof...(A) <= N && (sizeof...(A) > 1)>,
	         typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, size_t> && ...)>>
	inline constexpr vec<T, N> identity( A&&... args ) { return { static_cast<T>(args ? 1 : 0)... }; }
	inline constexpr vec<T, N> identity( size_t n ) { vec<T, N> dst = { 0 }; dst[n % N] = 1; return dst; }
	inline constexpr vec<T, N> neutral() { return { 0 }; }
	/* shuffle operations */
	vec<T, N> rotl(size_t n) { vec<T, N> dst; for(size_t i = 0; i < N; i++) dst[i] = (*this)[(n + i) % N]; return dst; }
	vec<T, N> rotr(size_t n) { vec<T, N> dst; for(size_t i = 0; i < N; i++) dst[i] = (*this)[(N - n + i) % N]; return dst; }
	vec<T, N> rot(ssize_t n) { return n < 0 ? rotl(std::abs(n)) : rotr(n); }
};

template<typename T, typename... A>
vec(T, A... args) -> vec<T, sizeof...(args) + 1>;

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


template<typename t>
struct q : wide<t, 4> { };

template<typename t>
struct uqv : wide<t, 4> { };
