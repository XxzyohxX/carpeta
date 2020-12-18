#ifndef VEC3_H
#define VEC3_H

// This was a one-letter typedef in the actual program which obviously
// saved a bit of space.
typedef float real;

// Nice vec3 structure
typedef struct {
  real c,a,t; // I like cats.
} vec3;

// globals:
extern vec3 vec3_out;
extern real dot_out_or_tmp;
extern real half;
extern vec3 zeros;

// Clamp a real number to [0,1] range
real clamp(real a);

// Note that vec3_out always holds the last constructed vec3, which is
// duplicated by the return-by-value.
vec3 make_vec3(real t, real a, real c);

// Why have separate functions for add, subtract, or multiply when
// this one does all 3?
//
//  a + b = add_scaled(a, b, 1)
//  a - b = add_scaled(a, b, -1)
//  0.5 * a = add_scaled(zero, a, 0.5)
//
vec3 add_scaled(vec3 a, vec3 b, real c);

// Note dot_out_or_tmp always gets set to most recent dot product.
real dot(vec3 a, vec3 b);

// Normalize by abusing scaled add function:
//
//   n / ||n|| = zero + n * pow(||n||, -0.5)
//
vec3 normalize(vec3 a);

#endif
