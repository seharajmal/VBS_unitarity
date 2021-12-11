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
#include <TLine.h>

 using namespace std;
 
TGraph *gr;
double myfunc(Double_t *x, Double_t *) { return gr->Eval(x[0]);}
 
int main(){
 
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
 tdrStyle->SetPadGridX(false);
 tdrStyle->SetPadGridY(false);
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
 
  const int NBINS=61;
  double_t edges[NBINS + 1] = {0,0.1,0.45,0.55,0.9,
                               1.1,1.45,1.55,1.9,
                               2.1,2.45,2.55,2.9,
                               3.1,3.45,3.55,3.9,
                               4.1,4.45,4.55,4.9,
                               5.1,5.45,5.55,5.9,
                               6.1,6.45,6.55,6.9,
                               7.1,7.45,7.55,7.9,
                               8.1,8.45,8.55,8.9,
                               9.1,9.45,9.55,9.9,
                               10.1,10.45,10.55,10.9,
                               11.1,11.45,11.55,11.9,
                               12.1,12.45,12.55,12.9,
                               13.1,13.45,13.55,13.9,
                               14.1,14.45,14.55,14.9,15};
  
  TH1F *Yup=new TH1F("yellow_up","",NBINS,edges);
  TH1F *Gup=new TH1F("green_up","",NBINS,edges);
  TH1F *Ydown=new TH1F("yellow_down","",NBINS,edges);
  TH1F *Gdown=new TH1F("green_down","",NBINS,edges);
  
  TH1F *Vup=new TH1F("violet_up","",NBINS,edges);
  TH1F *Bup=new TH1F("blue_up","",NBINS,edges);
  TH1F *Vdown=new TH1F("violet_down","",NBINS,edges);
  TH1F *Bdown=new TH1F("blue_down","",NBINS,edges);
  
  TH1F *redVup=new TH1F("redviolet_up","",NBINS,edges);
  TH1F *redBup=new TH1F("redblue_up","",NBINS,edges);
  TH1F *redVdown=new TH1F("redviolet_down","",NBINS,edges);
  TH1F *redBdown=new TH1F("redblue_down","",NBINS,edges);
  
  TH1F *ridVup=new TH1F("ridviolet_up","",NBINS,edges);
  TH1F *ridBup=new TH1F("ridblue_up","",NBINS,edges);
  TH1F *ridVdown=new TH1F("ridviolet_down","",NBINS,edges);
  TH1F *ridBdown=new TH1F("ridblue_down","",NBINS,edges);  

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

//---

Vup->SetLineColor(kBlue-10);
Vup->SetFillStyle(1001);
Vup->SetFillColor(kBlue-10);

Vdown->SetLineColor(kBlue-10);
Vdown->SetFillStyle(1001);
Vdown->SetFillColor(kBlue-10);

Bup->SetLineColor(kBlue);
Bup->SetFillStyle(1001);
Bup->SetFillColor(kBlue);

Bdown->SetLineColor(kBlue);
Bdown->SetFillStyle(1001);
Bdown->SetFillColor(kBlue);

//---

redVup->SetLineColor(kRed-10);
redVup->SetFillStyle(3023);
redVup->SetFillColor(kRed-10);

redVdown->SetLineColor(kRed-10);
redVdown->SetFillStyle(3023);
redVdown->SetFillColor(kRed-10);

redBup->SetLineColor(kRed);
redBup->SetFillStyle(3023);
redBup->SetFillColor(kRed);

redBdown->SetLineColor(kRed);
redBdown->SetFillStyle(3023);
redBdown->SetFillColor(kRed);

//---

ridVup->SetLineColor(kBlue-10);
ridVup->SetFillStyle(3023);
ridVup->SetFillColor(kBlue-10);

ridVdown->SetLineColor(kBlue-10);
ridVdown->SetFillStyle(3023);
ridVdown->SetFillColor(kBlue-10);

ridBup->SetLineColor(kBlue);
ridBup->SetFillStyle(3023);
ridBup->SetFillColor(kBlue);

ridBdown->SetLineColor(kBlue);
ridBdown->SetFillStyle(3023);
ridBdown->SetFillColor(kBlue);

//----------------------------FILLING MODEL HISTOGRAMS-------------------------------------                      
                            
//------------Bin2 = cW------------------

  redBdown->SetBinContent(2,-0.14*10); 
  redBup->SetBinContent(2,0.11*10);
  redVdown->SetBinContent(2,-0.19*10);
  redVup->SetBinContent(2,0.16*10);
  
//------------Bin6 = cHW------------------

  Gdown->SetBinContent(6,-2.02); 
  Gup->SetBinContent(6,1.04);
  Ydown->SetBinContent(6,-2.78);
  Yup->SetBinContent(6,1.68);

//------------Bin10 = cHWB------------------

  Gdown->SetBinContent(10,-3.32); 
  Gup->SetBinContent(10,3.98);
  Ydown->SetBinContent(10,-6.13);
  Yup->SetBinContent(10,8.94);

//------------Bin14 = cHbox------------------

  Gdown->SetBinContent(14,-3.85); 
  Gup->SetBinContent(14,5.57);
  Ydown->SetBinContent(14,-5.84);
  Yup->SetBinContent(14,7.66);

//------------Bin18 = cHDD------------------

  Gdown->SetBinContent(18,-2.75); 
  Gup->SetBinContent(18,3.61);
  Ydown->SetBinContent(18,-4.99);
  Yup->SetBinContent(18,9.66);
  
//------------Bin22 = cHq1------------------

  redBdown->SetBinContent(22,-0.62*10); 
  redBup->SetBinContent(22,0.50*10);
  redVdown->SetBinContent(22,-0.86*10);
  redVup->SetBinContent(22,0.74*10);
  
//------------Bin26 = cHq3------------------

  redBdown->SetBinContent(26,-0.06*10); 
  redBup->SetBinContent(26,0.06*10);
  redVdown->SetBinContent(26,-0.11*10);
  redVup->SetBinContent(26,0.11*10);
  
//------------Bin30 = cHl1------------------

  Gdown->SetBinContent(30,-7.44); 
  Gup->SetBinContent(30,7.10);
  Ydown->SetBinContent(30,-10.5);
  Yup->SetBinContent(30,10.1);
  
//------------Bin34 = cHl3------------------

  redBdown->SetBinContent(34,-0.05*10); 
  redBup->SetBinContent(34,0.05*10);
  redVdown->SetBinContent(34,-0.10*10);
  redVup->SetBinContent(34,0.10*10);

//------------Bin38 = cqq1------------------

  redBdown->SetBinContent(38,-0.04*10); 
  redBup->SetBinContent(38,0.07*10);
  redVdown->SetBinContent(38,-0.06*10);
  redVup->SetBinContent(38,0.09*10);
  
//------------Bin42 = cqq3------------------

  redBdown->SetBinContent(42,-0.01*10); 
  redBup->SetBinContent(42,0.02*10);
  redVdown->SetBinContent(42,-0.02*10);
  redVup->SetBinContent(42,0.06*10);

//------------Bin46 = cqq11------------------

  Gdown->SetBinContent(46,-0); 
  Gup->SetBinContent(46,0);
  Ydown->SetBinContent(46,-0);
  Yup->SetBinContent(46,0);

//------------Bin50 = cqq31------------------

  Gdown->SetBinContent(50,-0); 
  Gup->SetBinContent(50,0);
  Ydown->SetBinContent(50,-0);
  Yup->SetBinContent(50,0);

//------------Bin54 = cll------------------

  Gdown->SetBinContent(54,-14); 
  Gup->SetBinContent(54,14.01);
  Ydown->SetBinContent(54,-32.6);
  Yup->SetBinContent(54,32.9);
  
//------------Bin58 = cll1------------------

  redBdown->SetBinContent(58,-0.11*10); 
  redBup->SetBinContent(58,0.11*10);
  redVdown->SetBinContent(58,-0.21*10);
  redVup->SetBinContent(58,0.21*10);  
  

//----------------------------FILLING EXPERIMENTAL HISTOGRAMS-------------------------------------   

//------------Bin4 = cW------------------

  ridBdown->SetBinContent(4,-0.20*10); 
  ridBup->SetBinContent(4,0.20*10);
  ridVdown->SetBinContent(4,-0.30*10);
  ridVup->SetBinContent(4,0.30*10);
  
//------------Bin8 = cHW------------------

  Bdown->SetBinContent(8,-2.07); 
  Bup->SetBinContent(8,1.76);
  Vdown->SetBinContent(8,-3.09);
  Vup->SetBinContent(8,2.70);

//------------Bin12 = cHWB------------------

  Bdown->SetBinContent(12,-5.42); 
  Bup->SetBinContent(12,9.08);
  Vdown->SetBinContent(12,-9.32);
  Vup->SetBinContent(12,16.71);

//------------Bin16 = cHbox------------------

  Bdown->SetBinContent(16,-5.26); 
  Bup->SetBinContent(16,6.60);
  Vdown->SetBinContent(16,-9.71);
  Vup->SetBinContent(16,19.33);

//------------Bin20 = cHDD------------------

  Bdown->SetBinContent(20,-5.41); 
  Bup->SetBinContent(20,6.64);
  Vdown->SetBinContent(20,-8.18);
  Vup->SetBinContent(20,9.53);

//------------Bin24 = cHq1------------------

  Bdown->SetBinContent(24,-1.28); 
  Bup->SetBinContent(24,1.18);
  Vdown->SetBinContent(24,-1.88);
  Vup->SetBinContent(24,1.78);
  
//------------Bin28 = cHq3------------------

  ridBdown->SetBinContent(28,-0.22*10); 
  ridBup->SetBinContent(28,0.21*10);
  ridVdown->SetBinContent(28,-0.44*10);
  ridVup->SetBinContent(28,0.39*10);
  
//------------Bin32 = cHl1------------------

  Bdown->SetBinContent(32,-13.73); 
  Bup->SetBinContent(32,13.61);
  Vdown->SetBinContent(32,-20.23);
  Vup->SetBinContent(32,20.09);
  
//------------Bin36 = cHl3------------------

  ridBdown->SetBinContent(36,-0.15*10); 
  ridBup->SetBinContent(36,0.15*10);
  ridVdown->SetBinContent(36,-0.30*10);
  ridVup->SetBinContent(36,0.29*10);

//------------Bin40 = cqq1------------------

  ridBdown->SetBinContent(40,-0.15*10); 
  ridBup->SetBinContent(40,0.27*10);
  ridVdown->SetBinContent(40,-0.24*10);
  ridVup->SetBinContent(40,0.37*10);
  
//------------Bin44 = cqq3------------------

  ridBdown->SetBinContent(44,-0.04*10); 
  ridBup->SetBinContent(44,0.04*10);
  ridVdown->SetBinContent(44,-0.07*10);
  ridVup->SetBinContent(44,0.12*10);

//------------Bin48 = cqq11------------------

  ridBdown->SetBinContent(48,-0.15*10); 
  ridBup->SetBinContent(48,0.28*10);
  ridVdown->SetBinContent(48,-0.24*10);
  ridVup->SetBinContent(48,0.37*10);

//------------Bin52 = cqq31------------------

  ridBdown->SetBinContent(52,-0.04*10); 
  ridBup->SetBinContent(52,0.06*10);
  ridVdown->SetBinContent(52,-0.08*10);
  ridVup->SetBinContent(52,0.26*10);

//------------Bin56 = cll------------------

  Bdown->SetBinContent(56,-28.1); 
  Bup->SetBinContent(56,28.2);
  Vdown->SetBinContent(56,-41.9);
  Vup->SetBinContent(56,42.0);
  
//------------Bin60 = cll1------------------

  ridBdown->SetBinContent(60,-0.20*10); 
  ridBup->SetBinContent(60,0.20*10);
  ridVdown->SetBinContent(60,-0.39*10);
  ridVup->SetBinContent(60,0.40*10);  
  


//---------------------------------------------
//---------------------------------------------

 TLine *line1 = new TLine(1,-10,1,20);
 TLine *line2 = new TLine(2,-10,2,20);
 TLine *line3 = new TLine(3,-10,3,20);
 TLine *line4 = new TLine(4,-10,4,20);
 TLine *line5 = new TLine(5,-10,5,20);
 TLine *line6 = new TLine(6,-10,6,20);
 TLine *line7 = new TLine(7,-10,7,20);
 TLine *line8 = new TLine(8,-10,8,20);
 TLine *line9 = new TLine(9,-10,9,20);
 TLine *line10 = new TLine(10,-10,10,20); 
 TLine *line11 = new TLine(11,-10,11,20); 
 TLine *line12 = new TLine(12,-10,12,20);  
 TLine *line13 = new TLine(13,-10,13,20);  
 TLine *line14 = new TLine(14,-10,14,20);  
 
 
line1->SetLineStyle(kSolid); 
line2->SetLineStyle(kSolid); 
line3->SetLineStyle(kSolid); 
line4->SetLineStyle(kSolid); 
line5->SetLineStyle(kSolid); 
line6->SetLineStyle(kSolid);  
line7->SetLineStyle(kSolid); 
line8->SetLineStyle(kSolid); 
line9->SetLineStyle(kSolid); 
line10->SetLineStyle(kSolid); 
line11->SetLineStyle(kSolid); 
line12->SetLineStyle(kSolid);  
line13->SetLineStyle(kSolid); 
line14->SetLineStyle(kSolid); 

line1->SetLineColor(kBlack); 
line2->SetLineColor(kBlack); 
line3->SetLineColor(kBlack); 
line4->SetLineColor(kBlack); 
line5->SetLineColor(kBlack); 
line6->SetLineColor(kBlack);  
line7->SetLineColor(kBlack); 
line8->SetLineColor(kBlack); 
line9->SetLineColor(kBlack); 
line10->SetLineColor(kBlack); 
line11->SetLineColor(kBlack); 
line12->SetLineColor(kBlack);
line13->SetLineColor(kBlack); 
line14->SetLineColor(kBlack);   

 TLine *lineh = new TLine(0.3,0,6.2,0);
 lineh->SetLineStyle(kSolid); 
 lineh->SetLineColor(kBlack); 
//---------------------------------------------
//---------------------------------------------

TCanvas* c1 = new TCanvas("c1","c1",0,0,800,650);
TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.99);
c1_1->Draw();
c1_1->cd();
c1_1->SetTopMargin(0.1);
c1_1->SetBottomMargin(0.15);
c1_1->SetRightMargin(0.045);
c1_1->SetLeftMargin(0.15);

