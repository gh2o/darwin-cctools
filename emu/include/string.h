#ifndef _EMU_STRING_H_
#define _EMU_STRING_H_

#include_next <string.h>
#include_next <strings.h>

#include <sys/cdefs.h>
#include "config.h"

__BEGIN_DECLS

#ifndef HAVE_STRMODE
void strmode (int mode, char *p);
#endif

#ifndef HAVE_STRLCPY
size_t strlcpy (char *dest, const char *src, size_t size);
#endif

#ifndef HAVE_STRLCAT
size_t strlcat (char *dest, const char *src, size_t size);
#endif

__END_DECLS

#endif
