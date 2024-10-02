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
#ifndef CCT_LOG_H_
#define CCT_LOG_H_

#include <stddef.h>

/**
 * Logs a message with the given format string and arguments.
 *
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
extern void __cct_log(const char* fmt, ...);

/**
 * Logs an info message with the given location, function, line number, format string, and arguments.
 *
 * @param location The location of the log message (e.g. file name).
 * @param func The function name where the log message is being generated.
 * @param line The line number where the log message is being generated.
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
extern void __cct_log_info(const char* location,
                           const char* func,
                           const size_t line,
                           const char* fmt, ...);

/**
 * Logs a warning message with the given location, function, line number, format string, and arguments.
 *
 * @param location The location of the log message (e.g. file name).
 * @param func The function name where the log message is being generated.
 * @param line The line number where the log message is being generated.
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
extern void __cct_log_warning(const char* location,
                              const char* func,
                              const size_t line,
                              const char* fmt, ...);

/**
 * Logs an error message with the given location, function, line number, format string, and arguments, and exits the program.
 *
 * @param location The location of the log message (e.g. file name).
 * @param func The function name where the log message is being generated.
 * @param line The line number where the log message is being generated.
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
extern void __cct_log_error(const char* location,
                            const char* func,
                            const size_t line,
                            const char* fmt, ...);

/**
 * Logs a debug message with the given location, function, line number, format string, and arguments.
 *
 * @param location The location of the log message (e.g. file name).
 * @param func The function name where the log message is being generated.
 * @param line The line number where the log message is being generated.
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
extern void __cct_log_debug(const char* location,
                            const char* func,
                            const size_t line,
                            const char* fmt, ...);

#define __cct_log_args_for_level__(level, fmt, ...)                          \
	do {                                                                     \
		__cct_log_##level(__FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__); \
	} while (0)

#define __cct_log_plain__(fmt, ...)    \
	do {                               \
		__cct_log(fmt, ##__VA_ARGS__); \
	} while (0)

#define __cct_log_info__(fmt, ...)                            \
	do {                                                      \
		__cct_log_args_for_level__(info, fmt, ##__VA_ARGS__); \
	} while (0)

#define __cct_log_warning__(fmt, ...)                            \
	do {                                                         \
		__cct_log_args_for_level__(warning, fmt, ##__VA_ARGS__); \
	} while (0)

#define __cct_log_error__(fmt, ...)                            \
	do {                                                       \
		__cct_log_args_for_level__(error, fmt, ##__VA_ARGS__); \
	} while (0)

#define __cct_log_debug__(fmt, ...)                            \
	do {                                                       \
		__cct_log_args_for_level__(debug, fmt, ##__VA_ARGS__); \
	} while (0)

/**
 * Logs a plain message with the given format string and arguments.
 *
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
#define cct_log __cct_log_plain__

/**
 * Logs an info message with the given format string and arguments.
 *
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
#define cct_info __cct_log_info__

/**
 * Logs a warning message with the given format string and arguments.
 *
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
#define cct_warning __cct_log_warning__

/**
 * Logs an error message with the given format string and arguments, and exits the program.
 *
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
#define cct_error __cct_log_error__

/**
 * Logs a debug message with the given format string and arguments.
 *
 * @param fmt The format string for the log message.
 * @param ... The arguments to be used in the format string.
 */
#define cct_debug __cct_log_debug__

#endif  // CCT_LOG_H_
