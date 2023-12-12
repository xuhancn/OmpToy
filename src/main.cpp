#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#include <unistd.h>
#endif

void* open_iomp_library() {
  void* handle = NULL;
#ifdef _WIN32
  // ToDo: need confirm search path:
  return NULL;

  handle =
      LoadLibraryExA("libiomp5md.dll", NULL, LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR);
#else
  handle = dlopen(NULL, RTLD_NOW | RTLD_GLOBAL);
#endif
  return handle;
}

void* get_func_from_library(void* handle, const char* name) {
#ifdef _WIN32
  return GetProcAddress((HMODULE)handle, name);
#else
  return dlsym(handle, name);
#endif
}


#define N 1000

int main (int argc, char **argv)
{
    printf("Hello OmpToy.\n");

    void* handle = open_iomp_library();

    int a[N];

    #pragma omp parallel for
    for (int i = 0; i < N - 1; i++) {
        a[i] = a[i + 1];
    }

    printf("Bye OmpToy.\n");
    system("read -p 'Press Enter to continue...' var");
}