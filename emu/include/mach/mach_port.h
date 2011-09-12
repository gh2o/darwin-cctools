#ifndef _MACH_MACH_PORT_H_
#define _MACH_MACH_PORT_H_

#include <mach/mach_types.h>

kern_return_t mach_port_deallocate
(
	ipc_space_t task,
	mach_port_name_t name
);

#endif
