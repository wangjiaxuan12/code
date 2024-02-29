#include <iostream>
#include <math.h>
const int MAX = 100;

int input_matrix(int a, int b, int M[MAX][MAX])
{
    std::cout << "input matrix value, must " << a << " row, " << b << " column" << std::endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            std::cin >> M[i][j];
        }
    }
    return 0;
}

int output_matrix(int a, int b, int M[MAX][MAX])
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

int multi_matrix(int n, int m, int a, int b, int A[MAX][MAX], int B[MAX][MAX], int ret[MAX][MAX])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < m; k++)
            {
                ret[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    output_matrix(n, b, ret);
}

int main()
{
    int x;

    std::cout << "must input 2" << std::endl;
    while (std::cin >> x)
    {
        int n, m, a, b;
        int matA[MAX][MAX];
        int matB[MAX][MAX];
        int ret[MAX][MAX];
        std::cout << "input first matrix row and column, n x m" << std::endl;
        std::cin >> n >> m;
        input_matrix(n, m, matA);
        output_matrix(n, m, matA);

        std::cout << "input second matrix, row and column, a x b" << std::endl;
        std::cin >> a >> b;
        input_matrix(a, b, matB);
        output_matrix(a, b, matB);
        if (m != a)
        {
            std::cout << "NULL" << std::endl;
            std::cout << "input repeat" << std::endl;
        }
        else
        {
            multi_matrix(n, m, a, b, matA, matB, ret);
        }
    }
    return 0;
}
