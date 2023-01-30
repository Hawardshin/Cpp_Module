#include "Weapon.hpp"

Weapon::Weapon(){type = "No weapon";}
Weapon::Weapon(const std::string &type_) {type = type_;}// 매개변수를 레퍼런스로 해도 되는걸까? 라는 걱정이 있었는데 된다고 판단.

void				Weapon::setType(const std::string type_){type = type_;}
const std::string	&Weapon::getType(void){return (type);}
