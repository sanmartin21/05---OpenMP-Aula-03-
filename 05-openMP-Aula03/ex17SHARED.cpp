#include <omp.h>
#include <stdio.h>

int main()
{
    int x = 10; // Variável compartilhada
    int y = 20; // Variável compartilhada

#pragma omp parallel default(shared)
    {
        int thread_id = omp_get_thread_num(); // Cada thread tem sua própria cópia de thread_id
        x += thread_id;                       // Todas as threads modificam a mesma instância de x
        y += thread_id;                       // Todas as threads modificam a mesma instância de y
        printf("Thread %d, x: %d, y: %d\n", thread_id, x, y);
    }

    return 0;
}
