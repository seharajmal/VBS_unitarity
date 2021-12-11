#include <TAxis.h>
#include <TGraph.h>
#include <TH1F.h>
#include <TTree.h>
#include <TFile.h>
#include <TSystem.h>
#include <TClonesArray.h>
#include "TROOT.h"
#include <cmath>
#include <iostream>
#include <ostream>
#include <TF1.h>
#include <TLine.h>
#include <filesystem>
#include <TROOT.h>
#include <TStyle.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TClass.h>
#include <TMath.h>
#include <vector>
#include <algorithm> 

using namespace std;

TGraph *g;
double myfunc(Double_t *x, Double_t *) { return g->Eval(x[0]);}

int main(int argc, char*argv[]) {

char eftop[20];
sprintf(eftop, "%s",argv[1]);

// vector<double> width1;
// vector<double> width2;

double y1=3.84, y2=1.0;

//------mjj------

cout << "#### mjj ####" << endl;

char infile_mjj[100];
sprintf(infile_mjj, "likelihoodScan/mjj/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_mjj = TFile::Open(infile_mjj);
g = (TGraph*) f_mjj->Get("Graph;1");

TF1 *f1_mjj = new TF1("f1_mjj",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_mjj->GetX(y2,-10000,0)<< ";" <<f1_mjj->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_mjj->GetX(y1,-10000,0)<<";"<<f1_mjj->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_mjj->GetMinimumX(-10,10)<<endl; 

double w1_mjj = f1_mjj->GetX(y2,0,10000) - f1_mjj->GetX(y2,-10000,0);
double w2_mjj = f1_mjj->GetX(y1,0,10000) - f1_mjj->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_mjj <<endl;
 cout<<"Width 2sigma for mjj= " << w2_mjj <<endl;
cout << endl;


//------mll------

cout << "#### mll ####" << endl;

char infile_mll[100];
sprintf(infile_mll, "likelihoodScan/mll/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_mll = TFile::Open(infile_mll);
g = (TGraph*) f_mll->Get("Graph;1");

TF1 *f1_mll = new TF1("f1_mll",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_mll->GetX(y2,-10000,0)<< ";" <<f1_mll->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_mll->GetX(y1,-10000,0)<<";"<<f1_mll->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_mll->GetMinimumX(-10,10)<<endl; 

double w1_mll = f1_mll->GetX(y2,0,10000) - f1_mll->GetX(y2,-10000,0);
double w2_mll = f1_mll->GetX(y1,0,10000) - f1_mll->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_mll <<endl;
 cout<<"Width 2sigma for mll= " << w2_mll <<endl;
cout << endl;


//------MET------

cout << "#### MET ####" << endl;

char infile_MET[100];
sprintf(infile_MET, "likelihoodScan/MET/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_MET = TFile::Open(infile_MET);
g = (TGraph*) f_MET->Get("Graph;1");

TF1 *f1_MET = new TF1("f1_MET",myfunc,-10,1000,0);

cout<<"1sigma Confidence Interval = ["<< f1_MET->GetX(y2,-10000,0)<< ";" <<f1_MET->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_MET->GetX(y1,-10000,0)<<";"<<f1_MET->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_MET->GetMinimumX(-10,10)<<endl; 

double w1_MET = f1_MET->GetX(y2,0,10000) - f1_MET->GetX(y2,-10000,0);
double w2_MET = f1_MET->GetX(y1,0,10000) - f1_MET->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_MET <<endl;
 cout<<"Width 2sigma for MET= " << w2_MET <<endl;
cout << endl;


//------deltaPhijj------

cout << "#### deltaPhijj ####" << endl;

char infile_deltaPhijj[100];
sprintf(infile_deltaPhijj, "likelihoodScan/deltaPhijj/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_deltaPhijj = TFile::Open(infile_deltaPhijj);
g = (TGraph*) f_deltaPhijj->Get("Graph;1");

TF1 *f1_deltaPhijj = new TF1("f1_deltaPhijj",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_deltaPhijj->GetX(y2,-10000,0)<< ";" <<f1_deltaPhijj->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_deltaPhijj->GetX(y1,-10000,0)<<";"<<f1_deltaPhijj->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_deltaPhijj->GetMinimumX(-10,10)<<endl; 

double w1_deltaPhijj = f1_deltaPhijj->GetX(y2,0,10000) - f1_deltaPhijj->GetX(y2,-10000,0);
double w2_deltaPhijj = f1_deltaPhijj->GetX(y1,0,10000) - f1_deltaPhijj->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_deltaPhijj <<endl;
 cout<<"Width 2sigma for deltaPhijj= " << w2_deltaPhijj <<endl;
cout << endl;



//------deltaEtajj------

cout << "#### deltaEtajj ####" << endl;

char infile_deltaEtajj[100];
sprintf(infile_deltaEtajj, "likelihoodScan/deltaEtajj/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_deltaEtajj = TFile::Open(infile_deltaEtajj);
g = (TGraph*) f_deltaEtajj->Get("Graph;1");

TF1 *f1_deltaEtajj = new TF1("f1_deltaEtajj",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_deltaEtajj->GetX(y2,-10000,0)<< ";" <<f1_deltaEtajj->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_deltaEtajj->GetX(y1,-10000,0)<<";"<<f1_deltaEtajj->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_deltaEtajj->GetMinimumX(-10,10)<<endl; 

double w1_deltaEtajj = f1_deltaEtajj->GetX(y2,0,10000) - f1_deltaEtajj->GetX(y2,-10000,0);
double w2_deltaEtajj = f1_deltaEtajj->GetX(y1,0,10000) - f1_deltaEtajj->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_deltaEtajj <<endl;
 cout<<"Width 2sigma = " << w2_deltaEtajj <<endl;
cout << endl;



//------Eta_l1------

cout << "#### Eta_l1 ####" << endl;

char infile_Eta_l1[100];
sprintf(infile_Eta_l1, "likelihoodScan/Eta_l1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_Eta_l1 = TFile::Open(infile_Eta_l1);
g = (TGraph*) f_Eta_l1->Get("Graph;1");

TF1 *f1_Eta_l1 = new TF1("f1_Eta_l1",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_Eta_l1->GetX(y2,-10000,0)<< ";" <<f1_Eta_l1->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_Eta_l1->GetX(y1,-10000,0)<<";"<<f1_Eta_l1->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_Eta_l1->GetMinimumX(-10,10)<<endl; 

double w1_Eta_l1 = f1_Eta_l1->GetX(y2,0,10000) - f1_Eta_l1->GetX(y2,-10000,0);
double w2_Eta_l1 = f1_Eta_l1->GetX(y1,0,10000) - f1_Eta_l1->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_Eta_l1 <<endl;
 cout<<"Width 2sigma for Eta_l1= " << w2_Eta_l1 <<endl;
cout << endl;


//------Eta_l2------

cout << "#### Eta_l2 ####" << endl;

char infile_Eta_l2[100];
sprintf(infile_Eta_l2, "likelihoodScan/Eta_l2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_Eta_l2 = TFile::Open(infile_Eta_l2);
g = (TGraph*) f_Eta_l2->Get("Graph;1");

TF1 *f1_Eta_l2 = new TF1("f1_Eta_l2",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_Eta_l2->GetX(y2,-10000,0)<< ";" <<f1_Eta_l2->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_Eta_l2->GetX(y1,-10000,0)<<";"<<f1_Eta_l2->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_Eta_l2->GetMinimumX(-10,10)<<endl; 

double w1_Eta_l2 = f1_Eta_l2->GetX(y2,0,10000) - f1_Eta_l2->GetX(y2,-10000,0);
double w2_Eta_l2 = f1_Eta_l2->GetX(y1,0,10000) - f1_Eta_l2->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_Eta_l2 <<endl;
 cout<<"Width 2sigma for Eta_l2= " << w2_Eta_l2 <<endl;
cout << endl;


//------Eta_j1------

cout << "#### Eta_j1 ####" << endl;

char infile_Eta_j1[100];
sprintf(infile_Eta_j1, "likelihoodScan/Eta_j1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_Eta_j1 = TFile::Open(infile_Eta_j1);
g = (TGraph*) f_Eta_j1->Get("Graph;1");

TF1 *f1_Eta_j1 = new TF1("f1_Eta_j1",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_Eta_j1->GetX(y2,-10000,0)<< ";" <<f1_Eta_j1->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_Eta_j1->GetX(y1,-10000,0)<<";"<<f1_Eta_j1->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_Eta_j1->GetMinimumX(-10,10)<<endl; 

double w1_Eta_j1 = f1_Eta_j1->GetX(y2,0,10000) - f1_Eta_j1->GetX(y2,-10000,0);
double w2_Eta_j1 = f1_Eta_j1->GetX(y1,0,10000) - f1_Eta_j1->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_Eta_j1 <<endl;
 cout<<"Width 2sigma for Eta_j1= " << w2_Eta_j1 <<endl;
cout << endl;


//------Eta_j2------

cout << "#### Eta_j2 ####" << endl;

char infile_Eta_j2[100];
sprintf(infile_Eta_j2, "likelihoodScan/Eta_j2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_Eta_j2 = TFile::Open(infile_Eta_j2);
g = (TGraph*) f_Eta_j2->Get("Graph;1");

TF1 *f1_Eta_j2 = new TF1("f1_Eta_j2",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_Eta_j2->GetX(y2,-10000,0)<< ";" <<f1_Eta_j2->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_Eta_j2->GetX(y1,-10000,0)<<";"<<f1_Eta_j2->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_Eta_j2->GetMinimumX(-10,10)<<endl; 

double w1_Eta_j2 = f1_Eta_j2->GetX(y2,0,10000) - f1_Eta_j2->GetX(y2,-10000,0);
double w2_Eta_j2 = f1_Eta_j2->GetX(y1,0,10000) - f1_Eta_j2->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_Eta_j2 <<endl;
 cout<<"Width 2sigma for Eta_j2= " << w2_Eta_j2 <<endl;
cout << endl;


//------PT_l1------

cout << "#### PT_l1 ####" << endl;

char infile_PT_l1[100];
sprintf(infile_PT_l1, "likelihoodScan/PT_l1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_PT_l1 = TFile::Open(infile_PT_l1);
g = (TGraph*) f_PT_l1->Get("Graph;1");

TF1 *f1_PT_l1 = new TF1("f1_PT_l1",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_PT_l1->GetX(y2,-10000,0)<< ";" <<f1_PT_l1->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_PT_l1->GetX(y1,-10000,0)<<";"<<f1_PT_l1->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_PT_l1->GetMinimumX(-10,10)<<endl; 

double w1_PT_l1 = f1_PT_l1->GetX(y2,0,10000) - f1_PT_l1->GetX(y2,-10000,0);
double w2_PT_l1 = f1_PT_l1->GetX(y1,0,10000) - f1_PT_l1->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_PT_l1 <<endl;
 cout<<"Width 2sigma PT_l1= " << w2_PT_l1 <<endl;
cout << endl;


//------PT_l2------

cout << "#### PT_l2 ####" << endl;

char infile_PT_l2[100];
sprintf(infile_PT_l2, "likelihoodScan/PT_l2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_PT_l2 = TFile::Open(infile_PT_l2);
g = (TGraph*) f_PT_l2->Get("Graph;1");

TF1 *f1_PT_l2 = new TF1("f1_PT_l2",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_PT_l2->GetX(y2,-10000,0)<< ";" <<f1_PT_l2->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_PT_l2->GetX(y1,-10000,0)<<";"<<f1_PT_l2->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_PT_l2->GetMinimumX(-10,10)<<endl; 

double w1_PT_l2 = f1_PT_l2->GetX(y2,0,10000) - f1_PT_l2->GetX(y2,-10000,0);
double w2_PT_l2 = f1_PT_l2->GetX(y1,0,10000) - f1_PT_l2->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_PT_l2 <<endl;
 cout<<"Width 2sigma PT_l2= " << w2_PT_l2 <<endl;
cout << endl;

//------PT_j1------

cout << "#### PT_j1 ####" << endl;

char infile_PT_j1[100];
sprintf(infile_PT_j1, "likelihoodScan/PT_j1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_PT_j1 = TFile::Open(infile_PT_j1);
g = (TGraph*) f_PT_j1->Get("Graph;1");

TF1 *f1_PT_j1 = new TF1("f1_PT_j1",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_PT_j1->GetX(y2,-10000,0)<< ";" <<f1_PT_j1->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_PT_j1->GetX(y1,-10000,0)<<";"<<f1_PT_j1->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_PT_j1->GetMinimumX(-10,10)<<endl; 

double w1_PT_j1 = f1_PT_j1->GetX(y2,0,10000) - f1_PT_j1->GetX(y2,-10000,0);
double w2_PT_j1 = f1_PT_j1->GetX(y1,0,10000) - f1_PT_j1->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_PT_j1 <<endl;
 cout<<"Width 2sigma PT_j1= " << w2_PT_j1 <<endl;
cout << endl;


//------PT_j2------

cout << "#### PT_j2 ####" << endl;

char infile_PT_j2[100];
sprintf(infile_PT_j2, "likelihoodScan/PT_j2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_PT_j2 = TFile::Open(infile_PT_j2);
g = (TGraph*) f_PT_j2->Get("Graph;1");

TF1 *f1_PT_j2 = new TF1("f1_PT_j2",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_PT_j2->GetX(y2,-10000,0)<< ";" <<f1_PT_j2->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_PT_j2->GetX(y1,-10000,0)<<";"<<f1_PT_j2->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_PT_j2->GetMinimumX(-10,10)<<endl; 

double w1_PT_j2 = f1_PT_j2->GetX(y2,0,10000) - f1_PT_j2->GetX(y2,-10000,0);
double w2_PT_j2 = f1_PT_j2->GetX(y1,0,10000) - f1_PT_j2->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_PT_j2 <<endl;
 cout<<"Width 2sigma PT_j2= " << w2_PT_j2 <<endl;
cout << endl;
cout << endl;



//------ Zeppenfeld_12 ------

cout << "#### Zeppenfeld_12 ####" << endl;

char infile_Zeppenfeld_12[100];
sprintf(infile_Zeppenfeld_12, "likelihoodScan/Zeppenfeld_12/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_Zeppenfeld_12 = TFile::Open(infile_Zeppenfeld_12);
g = (TGraph*) f_Zeppenfeld_12->Get("Graph;1");

TF1 *f1_Zeppenfeld_12 = new TF1("f1_Zeppenfeld_12",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_Zeppenfeld_12->GetX(y2,-10000,0)<< ";" <<f1_Zeppenfeld_12->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_Zeppenfeld_12->GetX(y1,-10000,0)<<";"<<f1_Zeppenfeld_12->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_Zeppenfeld_12->GetMinimumX(-10,10)<<endl; 

double w1_zeppy_12 = f1_Zeppenfeld_12->GetX(y2,0,10000) - f1_Zeppenfeld_12->GetX(y2,-10000,0);
double w2_zeppy_12 = f1_Zeppenfeld_12->GetX(y1,0,10000) - f1_Zeppenfeld_12->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_zeppy <<endl;
 cout<<"Width 2sigma Zeppenfeld_12= " << w2_zeppy_12 <<endl;
cout << endl;
cout << endl;


//------ Zeppenfeld_1 ------

cout << "#### Zeppenfeld_1 ####" << endl;

char infile_Zeppenfeld_1[100];
sprintf(infile_Zeppenfeld_1, "likelihoodScan/Zeppenfeld_1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_Zeppenfeld_1 = TFile::Open(infile_Zeppenfeld_1);
g = (TGraph*) f_Zeppenfeld_1->Get("Graph;1");

TF1 *f1_Zeppenfeld_1 = new TF1("f1_Zeppenfeld_1",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_Zeppenfeld_1->GetX(y2,-10000,0)<< ";" <<f1_Zeppenfeld_1->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_Zeppenfeld_1->GetX(y1,-10000,0)<<";"<<f1_Zeppenfeld_1->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_Zeppenfeld_1->GetMinimumX(-10,10)<<endl; 

double w1_zeppy_1 = f1_Zeppenfeld_1->GetX(y2,0,10000) - f1_Zeppenfeld_1->GetX(y2,-10000,0);
double w2_zeppy_1 = f1_Zeppenfeld_1->GetX(y1,0,10000) - f1_Zeppenfeld_1->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_zeppy <<endl;
 cout<<"Width 2sigma Zeppenfeld_1= " << w2_zeppy_1 <<endl;
cout << endl;
cout << endl;


//------ Zeppenfeld_2 ------

cout << "#### Zeppenfeld_2 ####" << endl;

char infile_Zeppenfeld_2[100];
sprintf(infile_Zeppenfeld_2, "likelihoodScan/Zeppenfeld_2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_Zeppenfeld_2 = TFile::Open(infile_Zeppenfeld_2);
g = (TGraph*) f_Zeppenfeld_2->Get("Graph;1");

TF1 *f1_Zeppenfeld_2 = new TF1("f1_Zeppenfeld_2",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_Zeppenfeld_2->GetX(y2,-10000,0)<< ";" <<f1_Zeppenfeld_2->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_Zeppenfeld_2->GetX(y1,-10000,0)<<";"<<f1_Zeppenfeld_2->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_Zeppenfeld_2->GetMinimumX(-10,10)<<endl; 

double w1_zeppy_2 = f1_Zeppenfeld_2->GetX(y2,0,10000) - f1_Zeppenfeld_2->GetX(y2,-10000,0);
double w2_zeppy_2 = f1_Zeppenfeld_2->GetX(y1,0,10000) - f1_Zeppenfeld_2->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_zeppy <<endl;
 cout<<"Width 2sigma Zeppenfeld_2= " << w2_zeppy_2 <<endl;
cout << endl;
cout << endl;


//------ Mo1 ------

cout << "#### Mo1 ####" << endl;

char infile_Mo1[100];
sprintf(infile_Mo1, "likelihoodScan/Mo1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_Mo1 = TFile::Open(infile_Mo1);
g = (TGraph*) f_Mo1->Get("Graph;1");

TF1 *f1_Mo1 = new TF1("f1_Mo1",myfunc,-10,1000,0);


cout<<"1sigma Confidence Interval = ["<< f1_Mo1->GetX(y2,-10000,0)<< ";" <<f1_Mo1->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_Mo1->GetX(y1,-10000,0)<<";"<<f1_Mo1->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_Mo1->GetMinimumX(-10,10)<<endl; 

double w1_Mo1 = f1_Mo1->GetX(y2,0,10000) - f1_Mo1->GetX(y2,-10000,0);
double w2_Mo1 = f1_Mo1->GetX(y1,0,10000) - f1_Mo1->GetX(y1,-10000,0);

// cout<<"Width 1sigma = " << w1_Mo1 <<endl;
 cout<<"Width 2sigma Mo1= " << w2_Mo1 <<endl;
cout << endl;
cout << endl;


//------ M1T ------

cout << "#### M1T ####" << endl;

char infile_M1T[100];
sprintf(infile_M1T, "likelihoodScan/M1T/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *f_M1T = TFile::Open(infile_M1T);
g = (TGraph*) f_M1T->Get("Graph;1");

TF1 *f1_M1T = new TF1("f1_M1T",myfunc,-10,1000,0);




cout<<"1sigma Confidence Interval = ["<< f1_M1T->GetX(y2,-10000,0)<< ";" <<f1_M1T->GetX(y2,0,10000)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1_M1T->GetX(y1,-10000,0)<<";"<<f1_M1T->GetX(y1,0,10000)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1_M1T->GetMinimumX(-10,10)<<endl; 

double w1_M1T = f1_M1T->GetX(y2,0,10000) - f1_M1T->GetX(y2,-10000,0);
double w2_M1T = f1_M1T->GetX(y1,0,10000) - f1_M1T->GetX(y1,-10000,0); 

// cout<<"Width 1sigma = " << w1_M1T <<endl;
 cout<<"Width 2sigma M1T= " << w2_M1T <<endl;
cout << endl;
cout << endl;



//-------------------------------------------------------------------

double width1[] = {w1_mjj, w1_mll, w1_MET, w1_deltaPhijj, w1_Eta_l1, w1_Eta_l2, w1_Eta_j1, w1_Eta_j2, w1_PT_l1, w1_PT_l2, w1_PT_j1, w1_PT_j2, w1_deltaEtajj, w1_zeppy_12, w1_Mo1, w1_M1T, w1_zeppy_1, w1_zeppy_2}; 
double width2[] = {w2_mjj, w2_mll, w2_MET, w2_deltaPhijj, w2_Eta_l1, w2_Eta_l2, w2_Eta_j1, w2_Eta_j2, w2_PT_l1, w2_PT_l2, w2_PT_j1, w2_PT_j2, w2_deltaEtajj, w2_zeppy_12, w2_Mo1, w2_M1T, w2_zeppy_1, w2_zeppy_2}; 


//------------------- Best Confidence Interval -----------------------



double min1=width1[0];
double min2=width2[0];

for(int i=0;i<18;i++){
                     if(width1[i]<min1){min1=width1[i];}
                     }
                     
for(int i=0;i<18;i++){
                     if(width2[i]<min2){min2=width2[i];}
                     }

int a;
int b;

for(int i=0; i<18; i++){
                       if(min1==width1[i]){a=i;}            
                       }

if(a==0){ cout << "Best observable is mjj" << endl;}
else if(a==1){ cout << "Best observable is mll" << endl;}
else if(a==2){ cout << "Best observable is MET" << endl;}
else if(a==3){ cout << "Best observable is deltaPhijj" << endl;}
else if(a==4){ cout << "Best observable is Eta_l1" << endl;}
else if(a==5){ cout << "Best observable is Eta_l2" << endl;}
else if(a==6){ cout << "Best observable is Eta_j1" << endl;}
else if(a==7){ cout << "Best observable is Eta_j2" << endl;}
else if(a==8){ cout << "Best observable is PT_l1" << endl;}
else if(a==9){ cout << "Best observable is PT_l2" << endl;}
else if(a==10){ cout << "Best observable is PT_j1" << endl;}
else if(a==11){ cout << "Best observable is PT_j2" << endl;}
else if(a==12){ cout << "Best observable is deltaEtajj" << endl;}
else if(a==13){ cout << "Best observable is Zeppenfeld_12" << endl;}
else if(a==14){ cout << "Best observable is Mo1" << endl;}
else if(a==15){ cout << "Best observable is M1T" << endl;}
else if(a==16){ cout << "Best observable is Zeppenfeld_1" << endl;}
else if(a==17){ cout << "Best observable is Zeppenfeld_2" << endl;}


for(int i=0; i<18; i++){
                       if(min2==width2[i]){b=i;}            
                       }

if(b==0){ cout << "Best observable is mjj" << endl;}
else if(b==1){ cout << "Best observable is mll" << endl;}
else if(b==2){ cout << "Best observable is MET" << endl;}
else if(b==3){ cout << "Best observable is deltaPhijj" << endl;}
else if(b==4){ cout << "Best observable is Eta_l1" << endl;}
else if(b==5){ cout << "Best observable is Eta_l2" << endl;}
else if(b==6){ cout << "Best observable is Eta_j1" << endl;}
else if(b==7){ cout << "Best observable is Eta_j2" << endl;}
else if(b==8){ cout << "Best observable is PT_l1" << endl;}
else if(b==9){ cout << "Best observable is PT_l2" << endl;}
else if(b==10){ cout << "Best observable is PT_j1" << endl;}
else if(b==11){ cout << "Best observable is PT_j2" << endl;}
else if(b==12){ cout << "Best observable is deltaEtajj" << endl;}
else if(b==13){ cout << "Best observable is Zeppenfeld_12" << endl;}
else if(b==14){ cout << "Best observable is Mo1" << endl;}
else if(b==15){ cout << "Best observable is M1T" << endl;}
else if(b==16){ cout << "Best observable is Zeppenfeld_1" << endl;}
else if(b==17){ cout << "Best observable is Zeppenfeld_2" << endl;}


cout << endl;

//------------------- Worst Confidence Interval -----------------------

double max1=width1[0];
double max2=width2[0];

for(int i=0;i<16;i++){
                     if(width1[i]>max1){max1=width1[i];}
                     }
                     
for(int i=0;i<18;i++){
                     if(width2[i]>max2){max2=width2[i];}
                     }

int c;
int d;

for(int i=0; i<18; i++){
                       if(max1==width1[i]){c=i;}            
                       }

if(c==0){ cout << "Worst observable is mjj" << endl;}
else if(c==1){ cout << "Worst observable is mll" << endl;}
else if(c==2){ cout << "Worst observable is MET" << endl;}
else if(c==3){ cout << "Worst observable is deltaPhijj" << endl;}
else if(c==4){ cout << "Worst observable is Eta_l1" << endl;}
else if(c==5){ cout << "Worst observable is Eta_l2" << endl;}
else if(c==6){ cout << "Worst observable is Eta_j1" << endl;}
else if(c==7){ cout << "Worst observable is Eta_j2" << endl;}
else if(c==8){ cout << "Worst observable is PT_l1" << endl;}
else if(c==9){ cout << "Worst observable is PT_l2" << endl;}
else if(c==10){ cout << "Worst observable is PT_j1" << endl;}
else if(c==11){ cout << "Worst observable is PT_j2" << endl;}
else if(c==12){ cout << "Worst observable is deltaEtajj" << endl;}
else if(c==13){ cout << "Worst observable is Zeppenfeld_12" << endl;}
else if(c==14){ cout << "Worst observable is Mo1" << endl;}
else if(c==15){ cout << "Worst observable is M1T" << endl;}
else if(c==16){ cout << "Worst observable is Zeppenfeld_1" << endl;}
else if(c==17){ cout << "Worst observable is Zeppenfeld_2" << endl;}

for(int i=0; i<18; i++){
                       if(max2==width2[i]){d=i;}            
                       }

if(d==0){ cout << "Worst observable is mjj" << endl;}
else if(d==1){ cout << "Worst observable is mll" << endl;}
else if(d==2){ cout << "Worst observable is MET" << endl;}
else if(d==3){ cout << "Worst observable is deltaPhijj" << endl;}
else if(d==4){ cout << "Worst observable is Eta_l1" << endl;}
else if(d==5){ cout << "Worst observable is Eta_l2" << endl;}
else if(d==6){ cout << "Worst observable is Eta_j1" << endl;}
else if(d==7){ cout << "Worst observable is Eta_j2" << endl;}
else if(d==8){ cout << "Worst observable is PT_l1" << endl;}
else if(d==9){ cout << "Worst observable is PT_l2" << endl;}
else if(d==10){ cout << "Worst observable is PT_j1" << endl;}
else if(d==11){ cout << "Worst observable is PT_j2" << endl;}
else if(d==12){ cout << "Worst observable is deltaEtajj" << endl;}
else if(d==13){ cout << "Worst observable is Zeppenfeld_12" << endl;}
else if(d==14){ cout << "Worst observable is Mo1" << endl;}
else if(d==15){ cout << "Worst observable is M1T" << endl;}
else if(d==16){ cout << "Worst observable is Zeppenfeld_1" << endl;}
else if(d==17){ cout << "Worst observable is Zeppenfeld_2" << endl;}

cout << endl;

//----------------------------------------------

/*
for(int i=0; i<12; i++){
   cout << width2[i] << endl;
   }
*/

cout << endl;
cout << "#### Ordered Intervals (from best to worst) ####" << endl;
cout << endl;

   for (int i=0; i<18; i++) {
      int index = i;
      for (int j=i+1; j<18; j++)
         if (width2[j] < width2[index]) 
            {index = j;}
      
      double temp = width2[index];  
      width2[index] = width2[i];
      width2[i] = temp;
   }
   

for(int i=0; i<18; i++){
   cout << i+1 << ". ";
   if(width2[i]==w2_mjj){ cout << "mjj";}
   else if(width2[i]==w2_mll){ cout << "mll";}
   else if(width2[i]==w2_MET){ cout << "MET";} 
   else if(width2[i]==w2_deltaPhijj){ cout << "deltaPhijj";}
   else if(width2[i]==w2_Eta_l1){ cout << "Eta_l1";}
   else if(width2[i]==w2_Eta_l2){ cout << "Eta_l2";}
   else if(width2[i]==w2_Eta_j1){ cout << "Eta_j1";} 
   else if(width2[i]==w2_Eta_j2){ cout << "Eta_j2";}
   else if(width2[i]==w2_PT_l1){ cout << "PT_l1";}
   else if(width2[i]==w2_PT_l2){ cout << "PT_l2";}
   else if(width2[i]==w2_PT_j1){ cout << "PT_j1";}
   else if(width2[i]==w2_PT_j2){ cout << "PT_j2";}
   else if(width2[i]==w2_deltaEtajj){ cout << "deltaEtajj";}
   else if(width2[i]==w2_zeppy_12){ cout << "Zeppenfeld_12";}
   else if(width2[i]==w2_Mo1){ cout << "Mo1";}
   else if(width2[i]==w2_M1T){ cout << "M1T";}
   else if(width2[i]==w2_zeppy_1){ cout << "Zeppenfeld_1";}
   else if(width2[i]==w2_zeppy_2){ cout << "Zeppenfeld_2";}
   
   cout << " (" << width2[i] << ") -> ";
   
   if(i==0){ cout << "kRed/Solid line" << endl;}
   else if(i==1){ cout << "kOrange+1"<< endl;}
   else if(i==2){ cout << "kYellow"<< endl;} 
   else if(i==3){ cout << "kGreen"<< endl;}
   else if(i==4){ cout << "kGreen+2"<< endl;}
   else if(i==5){ cout << "kTeal"<< endl;}
   else if(i==6){ cout << "kAzure+10"<< endl;} 
   else if(i==7){ cout << "kBlue+1"<< endl;}
   else if(i==8){ cout << "kViolet-5"<< endl;}
   else if(i==9){ cout << "kMagenta"<< endl;}
   else if(i==10){ cout << "kAzure+9"<< endl;}
  else if(i==11){ cout << "kBlue+1"<< endl;}
   else if(i==12){ cout << "kViolet-5"<< endl;}
   else if(i==13){ cout << "kMagenta-3"<< endl;}
   else if(i==14){ cout << "kMagenta"<< endl;}
   else if(i==15){ cout << "kMagenta-10"<< endl;}
   else if(i==16){ cout << "kRed-9"<< endl;}
   else if(i==17){ cout << "kRed-7"<< endl;}
   
   }


//----------------------------------------------

int i=0;
return i;

}
