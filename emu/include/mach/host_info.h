#ifndef _MACH_HOST_INFO_H_
#define _MACH_HOST_INFO_H_

#include <mach/machine/vm_types.h>
#include <mach/message.h>
#include <mach/machine.h>

#define HOST_BASIC_INFO 1
#define HOST_VM_INFO    2
#define HOST_SCHED_INFO 3

typedef integer_t host_flavor_t;
typedef integer_t * host_info_t;

#pragma pack(4)
typedef struct host_basic_info {
	integer_t		max_cpus;		/* max number of CPUs possible */
	integer_t		avail_cpus;		/* number of CPUs now available */
	natural_t		memory_size;		/* size of memory in bytes, capped at 2 GB */
	cpu_type_t		cpu_type;		/* cpu type */
	cpu_subtype_t		cpu_subtype;		/* cpu subtype */
	cpu_threadtype_t	cpu_threadtype;		/* cpu threadtype */
	integer_t		physical_cpu;		/* number of physical CPUs now available */
	integer_t		physical_cpu_max;	/* max number of physical CPUs possible */
	integer_t		logical_cpu;		/* number of logical cpu now available */
	integer_t		logical_cpu_max;	/* max number of physical CPUs possible */
	uint64_t		max_mem;		/* actual size of physical memory */
} host_basic_info_data_t;
#pragma pack()

typedef struct host_sched_info {
	integer_t	min_timeout;	/* minimum timeout in milliseconds */
	integer_t	min_quantum;	/* minimum quantum in milliseconds */
} host_sched_info_data_t;

#define HOST_BASIC_INFO_COUNT ((mach_msg_type_number_t)( \
	sizeof(host_basic_info_data_t) / sizeof(integer_t) \
))
#define HOST_SCHED_INFO_COUNT ((mach_msg_type_number_t)( \
	sizeof(host_sched_info_data_t)/sizeof(integer_t) \
))

#endif
