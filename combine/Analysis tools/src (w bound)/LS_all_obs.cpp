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

double down;
double up;

if(strcmp(argv[1],"cW")==0){
                           down=-0.6;
                           up=0.6;
                           }
else if(strcmp(argv[1],"cHW")==0){
                           down=-2.5;
                           up=2.5;
                           }
else if(strcmp(argv[1],"cHWB")==0){
                           down=-10;
                           up=10;
                           }
else if(strcmp(argv[1],"cHDD")==0){
                           down=-8;
                           up=10;
                           }
else if(strcmp(argv[1],"cHbox")==0){
                           down=-7;
                           up=10;
                           }
else if(strcmp(argv[1],"cWtil")==0){
                           down=-0.4;
                           up=0.4;
                           }
else if(strcmp(argv[1],"cHWtil")==0){
                           down=-4.3;
                           up=4.3;
                           }
else if(strcmp(argv[1],"cHWBtil")==0){
                           down=-10;
                           up=10;
                           }
else if(strcmp(argv[1],"cHq1")==0)
    { 
    up=2.5;
    down=-3;
    }
else if(strcmp(argv[1],"cHq3")==0)
    { 
    up=0.3;
    down=-0.35;
    }
else if(strcmp(argv[1],"cHl1")==0)
    { 
    up=10;
    down=-10;
    }
else if(strcmp(argv[1],"cHl3")==0)
    { 
    up=0.21;
    down=-0.21;
    }
  else if(strcmp(argv[1],"cqq1")==0)
    { 
    up=0.24;
    down=-0.18;
    }
   else if(strcmp(argv[1],"cqq3")==0)
    { 
    up=0.2;
    down=-0.07;
    }
 /*    else if(strcmp(argv[1],"cqq11")==0)
    { 
    up=;
    down=;
    }
    else if(strcmp(argv[1],"cqq31")==0)
    { 
    up=;
    down=;
    }
    else if(strcmp(argv[1],"cll")==0)
    { 
    up=;
    down=;
    } */
    else if(strcmp(argv[1],"cll1")==0)
    { 
    up=0.32;
    down=-0.32;
    }  

                           
