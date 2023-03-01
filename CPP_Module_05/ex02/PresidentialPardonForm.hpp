#pragma once
# include "Form.hpp"

//PresidentialPardonForm: Required grades: sign 25, exec 5
//Informs that <target> has been pardoned by Zaphod Beeblebrox.
//All of them take only one parameter in their constructor: the target of the form.
//For example, "home" if you want to plant shrubbery at home.
class PresidentialPardonForm :public Form{
public:
  explicit PresidentialPardonForm(const std::string& name);
  PresidentialPardonForm(const PresidentialPardonForm& obj );
  virtual ~PresidentialPardonForm();
  virtual void execute(const Bureaucrat& executor) const;
private:
  PresidentialPardonForm();  //not use it
  PresidentialPardonForm& operator=(const PresidentialPardonForm& obj );
};
