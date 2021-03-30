#include "Word.h"


Word::Word(std::string a_wc, std::string a_swe, std::string a_ger){
  
  swe = a_swe;
  ger = a_ger;
  wc = a_wc ;
}

std::string Word::get_swe(){
  return swe;
}

std::string Word::get_ger(){

  return ger; 
}
std::string Word::get_wc(){

  return wc; 
}


bool Word::check(std::string in, bool swe_ger){
  
  if (swe_ger){
    
    if (in.compare(ger)==0){
      return true;
    }
    return false; 

  } else {
    if (in.compare(swe)==0){
	return true;
	      }
      return false; 

  }
    
  }
  