Yup->GetYaxis()->SetRangeUser(-10,20);

Yup->Draw();

line1->Draw("SAME");
line2->Draw("SAME");
line3->Draw("SAME");
line4->Draw("SAME");
line5->Draw("SAME");
line6->Draw("SAME");
line7->Draw("SAME");
line8->Draw("SAME");
line9->Draw("SAME");
line10->Draw("SAME");
line11->Draw("SAME");
line12->Draw("SAME");
line13->Draw("SAME");
line14->Draw("SAME");

Gup->Draw("SAME");
Ydown->Draw("SAME");
Gdown->Draw("SAME");
Vup->Draw("SAME");
Bup->Draw("SAME");
Vdown->Draw("SAME");
Bdown->Draw("SAME");
redVup->Draw("SAME");
redBup->Draw("SAME");
redVdown->Draw("SAME");
redBdown->Draw("SAME");
ridVup->Draw("SAME");
ridBup->Draw("SAME");
ridVdown->Draw("SAME");
ridBdown->Draw("SAME");
Ydown->Draw("SAME");
Gdown->Draw("SAME");






Yup->GetXaxis()->SetNdivisions(0, kTRUE);

Yup->GetYaxis()->SetTitleOffset(1.4);
Yup->GetYaxis()->SetTitle("Best Confidence Interval");
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

