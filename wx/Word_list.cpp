
#include "Word_list.h"


Word_list::Word_list(std::string filename){
   srand (time(NULL));
  Word_list::load_list(filename); 
}

void Word_list::add_word(Word* a_word){
  
 word_list.push_back(a_word);
  
}

Word* Word_list::get_random(){
 
  int len = Word_list::word_list.size();

  int val = rand()%len;

  return Word_list::word_list[val];
}



void Word_list::show_list(){
  for (Word* w : Word_list::word_list){

  }
}


  void Word_list::load_list(std::string filename){
    
    std::fstream f_s; 
    
    f_s.open(filename, std::ios::in);
    std::string temp;
    
    if(f_s.is_open()){
      
          
      while (getline(f_s, temp)){
	std::cout<<"read : "<<temp<<'\n';	
	if(!(temp.at(0)==':')){
	  makeWord(temp);
	} else {
	  break ;
	}

      }

    }
	f_s.close();
  }


void Word_list::makeWord(std::string in){
  std::vector<std::string> tokens;
  std::stringstream check1(in);
  std::string temp;
    
  while(std::getline(check1, temp, ':')){
      tokens.push_back(temp);
    }
    
  switch (in.at(0))
    {
  case 'n': make_noun(tokens);
    break;
    case'v':makeVerb(tokens);
      break;
    default: make_word(tokens);
  }

}

void Word_list::make_noun(std::vector<std::string> parts){


    std::string wc = parts[0];
    std::string article= parts[1];
    std::string swe = parts[2];
    std::string ger= parts[3];
    std::string end= parts[4];
    
    if (article.compare("m") ==0){
	article ="Der";
      }    

    if (article.compare("f")==0);{
	article ="Die";
      }

    if (article.compare("n")==0){
	article ="Das";
      }
	  
    std::cout<<"Making a noun "<<swe; 
    Word_list::word_list.push_back(new Word(wc,swe,ger,article,end));
}


void Word_list::makeVerb(std::vector<std::string> parts){
    
    std::string wc = parts[0];
    std::string swe = parts[1];
    std::string ger = parts[2];
    std::string preteritum= parts[3];
    std::string perfektP = parts[4];


    std::cout<<"make verb" <<swe<<ger<<preteritum<<perfektP<<'\n';
    //True or false just to separae constructors
    Word_list::word_list.push_back(new Word(true,wc,swe,ger,preteritum, perfektP));

  }




  void Word_list::make_word(std::vector<std::string> parts){
  
    std::string wc = parts[0];
    std::string swe= parts[1];
    std::string ger = parts[2];
    
    Word_list::word_list.push_back(new Word(wc,swe,ger));
    

  }




  


 






