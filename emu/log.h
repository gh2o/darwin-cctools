#ifndef _EMU_LOG_H_
#define _EMU_LOG_H_

#define EMU_MESSAGE(type,...) { \
	emu_log_message (type, __FUNCTION__, __VA_ARGS__); \
}

#define EMU_DEBUG(...) EMU_MESSAGE(DEBUG,__VA_ARGS__)
#define EMU_INFO(...) EMU_MESSAGE(INFO,__VA_ARGS__)
#define EMU_WARNING(...) EMU_MESSAGE(WARNING,__VA_ARGS__)
#define EMU_ERROR(...) EMU_MESSAGE(ERROR,__VA_ARGS__)
#define EMU_FATAL(...) EMU_MESSAGE(FATAL,__VA_ARGS__)

#if 0
#define EMU_NOT_IMPLEMENTED() EMU_DEBUG("not implemented")
#else
#define EMU_NOT_IMPLEMENTED()
#endif

typedef enum {
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR,
	FATAL
} emu_log_level;

void emu_log_message (
	emu_log_level type,
	const char *func,
	const char *format, ...
);

#endif
