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

  TH1F *Px_el=new TH1F("h_Px_el","",50,0,800);
  TH1F *Px_ve=new TH1F("h_Px_ve","",50,0,800);
  TH1F *Px_mu=new TH1F("h_Px_mu","",50,0,800);
  TH1F *Px_vm=new TH1F("h_Px_vm","",50,0,800);
  TH1F *Px_ta=new TH1F("h_Px_ta","",50,0,800);
  TH1F *Px_vt=new TH1F("h_Px_vt","",50,0,800); 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<branchParticle->GetEntries(); j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(Particle->Px==0) continue;

      if(abs(Particle->PID)==11) Px_el->Fill(Particle->Px);
      else if(abs(Particle->PID)==12) Px_ve->Fill(Particle->Px);
      else if(abs(Particle->PID)==13) Px_mu->Fill(Particle->Px);
      else if(abs(Particle->PID)==14) Px_vm->Fill(Particle->Px);
      else if(abs(Particle->PID)==15) Px_ta->Fill(Particle->Px);
      else if(abs(Particle->PID)==16) Px_vt->Fill(Particle->Px);

    }
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Px/%s_2017_inclusive.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  Px_el->Write();
  Px_ve->Write();
  Px_mu->Write();
  Px_vm->Write();
  Px_ta->Write();
  Px_vt->Write();
  risultati->Close();

}

