#include "tree.h"

tree *get_tree_from_file(const char * filename)
{
	assert(filename);
	ifstream fin(filename);
	if (!fin.is_open()) throw "Не найден указанный файл";

	tree *root;
	string x;
	tree *pt = new tree;
	fin >> pt->data;
	pt->left = nullptr;
	pt->right = nullptr;
	root = pt;
	while (fin >> x)
	{
		tree *p = new tree;
		p->data = x;
		p->left = nullptr;
		p->right = nullptr;
		tree *current = root;
		stack<tree*> way_on_tree;
		way_on_tree.push(root);

		while (current)
		{
			if (!current->right)
			{
				way_on_tree.push(current);
				current = current->left;
				if (current &&current->data[0] == 'd')
				{
					current = way_on_tree.top();
					current = current->right;
				}
			}
			else
			{
				way_on_tree.push(current);
				current = current->right;
				if (current->data[0] == 'd')
				{
					current = way_on_tree.top();
					way_on_tree.pop();
					while (current->right)
					{
						current = way_on_tree.top();
						way_on_tree.pop();
					}
					way_on_tree.push(current);
					current = current->right;
				}
			}
		}
		current = way_on_tree.top();
		if (current->left)
			current->right = p;
		else
			current->left = p;
	}
	fin.clear();
	fin.close();
	return root;
}

void * get_arr_from_file(const char * filename, tree * root)
{
	return nullptr;
}

void * get_arr_from_file(tree * root)
{
	return nullptr;
}

void delete_tree(tree *root)
{
	if (!root) return;
	delete_tree(root->left);
	delete_tree(root->right);
	delete root;
	root = nullptr;
}

void print_tree(const tree *root, std::ostream &source, size_t space)
{
	if (root == nullptr) return;
	print_tree(root->left, source, space + 1);
	for (size_t i = 0; i < space; i++) source << '\t';
	source << root->data << endl;
	print_tree(root->right, source, space + 1);
}

void print_number(const tree * root, std::ostream & source, size_t space)
{
	if (root == nullptr) return;
	print_number(root->left, source, space + 1);
	for (size_t i = 0; i < space; i++) source << '\t';
	source << root->data << endl;
	print_number(root->right, source, space + 1);
}

void print_tree_to_read(const char * filename, const tree * root)
{
	assert(filename);
	ofstream fout(filename);
	if (!fout.is_open())
		throw "Couldn't open file!";
	print_tree_to_read(root, fout);
	fout.close();
}

void print_tree_to_read(const tree *root, std::ostream &source)
{
	if (root == nullptr) return;
	source << root->data;
	print_tree_to_read(root->left, source);
	print_tree_to_read(root->right, source);
}

void print_tree(const char * filename, const tree * root)
{
	assert(filename);
	ofstream fout(filename);
	if (!fout.is_open())
		throw "Couldn't open file!";
	print_tree(root, fout);
	fout.close();
}

size_t leaves_count(const tree *root)
{
	if (!root) return 0;
	if (!root->left && !root->right)
		return 1;
	return leaves_count(root->left) + leaves_count(root->right);
}

size_t count(const tree *root)
{
	if (!root) return 0;
	if (!root->left && !root->right)
		return 1;
	return 1 + count(root->left) + count(root->right);
}

tree *create(tree *&root, int n)
{
	root = nullptr;
	for (int i = 0; i < n; i++)
	{
		tree *p = new tree;
		cin >> p->data;
		p->left = nullptr;
		p->right = nullptr;
		if (!root)
			root = p;
		else
		{
			tree *q = root, *r = nullptr;
			while (q)
			{
				r = q;
				if (p->data < q->data)
					q = q->left;
				else
					q = q->right;
			}
			if (p->data < r->data)
				r->left = p;
			else
				r->right = p;
		}
	}
	return root;
}

tree *copy(const tree *root)
{
	if (!root)
		return nullptr;
	tree *root_copy = new tree;
	root_copy->data = root->data;
	root_copy->left = copy(root->left);
	root_copy->right = copy(root->right);
	return root_copy;
}

size_t * copy(size_t *number, size_t n)
{
	size_t *result = new size_t[n];
	for (size_t i = 0; i < n; i++)
		result[i] = number[i];
	return result;
}

