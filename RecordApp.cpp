#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <algorithm>

#include "RecordApp.hpp"


void RecordApp::startApp(){

    ////////////////////////////////////////////////////test only
    // person_.reserve(1000000);
    // std::string a = "a";
    // Person temp(a, a, a, a, a, a, a);
    // for (int i = 0; i < 1000000; i++){
    //     person_.push_back(Person(temp));
    // }
    //std::cout << person_.size() << "\n";
    //searchByName("a");
    ///////////////////////////////////////////////////////////// del after test
    
    loadFromFile();
    printMenu();
    menuAction();
    //std::cout << searchResult_.size() << "\n";
    
}

void RecordApp::printMenu(){
    std::cout << " ---------------------------------- \n";
    std::cout << "|                MENU:             |\n";
    std::cout << " ----------------------------------\n";
    std::cout << "|                                  |\n";
    std::cout << "| 1. Add person                    |\n";
    std::cout << "| 2. Search                        |\n";
    std::cout << "| 3. Exit                          |\n";
    std::cout << "|                                  |\n";
    std::cout << " ----------------------------------\n";
}

void RecordApp::menuAction(){
    do{
        std::cout << "CHOOSE YOUR OPTION: ";
        std::cin >> optionMenu_;
        menuOption_ = static_cast<RecordApp::MenuOption>(optionMenu_);
        switch (menuOption_)
        {
            case MenuOption::add : {
            addPerson();  
            } break;
            case MenuOption::search: {
                
            } break;
            case MenuOption::exit : {
                exitApp();
                exit_ = true;
            } break;
            default : {
            
            } break;
        }

    } while (exit_ == true);

}

void RecordApp::addPerson(){
    addName();
    addOtherNames();
    addEmail();
    addTelephoneNumber();
    addAddress();
    person_.push_back(Person(firstName_, otherNames_, email_, tel_, street_, town_, country_));
}

void RecordApp::searchPerson(){
    printSearchMenu();
    menuActionSearch();
}

void RecordApp::exitApp(){
    for (int i = 0; i < static_cast<int>(person_.size()); i++){
        saveToFile(i);
    }
}

void RecordApp::addName(){
    do{
        std::cout << "Enter your name: ";
        std::cin >> firstName_;
        std::cout << "\n";
    } while (validName() == false);

}

void RecordApp::addOtherNames(){
    do{
        std::cout << "Enter your other names: ";
        std::cin >> otherNames_;
        std::cout << "\n";
    } while (validOtherNames() == false);
}

void RecordApp::addEmail(){
    do{
        std::cout << "Enter your email address: ";
        std::cin >> email_;
        std::cout << "\n";
    } while (validEmail() == false);
}

void RecordApp::addTelephoneNumber(){
    do{
        std::cout << "Enter your telephone number: ";
        std::cin >> tel_;
        std::cout << "\n";
    } while (validTelephoneNumber() == false);
}

void RecordApp::addAddress(){
    std::cout << "Enter your home address: \n";
    addStreet();
    addTown();
    addCountry();
}

void RecordApp::addStreet(){
    do{
        std::cout << "Street: ";
        std::cin >> street_;
        std::cout << "\n";
    } while (validStreet() == false);
}

void RecordApp::addTown(){
    do{
        std::cout << "Town: ";
        std::cin >> town_;
        std::cout << "\n";
    } while (validTown() == false);
}
    
void RecordApp::addCountry(){
    do{
        std::cout << "Country ";
        std::cin >> country_;
        std::cout << "\n";
    } while (validCountry() == false);
}
    
bool RecordApp::ifStringIsAlphabetChar(std::string value){
    if (std::all_of(value.begin(), value.end(), [](char i){return std::isalpha(i);})) {
        return true;
    } else {
        std::cout << "Minimum one character is not alphabetic\n";
        return false;
    }
}

bool RecordApp::maxLengthCheck(int index, std::string word){
    if (index >= static_cast<int>(word.size())){
        std::cout << "Maximum length is " << index << "\n";
        return false;
    }
    return true;
}

