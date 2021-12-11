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
#include <TLorentzVector.h>
using namespace std;

int main(int argc, char*argv[]){

  char infile[50];
  sprintf(infile, "data/%s.root",argv[1]);
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");

  double xmaxl=2.5;
  double xminl=-2.5;
  double xmaxj=5;
  double xminj=-5;

  double len=(xmaxj-xminj)/10;

  TH1F *Eta_l1=new TH1F("h_Eta_l1","",10,xminl,xmaxl);
  TH1F *Eta_l2=new TH1F("h_Eta_l2","",10,xminl,xmaxl);
  
  const int NBINSj=8;
  double_t edges[NBINSj + 1] = {xminj,xminj+2*len,xminj+3*len,xminj+4*len,xminj+5*len,xminj+6*len,xminj+7*len,xminj+8*len,xmaxj};
  TH1F *Eta_j1=new TH1F("h_Eta_j1","",NBINSj,edges);
  TH1F *Eta_j2=new TH1F("h_Eta_j2","",NBINSj,edges);


//  TH1F *Eta_j1=new TH1F("h_Eta_j1","",10,xminj,xmaxj);
//  TH1F *Eta_j2=new TH1F("h_Eta_j2","",10,xminj,xmaxj);
  
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
    int npart = branchParticle->GetEntries();
    if(branchParticle->GetEntries()==0) continue;
    if(npart!=10) continue;
    
  vector<double> PTj;
  vector<double> PTl;
  vector<double> Etaj;
  vector<double> Etal;
  
  double sqrtS;
     
  for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);

      if(abs(Particle->PID)<10&&(j==npart-1||j==npart-2)) {
      				  PTj.push_back(Particle->PT);
      				  Etaj.push_back(Particle->Eta);
      				  } 
      else if(abs(Particle->PID)==11||abs(Particle->PID)==15||abs(Particle->PID)==13) {
      				  PTl.push_back(Particle->PT);
      				  Etal.push_back(Particle->Eta);
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
                      int nbins1 = Eta_j1->GetNbinsX();
                      double ovfl1 = xmaxj - (xmaxj-xminj)/(nbins1+3);
                      double undfl1 = xminj + (xmaxj-xminj)/(nbins1+3);
                      if(Etaj[0]>xmaxj){Eta_j1->Fill(ovfl1,w);}
                      else if(Etaj[0]<xminj){Eta_j1->Fill(undfl1,w);}
	              else{Eta_j1->Fill(Etaj[0],w);}      
	              
	              int nbins2 = Eta_j2->GetNbinsX();
                      double ovfl2 = xmaxj - (xmaxj-xminj)/(nbins2+3);
                      double undfl2 = xminj + (xmaxj-xminj)/(nbins2+3);
                      if(Etaj[1]>xmaxj){Eta_j2->Fill(ovfl2,w);}
                      else if(Etaj[1]<xminj){Eta_j2->Fill(undfl2,w);}
	              else{Eta_j2->Fill(Etaj[1],w);}                       
                      }
      else if(PTj[0]<PTj[1]){
                      int nbins1 = Eta_j1->GetNbinsX();
                      double ovfl1 = xmaxj - (xmaxj-xminj)/(nbins1+3);
                      double undfl1 = xminj + (xmaxj-xminj)/(nbins1+3);
                      if(Etaj[1]>xmaxj){Eta_j1->Fill(ovfl1,w);}
                      else if(Etaj[1]<xminj){Eta_j1->Fill(undfl1,w);}
	              else{Eta_j1->Fill(Etaj[1],w);}      
	              
	              int nbins2 = Eta_j2->GetNbinsX();
                      double ovfl2 = xmaxj - (xmaxj-xminj)/(nbins2+3);
                      double undfl2 = xminj + (xmaxj-xminj)/(nbins2+3);
                      if(Etaj[0]>xmaxj){Eta_j2->Fill(ovfl2,w);}
                      else if(Etaj[0]<xminj){Eta_j2->Fill(undfl2,w);}
	              else{Eta_j2->Fill(Etaj[0],w);} 
                      }      
     

      if(PTl[0]>PTl[1]){  
                      int nbins1 = Eta_l1->GetNbinsX();
                      double ovfl1 = xmaxl - (xmaxl-xminl)/(nbins1+3);
                      double undfl1 = xminl + (xmaxl-xminl)/(nbins1+3);
                      if(Etal[0]>xmaxl){Eta_l1->Fill(ovfl1,w);}
                      else if(Etal[0]<xminl){Eta_l1->Fill(undfl1,w);}
	              else{Eta_l1->Fill(Etal[0],w);}      
	              
	              int nbins2 = Eta_l2->GetNbinsX();
                      double ovfl2 = xmaxl - (xmaxl-xminl)/(nbins2+3);
                      double undfl2 = xminl + (xmaxl-xminl)/(nbins2+3);
                      if(Etal[1]>xmaxl){Eta_l2->Fill(ovfl2,w);}
                      else if(Etal[1]<xminl){Eta_l2->Fill(undfl2,w);}
	              else{Eta_l2->Fill(Etal[1],w);}                       
                      }
      else if(PTl[0]<PTl[1]){
                      int nbins1 = Eta_l1->GetNbinsX();
                      double ovfl1 = xmaxl - (xmaxl-xminl)/(nbins1+3);
                      double undfl1 = xminl + (xmaxl-xminl)/(nbins1+3);
                      if(Etal[1]>xmaxl){Eta_l1->Fill(ovfl1,w);}
                      else if(Etal[1]<xminl){Eta_l1->Fill(undfl1,w);}
	              else{Eta_l1->Fill(Etal[1],w);}      
	              
	              int nbins2 = Eta_l2->GetNbinsX();
                      double ovfl2 = xmaxl - (xmaxl-xminl)/(nbins2+3);
                      double undfl2 = xminl + (xmaxl-xminl)/(nbins2+3);
                      if(Etal[0]>xmaxl){Eta_l2->Fill(ovfl2,w);}
                      else if(Etal[0]<xminl){Eta_l2->Fill(undfl2,w);}
	              else{Eta_l2->Fill(Etal[0],w);} 
                      }      
     

  	E.clear();
	Px.clear();
	Py.clear();
	Pz.clear();
 
 
 
    }



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Eta/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  Eta_l1->Write();
  Eta_l2->Write();
  Eta_j1->Write();
  Eta_j2->Write();
  
  risultati->Close();

}

