#include <omp.h>
#include <stdio.h>

int main()
{
    int x = 10; // Variável compartilhada inicializada com 10

// Início da região paralela
#pragma omp parallel shared(x)
    {
        int thread_id = omp_get_thread_num(); // Cada thread obtém seu próprio ID
        x += thread_id;                       // Todas as threads modificam a mesma instância de x
        printf("Thread %d modificou x para %d\n", thread_id, x);
    }
    // Fim da região paralela

    // Valor de x fora da região paralela
    printf("Valor final de x fora da região paralela: %d\n", x);

    return 0;
}
