# CPP Template

## Dependencies
Make sure these dependencies are in your PATH. You can check by using `which {command}`. For example `which ninja` should return the path to your currently install version of ninja. You can usually check the version of the installed binary using `{command} --version`. For example `g++ --version`.
* [Cmake](https://cmake.org/) 3.1
* C++17 Compiler ([GCC](https://www.gnu.org/software/gcc/) 7 | [Clang](https://clang.llvm.org/) 5)
* [Ninja](https://ninja-build.org/)
* A threading library ([supported libraries](https://cmake.org/cmake/help/latest/module/FindThreads.html))

## Getting the code
```sh
git clone git@github.com:FallingSnow/CPSC471.git
cd CPSC471
```

## Compiling

```sh
$ mkdir -p build && cd build    # Create a build directory
$ cmake -GNinja ../             # Generate build files
$ ninja                         # Compile
```
