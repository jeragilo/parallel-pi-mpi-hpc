#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rank, size;
    long long int num_steps = 0, i;
    double step, x, sum = 0.0, global_sum = 0.0;

    MPI_Init(&argc, &argv);                 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);   
    MPI_Comm_size(MPI_COMM_WORLD, &size);   

    if (rank == 0) {
        if (argc != 2) {
            printf("You must pass a single numeric value\n");
            printf("The value should be 100M or higher\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        num_steps = atoll(argv[1]);
    }

    // Broadcast num_steps from rank 0 to all processes
    MPI_Bcast(&num_steps, 1, MPI_LONG_LONG_INT, 0, MPI_COMM_WORLD);

    step = 1.0 / (double) num_steps;

    long long int chunk = num_steps / size;
    long long int start = rank * chunk;
    long long int end = (rank == size - 1) ? num_steps : start + chunk;

    double t_start = MPI_Wtime();

    for (i = start; i < end; i++) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    MPI_Reduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    double t_end = MPI_Wtime();

    if (rank == 0) {
        double pi = step * global_sum;
        printf("PI is approx %.50f\n", pi);
        printf("Time elapsed: %.6f seconds\n", t_end - t_start);
    }

    MPI_Finalize();
    return 0;
}
