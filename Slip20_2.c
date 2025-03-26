#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

#define N 1000

int main(int argc, char *argv[]) {
    int rank, size;
    int arr[N], local_max, global_max;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    srand(time(NULL) + rank); // Seed random number generator uniquely for each process

    int local_array_size = N / size;
    int local_array[local_array_size];

    // Process 0 initializes the array with random numbers
    if (rank == 0) {
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 1000; // Generate random numbers between 0-999
        }
    }

    // Scatter the array among processes
    MPI_Scatter(arr, local_array_size, MPI_INT, local_array, local_array_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Find the local maximum
    local_max = local_array[0];
    for (int i = 1; i < local_array_size; i++) {
        if (local_array[i] > local_max) {
            local_max = local_array[i];
        }
    }

    // Reduce all local max values to find the global maximum at process 0
    MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    // Process 0 prints the maximum value
    if (rank == 0) {
        printf("The maximum value is %d\n", global_max);
    }

    MPI_Finalize();
    return 0;
}
