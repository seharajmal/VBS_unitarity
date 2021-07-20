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

  TH1F *E_el=new TH1F("h_E_el","",50,0,800);
  TH1F *E_ve=new TH1F("h_E_ve","",50,0,800);
  TH1F *E_mu=new TH1F("h_E_mu","",50,0,800);
  TH1F *E_vm=new TH1F("h_E_vm","",50,0,800);
  TH1F *E_ta=new TH1F("h_E_ta","",50,0,800);
  TH1F *E_vt=new TH1F("h_E_vt","",50,0,800); 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<branchParticle->GetEntries(); j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(Particle->E==0) continue;

      if(abs(Particle->PID)==11) E_el->Fill(Particle->E);
      else if(abs(Particle->PID)==12) E_ve->Fill(Particle->E);
      else if(abs(Particle->PID)==13) E_mu->Fill(Particle->E);
      else if(abs(Particle->PID)==14) E_vm->Fill(Particle->E);
      else if(abs(Particle->PID)==15) E_ta->Fill(Particle->E);
      else if(abs(Particle->PID)==16) E_vt->Fill(Particle->E);

    }
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/E/%s_2017_inclusive.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  E_el->Write();
  E_ve->Write();
  E_mu->Write();
  E_vm->Write();
  E_ta->Write();
  E_vt->Write();
  risultati->Close();

}

