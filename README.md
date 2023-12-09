# whmath

C++ SIMD header-only math library targeting game/engine development

## Description

| file      | description                                                        |
| ----:     | :---                                                               |
|`math.hpp`   |template prototypes describe intended implementations               |

## Status

| type | sca  | vec  | ten | oct | sed
| ----:| :--- | :--- | :-- | :-- | :-- 
| `f32<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `f64<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
|  `i8<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
|  `u8<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `i16<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `u16<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `i32<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `u32<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `i64<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `u64<n>`|<ul><li>- [x] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `fxd<n>`|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|
| `cpx<n>`|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|<ul><li>- [ ] </ul></li>|


## Usage

```c++
#include <whmath/math.hpp>

using namespace math;

/* single float scalar */
sca::f32 f = 213.0f;

/* unsigned byte vector of size 4 */
vec::u8<4>  a = { 43, 52, 32, 53 };

/* single float vector of size 4 */
vec::f32<4> b = { 32.0, 54.0, 43.0, 34.0 };

/* single unsigned short integer split into 3 color components */
col::RGB565 c = { (24 << 0) | (54 << 5) | (32 << 6) };

```

# Links

- [Permutation](https://en.wikipedia.org/wiki/Permutation)
- [Parity Theorem for Permutations](https://maa.org/book/export/html/115646)
- [Levi-Civita symbol](https://en.wikipedia.org/wiki/Levi-Civita_symbol)
- [Hodge star operator](https://en.wikipedia.org/wiki/Hodge_star_operator)
