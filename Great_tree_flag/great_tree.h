#pragma once
#include "tree.h"


//����������� ������� ������ ��������� ������������ ������.
//������� ������:
//   ������������:
//		root_first - ��������� �� ������ ������, ��� �������� ����� ����� ��������;
//		root_second - ��������� �� ������ ������, ��� �������� ����� ����� ��������;
//��������� - ��������� �� ������ ������������ ������.
tree * get_great_tree(const tree *root_first, const tree *root_second);

//����������� ������� ������������ ������ ��� ������ � ������ ��������
//������� ������
//		root - ��������� �� ������
//		fData - �������� ��� �����
//� ������ ���������� �������� fData ����������� �� ������ ������������� (������)
tree * build_flag(const tree *root, string fData);


//����������� ������� ������������ ������ ��� ������ � ������ ��������
//������� ������
//		fData - �������� ��� �����
//		root - ��������� �� ������
//� ������ ���������� �������� fData ����������� �� ����� ������������� (������)
tree * build_flag(string fData, const tree *root);

//��������������� ������� ������ ���������� �������
string get_constant(string operation);

//size_t find_min(size_t a, size_t b) { if (a < b) return a; return b; }