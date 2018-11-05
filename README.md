# CPP Template

## Dependencies
Make sure these dependencies are in your PATH. You can check by using `which {command}`. For example `which ninja` should return the path to your currently install version of ninja. You can usually check the version of the installed binary using `{command} --version`. For example `g++ --version`.
#### Binarys
* Cmake 3.1
* C++17 Compiler (GCC 7 | Clang 5)
* Ninja
* libpthread

## Compiling

```bash
$ mkdir -p build && cd build    # Create a build directory
$ cmake -GNinja ../             # Generate build files
$ ninja                         # Compile
```
