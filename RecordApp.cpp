#include "RecordApp.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <limits>
#include <ios>


void RecordApp::startApp(){
    std::system("clear");
    loadFromFile();
    //std::cout << person_[0].getFirstName();
    menuAction();
    //std::cout << "|      ---------------------------------------------------------------------------------------------------------------      |\n";
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
        printMenu();
        
        std::cout << "CHOOSE YOUR OPTION: ";
        std::cin >> optionMenu_;
        menuOption_ = static_cast<RecordApp::MenuOption>(optionMenu_);
        switch (menuOption_)
        {
            case MenuOption::add : {
                std::system("clear");
                std::cout << "ADDING PERSON TO DATA BASE\n";
                addPerson(); 
            } break;
            case MenuOption::search: {
                std::system("clear");
                searchPerson();
            } break;
            case MenuOption::exit : {
                std::system("clear");
                exitApp();
            } break;
            default : {
                std::cout << "Wrong value, choose again\n";
                
            } break;
        }
    } while (menuOption_ != MenuOption::exit);
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void RecordApp::addPerson(){
    addName();
    addOtherNames();
    addEmail();
    addTelephoneNumber();
    addAddress();
    person_.push_back(Person(firstName_, otherNames_, email_, tel_, street_, town_, country_));
    saveToFile(static_cast<int>(person_.size() - 1));
    std::cout << "You added person.";
    std::cout << "\n               Name: " << firstName_ 
              << "\n               Other names: " << otherNames_
              << "\n               Email: " << email_
              << "\n               Tel.: " << tel_
              << "\n               Address: Street: " << street_
              << "\n                        Town: " << town_
              << "\n                        Country " << country_ << "\n";
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
        std::cout << "Enter name: ";
        std::cin >> firstName_;
    } while (validName() == false);

}

void RecordApp::addOtherNames(){
    do{
        std::cout << "Enter other names: ";
        std::cin >> otherNames_;
    } while (validOtherNames() == false);
}

void RecordApp::addEmail(){
    do{
        std::cout << "Enter email address: ";
        std::cin >> email_;
    } while (validEmail() == false);
}

void RecordApp::addTelephoneNumber(){
    do{
        std::cout << "Enter telephone number: ";
        std::cin >> tel_;
    } while (validTelephoneNumber() == false);
}

void RecordApp::addAddress(){
    std::cout << "Enter home address: \n";
    addStreet();
    addTown();
    addCountry();
}

void RecordApp::addStreet(){
    do{
        std::cout << "Street: ";
        std::cin >> street_;
    } while (validStreet() == false);
}

void RecordApp::addTown(){
    do{
        std::cout << "Town: ";
        std::cin >> town_;
    } while (validTown() == false);
}
    
