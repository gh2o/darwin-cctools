#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <mach-o/dyld.h>

int _NSGetExecutablePath (char *buf, uint32_t *bufsize)
{
	char proc[PATH_MAX + 2];
	sprintf (proc, "/proc/%d/exe", (int) getpid ());
	
	char ret[PATH_MAX + 2];
	ssize_t len = readlink (proc, ret, PATH_MAX + 1);
	
	if (len < 0)
		abort ();
	
	ret[len++] = '\0';
	
	if (*bufsize < len)
	{
		*bufsize = len;
		return -1;
	}
	else
	{
		strcpy (buf, ret);
		return 0;
	}
}
