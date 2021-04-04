#pragma once

#include "Word_list.h"


class Handler
{
 private:
  Word_list* wl;
  Word* current;
  bool swe_ger;
  int noCorrect;
  int total;
  
public:
  Handler();
  void setup();
  void show();
  void set_swe_ger(bool b);
  bool check(std::string in);
  bool check(std::string gen, std::string middle, std::string end); 
  
  std::string getGer();
  std::string getSwe();
  int getTotal();
  int getCorrect();
  void increaseTotal();
  void increaseCorrect(); 
  void reset();
  bool sweGer();
  bool isNoun();
  bool isVerb();
};


