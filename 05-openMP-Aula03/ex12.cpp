#include <omp.h>
#include <stdio.h>

int main()
{
    int sum = 0; // Variável compartilhada inicializada com zero

// Início da região paralela com redução
#pragma omp parallel reduction(+ : sum) num_threads(4)
    {
        int thread_id = omp_get_thread_num(); // Identificador da thread atual
        int value = thread_id * 5;            // Valor a ser adicionado a sum por cada thread

        // Cada thread adiciona seu valor a sum
        sum += value;
    }
    // Fim da região paralela

    // Imprime o resultado da redução
    printf("Resultado da redução: %d\n", sum);

    return 0;
}
