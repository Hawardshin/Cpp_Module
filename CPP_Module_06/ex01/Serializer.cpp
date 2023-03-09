#include "Serializer.hpp"
//public
Serializer::~Serializer() {
  std::cout <<"[Serializer Destructor called]\n";
}

// uintptr_t Serializer::serialize(Data* ptr){
//   return (reinterpret_cast<uintptr_t>(ptr));
// }

// Data* Serializer::deserialize(uintptr_t raw){
//   return (reinterpret_cast<Data*>(raw));
// }

// //private don't use constructor only need for othdox
// Serializer& Serializer::operator=(const Serializer& obj){
//   static_cast<void>(obj);
//   std::cout <<"[Serializer Copy assignment operator called]\n\n";
//   return (*this);
// }

// Serializer::Serializer() {
//   std::cout <<"[Serializer Default constructor called]\n";
// }

// Serializer::Serializer(const Serializer &obj) {
//   static_cast<void>(obj);
//   std::cout <<"[Serializer Copy constructor called]\n";
// }
