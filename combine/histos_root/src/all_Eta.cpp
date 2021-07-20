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

  TH1F *Eta_el=new TH1F("h_Eta_el","",20,-10,10);
  TH1F *Eta_ta=new TH1F("h_Eta_ta","",20,-10,10);
  TH1F *Eta_mu=new TH1F("h_Eta_mu","",20,-10,10);
  TH1F *Eta_j=new TH1F("h_Eta_j","",20,-10,10);

/*    
  TH1F *Eta_j1=new TH1F("h_Eta_j1","",50,-10,10);
  TH1F *Eta_j2=new TH1F("h_Eta_j2","",50,-10,10);
  
  vector<double> PT;
  vector<double> Eta;
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<branchParticle->GetEntries(); j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);

      if(abs(Particle->PID)==11) Eta_el->Fill(Particle->Eta);
      else if(abs(Particle->PID)==15) Eta_ta->Fill(Particle->Eta);
      else if(abs(Particle->PID)==13) Eta_mu->Fill(Particle->Eta);
/*    else if(0<abs(Particle->PID)<6)
      	    {
      	    PT.push_back(Particle->PT);
      	    Eta.push_back(Particle->Eta);
      	    }
        }       
     
       if(PT[0]>=PT[1])
           {
           Eta_j1->Fill(PT[0]);
           Eta_j2->Fill(PT[1]);
           }
       else
           {
           Eta_j1->Fill(PT[1]);
           Eta_j2->Fill(PT[0]);
           }
       PT.clear();  
*/
      else if(0<abs(Particle->PID)<6) Eta_j->Fill(Particle->Eta);
    }  
  }

    
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
  
  int n=treeReader->GetEntries();
  
  double lum=42*1000;   
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

/*  
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
*/ 
 
  nbins = Eta_j->GetNbinsX();
  for (int i=0; i<nbins; i++){
    double c = Eta_j->GetBinContent(i)*w;
    Eta_j->SetBinContent(i,c);
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Eta/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  Eta_el->Write();
  Eta_mu->Write();
  Eta_ta->Write();
  Eta_j->Write();

/*  
  Eta_j1->Write();
  Eta_j2->Write();
*/

  risultati->Close();

}

