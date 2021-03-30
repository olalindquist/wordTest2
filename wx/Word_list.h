#pragma once
#include <string>
#include "Word.h"
#include "Noun.h"

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include<vector>

class Word_list{
 private:
  std::vector<Word*> word_list;
  
  void load_list(std::string filename);
  void makeWord(std::string in);
  void make_noun(std::vector<std::string> parts);
  void make_word(std::vector<std::string> parts);


  
public:
  Word_list(std::string filename);
  void add_word(Word* a_word);
  Word* get_random();
  void show_list(); 
};
