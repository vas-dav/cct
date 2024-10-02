# CCT Logging API

This document provides a comprehensive overview of the logging API offered by the CCT library. The API encompasses various logging functions that facilitate the logging of messages at different severity levels.

## Macros

### #inlcude <cct/log.h>

### `cct_log`

Logs a plain message utilizing the specified format string and arguments.

- **Parameters:**
  - `fmt`: The format string for the log message.
  - `...`: The arguments to be utilized in the format string.

### `cct_info`

Logs an informational message utilizing the specified format string and arguments. This macro additionally traces the log line, function name, and file name.

- **Parameters:**
  - `fmt`: The format string for the log message.
  - `...`: The arguments to be utilized in the format string.

### `cct_warning`

Logs a warning message utilizing the specified format string and arguments. This macro also traces the log line, function name, and file name.

- **Parameters:**
  - `fmt`: The format string for the log message.
  - `...`: The arguments to be utilized in the format string.

### `cct_error`

Logs an error message utilizing the specified format string and arguments, and subsequently terminates the program. This macro traces the log line, function name, and file name.

- **Parameters:**
  - `fmt`: The format string for the log message.
  - `...`: The arguments to be utilized in the format string.

### `cct_debug`

Logs a debug message utilizing the specified format string and arguments. This macro also traces the log line, function name, and file name.

- **Parameters:**
  - `fmt`: The format string for the log message.
  - `...`: The arguments to be utilized in the format string.

## Features & Limitations

- All logging macros, with the exception of `cct_log`, will trace the log line, function name, and file name.
- The total length of the message for any of the logging macros must not exceed 256 bytes.

## Usage

Check example in [here](./main.c).

## Conclusion

The CCT Logging API provides a straightforward and effective mechanism for logging messages of differing severity levels. By employing these macros, developers can efficiently monitor the execution flow of their applications and manage errors in a systematic manner.