bool RecordApp::validName(){
    std::system("clear");
    ifInsertingStringIsCorrect = true;
    ifInsertingStringIsCorrect = ifStringIsAlphabetChar(firstName_);
    ifInsertingStringIsCorrect = maxLengthCheck(30, firstName_);
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validOtherNames(){
    std::system("clear");
    ifInsertingStringIsCorrect = true;
    ifInsertingStringIsCorrect = ifStringIsAlphabetChar(otherNames_);
    ifInsertingStringIsCorrect = maxLengthCheck(50, otherNames_);
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validEmail(){
    std::system("clear");
    ifInsertingStringIsCorrect = true;
    auto countAt = std::count(email_.begin(), email_.end(), '@');
    auto countPoint = std::count(email_.begin(), email_.end(), '.');
    if (countAt!= 1 || countPoint != 1){
        ifInsertingStringIsCorrect = false;
        std::cout << "Email address is not correct\n";
    }
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validTelephoneNumber(){
    std::system("clear");
    ifInsertingStringIsCorrect = true;
    ifInsertingStringIsCorrect = maxLengthCheck(10, tel_);
    if (!std::all_of(tel_.begin(), tel_.end(), [](char i){return std::isdigit(i);})) {
        std::cout << "Not all character is digit\n";
        ifInsertingStringIsCorrect = false;
    }
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validStreet(){
    //TO DO
    return true;
}

bool RecordApp::validTown(){
    //TO DO
    return true;
}

bool RecordApp::validCountry(){
    //TO DO
    return true;
}

bool RecordApp::validValueToFind(){
    //TO DO
    return true;
}


void RecordApp::saveToFile(int index){
    std::fstream file;
    file.open("records.txt", std::ios::out | std::ios::app);
    file << "[Person nr: " << index + 1 << "]\n";
    file << person_[index].getFirstName() << "\n";
    file << person_[index].getOthersName() << "\n";
    file << person_[index].getEmail() << "\n";
    file << person_[index].getTel() << "\n";
    file << person_[index].getStreet() << "\n";
    file << person_[index].getTown() << "\n";
    file << person_[index].getCountry() << "\n\n";
    file.close();
}

void RecordApp::loadFromFile(){
    person_.reserve(countRecord());
    int lineNo = 1;
	std::string line;
	std::fstream file;
	file.open("records.txt", std::ios::in);
	if (file.good() == false)
	{
		std::cout << "Created new file\n";
		file.open("records.txt", std::ios::out | std::ios::app);
	}
	while (getline(file, line)){
       
        switch (lineNo){
            case 2: { firstName_ = line; break;}
            case 3: { otherNames_ = line; break;}
            case 4: { email_ = line; break;}
            case 5: { tel_ = line; break;}
            case 6: { street_ = line; break;}
            case 7: { town_ = line; break;}
            case 8: { country_= line; break;}   
        }
        lineNo++;
        if (lineNo == 9){
            lineNo = 2;
            person_.push_back(Person(firstName_, otherNames_, email_, tel_, street_, town_, country_));
        } 
	}
    file.close();
}

int RecordApp::countRecord(){
    int lineNo = 0;
	std::string line;
	std::fstream file;
	file.open("records.txt", std::ios::in);
	if (file.good() == false)
	{
		std::cout << "Created new file\n";
		file.open("records.txt", std::ios::out | std::ios::app);
	}
	while (getline(file, line)){
        lineNo++;
    }
    file.close();
	return lineNo / 9;
}

void RecordApp::printSearchMenu(){
    std::cout << " ---------------------------------- \n";
    std::cout << "|      Criteria of serching:       |\n";
    std::cout << " ----------------------------------\n";
    std::cout << "|                                  |\n";
    std::cout << "| 1. Name                          |\n";
    std::cout << "| 2. Others names                  |\n";
    std::cout << "| 3. Email                         |\n";
    std::cout << "| 4. Telephone number              |\n";
    std::cout << "| 5. Street                        |\n";
    std::cout << "| 6. Town                          |\n";
    std::cout << "| 7. Country                       |\n";
    std::cout << "| 8. Back to menu                  |\n";
    std::cout << "|                                  |\n";
    std::cout << " ----------------------------------\n";
}

void RecordApp::menuActionSearch(){
    do{
        exitFromSearch_ = false;
        std::cout << "CHOOSE WITH KIND SEARCH YOU WILL USE: ";
        std::cin >> optionMenu_;
        menuChooseOption_ = static_cast<RecordApp::ChooseMenu>(optionMenu_);
        switch (menuChooseOption_)
        {
            case ChooseMenu::name : { 
                whatKindSearch_ = "name";
                insertValueToSearch();
                searchByName(insertValueToFind_);
            } break;
            case ChooseMenu::otherNames : {
                whatKindSearch_ = "other names";
                insertValueToSearch();
                searchByOtherNames(insertValueToFind_);
            } break;
            case ChooseMenu::mail : {
                whatKindSearch_ = "email";
                insertValueToSearch();
                searchByEmail(insertValueToFind_);
            } break;
            case ChooseMenu::tel : {
                whatKindSearch_ = "telephone number";
                insertValueToSearch();
                searchByTel(insertValueToFind_);
            } break;
            case ChooseMenu::street : {
                whatKindSearch_ = "street";
                insertValueToSearch();
                searchByStreet(insertValueToFind_);
            } break;
            case ChooseMenu::town : {
                whatKindSearch_ = "town";
                insertValueToSearch();
                searchByTown(insertValueToFind_);
            } break;
            case ChooseMenu::country : {
                whatKindSearch_ = "country";
                insertValueToSearch();
                searchByCountry(insertValueToFind_);
            } break;
            // case ChooseMenu::exit : {
            //     exitFromSearch_ = true;
            // } break;
            default : {
                
            } break;
        }

    } while (exitFromSearch_ == true);

}

void RecordApp::insertValueToSearch(){
    do{
        std::cout << "Search by "<< whatKindSearch_ << ". Please insert value to search ";
        std::cin >> insertValueToFind_;
    } while (validValueToFind() == false);
    
}

void RecordApp::searchByName(std::string name){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getFirstName() == name){
            searchResult_.insert({iterator_, element});
        }
    }
}

void RecordApp::searchByOtherNames(std::string otherNames){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getOthersName() == otherNames){
            searchResult_.insert({iterator_, element});
        }
    }
}

void RecordApp::searchByEmail(std::string email){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getEmail() == email){
            searchResult_.insert({iterator_, element});
        }
    }
}

void RecordApp::searchByTel(std::string tel){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getTel() == tel){
            searchResult_.insert({iterator_, element});
        }
    }
}

void RecordApp::searchByStreet(std::string street){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getStreet() == street){
            searchResult_.insert({iterator_, element});
        }
    }
}

void RecordApp::searchByTown(std::string town){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getTown() == town){
            searchResult_.insert({iterator_, element});
        }
    }
}

void RecordApp::searchByCountry(std::string country){
    searchResult_.clear();
    iterator_ = 0;
    for (auto const &element : person_){
        if (element.getCountry() == country){
            searchResult_.insert({iterator_, element});
        }
    }
}

// void RecordApp::printSearchPersons(){
//     std::cout << " "
// }