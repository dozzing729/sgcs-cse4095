#include <iostream>
#include <cstring>
#include <string>

#define LENID 8
#define LENNUM 13
#define LENBIR 10
#define STDMAXBUF 256

using namespace std;

class Student{
private:
    char id[LENID];
    string name;
    char number[LENNUM];
    char birthday[LENBIR];
public:
    Student();
    Student(const char * new_id);
    Student(const Student& s);

    Student & operator=(const Student & s);
    bool operator == (const Student & s);
    bool operator != (const Student & s);

    friend istream & operator >> (istream & is, Student & s);
    friend ostream & operator << (ostream & os, Student & s);

    void update_id(const char * new_id);
    void update_name(const string new_name);
    void update_number(const char * new_number);
    void update_birthday(const char * new_birthday);
};

istream & operator >> (istream & is, Student & s);
ostream & operator << (ostream & os, Student & s);
