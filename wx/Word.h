#pragma once
#include <string>
#include <iostream>

class Word {
 protected:
  std::string swe; 
  std::string ger;
  std::string wc; //Wordclass
  std::string genus;
  std::string ending; 

 public:
  Word (std::string wc, std::string a_swe, std::string a_ger );
  
  std::string get_swe();
  std::string get_ger();
  std::string getWc();

  bool check(std::string in, bool swe_ger);
  bool isNoun();
  bool isVerb();
  bool check(std::string gen, std::string end, bool swe_ger);
 

};









