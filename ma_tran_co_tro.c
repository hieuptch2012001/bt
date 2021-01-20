#include <stdio.h>
#include<math.h>

void NhapMatran(float* pMaTrix, int row, int col);
void CongMaTran(float* pMtA, float* pMtB,int rowA, int colA, int rowB, int colB);
void TruMaTran(float* pMtA, float* pMtB, int rowA, int colA, int rowB, int colB);
void NhanMaTran(float* pMt1, float* pMt2, int row1, int col1, int row2, int col2);
void InputMatrixRC(float* pDiMatrix); // Input Row number or Column number of a matrix

int main()
{
    int i,j,k;
    float matrixA [100];
    float matrixB [100];
    float rowMatrixA = 0;
    float colMatrixA = 0;
    float rowMatrixB = 0;
    float colMatrixB = 0;
    
    int checkSumMatrixAAndMatrixB = 0;
    int checkSubMatrixAAndMatrixB = 0;
    int checkMulMatrixAAndMatrixB = 0;
    int checkMulMatrixBAndMatrixA = 0;

    int continueProgram = 0;
    int subprogram = 0;
    int pheptinh = 0;  
      
    do    
    {   
        system("clear");
        printf("\n Input Matrix A's row number: "); 
        InputMatrixRC(&rowMatrixA);                   //Nhap so dong ma tran A 
        printf(" Input Matrix A's col number: ");
        InputMatrixRC(&colMatrixA);                   // Nhap so cot ma tran A 
        printf("\n Input Matrix A's elements: \n");
        NhapMatran(matrixA, rowMatrixA, colMatrixA);  //Nhap phan tu ma tran A
    
        printf("\n Input Matrix B's row number: "); 
        InputMatrixRC(&rowMatrixB);                  // Nhap so dong ma tran B  
        printf(" Input Matrix B's col number: ");
        InputMatrixRC(&colMatrixB);                  // Nhap so cot ma tran B  
        printf("\n Input Matrix B's elements: \n");   
        NhapMatran(matrixB, rowMatrixB, colMatrixB); // Nhap phan tu ma tran B
        if(rowMatrixA == colMatrixA && rowMatrixB == colMatrixB && rowMatrixA == rowMatrixB)
        {
            checkSumMatrixAAndMatrixB = 1;
            checkSubMatrixAAndMatrixB = 1;
            checkMulMatrixAAndMatrixB = 1;
            checkMulMatrixBAndMatrixA = 1;
        }
        else if(rowMatrixA == rowMatrixB && colMatrixA == colMatrixB)
        {
            checkSumMatrixAAndMatrixB = 1;
            checkSubMatrixAAndMatrixB = 1;
        }
        else if(rowMatrixA == colMatrixB)
        {
            checkMulMatrixBAndMatrixA = 1;
        }
        else if(rowMatrixB == colMatrixA)
        {
            checkMulMatrixAAndMatrixB = 1;
        }
        else
        {
            checkSumMatrixAAndMatrixB = 0;
            checkSubMatrixAAndMatrixB = 0;
            checkMulMatrixAAndMatrixB = 0;
            checkMulMatrixBAndMatrixA = 0;
        }
        
        
        do
        {   
            system("clear");
            printf("Phep tinh cho ma hai ma tran: \n");
            if(checkSumMatrixAAndMatrixB)
            {
                printf("*Press 1 to display The matrix product of A+B: \n");

            }
            if(checkSubMatrixAAndMatrixB)
            {               
                printf("*Press 2 to display The matrix product of A-B: \n");
            }
            if(checkMulMatrixAAndMatrixB)
            {
                printf("*Press 3 to display The matrix display of A*B: \n");
            }
            if(checkMulMatrixBAndMatrixA)
            {
                printf("*Press 4 to display The matrix product of B*A: \n");
            }else
            {
                printf("\nThere is not any a matrix product of A+B,A-B,A\\B,B\\A.");
            }
            printf("\n Choose your option: ");
            scanf("%d", &pheptinh);
            if (pheptinh == 1)
            {
                printf("\nThe matrix product of A+B: \n");
                CongMaTran(matrixA, matrixB, rowMatrixA, colMatrixA, rowMatrixB, colMatrixB);
            }else if (pheptinh == 2)
            {
                printf("*\nThe matrix product of A-B: \n");
                TruMaTran(matrixA, matrixB, rowMatrixA, colMatrixA, rowMatrixB, colMatrixB);
            }else if (pheptinh == 3)
            {
                printf("*The matrix product of A*B: \n");
                NhanMaTran(matrixA, matrixB, rowMatrixA, colMatrixA, rowMatrixB, colMatrixB);
            }else if (pheptinh == 4)
            {
                printf("*The matrix product of B*A: \n");
                NhanMaTran(matrixB, matrixA, rowMatrixB, colMatrixB, rowMatrixA, colMatrixA);
            }else
            {
                printf("--------------------------------------------------------------------");
            }
            printf("\n Press 1 to contine or 0 for Exit\n");
            printf("Nhap : ");
            scanf("%d", &subprogram);
        } while (subprogram == 1);
        


        printf("\nInput 0 to exit the program or 1 to Input another matrix \n");
        printf("Nhap : ");
        
        scanf("%d", &continueProgram);
        
    }while(continueProgram == 1);
    
    return 0;
}

void InputMatrixRC(float* pDiMatrix)
{   
    int checkPosRCMatrix = 0;
    int checkIntRCMatrix = 0;
    do
    {
        scanf("%f", pDiMatrix);
        
        if ((*pDiMatrix > 0) && (*pDiMatrix - (int)*pDiMatrix == 0))
        {
            checkPosRCMatrix = 1;
            checkIntRCMatrix = 1;
        }
        else if(*pDiMatrix <= 0)
        {
            printf("\nA negative number.");
            printf("\n Input a positive integer for the dimension of the Matrix:");
            checkPosRCMatrix = 0;
        }
        else if(*pDiMatrix - (int)*pDiMatrix != 0)
        {
            printf("\n A real number.");
            printf("Input a positive integer for the dimension of the Matrix: ");
            checkIntRCMatrix = 0;
        }       
    }while (!checkPosRCMatrix || !checkIntRCMatrix);
}

void NhapMatran(float* pMaTrix, int row, int col)
{
    for ( int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]:", i+1, j+1);
            scanf("%f", &pMaTrix[col*i + j]);
        }
    }
}
void CongMaTran(float* pMtA, float* pMtB,int rowA, int colA, int rowB, int colB)
{   
    float sum = 0;
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            sum = pMtA[colA*i + j] + pMtB[colB*i +j];
            printf("%.f \t", sum);
        }
        printf("\n");
    }
}
void TruMaTran(float* pMtA, float* pMtB,int rowA, int colA, int rowB, int colB)
{
    float sub = 0;
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < colA; j++)
        {
            sub = pMtA[colA*i + j] - pMtB[colB*i +j];
            printf("%.f \t", sub);
        }
        printf("\n");
    }
}
void NhanMaTran(float* pMt1, float* pMt2, int row1, int col1, int row2, int col2)
{   float mul = 0;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            for (int k = 0; k < row1 ; k++)
            {
                mul += pMt1[row1*i + k] + pMt2[j + k*col2];
            }
            printf("%.f \t", mul);
        }
        printf("\n");
    }
    
}