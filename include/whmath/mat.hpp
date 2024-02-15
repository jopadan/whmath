#pragma once

template<typename T, size_t COLS, size_t ROWS>
std::ostream& operator<<(std::ostream& stream, const mat<T, COLS, ROWS>& rhs)
{
	for (std::size_t i = 0; i < ROWS; i++)
		stream << rhs[i] << std::endl;

	return stream;
}

template<typename T, size_t COLS, size_t ROWS>
struct mat : wide<T, COLS, ROWS>
{
	constexpr explicit mat(const mat<T, COLS, ROWS + 1>& rhs) noexcept { for(int i = 0; i < (*this).size(); i++) (*this)[i] = rhs[i]; }
	constexpr explicit mat(const mat<T, COLS, ROWS - 1>& rhs, vec::vec<T, COLS> val) noexcept { for(int i = 0; i < rhs.size(); i++) (*this)[i] = rhs[i]; (*this)[rhs.size()] = val; }
	constexpr explicit mat(const vec::vec<T, COLS> val) noexcept : wide<T, COLS, ROWS>{ val } {}
	constexpr explicit mat(const T val) noexcept : wide<T, COLS, ROWS>{ { val } } {}

	constexpr mat(std::initializer_list<vec::vec<T, COLS>> rows) noexcept
	{
		std::copy(rows.begin(), rows.end(), (*this).begin()); 
	}
	constexpr mat(const mat&) noexcept = default;
	constexpr mat(mat&&) noexcept = default;
	constexpr mat() noexcept = default;
	friend std::ostream& operator<< <>(std::ostream& stream, const mat<T, COLS, ROWS>& rhs);
	template<typename... A,
		typename = std::enable_if_t<(sizeof...(A) <= ROWS) && (sizeof...(A) >= 1)>,
		typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, vec::type<T,COLS>> && ...)>>
	constexpr explicit mat(A&&... args) noexcept : wide<T, COLS, ROWS>{ static_cast<vec::type<T, COLS>>(args)... } {}

	static constexpr mat<T, ROWS, COLS> identity()
	{
		mat<T, ROWS, COLS> dst;

		for(size_t i = 0; i < ROWS; i++)
			dst[i] = vec::type<T, ROWS>::identity(i);

		return dst;
	}

	inline constexpr vec::vec<T, COLS> row(size_t n) { return (*this)[n]; }
	inline constexpr vec::vec<T, ROWS> col(size_t n)
	{
		vec::vec<T, ROWS> dst;
		for(size_t i = 0; i < ROWS; i++)
			dst[i] = (*this)[i][n];
		return dst;
	}
	inline constexpr void set_row(size_t n, vec::vec<T, COLS> rhs)
	{
		(*this)[n] = rhs;
	}
	inline constexpr void set_col(size_t n, vec::vec<T, ROWS> rhs)
	{
		for(size_t i = 0; i < ROWS; i++)
			(*this)[i][n % COLS] = rhs[i];
	}
	template<typename... Components,
		typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<Components>, size_t> && ...)>>
			inline constexpr mat<T, COLS, ROWS> permute_rows(Components&&... components) 
			{
				return { (*this)[ components % ROWS ]... };
			}
	template<typename... Components,
		typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<Components>, size_t> && ...)>>
			inline constexpr mat<T, COLS, ROWS> permute_cols(Components&&... components)
			{
				mat<T, COLS, ROWS> dst;

				for(size_t i = 0; i < ROWS; i++)
					dst[i] = { (*this)[i][components % COLS]... };
				return dst;
			}
	inline constexpr T row_sum(size_t n) { return row(n).sum(); }
	inline constexpr T col_sum(size_t n) { return col(n).sum(); }

	inline constexpr mat<T, ROWS, COLS> transpose()
	{
		mat<T, ROWS, COLS> dst = { 0 };
		for(size_t i = 0; i < ROWS; i++)
			for(size_t j = 0; j < COLS; j++)
				dst[j][i] = (*this)[i][j];
		return dst; 
	}
	template<typename... A,
		typename = std::enable_if_t<sizeof...(A) <= ROWS>,
		typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, ssize_t> && ...)>>
			inline constexpr mat<T, COLS, ROWS> rot_rows(A&&... args)
			{
				mat<T, COLS, ROWS> dst{ 0 };
				vec::vec<ssize_t, sizeof...(A)> rot{ static_cast<ssize_t>(args)... };
				for(size_t i = 0; i < sizeof...(A); i++)
					dst.set_row(i, row(i).rot(rot[i]));
				return dst;
			}

	template<typename... A,
		typename = std::enable_if_t<sizeof...(A) <= COLS>,
		typename = std::enable_if_t<(std::is_convertible_v<std::decay_t<A>, ssize_t> && ...)>>
			inline constexpr mat<T, COLS, ROWS> rot_cols(A&&... args)
			{
				mat<T, COLS, ROWS> dst{ 0 };
				vec::vec<ssize_t, sizeof...(A)> rot{ static_cast<ssize_t>(args)... };
				for(size_t i = 0; i < sizeof...(A); i++)
					dst.set_col(i, col(i).rot(rot[i]));
				return dst;
			}
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
	   */
};
