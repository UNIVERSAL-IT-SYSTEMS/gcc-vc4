#include <stdio.h>
#include <stdlib.h>

#include "cpuid.h"

static void bmi_test (void);

static void
__attribute__ ((noinline))
do_test (void)
{
  bmi_test ();
}

int
main ()
{
  unsigned int eax, ebx, ecx, edx;

  if (__get_cpuid_max (0, NULL) < 7)
    return 0;

  __cpuid_count (7, 0, eax, ebx, ecx, edx);

  /* Run BMI test only if host has BMI support.  */
  if (ebx & bit_BMI)
    {
      do_test ();
#ifdef DEBUG
    printf ("PASSED\n");
#endif
    }
#ifdef DEBUG
  else
    printf ("SKIPPED\n");
#endif

  return 0;
}
