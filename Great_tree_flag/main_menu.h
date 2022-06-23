#pragma once
#include <iostream>
#include <fstream>
#include <ctime>  // библиотека дл€ работы со временем
#include "tree.h"
#include "great_tree.h"

using namespace std;

void no_data();

// «апуск программы с вводом данных с консоли
void data();

// «апуск программы с фиксированными размерами дл€ тестировани€
void data(int size_first, int size_second);

// «апуск программы с фиксированными размерами дл€ тестировани€
//		и возвратом времени выполнени€ построени€ покрывающего дерева (да мне лень считать)
double data(int size_first, int size_second, char c);


//–абота с консолью


void data(char arg1[], char arg2[], char arg3[], char arg4[]);

void data(char arg1[], char arg2[], char arg3[]);

void data(char arg1[], char arg2[]);



