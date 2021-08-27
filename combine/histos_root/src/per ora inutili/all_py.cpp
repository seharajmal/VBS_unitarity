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

  TH1F *Py_el=new TH1F("h_Py_el","",50,0,800);
  TH1F *Py_ve=new TH1F("h_Py_ve","",50,0,800);
  TH1F *Py_mu=new TH1F("h_Py_mu","",50,0,800);
  TH1F *Py_vm=new TH1F("h_Py_vm","",50,0,800);
  TH1F *Py_ta=new TH1F("h_Py_ta","",50,0,800);
  TH1F *Py_vt=new TH1F("h_Py_vt","",50,0,800); 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    if(branchParticle->GetEntries()==0) continue;

    for(int j=0; j<branchParticle->GetEntries(); j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(Particle->Py==0) continue;

      if(abs(Particle->PID)==11) Py_el->Fill(Particle->Py);
      else if(abs(Particle->PID)==12) Py_ve->Fill(Particle->Py);
      else if(abs(Particle->PID)==13) Py_mu->Fill(Particle->Py);
      else if(abs(Particle->PID)==14) Py_vm->Fill(Particle->Py);
      else if(abs(Particle->PID)==15) Py_ta->Fill(Particle->Py);
      else if(abs(Particle->PID)==16) Py_vt->Fill(Particle->Py);

    }
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Py/%s_2017_inclusive.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  Py_el->Write();
  Py_ve->Write();
  Py_mu->Write();
  Py_vm->Write();
  Py_ta->Write();
  Py_vt->Write();
  risultati->Close();

}

