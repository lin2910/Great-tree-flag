#pragma once
#include <iostream>
#include <fstream>
#include <ctime>  // ���������� ��� ������ �� ��������
#include "tree.h"
#include "great_tree.h"

using namespace std;

void no_data();

// ������ ��������� � ������ ������ � �������
void data();

// ������ ��������� ��������� ��� � �������������� ��������� ��� ������������
void data(int size_first, int size_second);

void data(char arg1[], char arg2[], char arg3[], char arg4[]);

void data(char arg1[], char arg2[], char arg3[]);

void data(char arg1[], char arg2[]);



