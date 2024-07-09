#include <omp.h>
#include <stdio.h>

int main()
{
    int i;
    int n = 20;

#pragma omp parallel for schedule(static, 4)
    for (i = 0; i < n; i++)
    {
        int thread_id = omp_get_thread_num();
        printf("Thread %d executa iteração %d\n", thread_id, i);
    }

    return 0;
}
