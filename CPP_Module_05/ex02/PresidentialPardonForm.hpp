#pragma once

//PresidentialPardonForm: Required grades: sign 25, exec 5
//Informs that <target> has been pardoned by Zaphod Beeblebrox.
//All of them take only one parameter in their constructor: the target of the form.
//For example, "home" if you want to plant shrubbery at home.
class PresidentialPardonForm
{
private:

public:
  PresidentialPardonForm();
  explicit PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& obj );
  ~PresidentialPardonForm();
  PresidentialPardonForm& operator=(const PresidentialPardonForm& obj );
};
