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
#include <TLine.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TClass.h>
#include <TPad.h>
#include <TF1.h>
#include <fstream>

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
 
  const int NBINS=33;
  double_t edges[NBINS + 1] = {0.0,0.7,1.3,1.7,2.3,2.7,3.3,3.7,4.3,4.7,5.3,5.7,6.3,6.7,7.3,7.7,8.3,8.7,9.3,9.7,10.3,10.7,11.3,11.7,12.3,12.7,13.3,13.7,14.3,14.7,15.3,15.7,16.3,17};
  TH1F *Yup=new TH1F("yellow_up","",NBINS,edges);
  TH1F *Gup=new TH1F("green_up","",NBINS,edges);
  TH1F *Ydown=new TH1F("yellow_down","",NBINS,edges);
  TH1F *Gdown=new TH1F("green_down","",NBINS,edges);
  
  TH1F *rYup=new TH1F("yellow_rup","",NBINS,edges);
  TH1F *rGup=new TH1F("green_rup","",NBINS,edges);
  TH1F *rYdown=new TH1F("yellow_rdown","",NBINS,edges);
  TH1F *rGdown=new TH1F("green_rdown","",NBINS,edges);
  
  TH1F *eYup=new TH1F("yellow_eup","",NBINS,edges);
  TH1F *eGup=new TH1F("green_eup","",NBINS,edges);
  TH1F *eYdown=new TH1F("yellow_edown","",NBINS,edges);
  TH1F *eGdown=new TH1F("green_edown","",NBINS,edges);  
  
Yup->SetLineColor(kAzure+10);
Yup->SetFillStyle(1001);
Yup->SetFillColor(kAzure+10);

Ydown->SetLineColor(kAzure+10);
Ydown->SetFillStyle(1001);
Ydown->SetFillColor(kAzure+10);

Gup->SetLineColor(kBlue+1);
Gup->SetFillStyle(1001);
Gup->SetFillColor(kBlue+1);

Gdown->SetLineColor(kBlue+1);
Gdown->SetFillStyle(1001);
Gdown->SetFillColor(kBlue+1);

//----

rYup->SetLineColor(kAzure+10);
rYup->SetFillStyle(3023);
rYup->SetFillColor(kAzure+10);

rYdown->SetLineColor(kAzure+10);
rYdown->SetFillStyle(3023);
rYdown->SetFillColor(kAzure+10);

rGup->SetLineColor(kBlue+1);
rGup->SetFillStyle(3023);
rGup->SetFillColor(kBlue+1);

rGdown->SetLineColor(kBlue+1);
rGdown->SetFillStyle(3023);
rGdown->SetFillColor(kBlue+1);

//----

eYup->SetLineColor(kAzure+10);
eYup->SetFillStyle(3344);
eYup->SetFillColor(kAzure+10);

eYdown->SetLineColor(kAzure+10);
eYdown->SetFillStyle(3344);
eYdown->SetFillColor(kAzure+10);

eGup->SetLineColor(kBlue+1);
eGup->SetFillStyle(3344);
eGup->SetFillColor(kBlue+1);

eGdown->SetLineColor(kBlue+1);
eGdown->SetFillStyle(3344);
eGdown->SetFillColor(kBlue+1);

//----------------------------BEST CONFIDENCE INTERVALS FOR EACH OPERATOR-------------------------------------                      
            
    
                   
//----------------------------------------                       
//------------Bin2 = cqq3------------------

  Gdown->SetBinContent(2,-0.02); 
  Gup->SetBinContent(2,0.03);
  Ydown->SetBinContent(2,-0.03);
  Yup->SetBinContent(2,0.07);

//------------Bin4 = cqq1------------------

  Gdown->SetBinContent(4,-0.05); 
  Gup->SetBinContent(4,0.09);
  Ydown->SetBinContent(4,-0.09);
  Yup->SetBinContent(4,0.12);

//------------Bin6 = cW------------------

  Gdown->SetBinContent(6,-0.12); 
  Gup->SetBinContent(6,0.10);
  Ydown->SetBinContent(6,-0.17);
  Yup->SetBinContent(6,0.15);
  
  
//------------Bin8 = cWtil------------------

  Gdown->SetBinContent(8,-0.11); 
  Gup->SetBinContent(8,0.11);
  Ydown->SetBinContent(8,-0.16);
  Yup->SetBinContent(8,0.16);  
  
//------------Bin10 = cHl3------------------

  Gdown->SetBinContent(10,-0.09); 
  Gup->SetBinContent(10,0.09);
  Ydown->SetBinContent(10,-0.18);
  Yup->SetBinContent(10,0.18);  
  
