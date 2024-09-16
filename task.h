#pragma once
#include <iostream>
#include <cstdio>

using namespace std;
constexpr size_t SIZE_MAS = 200;

void install_mas(int(&mas)[SIZE_MAS][SIZE_MAS]);
void print_mas(int(&mas)[SIZE_MAS][SIZE_MAS]);
void multi_mas(int(&mas_a)[SIZE_MAS][SIZE_MAS], int(&mas_b)[SIZE_MAS][SIZE_MAS], int(&mas_result)[SIZE_MAS][SIZE_MAS]);
