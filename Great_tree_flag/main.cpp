#include "main_menu.h"
#include "tree.h"
#include "crtdynmem.h"


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	try
	{
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
		
	}
	catch (const ios_base::failure &e) {
		cerr << "������������ ����: " << e.what() << endl;
	}
	catch (const domain_error &e) {
		cerr << "�������� �������� ���������: " << e.what() << endl;
	}
	catch (const out_of_range &e) {
		cerr << "������ ��������� ��� ������: " << e.what() << endl;
	}
	catch (const exception &e) {
		cerr << "�������������� ������: " << e.what() << endl;
	}
	
	//_CrtDumpMemoryLeaks(); 
	system("pause");
	return 0;
}