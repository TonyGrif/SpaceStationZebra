#include "ships.h"

Ship::Ship() 
{
    this->ShipID(1);
    this->SetType();
    this->GenerateParts();
}

Ship::Ship(int id)
{
    this->ShipID(id);
    this->SetType();
    this->GenerateParts();
}

void Ship::SetType()
{
    // Quick and dirty way
    srand((unsigned) time(NULL)); 
    // Min + (rand() % max)
    int randNum = (1 + (rand() % 100));

    if(randNum <= 51) {
        this->type = 'H';
    }
    else if(randNum <= 65) {
        this->type = 'F';
    }
    else if(randNum <= 75) {
        this->type = 'K';
    }
    else if(randNum <= 80) {
        this->type = 'R';
    }
    else {
        this->type = 'O';
    }
}

void Ship::GenerateParts()
{
    int minVal, maxVal;
    if(this->Type() == 'H') {
        minVal = 1;
        maxVal= 100;
    }
    else if(this->Type() == 'F') {
        minVal = 75;
        maxVal= 125;
    }
    else if(this->Type() == 'K') {
        minVal = 2;
        maxVal= 200;
    }
    else if(this->Type() == 'R') {
        minVal = 1;
        maxVal= 199;
    }
    else {
        minVal = 200;
        maxVal = 999;
    }
}

std::string Ship::toString() const
{
    std::string tempStr;

    tempStr += '#';
    tempStr.append(std::to_string(this->ShipID()));

    tempStr += " (Type ";
    tempStr += (this->Type());
    tempStr += ")";

    tempStr += "\n";
    for(auto& i : this->GetParts()) {
        tempStr.append(std::to_string(i.PartId()));
        tempStr += " - ";
        tempStr.append(std::to_string(i.IsBroken()));
    }

    return tempStr;
}