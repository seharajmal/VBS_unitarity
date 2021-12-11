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
#include <TLorentzVector.h>
using namespace std;


int main(int argc, char*argv[]){


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  vector<double> E;
  vector<double> Px;
  vector<double> Py;
  vector<double> Pz;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Contributi lineare~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char infile_lin[50];
  sprintf(infile_lin, "data/%s_int.root",argv[1]);
  TFile* file_lin = TFile::Open(infile_lin);
  TTree *t_lin = (TTree*)file_lin->Get("LHEF;1");
  ExRootTreeReader *treeReader_lin = new ExRootTreeReader(t_lin);
  const TClonesArray *branchParticle_lin = treeReader_lin->UseBranch("Particle");

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  

  int n_lin=treeReader_lin->GetEntries();           
      
   for(int i=0; i<treeReader_lin->GetEntries(); i++){
    treeReader_lin->ReadEntry(i);
    int npart = branchParticle_lin->GetEntries();            
    if(branchParticle_lin->GetEntries()==0) continue;
    if(npart!=10) n_lin = n_lin-1;
    }
    
   int n0_lin = n_lin;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader_lin->GetEntries(); i++){
    treeReader_lin->ReadEntry(i);
    int npart = branchParticle_lin->GetEntries();    
           
    if(branchParticle_lin->GetEntries()==0) continue;
    if(npart!=10) continue;
     
    double sqrtS;
    
    for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle_lin->At(j);
      if(j==2&&abs(Particle->PID)==24) 
        {
        E.push_back(Particle->E);
        Px.push_back(Particle->Px);
        Py.push_back(Particle->Py);
        Pz.push_back(Particle->Pz);    
        }
      else if(j==3&&abs(Particle->PID)==24) 
        {
        E.push_back(Particle->E);
        Px.push_back(Particle->Px);
        Py.push_back(Particle->Py);
        Pz.push_back(Particle->Pz);    
        }
     
    }  
           
        TLorentzVector p3(Px[0],Py[0],Pz[0],E[0]);
        TLorentzVector p4(Px[1],Py[1],Pz[1],E[1]);
        TLorentzVector p = p3 + p4;
        double s = p*p;
        sqrtS = sqrt(s);
        if(sqrtS>2400) n_lin = n_lin-1;
                      
  	E.clear();
	Px.clear();
	Py.clear();
	Pz.clear();
	
  }
  
  int w_lin = n0_lin - n_lin;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Contributi quadratico~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char infile_quad[50];
  sprintf(infile_quad, "data/%s_quad.root",argv[1]);
  TFile* file_quad = TFile::Open(infile_quad);
  TTree *t_quad = (TTree*)file_quad->Get("LHEF;1");
  ExRootTreeReader *treeReader_quad = new ExRootTreeReader(t_quad);
  const TClonesArray *branchParticle_quad = treeReader_quad->UseBranch("Particle");

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  

  int n_quad=treeReader_quad->GetEntries();           
      
   for(int i=0; i<treeReader_quad->GetEntries(); i++){
    treeReader_quad->ReadEntry(i);
    int npart = branchParticle_quad->GetEntries();            
    if(branchParticle_quad->GetEntries()==0) continue;
    if(npart!=10) n_quad = n_quad-1;
    }
    
  int n0_quad = n_quad;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader_quad->GetEntries(); i++){
    treeReader_quad->ReadEntry(i);
    int npart = branchParticle_quad->GetEntries();    
           
    if(branchParticle_quad->GetEntries()==0) continue;
    if(npart!=10) continue;
     
    double sqrtS;
    
    for(int j=0; j<npart; j++){
    TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle_quad->At(j);
      if(j==2&&abs(Particle->PID)==24) 
        {
        E.push_back(Particle->E);
        Px.push_back(Particle->Px);
        Py.push_back(Particle->Py);
        Pz.push_back(Particle->Pz);    
        }
      else if(j==3&&abs(Particle->PID)==24) 
        {
        E.push_back(Particle->E);
        Px.push_back(Particle->Px);
        Py.push_back(Particle->Py);
        Pz.push_back(Particle->Pz);    
        }
     
    }  
           
        TLorentzVector p3(Px[0],Py[0],Pz[0],E[0]);
        TLorentzVector p4(Px[1],Py[1],Pz[1],E[1]);
        TLorentzVector p = p3 + p4;
        double s = p*p;
        sqrtS = sqrt(s);
        if(sqrtS>2400) n_quad = n_quad-1;
                      
  	E.clear();
	Px.clear();
	Py.clear();
	Pz.clear();
	
  }

  int w_quad = n0_quad - n_quad;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Contributi Standard Model~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  TFile* file_sm = TFile::Open("data/SM.root");
  TTree *t_sm = (TTree*)file_sm->Get("LHEF;1");
  ExRootTreeReader *treeReader_sm = new ExRootTreeReader(t_sm);
  const TClonesArray *branchParticle_sm = treeReader_sm->UseBranch("Particle");

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  

  int n_sm=treeReader_sm->GetEntries();           
      
   for(int i=0; i<treeReader_sm->GetEntries(); i++){
    treeReader_sm->ReadEntry(i);
    int npart = branchParticle_sm->GetEntries();            
    if(branchParticle_sm->GetEntries()==0) continue;
    if(npart!=10) n_sm = n_sm-1;
    }
    
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Percentuale sul totale (SM+BSM)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int N0 = n_sm + n0_lin + n0_quad;
int N = N0 - w_lin - w_quad;
double perc = 100*(N0 - N)/N0;

cout << "Gli eventi che non rispettano il bound di unitarietà sono il " << perc << "%" << " degli eventi totali" << endl;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Percentuale sui soli contributi BSM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int N0_bsm = n0_lin + n0_quad;
int N_bsm = N0_bsm - w_lin - w_quad;
double perc_bsm = 100*(N0_bsm - N_bsm)/N0_bsm;

cout << "Gli eventi che non rispettano il bound di unitarietà sono il " << perc_bsm << "%" << " degli eventi BSM" << endl;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


}

