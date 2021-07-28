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
#include <iostream>
using namespace std;

int main(int argc, char*argv[]){

  TH1F *phip=new TH1F("phip","",10,0,4);
  TH1F *phin=new TH1F("phin","",10,-4,0);

  char infile[50];
  sprintf(infile, "data/%s.root",argv[1]);
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");
  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<branchParticle->GetEntries(); j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      int pid = abs(Particle->PID);
      if(pid==21||pid==1||pid==2||pid==3||pid==4||pid==5||pid==6||pid==7||pid==8)
        {
        double p = Particle->Phi;
        if(p>=0) {
        phip->Fill(p); 
                 }
        else {
        phin->Fill(p);
             }
        cout << p << endl;
        }
       cout << "end event" << endl; 
     }        
    
  }
  
  
 
  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Phi/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  phip->Write();
  phin->Write();

  risultati->Close();

}
