#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_threads;

    // Solicita ao usuário o número de threads
    printf("Informe o número de threads: ");
    scanf("%d", &num_threads);

    // Seta a quantidade de threads
    omp_set_num_threads(num_threads);

    // Inicializa a semente para geração de números aleatórios
    srand(time(NULL));

// Início da região paralela
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num(); // Obtém o ID da thread

        // Cada thread gera 10 números aleatórios
        for (int i = 0; i < 10; i++)
        {
            int random_number = rand() % 1001; // Gera um número aleatório entre 0 e 1000
            printf("Thread %d gerou o número: %d\n", thread_id, random_number);
        }
    }
    // Fim da região paralela

    return 0;
}
