#pragma once
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
  wxTextCtrl* ans = nullptr;

  wxListBox * info    = nullptr;
  
  void onClick(wxCommandEvent &evt);
  void submit (wxCommandEvent &evt);
  void update();
  
  wxDECLARE_EVENT_TABLE();

  
  
};



