#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ios>
#include <limits>
#include <ctime>

class MagicCreation{
    public:
        std::string spellName;
        std::string magCoreType;
        std::string elementType;
        std::string modifier1;
        std::string modifier2;
        int manaCost;
        double castSpeed;
        double power;
        bool offTrueDefFalse;
        double range;
        double size;

        MagicCreation(char magicCore, char elementalCore, char mod1, char mod2){
            
        }

        int defOff(int defOffPowSpe){
            if (defOffPowSpe >= 0){
                offTrueDefFalse = true;

                castSpeed = (defOffPowSpe);
                power = (101 - defOffPowSpe);

                std::cout << "Power: "<< power << std::endl << "Speed: " << castSpeed << std::endl << offTrueDefFalse << std::endl;;
            }
            else{
                offTrueDefFalse = false;
                castSpeed = (-defOffPowSpe);
                power = (101 + defOffPowSpe);

                std::cout << "Power: "<< power << std::endl << "Speed: " << castSpeed << std::endl << offTrueDefFalse << std::endl;
            }
            return 0;
        }

};

int magicTable(){
    std::cout << "Input magic core, elemental core, and modifiers in order." << std::endl;

    std::string coreInput;
    std::getline(std::cin, coreInput);

    char magicCore[1];
    char element[1];
    char modifier1[1];
    char modifier2[1];

    std::size_t magCoreSearch = coreInput.find("MagicCore");
    std::size_t eleCoreSearch = coreInput.find("ElementalCore");
    std::size_t modSearch1 = coreInput.find("Mod1");
    std::size_t modSearch2 = coreInput.find("Mod2");
    // Takes letter inserted after "MagicCore" to use as core
    if (magCoreSearch!=std::string::npos){
        coreInput.copy(magicCore, 1, magCoreSearch + 9);
    }
    else{
        std::cout << "No magic core found, please input magic core." << std::endl;
        return 1;
    }

    if (eleCoreSearch!=std::string::npos){
        coreInput.copy(element, 1, eleCoreSearch + 13);
    }
    else{
        std::cout << "No elemental core found, please input elemental core." << std::endl;
        return 1;
    }

    if (modSearch1!=std::string::npos){
        coreInput.copy(modifier1, 1, modSearch1 + 4);
    }
    else{
        modifier1[0] = 'Z';
    }

    if (modSearch2!=std::string::npos){
        coreInput.copy(modifier2, 1, modSearch2 + 4);
    }
    else{
        modifier2[0] = 'Z';
    }

    int defOffPowSpe;
    std::cout << "Defense, offense, power, speed." << std::endl;
    std::cin >> defOffPowSpe;

    MagicCreation spell1(magicCore[0], element[0], modifier1[0], modifier2[0]);
    spell1.defOff(defOffPowSpe);

    std::string spellName;
    bool validSpellName = false;
    std::getline(std::cin, spellName);

    while (validSpellName == false){
        std::getline(std::cin, spellName);

        if(spellName.length() > 14){
            std::cout << "Can not be longer than 14 characters.";
        }
        else{
            spell1.spellName = spellName;
            validSpellName = true;
        }
    }

    std::cout << sizeof(MagicCreation);

    return 0;
}

int main(){
    int success = magicTable();
    if (success == 1){
        success = magicTable();
    }
    return 0;
}  