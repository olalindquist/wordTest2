#include "Handler.h"

Handler::Handler(){


  Handler::wl = new Word_list("words.txt");
  std::cout<<"WordList setup !done \n"; 
  Handler::noCorrect = 0;
  Handler::total = 0; 
  Handler::swe_ger = true; 
}

void Handler::setup(){
  Handler::current = wl->get_random();
}

void Handler::show(){
  std::cout<<Handler::current->get_swe()<<" " << Handler::current->get_ger()<<'\n';
  
}

void Handler::set_swe_ger(bool b){
  Handler::swe_ger = b;
}


bool Handler::check(std::string in){


  if (swe_ger){
    return Handler::current->check(in, true);
  } else{
    return Handler::current->check(in, false);
  }

}

bool Handler::check(std::string gen,std::string middle,  std::string ending){
  if (Handler::current->getWc().compare("n") == 0){
    std::cout<<"Error! checkNoun without noun"; 
    return false; 
  } 
  
  if (!(Handler::check(middle))){
    return false;
  }  else {
    if (!swe_ger){
    return Handler::check(middle);
  }
  
  if (swe_ger){
    return Handler::current->Word::check(gen, ending, true);
  } else{
    return Handler::current->Word::check(gen, ending, false);
  }
  
  
  }
}


std::string Handler::getGer(){
  
  return Handler::current->get_ger();
}

std::string Handler::getSwe(){
  return Handler::current->get_swe();
}

int Handler::getTotal(){


  return Handler::total;
}

int Handler::getCorrect(){
  return Handler::noCorrect;
}

void Handler::increaseTotal(){
  Handler::total+=1;
  
}
void Handler::increaseCorrect(){
  Handler::noCorrect +=1;
}
void Handler::reset(){
  Handler::total =0 ;
  Handler::noCorrect =0;
}
bool Handler::sweGer(){
  return swe_ger;
}

bool Handler::isNoun(){

  return Handler::current->isNoun(); 
}
bool Handler::isVerb(){
  return Handler::current->isVerb(); 
}
