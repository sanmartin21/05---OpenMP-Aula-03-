#include <omp.h>
#include <stdio.h>

int main()
{
    int condition = 1; // Variável que determina se a região paralela será executada

// Início da região paralela condicional
#pragma omp parallel if (condition)
    {
        int thread_id = omp_get_thread_num(); // Identificador da thread atual
        printf("Hello from thread %d\n", thread_id);
    }
    // Fim da região paralela

    return 0;
}
