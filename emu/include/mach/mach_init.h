#ifndef _MACH_MACH_INIT_H_
#define _MACH_MACH_INIT_H_

#include <mach/mach_types.h>
#include <sys/cdefs.h>
#include <unistd.h>

#define vm_page_size ((vm_size_t) sysconf (_SC_PAGESIZE))

#define mach_task_self() ((mach_port_t) 1)

__BEGIN_DECLS
mach_port_t mach_host_self ();
__END_DECLS

#endif
