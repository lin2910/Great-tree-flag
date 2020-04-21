#pragma once
#pragma once
#pragma once
//#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cassert>
//#include "crtdynmem.h"
using namespace std;

// Описание узла дерева:
//     data - имя операции в узле дерева;
//     left - укзатель на левое поддерево;
//     right - указатель на правое поддерево.
struct tree
{
	string data;
	tree *left;
	tree *right;
};

// Функция создания дерева.
// Данные вводятся из файла.
// Входные параметры:
//     filename - имя файловой переменной.
// Возвращает указатель на корневой элемент дерева.
tree *get_tree_from_file(const char *filename);

// Функция заполнения флагов массивов дерева.
// Данные вводятся из файла.
// Входные параметры:
//     filename - имя файловой переменной.
//     root - корневой элемент дерева, для которого производится заполнение данных.
void *get_arr_from_file(const char *filename, tree *root);

// Функция заполнения флагов массивов дерева.
// Данные вводятся из файла.
// Входные параметры:
//     root - корневой элемент дерева, для которого производится заполнение данных.
void *get_arr_from_file(tree *root);

// Функция удаления дерева.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
// root == nullptr после выполнения этой функции.
void delete_tree(tree *root);

// Функция вывода дерева на консоль.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
void print_tree(const tree *root, std::ostream &source = std::cout, size_t space = 0);

// Входные параметры:
//     root - указатель на корневой элемент дерева.
void print_number(const tree *root, std::ostream &source = std::cout, size_t space = 0);

void print_tree_to_read(const char *filename, const tree *root);

// Функция вывода дерева в файл в прямом порядке.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
void print_tree_to_read(const tree *root, std::ostream &source = std::cout);

// Функция записи дерева в файл.
// Входные параметры:
//     filename - имя файловой переменной.
//     root - указатель на корневой элемент дерева.
void print_tree(const char *filename, const tree *root);

// Функция вычисления количества листьев в дереве.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
size_t leaves_count(const tree *root);

// Функция вычисления количества вершин и листьев в дереве с нумерованием вершин.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
size_t count(const tree *root);
//size_t count(tree *&root);

// Функция копирования дерева
// Входные параметры:
//     root - указатель на корень дерева.
// Возвращает указатель на корневой элемент копированного дерева.
tree *copy(const tree *root);

// Рекурсивный метод вставки в случайное поддерево
// Вставляет элемент в случайное место в дереве
void random_insert(tree *&root, const string x, tree *current = nullptr);

// Функция для создания дерева с заданным количеством вершин
// Вершинами считаются только операции
tree *random_tree(const size_t count);

// Вспомогательная функция создания листев (операций чтения данных)
void leaves_maker(tree *&root);

// Вспомогательная функция создания листев (операций чтения данных) с уникальной меткой дерева и 
void leaves_maker(tree *&root, const string mark, size_t count = 0);

// Функция перевода числа в строку
string int_to_string(size_t a);

size_t find_min(size_t a, size_t b) { if (a < b) return a; return b; }
