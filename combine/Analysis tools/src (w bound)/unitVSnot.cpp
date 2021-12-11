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
#include <TPad.h>
#include <TF1.h>
#include <fstream>

 using namespace std;
 
//----- function built on graphic of likelihood scan from combine ----- 
 
TGraph *gr;
double myfunc(Double_t *x, Double_t *) { return gr->Eval(x[0]);}

//-----
 
int main(int argc, char*argv[]){


///////////////// START CONFIG 
  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.5); //title X location 
  gStyle->SetTitleY(0.96); //title Y location 
  gStyle->SetPaintTextFormat(".2f");
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");
 tdrStyle->SetCanvasBorderMode(0);
 tdrStyle->SetCanvasColor(kWhite);
 tdrStyle->SetCanvasDefH(600); //Height of canvas
 tdrStyle->SetCanvasDefW(600); //Width of canvas
 tdrStyle->SetCanvasDefX(0);   //POsition on screen
 tdrStyle->SetCanvasDefY(0);
 //For the Pad:
 tdrStyle->SetPadBorderMode(0);
 //tdrStyle->SetPadBorderSize(Width_t size = 1);
 tdrStyle->SetPadColor(kWhite);
 tdrStyle->SetPadGridX(true);
 tdrStyle->SetPadGridY(true);
 tdrStyle->SetGridColor(0);
 tdrStyle->SetGridStyle(3);
 tdrStyle->SetGridWidth(1);
 //For the frame:
 tdrStyle->SetFrameBorderMode(0);
 tdrStyle->SetFrameBorderSize(1);
 tdrStyle->SetFrameFillColor(0);
 tdrStyle->SetFrameFillStyle(0);
 tdrStyle->SetFrameLineColor(1);
 tdrStyle->SetFrameLineStyle(1);
 tdrStyle->SetFrameLineWidth(1);
 //For the histo:
 tdrStyle->SetHistFillColor(0);
 //tdrStyle->SetHistFillStyle(0);
 tdrStyle->SetHistLineColor(1);
 tdrStyle->SetHistLineStyle(0);
 tdrStyle->SetHistLineWidth(1);
 //tdrStyle->SetLegoInnerR(Float_t rad = 0.5);
 //tdrStyle->SetNumberContours(Int_t number = 20);
 //tdrStyle->SetEndErrorSize(0);
 tdrStyle->SetErrorX(0.);
//tdrStyle->SetErrorMarker(20);
 tdrStyle->SetMarkerStyle(20);
 //For the fit/function:
 tdrStyle->SetOptFit(1);
 tdrStyle->SetFitFormat("5.4g");
 //tdrStyle->SetFuncColor(1);
 tdrStyle->SetFuncStyle(1);
 tdrStyle->SetFuncWidth(1);
 //For the date:
 tdrStyle->SetOptDate(0);
 //tdrStyle->SetDateX(Float_t x = 0.01);
 //tdrStyle->SetDateY(Float_t y = 0.01);
 //For the statistics box:
 tdrStyle->SetOptFile(0);
 tdrStyle->SetOptStat(""); // To display the mean and RMS:   SetOptStat("mr");
 //tdrStyle->SetStatColor(kWhite);
 tdrStyle->SetStatColor(kGray);
 tdrStyle->SetStatFont(42);
 tdrStyle->SetTextSize(11);
 tdrStyle->SetTextAlign(11);
 tdrStyle->SetStatTextColor(1);
 tdrStyle->SetStatFormat("6.4g");
 tdrStyle->SetStatBorderSize(0);
 tdrStyle->SetStatX(1.); //Starting position on X axis
 tdrStyle->SetStatY(1.); //Starting position on Y axis
 tdrStyle->SetStatFontSize(0.025); //Vertical Size
 tdrStyle->SetStatW(0.25); //Horizontal size 
 //tdrStyle->SetStatStyle(Style_t style = 1001)
//Margins:
 tdrStyle->SetPadTopMargin(0.095);
 tdrStyle->SetPadBottomMargin(0.125);
 tdrStyle->SetPadLeftMargin(0.14);
 tdrStyle->SetPadRightMargin(0.1);
  // For the Global title:
  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);
  tdrStyle->SetTitleH(0.045); // Set the height of the title box
  //tdrStyle->SetTitleW(0); // Set the width of the title box
  tdrStyle->SetTitleX(0.20); // Set the position of the title box
  tdrStyle->SetTitleY(1.0); // Set the position of the title box
  //tdrStyle->SetTitleStyle(Style_t style = 1001);
  tdrStyle->SetTitleBorderSize(0);
  // For the axis titles:
  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.05);
  // For the axis labels:
  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");
  // For the axis:
  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(0); 
  tdrStyle->SetPadTickY(0);
  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);
  tdrStyle->cd();
///////////////// FINE CONFIG
 
  const int NBINS=55;
  double_t edges[NBINS + 1] = {0.0,0.6,1,1.4,1.6,2,2.4,2.6,3,3.4,3.6,4,4.4,4.6,5,5.4,5.6,6,6.4,6.6,7,7.4,7.6,8,8.4,8.6,9,9.4,9.6,10,10.4,10.6,11,11.4,11.6,12,12.4,12.6,13,13.4,13.6,14,14.4,14.6,15,15.4,15.6,16,16.4,16.6,17,17.4,17.6,18,18.4,19};
 
//----------------------------------------------- 
//--------- unitarity imposed analysis ----------
 
  TH1F *Yup=new TH1F("yellow_up","",NBINS,edges);
  TH1F *Gup=new TH1F("green_up","",NBINS,edges);
  TH1F *Ydown=new TH1F("yellow_down","",NBINS,edges);
  TH1F *Gdown=new TH1F("green_down","",NBINS,edges);
  
Yup->SetLineColor(kRed-10);
Yup->SetFillStyle(1001);
Yup->SetFillColor(kRed-10);

Ydown->SetLineColor(kRed-10);
Ydown->SetFillStyle(1001);
Ydown->SetFillColor(kRed-10);

Gup->SetLineColor(kRed);
Gup->SetFillStyle(1001);
Gup->SetFillColor(kRed);

Gdown->SetLineColor(kRed);
Gdown->SetFillStyle(1001);
Gdown->SetFillColor(kRed);

//----------------------------------------------- 
//--------- no unitarity analysis -----------

  TH1F *nYup=new TH1F("nyellow_up","",NBINS,edges);
  TH1F *nGup=new TH1F("ngreen_up","",NBINS,edges);
  TH1F *nYdown=new TH1F("nyellow_down","",NBINS,edges);
  TH1F *nGdown=new TH1F("ngreen_down","",NBINS,edges);

nYup->SetLineColor(kAzure+10);
nYup->SetFillStyle(1001);
nYup->SetFillColor(kAzure+10);

nYdown->SetLineColor(kAzure+10);
nYdown->SetFillStyle(1001);
nYdown->SetFillColor(kAzure+10);

nGup->SetLineColor(kBlue);
nGup->SetFillStyle(1001);
nGup->SetFillColor(kBlue);

nGdown->SetLineColor(kBlue);
nGdown->SetFillStyle(1001);
nGdown->SetFillColor(kBlue);

//----------------------------CALCULATION OF CONFIDENCE INTERVALS AND MINIMUM FOR EACH VARIABLE-------------------------------------                      

double y1=3.84, y2=1.0; 

