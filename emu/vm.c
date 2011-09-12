#include <stdlib.h>
#include <mach/vm_map.h>
#include "log.h"

kern_return_t vm_allocate
(
	vm_map_t target_task,
	vm_address_t *address,
	vm_size_t size,
	int flags
)
{
	if (!flags) // forced location
	{
		EMU_ERROR ("forced address not supported");
		return KERN_FAILURE;
	}
	
	void *mem = malloc (size);
	if (!mem)
	{
		EMU_ERROR ("malloc failed");
		return KERN_FAILURE;
	}
	
	*address = mem;
	return KERN_SUCCESS;
}

kern_return_t vm_deallocate
(
	vm_map_t target_task,
	vm_address_t address,
	vm_size_t size
)
{
	free (address);
	return KERN_SUCCESS;
}
