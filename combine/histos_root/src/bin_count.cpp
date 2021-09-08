//#include "TDRStyle.h "
#include <TROOT.h>
#include <TStyle.h>
#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TH1D.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TClass.h>
#include <iostream>
#include <fstream>


using namespace std;
 
int main(int argc, char*argv[]){
 
   char observable[20];
   sprintf(observable, "%s",argv[1]);
   char eftop[20];
   sprintf(eftop, "%s",argv[2]);
   char eftcontr[20];
   sprintf(eftcontr, "%s",argv[3]);
   
   const char *part2 = "_";
   const char *part3 = "VBS_SSWW_SM_";
   const char *part5 =  "SM_";
   
   char histo[100];
   strcpy(histo,part3);
   strcat(histo,eftop);
   strcat(histo,part2);
   strcat(histo,eftcontr);
   
   char path[50];
   sprintf(path, "SR_inclusive_2017/VBS_SSWW_SM_%s_%s",argv[2],argv[3]);

   char filename[20];
   sprintf(filename, "%s_bins.txt",argv[1]);
   ofstream file;
   file.open(filename, fstream::app);

//---------------
   
   char infile1[50];
   sprintf(infile1, "histos4datacards/%s.root",argv[1]);
   TFile f1(infile1);
   f1.ls();
   auto h1 = (TH1F*) f1.Get("SR_inclusive_2017/VBS_SSWW_SM");
   h1->Sumw2(); //normalization
   double w = h1->Integral();//GetEntries();
   int n1=h1->GetNbinsX();
    
   char infile2[50];
   sprintf(infile2, "histos4datacards/%s.root",argv[1]);
   TFile f2(infile2); 
   f2.ls();
   auto h2 = (TH1F*) f2.Get(path);
   h2->Sumw2();
   double w1 = h2->Integral();//GetEntries();
   int n2=h2->GetNbinsX();


file << observable << " " << eftcontr << endl;
file << "     " << endl;


//---------------

for(int j=1; j<=n1; j++){
   int e1=h1->GetBinContent(j);
   int e2=h2->GetBinContent(j);
   int E=e1+e2;   
   file << j << " ha " << E << " eventi;  ";   
   }  

file << "     " << endl;
file << "     " << endl;
file << "     " << endl;

	
file.close();

 int i=0;
 return i;
}