//-----------------------------------------------------------------------------------------------------------------
//---------------------------------------- UNITARITY ANALYSIS -----------------------------------------------------            
              
                   
//-----mjj-----                   

char path1[100];                    // location of combine output 
sprintf(path1,"likelihoodScan/mjj/%s/LS_objects_k_%s.root",argv[1],argv[1]);
                       
TFile *f_mjj = TFile::Open(path1);
gr= (TGraph*) f_mjj->Get("Graph;1");
TF1 *f1 = new TF1("f1",myfunc,-1000,1000,0);

double s1down_mjj=f1->GetX(y2,-1000,0);
double s1up_mjj=f1->GetX(y2,0,1000);
double s2down_mjj=f1->GetX(y1,-1000,0);
double s2up_mjj=f1->GetX(y1,0,1000);

double min_mjj=f1->GetMinimumX(-10,10);

f_mjj->Close();                 
gr->Clear();
               
//-----mll-----                   
                       
char path2[100];
sprintf(path2,"likelihoodScan/mll/%s/LS_objects_k_%s.root",argv[1],argv[1]);
                       
TFile *f_mll = TFile::Open(path2);
gr= (TGraph*) f_mll->Get("Graph;1");
TF1 *f2 = new TF1("f2",myfunc,-1000,1000,0);

double s1down_mll=f2->GetX(y2,-1000,0);
double s1up_mll=f2->GetX(y2,0,1000);
double s2down_mll=f2->GetX(y1,-1000,0);
double s2up_mll=f2->GetX(y1,0,1000);

double min_mll=f2->GetMinimumX(-10,10);

f_mll->Close();
gr->Clear();          

//-----PT_l1-----    

char path3[100];
sprintf(path3,"likelihoodScan/PT_l1/%s/LS_objects_k_%s.root",argv[1],argv[1]);               
                       
TFile *f_pt_l1 = TFile::Open(path3);
gr= (TGraph*) f_pt_l1->Get("Graph;1");
TF1 *f3 = new TF1("f3",myfunc,-1000,1000,0);

double s1down_PT_l1=f3->GetX(y2,-1000,0);
double s1up_PT_l1=f3->GetX(y2,0,1000);
double s2down_PT_l1=f3->GetX(y1,-1000,0);
double s2up_PT_l1=f3->GetX(y1,0,1000);

double min_PT_l1=f3->GetMinimumX(-10,10);

f_pt_l1->Close();
gr->Clear();   

//-----PT_l2-----         

char path4[100];
sprintf(path4,"likelihoodScan/PT_l2/%s/LS_objects_k_%s.root",argv[1],argv[1]);          
                       
TFile *f_pt_l2 = TFile::Open(path4);
gr= (TGraph*) f_pt_l2->Get("Graph;1");
TF1 *f4 = new TF1("f4",myfunc,-1000,1000,0);

double s1down_PT_l2=f4->GetX(y2,-1000,0);
double s1up_PT_l2=f4->GetX(y2,0,1000);
double s2down_PT_l2=f4->GetX(y1,-1000,0);
double s2up_PT_l2=f4->GetX(y1,0,1000);

double min_PT_l2=f4->GetMinimumX(-10,10);

f_pt_l2->Close();
gr->Clear();

//-----MET-----                   
                       
