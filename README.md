# whmath

C++ SIMD header-only math library targeting game/engine development mixing features of:

- [wolftype/versor][versor]
- [4J-company/mr-math][mr-math]
- [EricLengyel/Terathon-Math-Library][Terathon-Math-Library]

## Description

| file      | description                                                        |
| ----:     | :---                                                               |
|`math.hpp`   |template prototypes describe intended implementations               |

## Sources

```sh
get clone --recurse-submodules --recursive http://github.com/jopadan/whmath
cd whmath
```

## Building

```sh
cmake . --install-prefix=/usr
make install
```

### Optimization

Change `CMakeLists.txt` compile flags to fit your needs:
```sh
add_compile_options(-march=native -mfpmath=sse+387 -mveclibabi=svml -O3)
```

## Usage

```c++
#include <whmath/math.hpp>

using namespace math;

/* single float scalar */
sca::f32          s = 213.0f;

/* unsigned byte vector of size 4 */
vec::u8<4>        a = { 43, 52, 32, 53 };

/* single float vector of size 4 */
vec::f32<4>       b = { 32.0, 54.0, 43.0, 34.0 };

/* unsigned short integer bitfield with 3 color components */
col::u16<5,6,5>   c = { 24, 12, 12 };

/* unsigned short integer bitfield with 4 color components */
col::u16<4,4,4,4> d = { 24, 12, 12, 8 };

/* unsigned char integer vector with 4 color components */
col::u8<4>        e = { 24, 12, 12, 8 };

/* floating point vector with 4 color components */
col::f32<4>       f = { 24.0f, 12.0f, 12.0f, 8.0f };

/* 3d vector product */
mat::f32<3, 3> m3 = mat::f32<3,3>::identity();
m3[2] = prd::cross<sca::f32, 3>(m3[0], m3[1]);

/* 4d vector product */
mat::f32<4, 4> m4 = mat::f32<4,4>::identity();
m4[3] = prd::cross<sca::f32, 4>(m4[0], m4[1], m4[2]);


```

# Links
- [mr-math]
- [versor]
- [Terathon-Math-Library]
- [Terathon Software LLC]
- [Permutation]
- [Parity Theorem for Permutations]
- [Levi-Civita symbol]
- [Hodge star operator]

[mr-math]: https://github.com/4J-company/mr-math/
[versor]: https://github.com/wolftype/versor/
[Terathon-Math-Library]: https://github.com/EricLengyel/Terathon-Math-Library
[Terathon Software LLC]: https://terathon.com/index.html
[Permutation]: https://en.wikipedia.org/wiki/Permutation
[Parity Theorem for Permutations]: https://maa.org/book/export/html/115646
[Levi-Civita symbol]: https://en.wikipedia.org/wiki/Levi-Civita_symbol
[Hodge star operator]: https://en.wikipedia.org/wiki/Hodge_star_operator
