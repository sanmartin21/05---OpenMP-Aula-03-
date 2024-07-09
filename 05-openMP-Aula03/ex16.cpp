#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_threads;
    int start_range, end_range;
    int total_sum = 0; // Variável para armazenar a soma total dos números gerados

    // Solicita ao usuário o número de threads
    printf("Informe o número de threads: ");
    scanf("%d", &num_threads);

    // Solicita ao usuário os valores de início e fim do intervalo
    printf("Informe o valor de início do intervalo: ");
    scanf("%d", &start_range);
    printf("Informe o valor de fim do intervalo: ");
    scanf("%d", &end_range);

    // Verifica se o intervalo é válido
    if (start_range >= end_range)
    {
        printf("Intervalo inválido. O valor de início deve ser menor que o valor de fim.\n");
        return 1;
    }

    // Seta a quantidade de threads
    omp_set_num_threads(num_threads);

    // Inicializa a semente para geração de números aleatórios
    srand(time(NULL));

// Início da região paralela com redução para a variável total_sum
#pragma omp parallel reduction(+ : total_sum)
    {
        int thread_id = omp_get_thread_num(); // Obtém o ID da thread

        // Cada thread gera 10 números aleatórios dentro do intervalo especificado
        for (int i = 0; i < 10; i++)
        {
            int random_number = start_range + rand() % (end_range - start_range + 1); // Gera um número aleatório dentro do intervalo
            printf("Thread %d gerou o número: %d\n", thread_id, random_number);
            total_sum += random_number; // Adiciona o número gerado à soma total
        }
    }
    // Fim da região paralela

    // Exibe a soma total dos números gerados
    printf("A soma total dos números gerados é: %d\n", total_sum);

    return 0;
}
