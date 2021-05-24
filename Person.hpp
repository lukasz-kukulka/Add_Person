#pragma once
#include <string>

class Person{

public:
    Person(std::string, std::string, std::string, std::string, std::string, std::string, std::string);

    std::string getFirstName() const { return firstName_; }
    std::string getOthersName() const { return otherNames_; }
    std::string getEmail() const { return email_; }
    std::string getTel() const { return tel_; }
    std::string getStreet() const { return street_; }
    std::string getTown() const { return town_; }
    std::string getCountry() const { return country_; }

    
private:
    std::string firstName_;
    std::string otherNames_;
    std::string email_;
    std::string tel_;
    std::string street_;
    std::string town_;
    std::string country_;
};