/* { dg-do compile } */
/* { dg-options "-O1 -mdejagnu-cpu=future" } */
/* See vec-strir-9.c for the same test with -O2 optimization.  */

#include <altivec.h>

vector unsigned char
doString(vector unsigned char *vp)
{
  /* Though two built-in functions are called, the implementation
     should use a single instruction to implement both with -O1.  */
  vector unsigned char result = vec_strir (*vp);
  if (vec_strir_p (*vp))
    return result;
  else
    return doString (vp + 1);
}

/* Enforce that a single dot-form instruction which is properly biased
   for the target's endianness implements this built-in.  */

/* { dg-final { scan-assembler-times {\mvstribr\.} 1 { target { be } } } } */
/* { dg-final { scan-assembler-times {\mvstribr\M[^.]} 0 { target { be } } } } */
/* { dg-final { scan-assembler-times {\mvstribl} 0 { target { be } } } } */
/* { dg-final { scan-assembler-times {\mvstribl\.} 1 { target { le } } } } */
/* { dg-final { scan-assembler-times {\mvstribl\M[^.]} 0 { target { le } } } } */
/* { dg-final { scan-assembler-times {\mvstribr} 0 { target { le } } } } */
