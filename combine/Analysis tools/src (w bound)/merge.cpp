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

  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->mkdir(dirname);
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("Bkg");
  file->Clear();
  h->Clear(); 
  
  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("data_obs");
  file->Clear();
  h->Clear();   
  
  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM.root",argv[1]);
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

  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm");
  file->Clear();
  h->Clear();

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
// only cW

  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/cW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/cW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cW_quad");
  file->Clear();
  h->Clear();

// SM + cW

  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM_cW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM_cW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM_cW_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int_quad");
  file->Clear();
  h->Clear();

// All cW for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/cW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cW");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/unitarity/histos/%s/SM_cW_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cW");
  file->Clear();
  h->Clear();
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*  
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
  
  */
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

 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FERMIONIC OPERATORS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHq1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
// only cHq1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHq1_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq1_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHq1_int");
  file->Clear();
  h->Clear();

// SM + cHq1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHq1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHq1_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHq1_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHq1_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHq1_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHq1_int_quad");
  file->Clear();
  h->Clear(); 

// All cHq1 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHq1");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHq1_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHq1");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHq3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
// only cHq3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHq3_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq3_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHq3_int");
  file->Clear();
  h->Clear();

// SM + cHq3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHq3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHq3_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHq3_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHq3_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHq3_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHq3_int_quad");
  file->Clear();
  h->Clear(); 

// All cHq3 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHq3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHq3");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHq3_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHq3");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHl1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
// only cHl1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHl1_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl1_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHl1_int");
  file->Clear();
  h->Clear();

// SM + cHl1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHl1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHl1_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHl1_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHl1_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHl1_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHl1_int_quad");
  file->Clear();
  h->Clear(); 

// All cHl1 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHl1");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHl1_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHl1");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cHl3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
// only cHl3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHl3_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl3_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHl3_int");
  file->Clear();
  h->Clear();

// SM + cHl3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHl3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHl3_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHl3_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHl3_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHl3_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHl3_int_quad");
  file->Clear();
  h->Clear(); 

// All cHl3 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHl3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cHl3");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHl3_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cHl3");
  file->Clear();
  h->Clear();


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cqq1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  


  
// only cqq1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq1_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq1_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq1_int");
  file->Clear();
  h->Clear();

// SM + cqq1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq1_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq1_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq1_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq1_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq1_int_quad");
  file->Clear();
  h->Clear(); 

// All cqq1 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cqq1");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq1_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cqq1");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cqq3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
// only cqq3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq3_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq3_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq3_int");
  file->Clear();
  h->Clear();

// SM + cqq3

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq3_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq3_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq3_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq3_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq3_int_quad");
  file->Clear();
  h->Clear(); 

// All cqq3 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq3_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cqq3");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq3_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cqq3");
  file->Clear();
  h->Clear();


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cqq11~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
 
// only cqq11

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq11_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq11_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq11_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq11_int");
  file->Clear();
  h->Clear();

// SM + cqq11

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq11_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq11_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq11_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq11_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq11_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq11_int_quad");
  file->Clear();
  h->Clear(); 

// All cqq11 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq11_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cqq11");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq11_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cqq11");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cqq31~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
// only cqq31

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq31_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq31_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq31_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cqq31_int");
  file->Clear();
  h->Clear();

// SM + cqq31

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq31_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq31_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq31_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq31_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq31_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cqq31_int_quad");
  file->Clear();
  h->Clear(); 

// All cqq31 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cqq31_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cqq31");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cqq31_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cqq31");
  file->Clear();
  h->Clear();
  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cll~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
// only cll

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cll_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cll_int");
  file->Clear();
  h->Clear();

// SM + cll

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cll_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cll_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cll_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cll_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cll_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cll_int_quad");
  file->Clear();
  h->Clear(); 

// All cll for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cll");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cll_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cll");
  file->Clear();
  h->Clear();
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cll1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
 
// only cll1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cll1_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll1_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cll1_int");
  file->Clear();
  h->Clear();

// SM + cll1

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cll1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cll1_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cll1_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cll1_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cll1_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cll1_int_quad");
  file->Clear();
  h->Clear(); 

// All cll1 for likelihood scan

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cll1_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("quad_cll1");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cll1_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(particle);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("sm_lin_quad_cll1");
  file->Clear();
  h->Clear();
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  
  risultato->Close();

}

