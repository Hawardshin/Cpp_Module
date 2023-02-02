#include "Weapon.hpp"


Weapon::Weapon(std::string type_) : type(type_) {}

void				Weapon::setType(const std::string type_){type = type_;}
const std::string	&Weapon::getType(void){return (type);}
