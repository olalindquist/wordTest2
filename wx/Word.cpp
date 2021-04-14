#include "Word.h"


Word::Word(std::string a_wc, std::string a_swe, std::string a_ger){

  setVocab();
  wc = a_wc; 
  swe = a_swe;
  ger = a_ger;

}


//Noun
Word::Word (std::string a_wc, std::string a_swe, std::string a_ger, std::string a_genus, std::string a_ending ){
    setVocab();
    Word::noun=true; 
    Word::swe = a_swe  ;
    Word::ger = a_ger;
    Word::wc = a_wc ;
    Word::vocab.genus = a_genus;
    Word::vocab.ending = a_ending;
}



Word::Word (bool verb, std::string a_wc, std::string a_swe, std::string a_ger,  std::string a_preteritum, std::string a_perfectP){
  
  setVocab();
  Word::verb = true; 
  Word::swe = a_swe;
  Word::ger = a_ger;
  Word::wc = a_wc ;
  Word::vocab.preteritum = a_preteritum;
  Word::vocab.perfectP = a_perfectP ;

  std::cout<<"Made word: "<<Word::swe<<'\n';
  
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

std::string Word::getArticle(){
  return Word::vocab.genus;
}
std::string Word::getEnding(){
    return Word::vocab.ending;
 
}
std::string Word::getPreteritum(){
    return Word::vocab.preteritum;
}
std::string Word::getPerfectP(){
    return Word::vocab.perfectP;

}

//Standard Word
bool Word::check(std::string in, bool swe_ger){
 
  in = toUpper(in);
  
    if (swe_ger){
    
      if (in.compare(toUpper(ger))==0){
	return true;
      }
      return false; 

    } else {
      if (in.compare(toUpper(swe))==0){
	return true;
      }
      return false; 
    
  }
}
//Noun//Verb;

bool Word::check(std::string first, std::string second, bool swe_ger){
  first = toUpper(first);
  second = toUpper(second);

  
  if (Word::noun){
    
   if (swe_ger){
    
     if (first.compare(toUpper(Word::vocab.genus))==0 && second.compare(toUpper(Word::vocab.ending))==0) {
      return true;
     }
    return false; 
   }
  } else if (Word::verb){
    if (first.compare(toUpper(Word::vocab.preteritum))==0 && second.compare(toUpper(Word::vocab.perfectP))==0) {
      return true;
     }
    return false; 
   }
    
  
   return true; //Should not be reached;
}



void Word::setVocab(){
  Word::verb = false;
  Word::noun = false; 
  Word::vocab.genus = "";
  Word::vocab.ending ="";
  Word::vocab.preteritum = "";
  Word::vocab.perfectP ="";


}



  bool Word::isNoun(){
   
       return Word::noun; 
  }

  bool Word::isVerb(){
    return Word::verb;
 
  }
std::string Word::toUpper(std::string in){

  for (auto & c: in) c = (char)toupper(c);
  return in;
}
