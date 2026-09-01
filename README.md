# cpp-practice

My C++ journey as an autodidact.

## Building

Build files are kept in sibling directories so recursive source-file searches do
not pick up generated C++ files.

From the project root, configure the default build with:

```bash
cmake -S . -B ../cpp-practice-build -G "Unix Makefiles"
```

Configure Debug and Release builds using CLion's bundled Ninja executable:

```bash
cmake -S . -B ../cpp-practice-build-debug \
  -G Ninja \
  -DCMAKE_MAKE_PROGRAM=/Applications/CLion.app/Contents/bin/ninja/mac/aarch64/ninja \
  -DCMAKE_BUILD_TYPE=Debug

cmake -S . -B ../cpp-practice-build-release \
  -G Ninja \
  -DCMAKE_MAKE_PROGRAM=/Applications/CLion.app/Contents/bin/ninja/mac/aarch64/ninja \
  -DCMAKE_BUILD_TYPE=Release
```

Build the desired configuration:

```bash
cmake --build ../cpp-practice-build
cmake --build ../cpp-practice-build-debug
cmake --build ../cpp-practice-build-release
```
