//Copyright (c) 2023 Hawardshin(joushin)
#include "ShrubberyCreationForm.hpp"

//public
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) :Form(name, 72, 45) {
  std::cout <<"[ShrubberyCreationForm parameter constructor called]\n" <<"You make " << name << "\n\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj):Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade()){
  std::cout <<"[ShrubberyCreationForm Copy constructor called]\n" <<"You make " << obj.getName()  << "\n\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout <<"[ShrubberyCreationForm Destructor called]\n" <<"extinguish " << getName() << "\n\n";
}

//Makes some drilling noises.
//Then, informs that <target> has been robotomized successfully 50% of the time.


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
  check_exectutable(executor);
  std::ofstream out("<" + getName() + ">_shrubbery",
  std::ofstream::out | std::ofstream::trunc);
  std::string shrubbery =
"                                              ,                                  \n\
                                    .    ************..                           \n\
                        ,* .       *,*/,******,**,,*/(/ .  , .*                   \n\
                      ,,*,,*.,* ,*,,//****/*,**,/*//(//(*./*,*****,.**.           \n\
              *,,    */**,,,**,*,,.*(((/*(*/////**(*###(///****,****/ .           \n\
            ./,**,.,////*,*,*,(//,((/%#/((##(%&%((#%#%###(##*(//##((,.            \n\
            *,/*((/(*,*/*/*(/**(/(/((*#%######((#(######(/**,,/*/*,/**//..        \n\
              .   /((#(//(/*/(#/%%#/,*,***,,,*/*/((%#(((**/,,,,**,*//*((#         \n\
            .,,,,*,//,*##%#(/#%#(##*,*//***,***/(,((/##(((*/***,**//*#/*/(,       \n\
        ,*,(****,,,*,*//#(#(%%%%%%((/*//*/****(#(/##**(/*/##(#(((/(((/*,/         \n\
      */*(/**,*,**,/*/(((#%%%%%%%#%%##%#%%#%# (%%###/*/#%(#,*/***,*,,(#** ..**    \n\
      *(#((((//(/(((//(%#(%%##((,****/*,*,/,,//,#*((%%#%#(#*/(*/*,***,*****,/,*   \n\
    .,/(((/%#((##(#((#/((#(//**/**,,,*//*,,*,/,,,///%#%(#(#((*#//,(,*///((*/***,  \n\
        .  #*/,#%%#%((##/#*/*/**/****(*/*//(/(//((*,//%#%%%###(((///*#/(//#*#/..  \n\
      */*/*/,(/(#%%%&%(##((/*/(*/*##((//%#((//,//,**(#%**/(/#%%%%(#/(/(#(/(#((*   \n\
    //*//*/(*(*((#/###%%(%((#(((#((#/#(#(#%(#((#(#%((%(**/%/(//((/#(###########., \n\
      ,(*#(%%#/####%%%%%#((##%#%(##%%/%%(%%#(%((/#%%((/##%##%(,***/(#((#/ *#,/    \n\
            /**(#(#(#(##%#%((##/%#%%#%%%%%&&&##%%&&#%%%#((%##((#**///, /*.        \n\
              (  .* * /,((//(/. *.( #%%%&%%%%%&%%%%,/*,/*/(,  .  ,*               \n\
                                      (%%%%#%%%%%                                 \n\
                                        #%%#%#%%                                  \n\
                                        ####(%%%                                  \n\
                                        (####%#%*                                 \n\
                                        *#((((%#%#                                \n\
                                      *#/(#((#%%%###                              \n\
                                .   .(#%%#(##%, ,((###(*                          \n";
  out << shrubbery;
  out.close();
}

//private
ShrubberyCreationForm::ShrubberyCreationForm() :Form("", 72, 45){
  std::cout <<"[ShrubberyCreationForm Default constructor called]\n";
}

//I am not use but other how to do it?
//how to change private base class member?
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
  // sign = obj.getSign();
  (void)obj;
  std::cout <<"[ShrubberyCreationForm Copy assignment operator called]\n\n";
  return (*this);
}
