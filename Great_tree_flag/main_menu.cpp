#pragma once
#include "main_menu.h"


using namespace std;

void no_data()
{

	//	size_t tree_size_first, tree_size_second;
	cout << "����������� ����." << endl;

	tree *first_tree = get_tree_from_file("first_tree_to_read");
	tree *second_tree = get_tree_from_file("second_tree_to_read");
	tree *result = new tree;

	//������ ������� �������
	clock_t start = clock();
	result = get_great_tree(first_tree, second_tree);

	// ����� ������� �������
	clock_t stop = clock();

	// ���������� ������
	double seconds = double(stop - start) / CLOCKS_PER_SEC;

	cout << endl << "time : " << seconds << endl;
	print_tree("out.txt", result);
	ofstream fout("out.txt", ios_base::app);
	if (!fout.is_open())
		throw "Couldn't open file!";
	fout << "time : " << seconds << endl;
	fout.close();
	delete_tree(first_tree);
	delete_tree(second_tree);
}

void data() {
	size_t tree_size_first, tree_size_second;
	cout << "�� ������� ��������� ������ ������." << endl <<
		"������� ���������� ������ ��� �������� ������ : ";
	cin >> tree_size_first;
	if (tree_size_first < 1)
		throw domain_error("����������� ����� ������ ������� ������");
	tree *first_tree = random_tree(tree_size_first);
	change_tree(first_tree, "1");
	//print_tree("first_tree.txt", first_tree);
	//print_tree_to_read("first_tree_to_read.txt", first_tree);
	cout << "������� ���������� ������ ��� �������� ������ : ";
	cin >> tree_size_second;
	if (tree_size_second < 1)
		throw domain_error("����������� ����� ������ ������� ������");
	tree *second_tree = random_tree(tree_size_second);
	change_tree(second_tree, "2");
	//print_tree("second_tree.txt", second_tree);
	//print_tree_to_read("second_tree_to_read.txt", second_tree);
	if (tree_size_first + tree_size_second <= 50)
	{
		cout << "first tree:" << endl;
	print_tree(first_tree);
		cout << "second tree:" << endl;
	print_tree(second_tree);
	}

	tree *result = new tree;
	//������ ������� �������
	clock_t start = clock();
	result = get_great_tree(first_tree, second_tree);
	// ����� ������� �������
	clock_t stop = clock();
	// ���������� ������
	double seconds = double(stop - start) / CLOCKS_PER_SEC;
	if (tree_size_first + tree_size_second <= 50)
	{
	cout << "result" << endl;
	print_tree(result);
	}

	

	//print_tree_to_file("out.txt", result);
	//print_tree_to_read("out_to_read.txt", result);
	cout << endl << "time : " << seconds << endl;
	//print_tree_to_file("out.txt", result);
	/*ofstream fout("out.txt", ios_base::app);
	if (!fout.is_open())
	throw "Couldn't open file!";
	fout << "time : " << seconds << endl;
	fout.clear();
	fout.close();*/
	delete_tree(first_tree);
	delete_tree(second_tree);
	delete_tree(result);
}



void data(char arg1[], char arg2[], char arg3[], char arg4[]) {
	tree *first_tree = get_tree_from_file(arg1);
	cout << "1 tree" << endl;
	print_tree(first_tree);
	cout << "2 tree" << endl;
	tree *second_tree = get_tree_from_file(arg2);
	print_tree(second_tree);
	tree *result = new tree;

	cout << "result" << endl;
	//������ ������� �������
	clock_t start = clock();
	result = get_great_tree(first_tree, second_tree);

	// ����� ������� �������
	clock_t stop = clock();
	print_tree(result);
	// ���������� ������
	double seconds = double(stop - start) / CLOCKS_PER_SEC;

	cout << "time : " << seconds << endl;

	print_tree(arg3, result);
	ofstream fout(arg3, ios_base::app);
	if (!fout.is_open())
		throw "Couldn't open file!";
	fout << "time : " << seconds << endl;
	fout.close();

	print_tree_to_read(arg4, result);

	delete_tree(first_tree);
	delete_tree(second_tree);
}

void data(char arg1[], char arg2[], char arg3[]) {
	tree *first_tree = get_tree_from_file(arg1);
	cout << "1 tree" << endl;
	print_tree(first_tree);
	cout << "2 tree" << endl;
	tree *second_tree = get_tree_from_file(arg2);
	print_tree(second_tree);
	tree *result = new tree;

	cout << "result" << endl;
	//������ ������� �������
	clock_t start = clock();
	result = get_great_tree(first_tree, second_tree);

	// ����� ������� �������
	clock_t stop = clock();
	print_tree(result);
	// ���������� ������
	double seconds = double(stop - start) / CLOCKS_PER_SEC;

	cout << "time : " << seconds << endl;

	print_tree(arg3, result);
	ofstream fout(arg3, ios_base::app);
	if (!fout.is_open())
		throw "Couldn't open file!";
	fout << "time : " << seconds << endl;
	fout.close();
	delete_tree(first_tree);
	delete_tree(second_tree);
}

void data(char arg1[], char arg2[]) {
	tree *first_tree = get_tree_from_file(arg1);
	cout << "1 tree" << endl;
	print_tree(first_tree);
	cout << "2 tree" << endl;
	tree *second_tree = get_tree_from_file(arg2);
	print_tree(second_tree);
	tree *result = new tree;

	cout << "result" << endl;
	//������ ������� �������
	clock_t start = clock();
	result = get_great_tree(first_tree, second_tree);

	// ����� ������� �������
	clock_t stop = clock();
	print_tree(result);
	// ���������� ������
	double seconds = double(stop - start) / CLOCKS_PER_SEC;

	cout << "time : " << seconds << endl;

	print_tree("out.txt", result);
	ofstream fout("out.txt", ios_base::app);
	if (!fout.is_open())
		throw "Couldn't open file!";
	fout << "time : " << seconds << endl;
	fout.close();
	delete_tree(first_tree);
	delete_tree(second_tree);
}
