#include <stdio.h>
//#include <math.h>
#define dim 11


double a[11][11] = {{0.00583690322580645,-0.00422400000000000,0,0,0,0,0,0,0,0,0},
{-0.00422400000000000,0.00522400000000000,-0.00100000000000000,0,0,0,0,0,0,0,0},
{0,-0.00100000000000000,0.00399111111111111,-0.000111111111111111,0,-0.00288000000000000,0,0,0,0,0},
{0,0,-0.000111111111111111,0.00433511111111111,-0.00422400000000000,0,0,0,0,0,0},
{0,0,0,-0.00422400000000000,0.00583690322580645,0,0,0,0,0,-0.00161290322580645},
{0,0,0,0,-0.00161290322580645,9999999.99990976,0,0,0,-0.000161290322580645,0.00186443354838710},
{0,0,0,0,0,0,0.0291869313482217,-0.000200000000000000,-0.0288000000000000,0,0},
{0,0,0,0,0,-8.33333333333333e-05,-0.000200000000000000,0.00222555555555556,-0.00192000000000000,-2.22222222222222e-05,0},
{0,0,0,0,0,0,-0.0288000000000000,-0.00192000000000000,0.0596033333333333,-0.0288000000000000,0},
{0,0,0,0,0,0,0,-2.22222222222222e-05,-0.0288000000000000,0.0289835125448029,-0.000161290322580645},
{0,0,-0.00288000000000000,0,0,0.00305357433333333,0,-8.33333333333333e-05,0,0,-9.02400000000000e-05}};
/*
float a[5][5] = {{2, 1, 1, 3, 2},
                 {1, 2, 2, 1, 1},
                 {1, 2, 9, 1, 5},
                 {3, 1, 1, 7, 1},
                 {2, 1, 5, 1, 8}};
*/
double b[dim][1] = {{-0.00106884424213353},{ -0.000348692601884063},{ 0.000174265198850949}, {0.000174427403041040}, {-0.000174427403041040}, {-0.000149429667406232}, {2.41146505716419e-05}, {2.42126805918570e-05}, {2.52775723989535e-05}, {-0.000215358587964216}, {-2.48355314447163e-05}};

//float b[5][1] = {{-2}, {4}, {3}, {-5}, {1}};

double z[dim][1], x[dim][1], L[dim][dim], U[dim][dim];

int i, j, k, n = dim-1;   // n=10

void LUDecomposition(double L[dim][dim], double U[dim][dim])
{
    for (i = 0; i <= n; i++) /* Assigning value of 1 to diagonal elements */
    {
        L[i][i] = 1;
    }

    for (i = 0; i <= n; i++) /* Decomposition of Matrix A */
    {
        for (j = i; j <= n; j++) /* Calculation of Upper Triangle Matrix */
        {
            U[i][j] = a[i][j];
            for (k = 0; k < i; k++)
            {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        for (j = i + 1; j <= n; j++) /* Calculation of Lower Triangle Matrix */
        {
            L[j][i] = a[j][i];
            for (k = 0; k < i; k++)
            {
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] = L[j][i] / U[i][i];
        }
    }

    for (i = 0; i <= n; i++) /* Calculation of Z Matrix */
    {
        z[i][0] = b[i][0];
        for (j = 0; j < i; j++)
        {
            z[i][0] -= z[j][0] * L[i][j];
        }
    }

    for (i = n; i >= 0; i--) /* Calculation of X Matrix */
    {
        x[i][0] = z[i][0];
        for (j = i; j < n; j++)
        {
            x[i][0] -= U[i][j + 1] * x[j + 1][0];
        }
        x[i][0] = x[i][0] / U[i][i];
    }

    for (i = 0; i <= n; i++)
    {
        printf("a%d : %f\n", i + 1, x[i][0]);
    }

}


int main()
{
/*
           for (i = 0; i <= n; i++)
        {
            U[i][i] = 1;
        }
        LUDecomposition(U, L);
        */
    LUDecomposition( L,  U);
    return 0;
}
