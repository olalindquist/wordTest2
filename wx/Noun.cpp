
#include "Noun.h"


Noun::Noun(std::string a_genus, std::string a_swe, std::string a_ger, std::string a_ending) : Word("s", a_swe, a_ger){
  genus = a_genus;
  ending = a_ending;

}

std::string Noun::get_ending(){
  return ending;
}

std::string Noun::get_genus(){
  return genus;
}


    

   bool Noun::isNoun(){
     return true; 
   
  }
 









