#include <unistd.h>

void printf(const char* string)
{
	write(1, string, strlen(string));
	
	return;
}

