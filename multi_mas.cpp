#include "task.h"

void multi_mas(int(&mas_a)[SIZE_MAS][SIZE_MAS], int(&mas_b)[SIZE_MAS][SIZE_MAS], int(&mas_result)[SIZE_MAS][SIZE_MAS])    	//O(n^3) + O(n^2) + O(n) +O(1)
{
    for (int i = 0; i < SIZE_MAS; i++)                               	                                                    //O(n)
        for (int j = 0; j < SIZE_MAS; j++)                           	                                                    //O(n^2)
            for (int k = 0; k < SIZE_MAS; k++)                       	                                                    //O(n^3)
                mas_result[i][j] += (mas_a[i][k] * mas_b[k][j]);	                                                           // O(1)
}