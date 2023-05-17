#include "test.h"

void checkFunc{
	int i;
	printf ("Checking if processor is available...");
	if (system(NULL)) puts ("Ok");
	else exit (1);
	printf ("Executing command DIR...\n");
	i=system ("dir");
	printf ("The value returned was: %d.\n",i);
}
