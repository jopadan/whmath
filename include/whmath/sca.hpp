#pragma once
#if   defined(GLCOREARB)
#include <GL/glcorearb.h>
#elif defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <ctime>

using GLchar                       = char;
using GLuchar                      = unsigned char;
using GLbyte                       = int8_t;
using GLubyte                      = uint8_t;
using GLshort                      = int16_t;
using GLushort                     = uint16_t;
using GLint                        = int32_t;
using GLuint                       = uint32_t;
using GLint64                      = int64_t;
using GLuint64                     = uint64_t;
using GLsizei                      = int;
using GLbitfield                   = unsigned int;
using GLboolean                    = unsigned char;
using GLfloat                      = float;
using GLdouble                     = double;
using khronos_ssize_t              = ssize_t;
using khronos_usize_t              = size_t;
using khronos_intptr_t             = intptr_t;
using khronos_uintptr_t            = uintptr_t;
using khronos_stime_nanoseconds_t  = GLint64;
using khronos_utime_nanoseconds_t  = GLuint64;
using khronos_utime_microseconds_t = GLuint64;
using khronos_stime_microseconds_t = GLint64;
using khronos_time_t               = time_t;

#else
#include <stdint.h>
#include <stddef.h>
#include <time.h>

typedef char          GLchar;
typedef unsigned char GLuchar;
typedef int8_t        GLbyte;
typedef uint8_t       GLubyte;
typedef int16_t       GLshort;
typedef uint16_t      GLushort;
typedef int32_t       GLint;
typedef uint32_t      GLuint;
typedef int64_t       GLint64;
typedef uint64_t      GLuint64;
typedef int           GLsizei;
typedef unsigned int  GLbitfield;
typedef unsigned char GLboolean;
typedef float         GLfloat;
typedef double        GLdouble;
typedef ssize_t       khronos_ssize_t;
typedef size_t        khronos_usize_t;
typedef intptr_t      khronos_intptr_t;
typedef uintptr_t     khronos_uintptr_t;
typedef GLint64       khronos_stime_nanoseconds_t;
typedef GLuint64      khronos_utime_nanoseconds_t;
typedef GLuint64      khronos_utime_microseconds_t;
typedef GLint64       khronos_stime_microseconds_t;
typedef time_t        khronos_time_t;

#endif
