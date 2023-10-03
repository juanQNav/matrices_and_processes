#include <stdio.h>
#include <stdlib.h>

void read(FILE *mat, int *** mat1, int N);
void createMat(int ***mat, int N); 
void freeMat(int **mat, int N);
void printMat(int **mat, int N);


int main(int argc, char* argv[])
{
    FILE *matFileA, *matFileB;
    
    int **matA, **matB;
    int aN, bN;

    if(argc == 3)
    {
        matFileA = fopen(argv[1], "r");
        matFileB = fopen(argv[2], "r");
        if(matFileA == NULL || matFileB == NULL)
        {
            printf("Error apertura del archivo\n");
        }else
        {  
            fscanf(matFileA, "%d", &aN);
            fscanf(matFileB, "%d", &bN);
            createMat(&matA,aN);
            createMat(&matB,bN);
            read(matFileA, &matA, aN);
            read(matFileB, &matB, bN);
            printf("Matriz A\n");
            printMat(matA, aN);
            printf("Matriz B\n");
            printMat(matB, bN);
        }
    }else
    {
        printf("Error numero de argumentos\n");
        return 0;
    }
    
    
    fclose(matFileA);
    freeMat(matA, aN);
    freeMat(matB, bN);
    return 0;
}
void createMat(int ***mat, int N)
{
    *mat = (int **)calloc(N, sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        (*mat)[i] = (int *)malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            (*mat)[i][j] = 0;
    }
}
void freeMat(int **mat, int N)
{
    for (int i = 0; i < N; i++)
    {
        free(mat[i]);
    }
    free(mat);
}
void read(FILE * mat, int *** mat1, int N)
{
    int i = 0;
    while(!feof(mat))
    {
        
        for(int j = 0; j < N; j++)
        {
            fscanf(mat, "%d", &(*mat1)[i][j]);
        }
        i++;
    }
}
void printMat(int **mat, int N)
{
    for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++)
                    printf("%d ", mat[i][j]);
                printf("\n");
            }
}