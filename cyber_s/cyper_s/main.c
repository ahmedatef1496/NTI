/* strtol example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */

int main ()
{
  char szNumbers[] = "2001 60c0c0";
  char * pEnd;
  long int li1, li2, li3, li4;
  li1 = strtol (szNumbers,&pEnd,16);
  li2 = strtol (pEnd,&pEnd,16);

  printf ("The decimal equivalents are: %ld, %ld, .\n", li1, li2);
  return 0;
}