/*---------------------------- Colors ----------------------------

(from worst to best confidence interval)

1- kMagenta
2- kViolet-5
3- kBlue+1
4- kAzure+9
5- kAzure+10
6- kTeal
7- kGreen+1
8- kGreen+2
9- kYellow
10- kOrange+1
11- kOrange+7
12- kRed solid line

*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char infile[100];
sprintf(infile, "likelihoodScan/mjj/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fa = TFile::Open(infile);
g= (TGraph*) fa->Get("Graph;1");
g->SetLineColor(kViolet-5);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->SetMarkerStyle(14);
g->SetMarkerColor(kViolet-5);
//g->Draw();

TF1 *f1 = new TF1("f1",myfunc,down,up,0);
f1->SetLineColor(kWhite);
f1->SetLineStyle(3);
f1->SetLineWidth(1);
f1->Draw();
g->Draw("SAME");

leg->AddEntry(g, "mjj",  "l");
fa->Close();
g->Clear();



//------------------------------------------------------------

sprintf(infile, "likelihoodScan/mll/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fb = TFile::Open(infile);
g= (TGraph*) fb->Get("Graph;1");

TF1 *f2 = new TF1("f2",myfunc,down,up,0);

g->SetLineColor(kGreen);
g->SetLineStyle(2);
g->SetLineWidth(1.5);  

// g->SetLineColor(kRed);
// g->SetLineStyle(kSolid);
// g->SetLineWidth(2);  

//g->Draw("SAME");


//leg->AddEntry(g, "mll",  "l");
fb->Close();

//--------------------

sprintf(infile, "likelihoodScan/Eta_l1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fc = TFile::Open(infile);
g= (TGraph*) fc->Get("Graph;1");

g->SetLineColor(kOrange+1);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f3 = new TF1("f3",myfunc,-down,up,0);


leg->AddEntry(g, "Eta_l1",  "l");
fc->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/Eta_l2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fd = TFile::Open(infile);
g= (TGraph*) fd->Get("Graph;1");
TF1 *f4 = new TF1("f4",myfunc,down,up,0);

   g->SetLineColor(kGreen+2);
   g->SetLineStyle(2);
   g->SetLineWidth(1.5);
     
//g->SetLineColor(kRed);
//g->SetLineStyle(kSolid);
//g->SetLineWidth(2);
    
g->SetMarkerColor(kWhite);
g->Draw("SAME");

leg->AddEntry(g, "Eta_l2",  "l");
fd->Close();
g->Clear();


//--------------------

sprintf(infile, "likelihoodScan/Eta_j1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *ff = TFile::Open(infile);
g= (TGraph*) ff->Get("Graph;1");
TF1 *f6 = new TF1("f6",myfunc,down,up,0);

     g->SetLineColor(kAzure+10);
     g->SetLineStyle(2);
     g->SetLineWidth(1.5);


g->Draw("SAME");

leg->AddEntry(g, "Eta_j1",  "l");
ff->Close();
g->Clear();


//--------------------

sprintf(infile, "likelihoodScan/Eta_j2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fv = TFile::Open(infile);
g= (TGraph*) fv->Get("Graph;1");
TF1 *f16 = new TF1("f6",myfunc,down,up,0);

    g->SetLineColor(kBlue+1);
    g->SetLineStyle(2);
    g->SetLineWidth(1.5);

//g->SetLineColor(kRed);
// g->SetLineStyle(kSolid);
// g->SetLineWidth(2);     

//g->Draw("SAME");

//leg->AddEntry(g, "Eta_j2",  "l");

fv->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/PT_l1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fg = TFile::Open(infile);
g= (TGraph*) fg->Get("Graph;1");

g->SetLineColor(kTeal);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
//g->Draw("SAME");

TF1 *f7 = new TF1("f7",myfunc,down,up,0);


//leg->AddEntry(g, "PT_l1",  "l");
fg->Close();
g->Clear();

//--------------------

sprintf(infile, "likelihoodScan/PT_l2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fh = TFile::Open(infile);
g= (TGraph*) fh->Get("Graph;1");

//g->SetLineColor(kRed);
//g->SetLineStyle(kSolid);
//g->SetLineWidth(2);

g->SetLineColor(kGreen+2);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
//g->Draw("SAME");

TF1 *f8 = new TF1("f8",myfunc,down,up,0);

//leg->AddEntry(g, "PT_l2",  "l");
fh->Close();
g->Clear();


//--------------------

sprintf(infile, "likelihoodScan/PT_j1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fl = TFile::Open(infile);
g= (TGraph*) fl->Get("Graph;1");

g->SetLineColor(kMagenta);
g->SetLineStyle(2);
g->SetLineWidth(1.5);

//g->SetLineColor(kRed);
//g->SetLineStyle(kSolid);
//g->SetLineWidth(2);

g->Draw("SAME");

TF1 *f10 = new TF1("f10",myfunc,down,up,0);

leg->AddEntry(g, "PT_j1",  "l");
fl->Close();
g->Clear(); 


//--------------------

sprintf(infile, "likelihoodScan/PT_j2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fz = TFile::Open(infile);
g= (TGraph*) fz->Get("Graph;1");

g->SetLineColor(kMagenta);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
//g->Draw("SAME");

TF1 *f13 = new TF1("f10",myfunc,down,up,0);

//leg->AddEntry(g, "PT_j2",  "l");
fz->Close();
g->Clear(); 


//--------------------

sprintf(infile, "likelihoodScan/deltaEtajj/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fm = TFile::Open(infile);
g= (TGraph*) fm->Get("Graph;1");

// g->SetLineColor(kRed);
// g->SetLineStyle(kSolid);
// g->SetLineWidth(2);

g->SetLineColor(kYellow);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f9 = new TF1("f9",myfunc,down,up,0);


leg->AddEntry(g, "#Delta #eta jj",  "l");
fm->Close();
g->Clear();  


//--------------------

sprintf(infile, "likelihoodScan/deltaPhijj/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fn = TFile::Open(infile);
g= (TGraph*) fn->Get("Graph;1");

// g->SetLineColor(kRed);
// g->SetLineStyle(kSolid);
// g->SetLineWidth(2);

g->SetLineColor(kTeal);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f11 = new TF1("f11",myfunc,down,up,0);


leg->AddEntry(g, "#Delta #Phi jj",  "l");
fn->Close();
g->Clear();  


//--------------------

sprintf(infile, "likelihoodScan/MET/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fo = TFile::Open(infile);
g= (TGraph*) fo->Get("Graph;1");

g->SetLineColor(kRed);
g->SetLineStyle(kSolid);
g->SetLineWidth(2);

//g->SetLineColor(kYellow);
//g->SetLineStyle(2);
//g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f12 = new TF1("f12",myfunc,down,up,0);


leg->AddEntry(g, "MET",  "l");
fo->Close();
g->Clear();  


//--------------------

sprintf(infile, "likelihoodScan/Mo1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *foo = TFile::Open(infile);
g= (TGraph*) foo->Get("Graph;1");

//g->SetLineColor(kRed);
//g->SetLineStyle(kSolid);
//g->SetLineWidth(2);

g->SetLineColor(kBlue+1);
g->SetLineStyle(2);
g->SetLineWidth(1.5);

g->Draw("SAME");

TF1 *f121 = new TF1("f121",myfunc,down,up,0);


leg->AddEntry(g, "Mo1",  "l");
foo->Close();
g->Clear();  

//--------------------

sprintf(infile, "likelihoodScan/M1T/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fooo = TFile::Open(infile);
g= (TGraph*) fooo->Get("Graph;1");

//g->SetLineColor(kRed);
// g->SetLineStyle(kSolid);
// g->SetLineWidth(2);

g->SetLineColor(kOrange+1);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
//g->Draw("SAME");

TF1 *f122 = new TF1("f122",myfunc,down,up,0);


//leg->AddEntry(g, "M1T",  "l");
fooo->Close();
g->Clear();  

//--------------------

sprintf(infile, "likelihoodScan/Zeppenfeld_12/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *foooo = TFile::Open(infile);
g= (TGraph*) foooo->Get("Graph;1");

//g->SetLineColor(kRed);
// g->SetLineStyle(kSolid);
// g->SetLineWidth(2);

g->SetLineColor(kViolet-5);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
//g->Draw("SAME");

TF1 *f123 = new TF1("f11",myfunc,down,up,0);


//leg->AddEntry(g, "Z_12",  "l");
foooo->Close();
g->Clear();  


//--------------------

sprintf(infile, "likelihoodScan/Zeppenfeld_1/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fooooh = TFile::Open(infile);
g= (TGraph*) fooooh->Get("Graph;1");

//g->SetLineColor(kRed);
// g->SetLineStyle(kSolid);
// g->SetLineWidth(2);

g->SetLineColor(kAzure+10);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
//g->Draw("SAME");

TF1 *f1233 = new TF1("f11",myfunc,down,up,0);

//leg->AddEntry(g, "Z_1",  "l");
fooooh->Close();
g->Clear();  


//--------------------

sprintf(infile, "likelihoodScan/Zeppenfeld_2/%s/LS_objects_k_%s.root",argv[1],argv[1]);

TFile *fooool = TFile::Open(infile);
g= (TGraph*) fooool->Get("Graph;1");

//g->SetLineColor(kRed);
// g->SetLineStyle(kSolid);
// g->SetLineWidth(2);

g->SetLineColor(kGreen);
g->SetLineStyle(2);
g->SetLineWidth(1.5);
g->Draw("SAME");

TF1 *f1231 = new TF1("f11",myfunc,down,up,0);

leg->AddEntry(g, "Z_2",  "l");
fooool->Close();
g->Clear();  

//~~~~~~~~~~~~~~~~~~ graphic settings for most sensitive observable ~~~~~~~~~~~~~~~~~~

 /*   g->SetLineColor(kRed);
      g->SetLineStyle(kSolid);
      g->SetLineWidth(2);    */

//~~~~~~~~~~~~~~~~~~~ AXIS SETTINGS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

f1->GetXaxis()->SetRangeUser(up,down);
f1->GetYaxis()->SetRangeUser(0,5);


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
