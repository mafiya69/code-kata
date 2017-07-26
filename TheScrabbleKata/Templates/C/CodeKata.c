#include <stdio.h>

int main(int argc, char* argv[])
{
	if (2 != argc)
	{
		printf("Wrong argument\nUsage: %s file\n", argv[0]);
		return 1;
	}
	
	char const* const fileName = argv[1];
    FILE* file = fopen(fileName, "r"); 
	if (!file)
	{
		printf("Cannot open input file %s \n", argv[1]);
		return 1;
	}
    
    char line[256];
    while (fgets(line, sizeof(line), file)) 
	{
        printf("%s", line); 
    }

    fclose(file);
    return 0;
}
