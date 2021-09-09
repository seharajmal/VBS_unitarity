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


  double xmax=5;
  double xmin=-5;
  
  TH1F *deltaPhijj=new TH1F("h_deltaPhijj","",100,xmin,xmax);
  double delta;
  
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
      double phi1;
      double phi2;
      if(abs(Particle->PID)<10&&j==npart-1) {phi2 = Particle->Phi; }
      else if(abs(Particle->PID)<10&&j==npart-2) { phi1 = Particle->Phi; }
      delta = phi1 - phi2;
      
    
        int nbins = deltaPhijj->GetNbinsX();
        double ovfl = xmax - (xmax-xmin)/(nbins+3);
        double undfl = xmin + (xmax-xmin)/(nbins+3);


	if(delta>xmax){deltaPhijj->Fill(ovfl,w);}
	else if(delta<xmin){deltaPhijj->Fill(undfl,w);}
	else{deltaPhijj->Fill(delta,w);} 
    
      
    }  
  }

    

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/deltaPhijj/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");
  
  deltaPhijj->Write();
  
  risultati->Close();

}

