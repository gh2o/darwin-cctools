#include <stdio.h>
#include <stdarg.h>
#include "log.h"

static char *types[] = {"debug", "info", "warning", "error", "fatal"};

void emu_log_message (
	emu_log_level type,
	const char *func,
	const char *format, ...
)
{
	va_list ap;
	va_start (ap, format);

	fprintf (stderr, "emu.%s (%s): ", types[type], func);
	vfprintf (stderr, format, ap);
	fprintf (stderr, "\n");
	
	va_end (ap);
}
