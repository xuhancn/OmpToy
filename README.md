# OmpToy

## Guide:
```cmd
xu@xu-21HW:~/github$ git clone https://github.com/xuhancn/OmpToy.git
Cloning into 'OmpToy'...
remote: Enumerating objects: 16, done.
remote: Counting objects: 100% (16/16), done.
remote: Compressing objects: 100% (8/8), done.
remote: Total 16 (delta 2), reused 13 (delta 2), pack-reused 0
Receiving objects: 100% (16/16), 8.95 KiB | 4.48 MiB/s, done.
Resolving deltas: 100% (2/2), done.
xu@xu-21HW:~/github$ cd OmpToy/
xu@xu-21HW:~/github/OmpToy$ mkdir build
xu@xu-21HW:~/github/OmpToy$ cd build/
xu@xu-21HW:~/github/OmpToy/build$ cmake ..
-- The C compiler identification is GNU 12.3.0
-- The CXX compiler identification is GNU 12.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Check OMP with lib /usr/lib/gcc/x86_64-linux-gnu/12/libgomp.so and flags -fopenmp -v
-- Check OMP with lib /usr/lib/gcc/x86_64-linux-gnu/12/libgomp.so and flags -fopenmp -v
CMake Warning (dev) at /usr/share/cmake-3.25/Modules/FindPackageHandleStandardArgs.cmake:438 (message):
  The package name passed to `find_package_handle_standard_args` (OpenMP_C)
  does not match the name of the calling package (OMP).  This can lead to
  problems in calling code that expects `find_package` result variables
  (e.g., `_FOUND`) to follow a certain pattern.
Call Stack (most recent call first):
  cmake/Modules/FindOMP.cmake:590 (find_package_handle_standard_args)
  CMakeLists.txt:14 (find_package)
This warning is for project developers.  Use -Wno-dev to suppress it.

-- Found OpenMP_C: -fopenmp (found version "4.5")
CMake Warning (dev) at /usr/share/cmake-3.25/Modules/FindPackageHandleStandardArgs.cmake:438 (message):
  The package name passed to `find_package_handle_standard_args` (OpenMP_CXX)
  does not match the name of the calling package (OMP).  This can lead to
  problems in calling code that expects `find_package` result variables
  (e.g., `_FOUND`) to follow a certain pattern.
Call Stack (most recent call first):
  cmake/Modules/FindOMP.cmake:590 (find_package_handle_standard_args)
  CMakeLists.txt:14 (find_package)
This warning is for project developers.  Use -Wno-dev to suppress it.

-- Found OpenMP_CXX: -fopenmp (found version "4.5")
CMake Warning (dev) at /usr/share/cmake-3.25/Modules/FindPackageHandleStandardArgs.cmake:438 (message):
  The package name passed to `find_package_handle_standard_args` (OpenMP)
  does not match the name of the calling package (OMP).  This can lead to
  problems in calling code that expects `find_package` result variables
  (e.g., `_FOUND`) to follow a certain pattern.
Call Stack (most recent call first):
  cmake/Modules/FindOMP.cmake:634 (find_package_handle_standard_args)
  CMakeLists.txt:14 (find_package)
This warning is for project developers.  Use -Wno-dev to suppress it.

-- Found OpenMP: TRUE (found version "4.5")
-- Configuring done
-- Generating done
-- Build files have been written to: /home/xu/github/OmpToy/build
xu@xu-21HW:~/github/OmpToy/build$ make
[ 50%] Building CXX object CMakeFiles/OmpToy.dir/src/main.cpp.o
[100%] Linking CXX executable OmpToy
[100%] Built target OmpToy
xu@xu-21HW:~/github/OmpToy/build$ ldd OmpToy
        linux-vdso.so.1 (0x00007ffe3f1fe000)
        libgomp.so.1 => /lib/x86_64-linux-gnu/libgomp.so.1 (0x00007fa678422000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fa678200000)
        /lib64/ld-linux-x86-64.so.2 (0x00007fa67848d000)
xu@xu-21HW:~/github/OmpToy/build$ ./OmpToy
Hello OmpToy.
Bye OmpToy.
xu@xu-21HW:~/github/OmpToy/build$
```