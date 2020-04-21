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

// �������� ���� ������:
//     data - ��� �������� � ���� ������;
//     left - �������� �� ����� ���������;
//     right - ��������� �� ������ ���������.
struct tree
{
	string data;
	tree *left;
	tree *right;
};

// ������� �������� ������.
// ������ �������� �� �����.
// ������� ���������:
//     filename - ��� �������� ����������.
// ���������� ��������� �� �������� ������� ������.
tree *get_tree_from_file(const char *filename);

// ������� ���������� ������ �������� ������.
// ������ �������� �� �����.
// ������� ���������:
//     filename - ��� �������� ����������.
//     root - �������� ������� ������, ��� �������� ������������ ���������� ������.
void *get_arr_from_file(const char *filename, tree *root);

// ������� ���������� ������ �������� ������.
// ������ �������� �� �����.
// ������� ���������:
//     root - �������� ������� ������, ��� �������� ������������ ���������� ������.
void *get_arr_from_file(tree *root);

// ������� �������� ������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
// root == nullptr ����� ���������� ���� �������.
void delete_tree(tree *root);

// ������� ������ ������ �� �������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
void print_tree(const tree *root, std::ostream &source = std::cout, size_t space = 0);

// ������� ���������:
//     root - ��������� �� �������� ������� ������.
void print_number(const tree *root, std::ostream &source = std::cout, size_t space = 0);

void print_tree_to_read(const char *filename, const tree *root);

// ������� ������ ������ � ���� � ������ �������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
void print_tree_to_read(const tree *root, std::ostream &source = std::cout);

// ������� ������ ������ � ����.
// ������� ���������:
//     filename - ��� �������� ����������.
//     root - ��������� �� �������� ������� ������.
void print_tree(const char *filename, const tree *root);

// ������� ���������� ���������� ������� � ������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
size_t leaves_count(const tree *root);

// ������� ���������� ���������� ������ � ������� � ������ � ������������ ������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
size_t count(const tree *root);
//size_t count(tree *&root);

// ������� ����������� ������
// ������� ���������:
//     root - ��������� �� ������ ������.
// ���������� ��������� �� �������� ������� ������������� ������.
tree *copy(const tree *root);

// ����������� ����� ������� � ��������� ���������
// ��������� ������� � ��������� ����� � ������
void random_insert(tree *&root, const string x, tree *current = nullptr);

// ������� ��� �������� ������ � �������� ����������� ������
// ��������� ��������� ������ ��������
tree *random_tree(const size_t count);

// ��������������� ������� �������� ������ (�������� ������ ������)
void leaves_maker(tree *&root);

// ��������������� ������� �������� ������ (�������� ������ ������) � ���������� ������ ������ � 
void leaves_maker(tree *&root, const string mark, size_t count = 0);

// ������� �������� ����� � ������
string int_to_string(size_t a);

size_t find_min(size_t a, size_t b) { if (a < b) return a; return b; }
