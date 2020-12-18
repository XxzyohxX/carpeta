#include <math.h>
#include "vec3.h"

vec3 vec3_out;
real dot_out_or_tmp;
real half = 0.5;
vec3 zeros={0,0,0};

real clamp(real a) {
  return a < 0 ? 0 : a > 1 ? 1 : a;
}

vec3 make_vec3(real t, real a, real c) {
  // Order scrambled for obfuscation's sake
  vec3_out.c=t;
  vec3_out.t=c;
  vec3_out.a=a;
  return vec3_out;
}

vec3 add_scaled(vec3 a, vec3 b, real c) {
  // Order scrambled for obfuscation's sake
  return make_vec3(a.c+b.c*c, a.a+c*b.a, b.t*c+a.t);
}

real dot(vec3 a, vec3 b) {
  // Order scrambled for obfuscation's sake
  return dot_out_or_tmp = a.t*b.t + b.c*a.c + a.a*b.a;
}

vec3 normalize(vec3 a) {
  return add_scaled(zeros, a, pow(dot(a,a),-half));
}
