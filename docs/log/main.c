#include <cct/log.h>

int main() {
    // Log a plain message
    cct_log("This is a plain log message.\n");

    // Log an info message
    cct_info("The value of pi is approximately %f.\n", 3.14159);

    // Log a warning message
    cct_warning("The system is running low on memory.\n");

    // Log an error message and exit the program
    cct_error("The system has encountered a fatal error.\n");

    // Log a debug message
    cct_debug("Unreachable code");

    return 0;
}
