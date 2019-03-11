#include "Address.h"

Address::Address()
{
	name;
	street;
	postal;
	city;
	state;
	email;
}

Address::Address(string name_, string street_, int postal_, string city_, string state_, string email_)
{
	name = name_;
	transform(name.begin(), name.end(), name.begin(), ::tolower);

	street = street_;
	transform(street.begin(), street.end(), street.begin(), ::tolower);

	postal = postal_;

	city = city_;
	transform(city.begin(), city.end(), city.begin(), ::tolower);

	state = state_;
	transform(state.begin(), state.end(), state.begin(), ::tolower);

	email = email_;
	transform(email.begin(), email.end(), email.begin(), ::tolower);
}

string Address::get_name()
{
	return name;
}

string Address::get_street()
{
	return street;
}

int Address::get_postal()
{
	return postal;
}

string Address::get_city()
{
	return city;
}

string Address::get_state()
{
	return state;
}

string Address::get_email()
{
	return email;
}

void Address::set_name(string new_name)
{
	name = new_name;
}

void Address::set_street(string new_street)
{
	street = new_street;
}

void Address::set_postal(int new_postal)
{
	postal = new_postal;
}

void Address::set_city(string new_city)
{
	city = new_city;
}

void Address::set_state(string new_state)
{
	state = new_state;
}

void Address::set_email(string new_email)
{
	email = new_email;
}

bool Address::operator<(Address other)
{
	if (state < other.get_state())
	{
		return true;
	}
	else if (state > other.get_state())
	{
		return false;
	}

	//if equal, do nothing, continue through to evaluate city

	else if (city < other.get_city())
	{
		return true;
	}
	else if (city > other.get_city())
	{
		return false;
	}

	//if equal, do nothing, continue through to evaluate name

	else if (name < other.get_name()) 
	{
		return true;
	}
	else if (name > other.get_name())
	{
		return false;
	}

	return false;
	
}

bool Address::operator==(Address other)
{
	if (state != other.get_state())
	{
		return false;
	}

	//if equal, do nothing, continue through to evaluate city

	else if (city != other.get_city())
	{
		return false;
	}

	//if equal, do nothing, continue through to evaluate name

	else if (name != other.get_name())
	{
		return false;
	}

	return true;
}
