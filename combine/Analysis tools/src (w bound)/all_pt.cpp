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

  char infile[50];
  sprintf(infile, "data/%s.root",argv[1]);
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");
  
  double xmax1=900;  //per i leptoni
  double len1=xmax1/10;
  
  double xmax2=1600;  //per i jet
  double len2=xmax2/10;

  const int NBINS1=3;
  const int NBINS2=5;
  
  
  //pt_j1
  
  double_t edgesj1[NBINS2 + 1] = {0.0,len2,2*len2,3*len2,4*len2,xmax2};
  TH1F *PT_j1=new TH1F("h_PT_j1","",NBINS2,edgesj1);
  
  //pt_j2
  
  double_t edgesj2[NBINS1 + 1] = {0.0,len2,2*len2,xmax2};
  TH1F *PT_j2=new TH1F("h_PT_j2","",NBINS1,edgesj2);
  
  //pt_l1
  
  double_t edgesl1[NBINS1 + 1] = {0.0,len1,2*len1,xmax1};
  TH1F *PT_l1=new TH1F("h_PT_l1","",NBINS1,edgesl1);
  
  //pt_l2
  
  double_t edgesl2[NBINS1 + 1] = {0.0,len1/2,len1,xmax1};
  TH1F *PT_l2=new TH1F("h_PT_l2","",NBINS1,edgesl2);

  
