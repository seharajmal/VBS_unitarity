#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include "TROOT.h"
#include <cmath>
#include <iostream>
#include <filesystem>
using namespace std;

int main(int argc, char*argv[]){

  TFile *file=NULL;
  TH1F *h=NULL;
  char path[100];  
  char particle[20];
  sprintf(particle, "h_%s_%s",argv[1],argv[2]);
  char outfile[20];
  sprintf(outfile, "%s_%s.root",argv[1],argv[2]);
  TFile* risultato=new TFile(outfile, "RECREATE");
  char* dirname = "SR_inclusive_2017";

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->mkdir(dirname);
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("Bkg");
  file->Clear();
  h->Clear(); 
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("data_obs");
  file->Clear();
  h->Clear();   
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  double h_int=h->Integral();
  h->Scale(1./h_int);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("BkgPdf");
  file->Clear();
  h->Clear(); 
  
// SM for likelihood scan 

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cW

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cW_quad");
  file->Clear();
  h->Clear();

// SM + cW

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int_quad");
  file->Clear();
  h->Clear();

// All cW for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cW");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cW");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
// only cHW

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHW_quad");
  file->Clear();
  h->Clear();

// SM + cHW

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHW_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHW_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHW_int_quad");
  file->Clear();
  h->Clear();

// All cHW for likelihood scan  

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHW");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHW_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHW");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  

// only cHWB

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWB_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWB_quad");
  file->Clear();
  h->Clear();

// SM + cHWB

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWB_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWB_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWB_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWB_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWB_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWB_int_quad");
  file->Clear();
  h->Clear();

// All cHWB for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHWB");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWB_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHWB");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHbox

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->mkdir(dirname); 
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHbox_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHbox_int");
  file->Clear();
  h->Clear();
  
// SM + cHbox

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHbox_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHbox_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHbox_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHbox_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHbox_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHbox_int_quad");
  file->Clear();
  h->Clear(); 

// All cHbox for likelihood scan  

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHbox");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHbox_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHbox");
  file->Clear();
  h->Clear();
  
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

// only cHDD

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHDD_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHDD_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHDD_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHDD_int");
  file->Clear();
  h->Clear();

// SM + cHDD

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHDD_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHDD_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHDD_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHDD_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHDD_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHDD_int_quad");
  file->Clear();
  h->Clear(); 

// All cHDD for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHDD_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHDD");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHDD_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHDD");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
/*  
// only cWtil

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cWtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cWtil_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cWtil_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cWtil_int");
  file->Clear();
  h->Clear();

// SM + cWtil

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cWtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cWtil_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cWtil_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cWtil_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cWtil_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cWtil_int_quad");
  file->Clear();
  h->Clear(); 

// All cWtil for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cWtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cWtil");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cWtil_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cWtil");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHWtil

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWtil_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWtil_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWtil_int");
  file->Clear();
  h->Clear();

// SM + cHWtil

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWtil_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWtil_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWtil_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWtil_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWtil_int_quad");
  file->Clear();
  h->Clear(); 

// All cHWtil for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHWtil");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWtil_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHWtil");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// only cHWBtil

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWBtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWBtil_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWBtil_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWBtil_int");
  file->Clear();
  h->Clear();
  
// SM + cHWBtil

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWBtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWBtil_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWBtil_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWBtil_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWBtil_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWBtil_int_quad");
  file->Clear();
  h->Clear(); 

// All cHWBtil for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWBtil_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHWBtil");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWBtil_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHWBtil");
  file->Clear();
  h->Clear();
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
/*  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_quad_0.4.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_quad_04");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_int_0.4.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int_04");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_int_quad_0.4.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int_quad_04");
  file->Clear();
  h->Clear();  
*/
  
  risultato->Close();

}

