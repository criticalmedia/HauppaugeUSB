#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include "log.h"

static struct timeval tv_s = {0, 0};

static void printTS() {
	struct timeval tv;
	if(tv_s.tv_sec == 0) gettimeofday(&tv_s, NULL);
	gettimeofday(&tv, NULL);
	tv.tv_usec -= tv_s.tv_usec;
	tv.tv_sec -= tv_s.tv_sec + ((tv.tv_usec < 0) ? 1 : 0);
	tv.tv_usec += (tv.tv_usec < 0) ? 1000000 : 0;
	fprintf(stderr, "%06d.%06d ", tv.tv_sec, tv.tv_usec);
}

void wrapLog_vprintf(WRAPLOGL_t logLevel, const char *fmt, va_list args) {
	static int isSetTS = 0;
	if(!isSetTS) {
		printTS();
		isSetTS = 1;
	}
	if(fmt && fmt[0] && (fmt[strlen(fmt)-1] == '\n')) {
		isSetTS = 0;
	}
	vfprintf(stderr, fmt, args);
	fflush(stderr);
}

void wrapLog_printf(WRAPLOGL_t logLevel, const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	wrapLog_vprintf(logLevel, fmt, args);
	va_end(args);
}

void wrapLog_vprintf_ln(WRAPLOGL_t logLevel, const char *fmt, va_list args) {
	printTS();
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	fflush(stderr);
}

void wrapLog_printf_ln(WRAPLOGL_t logLevel, const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	wrapLog_vprintf_ln(logLevel, fmt, args);
	va_end(args);
}
