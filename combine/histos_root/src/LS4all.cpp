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


char eftop[20];
sprintf(eftop, "%s",argv[1]);

TCanvas* c1 = new TCanvas("c1","c1",0,0,800,650);
TPad *c1_1 = new TPad("c1_1", "newpad",0.01,0.01,0.99,0.99);
c1_1->Draw();
c1_1->cd();
c1_1->SetTopMargin(0.1);
c1_1->SetBottomMargin(0.15);
c1_1->SetRightMargin(0.045);
c1_1->SetLeftMargin(0.15);

TLegend *leg = new TLegend(0.68, 0.75, 0.94, 0.89);
leg->SetShadowColor(1);
leg->SetBorderSize(1);
leg->SetTextSize(0.02);
leg->SetFillColor(0);
leg->SetNColumns(2);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char infile[100];
sprintf(infile, "likelihoodScan/%s/mjj/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fa = TFile::Open(infile);
g= (TGraph*) fa->Get("Graph;1");

g->SetLineColor(kGreen+1);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->SetMarkerStyle(14);
g->SetMarkerColor(kGreen+1);
g->Draw();

TF1 *f1 = new TF1("f1",myfunc,-10,10,0);
f1->SetLineColor(kWhite);
f1->SetLineStyle(3);
f1->SetLineWidth(1);
f1->Draw("SAME");

leg->AddEntry(g, "mjj",  "l");
fa->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/%s/mll/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fb = TFile::Open(infile);
g= (TGraph*) fb->Get("Graph;1");
TF1 *f2 = new TF1("f2",myfunc,-10,10,0);

if(strcmp(argv[1],"cW")==0||strcmp(argv[1],"cWtil")==0||strcmp(argv[1],"cHW")==0||strcmp(argv[1],"cHWtil")==0||strcmp(argv[1],"cHbox")==0){
     g->SetLineColor(kRed);
     g->SetLineStyle(kSolid);
     g->SetLineWidth(2);
     }
else{
     g->SetLineColor(kGreen+2);
     g->SetLineStyle(2);
     g->SetLineWidth(1.5);
     }


g->Draw("SAME");

f2->SetLineWidth(2);
//f2->Draw("SAME");

leg->AddEntry(g, "mll",  "l");
fb->Close();

//--------------------

sprintf(infile, "likelihoodScan/%s/Eta_el/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fc = TFile::Open(infile);
g= (TGraph*) fc->Get("Graph;1");

g->SetLineColor(kViolet-9);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f3 = new TF1("f3",myfunc,-10,20,0);
f3->SetLineColor(kViolet-9);
f3->SetLineStyle(3);
f3->SetLineWidth(2);
//f3->Draw("SAME");

leg->AddEntry(g, "Eta_el",  "l");
fc->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/%s/Eta_mu/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fd = TFile::Open(infile);
g= (TGraph*) fd->Get("Graph;1");
TF1 *f4 = new TF1("f4",myfunc,-10,10,0);

if(strcmp(argv[1],"cHWB")==0){
     g->SetLineColor(kRed);
     g->SetLineStyle(kSolid);
     g->SetLineWidth(2);
     }
else{
     g->SetLineColor(kBlue);
     g->SetLineStyle(2);
     g->SetLineWidth(1.5);
     }

g->SetMarkerColor(kWhite);
g->Draw("SAME");

f4->SetLineWidth(2);
//f4->Draw("SAME");

leg->AddEntry(g, "Eta_mu",  "l");
fd->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/%s/Eta_ta/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fe = TFile::Open(infile);
g= (TGraph*) fe->Get("Graph;1");

g->SetLineColor(kMagenta);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f5 = new TF1("f5",myfunc,-10,10,0);
f5->SetLineColor(kMagenta);
f5->SetLineStyle(3);
f5->SetLineWidth(2);
//f5->Draw("SAME");

leg->AddEntry(g, "Eta_ta",  "l");
fe->Close();
g->Clear();


//--------------------

sprintf(infile, "likelihoodScan/%s/Eta_j/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *ff = TFile::Open(infile);
g= (TGraph*) ff->Get("Graph;1");
TF1 *f6 = new TF1("f6",myfunc,-10,10,0);

if(strcmp(argv[1],"cHDD")==0||strcmp(argv[1],"cHWBtil")==0){
     g->SetLineColor(kRed);
     g->SetLineStyle(kSolid);
     g->SetLineWidth(2);
     }
else{
     g->SetLineColor(kAzure+10);
     g->SetLineStyle(2);
     g->SetLineWidth(1.5);
     }

g->Draw("SAME");

f6->SetLineWidth(2);
//f6->Draw("SAME");

leg->AddEntry(g, "Eta_j",  "l");
ff->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/%s/PT_el/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fg = TFile::Open(infile);
g= (TGraph*) fg->Get("Graph;1");

g->SetLineColor(kOrange);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f7 = new TF1("f7",myfunc,-10,10,0);
f7->SetLineColor(kOrange);
f7->SetLineWidth(2);
f7->SetLineStyle(3);
//f7->Draw("SAME");

leg->AddEntry(g, "PT_el",  "l");
fg->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/%s/PT_mu/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fh = TFile::Open(infile);
g= (TGraph*) fh->Get("Graph;1");

g->SetLineColor(kRed);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f8 = new TF1("f8",myfunc,-10,10,0);
f8->SetLineColor(kRed);
f8->SetLineWidth(2);
f8->SetLineStyle(3);
//f8->Draw("SAME");

leg->AddEntry(g, "PT_mu",  "l");
fh->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/%s/PT_ta/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fi = TFile::Open(infile);
g= (TGraph*) fi->Get("Graph;1");

g->SetLineColor(kOrange-3);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f9 = new TF1("f9",myfunc,-10,10,0);
f9->SetLineColor(kOrange-3);
f9->SetLineWidth(2);
f9->SetLineStyle(3);
//f9->Draw("SAME");

leg->AddEntry(g, "PT_ta",  "l");
fi->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/%s/PT_j/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fl = TFile::Open(infile);
g= (TGraph*) fl->Get("Graph;1");
g->SetLineColor(kYellow);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f10 = new TF1("f10",myfunc,-10,10,0);
f10->SetLineColor(kYellow);
f10->SetLineWidth(2);
f10->SetLineStyle(3);
//f10->Draw("SAME");

leg->AddEntry(g, "PT_j",  "l");
fl->Close();
g->Clear();

//~~~~~~~~~~~~~~~~~~~ AXIS SETTINGS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


f1->GetXaxis()->SetTitleOffset(1.);
f1->GetXaxis()->SetLabelSize(0.045);
f1->GetXaxis()->SetTitleSize(0.06);
f1->GetYaxis()->SetTitleOffset(1.2);
f1->GetYaxis()->SetTitle("-2#DeltalnL");
f1->GetXaxis()->SetTitle(eftop);
f1->GetYaxis()->SetLabelSize(0.045);
f1->GetYaxis()->SetTitleSize(0.06);

TLatex latexLabel;
latexLabel.SetTextSize(0.04);
latexLabel.SetNDC();
latexLabel.DrawLatex(0.16, 0.93, "CMS   L=100 fb^-1");

TLatex latexLabel2;
latexLabel2.SetNDC();
latexLabel2.SetTextSize(0.04);
latexLabel2.DrawLatex(0.85, 0.93, "13 TeV");

//-------------------- CONFIDENCE LEVELS -------------------------------------------

double down;
double up;

if(strcmp(argv[1],"cW")==0)
    {
   down=-0.53;
   up=0.5;
    }
else if(strcmp(argv[1],"cHW")==0||strcmp(argv[1],"cHbox")==0)
    {
   down=-0.65;
   up=0.65;
    }
else if(strcmp(argv[1],"cHDD")==0)
    {
   down=-4.1;
   up=3.30;
    }    
else if(strcmp(argv[1],"cHWtil")==0)
    {
   down=-1.4;
   up=1.1;
    }
else if(strcmp(argv[1],"cHWB")==0)
    {
    down=-5;
    up=11.2;
    }
else if(strcmp(argv[1],"cHWBtil")==0)
    {
    down=-4;
    up=3.2;
    }
else if(strcmp(argv[1],"cWtil")==0)
    {
    down=-0.6;
    up=0.5;
    } 

TLine *l = new TLine(down,1,up,1);
TLine *ll = new TLine(down,3.84,up,3.84);
l->SetLineStyle(kSolid);
l->SetLineColor(kGreen+2);
l->SetLineWidth(1);
ll->SetLineStyle(kSolid);
ll->SetLineColor(kOrange);
ll->SetLineWidth(1);

l->Draw("SAME");
ll->Draw("SAME");

leg->AddEntry(l, "1#sigma CL", "l");
leg->AddEntry(ll, "2#sigma CL", "l");
leg->Draw();


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


char outfile[150];
strcpy(outfile,"likelihoodScan/allplots/All_LS_");
strcat(outfile,eftop);
strcat(outfile,".png");

c1->SaveAs(outfile);

int i=0;
return i;

}
