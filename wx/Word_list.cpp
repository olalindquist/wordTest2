
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
    default: make_word(tokens);
  }

}

void Word_list::make_noun(std::vector<std::string> parts){

    std::string wc = parts[0];
    std::string genus= parts[1];
    std::string swe = parts[2];
    std::string ger= parts[3];
    std::string end= parts[4];

    
    Word_list::word_list.push_back(new Noun(genus,swe,ger,end));


}

  void Word_list::make_word(std::vector<std::string> parts){
  
    std::string wc = parts[0];
    std::string swe= parts[1];
    std::string ger = parts[2];
    
    Word_list::word_list.push_back(new Word(wc,swe,ger));
    


  }




  


 






