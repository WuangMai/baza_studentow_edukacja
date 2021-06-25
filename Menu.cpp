#include "Menu.h"
#include "StudentEdukacjaDao.h"
#include "StudentEdukacja.h"
#include <iostream>
#include <string>


void Menu::menu()
{

	StudentEdukacjaDao* dao = new StudentEdukacjaDao();
	std::wcout << "Baza danych studentow" << std::endl;
	while (true)
	{
		std::wcout << "\n\tWybierz akcje:" << std::endl;
		std::wcout << "\tL - wyswietla wszystkich studentow z bazy" << std::endl;
		std::wcout << "\tD - dodaje nowego studenta do bazy" << std::endl;
		std::wcout << "\tU - usuwa studenta" << std::endl;
		std::wcout << "\tK - wyjscie i zapisanie bazy" << std::endl;
		std::string option;
		std::cin >> option;

		if (option == "l") {
			dao->showAll();
		}

		else if (option == "d")
		{
			StudentEdukacja* s = new StudentEdukacja();
			std::string input;

			std::cout << "Podaj imie: ";
			std::cin >> input;
			s->setImie(input);

			std::cout << "Podaj nazwisko: ";
			std::cin >> input;
			s->setNazwisko(input);

			std::cout << "Podaj wiek: ";
			std::cin >> input;
			int properAge = std::stoi(input);
			s->setWiek(properAge);

			std::cout << "Podaj grupe: ";
			std::cin >> input;
			s->setGrupa(input);

			std::cout << "Podaj numer indeksu: ";
			std::cin >> input;
			int properIndex = std::stoi(input);
			s->setIndex(properIndex);
			dao->add(s);
		}

		else if (option == "u")
		{
			std::cout << "Podaj numer indexu do usuniecia: ";
			int toDelete;
			std::cin >> toDelete;
			dao->del(toDelete);

		}

		else if (option == "k")
		{
			std::cout << "\nZapisuje baze i wychodze\n";
			dao->exit();
			delete dao;
			return;
		}
	}
	delete dao;
}
