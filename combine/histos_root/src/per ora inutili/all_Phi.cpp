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

  TH1F *Phi_el=new TH1F("h_Phi_el","",50,-5,5);
  TH1F *Phi_ve=new TH1F("h_Phi_ve","",50,-5,5);
  TH1F *Phi_mu=new TH1F("h_Phi_mu","",50,-5,5);
  TH1F *Phi_vm=new TH1F("h_Phi_vm","",50,-5,5);
  TH1F *Phi_ta=new TH1F("h_Phi_ta","",50,-5,5);
  TH1F *Phi_vt=new TH1F("h_Phi_vt","",50,-5,5); 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<branchParticle->GetEntries(); j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
     
      if(abs(Particle->PID)==11) Phi_el->Fill(Particle->Phi);
      else if(abs(Particle->PID)==12) Phi_ve->Fill(Particle->Phi);
      else if(abs(Particle->PID)==13) Phi_mu->Fill(Particle->Phi);
      else if(abs(Particle->PID)==14) Phi_vm->Fill(Particle->Phi);
      else if(abs(Particle->PID)==15) Phi_ta->Fill(Particle->Phi);
      else if(abs(Particle->PID)==16) Phi_vt->Fill(Particle->Phi);

    }
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Phi/%s_2017_inclusive.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  Phi_el->Write();
  Phi_ve->Write();
  Phi_mu->Write();
  Phi_vm->Write();
  Phi_ta->Write();
  Phi_vt->Write();
  risultati->Close();

}

