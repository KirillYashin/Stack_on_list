#include "Stack_on_list.h"
#include <locale>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите размер стека: ";
	std::cout << std::endl;
	int len;
	std::cin >> len;
	try
	{
		Stack_on_list<int> stlst(len);
		for (int i = 0; i < len; i++)
		{
			stlst.Push(std::rand() % 100);
		}
		std::cout << "Проверим стек на полноту и выведем его на экран";
		std::cout << std::endl;
		if (stlst.IsFull())
		{
			std::cout << "Стек полон";
			std::cout << std::endl;
			std::cout << "Содержимое: ";
			stlst.Print();
		}
		std::cout << std::endl;
		std::cout << "Заберем вершину стека и выведем ее на экран - " << stlst.Pop() << std::endl;
		std::cout << std::endl;
		std::cout << "Стек изменился: ";
		stlst.Print();
		std::cout << std::endl;
		std::cout << "Его длина = " << stlst.GetLength() << ", а максимальная длина = " << stlst.GetSize() << std::endl;
		std::cout << std::endl;
		std::cout << "Проверим работу функций IsEmpty и Pop, забирая и выводя элементы стека, пока он не опустеет" << std::endl;
		while (!stlst.IsEmpty())
			std::cout << "Элемент - " << stlst.Pop() << std::endl;
		std::cout << std::endl;
		std::cout << "Попробуем забрать еще элемент - получим исключение" << std::endl;
		stlst.Pop();
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	return 0;
}