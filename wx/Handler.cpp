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
  //  Handller::current.setWordParts(); 

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


bool Handler::check(std::string first,std::string second,  std::string third){
  if (Handler::current->isNoun()){
    for (auto & c: first) c = toupper(c);
    for (auto & c:third) c = toupper(c);
    for (auto & c: first) c = toupper(c);


    bool a = first.compare(Handler::getArticle()) ;
    bool b = second.compare(Handler::getGer());
     bool c = third.compare(Handler::getEnding());
     if (a==0&&b==0&&c==0){
       return true;
     }
  }
  if (Handler::current->isVerb()){
    bool a = first.compare(Handler::getGer()) ;
    bool b = second.compare(Handler::getPreteritum());
    bool c = third.compare(Handler::getPerfectP());
     if (a==0&&b==0&&c==0){
       return true;
     }


  }
  return false;
 
}

std::string Handler::getGer(){
  
  return Handler::current->get_ger();
}

std::string Handler::getSwe(){
  std::cout<<"Handler getSwe: "<<current->get_swe();
  
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


std::string Handler::getArticle(){
  return Handler::current->getArticle(); 
}
std::string Handler::getEnding(){
  return Handler::current->getEnding();
}
std::string Handler::getPreteritum(){
  return Handler::current->getPreteritum(); 
}
std::string Handler::getPerfectP(){
  return Handler::current->getPerfectP();
}


