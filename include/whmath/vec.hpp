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
	inline constexpr vec<T, 3> vector_product_3d(vec<T, 3> other)
	{
		return ((*this) * other.rotl(1) - other * (*this).rotl(1)).rotl(1);
	}
/*
	friend constexpr vec<T, 4> vector_product_4d(vec<T, 4> a, vec<T, 4> b, vec<T, 4> c)
	{
		
	}
	template<typename... A,
	         typename = std::enable_if_t<sizeof...(A) < (N - 1)>,
	         typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, vec<T, N>> && ...)>>
	constexpr vec<T, N> hodge_dual( A&&... args )
	{
		std::array<vec<T, N>, N> p = { (*this), static_cast<vec<T, N>>(args)..., { 0 } };
		std::array<std::array<vec<T, N-1>, N>, N> v;
		for(size_t j = 0; j < N; j++)
		{
			for(size_t l = 0; l < (N - 1); l++)
			{
				vec<T, N-1> tmp = { 0 };
				vec<T, N>& src = p[l];
				size_t k = 0;
				for(size_t i = 0; i < N; i++)
				{
					if(i == j)
					{
						k++;
						continue;
					}
					tmp[i-k] = src[i];
				}
				v[j][l] = tmp;
				std::cout << v[j][l] << std::endl;
			}
		}

		switch(N)
		{
			case 1:
			case 2:
			case 3:
			case 4:
				std::cout << "4D cross: " << std::endl;
					for(size_t i = 0; i < N - 1; i++)
					{
						std::cout << v[0][i] << std::endl;
						std::cout << v[1][i] << std::endl;
						std::cout << v[2][i] << std::endl;
						std::cout << v[3][i] << std::endl;
					}
					vec<T, 3> v1{ v[1][2], v[1][1], v[1][2] };
					          v1 *= { -v[2][3],  v[2][3], v[2][1] };
					vec<T, 3> v2{ v[1][3], v[1][1], v[1][3] };
					          v2 *= { -v[2][1], -v[2][3], v[2][3] };
					vec<T, 3> t{ v[0][0] * v1 + v[0][0].rotl(1) * v2 };
					std::cout << t << std::endl;
					break;
					    ( -p[0][3] * p[1][2] - p[0][2] * p[1][3]) * t[0][0] + (-p[0][3] * p[1][1] + p[0][1] * p[1][3]) * t[0][1] + (-p[0][1] * p[1][2] + p[0][2] * p[1][1]) * t[0][2],
					    (-p[0][3] * p[1][2] + p[0][2] * p[1][3]) * t[1][0] + ( p[0][3] * p[1][0] - p[0][0] * p[1][3]) * t[1][1] + ( p[0][0] * p[1][2] - p[0][2] * p[1][0]) * t[1][2],
					    ( p[0][3] * p[1][1] - p[0][1] * p[1][3]) * t[2][0] + (-p[0][3] * p[1][0] + p[0][0] * p[1][3]) * t[2][1] + (-p[0][0] * p[1][1] + p[0][1] * p[1][0]) * t[2][2],
					    ( p[0][1] * p[1][2] - p[0][2] * p[1][1]) * t[3][0] + (-p[0][0] * p[1][2] + p[0][2] * p[1][0]) * t[3][1] + ( p[0][0] * p[1][1] - p[0][1] * p[1][0]) * t[3][2]
			default:
				break;
		}
		return p[N-1];
	}
*/
/*
	sca::f32 det()
	{
		for(size_t i = 0; i < N; i++)
		{
			vec::f32<M> a = { 1.0f };
			vec::f32<M> b = { 1.0f };
			for(size_t i = 0; i < N; i++)
			{
				for(int k = 0; k < N; k++)
				{
					a[k] *= (*this)[(0+i) % N][(k+i) % N];
					b[k] *= (*this)[(0+i) % N][((N-k)-i) % N];
				}
			}
			return a[0] + a[1] + a[2] - b[0] - b[1] - b[2];
		}
	}
	template<typename... A,
	         typename = std::enable_if_t<(sizeof...(A) <= N) && (sizeof...(A) > 1)>,
		 typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, size_t> && ...)>>
	ssize_t levi_civita(A&&... a) { std::next_permutation(a...); }
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



template<typename t>
struct q : wide<t, 4> { };

template<typename t>
struct uqv : wide<t, 4> { };
