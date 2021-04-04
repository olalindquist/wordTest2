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
std::string Word::getWc(){

  return wc; 
}

//Standard Word
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
//Noun

  bool Word::isNoun(){
    return false; 
  }

  bool Word::isVerb(){
    return false; 
  }

bool Word::check(std::string gen, std::string end, bool swe_ger){
   if (swe_ger){
    
     if (gen.compare(Word::genus)==0 && ending.compare(Word::ending)==0) {
      return true;
     }
    return false; 
   }
   return true; //Should not be reached;
}
    
  



