/*
 * Math.c
 *
 * Math object methods and light wrappers 
 * around math.h library functions.
 *
 * Methods implemented:
 *
 * Math.abs(x)
 * Math.acos(x)
 * Math.asin(x)
 * Math.atan(x)
 * Math.atan2(y, x)
 * Math.ceil(x)
 * Math.cos(x)
 * Math.exp(x)
 * Math.floor(x)
 * Math.log(x)
 * Math.max([value1[,value2[, ...]]])
 * Math.min([value1[,value2[, ...]]])
 * Math.pow(x, y)
 * Math.random()
 * Math.round(x)
 * Math.sin(x)
 * Math.sqrt(x)
 * Math.tan(x)
 *
 * Properties implemented:
 *
 * Math.E
 * Math.lN2
 * Math.LN10
 * Math.LOG2E
 * Math.LOG10E
 * Math.PI
 * Math.M_PI_2
 * Math.M_PI_4
 * Math.M_1_PI
 * Math.M_2_PI
 * Math.M_2_SQRTPI
 * Math.SQRT1_2
 * Math.SQRT2
 *
 */
#include <math.h>
#include <time.h>
#include <unistd.h>

#include "Math.h"

azt_val * math_abs(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  if (x->number.is_nan) return AZTNAN();
  if (x->number.is_inf) return AZTINF();
  return AZTNUM(fabs(x->number.val));
}

azt_val * math_acos(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(acos(x->number.val));
}

azt_val * math_asin(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(asin(x->number.val));
}

azt_val * math_atan(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(atan(x->number.val));
}

azt_val * math_atan2(azt_val *instance, azt_args *args, eval_state *state) {
  double y = TO_NUM(ARG(args, 0))->number.val;
  double x = TO_NUM(ARG(args, 1))->number.val;
  return AZTNUM(atan2(y, x));
}

azt_val * math_ceil(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  if (x->number.is_inf) 
    return x->number.is_neg ? AZTNINF() : AZTINF();
  return AZTNUM(ceil(x->number.val));
}

azt_val * math_cos(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(cos(x->number.val));
}

azt_val * math_exp(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(exp(x->number.val));
}

azt_val * math_floor(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  if (x->number.is_inf) 
    return x->number.is_neg ? AZTNINF() : AZTINF();
  return AZTNUM(floor(x->number.val));
}

azt_val * math_log(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(log(x->number.val));
}

azt_val * math_max(azt_val *instance, azt_args *args, eval_state *state) {
  int length = ARGLEN(args);
  if (length == 0) return AZTNINF();
  if (length == 2) {
    azt_val *x = TO_NUM(ARG(args, 0)),
            *y = TO_NUM(ARG(args, 1));
    if (x->number.is_nan || y->number.is_nan) return AZTNAN();
    return x->number.val > y->number.val ? x : y;
  }

  int i;
  azt_val *max = TO_NUM(ARG(args, 0));
  azt_val *x;
  if (max->number.is_nan) return AZTNAN();
  for (i = 0; i < (length - 1); i++) {
    x = TO_NUM(ARG(args, i+1));
    if (x->number.is_nan) return AZTNAN();
    if (x->number.is_inf || x->number.val > max->number.val) 
      max = x;
  };
  return max;
}

azt_val * math_min(azt_val *instance, azt_args *args, eval_state *state) {
  int length = ARGLEN(args);
  if (length == 0) return AZTINF();
  if (length == 2) {
    azt_val *x = TO_NUM(ARG(args, 0)),
            *y = TO_NUM(ARG(args, 1));
    if (x->number.is_nan || y->number.is_nan) return AZTNAN();
    return x->number.val < y->number.val ? x : y;
  }

  int i;
  azt_val *min = TO_NUM(ARG(args, 0));
  azt_val *x;
  if (min->number.is_nan) return AZTNAN();
  for (i = 0; i < (length - 1); i++) {
    x = TO_NUM(ARG(args, i+1));
    if (x->number.is_nan) return AZTNAN();
    if (x->number.val < min->number.val) 
      min = x;
  };
  return min;
}

azt_val * math_pow(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  azt_val *y = TO_NUM(ARG(args, 1));
  if (x->number.is_nan || y->number.is_nan)
    return AZTNAN();
  return AZTNUM(pow(x->number.val, y->number.val));
}

