#pragma once

#include <string>

class StudentEdukacja
{
private:
	std::string imie;
	std::string nazwisko;
	int wiek = 0;
	std::string grupa;
	int index;

public:
	static bool comp(const StudentEdukacja* first, const StudentEdukacja* second);

	StudentEdukacja(const std::string& imie, const std::string& nazwisko, int wiek, const std::string& grupa, int index);

	StudentEdukacja();

	virtual std::string getImie();

	virtual std::string toString();

	virtual void setImie(const std::string& imie);

	virtual std::string getNazwisko();

	virtual void setNazwisko(const std::string& nazwisko);

	virtual int getWiek();

	virtual void setWiek(int wiek);

	virtual std::string getGrupa();

	virtual void setGrupa(const std::string& grupa);

	virtual int getIndex();

	virtual void setIndex(int index);
};
