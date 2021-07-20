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
  char observable[20];
  sprintf(observable, "h_%s",argv[1]);
  char outfile[20];
  sprintf(outfile, "%s.root",argv[1]);
  TFile* risultato=new TFile(outfile, "RECREATE");
  char* dirname = "SR_inclusive_2017";
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->mkdir(dirname); 
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHbox_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHbox_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->mkdir(dirname); 
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHbox_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHW_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cW_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cW_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("data_obs");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("Bkg");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  double h_int=h->Integral();
  h->Scale(1./h_int);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("BkgPdf");
  file->Clear();
  h->Clear();  
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWB_int");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/cHWB_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_cHWB_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWB_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWB_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWB_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWB_int");
  file->Clear();
  h->Clear();  
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHWB_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHWB_int_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHW_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHW_int");
  file->Clear();
  h->Clear();  
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHW_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHW_int_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHbox_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHbox_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHbox_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHbox_int");
  file->Clear();
  h->Clear();  
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHbox_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHbox_int_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHDD_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHDD_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHDD_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHDD_int");
  file->Clear();
  h->Clear();  
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cHDD_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cHDD_int_quad");
  file->Clear();
  h->Clear();

  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_quad");
  file->Clear();
  h->Clear();
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_int.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int");
  file->Clear();
  h->Clear();  
  
  sprintf(path, "/home/nyykki/Scrivania/histos_root/histos/%s/SM_cW_int_quad.root",argv[1]);
  file=TFile::Open(path);
  h=(TH1F*)file->Get(observable);
  risultato->cd();
  risultato->cd(dirname);
  h->Write("VBS_SSWW_SM_cW_int_quad");
  file->Clear();
  h->Clear();
  
  risultato->Close();

}

