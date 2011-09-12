#ifndef _MACH_VM_TYPES_H_
#define _MACH_VM_TYPES_H_

#include <stdint.h>
#include <mach/port.h>
#include <mach/machine/vm_types.h>

typedef mach_port_t vm_map_t;

typedef void * vm_offset_t;
typedef void * vm_address_t;

#endif
