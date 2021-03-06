// Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main(int argc, char **argv)
{
	int rank, size, tag = 1;
	int senddata, recvdata;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0) {
		senddata = 9999;
		MPI_Send(&senddata, 1, MPI_INT,
			1, tag, MPI_COMM_WORLD);
		printf("I sent data = %d\n", senddata);
	}
	if (rank == 1) {
		MPI_Recv(&recvdata, 1, MPI_INT,
			0, tag, MPI_COMM_WORLD, &status);
		printf("I recieved data = %d\n", recvdata);
	}

	MPI_Finalize();
    return 0;
}

