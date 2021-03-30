#pragma once
#include "Word.h"
#include <string>


class Noun :  public Word{

private:
  std::string genus;
  std::string ending;

public:
  Noun (std::string a_genus, std::string a_swe, std::string a_ger, std::string a_ending);
  std::string get_ending();
  std::string get_genus();
};
