#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
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
	long page_size = sysconf (_SC_PAGESIZE);
	
	long number_of_pages = (size + page_size - 1) / page_size;
	size_t size_rounded = number_of_pages * page_size;
	
	if (!flags) // forced location
	{
		EMU_ERROR ("forced address not supported");
		return KERN_FAILURE;
	}
	
	void *mem = mmap (
		NULL,
		size_rounded,
		PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS,
		-1,
		0
	);
	
	if (mem == MAP_FAILED)
	{
		EMU_ERROR ("malloc failed");
		return KERN_FAILURE;
	}
	
	*address = (vm_address_t) mem;
	return KERN_SUCCESS;
}

kern_return_t vm_deallocate
(
	vm_map_t target_task,
	vm_address_t address,
	vm_size_t size
)
{
	long page_size = sysconf (_SC_PAGESIZE);
	
	long first_page = address / page_size;
	long last_page = (address + size - 1) / page_size;
	
	long number_of_pages = last_page - first_page + 1;
	
	void *mstart = (void *)(first_page * page_size);
	size_t msize = number_of_pages * page_size;
	
	munmap (mstart, msize);
	
	return KERN_SUCCESS;
}
