/*
MIT License

Copyright (c) 2022 Vasily Davydov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

---------------------------------------------------------------------------
MIT License Comment Section

The MIT License is a permissive open source license that allows you to
use, modify, distribute, and sublicense the software under certain conditions.
It is important to read and understand the full license text below.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

---------------------------------------------------------------------------

*/

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "log.h"

// Different log levels that can be used to categorize log messages
enum {
	LEVEL_INFO,
	LEVEL_DEBUG,
	LEVEL_WARNING,
	LEVEL_ERROR
};

// An array of strings that correspond to each log level
static const char* logLevels[] = {
    "INFO",
    "WARNING",
    "DEBUG",
    "ERROR"};

// The maximum buffer capacity for log messages
#define LOG_BUFFER_MAX_CAP 256

// Emit log message with additional checks
#define _LOG_STREAMOUT(message, message_length) \
	assert(message_length > 0);                 \
	printf("%.*s", message_length, message)

static void __create_log_line(const char* _status,
                              const char* _location,
                              const char* _func,
                              const size_t _line,
                              const char* _fmt, ...) {
	va_list args;
	va_start(args, _fmt);
	char message[LOG_BUFFER_MAX_CAP] = {0};
	int message_len = vsnprintf(message, LOG_BUFFER_MAX_CAP, _fmt, args);
	va_end(args);
	char buffer[LOG_BUFFER_MAX_CAP] = {0};
	int buffer_len = snprintf(buffer, LOG_BUFFER_MAX_CAP,
	                          "[%s] %s:%zu:%s %.*s\n",
	                          _status,
	                          _location,
	                          _line,
	                          _func,
	                          message_len,
	                          message);
	_LOG_STREAMOUT(buffer, buffer_len);
}

static void __create_log_line_simple(const char* _status,
                                     const char* _fmt, ...) {
	va_list args;
	va_start(args, _fmt);
	char message[LOG_BUFFER_MAX_CAP] = {0};
	int message_len = vsnprintf(message, LOG_BUFFER_MAX_CAP, _fmt, args);
	va_end(args);
	char buffer[LOG_BUFFER_MAX_CAP] = {0};

	int buffer_len = 0;
	if (_status) {
		buffer_len = snprintf(buffer, LOG_BUFFER_MAX_CAP,
		                      "[%s] %.*s\n",
		                      _status,
		                      message_len,
		                      message);
	} else {
		buffer_len = snprintf(buffer, LOG_BUFFER_MAX_CAP,
		                      "%.*s\n",
		                      message_len,
		                      message);
	}
	_LOG_STREAMOUT(buffer, buffer_len);
}

void __cct_log(const char* _fmt, ...) {
	va_list args;
	va_start(args, _fmt);
	__create_log_line_simple(NULL, _fmt, args);
	va_end(args);
}

#define LOG_LINE_VA_LIST_EXPANSION_MACRO(level)                               \
	do {                                                                      \
		va_list args;                                                         \
		va_start(args, fmt);                                                  \
		__create_log_line(logLevels[level], location, func, line, fmt, args); \
		va_end(args);                                                         \
	} while (0)

void __cct_log_info(const char* location,
                    const char* func,
                    size_t line,
                    const char* fmt, ...) {
	LOG_LINE_VA_LIST_EXPANSION_MACRO(LEVEL_INFO);
}

void __cct_log_warning(const char* location,
                       const char* func,
                       size_t line,
                       const char* fmt, ...) {
	LOG_LINE_VA_LIST_EXPANSION_MACRO(LEVEL_WARNING);
}

void __cct_log_error(const char* location,
                     const char* func,
                     size_t line,
                     const char* fmt, ...) {
	LOG_LINE_VA_LIST_EXPANSION_MACRO(LEVEL_ERROR);
	const int _exit_code = EXIT_FAILURE;
	exit(_exit_code);
}

void __cct_log_debug(const char* location,
                     const char* func,
                     size_t line,
                     const char* fmt, ...) {
	LOG_LINE_VA_LIST_EXPANSION_MACRO(LEVEL_DEBUG);
}