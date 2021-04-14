#pragma once
#include <string>
#include <iostream>
#include <vector>


class Word {
 protected:
  std::string swe; 
  std::string ger;
  std::string wc; //Wordclass
  bool noun;
  bool verb;
  
  struct {
    std::string genus;
    std::string ending;
    std::string preteritum;
    std::string perfectP;
  
  } vocab;

  void setVocab(); 
 public:
  Word (std::string a_wc, std::string a_swe, std::string a_ger );
  Word (std::string a_wc, std::string a_swe, std::string a_ger, std::string a_genus, std::string a_ending );
  Word (bool verb, std::string a_wc, std::string a_swe,std::string a_ger, std::string a_preteritum, std::string a_perfekP);

  std::string get_swe();
  std::string get_ger();
  std::string getWc();
  std::string getArticle();
  std::string getEnding();
  std::string getPreteritum();
  std::string getPerfectP();
  
  bool check(std::string in, bool swe_ger);
  bool check(std::string gen, std::string end, bool swe_ger);
  
  bool isNoun();
  bool isVerb();
  std::string toUpper(std::string in);
  
};











