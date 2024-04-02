#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ios>
#include <limits>
#include <ctime>

int main(){
    double userHP{213.0};
    double enemyHP{230.0};
    srand(time(NULL));

    char userInput;
    int randNum;
    bool playerTurn = true;

    while (userInput != 'e'){
        randNum = (rand() % 3);

        if (playerTurn == true){

            std::cout << "Choose your attack method!" << std::endl << "A: Slash" << std::endl << "B: Heavy attack" << std::endl;
            std::cin >> userInput;

            if (userInput == 'a'){
                switch (randNum){
                    case 0:
                    enemyHP -= 40;
                    std::cout << "Hit enemy for 40!" << std::endl;
                    break;

                    case 1:
                    userHP -= 30;
                    std::cout << "You missed and your enemy hit you for 30!" << std::endl;
                    break;

                    case 2:
                    std::cout << "Your enemy parried the attack!" << std::endl;
                    break;
                }

                playerTurn = false;
            }


            else if(userInput == 'b'){
                switch (randNum){
                    case 0:
                    enemyHP -= 80;
                    std::cout << "Hit enemy for 80!" << std::endl;
                    break;

                    case 1:
                    userHP -= 30;
                    std::cout << "You missed and your enemy hit you for 30!" << std::endl;
                    break;

                    case 2:
                    userHP -= 20;
                    std::cout << "Your enemy parried the attack and hit you for 20!" << std::endl;
                    break;
                }

                playerTurn = false;
            }
        }

        else{
            std::cout << "Your enemy is about to attack! Prepare your defense:" << std::endl << "A: Counter attack" << std::endl << "B: Parry attack" << std::endl;

            std::cin >> userInput;

            if (userInput == 'a'){
                switch (randNum){
                    case 0:
                    enemyHP -= 50;
                    std::cout << "You successfully counter attacked and hit your opponent for 50!" << std::endl;
                    break;

                    case 1:
                    userHP -= 40;
                    std::cout << "Your enemy was prepared and parried your counter attack! You were hit for 40!" << std::endl;
                    break;

                    case 2:
                    userHP -= 20;
                    std::cout << "Your enemy dodges your attack and hit you for 20!" << std::endl;
                    break;
                }

                playerTurn = true;
            }


            else if(userInput == 'b'){
                switch (randNum){
                    case 0:
                    std::cout << "You successfully parried the attack" << std::endl;
                    break;

                    case 1:
                    userHP -= 20;
                    std::cout << "You mistimed your parry and lost 20 HP!" << std::endl;
                    break;

                    case 2:
                    enemyHP -= 20;
                    std::cout << "Your parry left them open, and you hit your enemy for 20!" << std::endl;
                    break;
                }

                playerTurn = true;
            }
        }
    

        if (userHP <= 0){
            std::cout << "You died!" << std::endl;
            return 0;
        }

        if (enemyHP <= 0){
            std::cout << "You defeated your enemy!" << std::endl;
            return 0;
        } 
    }
}