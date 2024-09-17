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
        qs(arr, 0, size - 1);
        clock_t end_time = clock();

        time_ = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        print_time();
    }

    void qs(int* items, int left, int right)
    {
        while (left < right)
        {
            int pivot = items[(left + right) / 2];
            int i = left;
            int j = right;

            do
            {
                while (items[i] < pivot) i++;
                while (pivot < items[j]) j--;

                if (i <= j)
                {
                    std::swap(items[i], items[j]);
                    i++;
                    j--;
                }
            } while (i <= j);

            // Рекурсивный вызов для двух подмассивов
            if (j - left < right - i)
            {
                qs(items, left, j);
                left = i;
            }
            else
            {
                qs(items, i, right);
                right = j;
            }
        }
    }

    void print_time() {

        std::cout << data_name[count] << std::endl;
        count++;
        std::cout << "Size: " << size << std::endl;
        std::cout << "Time shell: " << time_ << " seconds\n" << std::endl;
    }
};