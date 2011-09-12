#ifndef _MACH_VM_STATISTICS_H_
#define _MACH_VM_STATISTICS_H_

#include <mach/machine/vm_types.h>

struct vm_statistics {
	natural_t	free_count;		/* # of pages free */
	natural_t	active_count;		/* # of pages active */
	natural_t	inactive_count;		/* # of pages inactive */
	natural_t	wire_count;		/* # of pages wired down */
	natural_t	zero_fill_count;	/* # of zero fill pages */
	natural_t	reactivations;		/* # of pages reactivated */
	natural_t	pageins;		/* # of pageins */
	natural_t	pageouts;		/* # of pageouts */
	natural_t	faults;			/* # of faults */
	natural_t	cow_faults;		/* # of copy-on-writes */
	natural_t	lookups;		/* object cache lookups */
	natural_t	hits;			/* object cache hits */

	natural_t	purgeable_count;	/* # of pages purgeable */
	natural_t	purges;			/* # of pages purged */

	natural_t	speculative_count;	/* # of pages speculative */
};

typedef struct vm_statistics	vm_statistics_data_t;

#endif