//  TH1F *PT_l1=new TH1F("h_PT_l1","",10,0,xmax1);
//  TH1F *PT_l2=new TH1F("h_PT_l2","",10,0,xmax1);
//  TH1F *PT_j1=new TH1F("h_PT_j1","",10,0,xmax2);
//  TH1F *PT_j2=new TH1F("h_PT_j2","",10,0,xmax2);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  vector<double> E;
  vector<double> Px;
  vector<double> Py;
  vector<double> Pz;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~Calcolo del peso~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  int n=treeReader->GetEntries();
  
  double lum=100*1000;   
  double xsec=1.;
  
  if(strcmp(argv[1],"SM")==0)
    {
    xsec=0.0272;
 //     xsec=0.001518;  
    }
  else if(strcmp(argv[1],"cW_int")==0)
    { 
    xsec=0.0006169;
 //      xsec=0.00008569; 
    }
  else if(strcmp(argv[1],"cW_quad")==0)
    {
    xsec=0.008858; 
//      xsec=0.001146;
    }
  else if(strcmp(argv[1],"cHW_int")==0)
    { 
    xsec=-0.00004092; 
//  xsec=0.00002587;
    }
  else if(strcmp(argv[1],"cHW_quad")==0)
    { 
  xsec=0.0009115; 
//  xsec=0.000009142;
    }
  else if(strcmp(argv[1],"cHWB_int")==0)
    { 
    xsec=-0.0001818;
//   xsec=-0.00001399; 
    }
  else if(strcmp(argv[1],"cHWB_quad")==0)
    { 
   xsec=0.000005341; 
//   xsec=0.0000003991;
    }
  else if(strcmp(argv[1],"cHbox_int")==0)
    { 
   xsec=-0.0000552; 
//   xsec=-0.000004942;
    }
  else if(strcmp(argv[1],"cHbox_quad")==0)
    { 
  xsec=0.00003789; 
//  xsec=0.000001162;
    }
  else if(strcmp(argv[1],"cHDD_int")==0)
    { 
   xsec=-0.0001773; 
//   xsec=-0.00001454;
    }
  else if(strcmp(argv[1],"cHDD_quad")==0)
    { 
   xsec=0.00000635; 
//  xsec=0.0000005996;
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
  else if(strcmp(argv[1],"cHq1_int")==0)
    { 
    xsec=0.0001158;
    }
    else if(strcmp(argv[1],"cHq1_quad")==0)
    { 
    xsec=0.0002699;     
    }
    else if(strcmp(argv[1],"cHq3_int")==0)
    { 
    xsec=0.005382;
    }
    else if(strcmp(argv[1],"cHq3_quad")==0)
    { 
    xsec=0.001632;
    }  
    else if(strcmp(argv[1],"cHl1_int")==0)
    { 
    xsec=0.000002135;
    }
    else if(strcmp(argv[1],"cHl1_quad")==0)
    { 
    xsec=0.000001646;
    } 
    else if(strcmp(argv[1],"cHl3_int")==0)
    { 
    xsec=-0.007525;
    }
    else if(strcmp(argv[1],"cHl3_quad")==0)
    { 
    xsec=0.0009231;
    }
        else if(strcmp(argv[1],"cqq1_int")==0)
    { 
    xsec=-0.002693;
    }
    else if(strcmp(argv[1],"cqq1_quad")==0)
    { 
    xsec=0.04174;
    } 
    else if(strcmp(argv[1],"cqq3_int")==0)
    { 
    xsec=-0.02057;
    }
    else if(strcmp(argv[1],"cqq3_quad")==0)
    { 
    xsec=0.1324; 
    }
    else if(strcmp(argv[1],"cqq11_int")==0)
    { 
    xsec=184.3;
    }
    else if(strcmp(argv[1],"cqq11_quad")==0)
    { 
    xsec=0.04079;
    } 
    else if(strcmp(argv[1],"cqq31_int")==0)
    { 
    xsec=9739;
    }
    else if(strcmp(argv[1],"cqq31_quad")==0)
    { 
    xsec=0.1351; 
    } 
    else if(strcmp(argv[1],"cll_int")==0)
    { 
    xsec=-0.0000000733;
    } 
    else if(strcmp(argv[1],"cll_quad")==0)
    { 
    xsec=0.0000003146; 
    }
    else if(strcmp(argv[1],"cll1_int")==0)
    { 
    xsec=0.005649;
    }
    else if(strcmp(argv[1],"cll1_quad")==0)
    { 
    xsec=0.0005135;
    } 

    
  double w=xsec*lum/n;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    int npart=branchParticle->GetEntries();
  if(branchParticle->GetEntries()==0) continue;
  if(npart!=10) continue;
    
  vector<double> PTj;
  vector<double> PTl;
  
  double sqrtS;
     
  for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(Particle->PT==0) continue;

      if(abs(Particle->PID)<10&&(j==npart-1||j==npart-2)) {
      				  PTj.push_back(Particle->PT);
      				  } 
      else if(abs(Particle->PID)==11||abs(Particle->PID)==15||abs(Particle->PID)==13) {
    //  else if(abs(Particle->PID)==12||abs(Particle->PID)==14||abs(Particle->PID)==16) {
      				  PTl.push_back(Particle->PT);
                                 } 
      else if(j==2&&abs(Particle->PID)==24) 
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
        if(strcmp(argv[1],"SM")!=0&&sqrtS>5744) continue;
    
      
      
      if(PTj[0]>PTj[1]){  
                      int nbins1 = PT_j1->GetNbinsX();
                      double ovfl1 = xmax2 - xmax2/(nbins1+3);
                      if(PTj[0]>xmax2){PT_j1->Fill(ovfl1,w);}
	              else{PT_j1->Fill(PTj[0],w);}      
	              
	              int nbins2 = PT_j2->GetNbinsX();
                      double ovfl2 = xmax2 - xmax2/(nbins2+3);
                      if(PTj[1]>xmax2){PT_j2->Fill(ovfl2,w);}
	              else{PT_j2->Fill(PTj[1],w);}                       
                      }
      else if(PTj[0]<PTj[1]){
                      int nbins1 = PT_j1->GetNbinsX();
                      double ovfl1 = xmax2 - xmax2/(nbins1+3);
                      if(PTj[1]>xmax2){PT_j1->Fill(ovfl1,w);}
	              else{PT_j1->Fill(PTj[1],w);}      
	              
	              int nbins2 = PT_j2->GetNbinsX();
                      double ovfl2 = xmax2 - xmax2/(nbins2+3);
                      if(PTj[0]>xmax2){PT_j2->Fill(ovfl2,w);}
	              else{PT_j2->Fill(PTj[0],w);} 
                      }      
                      
       
      if(PTl[0]>PTl[1]){  
                      int nbins1 = PT_l1->GetNbinsX();
                      double ovfl1 = xmax1 - xmax1/(nbins1+3);
                      if(PTl[0]>xmax1){PT_l1->Fill(ovfl1,w);}
	              else{PT_l1->Fill(PTl[0],w);}      
	              
	              int nbins2 = PT_l2->GetNbinsX();
                      double ovfl2 = xmax1 - xmax1/(nbins2+3);
                      if(PTl[1]>xmax1){PT_l2->Fill(ovfl2,w);}
	              else{PT_l2->Fill(PTl[1],w);}                       
                      }
      else if(PTl[0]<PTl[1]){
                      int nbins1 = PT_l1->GetNbinsX();
                      double ovfl1 = xmax1 - xmax1/(nbins1+3);
                      if(PTl[1]>xmax1){PT_l1->Fill(ovfl1,w);}
	              else{PT_l1->Fill(PTl[1],w);}      
	              
	              int nbins2 = PT_l2->GetNbinsX();
                      double ovfl2 = xmax1 - xmax1/(nbins2+3);
                      if(PTl[0]>xmax1){PT_l2->Fill(ovfl2,w);}
	              else{PT_l2->Fill(PTl[0],w);} 
                      }     
                      
                      
      	E.clear();
	Px.clear();
	Py.clear();
	Pz.clear();
                      
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/PT/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  PT_l1->Write();  
  PT_l2->Write(); 
  PT_j1->Write();  
  PT_j2->Write();  

  risultati->Close();
  }
  


