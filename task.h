#pragma once
#include <iostream>
#include <cstdio>

using namespace std;

class Task  //O(n ^ 3) + (O(n^2)*7) + (O(n)*7) + (O(n)*17)
{
    size_t size = 10000;                                                 //O(1)

    double time_ = 0;                                                   //O(1)

    int** data_a = nullptr;                                             //O(1)
    int** data_b = nullptr;                                             //O(1)
    int** data_result = nullptr;                                        //O(1)

public:

    Task()
    {
        install(data_a);                                                            //O(n^2) + O(n) + O(1)
        install(data_b);                                                            //O(n^2) + O(n) + O(1)
        install(data_result);                                                       //O(n^2) + O(n) + O(1)

        for (size_t i = 0; i < size; i++)                               //O(n)
            for (size_t j = 0; j < size; j++) {                         //O(n^2)    
                data_a[i][j] = rand() % 100 + 1;                        //O(1)
                data_b[i][j] = rand() % 100 + 1;                        //O(1)
            }
        multiplay();                                                                //O(n ^ 3) + O(n^2) + O(n) + (O(1)*2)
        print_time();                                                               //O(1)*2
    }

    ~Task() 
    {
        deinstall(data_a);                                                          //O(n^2) + O(n) + (O(1)*2)
        deinstall(data_b);                                                          //O(n^2) + O(n) + (O(1)*2)
        deinstall(data_result);                                                     //O(n^2) + O(n) + (O(1)*2)
    }


    void install(int**& data)                                                       //O(n^2) + O(n) + O(1)
    {
        data = new int* [size];                                         //O(n)
        for (size_t i = 0; i < size; i++) {                             //O(n^2)    
            data[i] = new int[size];                                    //O(1)
        }
    }

    void deinstall(int** data)                                                      //O(n^2) + O(n) + (O(1)*2)
    {
        if (data)                                                       //O(1)
        {
            for (size_t i = 0; i < size; i++)                           //O(n)
                delete[] data[i];                                       //O(1)
            delete[] data;                                              //O(n^2)    
        }
    }

    void multiplay()                                                                //O(n ^ 3) + O(n^2) + O(n) + (O(1)*2)
    {
        clock_t start = clock();                                        //O(1)
        for (int i = 0; i < size; i++)                                  //O(n)
            for (int j = 0; j < size; j++)                              //O(n^2)    
                for (int k = 0; k < size; k++)                          //O(n^3)    
                    data_result[i][j] += (data_a[i][k] * data_b[k][j]); //O(1)

        clock_t end = clock();                                          //O(1)
        time_ = static_cast<double>(end - start) / CLOCKS_PER_SEC;      //O(1)
    }

    void print_time()                                                               //O(1)*2
    {
        std::cout << "size: " << size << std::endl;                     //O(1)
        std::cout << "teme multiplay: " << time_ << std::endl;          //O(1)
    }
};