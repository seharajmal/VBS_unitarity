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

  char infile[50];
  sprintf(infile, "data/%s.root",argv[1]);
  TFile* file = TFile::Open(infile);
  TTree *t = (TTree*)file->Get("LHEF;1");
  ExRootTreeReader *treeReader = new ExRootTreeReader(t);
  const TClonesArray *branchParticle = treeReader->UseBranch("Particle");

  double xmax=1.7;
  double xmin=-1.7;
  
  TH1F *Zeppenfeld_12=new TH1F("h_Zeppenfeld_12","",10,xmin,xmax);
  TH1F *Zeppenfeld_1=new TH1F("h_Zeppenfeld_1","",10,xmin,xmax);
  TH1F *Zeppenfeld_2=new TH1F("h_Zeppenfeld_2","",10,xmin,xmax);

  
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
    
      double zeppy12, zeppy1, zeppy2;
      double etal1, etal2, etaj1, etaj2, maxx;
      double pt1, pt2;
      double ll = etal1 + etal2, jj = etaj1 + etaj2;
      
    cout << "### Event n." << i << " ### " << endl;
    cout << endl;
    
    for(int j=0; j<npart; j++){           /* j sono gli indici delle particelle */
      TRootLHEFParticle *Particle = (TRootLHEFParticle*) branchParticle->At(j);
      if(abs(Particle->PID)<10&&j==npart-1) {etaj2 = Particle->Eta; }
      else if(abs(Particle->PID)<10&&j==npart-2) { etaj1 = Particle->Eta; }
      else if(abs(Particle->PID)>10&&j==npart-6) { etal2 = Particle->Eta;
                                                   pt2 = Particle->PT; }
      else if(abs(Particle->PID)>10&&j==npart-5) { etal1 = Particle->Eta;
                                                   pt1 = Particle->PT; }
      
    //  cout << Particle->Eta << endl;
         
    }  
        
   //     cout << endl;
    
    
    if(pt2>pt1){maxx = etal2;
                    etal2 = etal1;
                    etal1 = maxx;}
        
 //       cout << etal1 << endl;
 //       cout << etal2 << endl;
 //       cout << endl;
                    
  
        zeppy12 = (ll-0.5*jj)/abs(etaj1-etaj2);
        zeppy1 = (etal1-0.5*jj)/abs(etaj1-etaj2);
        zeppy2 = (etal2-0.5*jj)/abs(etaj1-etaj2);
        
        int nbins = Zeppenfeld_12->GetNbinsX();
        double ovfl = xmax - (xmax-xmin)/(nbins+3);
        double undfl = xmin + (xmax-xmin)/(nbins+3);
        
       //   cout << zeppy12 << endl;
   //       cout << zeppy1 << endl;
       //   cout << zeppy2 << endl;
        //  cout << endl;

	if(zeppy12>xmax){Zeppenfeld_12->Fill(ovfl,w);}
	else if(zeppy12<xmin){Zeppenfeld_12->Fill(undfl,w);}
	else{Zeppenfeld_12->Fill(zeppy12,w);}  

	if(zeppy1>xmax){Zeppenfeld_1->Fill(ovfl,w);}
	else if(zeppy1<xmin){Zeppenfeld_1->Fill(undfl,w);}
	else{Zeppenfeld_1->Fill(zeppy1,w);}  

	if(zeppy2>xmax){Zeppenfeld_2->Fill(ovfl,w);}
	else if(zeppy2<xmin){Zeppenfeld_2->Fill(undfl,w);}
	else{Zeppenfeld_2->Fill(zeppy2,w);}  

  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  char outfile[50];
  sprintf(outfile, "histos/Zeppenfeld/%s.root",argv[1]);
  TFile* risultati=new TFile(outfile, "RECREATE");
  
  Zeppenfeld_12->Write();
  Zeppenfeld_1->Write();
  Zeppenfeld_2->Write();
  risultati->Close();

}

