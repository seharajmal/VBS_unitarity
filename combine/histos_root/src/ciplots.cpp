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
 
TGraph *gr;
double myfunc(Double_t *x, Double_t *) { return gr->Eval(x[0]);}
 
int main(int argc, char*argv[]){
 
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
 
  const int NBINS=21;
  double_t edges[NBINS + 1] = {0.0,0.9,1.1,1.9,2.1,2.9,3.1,3.9,4.1,4.9,5.1,5.9,6.1,6.9,7.1,7.9,8.1,8.9,9.1,9.9,10.1,11};
  TH1F *Yup=new TH1F("yellow_up","",NBINS,edges);
  TH1F *Gup=new TH1F("green_up","",NBINS,edges);
  TH1F *Ydown=new TH1F("yellow_down","",NBINS,edges);
  TH1F *Gdown=new TH1F("green_down","",NBINS,edges);
  
Yup->SetLineColor(kYellow);
Yup->SetFillStyle(1001);
Yup->SetFillColor(kYellow);

Ydown->SetLineColor(kYellow);
Ydown->SetFillStyle(1001);
Ydown->SetFillColor(kYellow);

Gup->SetLineColor(kGreen);
Gup->SetFillStyle(1001);
Gup->SetFillColor(kGreen);

Gdown->SetLineColor(kGreen);
Gdown->SetFillStyle(1001);
Gdown->SetFillColor(kGreen);

//----------------------------CALCULATION OF CONFIDENCE INTERVALS AND MINIMUM FOR EACH VARIABLE-------------------------------------                      
            
double y1=3.84, y2=1.0;                
                   
//-----mjj-----                   

char path1[100];
sprintf(path1,"likelihoodScan/%s/mjj/LS_objects_k_%s.root",argv[1],argv[1]);
                       
TFile *f_mjj = TFile::Open(path1);
gr= (TGraph*) f_mjj->Get("Graph;1");
TF1 *f1 = new TF1("f1",myfunc,-100,100,0);

double s1down_mjj=f1->GetX(y2,-100,0);
double s1up_mjj=f1->GetX(y2,0,100);
double s2down_mjj=f1->GetX(y1,-100,0);
double s2up_mjj=f1->GetX(y1,0,100);

double min_mjj=f1->GetMinimumX(-10,10);

f_mjj->Close();                 
gr->Clear();
               
//-----mll-----                   
                       
char path2[100];
sprintf(path2,"likelihoodScan/%s/mll/LS_objects_k_%s.root",argv[1],argv[1]);
                       
TFile *f_mll = TFile::Open(path2);
gr= (TGraph*) f_mll->Get("Graph;1");
TF1 *f2 = new TF1("f2",myfunc,-100,100,0);

double s1down_mll=f2->GetX(y2,-100,0);
double s1up_mll=f2->GetX(y2,0,100);
double s2down_mll=f2->GetX(y1,-100,0);
double s2up_mll=f2->GetX(y1,0,100);

double min_mll=f2->GetMinimumX(-10,10);

f_mll->Close();
gr->Clear();          

//-----PT_el-----    

char path3[100];
sprintf(path3,"likelihoodScan/%s/PT_el/LS_objects_k_%s.root",argv[1],argv[1]);               
                       
TFile *f_pt_el = TFile::Open(path3);
gr= (TGraph*) f_pt_el->Get("Graph;1");
TF1 *f3 = new TF1("f3",myfunc,-100,100,0);

double s1down_PT_el=f3->GetX(y2,-100,0);
double s1up_PT_el=f3->GetX(y2,0,100);
double s2down_PT_el=f3->GetX(y1,-100,0);
double s2up_PT_el=f3->GetX(y1,0,100);

double min_PT_el=f3->GetMinimumX(-10,10);

f_pt_el->Close();
gr->Clear();   

//-----PT_mu-----         

char path4[100];
sprintf(path4,"likelihoodScan/%s/PT_mu/LS_objects_k_%s.root",argv[1],argv[1]);          
                       
TFile *f_pt_mu = TFile::Open(path4);
gr= (TGraph*) f_pt_mu->Get("Graph;1");
TF1 *f4 = new TF1("f4",myfunc,-100,100,0);

double s1down_PT_mu=f4->GetX(y2,-100,0);
double s1up_PT_mu=f4->GetX(y2,0,100);
double s2down_PT_mu=f4->GetX(y1,-100,0);
double s2up_PT_mu=f4->GetX(y1,0,100);

double min_PT_mu=f4->GetMinimumX(-10,10);

f_pt_mu->Close();
gr->Clear();

//-----PT_ta-----                   
                       
char path5[100];
sprintf(path5,"likelihoodScan/%s/PT_ta/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_pt_ta = TFile::Open(path5);
gr= (TGraph*) f_pt_ta->Get("Graph;1");
TF1 *f5 = new TF1("f5",myfunc,-100,100,0);

double s1down_PT_ta=f5->GetX(y2,-100,0);
double s1up_PT_ta=f5->GetX(y2,0,100);
double s2down_PT_ta=f5->GetX(y1,-100,0);
double s2up_PT_ta=f5->GetX(y1,0,100);

double min_PT_ta=f5->GetMinimumX(-10,10);

f_pt_ta->Close();
gr->Clear();

//-----PT_j-----                   
                       
char path6[100];
sprintf(path6,"likelihoodScan/%s/PT_j/LS_objects_k_%s.root",argv[1],argv[1]);                       
                       
TFile *f_pt_j = TFile::Open(path6);
gr= (TGraph*) f_pt_j->Get("Graph;1");
TF1 *f6 = new TF1("f6",myfunc,-100,100,0);

double s1down_PT_j=f6->GetX(y2,-100,0);
double s1up_PT_j=f6->GetX(y2,0,100);
double s2down_PT_j=f6->GetX(y1,-100,0);
double s2up_PT_j=f6->GetX(y1,0,100);

double min_PT_j=f6->GetMinimumX(-10,10);

f_pt_j->Close();
gr->Clear();

//-----Eta_el-----    

char path7[100];
sprintf(path7,"likelihoodScan/%s/Eta_el/LS_objects_k_%s.root",argv[1],argv[1]);               
                       
TFile *f_Eta_el = TFile::Open(path7);
gr= (TGraph*) f_Eta_el->Get("Graph;1");
TF1 *f7 = new TF1("f7",myfunc,-100,100,0);

double s1down_Eta_el=f7->GetX(y2,-100,0);
double s1up_Eta_el=f7->GetX(y2,0,100);
double s2down_Eta_el=f7->GetX(y1,-100,0);
double s2up_Eta_el=f7->GetX(y1,0,100);

double min_Eta_el=f7->GetMinimumX(-10,10);

f_Eta_el->Close();
gr->Clear(); 

//-----Eta_mu-----   

char path8[100];
sprintf(path8,"likelihoodScan/%s/Eta_mu/LS_objects_k_%s.root",argv[1],argv[1]);                
                       
TFile *f_Eta_mu = TFile::Open(path8);
gr= (TGraph*) f_Eta_mu->Get("Graph;1");
TF1 *f8 = new TF1("f8",myfunc,-100,100,0);

double s1down_Eta_mu=f8->GetX(y2,-100,0);
double s1up_Eta_mu=f8->GetX(y2,0,100);
double s2down_Eta_mu=f8->GetX(y1,-100,0);
double s2up_Eta_mu=f8->GetX(y1,0,100);

double min_Eta_mu=f8->GetMinimumX(-10,10);

f_Eta_mu->Close();
gr->Clear();

//-----Eta_ta-----       

char path9[100];
sprintf(path9,"likelihoodScan/%s/Eta_ta/LS_objects_k_%s.root",argv[1],argv[1]);            
                       
TFile *f_Eta_ta = TFile::Open(path9);
gr= (TGraph*) f_Eta_ta->Get("Graph;1");
TF1 *f9 = new TF1("f9",myfunc,-100,100,0);

double s1down_Eta_ta=f9->GetX(y2,-100,0);
double s1up_Eta_ta=f9->GetX(y2,0,100);
double s2down_Eta_ta=f9->GetX(y1,-100,0);
double s2up_Eta_ta=f9->GetX(y1,0,100);

double min_Eta_ta=f9->GetMinimumX(-10,10);

f_Eta_ta->Close();
gr->Clear();

//-----Eta_j-----                   
                       
char path10[100];
sprintf(path10,"likelihoodScan/%s/Eta_j/LS_objects_k_%s.root",argv[1],argv[1]);
                       
TFile *f_Eta_j = TFile::Open(path10);
gr= (TGraph*) f_Eta_j->Get("Graph;1");
TF1 *f10 = new TF1("f10",myfunc,-100,100,0);

double s1down_Eta_j=f10->GetX(y2,-100,0);
double s1up_Eta_j=f10->GetX(y2,0,100);
double s2down_Eta_j=f10->GetX(y1,-100,0);
double s2up_Eta_j=f10->GetX(y1,0,100);

double min_Eta_j=f9->GetMinimumX(-10,10);

f_Eta_j->Close();
gr->Clear();

//----------------------------------------                       
//------------Bin2 = mjj------------------

  Gdown->SetBinContent(2,s1down_mjj); 
  Gup->SetBinContent(2,s1up_mjj);
  Ydown->SetBinContent(2,s2down_mjj);
  Yup->SetBinContent(2,s2up_mjj);
  
//------------Bin4 = mll------------------

  Gdown->SetBinContent(4,s1down_mll); 
  Gup->SetBinContent(4,s1up_mll);
  Ydown->SetBinContent(4,s2down_mll);
  Yup->SetBinContent(4,s2up_mll);

//------------Bin6 = pt_el------------------

  Gdown->SetBinContent(6,s1down_PT_el); 
  Gup->SetBinContent(6,s1up_PT_el);
  Ydown->SetBinContent(6,s2down_PT_el);
  Yup->SetBinContent(6,s2up_PT_el);

//------------Bin8 = pt_mu------------------

  Gdown->SetBinContent(8,s1down_PT_mu); 
  Gup->SetBinContent(8,s1up_PT_mu);
  Ydown->SetBinContent(8,s2down_PT_mu);
  Yup->SetBinContent(8,s2up_PT_mu);

//------------Bin10 = pt_ta------------------

  Gdown->SetBinContent(10,s1down_PT_ta); 
  Gup->SetBinContent(10,s1up_PT_ta);
  Ydown->SetBinContent(10,s2down_PT_ta);
  Yup->SetBinContent(10,s2up_PT_ta);
  
//------------Bin12 = pt_j------------------

  Gdown->SetBinContent(12,s1down_PT_j); 
  Gup->SetBinContent(12,s1up_PT_j);
  Ydown->SetBinContent(12,s2down_PT_j);
  Yup->SetBinContent(12,s2up_PT_j);

//------------Bin14 = eta_el------------------

  Gdown->SetBinContent(14,s1down_Eta_el); 
  Gup->SetBinContent(14,s1up_Eta_el);
  Ydown->SetBinContent(14,s2down_Eta_el);
  Yup->SetBinContent(14,s2up_Eta_el);
  
//------------Bin16 = eta_mu------------------

  Gdown->SetBinContent(16,s1down_Eta_mu); 
  Gup->SetBinContent(16,s1up_Eta_mu);
  Ydown->SetBinContent(16,s2down_Eta_mu);
  Yup->SetBinContent(16,s2up_Eta_mu);

//------------Bin18 = eta_ta------------------

  Gdown->SetBinContent(18,s1down_Eta_ta); 
  Gup->SetBinContent(18,s1up_Eta_ta);
  Ydown->SetBinContent(18,s2down_Eta_ta);
  Yup->SetBinContent(18,s2up_Eta_ta);
  
//------------Bin20 = eta_j------------------

  Gdown->SetBinContent(20,s1down_Eta_j); 
  Gup->SetBinContent(20,s1up_Eta_j);
  Ydown->SetBinContent(20,s2down_Eta_j);
  Yup->SetBinContent(20,s2up_Eta_j);

//------------Bin intermedi----------------   

Gup->SetBinContent(1,0); 
Gup->SetBinContent(3,0); 
Gup->SetBinContent(5,0); 
Gup->SetBinContent(7,0); 
Gup->SetBinContent(9,0); 
Gup->SetBinContent(11,0); 
Gup->SetBinContent(13,0); 
Gup->SetBinContent(15,0); 
Gup->SetBinContent(17,0); 
Gup->SetBinContent(19,0); 
Gup->SetBinContent(21,0); 

Gdown->SetBinContent(1,0); 
Gdown->SetBinContent(3,0); 
Gdown->SetBinContent(5,0); 
Gdown->SetBinContent(7,0); 
Gdown->SetBinContent(9,0); 
Gdown->SetBinContent(11,0); 
Gdown->SetBinContent(13,0); 
Gdown->SetBinContent(15,0); 
Gdown->SetBinContent(17,0); 
Gdown->SetBinContent(19,0); 
Gdown->SetBinContent(21,0); 

//----------------------------------------------

Int_t n = 10;
Double_t x[10] = {1,2,3,4,5,6,7,8,9,10};
Double_t y[10]={min_mjj,min_mll,min_PT_el,min_PT_mu,min_PT_ta,min_PT_j,min_Eta_el,min_Eta_mu,min_Eta_ta,min_Eta_j};

auto g  = new TGraph(n,x,y);
g->SetMarkerColor(kRed);
g->SetMarkerStyle(kFullCircle);

//---------------------------------------------

char eftop[10];
sprintf(eftop,"%s",argv[1]);

char plotname[30];
sprintf(plotname,"CIplots/CI_%s.png",argv[1]);


//---------------------------------------------

TCanvas* c1 = new TCanvas("c1","c1",0,0,800,650);
TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.99);
c1_1->Draw();
c1_1->cd();
c1_1->SetTopMargin(0.1);
c1_1->SetBottomMargin(0.15);
c1_1->SetRightMargin(0.045);
c1_1->SetLeftMargin(0.15);

double a;
double b;

if(strcmp(argv[1],"cW")==0)
    {
   a=-0.5;
   b=0.5;
    }
  else if(strcmp(argv[1],"cHW")==0)
    { 
    a=-0.5;
    b=0.5; 
    }
  else if(strcmp(argv[1],"cHWB")==0)
    { 
    a=-9;
    b=9; 
    }
  else if(strcmp(argv[1],"cHbox")==0)
    { 
    a=-1;
    b=1; 
    }
  else if(strcmp(argv[1],"cHDD")==0)
    { 
    a=-5;
    b=5; 
    }    
  else if(strcmp(argv[1],"cWtil")==0)
    { 
    a=-0.5;
    b=0.5; 
    }
  else if(strcmp(argv[1],"cHWtil")==0)
    { 
    a=-1.7;
    b=1; 
    }
  else if(strcmp(argv[1],"cHWBtil")==0)
    { 
    a=-2.5;
    b=2; 
    }
    
Yup->GetYaxis()->SetRangeUser(a,b);

Yup->Draw();
Gup->Draw("SAME");
Ydown->Draw("SAME");
Gdown->Draw("SAME");
g->Draw("P");

Yup->GetXaxis()->SetNdivisions(0, kTRUE);

Yup->GetYaxis()->SetTitleOffset(1.4);
Yup->GetYaxis()->SetTitle("Confidence Interval");
Yup->GetYaxis()->SetLabelSize(0.045);
Yup->GetYaxis()->SetTitleSize(0.05);

TLatex latexLabel;
latexLabel.SetTextSize(0.04);
latexLabel.SetNDC();
latexLabel.DrawLatex(0.16, 0.93, "CMS   L=100 fb^-1");

TLatex latexLabel2;
latexLabel2.SetNDC();
latexLabel2.SetTextSize(0.04);
latexLabel2.DrawLatex(0.85, 0.93, "13 TeV");

TLatex latexLabel3;
latexLabel3.SetTextSize(0.05);
latexLabel3.SetNDC();
latexLabel3.DrawLatex(0.16, 0.03, eftop);

//-----------------------------------------------

TLatex latexLabelX;
latexLabelX.SetNDC();
latexLabelX.SetTextSize(0.04);
latexLabelX.DrawLatex(0.87, 0.11, "#eta_j");

TLatex latexLabelIX;
latexLabelIX.SetNDC();
latexLabelIX.SetTextSize(0.04);
latexLabelIX.DrawLatex(0.79, 0.11, "#eta_#tau");

TLatex latexLabelIIX;
latexLabelIIX.SetNDC();
latexLabelIIX.SetTextSize(0.04);
latexLabelIIX.DrawLatex(0.72, 0.11, "#eta_#mu");

TLatex latexLabelVII;
latexLabelVII.SetNDC();
latexLabelVII.SetTextSize(0.04);
latexLabelVII.DrawLatex(0.64, 0.11, "#eta_e");

TLatex latexLabelVI;
latexLabelVI.SetNDC();
latexLabelVI.SetTextSize(0.04);
latexLabelVI.DrawLatex(0.57, 0.11, "pt_j");

TLatex latexLabelV;
latexLabelV.SetNDC();
latexLabelV.SetTextSize(0.04);
latexLabelV.DrawLatex(0.50, 0.11, "pt_#tau");

TLatex latexLabelIV;
latexLabelIV.SetNDC();
latexLabelIV.SetTextSize(0.04);
latexLabelIV.DrawLatex(0.42, 0.11, "pt_#mu");

TLatex latexLabelIII;
latexLabelIII.SetNDC();
latexLabelIII.SetTextSize(0.04);
latexLabelIII.DrawLatex(0.35, 0.11, "pt_e");

TLatex latexLabelII;
latexLabelII.SetNDC();
latexLabelII.SetTextSize(0.04);
latexLabelII.DrawLatex(0.27, 0.11, "mll");

TLatex latexLabelI;
latexLabelI.SetNDC();
latexLabelI.SetTextSize(0.04);
latexLabelI.DrawLatex(0.20, 0.11, "mjj");




//-----------------------------------------------

TLegend *leg = new TLegend(0.15, 0.75, 0.48, 0.89);
leg->SetShadowColor(1);
leg->SetBorderSize(1);
leg->SetTextSize(0.03);
leg->SetFillColor(0);
leg->AddEntry(g, "Best fit", "p");
leg->AddEntry(Gup, "#pm1#sigma expected", "f");
leg->AddEntry(Yup, "#pm2#sigma expected", "f");
leg->Draw();

c1->SaveAs(plotname);

//------------------------------------Tables for LateX--------------------------------------------

char tablename[50];
sprintf(tablename,"CIplots/tabellaCI%s.txt",argv[1]);

fstream cifile;
cifile.open(tablename, fstream::out);

  cifile<<"  \\begin{tabular}{ |p{2.2cm}||p{3cm}|p{3cm}|  }"<<endl;
  cifile<<"  \\hline"<<endl;
  cifile<<"  \\multicolumn{3}{|c|}{Confidence Intervals for cW}\\\\"<<endl;
  cifile<<"  \\hline"<<endl<<endl;
  cifile<<"  \\hline"<<endl<<endl;
  	
  cifile<<"  Obs.&$1\\sigma CL$&$2\\sigma CL$\\\\"<<endl;
  cifile<<"  \\hline"<<endl;
  cifile<<"  $m_{jj}$&"<<"$["<<s1down_mjj<<","<<s1up_mjj<<"]$"<<"&"<<"$["<<s2down_mjj<<","<<s2up_mjj<<"]$"<<"\\\\"<<endl;
  cifile<<"  $m_{ll}$&"<<"$["<<s1down_mll<<","<<s1up_mll<<"]$"<<"&"<<"$["<<s2down_mll<<","<<s2up_mll<<"]$"<<"\\\\"<<endl;
  cifile<<"  \\hline"<<endl;
  cifile<<"  $p_T^{e}$&"<<"$["<<s1down_PT_el<<","<<s1up_PT_el<<"]$"<<"&"<<"$["<<s2down_PT_el<<","<<s2up_PT_el<<"]$"<<"\\\\"<<endl;
  cifile<<"  $p_T^{\\mu}$&"<<"$["<<s1down_PT_mu<<","<<s1up_PT_mu<<"]$"<<"&"<<"$["<<s2down_PT_mu<<","<<s2up_PT_mu<<"]$"<<"\\\\"<<endl;
  cifile<<"  $p_T^{\\tau}$&"<<"$["<<s1down_PT_ta<<","<<s1up_PT_ta<<"]$"<<"&"<<"$["<<s2down_PT_ta<<","<<s2up_PT_ta<<"]$"<<"\\\\"<<endl;
  cifile<<"  $p_T^{j}$&"<<"$["<<s1down_PT_j<<","<<s1up_PT_j<<"]$"<<"&"<<"$["<<s2down_PT_j<<","<<s2up_PT_j<<"]$"<<"\\\\"<<endl;
  cifile<<"  \\hline"<<endl;
  cifile<<"  $\\eta^{e}$&"<<"$["<<s1down_Eta_el<<","<<s1up_Eta_el<<"]$"<<"&"<<"$["<<s2down_Eta_el<<","<<s2up_Eta_el<<"]$"<<"\\\\"<<endl;
  cifile<<"  $\\eta^{\\mu}$&"<<"$["<<s1down_Eta_mu<<","<<s1up_Eta_mu<<"]$"<<"&"<<"$["<<s2down_Eta_mu<<","<<s2up_Eta_mu<<"]$"<<"\\\\"<<endl;
  cifile<<"  $\\eta^{\\tau}$&"<<"$["<<s1down_Eta_ta<<","<<s1up_Eta_ta<<"]$"<<"&"<<"$["<<s2down_Eta_ta<<","<<s2up_Eta_ta<<"]$"<<"\\\\"<<endl;
  cifile<<"  $\\eta^{j}$&"<<"$["<<s1down_Eta_j<<","<<s1up_Eta_j<<"]$"<<"&"<<"$["<<s2down_Eta_j<<","<<s2up_Eta_j<<"]$"<<"\\\\"<<endl;
  
  cifile<<"  \\hline"<<endl<<endl;
  cifile<<"\\end{tabular}"<<endl<<endl<<endl;

cifile.close();

int i=0;
return i;
}
