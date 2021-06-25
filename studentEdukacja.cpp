#include "StudentEdukacja.h"

bool StudentEdukacja::comp(const StudentEdukacja* first, const StudentEdukacja* second)
{
	return first->index < second->index;
}

StudentEdukacja::StudentEdukacja(const std::string& imie, const std::string& nazwisko, int wiek, const std::string& grupa, int index)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->wiek = wiek;
	this->grupa = grupa;
	this->index = index;
}

StudentEdukacja::StudentEdukacja()
{
}

std::string StudentEdukacja::getImie()
{
	return imie;
}

std::string StudentEdukacja::toString()
{
	return "\n\tImie= " + imie + "\n" + "\tNazwisko= " + nazwisko + "\n" + "\tWiek= " + std::to_string(wiek) + "\n" + "\tGrupa= " + grupa + "\n" + "\tIndex= " + std::to_string(index) + "\n- - - - - - - - - - - - - - ";
}



void StudentEdukacja::setImie(const std::string& imie)
{
	this->imie = imie;
}

std::string StudentEdukacja::getNazwisko()
{
	return nazwisko;
}

void StudentEdukacja::setNazwisko(const std::string& nazwisko)
{
	this->nazwisko = nazwisko;
}

int StudentEdukacja::getWiek()
{
	return wiek;
}

void StudentEdukacja::setWiek(int wiek)
{
	this->wiek = wiek;
}

std::string StudentEdukacja::getGrupa()
{
	return grupa;
}

void StudentEdukacja::setGrupa(const std::string& grupa)
{
	this->grupa = grupa;
}

int StudentEdukacja::getIndex()
{
	return index;
}

void StudentEdukacja::setIndex(int index)
{
	this->index = index;
}
