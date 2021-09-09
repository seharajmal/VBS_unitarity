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

using namespace std;

TGraph *g;
double myfunc(Double_t *x, Double_t *) { return g->Eval(x[0]);}

int main(int argc, char*argv[]) {

/////////// START CONFIG

  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.5); 
  gStyle->SetTitleY(0.96); 
  gStyle->SetPaintTextFormat(".2f");
 TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");
 tdrStyle->SetCanvasBorderMode(0);
 tdrStyle->SetCanvasColor(kWhite);
 tdrStyle->SetCanvasDefH(600); 
 tdrStyle->SetCanvasDefW(600); 
 tdrStyle->SetCanvasDefX(0);  
 tdrStyle->SetCanvasDefY(0);
 tdrStyle->SetPadBorderMode(0);
 tdrStyle->SetPadColor(kWhite);
 tdrStyle->SetPadGridX(false);
 tdrStyle->SetPadGridY(false);
 tdrStyle->SetGridColor(0);
 tdrStyle->SetGridStyle(3);
 tdrStyle->SetGridWidth(1);
 tdrStyle->SetFrameBorderMode(0);
 tdrStyle->SetFrameBorderSize(1);
 tdrStyle->SetFrameFillColor(0);
 tdrStyle->SetFrameFillStyle(0);
 tdrStyle->SetFrameLineColor(1);
 tdrStyle->SetFrameLineStyle(1);
 tdrStyle->SetFrameLineWidth(1);
 tdrStyle->SetHistFillColor(0);
 tdrStyle->SetHistLineColor(1);
 tdrStyle->SetHistLineStyle(0);
 tdrStyle->SetHistLineWidth(1);
 tdrStyle->SetErrorX(0.);
 tdrStyle->SetMarkerStyle(20);
 tdrStyle->SetOptFit(1);
 tdrStyle->SetFitFormat("5.4g");
 tdrStyle->SetFuncStyle(1);
 tdrStyle->SetFuncWidth(1);
 tdrStyle->SetOptDate(0);
 tdrStyle->SetOptFile(0);
 tdrStyle->SetOptStat(""); 
 tdrStyle->SetStatColor(kGray);
 tdrStyle->SetStatFont(42);
 tdrStyle->SetTextSize(11);
 tdrStyle->SetTextAlign(11);
 tdrStyle->SetStatTextColor(1);
 tdrStyle->SetStatFormat("6.4g");
 tdrStyle->SetStatBorderSize(0);
 tdrStyle->SetStatX(1.); 
 tdrStyle->SetStatY(1.); 
 tdrStyle->SetStatFontSize(0.025); 
 tdrStyle->SetStatW(0.25); 
 tdrStyle->SetPadTopMargin(0.095);
 tdrStyle->SetPadBottomMargin(0.125);
 tdrStyle->SetPadLeftMargin(0.14);
 tdrStyle->SetPadRightMargin(0.1);
 tdrStyle->SetOptTitle(0);
 tdrStyle->SetTitleFont(42);
 tdrStyle->SetTitleColor(1);
 tdrStyle->SetTitleTextColor(1);
 tdrStyle->SetTitleFillColor(10);
 tdrStyle->SetTitleFontSize(0.05);
 tdrStyle->SetTitleH(0.045); 
 tdrStyle->SetTitleX(0.20); 
 tdrStyle->SetTitleY(1.0); 
 tdrStyle->SetTitleBorderSize(0);
 tdrStyle->SetTitleColor(1, "XYZ");
 tdrStyle->SetTitleFont(42, "XYZ");
 tdrStyle->SetTitleSize(0.06, "XYZ");
 tdrStyle->SetTitleXOffset(0.9);
 tdrStyle->SetTitleYOffset(1.05);
 tdrStyle->SetLabelColor(1, "XYZ");
 tdrStyle->SetLabelFont(42, "XYZ");
 tdrStyle->SetLabelOffset(0.007, "XYZ");
 tdrStyle->SetLabelSize(0.05, "XYZ");
 tdrStyle->SetAxisColor(1, "XYZ");
 tdrStyle->SetStripDecimals(kTRUE);
 tdrStyle->SetTickLength(0.03, "XYZ");
 tdrStyle->SetNdivisions(510, "XYZ");
 tdrStyle->SetPadTickX(0); 
 tdrStyle->SetPadTickY(0);
 tdrStyle->SetOptLogx(0);
 tdrStyle->SetOptLogy(0);
 tdrStyle->SetOptLogz(0);
 tdrStyle->cd();
