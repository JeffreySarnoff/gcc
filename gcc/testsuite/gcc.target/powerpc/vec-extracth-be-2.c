/* { dg-options "-mdejagnu-cpu=future -mbig-endian" } */

#include <altivec.h>

extern void abort (void);

int
main (int argc, char *argv [])
{
  vector unsigned int source_a = { 0, 4, 8, 12 };
  vector unsigned int source_b = { 16, 20, 24, 28 };

  vector unsigned long long int result_1 = { 0, 16 };
  vector unsigned long long int result_2 = { 0, 12 };
  vector unsigned long long int result_3 = { 0, 4 };
  vector unsigned long long int result_4 = { 0, 16 };

  if (!vec_all_eq (vec_extracth (source_a, source_b, 12), result_1))
    abort ();
  if (!vec_all_eq (vec_extracth (source_a, source_b, 16), result_2))
    abort ();
  if (!vec_all_eq (vec_extracth (source_b, source_a, 8), result_3))
    abort ();
  if (!vec_all_eq (vec_extracth (source_b, source_a, 28), result_4))
    abort ();

  return 0;
}

/* { dg-final { scan-assembler {\mvextduwvrx\M} } } */