char path5[100];
sprintf(path5,"likelihoodScan/MET/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_MET = TFile::Open(path5);
gr= (TGraph*) f_MET->Get("Graph;1");
TF1 *f5 = new TF1("f5",myfunc,-1000,1000,0);

double s1down_MET=f5->GetX(y2,-1000,0);
double s1up_MET=f5->GetX(y2,0,1000);
double s2down_MET=f5->GetX(y1,-1000,0);
double s2up_MET=f5->GetX(y1,0,1000);

double min_MET=f5->GetMinimumX(-10,10);

f_MET->Close();
gr->Clear();

//-----PT_j1-----                   
                       
char path6[100];
sprintf(path6,"likelihoodScan/PT_j1/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_pt_j1 = TFile::Open(path6);
gr= (TGraph*) f_pt_j1->Get("Graph;1");
TF1 *f6 = new TF1("f6",myfunc,-1000,1000,0);

double s1down_PT_j1=f6->GetX(y2,-1000,0);
double s1up_PT_j1=f6->GetX(y2,0,1000);
double s2down_PT_j1=f6->GetX(y1,-1000,0);
double s2up_PT_j1=f6->GetX(y1,0,1000);

double min_PT_j1=f6->GetMinimumX(-10,10);

f_pt_j1->Close();
gr->Clear();

//-----Eta_l1-----    

char path7[100];
sprintf(path7,"likelihoodScan/Eta_l1/%s/LS_objects_k_%s.root",argv[1],argv[1]);               
                       
TFile *f_Eta_l1 = TFile::Open(path7);
gr= (TGraph*) f_Eta_l1->Get("Graph;1");
TF1 *f7 = new TF1("f7",myfunc,-1000,1000,0);

double s1down_Eta_l1=f7->GetX(y2,-1000,0);
double s1up_Eta_l1=f7->GetX(y2,0,1000);
double s2down_Eta_l1=f7->GetX(y1,-1000,0);
double s2up_Eta_l1=f7->GetX(y1,0,1000);

double min_Eta_l1=f7->GetMinimumX(-10,10);

f_Eta_l1->Close();
gr->Clear(); 

//-----Eta_l2-----   

char path8[100];
sprintf(path8,"likelihoodScan/Eta_l2/%s/LS_objects_k_%s.root",argv[1],argv[1]);                
                       
TFile *f_Eta_l2 = TFile::Open(path8);
gr= (TGraph*) f_Eta_l2->Get("Graph;1");
TF1 *f8 = new TF1("f8",myfunc,-1000,1000,0);

double s1down_Eta_l2=f8->GetX(y2,-1000,0);
double s1up_Eta_l2=f8->GetX(y2,0,1000);
double s2down_Eta_l2=f8->GetX(y1,-1000,0);
double s2up_Eta_l2=f8->GetX(y1,0,1000);

double min_Eta_l2=f8->GetMinimumX(-10,10);

f_Eta_l2->Close();
gr->Clear();

//-----Eta_j1-----       

char path9[100];
sprintf(path9,"likelihoodScan/Eta_j1/%s/LS_objects_k_%s.root",argv[1],argv[1]);            
                       
TFile *f_Eta_j1 = TFile::Open(path9);
gr= (TGraph*) f_Eta_j1->Get("Graph;1");
TF1 *f9 = new TF1("f9",myfunc,-1000,1000,0);

double s1down_Eta_j1=f9->GetX(y2,-1000,0);
double s1up_Eta_j1=f9->GetX(y2,0,1000);
double s2down_Eta_j1=f9->GetX(y1,-1000,0);
double s2up_Eta_j1=f9->GetX(y1,0,1000);

double min_Eta_j1=f9->GetMinimumX(-10,10);

f_Eta_j1->Close();
gr->Clear();

//-----Eta_j2-----                   
                       
char path10[100];
sprintf(path10,"likelihoodScan/Eta_j2/%s/LS_objects_k_%s.root",argv[1],argv[1]);
                       
TFile *f_Eta_j2 = TFile::Open(path10);
gr= (TGraph*) f_Eta_j2->Get("Graph;1");
TF1 *f10 = new TF1("f10",myfunc,-1000,1000,0);

double s1down_Eta_j2=f10->GetX(y2,-1000,0);
double s1up_Eta_j2=f10->GetX(y2,0,1000);
double s2down_Eta_j2=f10->GetX(y1,-1000,0);
double s2up_Eta_j2=f10->GetX(y1,0,1000);

double min_Eta_j2=f10->GetMinimumX(-10,10);

f_Eta_j2->Close();
gr->Clear();

//-----PT_j2-----                   
                       
char path11[100];
sprintf(path11,"likelihoodScan/PT_j2/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_pt_j2 = TFile::Open(path11);
gr= (TGraph*) f_pt_j2->Get("Graph;1");
TF1 *f11 = new TF1("f11",myfunc,-1000,1000,0);

double s1down_PT_j2=f11->GetX(y2,-1000,0);
double s1up_PT_j2=f11->GetX(y2,0,1000);
double s2down_PT_j2=f11->GetX(y1,-1000,0);
double s2up_PT_j2=f11->GetX(y1,0,1000);


double min_PT_j2=f11->GetMinimumX(-10,10);

f_pt_j2->Close();
gr->Clear();

//-----deltaPhijj-----                   
                       
char path12[100];
sprintf(path12,"likelihoodScan/deltaPhijj/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_deltaPhijj = TFile::Open(path12);
gr= (TGraph*) f_deltaPhijj->Get("Graph;1");
TF1 *f12 = new TF1("f12",myfunc,-1000,1000,0);

double s1down_deltaPhijj=f12->GetX(y2,-1000,0);
double s1up_deltaPhijj=f12->GetX(y2,0,1000);
double s2down_deltaPhijj=f12->GetX(y1,-1000,0);
double s2up_deltaPhijj=f12->GetX(y1,0,1000);


double min_deltaPhijj=f12->GetMinimumX(-10,10);

f_deltaPhijj->Close();
gr->Clear();

//-----M1T-----                   
                       
char path13[100];
sprintf(path13,"likelihoodScan/M1T/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_M1T = TFile::Open(path13);
gr= (TGraph*) f_M1T->Get("Graph;1");
TF1 *f13 = new TF1("f13",myfunc,-1000,1000,0);

double s1down_M1T=f13->GetX(y2,-1000,0);
double s1up_M1T=f13->GetX(y2,0,1000);
double s2down_M1T=f13->GetX(y1,-1000,0);
double s2up_M1T=f13->GetX(y1,0,1000);


double min_M1T=f13->GetMinimumX(-10,10);

f_M1T->Close();
gr->Clear();

//-----Mo1-----                   
                       
char path14[100];
sprintf(path14,"likelihoodScan/Mo1/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_Mo1 = TFile::Open(path14);
gr= (TGraph*) f_Mo1->Get("Graph;1");
TF1 *f14 = new TF1("f14",myfunc,-1000,1000,0);

double s1down_Mo1=f14->GetX(y2,-1000,0);
double s1up_Mo1=f14->GetX(y2,0,1000);
double s2down_Mo1=f14->GetX(y1,-1000,0);
double s2up_Mo1=f14->GetX(y1,0,1000);


double min_Mo1=f14->GetMinimumX(-10,10);

f_Mo1->Close();
gr->Clear();

//-----Zeppenfeld_12-----                   
                       
char path15[100];
sprintf(path15,"likelihoodScan/Zeppenfeld_12/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_Zeppenfeld_12 = TFile::Open(path15);
gr= (TGraph*) f_Zeppenfeld_12->Get("Graph;1");
TF1 *f15 = new TF1("f14",myfunc,-1000,1000,0);

double s1down_Zeppenfeld_12=f15->GetX(y2,-1000,0);
double s1up_Zeppenfeld_12=f15->GetX(y2,0,1000);
double s2down_Zeppenfeld_12=f15->GetX(y1,-1000,0);
double s2up_Zeppenfeld_12=f15->GetX(y1,0,1000);


double min_Zeppenfeld_12=f15->GetMinimumX(-10,10);

f_Zeppenfeld_12->Close();
gr->Clear();

//-----Zeppenfeld_1-----                   
                       
char path16[100];
sprintf(path16,"likelihoodScan/Zeppenfeld_1/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_Zeppenfeld_1 = TFile::Open(path16);
gr= (TGraph*) f_Zeppenfeld_1->Get("Graph;1");
TF1 *f16 = new TF1("f14",myfunc,-1000,1000,0);

double s1down_Zeppenfeld_1=f16->GetX(y2,-1000,0);
double s1up_Zeppenfeld_1=f16->GetX(y2,0,1000);
double s2down_Zeppenfeld_1=f16->GetX(y1,-1000,0);
double s2up_Zeppenfeld_1=f16->GetX(y1,0,1000);


double min_Zeppenfeld_1=f16->GetMinimumX(-10,10);

f_Zeppenfeld_1->Close();
gr->Clear();

//-----Zeppenfeld_2-----                   
                       
char path17[100];
sprintf(path17,"likelihoodScan/Zeppenfeld_2/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_Zeppenfeld_2 = TFile::Open(path17);
gr= (TGraph*) f_Zeppenfeld_2->Get("Graph;1");
TF1 *f17 = new TF1("f17",myfunc,-1000,1000,0);

double s1down_Zeppenfeld_2=f17->GetX(y2,-1000,0);
double s1up_Zeppenfeld_2=f17->GetX(y2,0,1000);
double s2down_Zeppenfeld_2=f17->GetX(y1,-1000,0);
double s2up_Zeppenfeld_2=f17->GetX(y1,0,1000);


double min_Zeppenfeld_2=f17->GetMinimumX(-10,10);

f_Zeppenfeld_2->Close();
gr->Clear();

//-----deltaEtajj-----                   
                       
char path18[100];
sprintf(path18,"likelihoodScan/deltaEtajj/%s/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_deltaEtajj = TFile::Open(path18);
gr= (TGraph*) f_deltaEtajj->Get("Graph;1");
TF1 *f18 = new TF1("f18",myfunc,-1000,1000,0);

double s1down_deltaEtajj=f18->GetX(y2,-1000,0);
double s1up_deltaEtajj=f18->GetX(y2,0,1000);
double s2down_deltaEtajj=f18->GetX(y1,-1000,0);
double s2up_deltaEtajj=f18->GetX(y1,0,1000);


double min_deltaEtajj=f18->GetMinimumX(-10,10);

f_deltaEtajj->Close();
gr->Clear();


//----------------- 	FILLING HISTOGRAMS    --------------------

//----------------------------------------                       
//------------Bin2 = mjj------------------

  Gdown->SetBinContent(2,s1down_mjj); 
  Gup->SetBinContent(2,s1up_mjj);
  Ydown->SetBinContent(2,s2down_mjj);
  Yup->SetBinContent(2,s2up_mjj);
  
//------------Bin5 = mll------------------

  Gdown->SetBinContent(5,s1down_mll); 
  Gup->SetBinContent(5,s1up_mll);
  Ydown->SetBinContent(5,s2down_mll);
  Yup->SetBinContent(5,s2up_mll);

//------------Bin8 = pt_l1------------------

  Gdown->SetBinContent(8,s1down_PT_l1); 
  Gup->SetBinContent(8,s1up_PT_l1);
  Ydown->SetBinContent(8,s2down_PT_l1);
  Yup->SetBinContent(8,s2up_PT_l1);

//------------Bin11 = pt_l2------------------

  Gdown->SetBinContent(11,s1down_PT_l2); 
  Gup->SetBinContent(11,s1up_PT_l2);
  Ydown->SetBinContent(11,s2down_PT_l2);
  Yup->SetBinContent(11,s2up_PT_l2);

//------------Bin14 = pt_j1------------------

  Gdown->SetBinContent(14,s1down_PT_j1); 
  Gup->SetBinContent(14,s1up_PT_j1);
  Ydown->SetBinContent(14,s2down_PT_j1);
  Yup->SetBinContent(14,s2up_PT_j1);
  
//------------Bin17 = pt_j2------------------

  Gdown->SetBinContent(17,s1down_PT_j2); 
  Gup->SetBinContent(17,s1up_PT_j2);
  Ydown->SetBinContent(17,s2down_PT_j2);
  Yup->SetBinContent(17,s2up_PT_j2);

//------------Bin20 = eta_l1------------------

  Gdown->SetBinContent(20,s1down_Eta_l1); 
  Gup->SetBinContent(20,s1up_Eta_l1);
  Ydown->SetBinContent(20,s2down_Eta_l1);
  Yup->SetBinContent(20,s2up_Eta_l1);
  
//------------Bin23 = eta_l2------------------

  Gdown->SetBinContent(23,s1down_Eta_l2); 
  Gup->SetBinContent(23,s1up_Eta_l2);
  Ydown->SetBinContent(23,s2down_Eta_l2);
  Yup->SetBinContent(23,s2up_Eta_l2);

//------------Bin26 = eta_j1------------------

  Gdown->SetBinContent(26,s1down_Eta_j1); 
  Gup->SetBinContent(26,s1up_Eta_j1);
  Ydown->SetBinContent(26,s2down_Eta_j1);
  Yup->SetBinContent(26,s2up_Eta_j1);
  
//------------Bin29 = eta_j2------------------

  Gdown->SetBinContent(29,s1down_Eta_j2); 
  Gup->SetBinContent(29,s1up_Eta_j2);
  Ydown->SetBinContent(29,s2down_Eta_j2);
  Yup->SetBinContent(29,s2up_Eta_j2);
  
//------------Bin32 = met------------------

  Gdown->SetBinContent(32,s1down_MET); 
  Gup->SetBinContent(32,s1up_MET);
  Ydown->SetBinContent(32,s2down_MET);
  Yup->SetBinContent(32,s2up_MET);
  
//------------Bin35 = deltaPhijj------------------

  Gdown->SetBinContent(35,s1down_deltaPhijj); 
  Gup->SetBinContent(35,s1up_deltaPhijj);
  Ydown->SetBinContent(35,s2down_deltaPhijj);
  Yup->SetBinContent(35,s2up_deltaPhijj);
  
//------------Bin38 = m1t------------------

  Gdown->SetBinContent(38,s1down_M1T); 
  Gup->SetBinContent(38,s1up_M1T);
  Ydown->SetBinContent(38,s2down_M1T);
  Yup->SetBinContent(38,s2up_M1T);  
  
//------------Bin41 = mo1------------------

  Gdown->SetBinContent(41,s1down_Mo1); 
  Gup->SetBinContent(41,s1up_Mo1);
  Ydown->SetBinContent(41,s2down_Mo1);
  Yup->SetBinContent(41,s2up_Mo1); 
  
//------------Bin44 = Zeppenfeld_12------------------

  Gdown->SetBinContent(44,s1down_Zeppenfeld_12); 
  Gup->SetBinContent(44,s1up_Zeppenfeld_12);
  Ydown->SetBinContent(44,s2down_Zeppenfeld_12);
  Yup->SetBinContent(44,s2up_Zeppenfeld_12);     

//------------Bin47 = Zeppenfeld_1------------------

  Gdown->SetBinContent(47,s1down_Zeppenfeld_1); 
  Gup->SetBinContent(47,s1up_Zeppenfeld_1);
  Ydown->SetBinContent(47,s2down_Zeppenfeld_1);
  Yup->SetBinContent(47,s2up_Zeppenfeld_1);   
  
//------------Bin50 = Zeppenfeld_2------------------

  Gdown->SetBinContent(50,s1down_Zeppenfeld_2); 
  Gup->SetBinContent(50,s1up_Zeppenfeld_2);
  Ydown->SetBinContent(50,s2down_Zeppenfeld_2);
  Yup->SetBinContent(50,s2up_Zeppenfeld_2);     
  
//------------Bin53 = deltaPhijj------------------

  Gdown->SetBinContent(53,s1down_deltaEtajj); 
  Gup->SetBinContent(53,s1up_deltaEtajj);
  Ydown->SetBinContent(53,s2down_deltaEtajj);
  Yup->SetBinContent(53,s2up_deltaEtajj);  

//----------------- Blue points = likelihood minima ---------------------

Int_t n = 18;
Double_t x[18] = {0.8,1.8,2.8,3.8,4.8,5.8,6.8,7.8,8.8,9.8,10.8,11.8,12.8,13.8,14.8,15.8,16.8,17.8};
Double_t y[18]={min_mjj,min_mll,min_PT_l1,min_PT_l2,min_PT_j1,min_PT_j2,min_Eta_l1,min_Eta_l2,min_Eta_j1,min_Eta_j2,min_MET,min_deltaPhijj,min_M1T,min_Mo1,min_Zeppenfeld_12,min_Zeppenfeld_1,min_Zeppenfeld_2,min_deltaEtajj};

auto g  = new TGraph(n,x,y);
g->SetMarkerColor(kAzure+10);
g->SetMarkerStyle(kFullCircle);

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------
//--------------------------------------- NO UNITARITY ANALYSIS ---------------------------------------------------            
              
                   
//-----mjj-----                   

char npath1[100];                    // location of combine output 
sprintf(npath1,"likelihoodScan/mjj/%s/LS_objects_k_%s.root",argv[2],argv[2]);
                       
TFile *nf_mjj = TFile::Open(npath1);
gr= (TGraph*) nf_mjj->Get("Graph;1");
TF1 *nf1 = new TF1("nf1",myfunc,-1000,1000,0);

double ns1down_mjj=nf1->GetX(y2,-1000,0);
double ns1up_mjj=nf1->GetX(y2,0,1000);
double ns2down_mjj=nf1->GetX(y1,-1000,0);
double ns2up_mjj=nf1->GetX(y1,0,1000);

double nmin_mjj=nf1->GetMinimumX(-10,10);

nf_mjj->Close();                 
gr->Clear();
               
//-----mll-----                   
                       
char npath2[100];
sprintf(npath2,"likelihoodScan/mll/%s/LS_objects_k_%s.root",argv[2],argv[2]);
                       
TFile *nf_mll = TFile::Open(npath2);
gr= (TGraph*) nf_mll->Get("Graph;1");
TF1 *nf2 = new TF1("nf2",myfunc,-1000,1000,0);

double ns1down_mll=nf2->GetX(y2,-1000,0);
double ns1up_mll=nf2->GetX(y2,0,1000);
double ns2down_mll=nf2->GetX(y1,-1000,0);
double ns2up_mll=nf2->GetX(y1,0,1000);

double nmin_mll=nf2->GetMinimumX(-10,10);

nf_mll->Close();
gr->Clear();          

//-----PT_l1-----    

char npath3[100];
sprintf(npath3,"likelihoodScan/PT_l1/%s/LS_objects_k_%s.root",argv[2],argv[2]);               
                       
TFile *nf_pt_l1 = TFile::Open(npath3);
gr= (TGraph*) nf_pt_l1->Get("Graph;1");
TF1 *nf3 = new TF1("nf3",myfunc,-1000,1000,0);

double ns1down_PT_l1=nf3->GetX(y2,-1000,0);
double ns1up_PT_l1=nf3->GetX(y2,0,1000);
double ns2down_PT_l1=nf3->GetX(y1,-1000,0);
double ns2up_PT_l1=nf3->GetX(y1,0,1000);

double nmin_PT_l1=nf3->GetMinimumX(-10,10);

nf_pt_l1->Close();
gr->Clear();   

//-----PT_l2-----         

char npath4[100];
sprintf(npath4,"likelihoodScan/PT_l2/%s/LS_objects_k_%s.root",argv[2],argv[2]);          
                       
TFile *nf_pt_l2 = TFile::Open(npath4);
gr= (TGraph*) nf_pt_l2->Get("Graph;1");
TF1 *nf4 = new TF1("nf4",myfunc,-1000,1000,0);

double ns1down_PT_l2=nf4->GetX(y2,-1000,0);
double ns1up_PT_l2=nf4->GetX(y2,0,1000);
double ns2down_PT_l2=nf4->GetX(y1,-1000,0);
double ns2up_PT_l2=nf4->GetX(y1,0,1000);

double nmin_PT_l2=nf4->GetMinimumX(-10,10);

nf_pt_l2->Close();
gr->Clear();

//-----MET-----                   
                       
char npath5[100];
sprintf(npath5,"likelihoodScan/MET/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_MET = TFile::Open(npath5);
gr= (TGraph*) nf_MET->Get("Graph;1");
TF1 *nf5 = new TF1("nf5",myfunc,-1000,1000,0);

double ns1down_MET=nf5->GetX(y2,-1000,0);
double ns1up_MET=nf5->GetX(y2,0,1000);
double ns2down_MET=nf5->GetX(y1,-1000,0);
double ns2up_MET=nf5->GetX(y1,0,1000);

double nmin_MET=nf5->GetMinimumX(-10,10);

nf_MET->Close();
gr->Clear();

//-----PT_j1-----                   
                       
char npath6[100];
sprintf(npath6,"likelihoodScan/PT_j1/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_pt_j1 = TFile::Open(npath6);
gr= (TGraph*) nf_pt_j1->Get("Graph;1");
TF1 *nf6 = new TF1("nf6",myfunc,-1000,1000,0);

double ns1down_PT_j1=nf6->GetX(y2,-1000,0);
double ns1up_PT_j1=nf6->GetX(y2,0,1000);
double ns2down_PT_j1=nf6->GetX(y1,-1000,0);
double ns2up_PT_j1=nf6->GetX(y1,0,1000);

double nmin_PT_j1=nf6->GetMinimumX(-10,10);

nf_pt_j1->Close();
gr->Clear();

//-----Eta_l1-----    

char npath7[100];
sprintf(npath7,"likelihoodScan/Eta_l1/%s/LS_objects_k_%s.root",argv[2],argv[2]);               
                       
TFile *nf_Eta_l1 = TFile::Open(npath7);
gr= (TGraph*) nf_Eta_l1->Get("Graph;1");
TF1 *nf7 = new TF1("nf7",myfunc,-1000,1000,0);

double ns1down_Eta_l1=nf7->GetX(y2,-1000,0);
double ns1up_Eta_l1=nf7->GetX(y2,0,1000);
double ns2down_Eta_l1=nf7->GetX(y1,-1000,0);
double ns2up_Eta_l1=nf7->GetX(y1,0,1000);

double nmin_Eta_l1=nf7->GetMinimumX(-10,10);

nf_Eta_l1->Close();
gr->Clear(); 

//-----Eta_l2-----   

char npath8[100];
sprintf(npath8,"likelihoodScan/Eta_l2/%s/LS_objects_k_%s.root",argv[2],argv[2]);                
                       
TFile *nf_Eta_l2 = TFile::Open(npath8);
gr= (TGraph*) nf_Eta_l2->Get("Graph;1");
TF1 *nf8 = new TF1("nf8",myfunc,-1000,1000,0);

double ns1down_Eta_l2=nf8->GetX(y2,-1000,0);
double ns1up_Eta_l2=nf8->GetX(y2,0,1000);
double ns2down_Eta_l2=nf8->GetX(y1,-1000,0);
double ns2up_Eta_l2=nf8->GetX(y1,0,1000);

double nmin_Eta_l2=nf8->GetMinimumX(-10,10);

nf_Eta_l2->Close();
gr->Clear();

//-----Eta_j1-----       

char npath9[100];
sprintf(npath9,"likelihoodScan/Eta_j1/%s/LS_objects_k_%s.root",argv[2],argv[2]);            
                       
TFile *nf_Eta_j1 = TFile::Open(npath9);
gr= (TGraph*) nf_Eta_j1->Get("Graph;1");
TF1 *nf9 = new TF1("nf9",myfunc,-1000,1000,0);

double ns1down_Eta_j1=nf9->GetX(y2,-1000,0);
double ns1up_Eta_j1=nf9->GetX(y2,0,1000);
double ns2down_Eta_j1=nf9->GetX(y1,-1000,0);
double ns2up_Eta_j1=nf9->GetX(y1,0,1000);

double nmin_Eta_j1=nf9->GetMinimumX(-10,10);

nf_Eta_j1->Close();
gr->Clear();

//-----Eta_j2-----                   
                       
char npath10[100];
sprintf(npath10,"likelihoodScan/Eta_j2/%s/LS_objects_k_%s.root",argv[2],argv[2]);
                       
TFile *nf_Eta_j2 = TFile::Open(npath10);
gr= (TGraph*) nf_Eta_j2->Get("Graph;1");
TF1 *nf10 = new TF1("nf10",myfunc,-1000,1000,0);

double ns1down_Eta_j2=nf10->GetX(y2,-1000,0);
double ns1up_Eta_j2=nf10->GetX(y2,0,1000);
double ns2down_Eta_j2=nf10->GetX(y1,-1000,0);
double ns2up_Eta_j2=nf10->GetX(y1,0,1000);

double nmin_Eta_j2=nf10->GetMinimumX(-10,10);

nf_Eta_j2->Close();
gr->Clear();

//-----PT_j2-----                   
                       
char npath11[100];
sprintf(npath11,"likelihoodScan/PT_j2/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_pt_j2 = TFile::Open(npath11);
gr= (TGraph*) nf_pt_j2->Get("Graph;1");
TF1 *nf11 = new TF1("nf11",myfunc,-1000,1000,0);

double ns1down_PT_j2=nf11->GetX(y2,-1000,0);
double ns1up_PT_j2=nf11->GetX(y2,0,1000);
double ns2down_PT_j2=nf11->GetX(y1,-1000,0);
double ns2up_PT_j2=nf11->GetX(y1,0,1000);


double nmin_PT_j2=nf11->GetMinimumX(-10,10);

nf_pt_j2->Close();
gr->Clear();

//-----deltaPhijj-----                   
                       
char npath12[100];
sprintf(npath12,"likelihoodScan/deltaPhijj/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_deltaPhijj = TFile::Open(npath12);
gr= (TGraph*) nf_deltaPhijj->Get("Graph;1");
TF1 *nf12 = new TF1("nf12",myfunc,-1000,1000,0);

double ns1down_deltaPhijj=nf12->GetX(y2,-1000,0);
double ns1up_deltaPhijj=nf12->GetX(y2,0,1000);
double ns2down_deltaPhijj=nf12->GetX(y1,-1000,0);
double ns2up_deltaPhijj=nf12->GetX(y1,0,1000);


double nmin_deltaPhijj=nf12->GetMinimumX(-10,10);

nf_deltaPhijj->Close();
gr->Clear();

//-----M1T-----                   
                       
char npath13[100];
sprintf(npath13,"likelihoodScan/M1T/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_M1T = TFile::Open(npath13);
gr= (TGraph*) nf_M1T->Get("Graph;1");
TF1 *nf13 = new TF1("nf13",myfunc,-1000,1000,0);

double ns1down_M1T=nf13->GetX(y2,-1000,0);
double ns1up_M1T=nf13->GetX(y2,0,1000);
double ns2down_M1T=nf13->GetX(y1,-1000,0);
double ns2up_M1T=nf13->GetX(y1,0,1000);


double nmin_M1T=nf13->GetMinimumX(-10,10);

nf_M1T->Close();
gr->Clear();

//-----Mo1-----                   
                       
char npath14[100];
sprintf(npath14,"likelihoodScan/Mo1/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_Mo1 = TFile::Open(npath14);
gr= (TGraph*) nf_Mo1->Get("Graph;1");
TF1 *nf14 = new TF1("nf14",myfunc,-1000,1000,0);

double ns1down_Mo1=nf14->GetX(y2,-1000,0);
double ns1up_Mo1=nf14->GetX(y2,0,1000);
double ns2down_Mo1=nf14->GetX(y1,-1000,0);
double ns2up_Mo1=nf14->GetX(y1,0,1000);


double nmin_Mo1=nf14->GetMinimumX(-10,10);

nf_Mo1->Close();
gr->Clear();

//-----Zeppenfeld_12-----                   
                       
char npath15[100];
sprintf(npath15,"likelihoodScan/Zeppenfeld_12/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_Zeppenfeld_12 = TFile::Open(npath15);
gr= (TGraph*) nf_Zeppenfeld_12->Get("Graph;1");
TF1 *nf15 = new TF1("nf14",myfunc,-1000,1000,0);

double ns1down_Zeppenfeld_12=nf15->GetX(y2,-1000,0);
double ns1up_Zeppenfeld_12=nf15->GetX(y2,0,1000);
double ns2down_Zeppenfeld_12=nf15->GetX(y1,-1000,0);
double ns2up_Zeppenfeld_12=nf15->GetX(y1,0,1000);


double nmin_Zeppenfeld_12=nf15->GetMinimumX(-10,10);

nf_Zeppenfeld_12->Close();
gr->Clear();

//-----Zeppenfeld_1-----                   
                       
char npath16[100];
sprintf(npath16,"likelihoodScan/Zeppenfeld_1/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_Zeppenfeld_1 = TFile::Open(npath16);
gr= (TGraph*) nf_Zeppenfeld_1->Get("Graph;1");
TF1 *nf16 = new TF1("nf16",myfunc,-1000,1000,0);

double ns1down_Zeppenfeld_1=nf16->GetX(y2,-1000,0);
double ns1up_Zeppenfeld_1=nf16->GetX(y2,0,1000);
double ns2down_Zeppenfeld_1=nf16->GetX(y1,-1000,0);
double ns2up_Zeppenfeld_1=nf16->GetX(y1,0,1000);


double nmin_Zeppenfeld_1=nf16->GetMinimumX(-10,10);

nf_Zeppenfeld_1->Close();
gr->Clear();

//-----Zeppenfeld_2-----                   
                       
char npath17[100];
sprintf(npath17,"likelihoodScan/Zeppenfeld_2/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_Zeppenfeld_2 = TFile::Open(npath17);
gr= (TGraph*) nf_Zeppenfeld_2->Get("Graph;1");
TF1 *nf17 = new TF1("nf17",myfunc,-1000,1000,0);

double ns1down_Zeppenfeld_2=nf17->GetX(y2,-1000,0);
double ns1up_Zeppenfeld_2=nf17->GetX(y2,0,1000);
double ns2down_Zeppenfeld_2=nf17->GetX(y1,-1000,0);
double ns2up_Zeppenfeld_2=nf17->GetX(y1,0,1000);


double nmin_Zeppenfeld_2=nf17->GetMinimumX(-10,10);

nf_Zeppenfeld_2->Close();
gr->Clear();

//-----deltaEtajj-----                   
                       
char npath18[100];
sprintf(npath18,"likelihoodScan/deltaEtajj/%s/LS_objects_k_%s.root",argv[2],argv[2]);                       
                       
TFile *nf_deltaEtajj = TFile::Open(npath18);
gr= (TGraph*) nf_deltaEtajj->Get("Graph;1");
TF1 *nf18 = new TF1("nf18",myfunc,-1000,1000,0);

double ns1down_deltaEtajj=nf18->GetX(y2,-1000,0);
double ns1up_deltaEtajj=nf18->GetX(y2,0,1000);
double ns2down_deltaEtajj=nf18->GetX(y1,-1000,0);
double ns2up_deltaEtajj=nf18->GetX(y1,0,1000);


double nmin_deltaEtajj=nf18->GetMinimumX(-10,10);

nf_deltaEtajj->Close();
gr->Clear();


//----------------- 	FILLING HISTOGRAMS    --------------------

//----------------------------------------                       
//------------Bin3 = mjj------------------

  nGdown->SetBinContent(3,ns1down_mjj); 
  nGup->SetBinContent(3,ns1up_mjj);
  nYdown->SetBinContent(3,ns2down_mjj);
  nYup->SetBinContent(3,ns2up_mjj);
  
//------------Bin6 = mll------------------

  nGdown->SetBinContent(6,ns1down_mll); 
  nGup->SetBinContent(6,ns1up_mll);
  nYdown->SetBinContent(6,ns2down_mll);
  nYup->SetBinContent(6,ns2up_mll);

//------------Bin9 = pt_l1------------------

  nGdown->SetBinContent(9,ns1down_PT_l1); 
  nGup->SetBinContent(9,ns1up_PT_l1);
  nYdown->SetBinContent(9,ns2down_PT_l1);
  nYup->SetBinContent(9,ns2up_PT_l1);

//------------Bin12 = pt_l2------------------

  nGdown->SetBinContent(12,ns1down_PT_l2); 
  nGup->SetBinContent(12,ns1up_PT_l2);
  nYdown->SetBinContent(12,ns2down_PT_l2);
  nYup->SetBinContent(12,ns2up_PT_l2);

//------------Bin15 = pt_j1------------------

  nGdown->SetBinContent(15,ns1down_PT_j1); 
  nGup->SetBinContent(15,ns1up_PT_j1);
  nYdown->SetBinContent(15,ns2down_PT_j1);
  nYup->SetBinContent(15,ns2up_PT_j1);
  
//------------Bin18 = pt_j2------------------

  nGdown->SetBinContent(18,ns1down_PT_j2); 
  nGup->SetBinContent(18,ns1up_PT_j2);
  nYdown->SetBinContent(18,ns2down_PT_j2);
  nYup->SetBinContent(18,ns2up_PT_j2);

//------------Bin21 = eta_l1------------------

  nGdown->SetBinContent(21,ns1down_Eta_l1); 
  nGup->SetBinContent(21,ns1up_Eta_l1);
  nYdown->SetBinContent(21,ns2down_Eta_l1);
  nYup->SetBinContent(21,ns2up_Eta_l1);
  
//------------Bin24 = eta_l2------------------

  nGdown->SetBinContent(24,ns1down_Eta_l2); 
  nGup->SetBinContent(24,ns1up_Eta_l2);
  nYdown->SetBinContent(24,ns2down_Eta_l2);
  nYup->SetBinContent(24,ns2up_Eta_l2);

//------------Bin27 = eta_j1------------------

  nGdown->SetBinContent(27,ns1down_Eta_j1); 
  nGup->SetBinContent(27,ns1up_Eta_j1);
  nYdown->SetBinContent(27,ns2down_Eta_j1);
  nYup->SetBinContent(27,ns2up_Eta_j1);
  
//------------Bin30 = eta_j2------------------

  nGdown->SetBinContent(30,ns1down_Eta_j2); 
  nGup->SetBinContent(30,ns1up_Eta_j2);
  nYdown->SetBinContent(30,ns2down_Eta_j2);
  nYup->SetBinContent(30,ns2up_Eta_j2);
  
//------------Bin33 = met------------------

  nGdown->SetBinContent(33,ns1down_MET); 
  nGup->SetBinContent(33,ns1up_MET);
  nYdown->SetBinContent(33,ns2down_MET);
  nYup->SetBinContent(33,ns2up_MET);
  
//------------Bin36 = deltaPhijj------------------

  nGdown->SetBinContent(36,ns1down_deltaPhijj); 
  nGup->SetBinContent(36,ns1up_deltaPhijj);
  nYdown->SetBinContent(36,ns2down_deltaPhijj);
  nYup->SetBinContent(36,ns2up_deltaPhijj);
  
//------------Bin39 = m1t------------------

  nGdown->SetBinContent(39,ns1down_M1T); 
  nGup->SetBinContent(39,ns1up_M1T);
  nYdown->SetBinContent(39,ns2down_M1T);
  nYup->SetBinContent(39,ns2up_M1T);  
  
//------------Bin42 = mo1------------------

  nGdown->SetBinContent(42,ns1down_Mo1); 
  nGup->SetBinContent(42,ns1up_Mo1);
  nYdown->SetBinContent(42,ns2down_Mo1);
  nYup->SetBinContent(42,ns2up_Mo1); 
  
//------------Bin45 = Zeppenfeld_12------------------

  nGdown->SetBinContent(45,ns1down_Zeppenfeld_12); 
  nGup->SetBinContent(45,ns1up_Zeppenfeld_12);
  nYdown->SetBinContent(45,ns2down_Zeppenfeld_12);
  nYup->SetBinContent(45,ns2up_Zeppenfeld_12);     

//------------Bin48 = Zeppenfeld_1------------------

  nGdown->SetBinContent(48,ns1down_Zeppenfeld_1); 
  nGup->SetBinContent(48,ns1up_Zeppenfeld_1);
  nYdown->SetBinContent(48,ns2down_Zeppenfeld_1);
  nYup->SetBinContent(48,ns2up_Zeppenfeld_1);   
  
//------------Bin51 = Zeppenfeld_2------------------

  nGdown->SetBinContent(51,ns1down_Zeppenfeld_2); 
  nGup->SetBinContent(51,ns1up_Zeppenfeld_2);
  nYdown->SetBinContent(51,ns2down_Zeppenfeld_2);
  nYup->SetBinContent(51,ns2up_Zeppenfeld_2);     
  
//------------Bin54 = deltaPhijj------------------

  nGdown->SetBinContent(54,ns1down_deltaEtajj); 
  nGup->SetBinContent(54,ns1up_deltaEtajj);
  nYdown->SetBinContent(54,ns2down_deltaEtajj);
  nYup->SetBinContent(54,ns2up_deltaEtajj);  

//----------------- Red points = likelihood minima ---------------------

Int_t n0 = 18;
Double_t x0[18] = {1.2,2.2,3.2,4.2,5.2,6.2,7.2,8.2,9.2,10.2,11.2,12.2,13.2,14.2,15.2,16.2,17.2,18.2};
Double_t y0[18]={nmin_mjj,nmin_mll,nmin_PT_l1,nmin_PT_l2,nmin_PT_j1,nmin_PT_j2,nmin_Eta_l1,nmin_Eta_l2,nmin_Eta_j1,nmin_Eta_j2,nmin_MET,nmin_deltaPhijj,nmin_M1T,nmin_Mo1,nmin_Zeppenfeld_12,nmin_Zeppenfeld_1,nmin_Zeppenfeld_2,nmin_deltaEtajj};

auto g0  = new TGraph(n0,x0,y0);
g0->SetMarkerColor(kRed-10);
g0->SetMarkerStyle(kFullCircle);

//---------------------------------------------


char eftop[10];              
sprintf(eftop,"%s",argv[1]);

char plotname[30];
sprintf(plotname,"CIplots/Compare_%s.png",argv[1]);        // name of .png file in output


//---------------------------------------------

TCanvas* c1 = new TCanvas("c1","c1",0,0,800,650);
TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.99);
c1_1->Draw();
c1_1->cd();
c1_1->SetTopMargin(0.1);
c1_1->SetBottomMargin(0.15);
c1_1->SetRightMargin(0.045);
c1_1->SetLeftMargin(0.15);

double a; // extreme values of worst confidence interval (2sigma CL) -> to set the range of Y axis (from code "intervals.cpp")
double b;  

//---------- all final states --------------

if(strcmp(argv[1],"cW")==0){
                          // a=-38;
                          // b=23;
                          a=-0.5;
                          b=0.5;
                           }
else if(strcmp(argv[1],"cHW")==0){
                           a=-1.4;
                           b=1.5;
                           }
else if(strcmp(argv[1],"cHWB")==0){
                           a=-8;
                           b=13.8;
                           }
else if(strcmp(argv[1],"cHDD")==0){
                           a=-10;
                           b=45;
                           }
else if(strcmp(argv[1],"cHbox")==0){
                           a=-5.8;
                           b=7.1;
                           }
else if(strcmp(argv[1],"cWtil")==0){
                           a=-0.5;
                           b=0.5;
                           }
else if(strcmp(argv[1],"cHWtil")==0){
                           a=-4.8;
                           b=4.8;
                           }
else if(strcmp(argv[1],"cHWBtil")==0){
                           a=-116;
                           b=116;
                           }
else if(strcmp(argv[1],"cHq1")==0)
    { 
    a=-2.7;
    b=2.5;
    }
else if(strcmp(argv[1],"cHq3")==0)
    { 
    a=-0.35;
    b=0.3;
    }
else if(strcmp(argv[1],"cHl1")==0)
    { 
    a=-255;
    b=180;
    }
else if(strcmp(argv[1],"cHl3")==0)
    { 
    a=-0.23;
    b=0.23;
    }
    else if(strcmp(argv[1],"cqq1")==0)
    { 
    a=-0.18;
    b=0.24;
    }
   else if(strcmp(argv[1],"cqq3")==0)
    { 
    a=-0.07;
    b=0.19;
    }
/*     else if(strcmp(argv[1],"cqq11")==0)
    { 
    a=;
    b=;
    }
    else if(strcmp(argv[1],"cqq31")==0)
    { 
    a=;
    b=;
    }
    else if(strcmp(argv[1],"cll")==0)
    { 
    a=;
    b=;
    }*/
    else if(strcmp(argv[1],"cll1")==0)
    { 
    a=-0.31;
    b=0.31;
    }  

//--------------

Yup->GetYaxis()->SetRangeUser(a,b);

Yup->Draw();
Gup->Draw("SAME");
Ydown->Draw("SAME");
Gdown->Draw("SAME");
g->Draw("P");

nYup->Draw("SAME");
nGup->Draw("SAME");
nYdown->Draw("SAME");
nGdown->Draw("SAME");
g0->Draw("P");

Yup->GetXaxis()->SetNdivisions(0, kTRUE);

Yup->GetYaxis()->SetTitleOffset(1.4);
Yup->GetYaxis()->SetTitle("Confidence Interval");
Yup->GetYaxis()->SetLabelSize(0.045);
Yup->GetYaxis()->SetTitleSize(0.05);

TLatex latexLabel;
latexLabel.SetTextSize(0.04);
latexLabel.SetNDC();
latexLabel.DrawLatex(0.16, 0.93, "CMS   L=100 fb^{-1}");

TLatex latexLabel2;
latexLabel2.SetNDC();
latexLabel2.SetTextSize(0.04);
latexLabel2.DrawLatex(0.85, 0.93, "13 TeV");

TLatex latexLabel3;
latexLabel3.SetTextSize(0.05);
latexLabel3.SetNDC();
latexLabel3.DrawLatex(0.16, 0.02, eftop);

TLatex latexLabel0;
latexLabel0.SetTextSize(0.05);
latexLabel0.SetTextColor(kRed);
latexLabel0.SetNDC();
latexLabel0.DrawLatex(0.75, 0.02, "#sqrt{#hat{s}} < 5.4 TeV");

//-----------------------------------------------

/*
TLatex latexLabelI;
latexLabelI.SetNDC();
latexLabelI.SetTextSize(0.025);
latexLabelI.DrawLatex(0.20, 0.11, "mjj   mll  pt_l1 pt_l2 pt_j1    pt_j2   #eta_l1    #eta_l2    #eta_j1   #eta_j2     met   #Delta#phi_jj   ");
*/

TLatex latexLabelI;  
latexLabelI.SetNDC(); 
latexLabelI.SetTextSize(0.03);
latexLabelI.SetTextAngle(45);
latexLabelI.DrawLatex(0.185, 0.09, "m_{jj}");

TLatex latexLabelII;  
latexLabelII.SetNDC(); 
latexLabelII.SetTextSize(0.03);
latexLabelII.SetTextAngle(45);
latexLabelII.DrawLatex(0.23, 0.09, "m_{ll}");

TLatex latexLabelIII;  
latexLabelIII.SetNDC(); 
latexLabelIII.SetTextSize(0.03);
latexLabelIII.SetTextAngle(45);
latexLabelIII.DrawLatex(0.27, 0.09, "pt_{l1}");

TLatex latexLabelIV;  
latexLabelIV.SetNDC(); 
latexLabelIV.SetTextSize(0.03);
latexLabelIV.SetTextAngle(45);
latexLabelIV.DrawLatex(0.31, 0.09, "pt_{l2}");

TLatex latexLabelV;  
latexLabelV.SetNDC(); 
latexLabelV.SetTextSize(0.03);
latexLabelV.SetTextAngle(45);
latexLabelV.DrawLatex(0.355, 0.09, "pt_{j1}");

TLatex latexLabelVI;  
latexLabelVI.SetNDC(); 
latexLabelVI.SetTextSize(0.03);
latexLabelVI.SetTextAngle(45);
latexLabelVI.DrawLatex(0.395, 0.09, "pt_{j2}");

TLatex latexLabelVII;  
latexLabelVII.SetNDC(); 
latexLabelVII.SetTextSize(0.03);
latexLabelVII.SetTextAngle(45);
latexLabelVII.DrawLatex(0.44, 0.09, "#eta_{l1}");

TLatex latexLabelVIII;  
latexLabelVIII.SetNDC(); 
latexLabelVIII.SetTextSize(0.03);
latexLabelVIII.SetTextAngle(45);
latexLabelVIII.DrawLatex(0.485, 0.09, "#eta_{l2}");

TLatex latexLabelIX;  
latexLabelIX.SetNDC(); 
latexLabelIX.SetTextSize(0.03);
latexLabelIX.SetTextAngle(45);
latexLabelIX.DrawLatex(0.53, 0.09, "#eta_{j1}");

TLatex latexLabelX;  
latexLabelX.SetNDC(); 
latexLabelX.SetTextSize(0.03);
latexLabelX.SetTextAngle(45);
latexLabelX.DrawLatex(0.57, 0.09, "#eta_{j2}");

TLatex latexLabelXI;  
latexLabelXI.SetNDC(); 
latexLabelXI.SetTextSize(0.03);
latexLabelXI.SetTextAngle(45);
latexLabelXI.DrawLatex(0.615, 0.09, "met");

TLatex latexLabelXII;  
latexLabelXII.SetNDC(); 
latexLabelXII.SetTextSize(0.03);
latexLabelXII.SetTextAngle(45);
latexLabelXII.DrawLatex(0.655, 0.09, "#Delta#phi_{jj}");

TLatex latexLabelXIII;  
latexLabelXIII.SetNDC(); 
latexLabelXIII.SetTextSize(0.03);
latexLabelXIII.SetTextAngle(45);
latexLabelXIII.DrawLatex(0.70, 0.09, "m1t");

TLatex latexLabelXIV;  
latexLabelXIV.SetNDC(); 
latexLabelXIV.SetTextSize(0.03);
latexLabelXIV.SetTextAngle(45);
latexLabelXIV.DrawLatex(0.735, 0.09, "mo1");

TLatex latexLabelXV;  
latexLabelXV.SetNDC(); 
latexLabelXV.SetTextSize(0.03);
latexLabelXV.SetTextAngle(45);
latexLabelXV.DrawLatex(0.785, 0.09, "Z_{12}");

TLatex latexLabelXVI;  
latexLabelXVI.SetNDC(); 
latexLabelXVI.SetTextSize(0.03);
latexLabelXVI.SetTextAngle(45);
latexLabelXVI.DrawLatex(0.83, 0.09, "Z_{1}");

TLatex latexLabelXVII;  
latexLabelXVII.SetNDC(); 
latexLabelXVII.SetTextSize(0.03);
latexLabelXVII.SetTextAngle(45);
latexLabelXVII.DrawLatex(0.87, 0.09, "Z_{2}");

TLatex latexLabelXVIII;  
latexLabelXVIII.SetNDC(); 
latexLabelXVIII.SetTextSize(0.03);
latexLabelXVIII.SetTextAngle(45);
latexLabelXVIII.DrawLatex(0.905, 0.09, "#Delta#eta_{jj}");



//-----------------------------------------------

TLegend *leg = new TLegend(0.39, 0.89, 0.85, 0.99);
leg->SetShadowColor(1);
leg->SetBorderSize(1);
leg->SetTextSize(0.025);
leg->SetFillColor(0);
leg->SetNColumns(2);
leg->AddEntry(g, "Best fit (unit)", "p");
leg->AddEntry(g0, "Best fit", "p");
leg->AddEntry(Gup, "#pm1#sigma expected (unit)", "f");
leg->AddEntry(nGup, "#pm1#sigma expected", "f");
leg->AddEntry(Yup, "#pm2#sigma expected (unit)", "f");
leg->AddEntry(nYup, "#pm2#sigma expected", "f"); 
leg->Draw();

c1->SaveAs(plotname);

int i=0;
return i;
}
