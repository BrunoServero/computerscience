#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 65536



int main(int argc, char **argv)
{
	int myid, numprocs;
 int busca = 165207;
	int data[MAXSIZE], *my_data, local_n, i, x, low, high, myresult=0, result=0;
    int *res_data;
	FILE *fp;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	if (myid == 0) {  /* Open input file and initialize data */
		if ((fp = fopen("vetor1.csv","r")) == NULL) {
			printf("Can't open the input file: vetor1.csv\n\n");
			exit(1);
		}
		for(i = 0; i < MAXSIZE; i++) fscanf(fp,"%d\n", &data[i]);
	}
	local_n = MAXSIZE/numprocs;
    my_data = calloc(local_n, sizeof(MPI_INT));
    res_data = calloc(numprocs, sizeof(MPI_INT));
    
	MPI_Scatter(data, local_n, MPI_INT, my_data, local_n, MPI_INT,  0, MPI_COMM_WORLD); 
	
	for(i = 0; i < local_n; i++)
   if(my_data[i] == busca){
		myresult += i;
   }

    MPI_Gather(&myresult, 1, MPI_INT, res_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (myid == 0) {
        for (i = 0; i < numprocs; i++)
            result += res_data[i];
        printf("A posição do vetor é: %d.\n", result);
   }
	MPI_Finalize();
	return 0;
}