#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include "TROOT.h"
#include "ExRootTreeReader.h"
#include "ExRootClasses.h"
#include <cmath>
using namespace std;

int main(int argc, char*argv[]){

  char infile[50];
  sprintf(infile, "data/%s.root",argv[1]);
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");

  TH1F *Eta_el=new TH1F("h_Eta_el","",20,-6,6);
   TH1F *Eta_mu=new TH1F("h_Eta_mu","",20,-6,6);
   TH1F *Eta_ta=new TH1F("h_Eta_ta","",20,-6,8);
  TH1F *Eta_j1=new TH1F("h_Eta_j1","",20,-6,10);
  TH1F *Eta_j2=new TH1F("h_Eta_j2","",20,-6,10);
/*  
  const int emNBINS=6;
  double_t emedges[emNBINS + 1] = {-6,-2.4,-1.2,0.0,1.2,2.4,6};
  TH1F *Eta_el=new TH1F("h_Eta_el","",emNBINS,emedges);
  TH1F *Eta_mu=new TH1F("h_Eta_mu","",emNBINS,emedges);
  
  const int taNBINS=5;
  double_t taedges[taNBINS + 1] = {-6,-1.2,0.0,1.2,2.4,6};  
  TH1F *Eta_ta=new TH1F("h_Eta_ta","",taNBINS,taedges);
  
  const int jNBINS=8;
  double_t jedges[jNBINS + 1] = {-6,-4.6,-3.2,-1.8,-0.4,1.,2.4,3.8,8};
  TH1F *Eta_j1=new TH1F("h_Eta_j1","",jNBINS,jedges);
  
  TH1F *Eta_j2=new TH1F("h_Eta_j2","",jNBINS,jedges);*/


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    int npart = branchParticle->GetEntries();
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);

      if(abs(Particle->PID)==11){ Eta_el->Fill(Particle->Eta); }
      else if(abs(Particle->PID)==15){ Eta_ta->Fill(Particle->Eta); }
      else if(abs(Particle->PID)==13){ Eta_mu->Fill(Particle->Eta); }
      else if(abs(Particle->PID)<10&&j==npart-1) { Eta_j2->Fill(Particle->Eta); }
      else if(abs(Particle->PID)<10&&j==npart-2) { Eta_j1->Fill(Particle->Eta); }
    }  
  }

    
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
  int n=treeReader->GetEntries();
  
  double lum=100*1000;   
  double xsec=1.;
  
  if(strcmp(argv[1],"SM")==0)
    {
//    xsec=0.0272;
      xsec=0.003017;  
    }
  else if(strcmp(argv[1],"cW_int")==0)
    { 
//    xsec=0.0006169;
      xsec=0.0001197; 
    }
  else if(strcmp(argv[1],"cW_quad")==0)
    {
//    xsec=0.008858; 
      xsec=0.00162;
    }
    
  else if(strcmp(argv[1],"cW_int_0.4")==0)
    { 
    xsec=0.000252; 
    }
  else if(strcmp(argv[1],"cW_quad_0.4")==0)
    {
    xsec=0.001394; 
    }

  else if(strcmp(argv[1],"cHW_int")==0)
    { 
    xsec=-0.00004092; 
    }
  else if(strcmp(argv[1],"cHW_quad")==0)
    { 
    xsec=0.0009115; 
    }
  else if(strcmp(argv[1],"cHWB_int")==0)
    { 
    xsec=-0.0001818; 
    }
  else if(strcmp(argv[1],"cHWB_quad")==0)
    { 
    xsec=0.000005341; 
    }
  else if(strcmp(argv[1],"cHbox_int")==0)
    { 
    xsec=-0.0000552; 
    }
  else if(strcmp(argv[1],"cHbox_quad")==0)
    { 
    xsec=0.00003789; 
    }
  else if(strcmp(argv[1],"cHDD_int")==0)
    { 
    xsec=-0.0001773; 
    }
  else if(strcmp(argv[1],"cHDD_quad")==0)
    { 
    xsec=0.00000635; 
    }
  else if(strcmp(argv[1],"cWtil_int")==0)
    { 
    xsec=0.00002017; 
    }
  else if(strcmp(argv[1],"cWtil_quad")==0)
    { 
    xsec=0.008843; 
    }      

  else if(strcmp(argv[1],"cHWtil_int")==0)
    { 
    xsec=0.0000007662; 
    }
  else if(strcmp(argv[1],"cHWtil_quad")==0)
    { 
    xsec=0.00007571; 
    }
  else if(strcmp(argv[1],"cHWBtil_int")==0)
    { 
    xsec=0.0000001041; 
    }
  else if(strcmp(argv[1],"cHWBtil_quad")==0)
    { 
    xsec=0.000002429; 
    } 

  double w=xsec*lum/n;

  int nbins = Eta_el->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = Eta_el->GetBinContent(i)*w;
    Eta_el->SetBinContent(i,c);
  }
  
  nbins = Eta_mu->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = Eta_mu->GetBinContent(i)*w;
    Eta_mu->SetBinContent(i,c);
  }
  
  nbins = Eta_ta->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = Eta_ta->GetBinContent(i)*w;
    Eta_ta->SetBinContent(i,c);
  }

  nbins = Eta_j1->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = Eta_j1->GetBinContent(i)*w;
    Eta_j1->SetBinContent(i,c);
  }
  
  nbins = Eta_j2->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = Eta_j2->GetBinContent(i)*w;
    Eta_j2->SetBinContent(i,c);
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Eta/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");
  
  Eta_el->Write();
  Eta_mu->Write();
  Eta_ta->Write();
  Eta_j1->Write();
  Eta_j2->Write();
  
  risultati->Close();

}

