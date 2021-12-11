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

 using namespace std;
 
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
 

   char observable[20];
   sprintf(observable, "%s",argv[1]);
   char eftop[20];
   sprintf(eftop, "%s",argv[2]);
 
   
   const char *part1 = "_SMvsSM+";
   const char *part2 = "_";
   const char *part3 = "VBS_SSWW_SM_";
   const char *part4 = ".png";
   const char *part5 =  "SM_";
   
   
   char name[50];
   sprintf(name,"plots/%s_%s.png",argv[1],argv[2]);
   
   char legint[50];
   sprintf(legint, "%s lin",argv[2]);
   
   char legquad[50];
   sprintf(legquad, "%s quad",argv[2]);
   
   char legintquad[50];
   sprintf(legintquad, "SM + %s lin + quad",argv[2]);


//-------------------------------------------------------------------------------------
   
   TFile *f;
   TH1F *h1;
   TH1F *h2;
   TH1F *h3;
   TH1F *h4;
   
   TH1F *sub1;
   TH1F *sub2;
   TH1F *sub12;
  
    
   
   char infile[50];
   sprintf(infile, "histos4datacards/%s.root",argv[1]);

   char histint[100];
   sprintf(histint, "SR_inclusive_2017/VBS_SSWW_%s_int",argv[2]);

   char histquad[100];
   sprintf(histquad, "SR_inclusive_2017/VBS_SSWW_%s_quad",argv[2]);
   
   char histintquad[100];
   sprintf(histintquad, "SR_inclusive_2017/VBS_SSWW_SM_%s_int_quad",argv[2]);
  
   f = TFile::Open(infile);
   h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
   h1->Sumw2(); 
 //  double w1 = h1->Integral();
 //  h1->Scale(1./w1);

   h2 = (TH1F*) f->Get(histint);
   h2->Sumw2();
  // double w2 = h2->Integral();
  // h2->Scale(-1);

   h3 = (TH1F*) f->Get(histquad);
   h3->Sumw2();
  // double w3 = h3->Integral();
// h3->Scale(10);
   
   h4 = (TH1F*) f->Get(histintquad);
   h4->Sumw2();
  // double w4 = h4->Integral();
  // h4->Scale(1./w4);
   
   sub1 = (TH1F*) f->Get(histint);
   sub2 = (TH1F*) f->Get(histint);
   sub12 = (TH1F*) f->Get(histint);
   
   h1->SetLineColor(kYellow-10);
   h1->SetLineWidth(2);
   h1->SetFillColor(kYellow-10),
//   h1->SetFillStyle(3001);
   
   h2->SetLineColor(kGreen+1);
   h2->SetLineWidth(2);
   h2->SetLineStyle(kSolid);
   
   h3->SetLineColor(kAzure);
   h3->SetLineWidth(2);
   h3->SetLineStyle(kSolid);
   
   h4->SetLineColor(kRed);
   h4->SetLineWidth(3);
   
TCanvas* c1 = new TCanvas("c1","c1",0,0,800,650);
   
