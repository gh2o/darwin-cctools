#ifndef _MACH_MACH_HOST_H_
#define _MACH_MACH_HOST_H_

#include <mach/mach_types.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

kern_return_t host_info
(
	host_t host,
	host_flavor_t flavor,
	host_info_t host_info_out,
	mach_msg_type_number_t *host_info_count
);

kern_return_t host_statistics
(
	host_t host_priv,
	host_flavor_t flavor,
	host_info_t host_info_out,
	mach_msg_type_number_t *host_info_count
);

__END_DECLS

#endif
