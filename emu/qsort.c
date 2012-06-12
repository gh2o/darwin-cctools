#include <stdlib.h>
#include <libc.h>

#ifdef QSORT_R_IS_GNU

struct pass
{
	void *arg;
	int (*compar) (void *, const void *, const void *);
};

static int comparator (const void *a, const void *b, void *p)
{
	struct pass *pass = p;
	return pass->compar (pass->arg, a, b);
}

#undef qsort_r
void qsort_r_bsd (void * base, size_t nmemb, size_t size,
	void *arg, int (*compar) (void *, const void *, const void *))
{
	struct pass pass;
	pass.arg = arg;
	pass.compar = compar;
	qsort_r (base, nmemb, size, comparator, &pass);
}

#endif