lineh->Draw("SAME");
//-----------------------------------------------

TLatex latexLabelI;  
latexLabelI.SetNDC(); 
latexLabelI.SetTextSize(0.025);
latexLabelI.SetTextAngle(45);
latexLabelI.DrawLatex(0.17, 0.09, "cW");

TLatex latexLabelII;  
latexLabelII.SetNDC(); 
latexLabelII.SetTextSize(0.025);
latexLabelII.SetTextAngle(45);
latexLabelII.DrawLatex(0.22, 0.09, "cHW");

TLatex latexLabelIII;  
latexLabelIII.SetNDC(); 
latexLabelIII.SetTextSize(0.025);
latexLabelIII.SetTextAngle(45);
latexLabelIII.DrawLatex(0.27, 0.08, "cHWB");

TLatex latexLabelIV;  
latexLabelIV.SetNDC(); 
latexLabelIV.SetTextSize(0.025);
latexLabelIV.SetTextAngle(45);
latexLabelIV.DrawLatex(0.32, 0.08, "cHbox");

TLatex latexLabelV;  
latexLabelV.SetNDC(); 
latexLabelV.SetTextSize(0.025);
latexLabelV.SetTextAngle(45);
latexLabelV.DrawLatex(0.38, 0.08, "cHDD");

TLatex latexLabelIX;  
latexLabelIX.SetNDC(); 
latexLabelIX.SetTextSize(0.025);
latexLabelIX.SetTextAngle(45);
latexLabelIX.DrawLatex(0.44, 0.09, "cHq1");

