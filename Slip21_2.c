#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) 
{
    int rank, size, n = 1000;
    int numbers[n], local_sum = 0, global_sum = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        for (int i = 0; i < n; i++) 
        {
            numbers[i] = rand() % 1000;
        }
    }
    MPI_Bcast(numbers, n, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i = rank; i < n; i += size) 
    {
        if (numbers[i] % 2 != 0) {
            local_sum += numbers[i];
        }
    }
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) 
    {
        printf("Sum of all odd numbers: %d\n", global_sum);
    }
    MPI_Finalize();
    
    return 0;
}

/*  mpicc Slip24_1.c -o Slip24_1
mpirun --oversubscribe -np 4 ./Slip24_1
Sum of all odd numbers: 238007  */