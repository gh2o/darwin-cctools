#ifndef _MACH_MACH_TYPES_H_
#define _MACH_MACH_TYPES_H_

#include <stdint.h>

#include <mach/kern_return.h>
#include <mach/host_info.h>
#include <mach/port.h>
#include <mach/message.h>
#include <mach/vm_types.h>

typedef mach_port_t host_t;

typedef host_t host_name_t;
typedef host_t host_name_port_t;

typedef mach_port_t ipc_space_t;

#endif
