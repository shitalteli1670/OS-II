#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 1000 

int main(int argc, char** argv) 
{
    int rank, size, i;
    int local_sum = 0, global_sum = 0;
    int numbers[N];
    
    MPI_Init(&argc, &argv); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int elements_per_process = N / size;
    int start = rank * elements_per_process;
    int end = (rank == size - 1) ? N : start + elements_per_process;
    if (rank == 0) {
        printf("Generating %d random numbers...\n", N);
        srand(42);
        for (i = 0; i < N; i++) 
        {
            numbers[i] = rand() % 100;
        }
    }
    MPI_Bcast(numbers, N, MPI_INT, 0, MPI_COMM_WORLD);
    for (i = start; i < end; i++) 
    {
        local_sum += numbers[i];
    }
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) 
    {
        double average = (double)global_sum / N;
        printf("Total Sum: %d\n", global_sum);
        printf("Average: %.2f\n", average);
    }

    MPI_Finalize();
    return 0;
}
