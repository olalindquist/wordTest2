#pragma once

#include <stdlib.h>
#include <time.h>  
#include "Word_list.h"
#include "Handler.h"
#include "Word.h"
#include "Noun.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class cMain : public wxFrame{
  
public:
  cMain ();
  
  Handler* handler = nullptr; 

  wxButton* button1 = nullptr;
  wxButton* button_commit = nullptr;
  wxTextCtrl* question = nullptr;
 
  wxTextCtrl* article = nullptr;
  wxTextCtrl* ans = nullptr;
  wxTextCtrl* ending = nullptr;
  wxTextCtrl* preteritum = nullptr;
  wxTextCtrl* perfektP = nullptr;


  wxListBox* info    = nullptr;

  wxArrayString choices;
  wxRadioBox* box = nullptr;
  wxRadioButton* radioButton = nullptr;

  
  //Bonus button
  //void onClick(wxCommandEvent &evt);

  // SubmitButton
  void submit (wxCommandEvent &evt);
  // Update evertything.
  void update();
  //Clear score and get new word.
  void clearAll(wxCommandEvent &evt);
  //Set upp correct fields for correct words
  void updateScreen();
  //Check radiobuttons and set swe_ger to true or false. 
  void setLanguage();
  // If its a Noun
  bool submitNoun();
  // Check no fields length <1
  bool readyToCommit();
  // Locks all but ans field
  void inactivateAll(); 
  

  wxDECLARE_EVENT_TABLE();

  
  
};



