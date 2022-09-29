#include "parts.h"

Parts::Parts()
{
    this->PartId(1);
    this->IsBroken(false);
}

Parts::Parts(int id)
{
    this->PartId(id);
    this->IsBroken(false);
}

std::string Parts::toString() const
{
    std::string temp;

    temp.append("    Part #");
    temp += std::to_string(this->PartId());
    temp.append(" - ");
    temp += std::to_string(this->IsBroken());

    return temp;
}