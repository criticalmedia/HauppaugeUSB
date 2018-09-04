#ifndef __LOG_H_
#define __LOG_H_

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	WRAPLOGL_ERROR,
	WRAPLOGL_WARN,
	WRAPLOGL_DEBUG
} WRAPLOGL_t;

void wrapLog_vprintf(WRAPLOGL_t logLevel, const char *fmt, va_list args);
void wrapLog_printf(WRAPLOGL_t logLevel, const char *fmt, ...);
void wrapLog_vprintf_ln(WRAPLOGL_t logLevel, const char *fmt, va_list args);
void wrapLog_printf_ln(WRAPLOGL_t logLevel, const char *fmt, ...);

#define WRAPLOGV wrapLog_vprintf_ln
#define WRAPLOG wrapLog_printf_ln

#define wrapLogError(M, ...) WRAPLOG(WRAPLOGL_ERROR, M, ##__VA_ARGS__)
#define wrapLogWarn(M, ...) WRAPLOG(WRAPLOGL_WARN, M, ##__VA_ARGS__)
#define wrapLogDebug(M, ...) WRAPLOG(WRAPLOGL_DEBUG, M, ##__VA_ARGS__)

#define _DbgLogError(M, ...) wrapLog_printf(WRAPLOGL_ERROR, M, ##__VA_ARGS__)
#define _DbgLogWarn(M, ...) wrapLog_printf(WRAPLOGL_ERROR, M, ##__VA_ARGS__)
#define _DbgLogInfo(M, ...) wrapLog_printf(WRAPLOGL_DEBUG, M, ##__VA_ARGS__)
#define _DbgLogRelease(M, ...) wrapLog_printf(WRAPLOGL_DEBUG, M, ##__VA_ARGS__)
#define _DbgLogTrace(M, ...) wrapLog_printf(WRAPLOGL_DEBUG, M, ##__VA_ARGS__)
#define _DbgLogMicroTrace(M, ...) wrapLog_printf(WRAPLOGL_DEBUG, M, ##__VA_ARGS__)

#define DbgLogError(V) _DbgLogError V
#define DbgLogWarn(V) _DbgLogWarn V
#define DbgLogInfo(V) _DbgLogInfo V
#define DbgLogRelease(V) _DbgLogRelease V
#define DbgLogTrace(V) _DbgLogTrace V
#define DbgLogMicroTrace(V) _DbgLogMicroTrace V

#define DbgLog DbgLogInfo

#ifdef __cplusplus
}
#endif

#endif
