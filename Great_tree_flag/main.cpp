#include "main_menu.h"
#include "tree.h"


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	try
	{
		//тестирование
		/*
		tree *test = random_tree(5);
		print_tree(test);

		tree * tesf_with_flag;
		cout << endl <<  endl << endl << endl;
		cout << get_constant(test->data);
		cout << endl <<  endl << endl;

		tesf_with_flag = build_flag( get_constant(test->data), test);
		print_tree(tesf_with_flag);
		*/
		
		//отладка
		//data();

		//замеры времени
		for (size_t i = 0; i < 20; i++)
		{
			data(30, 30);
		}


		//основная раброта
		/*
		if (argc < 3)

		data();

		else
		{
		if (argc >= 4)
		if (argc >= 5)
		data(argv[1], argv[2], argv[3], argv[4]);
		else
		data(argv[1], argv[2], argv[3]);

		else
		data(argv[1], argv[2]);
		}
		*/
	}
	catch (const ios_base::failure &e) {
		cerr << "Некорректный ввод: " << e.what() << endl;
	}
	catch (const domain_error &e) {
		cerr << "Неверное значение параметра: " << e.what() << endl;
	}
	catch (const out_of_range &e) {
		cerr << "Индекс находится вне границ: " << e.what() << endl;
	}
	catch (const exception &e) {
		cerr << "Непредвиденная ошибка: " << e.what() << endl;
	}
	//_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}