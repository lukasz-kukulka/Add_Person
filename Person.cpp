#include "Person.hpp"

Person::Person(std::string firstName, 
               std::string otherNames, 
               std::string email, 
               std::string tel, 
               std::string street, 
               std::string town, 
               std::string country) : firstName_ (firstName), otherNames_ (otherNames), email_(email), tel_(tel), street_(street), town_(town), country_(country){
}

