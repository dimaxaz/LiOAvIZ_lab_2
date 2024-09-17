#pragma once
#include <iostream>
#include <cstdio>

using namespace std;

class Task
{
    size_t size = 10000000;

    double time_ = 0;

    int* data_rand  = nullptr;
    int* data_up    = nullptr;
    int* data_Down  = nullptr;
    int* data_half  = nullptr;

    std::string data_name[4] = { "data_rand", "data_up", "data_Down", "data_half" };
    int count = 0;

public:

    Task()
    {
        install(data_rand);
        for (size_t i = 0; i < size; i++)
            data_rand[i] = rand() % 100 + 1;

        install(data_up);
        for (size_t i = 0; i < size; i++)
            data_up[i] = i;

        install(data_Down);
        for (size_t i = 0; i < size; i++)
            data_Down[i] = size - i;

        install(data_half);
        for (size_t i = 0; i < size; ++i)
        data_half[i] = (i < size / 2) ? (i + 1) : (size - i);

        sort_print_mass_time(data_rand);
        sort_print_mass_time(data_up);
        sort_print_mass_time(data_Down);
        sort_print_mass_time(data_half);
    }

    ~Task() 
    {
        deinstall(data_rand);
        deinstall(data_up);
        deinstall(data_Down);
        deinstall(data_half);
    }


    void install(int*& data)                                        
    {
        data = new int [size];

    }

    void deinstall(int* data)                                       
    {                                                                               
            delete[] data;                                           
    }

    void sort_print_mass_time(int* arr)
    {
        clock_t start_time = clock();
        shell (arr);
        clock_t end_time = clock();

        time_ = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        print_time();
    }

    void shell(int* arr) 
    {
        for (int gap = size / 2; gap > 0; gap /= 2)
            for (int i = gap; i < size; i++)
                for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap)
                    swap(arr[j], arr[j - gap]);
    }

   

    void print_time() {

        std::cout << data_name[count] << std::endl;
        count++;
        std::cout << "Size: " << size << std::endl;
        std::cout << "Time shell: " << time_ << " seconds\n" << std::endl;
    }
};