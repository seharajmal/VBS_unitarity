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
  
  vector<double> E;
  vector<double> PT;

  double xmax=600;
  double len=xmax/10;
  
  const int NBINS=8;
  double_t edges[NBINS + 1] = {0.0,len,2*len,3*len,4*len,5*len,6*len,7*len,xmax};
  
   TH1F *MET=new TH1F("h_MET","",NBINS,edges);
  //  TH1F *MET=new TH1F("h_MET","",10,0,xmax);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NORMALIZATIONto#EVENTS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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


int nbins = MET->GetNbinsX();
double ovfl = xmax - xmax/(nbins+3);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  for(int i=0; i<treeReader->GetEntries(); i++){
    treeReader->ReadEntry(i);
    int npart=branchParticle->GetEntries();
  if(branchParticle->GetEntries()==0) continue;
  if(npart!=10) continue;
  
  double px1, py1;
  double px2, py2;
  double met, px, py, pz, e;
  double Met;

  TLorentzVector v1;
  TLorentzVector v2;


    for(int j=0; j<npart; j++){
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(Particle->PT==0) continue;        
                                 
                                 
      if(abs(Particle->PID)>10&&j==npart-3) {
                                 px1 = Particle->Px;
                                 py1 = Particle->Py;
                                 
                                 px = Particle->Px;
      				  py = Particle->Py;
       			  pz = Particle->Pz;
       		          e = Particle->E;
                                 
                                 v1.SetPxPyPzE(px,py,pz,e);
                                 
                                 }
      else if(abs(Particle->PID)>10&&j==npart-4) {
                                 px2 = Particle->Px;
                                 py2 = Particle->Py;
                                 
                                 px = Particle->Px;
      				  py = Particle->Py;
       			  pz = Particle->Pz;
        		          e = Particle->E;
                                 
                                 v2.SetPxPyPzE(px,py,pz,e);
                                 
                                 }
      }
      
       
      Met = (v1 + v2).Pt();
      
      px = px1 + px2;
      py = py1 + py2;  
      met = sqrt(px*px+py*py);
      
      
      if(met>xmax){MET->Fill(ovfl,w);}
      else{MET->Fill(met,w);}         
     
  }
  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/MET/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");

  MET->Write();


  risultati->Close();

}

