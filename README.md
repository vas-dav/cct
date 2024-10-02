# cct (Common C Tools)

This is a collection of useful and common C tools that can be installed and used in any C project using C99 or higher. The goal of this project is to provide a set of reusable and well-tested functions that can be easily integrated into various C projects.

## Library Structure

The CCT library is compiled into a static library, which includes several header files. The main header files are:

- [log.h](./log.h): Provides logging functionality with customizable log levels and output streams

## Installation

To install the CCT library, follow these steps:

1. Clone the repository:

```bash
git clone https://github.com/vas-dav/cct.git
```

2. Build the library:

```bash
cd cct && make
```

3. Install the library:

```bash
make install
```

## Using the library

> This example is trivial only created to get started.
> More diverse use cases and documentation is available in [docs](./docs/).

Once the library is installed, it can be used in any source file as follows:

```c
#include <cct/log.h>

int main(int argc, char **argv) {
    cct_log("Hello from CCT!");
    return 0;
}
```

And compiled inlcuding the library:

```bash
<your_c_compiler> hello.c -lcct
```

## Documentation

All of the documentation can be found [here](./docs/).
