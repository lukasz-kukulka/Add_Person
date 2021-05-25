#include <iostream>
#include <fstream>

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
    


bool RecordApp::validName(){
    //TO DO
    return true;
}

bool RecordApp::validOtherNames(){
    //TO DO
    return true;
}

bool RecordApp::validEmail(){
    //TO DO
    return true;
}

bool RecordApp::validTelephoneNumber(){
    //TO DO
    return true;
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
                whatKindSearch = "name";
                insertValueToSearch();
                searchByName(insertValueToFind);
            } break;
            case ChooseMenu::otherNames : {
                whatKindSearch = "other names";
                insertValueToSearch();
            } break;
            case ChooseMenu::mail : {
                whatKindSearch = "email";
                insertValueToSearch();
            } break;
            case ChooseMenu::tel : {
                whatKindSearch = "telephone number";
                insertValueToSearch();
            } break;
            case ChooseMenu::street : {
                whatKindSearch = "street";
                insertValueToSearch();
            } break;
            case ChooseMenu::town : {
                whatKindSearch = "town";
                insertValueToSearch();
            } break;
            case ChooseMenu::country : {
                whatKindSearch = "country";
                insertValueToSearch();
            } break;
            case ChooseMenu::exit : {
                exitFromSearch_ = true;
            } break;
            default : {
                
            } break;
        }

    } while (exitFromSearch_ == true);

}

void RecordApp::insertValueToSearch(){
    do{
        std::cout << "Search by "<< whatKindSearch << ". Please insert value to search ";
        std::cin >> insertValueToFind;
    } while (validValueToFind() == false);
    
}

void RecordApp::searchByName(std::string name){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getFirstName() == name){
            searchResult_.push_back(Person(element));
        }
    }
}

void RecordApp::searchByOtherNames(std::string otherNames){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getOthersName() == otherNames){
            searchResult_.push_back(Person(element));
        }
    }
}

void RecordApp::searchByEmail(std::string email){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getEmail() == email){
            searchResult_.push_back(Person(element));
        }
    }
}

void RecordApp::searchByTel(std::string tel){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getTel() == tel){
            searchResult_.push_back(Person(element));
        }
    }
}

void RecordApp::searchByStreet(std::string street){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getStreet() == street){
            searchResult_.push_back(Person(element));
        }
    }
}

void RecordApp::searchByTown(std::string town){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getTown() == town){
            searchResult_.push_back(Person(element));
        }
    }
}

void RecordApp::searchByCountry(std::string country){
    searchResult_.clear();
    for (auto const& element : person_){
        if (element.getCountry() == country){
            searchResult_.push_back(Person(element));
        }
    }
}