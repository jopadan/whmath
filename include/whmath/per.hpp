#pragma once

template<typename T, size_t N>
struct permutation : vec::type<T, N>
{
	enum sort_variant
	{
		DEFAULT_SORT = 0 << 0,
		BUBBLE_SORT  = 1 << 0,
		PANCAKE_SORT = 1 << 1,
		BLOCK_SORT   = 1 << 2,
	};

	constexpr permutation() = default;
	constexpr permutation(const vec::type<T,N>& rhs) : vec::type<T,N>(rhs) { }

	bool parity()
	{
		size_t swap_count = 0;
		sort(BUBBLE_SORT, &swap_count);
		return pow(-1, swap_count) <= 0 ? false : true;
	}

	ssize_t levi_civita()
	{
		return parity() ? 1 : -1;
	}

	permutation<T,N> next()
	{
		permutation<T, N> dst(*this);
		std::next_permutation(dst.begin(), dst.end());
		return dst;
	}

	permutation<T, N> sort(enum sort_variant algorithm, size_t* swap_count = nullptr)
	{
		switch(algorithm)
		{
			case BUBBLE_SORT:
				return bubble_sort(swap_count);
			case PANCAKE_SORT:
				return pancake_sort(swap_count);
			case BLOCK_SORT:
				return block_sort(swap_count);
			default:
				return default_sort(swap_count);
		};
	}

	permutation<T,N> default_sort(size_t* swap_count = nullptr)
	{
		permutation<T,N> p(*this);	
		std::sort(p.begin(), p.end());
		return p;
	}

	permutation<T,N> bubble_sort(size_t* swap_count = nullptr)
	{
		permutation<T,N> p(*this);
		for(size_t i = 0; i < N/2 + 1; ++i)
		{
			for(size_t j = N - 1; j > 0; --j)
				if(p[j - 1] > p[j])
				{
					std::swap(p[j - 1], p[j]);
					if(swap_count != nullptr)
						(*swap_count)++;
				}
		}
		return p;
	}

	permutation<T,N> pancake_sort(size_t* swap_count = nullptr)
	{
		permutation<T,N> p(*this);
		for(size_t n = N; n > 1; n--)
		{
			/* locate maximum */
			size_t maxdex = 0;
			for(size_t i = 0; i < n; i++)
				if(p[i] > p[maxdex])
					maxdex = i;
			/* not the last */
			if(maxdex != n - 1)
			{
				/* not the first */
				if(maxdex != 0)
				{
					size_t k = maxdex;
					for(size_t i = 0; i < k; k--, i++)
					{
						std::swap(p[i], p[k]);
						if(swap_count != nullptr)
							(*swap_count)++;
					}
				}
				size_t k = n - 1;
				for(size_t i = 0; i < k; k--, i++)
				{
					std::swap(p[i], p[k]);
					if(swap_count != nullptr)
						(*swap_count)++;
				}
			}
		}
		return p;
	}

	permutation<T,N> block_sort(size_t* swap_count = nullptr)
	{
		permutation<T,N> p(*this);
		for(size_t i = 0; i < N/2 + 1; ++i)
		{
			for(size_t j = N - 1; j > 0; --j)
				if(p[j - 1] > p[j])
				{
					std::swap(p[j - 1], p[j]);
					if(swap_count != nullptr)
						(*swap_count)++;
				}
		}
		return p;
	}
};

