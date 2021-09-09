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

/*   
  const int NBINS=5;
  double_t edges[NBINS + 1] = {0.0, 60.0, 120.0, 180.0, 240.0, 1200.0};
  TH1D *PT_el=new TH1D("h_PT_el","",NBINS,edges);  
  TH1D *PT_mu=new TH1D("h_PT_mu","",NBINS,edges);  
  TH1D *PT_ta=new TH1D("h_PT_ta","",NBINS,edges);  
  
  const int NBINS2=9;
  double_t edges2[NBINS2 + 1] = {0.0, 120.0, 240.0, 360.0, 480.0, 600.0, 720.0, 840.0,960, 1200.0};
  TH1D *PT_j1=new TH1D("h_PT_j1","",NBINS2,edges2);
  TH1D *PT_j2=new TH1D("h_PT_j2","",NBINS2,edges2);
*/

  double xmax=1200;

  TH1F *PT_el=new TH1F("h_PT_el","",50,0,xmax);
  TH1F *PT_ta=new TH1F("h_PT_ta","",50,0,xmax);
  TH1F *PT_mu=new TH1F("h_PT_mu","",50,0,xmax);
  TH1F *PT_j1=new TH1F("h_PT_j1","",50,0,xmax);
  TH1F *PT_j2=new TH1F("h_PT_j2","",50,0,xmax);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NORMALIZATIONto#EVENTS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
    int npart=branchParticle->GetEntries();
  if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(Particle->PT==0) continue;

      if(abs(Particle->PID)==11) {
                                 int nbins = PT_el->GetNbinsX();
                                 double ovfl = xmax - xmax/(nbins+3);
                                 double pt = Particle->PT;
                                 if(pt>xmax){PT_el->Fill(ovfl,w);}
	                         else{PT_el->Fill(pt,w);}                            
                                 }
      else if(abs(Particle->PID)==15) {
                                 int nbins = PT_ta->GetNbinsX();
                                 double ovfl = xmax - xmax/(nbins+3);
                                 double pt = Particle->PT;
                                 if(pt>xmax){PT_ta->Fill(ovfl,w);}
	                         else{PT_ta->Fill(pt,w);}                            
                                 }
      else if(abs(Particle->PID)==13) {
                                 int nbins = PT_mu->GetNbinsX();
                                 double ovfl = xmax - xmax/(nbins+3);
                                 double pt = Particle->PT;
                                 if(pt>xmax){PT_mu->Fill(ovfl,w);}
	                         else{PT_mu->Fill(pt,w);}                            
                                 }
      else if(abs(Particle->PID)<10&&j==npart-1) {
                                 int nbins = PT_j2->GetNbinsX();
                                 double ovfl = xmax - xmax/(nbins+3);
                                 double pt = Particle->PT;
                                 if(pt>xmax){PT_j2->Fill(ovfl,w);}
	                         else{PT_j2->Fill(pt,w);}                            
                                 }
      else if(abs(Particle->PID)<10&&j==npart-2) {
                                 int nbins = PT_j1->GetNbinsX();
                                 double ovfl = xmax - xmax/(nbins+3);
                                 double pt = Particle->PT;
                                 if(pt>xmax){PT_j1->Fill(ovfl,w);}
	                         else{PT_j1->Fill(pt,w);}                            
                                 }
     } 
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

