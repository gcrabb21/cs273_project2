#include <string>
#include <algorithm>
using std::string;

#ifndef ADDRESS_H_
#define ADDRESS_H_

class Address {
private:
	string name;
	string street;
	int postal;
	string city;
	string state;
	string email;
public:
	Address();
	Address(string name_, string street_, int postal_, string city_, string state_, string email_);

	string get_name();
	string get_street();
	int get_postal();
	string get_city();
	string get_state();
	string get_email();

	void set_name(string new_name);
	void set_street(string new_street);
	void set_postal(int new_postal);
	void set_city(string new_city);
	void set_state(string new_state);
	void set_email(string new_email);

	bool operator<(Address other);
	bool operator>(Address other);
	bool operator==(Address other);
	bool operator!=(Address other);
};

#endif