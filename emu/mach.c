#include <string.h>
#include <stdio.h>
#include <time.h>
#include <mach/mach_error.h>
#include <mach/mach_init.h>
#include <mach/mach_port.h>
#include <mach/mach_time.h>
#include "log.h"

char *mach_error_string (mach_error_t value)
{
	if (value == 0)
		return "Success";
	
	char str[512];
	sprintf (str, "Mach Error %d", value);
	return strdup (str);
}

mach_port_t mach_host_self ()
{
	EMU_NOT_IMPLEMENTED ();
	return 1;
}

kern_return_t mach_port_deallocate
(
	ipc_space_t task,
	mach_port_name_t name
)
{
	EMU_NOT_IMPLEMENTED ();
	return KERN_SUCCESS;
}

kern_return_t mach_timebase_info (mach_timebase_info_t info)
{
	info->numer = 1;
	info->denom = 1;
	return KERN_SUCCESS;
}

uint64_t mach_absolute_time ()
{
	// return nanoseconds
	struct timespec ts = {0,0};
	clock_gettime (CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}