TLatex latexLabelX;  
latexLabelX.SetNDC(); 
latexLabelX.SetTextSize(0.025);
latexLabelX.SetTextAngle(45);
latexLabelX.DrawLatex(0.49, 0.09, "cHq3");

TLatex latexLabelXI;  
latexLabelXI.SetNDC(); 
latexLabelXI.SetTextSize(0.025);
latexLabelXI.SetTextAngle(45);
latexLabelXI.DrawLatex(0.55, 0.09, "cHl1");

TLatex latexLabelXII;  
latexLabelXII.SetNDC(); 
latexLabelXII.SetTextSize(0.025);
latexLabelXII.SetTextAngle(45);
latexLabelXII.DrawLatex(0.60, 0.09, "cHl3");

TLatex latexLabelXIII;  
latexLabelXIII.SetNDC(); 
latexLabelXIII.SetTextSize(0.025);
latexLabelXIII.SetTextAngle(45);
latexLabelXIII.DrawLatex(0.65, 0.09, "cqq1");

TLatex latexLabelXIV;  
latexLabelXIV.SetNDC(); 
latexLabelXIV.SetTextSize(0.025);
latexLabelXIV.SetTextAngle(45);
latexLabelXIV.DrawLatex(0.71, 0.09, "cqq3");

TLatex latexLabelXV;  
latexLabelXV.SetNDC(); 
latexLabelXV.SetTextSize(0.025);
latexLabelXV.SetTextAngle(45);
latexLabelXV.DrawLatex(0.75, 0.085, "cqq11");

