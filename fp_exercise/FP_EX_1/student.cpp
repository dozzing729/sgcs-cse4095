#include "student.h"
#include <sstream>

using namespace std;

Student::Student() { }

Student::Student(const char* new_id) {
	update_id(new_id);
}

Student::Student(const Student & s) {
	update_id(s.id);
	update_name(s.name);
	update_number(s.number);
	update_birthday(s.birthday);
}

Student& Student::operator=(const Student & s){
	update_id(s.id);
	update_name(s.name);
	update_number(s.number);
	update_birthday(s.birthday);
	return *this;
}

bool Student::operator == (const Student & s) {
	if (memcmp(id, s.id, 8) == 0) return true;
	else return false;
}

bool Student::operator != (const Student & s) {
	if (memcmp(id, s.id, 8) == 0) return false;
	else return true;
}

void Student::update_id(const char * new_id) {
	memcpy(id, new_id, LENID);
}

void Student::update_name(const string new_name) {
	name = new_name;
}

void Student::update_number(const char * new_number) {
	memcpy(number, new_number, LENNUM);
}

void Student::update_birthday(const char * new_birthday) {
	memcpy(birthday, new_birthday, LENBIR);
}



istream & operator >> (istream & is, Student & s) {
	string tmp;

	is.exceptions(istream::failbit | istream::badbit);
	try {
		getline(is, tmp);
	}
	catch (istream::failure err) {
		return is;
	}

	istringstream iss(tmp);
	string tmp2;

	getline(iss, tmp2, '|');
	s.update_id(tmp2.data());
	getline(iss, tmp2, '|');
	s.update_name(tmp2);
	getline(iss, tmp2, '|');
	s.update_number(tmp2.data());
	getline(iss, tmp2, '|');
	s.update_birthday(tmp2.data());

	return is;
}

ostream & operator << (ostream & os, Student & s) {
	string id(s.id, LENID);
	string number(s.number, LENNUM);
	string birthday(s.birthday, LENBIR);

	os << "ID : " << id << endl;
	os << "NAME : " << s.name << endl;
	os << "NUMBER : " << number << endl;
	os << "BIRTHDAY : " << birthday << endl;
	return os;
}
