#pragma once
#include <iostream>
#include <fstream>
#include <ctime>  // библиотека для работы со временем
#include "tree.h"
#include "great_tree.h"

using namespace std;

void no_data();

// Запуск программы с вводом данных с консоли
void data();

// Запуск программы несколько раз с фиксированными размерами для тестирования
void data(int size_first, int size_second);

void data(char arg1[], char arg2[], char arg3[], char arg4[]);

void data(char arg1[], char arg2[], char arg3[]);

void data(char arg1[], char arg2[]);



