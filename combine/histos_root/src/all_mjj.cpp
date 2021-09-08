#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include "TROOT.h"
#include <TLorentzVector.h>
#include "ExRootTreeReader.h"
#include "ExRootClasses.h"
#include <cmath>
#include <iostream>
#include <TH1.h>
using namespace std;

int main(int argc, char*argv[]){

//  const int NBINS=9;
//  double_t edges[NBINS + 1] = {0.0, 1100.0, 2200.0, 3300.0, 4400.0, 5500.0, 6600.0, 7700.0, 8800.0, 11000.0};
//  TH1D *Mjj=new TH1D("h_mjj","",NBINS,edges);

   double xmax=5000;
   TH1F *Mjj=new TH1F("h_mjj","",10,0,xmax);

  char infile[50];
  sprintf(infile, "data/%s.root",argv[1]);
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");
  
  char outfile[50];
  sprintf(outfile, "histos/mjj/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");  

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
    int npart=branchParticle->GetEntries();
    if(npart==0) continue;
    TLorentzVector v;
    for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      
      if(j==npart-1||j==npart-2)
        {
        double px = Particle->Px;
        double py = Particle->Py;
        double pz = Particle->Pz;
        double e = Particle->E;
        v.SetPxPyPzE(px + v.Px(),py + v.Py(),pz + v.Pz(),e + v.E());
        }
        
    
     }        
     
        int nbins = Mjj->GetNbinsX();
        double ovfl = xmax - xmax/(nbins+3);

	double mjj=v.M();
	if(mjj>xmax){
	           Mjj->Fill(ovfl,w);
	           }
	else{Mjj->Fill(mjj,w);}
     
//        Mjj->Fill(v.M());
        v.Clear(); 
  
  }
  
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   
  


/*  int nbins = Mjj->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = Mjj->GetBinContent(i)*w;
    Mjj->SetBinContent(i,c);
  }
*/
 

Mjj->Write();


risultati->Close();




}

