/*****************************************/
// program to sum of elements in an array using MPI_Reduce()

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#define ARRAY_SIZE 1000
int main(int argc, char *argv[]) 
{
    int rank, size;
    int local_array[ARRAY_SIZE];
    int local_sum = 0;
    int global_sum = 0;
    int i;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    srand(time(NULL) + rank);
    for (i = 0; i < ARRAY_SIZE; i++) 
    {
        local_array[i] = rand() % 1000;
    }
    for (i = 0; i < ARRAY_SIZE; i++) 
    {
        local_sum += local_array[i];
    }
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) 
    {
        printf("Global sum of 1000 random numbers: %d\n", global_sum);
    }
    MPI_Finalize();
    return 0;
}

/*  mpicc Slip30_2.c -o Slip28_2
mpirun --oversubscribe -np 4 ./Slip28_2
Global minimum: 998348  */