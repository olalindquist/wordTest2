#include "Handler.h"

Handler::Handler(){
  Handler::wl = new Word_list("words.txt");
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




std::string Handler::getGer(){
  return current->get_ger();
}

std::string Handler::getSwe(){
 return current->get_swe();
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



