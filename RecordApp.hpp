#pragma once
#include <vector>
#include <map>
#include <memory>

#include "Person.hpp"

class RecordApp{

public:
    void startApp();

    enum class MenuOption {
        add = 1,
        search,
        exit
    };

    enum class ChooseMenu {
        name = 1,
        otherNames,
        mail,
        tel,
        street,
        town,
        country,
        exit
    };

    enum class StateStatus {
            back = 1,
            tryInsterAgain,
            deleteItem
    } stateStatus_;

    
private:

    void printMenu();
    void menuAction();
    void addPerson();
    void searchPerson();
    void exitApp();

    void addName();
    void addOtherNames();
    void addEmail();
    void addTelephoneNumber();
    void addAddress();
    void addStreet();
    void addTown();
    void addCountry();

    bool validName();
    bool validOtherNames();
    bool validEmail();
    bool validTelephoneNumber();
    bool validStreet();
    bool validTown();
    bool validCountry();
    bool validValueToFind();
    bool ifStringIsAlphabetChar(std::string);
    bool maxLengthCheck(int, std::string);

    void saveToFile(int);
    void resaveToFile();
    void loadFromFile();
    int countRecord();
    void deleteRecord();
    
    void printSearchMenu();
    void menuActionSearch();
    void insertValueToSearch();

    void searchByName(std::string);
    void searchByOtherNames(std::string);
    void searchByEmail(std::string);
    void searchByTel(std::string);
    void searchByStreet(std::string);
    void searchByTown(std::string);
    void searchByCountry(std::string);

    void printSearchPersons();
    StateStatus actionAfterSearch();
    void askIfStopSearch();
    


    std::vector<Person>person_;
    //std::vector<Person>searchResult_;
    std::map<int, Person>searchResult_;
    MenuOption menuOption_ { MenuOption::add };
    ChooseMenu menuChooseOption_ { ChooseMenu::name };
    int optionMenu_ { 0 };
    int optionSearchMenu_ { 0 };
    std::string firstName_;
    std::string otherNames_;
    std::string email_;
    std::string tel_;
    std::string street_;
    std::string town_;
    std::string country_;
    bool exit_ { false };
    bool exitFromSearch_ { false };
    std::string whatKindSearch_ { "" };
    std::string insertValueToFind_ { "" };
    int iterator_ { 0 };
    bool ifInsertingStringIsCorrect { true };
    int selectPerson_ = { 0 };
};
