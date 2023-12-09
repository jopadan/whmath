#pragma once

template<typename T, size_t N>
struct permutation : vec::type<T, N>
{

	constexpr permutation(vec::vec<T,N>& v) : vec::type<T,N>(v) {}
 	inline constexpr permutation next()
	{
		permutation<T, N> p(*this);
		std::next_permutation(p.begin(), p.end());
		return p;
	}

	inline constexpr int8_t parity()
	{
		size_t s = 1;
		permutation<T, N> p(*this);
		bool swapped = false;
		do
		{
			swapped = false;
			for(size_t i = 0; i < N; i++)
			{
				if(p[i] > p[(i+1) % N])
				{
					std::swap(p[i], p[(i+1) % N]);
					s *= -1;
					swapped = true;
				}
			}
		} while(swapped);
		return s == 1 ? 1 : -1;
	}

	inline constexpr permutation pancake_sort()
	{
		permutation<T, N> p(*this);
		for(size_t i = N; i > 1; i--)
		{
			/* max index */
			size_t maxdex = 0;
			for(size_t k = 0; k < i; k++)
				if(p[k] > p[maxdex])
					maxdex = k;
			/* not the last element */
			if(maxdex != (i - 1))
			{
			        /* not the first element */
				if(maxdex != 0)
				{
					size_t left = 0;
					for(size_t j = maxdex; left < j; j--)
					{
						std::swap(p[left], p[j]);
						left += 1;
					}
				}
				size_t left = 0;
				for(size_t j = i - 1; left < j; j--)
				{
					std::swap(p[left], p[j]);
					left += 1;
				}
			}
		}
		return p; 
	}
};
