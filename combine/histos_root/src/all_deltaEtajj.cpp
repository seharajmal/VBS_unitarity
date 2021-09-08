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

//Lavora sugli output di ExRootAnalysis, contenuti in "data"

int main(int argc, char*argv[]){

  char infile[50];
  sprintf(infile, "data/%s.root",argv[1]);
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");

  double xmax=13;
  double xmin=-13;
  
  TH1F *deltaEta=new TH1F("h_deltaEtajj","",30,xmin,xmax);
  double delta;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~Calcolo del peso~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
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
  


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    int npart = branchParticle->GetEntries();            
    if(branchParticle->GetEntries()==0) continue;
    
    for(int j=0; j<npart; j++){           /* j sono gli indici delle particelle */
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      double eta1;
      double eta2;
      if(abs(Particle->PID)<10&&j==npart-1) {eta2 = Particle->Eta; }
      else if(abs(Particle->PID)<10&&j==npart-2) { eta1 = Particle->Eta; }
      delta = eta1 - eta2;
      deltaEta->Fill(delta);
      
    }  
  

    
        int nbins = deltaEta->GetNbinsX();
        double ovfl = xmax - (xmax-xmin)/(nbins+3);

	if(delta>xmax){
	           deltaEta->Fill(ovfl,w);
	           }
	else{deltaEta->Fill(delta,w);}  


/*  for (int i=0; i<nbins; i++){
    double c = deltaEta->GetBinContent(i)*w;
    deltaEta->SetBinContent(i,c); */
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/deltaEtajj/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");
  
  deltaEta->Write();
  
  risultati->Close();

}