//--------------- FIRST PANEL -----------------

	TPad *c1_1 = new TPad("c1_1", "newpad",0.35,0.25,0.99,0.99);
	c1_1->Draw();
	c1_1->cd();
	c1_1->SetTopMargin(0.1);
	c1_1->SetBottomMargin(0.15);
	c1_1->SetRightMargin(0.045);
	c1_1->SetLeftMargin(0.15);
	
        h4->Draw("histo");
        h1->Draw("histsame");
        h2->Draw("histsame");
        h3->Draw("histsame");
        h4->Draw("histsame");
	
	
        h4->Paint("histo");
        h1->Paint("histsame");
        h2->Paint("histsame");
        h3->Paint("histsame");
        h4->Paint("histsame");
        
        h4->GetXaxis()->SetTitleOffset(1.2);
	h4->GetXaxis()->SetLabelSize(0.045);
	h4->GetXaxis()->SetTitleSize(0.05);
	h4->GetYaxis()->SetTitleOffset(1.4);
	h4->GetYaxis()->SetTitle("Normalized Events");
	
	h4->GetYaxis()->SetRangeUser(-10,2000);  
    //    c1_1->SetLogy();
	
	h4->GetYaxis()->SetLabelSize(0.045);
	h4->GetYaxis()->SetTitleSize(0.05);

        TLatex latexLabel;
	latexLabel.SetTextSize(0.04);
	latexLabel.SetNDC();
	latexLabel.DrawLatex(0.16, 0.93, "CMS   L=100 fb^{-1}");
	TLatex latexLabel2;
	latexLabel2.SetTextSize(0.04);

	latexLabel2.SetNDC();
	latexLabel2.DrawLatex(0.85, 0.93, "13 TeV");

 TLegend *leg = new TLegend(0.60, 0.75, 0.98, 0.89);
 leg->SetShadowColor(0);
 leg->SetBorderSize(1);
 leg->SetTextSize(0.03);
 leg->SetFillColor(0);
 leg->AddEntry(h1, "SM",  "f");
 leg->AddEntry(h2, legint, "l");
 leg->AddEntry(h3, legquad, "l");
 leg->AddEntry(h4, legintquad, "l");
 leg->Draw();
 c1_1->RedrawAxis();
 
cout << "step1" << endl;
c1_1->Closed();

//--------------- SECOND PANEL -----------------

	TPad *c1_2 = new TPad("c1_2", "newpad",0.35,0.10,0.99,0.22);
	c1_2->cd();
	c1_2->SetTopMargin(0.1);
	c1_2->SetBottomMargin(0.15);
	c1_2->SetRightMargin(0.045);
	c1_2->SetLeftMargin(0.15);
	
	double lin, quad, bsm, sm;
	
	cout << "step2" << endl;
	
	int nbins = h1->GetNbinsX();
	
	 cout << "step3" << endl;
	
	for(int j=0; j<=nbins; j++){
	                           sm = h1->GetBinContent(j);
	                           lin = h2->GetBinContent(j);
	                           quad = h3->GetBinContent(j); 
	                           bsm = h4->GetBinContent(j);
	                           
	                           if(sm!=0){sub1->SetBinContent(j,lin/sm);
	                                     sub2->SetBinContent(j,quad/sm);
	                                     sub12->SetBinContent(j,bsm/sm);}
	                           else{sub1->SetBinContent(j,0);
	                                sub2->SetBinContent(j,0);
	                                sub12->SetBinContent(j,0);}
	                           }
        
        cout << "step4" << endl;
                                                 
                                                 
        sub1->SetLineStyle(kSolid);
        sub1->SetLineColor(kGreen+1);
        sub1->SetLineWidth(2);
        sub1->SetFillStyle(0); 
	                            
	sub2->SetLineStyle(kSolid);
        sub2->SetLineColor(kAzure);
        sub2->SetLineWidth(2);
        sub2->SetFillStyle(0);   
        
        sub12->SetLineStyle(kSolid);
        sub12->SetLineColor(kRed);
        sub12->SetLineWidth(2);
        sub12->SetFillStyle(0); 
	
	sub1->GetYaxis()->SetRangeUser(-2,2);                            
	                            
	sub1->Draw("histo");
        sub2->Draw("histsame");
        sub12->Draw("histsame");
        
        sub1->Paint("histo");
        sub2->Paint("histsame");
        sub12->Paint("histsame");
        
        cout << "step5" << endl;
        
        sub1->GetXaxis()->SetTitleOffset(1.2);
	sub1->GetXaxis()->SetLabelSize(0.045);
	sub1->GetXaxis()->SetTitleSize(0.05);
	sub1->GetYaxis()->SetTitleOffset(1.4);
	
	char title[50];
        sprintf(title, "%s[GeV]",argv[1]);
	sub1->GetXaxis()->SetTitle(title);
	c1_2->Draw();

 c1->SaveAs(name);
 int i=0;
 return i;
}