//------------Bin12 = cHq3------------------

  Gdown->SetBinContent(12,-0.12); 
  Gup->SetBinContent(12,0.12);
  Ydown->SetBinContent(12,-0.24);
  Yup->SetBinContent(12,0.23); 
  
//------------Bin14 = cll1------------------

  Gdown->SetBinContent(14,-0.14); 
  Gup->SetBinContent(14,0.14);
  Ydown->SetBinContent(14,-0.27);
  Yup->SetBinContent(14,0.27);

//------------Bin16 = cHW------------------

  Gdown->SetBinContent(16,-0.36); 
  Gup->SetBinContent(16,0.37);
  Ydown->SetBinContent(16,-0.53);
  Yup->SetBinContent(16,0.53);

  
//------------Bin18 = cHq1------------------

  Gdown->SetBinContent(18,-0.93); 
  Gup->SetBinContent(18,0.81);
  Ydown->SetBinContent(18,-1.32);
  Yup->SetBinContent(18,1.19);

//------------Bin20 = cHWtil------------------

  rGdown->SetBinContent(20,-1.21/10); 
  rGup->SetBinContent(20,1.21/10);
  rYdown->SetBinContent(20,-1.77/10);
  rYup->SetBinContent(20,1.77/10);

//------------Bin22 = cHbox------------------

  rGdown->SetBinContent(22,-1.90/10); 
  rGup->SetBinContent(22,2.28/10);
  rYdown->SetBinContent(22,-2.83/10);
  rYup->SetBinContent(22,3.22/10);
  
//------------Bin24 = cHWB------------------

  rGdown->SetBinContent(24,-3.63/10); 
  rGup->SetBinContent(24,4.39/10);
  rYdown->SetBinContent(24,-6.66/10);
  rYup->SetBinContent(24,9.74/10);

//------------Bin26 = cHDD------------------

  rGdown->SetBinContent(26,-3.54/10); 
  rGup->SetBinContent(26,5.32/10);
  rYdown->SetBinContent(26,-6.20/10);
  rYup->SetBinContent(26,10.5/10);
  

//------------Bin28 = cHl1------------------

  rGdown->SetBinContent(28,-7.41/10); 
  rGup->SetBinContent(28,7.21/10);
  rYdown->SetBinContent(28,-10.8/10);
  rYup->SetBinContent(28,10.6/10);
  
//------------Bin30 = cHWBtil------------------

  eGdown->SetBinContent(30,-14.8/100); 
  eGup->SetBinContent(30,14.8/100);
  eYdown->SetBinContent(30,-35.8/100);
  eYup->SetBinContent(30,35.6/100);
  
//------------Bin32 = cll------------------

  eGdown->SetBinContent(32,-17.5/100); 
  eGup->SetBinContent(32,17.6/100);
  eYdown->SetBinContent(32,-46.2/100);
  eYup->SetBinContent(32,46.5/100);


//-----------------Segna come punti rossi i minimi della likelihood---------------------

Int_t n = 16;
Double_t x[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
Double_t y[16]={0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05};

auto g  = new TGraph(n,x,y);
g->SetMarkerColor(kRed);
g->SetMarkerStyle(kFullCircle);


//---------------------------------------------

TCanvas* c1 = new TCanvas("c1","c1",0,0,800,650);
TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.99);
c1_1->Draw();
c1_1->cd();
c1_1->SetTopMargin(0.1);
c1_1->SetBottomMargin(0.15);
c1_1->SetRightMargin(0.045);
c1_1->SetLeftMargin(0.15);

double a=-1.4; // sono gli estremi dell'intervallo 2sigma più brutto
double b=1.4;  // 

//--------------

Yup->GetYaxis()->SetRangeUser(a,b);

Yup->Draw();
Gup->Draw("SAME");
Ydown->Draw("SAME");
Gdown->Draw("SAME");
rYup->Draw("SAME");
rGup->Draw("SAME");
rYdown->Draw("SAME");
rGdown->Draw("SAME");
eYup->Draw("SAME");
eGup->Draw("SAME");
eYdown->Draw("SAME");
eGdown->Draw("SAME");
g->Draw("P");

Yup->GetXaxis()->SetNdivisions(0, kTRUE);

Yup->GetYaxis()->SetTitleOffset(1.4);
Yup->GetYaxis()->SetTitle("Best Confidence Interval");
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


//-----------------------------------------------


TLatex latexLabelI;  
latexLabelI.SetNDC(); 
latexLabelI.SetTextSize(0.025);
latexLabelI.SetTextAngle(45);
latexLabelI.DrawLatex(0.29, 0.09, "cW");

