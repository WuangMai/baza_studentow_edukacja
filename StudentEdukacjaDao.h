#pragma once

#include "StudentEdukacja.h"
#include <string>
#include <vector>
#include <iostream>

class StudentEdukacjaDao
{

public:
	static std::vector<StudentEdukacja*> wczytaj;
private:
	static std::vector<StudentEdukacja*> load();

public:
	virtual void showAll();

	virtual StudentEdukacja* show(int index);

	virtual void add(StudentEdukacja* s);

	virtual void del(int index);

	virtual void exit();
};
