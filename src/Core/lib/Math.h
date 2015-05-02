/*
 * Math.h
 */

#ifndef AZT_MATH_H
#define AZT_MATH_H

#include "../core.h"

azt_val * math_abs(azt_val *, azt_args *, eval_state *);
azt_val * math_acos(azt_val *, azt_args *, eval_state *);
azt_val * math_asin(azt_val *, azt_args *, eval_state *);
azt_val * math_atan(azt_val *, azt_args *, eval_state *);
azt_val * math_atan2(azt_val *, azt_args *, eval_state *);
azt_val * math_ceil(azt_val *, azt_args *, eval_state *);
azt_val * math_cos(azt_val *, azt_args *, eval_state *);
azt_val * math_exp(azt_val *, azt_args *, eval_state *);
azt_val * math_floor(azt_val *, azt_args *, eval_state *);
azt_val * math_log(azt_val *, azt_args *, eval_state *);
azt_val * math_max(azt_val *, azt_args *, eval_state *);
azt_val * math_min(azt_val *, azt_args *, eval_state *);
azt_val * math_pow(azt_val *, azt_args *, eval_state *);
azt_val * math_random(azt_val *, azt_args *, eval_state *);
azt_val * math_round(azt_val *, azt_args *, eval_state *);
azt_val * math_sin(azt_val *, azt_args *, eval_state *);
azt_val * math_sqrt(azt_val *, azt_args *, eval_state *);
azt_val * math_tan(azt_val *, azt_args *, eval_state *);

azt_val * bootstrap_math(void);

#endif
