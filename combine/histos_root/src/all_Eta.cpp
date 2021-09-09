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

  double xmaxl=6;
  double xminl=-6;
  double xmaxj=8;
  double xminj=-6;

  TH1F *Eta_el=new TH1F("h_Eta_el","",20,xminl,xmaxl);
  TH1F *Eta_mu=new TH1F("h_Eta_mu","",20,xminl,xmaxl);
  TH1F *Eta_ta=new TH1F("h_Eta_ta","",20,xminl,xmaxl);
  TH1F *Eta_j1=new TH1F("h_Eta_j1","",20,xminj,xmaxj);
  TH1F *Eta_j2=new TH1F("h_Eta_j2","",20,xminj,xmaxj);
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
  
  int n=treeReader->GetEntries();
  
  double lum=100*1000;   
  double xsec=1.;
  
  if(strcmp(argv[1],"SM")==0)
    {
//    xsec=0.0272;
      xsec=0.001518;  
    }
  else if(strcmp(argv[1],"cW_int")==0)
    { 
//    xsec=0.0006169;
      xsec=0.00008569; 
    }
  else if(strcmp(argv[1],"cW_quad")==0)
    {
//    xsec=0.008858; 
      xsec=0.001146;
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


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    int npart = branchParticle->GetEntries();
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);

      if(abs(Particle->PID)==11) {
                                 int nbins = Eta_el->GetNbinsX();
                                 double ovfl = xmaxl - (xmaxl-xminl)/(nbins+3);
                                 double undfl = xminl + (xmaxl-xminl)/(nbins+3);
                                 double eta = Particle->Eta;
                                 if(eta>xmaxl){Eta_el->Fill(ovfl,w);}
                                 else if(eta<xminl){Eta_el->Fill(undfl,w);}
	                         else{Eta_el->Fill(eta,w);}                            
                                 }
      else if(abs(Particle->PID)==15) {
                                 int nbins = Eta_ta->GetNbinsX();
                                 double ovfl = xmaxl - (xmaxl-xminl)/(nbins+3);
                                 double undfl = xminl + (xmaxl-xminl)/(nbins+3);
                                 double eta = Particle->Eta;
                                 if(eta>xmaxl){Eta_ta->Fill(ovfl,w);}
                                 else if(eta<xminl){Eta_ta->Fill(undfl,w);}
	                         else{Eta_ta->Fill(eta,w);}                            
                                 }
      else if(abs(Particle->PID)==13) {
                                 int nbins = Eta_mu->GetNbinsX();
                                 double ovfl = xmaxl - (xmaxl-xminl)/(nbins+3);
                                 double undfl = xminl + (xmaxl-xminl)/(nbins+3);
                                 double eta = Particle->Eta;
                                 if(eta>xmaxl){Eta_mu->Fill(ovfl,w);}
                                 else if(eta<xminl){Eta_mu->Fill(undfl,w);}
	                         else{Eta_mu->Fill(eta,w);}                            
                                 }
      else if(abs(Particle->PID)<10&&j==npart-1) {
                                 int nbins = Eta_j2->GetNbinsX();
                                 double ovfl = xmaxj - (xmaxj-xminj)/(nbins+3);
                                 double undfl = xminj + (xmaxj-xminj)/(nbins+3);
                                 double eta = Particle->Eta;
                                 if(eta>xmaxj){Eta_j2->Fill(ovfl,w);}
                                 else if(eta<xminj){Eta_j2->Fill(undfl,w);}
	                         else{Eta_j2->Fill(eta,w);}                            
                                 }
      else if(abs(Particle->PID)<10&&j==npart-2) {
                                 int nbins = Eta_j1->GetNbinsX();
                                 double ovfl = xmaxj - (xmaxj-xminj)/(nbins+3);
                                 double undfl = xminj + (xmaxj-xminj)/(nbins+3);
                                 double eta = Particle->Eta;
                                 if(eta>xmaxj){Eta_j1->Fill(ovfl,w);}
                                 else if(eta<xminj){Eta_j1->Fill(undfl,w);}
	                         else{Eta_j1->Fill(eta,w);}                            
                                 }
    }  
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

