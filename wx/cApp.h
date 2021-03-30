#pragma once
#include "cMain.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


class cApp : public wxApp{

private:
  cMain* m_frame1 = nullptr;
  
public:
  cApp();
  virtual bool OnInit();

  
};

