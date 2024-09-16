#include "task.h"

int main()																													//O(n ^ 3) + (O(n^2)*6) + (O(n)*6) + (O(1)*29)
{
	setvbuf(stdin, NULL, _IONBF, 0);																						//O(1)
	setvbuf(stdout, NULL, _IONBF, 0);																						//O(1)

	clock_t start_install_mas_a, 
			start_install_mas_b,
			start_multi_mas,
			start_print_mas_a,
			start_print_mas_b,
			start_print_mas_result,
			end_1, end_2, end_3, 
			end_4, end_5, end_6;																							//O(1)
	
	int 	mas_a[SIZE_MAS][SIZE_MAS]{ 0 },
			mas_b[SIZE_MAS][SIZE_MAS]{ 0 },
			mas_result[SIZE_MAS][SIZE_MAS]{ 0 };																			//O(1)
	
	start_install_mas_a = clock();																							//O(1)
	install_mas(mas_a);																										//O(n^2) +	O(n) + O(1)
	end_1 = clock();																										//O(1)
	
	start_install_mas_b = clock();																							//O(1)
	install_mas(mas_b);																										//O(n^2) +	O(n) + O(1)
	end_2 = clock();																										//O(1)
	
	start_print_mas_a = clock();																							//O(1)
	print_mas(mas_a);																										//O(n^2) + O(n)+ (O(1)*2)
	end_3 = clock();																										//O(1)
	
	start_print_mas_b = clock();																							//O(1)
	print_mas(mas_b);																										//O(n^2) + O(n)+ (O(1)*2)
	end_4 = clock();																										//O(1)
	
	start_multi_mas = clock();																								//O(1)
	multi_mas(mas_a, mas_b, mas_result);																					//O(n^3) + O(n^2) + O(n) +O(1)
	end_5 = clock();																										//O(1)
	
	start_print_mas_result = clock();																						//O(1)
	print_mas(mas_result);																									//O(n^2) + O(n)+ (O(1)*2)
	end_6 = clock();																										//O(1)
	
	std::cout <<"SIZE_MAS: \t\t" << SIZE_MAS << std::endl;																	//O(1)
	std::cout <<"start_install_mas_a \t"<< double(end_1 - start_install_mas_a) / CLOCKS_PER_SEC << " seconds\n";			//O(1)
	std::cout <<"start_install_mas_b \t" << double(end_2 - start_install_mas_b) / CLOCKS_PER_SEC << " seconds\n";			//O(1)
	std::cout <<"start_print_mas_a \t" << double(end_3 - start_print_mas_a) / CLOCKS_PER_SEC << " seconds\n";				//O(1)
	std::cout << "start_print_mas_b \t" << double(end_4 - start_print_mas_b) / CLOCKS_PER_SEC << " seconds\n";				//O(1)
	std::cout << "start_multi_mas \t" << double(end_5 - start_multi_mas) / CLOCKS_PER_SEC << " seconds\n";					//O(1)
	std::cout << "start_print_mas_result \t" << double(end_6 - start_print_mas_result) / CLOCKS_PER_SEC << " seconds\n";	//O(1)

	return (0);																												//O(1)
}

