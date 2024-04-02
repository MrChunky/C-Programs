#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <ios>
#include <limits>
#include <ctime>

class Item {
    public:
        std::string itemName;
        std::string itemCategory;
        int itemSellPrice;
        //Common, Uncommon, Rare, Legendary
        std::string itemRarity;
        std::string itemModel;
        std::string itemDesc;
        //Chance of the item spawning inside a chest
        int itemSpawnChance;
        //Amount of duplicate items
        int itemCount;

    Item(){};

    Item(
        std::string aItemName, std::string aItemCategory,
        int aItemSellPrice, std::string aItemRarity,
        std::string aItemModel, std::string aItemDesc,
        int aItemSpawnChance
    ){
        itemName = aItemName;
        itemCategory = aItemCategory;
        itemSellPrice = aItemSellPrice;
        itemRarity = aItemRarity;
        itemModel = aItemModel;
        itemDesc = aItemDesc;
        itemSpawnChance = aItemSpawnChance;
    };
};

class MagicCore: public Item{
    public:
        std::string coreType;
        std::string compatableMods;
};

class MagicModifier: public Item{
    public:
        std::string modType;
};

class ElementCore: public Item{
    public:
        std::string element;
};

class Weapon: public Item{
    public:
        std::string damageType;
        std::string weaponType;
        double damage;
        double swingSpeed;
        double range;
    Weapon(
        std::string aItemName, std::string aItemCategory,
        int aItemSellPrice, std::string aItemRarity,
        std::string aItemModel, std::string aItemDesc,
        int aItemSpawnChance, std::string aDamageType,
        std::string aWeaponType, double aDamage,
        double aSwingSpeed, double aRange
    ){
        itemName = aItemName;
        itemCategory = aItemCategory;
        itemSellPrice = aItemSellPrice;
        itemRarity = aItemRarity;
        itemModel = aItemModel;
        itemDesc = aItemDesc;
        itemSpawnChance = aItemSpawnChance;
        damageType = aDamageType;
        weaponType = aWeaponType;
        damage = aDamage;
        swingSpeed = aSwingSpeed;
        range = aRange;
    };
};

class NPC{

    public:
        std::string npcName;
        std::string npcDesc;
        std::string npcFaction;
        std::string npcDialogue;
        std::string voiceData;
        std::string npcModel;
};

class MerchantNPC: public NPC{
    public:
        

};




int chestOpen(){
    srand(time(NULL));

    int randChestSize{rand() % 3 + 1};

    int randNum{rand() % 10};
    // Turns equal chance of getting each item into 40/30/20/10%
    if (randNum >= 6){
        randNum = 0; // Gold Chalice, Item
    }
    else if (randNum >= 3){
        randNum = 4; // Ruby, Item
    }
    else if (randNum >= 1){
        randNum = 2; // Steel sword, Weapon
    }
    else{
        randNum = 3; // Gold key, Item
    }

    int itemID = randNum;
    
    return itemID;
}

int main(){
    //Array containing the pool table of the chest
    Item chestContent[5];

    chestContent[0] = Item("Gold Chalice", "Sellable", 30, "Common", "Empty", "An old cup made of pure gold", 30);
    chestContent[1] = Item("Empty Vase", "Sellable", 20, "Common", "Empty", "A vase with a long crack on the side", 20);
    chestContent[2] = Weapon("Steel Sword", "Weapon", 5, "Uncommon", "Empty", "A steel sword of fine quality", 40, "Slash", "Medium", 28.2, 0.77, 8.0);
    chestContent[3] = Item("Gold Key", "Crafting", 50, "Uncommon", "Empty", "Look ancient", 10);
    chestContent[4] = Item("Ruby", "Sellable", 50, "Uncommon", "Empty", "Shiny and red", 20);

    int itemID = chestOpen();

    std::cout << "You found 1 " << chestContent[itemID].itemName << std::endl;

    std::getline(std::cin, chestContent[4].itemName);

    std::cout << chestContent[4].itemName;

    return 0;
}