void RecordApp::addCountry(){
    do{
        std::cout << "Country ";
        std::cin >> country_;
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
    if (index <= static_cast<int>(word.size())){
        std::cout << "Maximum length is " << index << "\n";
        return false;
    }
    return true;
}

bool RecordApp::validName(){
    ifInsertingStringIsCorrect = true;
    if (ifStringIsAlphabetChar(firstName_) == false || maxLengthCheck(30, firstName_) == false) {
        ifInsertingStringIsCorrect = false;
    }
    return ifInsertingStringIsCorrect;
}
bool RecordApp::validOtherNames(){
    ifInsertingStringIsCorrect = true;
    if (ifStringIsAlphabetChar(otherNames_) == false || maxLengthCheck(50, otherNames_) == false) {
        ifInsertingStringIsCorrect = false;
    }
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validEmail(){
    ifInsertingStringIsCorrect = true;
    auto countAt = std::count(email_.begin(), email_.end(), '@');
    auto countPoint = std::count(email_.begin(), email_.end(), '.');
    if (countAt != 1 || countPoint != 1){
        ifInsertingStringIsCorrect = false;
        std::cout << "Email address is not correct\n";
    }
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validTelephoneNumber(){

    ifInsertingStringIsCorrect = true;
    if (tel_.size() != 10){
        std::cout << "Telephone number should have 10 diggit number\n";
        ifInsertingStringIsCorrect = false;
    }
    if (!std::all_of(tel_.begin(), tel_.end(), [](char i){return std::isdigit(i);})) {
        std::cout << "Not all character is digit\n";
        ifInsertingStringIsCorrect = false;
    }
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validStreet(){
    ifInsertingStringIsCorrect = true;
    if (ifStringIsAlphabetChar(street_) == false || maxLengthCheck(50, street_) == false) {
        ifInsertingStringIsCorrect = false;
    }
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validTown(){
    ifInsertingStringIsCorrect = true;
    if (ifStringIsAlphabetChar(town_) == false || maxLengthCheck(50, town_) == false) {
        ifInsertingStringIsCorrect = false;
    }
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validCountry(){
    ifInsertingStringIsCorrect = true;
    if (ifStringIsAlphabetChar(country_) == false || maxLengthCheck(50, country_) == false) {
        ifInsertingStringIsCorrect = false;
    }
    return ifInsertingStringIsCorrect;
}

bool RecordApp::validValueToFind(){

    // if (askIfStopSearch() == RecordApp::StateStatus::back){
    //     return false;
    // }
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
        if (lineNo > 9){
            lineNo = 1;
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
        std::cin >> optionSearchMenu_;
        menuChooseOption_ = static_cast<RecordApp::ChooseMenu>(optionSearchMenu_);
        
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
            case ChooseMenu::exit : {
                std::system("clear");
                exitFromSearch_ = true;
            } break;
            default : {
                std::cout << "Wrong value, choose again\n";
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } break;
        }
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (exitFromSearch_ != true);

}

void RecordApp::insertValueToSearch(){
    do{
        std::cout << "Search by "<< whatKindSearch_ << ". Please insert value to search:\n";
        std::cin >> insertValueToFind_ ;
        //std::cout << insertValueToFind_ << "  <- insertValueToFind_    #####################################################    tab->  " << searchResult_.at(0).getFirstName();
    } while (validValueToFind() == false);
}

void RecordApp::askIfStopSearch(){
    int result = 0;
    
    if (searchResult_.size() == 0){
        do{
            std::cout << "I can't find this value, what you wanna do: \n";
            std::cout << "1. Try insert again. \n";
            std::cout << "2. Back \n";
            //std::cin.clear();
            std::cin >> result;
            stateStatus_ = static_cast<StateStatus>(result);
        }while (stateStatus_ != StateStatus::tryInsterAgain && stateStatus_ != StateStatus::back);
        exitFromSearch_ = true;
    } else {
        actionAfterSearch();
    }
}

void RecordApp::searchByName(std::string name){
    searchResult_.clear();

    for (auto const& element : person_){
        if (element.getFirstName() == name){
            searchResult_.insert({iterator_, element});
        }
    }
    askIfStopSearch();
}

void RecordApp::searchByOtherNames(std::string otherNames){
    searchResult_.clear();
    for (auto const& element : person_){
        
        if (element.getOthersName() == otherNames){
            searchResult_.insert({iterator_, element});
        }
    }
    askIfStopSearch();
}

void RecordApp::searchByEmail(std::string email){
    searchResult_.clear();
    iterator_ = 0;
    for (auto const& element : person_){
        //std::cout << element.getEmail() << "  <<------  INSIDE EMAIL SEARCH ----->" << email << "\n";
        if (element.getEmail() == email){
            //std::cout << "INSIDE EMAIL SEARCH \n";
            
            searchResult_.insert({iterator_, element});
        }
        iterator_++;
    }
    askIfStopSearch();
}

void RecordApp::searchByTel(std::string tel){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getTel() == tel){
            searchResult_.insert({iterator_, element});
        }
    }
    askIfStopSearch();
}

void RecordApp::searchByStreet(std::string street){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getStreet() == street){
            searchResult_.insert({iterator_, element});
        }
    }
    askIfStopSearch();
}

void RecordApp::searchByTown(std::string town){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getTown() == town){
            searchResult_.insert({iterator_, element});
        }
    }
    askIfStopSearch();
}

void RecordApp::searchByCountry(std::string country){
    searchResult_.clear();
    iterator_ = 0;
    for (auto const &element : person_){
        if (element.getCountry() == country){
            searchResult_.insert({iterator_, element});
        }
        iterator_++;
    }
    askIfStopSearch();
}

void RecordApp::printSearchPersons(){
    for(auto const & element : searchResult_){
        selectPerson_ = element.first;
        std::cout << "ID in database: " << element.first << " | "
                  << "First name: " << element.second.getFirstName() << " | "
                  << "Other names: " << element.second.getOthersName() << " | "
                  << "Email: " << element.second.getEmail() << " | "
                  << "Telephone number: " << element.second.getTel() << " | "
                  << "Street: " << element.second.getStreet() << " | "
                  << "Town: " << element.second.getTown()<< " | "
                  << "Country: " << element.second.getCountry() << "\n";
    }
}

RecordApp::StateStatus RecordApp::actionAfterSearch(){
    int chooseActionInPlayerSearch = 0;
    printSearchPersons();
    std::cout << "Insert ID with person you wanna choose: ";
    std::cin >> selectPerson_;
    do{
        std::cout << "What you wanna do: \n";
        std::cout << "1. Delete: \n";
        std::cout << "2. Back: \n";
        std::cin >> chooseActionInPlayerSearch;
        stateStatus_ = static_cast<StateStatus>(chooseActionInPlayerSearch);
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (stateStatus_ != StateStatus::deleteItem && stateStatus_ != StateStatus::back);
    return stateStatus_;
}


