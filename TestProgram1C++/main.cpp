#include <iostream>
#include <iomanip>
#include <ios>
#include <limits>
#include <string>
#include <cmath>

/*
int main(){
    std::cout << "Insert catalyst: " << std::endl;
    char catalyst;
    std::cin >> catalyst;

    std::cout << "Insert magic core:" << std::endl;
    char magicCore;
    std::cin >> magicCore;

    std::cout << "Insert modifiers:" << std::endl;
    char modifier;
    std::cin >> modifier;

    std::cout << catalyst << magicCore << modifier;
}
*/
/*int userInputFunc(std::string userFullName, std::string userBirth, std::string userHeight, std::string userHairColor){
    int firstNameEnd = userFullName.find(' ');
    char firstName[20];
    char lastName[20];

    std::size_t strLengthFirst = userFullName.copy(firstName,firstNameEnd,0);
    std::size_t strLengthLast = userFullName.copy(lastName,userFullName.length() - firstNameEnd,firstNameEnd);

    firstName[strLengthFirst] = '\0';
    lastName[strLengthLast] = '\0';

    std::cout << "Name: "<< firstName << lastName << std::endl 
        << "Born: " << userBirth << std::endl 
        << "Height: " << userHeight  << std::endl
        << "Hair Color: " << userHairColor << std::endl;

    return 0;
}*/


//int main(){
    /*std::string testString = "Hello fucker";
    std::string filter[] = {"fuck", "shit", "hell"};
    std::cout << testString.find(filter[0]) << std::endl;
    std::cout << sqrt(9) << std::endl;
    std::cout << pow(5,2) << std::endl;

    int number1{1};
    int number2{3};

    std::string name2;

    std::getline(std::cin, name2);

    std::cout << name2 << std::endl;

    std::cout << fmax(number1, number2) << std::endl;*/
   /* std::string hairColor;
    std::string fullName;
    std::string height;
    std::string birthDate;
    std::string heightAndHair;

    std::cout << "Please enter your full name." << std::endl;
    std::getline(std::cin, fullName);

    std::cout << "Please enter your birthdate." << std::endl;
    std::getline(std::cin, birthDate);

    std::cout << "Please enter your height and hair color" << std::endl;
    std::getline(std::cin, heightAndHair);


    int textEnd; 
    if (heightAndHair.find(' ')!=std::string::npos){

        char findHeight[20];
        char findHairColor[20];*/

        // Seperates the two words into their owns vars/arrays.

        /*if (heightAndHair.find(",")!=std::string::npos){


            heightAndHair.erase(heightAndHair.find(","), 1);
        }
        else if (heightAndHair.find(".")!=std::string::npos){
            heightAndHair.erase(heightAndHair.find("."), 1);
        }

        textEnd = heightAndHair.find(' '); // Finds space inbetween answers to determine the start and end of each answer

        std::size_t strLengthHeight = heightAndHair.copy(findHeight,textEnd,0);
        std::size_t strLengthHair = heightAndHair.copy(findHairColor,heightAndHair.length() - textEnd - 1,textEnd + 1);

        findHeight[strLengthHeight] = '\0';
        findHairColor[strLengthHair] = '\0';

        hairColor = findHairColor;
        height = findHeight;

        userInputFunc(fullName, birthDate, height, hairColor);
    }
    else{
        std::cout << "Please enter valid answer." << std::endl;
    }


    return 0;
}*/

int userInputFunc(int invCount, std::string inventory[]){

    if (invCount == 0){
        std::cout << "Inventory is empty." << std::endl;
    }
    else{
        for (int i = 0; i <= invCount; i++){
            std::cout << inventory[i] << std::endl;
        }
    }

    return 0;
}

std::string userInventoryAdd(int invCount, std::string inventory[]){

        std::cout << "Pick up an item" << std::endl;
        std::cin >> inventory[invCount];

        std::cout << "Picked up: " << inventory[invCount] << std::endl;

    return inventory[invCount];
}

int main(){

    char userInput;
    std::string inventory[10];
    int invCount{0};
    bool isInv = false;

    while (userInput != 'e'){
        std::cin >> userInput;
    
        if (userInput == 'e'){
            std::cout << "Closed program";
        }
        else if (userInput == 'f'){
            userInputFunc(invCount, inventory);
        }
        else if (userInput == 'g'){
            if (invCount == 9){
                std::cout << "Your inventory is full!" << std::endl;
            }
            else{
                inventory[invCount] = userInventoryAdd(invCount, inventory);
                invCount++;
            }
        }
    }
    return 0;
}