tree *find(tree *root, string k, const bool type) {
	if (!root)
		return root;
	if (k == root->data)
		return root;
	if (type == true) //Дерево поиска
	{
		if (k > root->data)
			return find(root->right, k, true);
		else
			return find(root->left, k, true);
	}
	else
	{
		if (find(root->left, k, false))
			return find(root->left, k, false);
		return find(root->right, k, false);
	}
}

void random_insert(tree *& root, const string x, tree *current)
{
	if (!root) {
		if (!current)
		{
			root = new tree;

			string t = "*";
			root->data = t;
			root->left = nullptr;
			root->right = nullptr;
		}
		else
		{
			tree *p = new tree;
			p->data = x;
			p->left = nullptr;
			p->right = nullptr;
			if (current->left)
				current->right = p;
			else
				current->left = p;
		}
	}
	else {
		current = root;
		if (std::rand() % 2 == 0)  // вставляем элемент в случайное поддерево
			random_insert(root->left, x, current);
		else
			random_insert(root->right, x, current);
	}
}

tree * random_tree(const size_t count)
{
	tree *result = new tree;
	result->left = nullptr;
	result->right = nullptr;
	string t;
	if (std::rand() % 2 == 0)
	//	if (std::rand() % 2 == 0)
			t = "+";
	//	else
	//		t = "-";
	else
	//	if (std::rand() % 2 == 0)
			t = "*";
	//	else
	//		t = "/";
	result->data = t;
	for (size_t i = 1; i < count; i++) {
		if (std::rand() % 2 == 0)
	//		if (std::rand() % 2 == 0)
				t = "+";
	//		else
	//			t = "-";
		else
	//		if (std::rand() % 2 == 0)
				t = "*";
	//		else
	//			t = "/";
		random_insert(result, t);
	}
	leaves_maker(result);
	return result;
}

void leaves_maker(tree *&root)
{
	if (root == nullptr) return;
	leaves_maker(root->left);

	leaves_maker(root->right);
	if (root->left == nullptr && root->right == nullptr)
	{
		tree *p = new tree;
		p->data = "read";
		p->left = nullptr;
		p->right = nullptr;
		tree *q = new tree;
		q->data = "read";
		q->left = nullptr;
		q->right = nullptr;
		root->left = p;
		root->right = q;
	}
	else
		if (root->left == nullptr)
		{
			tree *p = new tree;
			p->data = "read";
			p->left = nullptr;
			p->right = nullptr;
			root->left = p;
		}
		else
			if (root->right == nullptr)
			{
				tree *q = new tree;
				q->data = "read";
				q->left = nullptr;
				q->right = nullptr;

				root->right = q;
			}
}

void leaves_maker(tree *& root, const string mark, size_t count)
{
	if (root == nullptr) return;
	leaves_maker(root->left);

	leaves_maker(root->right);
	if (root->left == nullptr && root->right == nullptr)
	{
		tree *p = new tree;
		p->data = "read";
		p->left = nullptr;
		p->right = nullptr;
		tree *q = new tree;
		q->data = "read";
		q->left = nullptr;
		q->right = nullptr;
		root->left = p;
		root->right = q;
	}
	else
		if (root->left == nullptr)
		{
			tree *p = new tree;
			p->data = "read";
			p->left = nullptr;
			p->right = nullptr;
			root->left = p;
		}
		else
			if (root->right == nullptr)
			{
				tree *q = new tree;
				q->data = "read";
				q->left = nullptr;
				q->right = nullptr;

				root->right = q;
			}
}



string int_to_string(size_t a)
{
	int new_a = 0;
	while (a > 0) {
		new_a *= 10; new_a += a % 10;
		a /= 10;
	}
	size_t n = 0;
	string str = "";
	while (new_a > 0) {
		str += new_a % 10 + 48;
		new_a /= 10;
		n++;
	}
	str[n] = 0;
	return str;
}

void change_tree(tree *&root, string p){
	if (!root)
		return;
	change_tree(root->right, p);
	change_tree(root->left, p);
	if (!root->left && !root->right)
			root->data = root->data + p;
			

}