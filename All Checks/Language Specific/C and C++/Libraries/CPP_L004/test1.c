#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *pFile;
	pFile = fopen("myfile.txt", "r");
	if (pFile == NULL)
	{
		fputs("error opening file\n", stderr);
		abort(); // UndCC_Violation
	}
	fclose (pFile);

	FILE *testFile;
	pFile = fopen("testfile.txt", "r");
	if (testFile==NULL)
	{
		printf("Error opening file");
		exit(1); // UndCC_Violation
	}
	else
	{
		/* other stuff here */
	}

	char *pPath;
	pPath = getenv("PATH"); // UndCC_Violation
	if (pPath!=NULL)
		printf("The current path is: %s", pPath);

	int i;
	printf("Checking if processor is available...");
	if (system(NULL)) // UndCC_Violation
		puts("Ok");
	else
		exit(1); // UndCC_Violation
	printf("Executing command DIR...\n");
	i = system ("dir"); // UndCC_Violation
	printf("The value returned was: %d.\n", i);

	return 0;
}
