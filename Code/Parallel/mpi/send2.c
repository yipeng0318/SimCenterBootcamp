#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv) {
  int procID, numP;
  MPI_Status status;

  MPI_Init( &argc, &argv );
  MPI_Comm_size( MPI_COMM_WORLD, &numP );
  MPI_Comm_rank( MPI_COMM_WORLD, &procID );

  if (procID == 0) {
    int buf[2] = {12345, 67890};
    MPI_Send(&buf, 2, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&buf, 2, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
    printf("%d Received %d %d\n", procID, buf[0], buf[1]);
  } else if (procID == 1) {
    int buf[2] = {67890, 12345};
    MPI_Send(&buf, 2, MPI_INT, 0, 0, MPI_COMM_WORLD);
    MPI_Recv(&buf, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    printf("%d Received %d %d\n", procID, buf[0], buf[1]);
  }


  MPI_Finalize();
  return 0;

}
