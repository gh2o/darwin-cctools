#include <string.h>
#include <stdio.h>
#include <mach/mach_error.h>
#include <mach/mach_init.h>
#include <mach/mach_port.h>
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
