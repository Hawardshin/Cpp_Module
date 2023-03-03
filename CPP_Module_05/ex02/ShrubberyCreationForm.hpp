#pragma once
#include "Form.hpp"
#include <fstream>
//ShrubberyCreationForm: Required grades: sign 145, exec 137
//Create a file <target>_shrubbery in the working directory,
//and writes ASCII trees inside it.
class ShrubberyCreationForm :public Form{
private:
  ShrubberyCreationForm();

public:
  explicit ShrubberyCreationForm(const std::string& name);
  ShrubberyCreationForm(const ShrubberyCreationForm& obj );
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj );
  virtual void execute(const Bureaucrat& executor) const;
};