///////////////// END CONFIG


char observable[20];
sprintf(observable, "%s",argv[1]);
char eftop[20];
sprintf(eftop, "%s",argv[2]);

char infile[100];
sprintf(infile, "likelihoodScan/%s/%s/LS_objects_k_%s.root",argv[2],argv[1],argv[2]);

TFile *f = TFile::Open(infile);
g= (TGraph*) f->Get("Graph;1");

TF1 *f1 = new TF1("f1",myfunc,-10,1000,0);

double y1=3.84, y2=1.0;

cout<<"1sigma Confidence Interval = ["<< f1->GetX(y2,-10,0)<< ";" <<f1->GetX(y2,0,10)<<"]"<<endl;
cout<<"2sigma Confidence Interval = ["<< f1->GetX(y1,-10,0)<<";"<<f1->GetX(y1,0,10)<<"]"<<endl;
cout<<"Likelihood Minimum ="<<f1->GetMinimumX(-10,10)<<endl; 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


TCanvas* c1 = new TCanvas("c1","c1",0,0,800,650);
TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.99);
c1_1->Draw();
c1_1->cd();
c1_1->SetTopMargin(0.1);
c1_1->SetBottomMargin(0.15);
c1_1->SetRightMargin(0.045);
c1_1->SetLeftMargin(0.15);

g->Draw();
f1->Draw("SAME");
f1->SetLineColor(kRed);
f1->SetLineWidth(2);
g->SetLineColor(kWhite);
g->SetMarkerColor(kWhite);

//-------------------------------------------------------------------

int nbins=g->GetXaxis()->GetNbins();
double down=g->GetXaxis()->GetBinLowEdge(1);
double up=g->GetXaxis()->GetBinUpEdge(nbins);

TLine *l = new TLine(down,1,up,1);
TLine *ll = new TLine(down,3.84,up,3.84);
l->SetLineStyle(kDashed);
l->SetLineColor(kGreen+2);
l->SetLineWidth(2);
ll->SetLineStyle(kDashed);
ll->SetLineColor(kOrange);
ll->SetLineWidth(2);

l->Draw("SAME");
ll->Draw("SAME");



g->GetXaxis()->SetTitleOffset(1.);
g->GetXaxis()->SetLabelSize(0.045);
g->GetXaxis()->SetTitleSize(0.06);
g->GetYaxis()->SetTitleOffset(1.2);
g->GetYaxis()->SetTitle("-2#DeltalnL");
g->GetXaxis()->SetTitle(eftop);
g->GetYaxis()->SetLabelSize(0.045);
g->GetYaxis()->SetTitleSize(0.06);

TLatex latexLabel;
latexLabel.SetTextSize(0.04);
latexLabel.SetNDC();
latexLabel.DrawLatex(0.16, 0.93, "CMS   L=100 fb^-1");

TLatex latexLabel2;
latexLabel2.SetNDC();
latexLabel2.SetTextSize(0.04);
latexLabel2.DrawLatex(0.85, 0.93, "13 TeV");

TLatex latexLabel3;
latexLabel3.SetTextSize(0.06);
latexLabel3.SetNDC();
latexLabel3.DrawLatex(0.16, 0.03, observable);

TLegend *leg = new TLegend(0.68, 0.75, 0.94, 0.89);
leg->SetShadowColor(1);
leg->SetBorderSize(1);
leg->SetTextSize(0.03);
leg->SetFillColor(0);
leg->AddEntry(f1, "Likelihood Scan",  "l");
leg->AddEntry(l, "1#sigma CL", "l");
leg->AddEntry(ll, "2#sigma CL", "l");
leg->Draw();

char outfile[100];
sprintf(outfile, "likelihoodScan/%s/allplots/LS_%s_%s.png",argv[2],argv[1],argv[2]);

c1->SaveAs(outfile);

int i=0;
return i;

}
