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
  
  vector<double> E;
  vector<double> PT;
   
  const int NBINS=5;
  double_t edges[NBINS + 1] = {0.0, 60.0, 120.0, 180.0, 240.0, 1200.0};
  TH1D *PT_el=new TH1D("h_PT_el","",NBINS,edges);  
  TH1D *PT_mu=new TH1D("h_PT_mu","",NBINS,edges);  
  TH1D *PT_ta=new TH1D("h_PT_ta","",NBINS,edges);  
  
  const int NBINS2=9;
  double_t edges2[NBINS2 + 1] = {0.0, 120.0, 240.0, 360.0, 480.0, 600.0, 720.0, 840.0,960, 1200.0};
  TH1D *PT_j1=new TH1D("h_PT_j","",NBINS2,edges2);
  TH1D *PT_j2=new TH1D("h_PT_j","",NBINS2,edges2);
/*
  TH1F *PT_el=new TH1F("h_PT_el","",10,0,1200);
  TH1F *PT_ta=new TH1F("h_PT_ta","",10,0,1200);
  TH1F *PT_mu=new TH1F("h_PT_mu","",10,0,1200);
  TH1F *PT_j=new TH1F("h_PT_j","",10,0,1200);
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  int npart=branchParticle->GetEntries();
  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(Particle->PT==0) continue;

      if(abs(Particle->PID)==11) PT_el->Fill(Particle->PT);
      else if(abs(Particle->PID)==15) PT_ta->Fill(Particle->PT);
      else if(abs(Particle->PID)==13) PT_mu->Fill(Particle->PT);
      else if(abs(Particle->PID)<10&&j==npart-1) { PT_j2->Fill(Particle->PT); }
      else if(abs(Particle->PID)<10&&j==npart-2) { PT_j1->Fill(Particle->PT); }
     } 
  }
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NORMALIZATIONto#EVENTS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  int n=treeReader->GetEntries();
  
  double lum=100*1000;   
  double xsec=1.;
  
  if(strcmp(argv[1],"SM")==0)
    {
    xsec=0.0272; 
    }
  else if(strcmp(argv[1],"cW_int")==0)
    { 
    xsec=0.0006169; 
    }
  else if(strcmp(argv[1],"cW_quad")==0)
    {
    xsec=0.008858; 
    }
    
  else if(strcmp(argv[1],"cW_int")==0)
    { 
    xsec=0.0006169; 
    }
  else if(strcmp(argv[1],"cW_quad")==0)
    {
    xsec=0.008858; 
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

  int nbins = PT_el->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = PT_el->GetBinContent(i)*w;
    PT_el->SetBinContent(i,c);
  }
  
  nbins = PT_mu->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = PT_mu->GetBinContent(i)*w;
    PT_mu->SetBinContent(i,c);
  }
  
  nbins = PT_ta->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = PT_ta->GetBinContent(i)*w;
    PT_ta->SetBinContent(i,c);
  }

  nbins = PT_j1->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = PT_j1->GetBinContent(i)*w;
    PT_j1->SetBinContent(i,c);
  }
  
  nbins = PT_j2->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = PT_j2->GetBinContent(i)*w;
    PT_j2->SetBinContent(i,c);
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/PT/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  PT_el->Write();
  PT_ta->Write();
  PT_mu->Write();
  PT_j1->Write();  
  PT_j2->Write();  

  risultati->Close();

}

