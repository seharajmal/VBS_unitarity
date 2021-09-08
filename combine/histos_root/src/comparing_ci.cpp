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
  double_t edges[NBINS + 1] = {0.3,0.8,1.03,1.07,1.3,1.9,2.13,2.17,2.4,3.0,3.23,3.27,3.5,4.1,4.33,4.37,4.6,5.2,5.43,5.47,5.7,6.2};
  
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

redVup->SetLineColor(kBlue-10);
redVup->SetFillStyle(3023);
redVup->SetFillColor(kBlue-10);

redVdown->SetLineColor(kBlue-10);
redVdown->SetFillStyle(3023);
redVdown->SetFillColor(kBlue-10);

redBup->SetLineColor(kBlue);
redBup->SetFillStyle(3023);
redBup->SetFillColor(kBlue);

redBdown->SetLineColor(kBlue);
redBdown->SetFillStyle(3023);
redBdown->SetFillColor(kBlue);

//----------------------------FILLING MODEL HISTOGRAMS-------------------------------------                      
                            
//------------Bin2 = cW------------------

  Gdown->SetBinContent(2,-0.037); 
  Gup->SetBinContent(2,0.030);
  Ydown->SetBinContent(2,-0.053);
  Yup->SetBinContent(2,0.046);
  
//------------Bin6 = cHW------------------

  Gdown->SetBinContent(6,-0.037); 
  Gup->SetBinContent(6,0.034);
  Ydown->SetBinContent(6,0.054);
  Yup->SetBinContent(6,0.050);

//------------Bin10 = cHWB------------------

  Gdown->SetBinContent(10,-0.28); 
  Gup->SetBinContent(10,0.44);
  Ydown->SetBinContent(10,-0.42);
  Yup->SetBinContent(10,1.0);

//------------Bin14 = cHbox------------------

  Gdown->SetBinContent(14,-0.046); 
  Gup->SetBinContent(14,0.039);
  Ydown->SetBinContent(14,-0.067);
  Yup->SetBinContent(14,0.060);

//------------Bin18 = cHDD------------------

  Gdown->SetBinContent(18,-0.47); 
  Gup->SetBinContent(18,0.18);
  Ydown->SetBinContent(18,-0.59);
  Yup->SetBinContent(18,0.29);
  

//----------------------------FILLING EXPERIMENTAL HISTOGRAMS-------------------------------------   

//------------Bin4 = cW------------------

  Bdown->SetBinContent(4,-0.20); 
  Bup->SetBinContent(4,0.20);
  Vdown->SetBinContent(4,-0.30);
  Vup->SetBinContent(4,0.30);
  
//------------Bin8 = cHW------------------

  redBdown->SetBinContent(8,-2.07/10); 
  redBup->SetBinContent(8,1.76/10);
  redVdown->SetBinContent(8,-3.09/10);
  redVup->SetBinContent(8,2.70/10);

//------------Bin12 = cHWB------------------

  redBdown->SetBinContent(12,-5.42/10); 
  redBup->SetBinContent(12,9.08/10);
  redVdown->SetBinContent(12,-9.32/10);
  redVup->SetBinContent(12,16.71/10);

//------------Bin16 = cHbox------------------

  redBdown->SetBinContent(16,-5.26/10); 
  redBup->SetBinContent(16,6.60/10);
  redVdown->SetBinContent(16,-9.71/10);
  redVup->SetBinContent(16,19.33/10);

//------------Bin20 = cHDD------------------

  redBdown->SetBinContent(20,-5.41/10); 
  redBup->SetBinContent(20,6.64/10);
  redVdown->SetBinContent(20,-8.18/10);
  redVup->SetBinContent(20,9.53/10);


//---------------------------------------------
//---------------------------------------------

 TLine *line1 = new TLine(0.5,-1,0.5,2);
 TLine *line2 = new TLine(1.6,-1,1.6,2);
 TLine *line3 = new TLine(2.7,-1,2.7,2);
 TLine *line4 = new TLine(3.8,-1,3.8,2);
 TLine *line5 = new TLine(4.9,-1,4.9,2);
 TLine *line6 = new TLine(6,-1,6,2);
 
line1->SetLineStyle(kDotted); 
line2->SetLineStyle(kDotted); 
line3->SetLineStyle(kDotted); 
line4->SetLineStyle(kDotted); 
line5->SetLineStyle(kDotted); 
line6->SetLineStyle(kDotted);  

line1->SetLineColor(kBlack); 
line2->SetLineColor(kBlack); 
line3->SetLineColor(kBlack); 
line4->SetLineColor(kBlack); 
line5->SetLineColor(kBlack); 
line6->SetLineColor(kBlack);  

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

Yup->GetYaxis()->SetRangeUser(-1,2);

Yup->Draw();
line1->Draw("SAME");
line2->Draw("SAME");
line3->Draw("SAME");
line4->Draw("SAME");
line5->Draw("SAME");
line6->Draw("SAME");
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
Ydown->Draw("SAME");
Gdown->Draw("SAME");
lineh->Draw("SAME");




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


//-----------------------------------------------

TLatex latexLabelV;
latexLabelV.SetNDC();
latexLabelV.SetTextSize(0.04);
latexLabelV.DrawLatex(0.82, 0.11, "cHDD");

TLatex latexLabelIV;
latexLabelIV.SetNDC();
latexLabelIV.SetTextSize(0.04);
latexLabelIV.DrawLatex(0.66, 0.11, "cHbox");

TLatex latexLabelIII;
latexLabelIII.SetNDC();
latexLabelIII.SetTextSize(0.04);
latexLabelIII.DrawLatex(0.51, 0.11, "cHWB");

TLatex latexLabelII;
latexLabelII.SetNDC();
latexLabelII.SetTextSize(0.04);
latexLabelII.DrawLatex(0.38, 0.11, "cHW");

TLatex latexLabelI;
latexLabelI.SetNDC();
latexLabelI.SetTextSize(0.04);
latexLabelI.DrawLatex(0.23, 0.11, "cW");




//-----------------------------------------------

TLegend *leg = new TLegend(0.15, 0.65, 0.47, 0.89);
leg->SetShadowColor(1);
leg->SetBorderSize(1);
leg->SetTextSize(0.03);
leg->SetFillColor(0);
leg->AddEntry(Gup, "#pm1#sigma analysis1", "f");
leg->AddEntry(Yup, "#pm2#sigma analysis1", "f");
leg->AddEntry(Bup, "#pm1#sigma analysis2", "f");
leg->AddEntry(Vup, "#pm2#sigma analysis2", "f");
leg->AddEntry(redBup, "#pm1#sigma analysis2 (*0.1)", "f");
leg->AddEntry(redVup, "#pm2#sigma analysis2 (*0.1)", "f");
leg->Draw();

c1->SaveAs("modVSexp.png");


int i=0;
return i;
}
