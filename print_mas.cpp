#include "task.h"

void print_mas(int(&mas)[SIZE_MAS][SIZE_MAS])			//O(n^2) + O(n)+ (O(1)*2)
{
	for (int i = 0; i < SIZE_MAS; ++i) {				//O(n)
		for (int j = 0; j < SIZE_MAS; ++j)				//O(n^2)
			cout << mas[i][j] << " ";					// O(1)
		cout << endl;									// O(1)
	}
}