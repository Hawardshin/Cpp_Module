#include "Brain.hpp"

Brain::Brain() {
	std::cout <<"[Brain Default constructor called]\n\n";
}

Brain::Brain(std::string *ideas_){
	for (int i=0; i< 100;i++) ideas[i]=  ideas_[i];
	std::cout <<"[Brain parameter constructor called]\n\n";
}

Brain::Brain(const Brain &obj) {
	for (int i=0; i< 100;i++) ideas[i]=  obj.ideas[i];
	std::cout <<"[Brain Copy constructor called]\n" <<"You make " << obj.ideas << "\n\n";
}

Brain::~Brain() {
	std::cout <<"[Brain Destructor called]\n" <<"extinguish Brain\n\n";
}

Brain& Brain::operator=(const Brain& obj){
	std::cout <<"[Brain Copy assignment operator called]\n\n";
	for (int i=0; i< 100;i++) ideas[i]=  obj.ideas[i];
	return (*this);
}

void	Brain::speak_all_ideas(){
	for (int i=0;i<100;i++)
	{
		std::cout << "ideas[" <<i << "] : " << ideas[i] << "| " ;
		if (i+1 % 10 == 0)
			std::cout << "\n";
	}
}
