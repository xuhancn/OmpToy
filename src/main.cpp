#include <stdio.h>
#include <stdlib.h>
#include <mutex>
#include <atomic>

#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#include <unistd.h>
#endif

typedef void* kmp_affinity_mask_t;
typedef void (*kmp_create_affinity_mask_p)(kmp_affinity_mask_t*);
typedef int (*kmp_set_affinity_mask_proc_p)(int, kmp_affinity_mask_t*);
typedef int (*kmp_set_affinity_p)(kmp_affinity_mask_t*);
typedef void (*kmp_destroy_affinity_mask_p)(kmp_affinity_mask_t*);
typedef int (*kmp_get_affinity_p)(kmp_affinity_mask_t*);
typedef int (*kmp_get_affinity_max_proc_p)();

// IOMP symbol
kmp_create_affinity_mask_p kmp_create_affinity_mask_ext;
kmp_set_affinity_mask_proc_p kmp_set_affinity_mask_proc_ext;
kmp_set_affinity_p kmp_set_affinity_ext;
kmp_destroy_affinity_mask_p kmp_destroy_affinity_mask_ext;
kmp_get_affinity_p kmp_get_affinity_ext;
kmp_get_affinity_max_proc_p kmp_get_affinity_max_proc_ext;

// IOMP symbol loading control flag
std::once_flag
    iomp_symbol_loading_call_once_flag; // call_once_flag to ensure the iomp
                                        // symbol loaded once globally
std::atomic<bool> iomp_symbol_loaded{false};

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


void loading_iomp_symbol() {
  void* handle = open_iomp_library();
  if (handle == NULL ||
      get_func_from_library(handle, "kmp_create_affinity_mask") == NULL ||
      get_func_from_library(handle, "kmp_set_affinity_mask_proc") == NULL ||
      get_func_from_library(handle, "kmp_set_affinity") == NULL ||
      get_func_from_library(handle, "kmp_get_affinity") == NULL ||
      get_func_from_library(handle, "kmp_destroy_affinity_mask") == NULL ||
      get_func_from_library(handle, "kmp_get_affinity_max_proc") == NULL) {
    iomp_symbol_loaded = false;
    return;
  }

  kmp_create_affinity_mask_ext =
      (kmp_create_affinity_mask_p)get_func_from_library(
          handle, "kmp_create_affinity_mask");
  kmp_set_affinity_mask_proc_ext =
      (kmp_set_affinity_mask_proc_p)get_func_from_library(
          handle, "kmp_set_affinity_mask_proc");
  kmp_set_affinity_ext =
      (kmp_set_affinity_p)get_func_from_library(handle, "kmp_set_affinity");
  kmp_get_affinity_ext =
      (kmp_get_affinity_p)get_func_from_library(handle, "kmp_get_affinity");
  kmp_destroy_affinity_mask_ext =
      (kmp_destroy_affinity_mask_p)get_func_from_library(
          handle, "kmp_destroy_affinity_mask");
  kmp_get_affinity_max_proc_ext =
      (kmp_get_affinity_max_proc_p)get_func_from_library(
          handle, "kmp_get_affinity_max_proc");

  iomp_symbol_loaded = true;
  return;
}

#define N 1000

int main (int argc, char **argv)
{
    printf("Hello OmpToy.\n");

    loading_iomp_symbol();

    int a[N];

    #pragma omp parallel for
    for (int i = 0; i < N - 1; i++) {
        a[i] = a[i + 1];
    }

    printf("Bye OmpToy.\n");
    system("read -p 'Press Enter to continue...' var");
}