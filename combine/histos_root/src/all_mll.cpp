#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include "TROOT.h"
#include "ExRootTreeReader.h"
#include "ExRootClasses.h"
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char*argv[]){

  vector<double> E;
  vector<double> Px;
  vector<double> Py;
  vector<double> Pz;
  
//  const int nbins=5;
//  double_t edges[nbins + 1]={0.0,150.0,300.0,450.0,600.0,3000.0};
//  TH1F *Mll=new TH1F("h_mll","",nbins,edges);
  
   double xmax=700;
  
   TH1F *Mll=new TH1F("h_mll","",10,0,xmax);
// TH1F *Mll=new TH1F("h_mll","",10,0,3000);
  
  char infile[50];
  sprintf(infile, "data/%s.root",argv[1]);
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");
  

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
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<branchParticle->GetEntries(); j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);

//metti gli eventi con mll > 700 nell'ultimo bin 
    
      if(abs(Particle->PID)==11||abs(Particle->PID)==13||abs(Particle->PID)==15) 
        {
        E.push_back(Particle->E);
        Px.push_back(Particle->Px);
        Py.push_back(Particle->Py);
        Pz.push_back(Particle->Pz);    
        }

     }
      
        TLorentzVector l1(Px[0],Py[0],Pz[0],E[0]);
        TLorentzVector l2(Px[1],Py[1],Pz[1],E[1]);
        
//      mll=sqrt(pow(E[0]+E[1],2)-pow(Px[0]+Px[1],2)-pow(Py[0]+Py[1],2)-pow(Pz[0]+Pz[1],2));

        int nbins = Mll->GetNbinsX();
        double ovfl = xmax - xmax/(nbins+3);


	double mll=(l1+l2).M();
	if(mll>xmax){
	           Mll->Fill(ovfl,w);
	           }
	else{Mll->Fill(mll,w);}
        E.clear();
        Px.clear();
        Py.clear();
        Pz.clear();
  
  }
  
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   
  

/*
  int Nbins = Mll->GetNbinsX();
  for (int i=0; i<Nbins; i++){
    double c = Mll->GetBinContent(i)*w;
    Mll->SetBinContent(i,c);
  }
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char outfile[50];
sprintf(outfile, "histos/mll/%s.root",argv[1]);
TFile* risultati=new TFile(outfile, "RECREATE");

Mll->Write();
risultati->Close();


}

