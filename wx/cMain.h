#pragma once
#include <stdlib.h>
#include <time.h>  
#include "Word_list.h"
#include "Handler.h"
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

  
  void onClick(wxCommandEvent &evt);
  void submit (wxCommandEvent &evt);
  void update();
  void clearAll(wxCommandEvent &evt);
  void updateScreen();
  void setLanguage();

  wxDECLARE_EVENT_TABLE();

  
  
};



