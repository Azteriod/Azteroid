#include "Say.h"

azt_val * print_say(azt_val *instance, azt_args *args, eval_state *state) {
  unsigned i;
  for (i = 0; i < ARGLEN(args); i++)
    fh_debug(stdout, fh_to_primitive(ARG(args, i), T_STRING), 0, 1);
  return AZTUNDEF();
}

azt_val * print_sayln(azt_val *instance, azt_args *args, eval_state *state) {
  unsigned i;
  for (i = 0; i < ARGLEN(args); i++)
    fh_debug(stdout, fh_to_primitive(ARG(args, i), T_STRING), 0, 1);
  return AZTUNDEF();
}