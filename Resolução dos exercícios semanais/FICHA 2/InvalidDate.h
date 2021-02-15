#pragma once
#include <string>

class InvalidDate
{
public:
	InvalidDate(const std::string& message) { this->message = message; };
	std::string what() const { return message; };
private:
	std::string message;
};

