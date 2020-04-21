#include "great_tree.h"

tree * get_great_tree(const tree * left_tree, const tree * right_tree)
{
	//Проверка корректности входных данных
	if (left_tree == nullptr || right_tree == nullptr)
		throw "Дерево задано неправильно. Пожалуйста, проверьте входные данные.";

	//Проверка корней входных деревьев

	//чтение	чтение
	if (left_tree->data == "read" && right_tree->data == "read") {
		tree * flag = new tree;
		flag->data = "flag";
		flag->left = copy(left_tree);
		flag->right = copy(right_tree);
		return flag;
	}

	//чтение	операция
	if (left_tree->data == "read") {
		tree * result = new tree;
		result->data = right_tree->data;

		result->left = build_flag(right_tree->left, left_tree->data);

		if (right_tree->data == "*") {
			result->right = build_flag(right_tree->right, "1");
			return result;
		}

		if (right_tree->data == "+") {
			result->right = build_flag(right_tree->right, "0");
			return result;
		}

		throw "Ошибка в создании флага. Неверная операция в корне дерева.";
	}

	//операция	чтение
	if (right_tree->data == "read") {
		tree * result = new tree;
		result->data = left_tree->data;

		result->left = build_flag(right_tree->data, left_tree->left);

		result->right = build_flag(get_constant(left_tree->data), left_tree->right);
		return result;

	}

	//операция	операция
	if (left_tree->data == right_tree->data) {		//Вершина покрывающего дерева — общая вершина первого и второго входных деревьев
		tree * result = new tree;
		result->data = left_tree->data;
		result->left = get_great_tree(left_tree->left, right_tree->left);
		result->right = get_great_tree(left_tree->right, right_tree->right);

	}
	else {				//Вершина покрывающего дерева — вершина одного из входных деревьев
		/*4.2.1
				Правое поддерево — покрывающее дерево для правой ветви первого дерева и второго дерева;
				Левое поддерево — покрывающее дерево для левой ветви первого дерева и дерева,
					состоящей из одной операции чтения данных, содержащую соответствующую константу.*/
		tree * case41 = new tree;
		case41->data = right_tree->data;
		case41->right = get_great_tree(left_tree, right_tree->right);
		case41->left = build_flag(get_constant(right_tree->data), right_tree->left);

		/*	4.2.2
				Правое поддерево — покрывающее дерево для правой ветви первого дерева и дерева,
					состоящей из одной операции чтения данных, содержащую соответствующую константу;
				Левое поддерево — покрывающее дерево для левой ветви первого дерева и второго дерева.*/
		tree * case42 = new tree;
		case42->data = right_tree->data;
		case42->right = build_flag(get_constant(right_tree->data), right_tree->right);
		case42->left = get_great_tree(left_tree, right_tree->left);

		/*	4.2.3
				Правое поддерево — покрывающее дерево для правой ветви первого дерева и второго дерева;
				Левое поддерево — покрывающее дерево для левой ветви первого дерева и дерева,
					состоящей из одной операции чтения данных, содержащую соответствующую константу.*/
		tree * case43 = new tree;
		case43->data = left_tree->data;
		case43->right = get_great_tree(left_tree->left, right_tree);
		case43->left = build_flag(left_tree->right, get_constant(left_tree->data));

		/*	4.2.4
				Правое поддерево — покрывающее дерево для правой ветви первого дерева и дерева,
					состоящей из одной операции чтения данных, содержащую соответствующую константу;
				Левое поддерево — покрывающее дерево для левой ветви первого дерева и второго дерева.*/
		tree * case44 = new tree;
		case44->data = left_tree->data;
		case44->right = build_flag(left_tree->left, get_constant(left_tree->data));
		case44->left = get_great_tree(left_tree->right, right_tree); 

		size_t size1 = count(case41);
		size_t size2 = count(case42);
		size_t size3 = count(case43);
		size_t size4 = count(case44);
		
		size_t s = find_min(find_min(size1, size2), find_min(size3, size4));
		
		if (size1 == s) {
			delete_tree(case41);
			delete_tree(case42);
			delete_tree(case43);
			delete_tree(case44);
			return case41;
		}
		if (size2 == s) {
			delete_tree(case41);
			delete_tree(case43);
			delete_tree(case44);
			return case42;
		}
		if (size3 == s) {
			delete_tree(case41);
			delete_tree(case42);
			delete_tree(case44);
			return case43;
		}
		if (size4 == s) {
			delete_tree(case41);
			delete_tree(case42);
			delete_tree(case43);
			return case44;
		}
	}
}

tree * build_flag(const tree * root, string fData)
{
	tree * flag = new tree;
	if (root->data == "read") {
		flag->data = "flag";
		flag->left = copy(root);
		flag->right = new tree;
		flag->right->data = fData;
		flag->right->left = nullptr;
		flag->right->right = nullptr;
		return flag;
	}

	flag->data = root->data;

	flag->left = build_flag(root->left, fData);
	flag->right = build_flag(root->right, get_constant(flag->data));
	return flag;
}

tree * build_flag(string fData, const tree * root)
{
	tree * flag = new tree;
	if (root->data == "read") {
		flag->data = "flag";
		flag->right = copy(root);
		flag->left = new tree;
		flag->left->data = fData;
		flag->left->left = nullptr;
		flag->left->right = nullptr;
		return flag;
	}

	flag->data = root->data;

	flag->left = build_flag(root->left, fData);
	flag->right = build_flag(get_constant(flag->data), root->right);
	return flag;
}

string get_constant(string operation) {
	if (operation == "*")
		return "1";
	if (operation == "+")
		return "0";
	throw "Ошибка в создании флага. Неверная операция в корне дерева.";

}