azt_val * math_random(azt_val *instance, azt_args *args, eval_state *state) {
  return AZTNUM((double)rand() / RAND_MAX);
}

azt_val * math_round(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(floor(x->number.val + 0.5));
}

azt_val * math_sin(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(sin(x->number.val));
}

azt_val * math_sqrt(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  if (x->number.is_nan) return AZTNAN();
  if (x->number.is_inf) return AZTINF();
  if (x->number.val < 0) return AZTNAN();
  return AZTNUM(sqrt(x->number.val));
}

azt_val * math_tan(azt_val *instance, azt_args *args, eval_state *state) {
  azt_val *x = TO_NUM(ARG(args, 0));
  return AZTNUM(tan(x->number.val));
}

unsigned long mix(unsigned long a, unsigned long b, unsigned long c) {
  a=a-b;  a=a-c;  a=a^(c >> 13);
  b=b-c;  b=b-a;  b=b^(a << 8);
  c=c-a;  c=c-b;  c=c^(b >> 13);
  a=a-b;  a=a-c;  a=a^(c >> 12);
  b=b-c;  b=b-a;  b=b^(a << 16);
  c=c-a;  c=c-b;  c=c^(b >> 5);
  a=a-b;  a=a-c;  a=a^(c >> 3);
  b=b-c;  b=b-a;  b=b^(a << 10);
  c=c-a;  c=c-b;  c=c^(b >> 15);
  return c;
}

void seed_rand() {
  // Need more entropy than time alone provides. 
  srand(mix(clock(), time(NULL), getpid()));
}

azt_val * bootstrap_math() {
  seed_rand();

  azt_val *math = AZTOBJ();

  fh_set_class(math, "Math");

  // Define properties
  DEF(math, "E",          AZTNUM(2.718281828459045235360287471352662498L));
  DEF(math, "LN2",        AZTNUM(0.693147180559945309417232121458176568L));
  DEF(math, "LN10",       AZTNUM(2.302585092994045684017991454684364208L));
  DEF(math, "LOG2E",      AZTNUM(1.442695040888963407359924681001892137L));
  DEF(math, "LOG10E",     AZTNUM(0.434294481903251827651128918916605082L));
  DEF(math, "PI",         AZTNUM(3.141592653589793238462643383279502884L));
  DEF(math, "M_PI_2",     AZTNUM(1.570796326794896619231321691639751442L));
  DEF(math, "M_PI_4",     AZTNUM(0.785398163397448309615660845819875721L));
  DEF(math, "M_1_PI",     AZTNUM(0.318309886183790671537767526745028724L));
  DEF(math, "M_2_PI",     AZTNUM(0.636619772367581343075535053490057448L));
  DEF(math, "M_2_SQRTPI", AZTNUM(1.128379167095512573896158903121545172L));
  DEF(math, "SQRT1_2",    AZTNUM(0.707106781186547524400844362104849039L));
  DEF(math, "SQRT2",      AZTNUM(1.414213562373095048801688724209698079L));

  // Define methods
  DEF(math, "abs", AZTNFUNC(math_abs, 1));
  DEF(math, "acos", AZTNFUNC(math_acos, 1));
  DEF(math, "asin", AZTNFUNC(math_asin, 1));
  DEF(math, "atan", AZTNFUNC(math_atan, 1));
  DEF(math, "atan2", AZTNFUNC(math_atan2, 2));
  DEF(math, "ceil", AZTNFUNC(math_ceil, 1));
  DEF(math, "cos", AZTNFUNC(math_cos, 1));
  DEF(math, "exp", AZTNFUNC(math_exp, 1));
  DEF(math, "floor", AZTNFUNC(math_floor, 1));
  DEF(math, "log", AZTNFUNC(math_log, 1));
  DEF(math, "max", AZTNFUNC(math_max, 2));
  DEF(math, "min", AZTNFUNC(math_min, 2));
  DEF(math, "pow", AZTNFUNC(math_pow, 2));
  DEF(math, "random", AZTNFUNC(math_random, 0));
  DEF(math, "round", AZTNFUNC(math_round, 1));
  DEF(math, "sin", AZTNFUNC(math_sin, 1));
  DEF(math, "sqrt", AZTNFUNC(math_sqrt, 1));
  DEF(math, "tan", AZTNFUNC(math_tan, 1));

  fh_attach_prototype(math, fh->function_proto);

  return math;
}