#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#define ARRAY_SIZE 1000
int main(int argc, char *argv[]) 
{
    int rank, size;
    int local_array[ARRAY_SIZE];
    int local_min, global_min;
    int i;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    srand(time(NULL) + rank);
    for (i = 0; i < ARRAY_SIZE; i++) 
    {
        local_array[i] = rand();
    }
    local_min = local_array[0];
    for (i = 1; i < ARRAY_SIZE; i++) 
    {
        if (local_array[i] < local_min) 
        {
            local_min = local_array[i];
        }
    }
    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    if (rank == 0) 
    {
        printf("Global minimum: %d\n", global_min);
    }
    MPI_Finalize();
    return 0;
}

/*    mpicc Slip30_2.c -o Slip30_2
mpirun --oversubscribe -np 4 ./Slip30_2
Global minimum: 416305   */