#include <mach/mach_host.h>
#include "log.h"

kern_return_t host_info
(
	host_t host,
	host_flavor_t flavor,
	host_info_t host_info_out,
	mach_msg_type_number_t *host_info_count
)
{
	EMU_NOT_IMPLEMENTED ();
	return KERN_FAILURE;
}

kern_return_t host_statistics
(
	host_t host_priv,
	host_flavor_t flavor,
	host_info_t host_info_out,
	mach_msg_type_number_t *host_info_count
)
{
	EMU_NOT_IMPLEMENTED ();
	return KERN_FAILURE;
}