TLatex latexLabelII;  
latexLabelII.SetNDC(); 
latexLabelII.SetTextSize(0.025);
latexLabelII.SetTextAngle(45);
latexLabelII.DrawLatex(0.52, 0.09, "cHW");

TLatex latexLabelIII;  
latexLabelIII.SetNDC(); 
latexLabelIII.SetTextSize(0.025);
latexLabelIII.SetTextAngle(45);
latexLabelIII.DrawLatex(0.70, 0.08, "cHWB");

TLatex latexLabelIV;  
latexLabelIV.SetNDC(); 
latexLabelIV.SetTextSize(0.025);
latexLabelIV.SetTextAngle(45);
latexLabelIV.DrawLatex(0.66, 0.08, "cHbox");

TLatex latexLabelV;  
latexLabelV.SetNDC(); 
latexLabelV.SetTextSize(0.025);
latexLabelV.SetTextAngle(45);
latexLabelV.DrawLatex(0.75, 0.08, "cHDD");

TLatex latexLabelVI;  
latexLabelVI.SetNDC(); 
latexLabelVI.SetTextSize(0.025);
latexLabelVI.SetTextAngle(45);
latexLabelVI.DrawLatex(0.33, 0.08, "cWtil");

TLatex latexLabelVII;  
latexLabelVII.SetNDC(); 
latexLabelVII.SetTextSize(0.025);
latexLabelVII.SetTextAngle(45);
latexLabelVII.DrawLatex(0.615, 0.08, "cHWtil");

TLatex latexLabelVIII;  
latexLabelVIII.SetNDC(); 
latexLabelVIII.SetTextSize(0.025);
latexLabelVIII.SetTextAngle(45);
latexLabelVIII.DrawLatex(0.835, 0.07, "cHWBtil");

TLatex latexLabelIX;  
latexLabelIX.SetNDC(); 
latexLabelIX.SetTextSize(0.025);
latexLabelIX.SetTextAngle(45);
latexLabelIX.DrawLatex(0.565, 0.09, "cHq1");

TLatex latexLabelX;  
latexLabelX.SetNDC(); 
latexLabelX.SetTextSize(0.025);
latexLabelX.SetTextAngle(45);
latexLabelX.DrawLatex(0.43, 0.09, "cHq3");

TLatex latexLabelXI;  
latexLabelXI.SetNDC(); 
latexLabelXI.SetTextSize(0.025);
latexLabelXI.SetTextAngle(45);
latexLabelXI.DrawLatex(0.80, 0.09, "cHl1");

TLatex latexLabelXII;  
latexLabelXII.SetNDC(); 
latexLabelXII.SetTextSize(0.025);
latexLabelXII.SetTextAngle(45);
latexLabelXII.DrawLatex(0.38, 0.09, "cHl3");

TLatex latexLabelXIII;  
latexLabelXIII.SetNDC(); 
latexLabelXIII.SetTextSize(0.025);
latexLabelXIII.SetTextAngle(45);
latexLabelXIII.DrawLatex(0.24, 0.09, "cqq1");

TLatex latexLabelXIV;  
latexLabelXIV.SetNDC(); 
latexLabelXIV.SetTextSize(0.025);
latexLabelXIV.SetTextAngle(45);
latexLabelXIV.DrawLatex(0.19, 0.09, "cqq3");


TLatex latexLabelXVII;  
latexLabelXVII.SetNDC(); 
latexLabelXVII.SetTextSize(0.025);
latexLabelXVII.SetTextAngle(45);
latexLabelXVII.DrawLatex(0.90, 0.09, "cll");

TLatex latexLabelXVIII;  
latexLabelXVIII.SetNDC(); 
latexLabelXVIII.SetTextSize(0.025);
latexLabelXVIII.SetTextAngle(45);
latexLabelXVIII.DrawLatex(0.48, 0.09, "cll1");

//-----------------------------------------------
//-----------------------------------------------

TLegend *leg = new TLegend(0.18, 0.62, 0.43, 0.89);
leg->SetShadowColor(1);
leg->SetBorderSize(1);
leg->SetTextSize(0.025);
leg->SetFillColor(0);
leg->AddEntry(g, "Best fit", "p");
leg->AddEntry(Gup, "#pm1#sigma expected", "f");
leg->AddEntry(Yup, "#pm2#sigma expected", "f"); 
leg->AddEntry(rGup, "#pm1#sigma expected (*0.1)", "f");
leg->AddEntry(rYup, "#pm2#sigma expected (*0.1)", "f"); 
leg->AddEntry(eGup, "#pm1#sigma expected (*0.01)", "f");
leg->AddEntry(eYup, "#pm2#sigma expected (*0.01)", "f"); 
leg->Draw();

c1->SaveAs("Best_intervals.png");



int i=0;
return i;
}
