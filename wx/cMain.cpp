#include "cMain.h"


wxBEGIN_EVENT_TABLE(cMain, wxFrame)

EVT_BUTTON(10001, cMain::submit)
EVT_BUTTON(10004, cMain::clearAll)
EVT_TEXT_ENTER(10002, cMain::submit)





 wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr,wxID_ANY, "window", wxPoint(30,30),wxSize(800,600)){
  
  std::cout<<"Constructor \n"; 
  cMain::handler = new Handler();
  std::cout<<"Constructor setup done \n"; 
  cMain::handler->setup();

  button_commit = new wxButton(this,10001, "commit", wxPoint(160,500), wxSize(150,50));
  button1 = new wxButton(this,10004, "clear/restart" ,wxPoint(10,500), wxSize(150,50));
  
  question = new wxTextCtrl(this, wxID_ANY, "quest", wxPoint(10,150), wxSize(150,30), wxTE_READONLY);
  article = new wxTextCtrl(this, 10002, "Der", wxPoint(250,150), wxSize(45,30),wxTE_PROCESS_ENTER);

  ans = new wxTextCtrl(this, 10002, "Base", wxPoint(320,150), wxSize(150,30),wxTE_PROCESS_ENTER);

  

  ending = new wxTextCtrl(this, 10002, "ending", wxPoint(500,150), wxSize(60,30),wxTE_PROCESS_ENTER);

  preteritum = new wxTextCtrl(this, 10002, "preteritum", wxPoint(320,200), wxSize(150,30),wxTE_PROCESS_ENTER);
  
 perfektP = new wxTextCtrl(this, 10002, "perfektP", wxPoint(320,240), wxSize(150,30),wxTE_PROCESS_ENTER);
  
    //************

 
  
  info = new wxListBox(this, 10010, wxPoint(10,10), wxSize(600,120));
  

  cMain::choices.Add("Svenska->Tyska");
  cMain::choices.Add("Tyska->Svenska");
  cMain::choices.Add("Blandat"); 

  box = new wxRadioBox(this, wxID_ANY, 
		       "Språk: ", wxPoint(640,10), 
		       wxDefaultSize, choices, 3, wxRA_VERTICAL);
}



void cMain::submit(wxCommandEvent &evt){
  std::string ch = std::string((ans->GetValue()));
  bool correct = false; 

  if (!readyToCommit()){
    return;
  }

  
  if(cMain::handler->isNoun()){

    
    submitNoun();
  }

  else if (cMain::handler->isVerb()){
      std::cout<<"Verb not yet implemented";
       correct = handler->check(ch);
      
    } else {
        correct = handler->check(ch);

    }
  
  if (correct){
    cMain::handler->increaseTotal();
    cMain:handler->increaseCorrect();
    info->Append("Correct!");
  }else{
    info->Append("Wrong!");
    cMain::handler->increaseTotal();
  }
   cMain::update();
   cMain::updateScreen();
  evt.Skip();
    
}

void cMain::update(){
  
  setLanguage(); 
  cMain::handler->setup();
   cMain::updateScreen();  
}

void cMain::clearAll(wxCommandEvent &evt){

  cMain::handler->reset(); 
  cMain::handler->setup();
  cMain::updateScreen();  
  
  evt.Skip();
}

void cMain::updateScreen(){
     std::cout<<"Screen Update! \n";
     cMain::inactivateAll();
  
     ans->SetEditable(true);
     ans->SetFocus();
     ans->Clear();
  
  if (handler->sweGer()){

    question->SetValue(cMain::handler->getSwe());
	
    if (handler->isNoun()){
      std::cout<<"Is a Noun\n"; 
      article -> SetEditable(true);
      ending -> SetEditable(true);   
      article->Clear();
      ending->Clear();

      article->SetFocus();
    }
    if (handler->isVerb()){
      preteritum-> SetEditable(true);
      perfektP -> SetEditable(true); 
      preteritum ->Clear();
      perfektP ->Clear(); 

    }

    //ans->SetValue(cMain::handler->getGer());


  } else {
    
    question->SetValue(cMain::handler->getGer());
    //ans->SetValue(cMain::handler->getSwe());

  }
  


  

          
    
  std::string score =  std::to_string(handler->getCorrect());
  std::string total =  std::to_string(handler->getTotal());
  
  
  std::string infoText = "No corrects: "+score +'\n'+"Total: "+total+'\n';
  
  info->Clear();
  info->Insert(infoText,0);
  
}

void cMain::setLanguage(){
  int selection = box->GetSelection();
  
 
  if (selection == 1){
    handler->set_swe_ger(false);
  }
  if (selection == 0){
    handler->set_swe_ger(true);
  }
  if (selection == 2){
    int rnd = rand()%10;
    if (rnd<=5){
    handler->set_swe_ger(true);
    } else {
      handler->set_swe_ger(false);
    }
    
    
  }
}


  bool cMain::submitNoun(){

    std::string beg = std::string((ans->GetValue()));
    std::string main = std::string((ans->GetValue()));
    std::string end = std::string((ans->GetValue()));
    
   


    
    
    return handler->check(beg,main,end);
    


  }

bool cMain::readyToCommit(){
  std::string beg = std::string((article->GetValue()));
  std::string mn = std::string((ans->GetValue()));
  std::string end = std::string((ending->GetValue()));
  std::string pret = std::string((preteritum->GetValue()));
  std::string pp = std::string((perfektP->GetValue()));

 
  return !(beg.size()<1||mn.size()<1||end.size()<1||pret.size()<1||pp.size()<1);
 
 
    
}

void cMain::inactivateAll(){

  question->SetValue("***");
  ans->SetValue("***");
  ending->SetValue("***");
  preteritum->SetValue("***");
  perfektP->SetValue("***");
 
  article->SetEditable(false);
  ans->SetEditable(false);
  ending->SetEditable(false);
  preteritum->SetEditable(false);
  perfektP->SetEditable(false);
      
  
     

}

















