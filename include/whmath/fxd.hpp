
/* fixed point scalar types */
/*
		template <typename _int_type, typename _float_type, 
			 _int_type   DECIMAL_BITS   = (_int_type)std::numeric_limits<_int_type>::digits / 2, 
			 _int_type   FRACTION_BITS  = (_int_type)std::numeric_limits<_int_type>::digits - DECIMAL_BITS, 
			 _int_type   SCALE          = ((_int_type)1) << FRACTION_BITS, 
			 _float_type PRECISION      = (_float_type)1.0 / SCALE, 
			 _float_type ACCURACY       = (_float_type)(PRECISION/2.0), 
			 _int_type   DECIMAL_MAX    = (_int_type)1 << DECIMAL_BITS, 
			 _int_type   DECIMAL_MIN    = (_int_type)-1 << DECIMAL_BITS, 
			 _float_type FRACTIONAL_MAX = (_float_type)DECIMAL_MAX + (_float_type)(1.0 - PRECISION), 
			 _float_type FRACTIONAL_MIN = (_float_type)DECIMAL_MIN>
				 struct qnumber : std::array<_int_type, 1>
				 {
					 qnumber() = default;
					 qnumber(_float_type f) { *this = from_float(f); }
					 _int_type from_float(_float_type f) { return (_int_type)round(f * (_float_type)SCALE); }
					 operator _int_type() const { return (_int_type)(*this * PRECISION); }
					 operator _float_type() const { return (_float_type)(*this * PRECISION); }
					 constexpr friend qnumber& operator+=(qnumber lhs, const qnumber& rhs) { lhs._value += rhs._value; return lhs; } 
					 constexpr friend qnumber& operator-=(qnumber lhs, const qnumber& rhs) { lhs._value -= rhs._value; return lhs; } 
					 constexpr friend qnumber& operator+(qnumber lhs, const qnumber& rhs) { lhs += rhs; return lhs; } 
					 constexpr friend qnumber& operator-(qnumber lhs, const qnumber& rhs) { lhs -= rhs; return lhs; }

				 };

		template<typename _int_type, typename _float_type, _int_type bits, _int_type frac>
		using fxd = qnumber<_int_type, _float_type, bits, frac>;
*/
