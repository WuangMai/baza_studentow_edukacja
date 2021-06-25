#include "StudentEdukacjaDao.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

std::vector<StudentEdukacja*> StudentEdukacjaDao::wczytaj = StudentEdukacjaDao::load();

std::vector<StudentEdukacja*> StudentEdukacjaDao::load()
{
	std::fstream baza;
	baza.open("baza_studentow.txt", std::ios::in);
	if (baza.good() == true && baza.is_open() == true)
	{
		std::cout << "Pomyslnie otworzono plik bazy\n" << std::endl;
	}

	std::vector<StudentEdukacja*> edukacjaList;
	std::string line;
	std::string name;
	std::string surname;
	int age = 0;
	std::string ageString;
	std::string group;
	int index = 0;
	std::string indexString;
	while (std::getline(baza, line))
	{
		name = line;
		std::getline(baza, line);
		surname = line;
		std::getline(baza, line);
		ageString = line;
		std::getline(baza, line);
		group = line;
		std::getline(baza, line);
		indexString = line;

		age = std::stoi(ageString);
		index = std::stoi(indexString);
		StudentEdukacja* student = new StudentEdukacja(name, surname, age, group, index);
		edukacjaList.push_back(student);
	}
	return edukacjaList;
}

void StudentEdukacjaDao::showAll()
{
	std::vector<StudentEdukacja*> toSort = wczytaj;
	std::sort(toSort.begin(), toSort.end(), StudentEdukacja::comp);

	for (auto studentEdukacja : toSort)
	{
		std::cout << studentEdukacja->toString() << "\n";
	}
}

StudentEdukacja* StudentEdukacjaDao::show(int index)
{
	std::vector<StudentEdukacja*> found;
	for (auto s : StudentEdukacjaDao::wczytaj)
	{
		if (s->getIndex() == index)
		{
			found.push_back(s);
		}
	}
	if (!found.empty())
	{
		std::cout << "\n\tStudent znaleziony i usuniety\n";
		return found[0];
		
	}
	else
	{
		std::cout << "\n\tBlad nie znaleziono studenta\n" << std::endl;
	}
	return nullptr;
}

void StudentEdukacjaDao::add(StudentEdukacja* s)
{
	StudentEdukacjaDao::wczytaj.push_back(s);
	std::cout << "\n\tDodano do listy!\n" << std::endl;
}

void StudentEdukacjaDao::del(int index)
{
	wczytaj.erase(std::remove(wczytaj.begin(), wczytaj.end(), show(index)), wczytaj.end());
}

void StudentEdukacjaDao::exit()
{
	std::ofstream baza("baza_studentow.txt");

	std::vector<StudentEdukacja*>& toSave = StudentEdukacjaDao::wczytaj;
	for (auto s : toSave)
	{
		std::string sb = s->getImie() + "\n" + s->getNazwisko() + "\n" + std::to_string(s->getWiek()) + "\n" + s->getGrupa() + "\n" + std::to_string(s->getIndex()) + "\n";
		baza << sb;
	}

}