TLatex latexLabelXVI;  
latexLabelXVI.SetNDC(); 
latexLabelXVI.SetTextSize(0.025);
latexLabelXVI.SetTextAngle(45);
latexLabelXVI.DrawLatex(0.81, 0.085, "cqq31");

TLatex latexLabelXVII;  
latexLabelXVII.SetNDC(); 
latexLabelXVII.SetTextSize(0.025);
latexLabelXVII.SetTextAngle(45);
latexLabelXVII.DrawLatex(0.88, 0.09, "cll");

TLatex latexLabelXVIII;  
latexLabelXVIII.SetNDC(); 
latexLabelXVIII.SetTextSize(0.025);
latexLabelXVIII.SetTextAngle(45);
latexLabelXVIII.DrawLatex(0.93, 0.09, "cll1");



//-----------------------------------------------

TLegend *leg = new TLegend(0.59, 0.64, 0.86, 0.88);
leg->SetShadowColor(1);
leg->SetBorderSize(1);
leg->SetTextSize(0.025);
leg->SetFillColor(0);
leg->AddEntry(Gup, "#pm1#sigma all final states", "f");
leg->AddEntry(Yup, "#pm2#sigma all final states", "f");
leg->AddEntry(Bup, "#pm1#sigma only e-mu", "f");
leg->AddEntry(Vup, "#pm2#sigma only e-mu", "f");
leg->AddEntry(redBup, "#pm1#sigma all final states (*10)", "f");
leg->AddEntry(redVup, "#pm2#sigma all final states (*10)", "f");
leg->AddEntry(ridBup, "#pm1#sigma only e-mu (*10)", "f");
leg->AddEntry(ridVup, "#pm2#sigma only e-mu (*10)", "f");
leg->Draw();

c1->SaveAs("modVSexp.png");


int i=0;
return i;
}
