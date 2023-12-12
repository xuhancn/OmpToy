#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main (int argc, char **argv)
{
    printf("Hello OmpToy.\n");
    int a[N];

    #pragma omp parallel for
    for (int i = 0; i < N - 1; i++) {
        a[i] = a[i + 1];
    }

    printf("Bye OmpToy.\n");
    system("read -p 'Press Enter to continue...' var");
}