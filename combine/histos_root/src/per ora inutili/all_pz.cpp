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

  TH1F *Pz_el=new TH1F("h_Pz_el","",50,0,800);
  TH1F *Pz_ve=new TH1F("h_Pz_ve","",50,0,800);
  TH1F *Pz_mu=new TH1F("h_Pz_mu","",50,0,800);
  TH1F *Pz_vm=new TH1F("h_Pz_vm","",50,0,800);
  TH1F *Pz_ta=new TH1F("h_Pz_ta","",50,0,800);
  TH1F *Pz_vt=new TH1F("h_Pz_vt","",50,0,800); 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<branchParticle->GetEntries(); j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(Particle->Py==0) continue;

      if(abs(Particle->PID)==11) Pz_el->Fill(Particle->Pz);
      else if(abs(Particle->PID)==12) Pz_ve->Fill(Particle->Pz);
      else if(abs(Particle->PID)==13) Pz_mu->Fill(Particle->Pz);
      else if(abs(Particle->PID)==14) Pz_vm->Fill(Particle->Pz);
      else if(abs(Particle->PID)==15) Pz_ta->Fill(Particle->Pz);
      else if(abs(Particle->PID)==16) Pz_vt->Fill(Particle->Pz);

    }
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Pz/%s_2017_inclusive.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  Pz_el->Write();
  Pz_ve->Write();
  Pz_mu->Write();
  Pz_vm->Write();
  Pz_ta->Write();
  Pz_vt->Write();
  risultati->Close();

}

