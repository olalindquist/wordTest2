#include "cMain.h"


wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(10001, cMain::onClick)
EVT_TEXT_ENTER(10002, cMain::submit)


wxEND_EVENT_TABLE()


cMain::cMain(): wxFrame(nullptr,wxID_ANY, "window", wxPoint(30,30),wxSize(800,600)){
  
  cMain::handler = new Handler();
  handler->setup();
  
  button_commit = new wxButton(this,10001, "commit", wxPoint(160,200), wxSize(150,50));
			    
  button1 = new wxButton(this,10001, "Click me" ,wxPoint(10,200), wxSize(150,50));
  question = new wxTextCtrl(this, 10002, "text", wxPoint(10,150), wxSize(300,30),wxTE_PROCESS_ENTER);
  ans = new wxTextCtrl(this, 10003, "text", wxPoint(320,150), wxSize(300,30),wxTE_PROCESS_ENTER);
  info = new wxListBox(this, wxID_ANY, wxPoint(10,10), wxSize(600,120));
 
}


void cMain::onClick(wxCommandEvent &evt){

   question->SetValue(cMain::handler->getGer());
   ans->SetValue(cMain::handler->getSwe()); 

   evt.Skip(); 
}
//  std::string = wxString::ToStdString()
void cMain::submit(wxCommandEvent &evt){
  std::string ch = (ans->GetValue())::ToStdString();
  bool correct = handler->check(ch);
    
  if (correct){
    handler->increaseTotal();
    handler->increasCorrect();
  }else{

    handler->increaseTotal();
  }
    
}

void cMain::update(){
  std::string infoText = "No corrects: "<<handler->getCorrect()<<'\n';
  info->SetValue(infoText);
  handler->setup();
  
}






















