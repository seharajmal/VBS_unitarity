#include <fstream>
#include <TH1F.h>
#include <TFile.h>
using namespace std;
int main(){

  TFile *f;
  TH1F *h1;
  TH1F *h0;
  double n1;
  double n0;

  fstream file;
  file.open("significanza.txt", fstream::out);
  
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CPC_operators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mjj_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/mjj.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mjj_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mjj_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWB_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mjj_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHbox_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mjj_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHDD_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mll_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/mll.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mll_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mll_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWB_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mll_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHbox_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mll_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHDD_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  file<<"\\begin{tabular}{ |p{2.2cm}|p{2.5cm}||p{2.2cm}|p{2.2cm}| }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{4}{|c|}{Significance for $m_{jj}$ and $m_{ll}$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Wilson coefficient&EFT contributions&$m_{jj}$&$m_{ll}$\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  &SM+lin&"<<mjj_cW_lin<<"&"<<mll_cW_lin<<"\\\\"<<endl;
  file<<"  $c_W$&SM+quad&"<<mjj_cW_quad<<"&"<<mll_cW_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<mjj_cW_lin_quad<<"&"<<mll_cW_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<mjj_cHW_lin<<"&"<<mll_cHW_lin<<"\\\\"<<endl;
  file<<"  $c_{HW}$&SM+quad&"<<mjj_cHW_quad<<"&"<<mll_cHW_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<mjj_cHW_lin_quad<<"&"<<mll_cHW_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<mjj_cHWB_lin<<"&"<<mll_cHWB_lin<<"\\\\"<<endl;
  file<<"  $c_{HWB}$&SM+quad&"<<mjj_cHWB_quad<<"&"<<mll_cHWB_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<mjj_cHWB_lin_quad<<"&"<<mll_cHWB_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<mjj_cHbox_lin<<"&"<<mll_cHbox_lin<<"\\\\"<<endl;
  file<<"  $c_{H\\square}$&SM+quad&"<<mjj_cHbox_quad<<"&"<<mll_cHbox_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<mjj_cHbox_lin_quad<<"&"<<mll_cHbox_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<mjj_cHDD_lin<<"&"<<mll_cHDD_lin<<"\\\\"<<endl;
  file<<"  $c_{HDD}$&SM+quad&"<<mjj_cHDD_quad<<"&"<<mll_cHDD_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<mjj_cHDD_lin_quad<<"&"<<mll_cHDD_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;

  file<<"\\end{tabular}"<<endl<<endl<<endl;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_el_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/PT_el.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_el_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_el_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWB_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_el_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHbox_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_el_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHDD_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_mu_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/PT_mu.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_mu_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_mu_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWB_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_mu_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHbox_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_mu_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHDD_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/PT_ta.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cW_quad = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWB_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHbox_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHDD_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_j_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/PT_j.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cW_quad = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_j_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_j_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWB_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_j_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHbox_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_j_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHDD_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  file<<"\\begin{tabular}{ |p{2.2cm}|p{2.5cm}||p{2.2cm}|p{2.2cm}|p{2.2cm}|p{2.2cm}|  }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{6}{|c|}{Significance for $p_T$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Wilson coefficient&EFT contributions&$p_T^{e}$&$p_T^{\\mu}$&$p_T^{\\tau}$&$p_T^j$\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  &SM+lin&"<<ptel_cW_lin<<"&"<<ptmu_cW_lin<<"&"<<ptta_cW_lin<<"&"<<ptj_cW_lin<<"\\\\"<<endl;
  file<<"  $c_W$&SM+quad&"<<ptel_cW_quad<<"&"<<ptmu_cW_quad<<"&"<<ptta_cW_quad<<"&"<<ptj_cW_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<ptel_cW_lin_quad<<"&"<<ptmu_cW_lin_quad<<"&"<<ptta_cW_lin_quad<<"&"<<ptj_cW_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<ptel_cHW_lin<<"&"<<ptmu_cHW_lin<<"&"<<ptta_cHW_lin<<"&"<<ptj_cHW_lin<<"\\\\"<<endl;
  file<<"  $c_{HW}$&SM+quad&"<<ptel_cHW_quad<<"&"<<ptmu_cHW_quad<<"&"<<ptta_cHW_quad<<"&"<<ptj_cHW_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<ptel_cHW_lin_quad<<"&"<<ptmu_cHW_lin_quad<<"&"<<ptta_cHW_lin_quad<<"&"<<ptj_cHW_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<ptel_cHWB_lin<<"&"<<ptmu_cHWB_lin<<"&"<<ptta_cHWB_lin<<"&"<<ptj_cHWB_lin<<"\\\\"<<endl;
  file<<"  $c_{HWB}$&SM+quad&"<<ptel_cHWB_quad<<"&"<<ptmu_cHWB_quad<<"&"<<ptta_cHWB_quad<<"&"<<ptj_cHWB_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<ptel_cHWB_lin_quad<<"&"<<ptmu_cHWB_lin_quad<<"&"<<ptta_cHWB_lin_quad<<"&"<<ptj_cHWB_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<ptel_cHbox_lin<<"&"<<ptmu_cHbox_lin<<"&"<<ptta_cHbox_lin<<"&"<<ptj_cHbox_lin<<"\\\\"<<endl;
  file<<"  $c_{H\\square}$&SM+quad&"<<ptel_cHbox_quad<<"&"<<ptmu_cHbox_quad<<"&"<<ptta_cHbox_quad<<"&"<<ptj_cHbox_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<ptel_cHbox_lin_quad<<"&"<<ptmu_cHbox_lin_quad<<"&"<<ptta_cHbox_lin_quad<<"&"<<ptj_cHbox_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<ptel_cHDD_lin<<"&"<<ptmu_cHDD_lin<<"&"<<ptta_cHDD_lin<<"&"<<ptj_cHDD_lin<<"\\\\"<<endl;
  file<<"  $c_{HDD}$&SM+quad&"<<ptel_cHDD_quad<<"&"<<ptmu_cHDD_quad<<"&"<<ptta_cHDD_quad<<"&"<<ptj_cHDD_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<ptel_cHDD_lin_quad<<"&"<<ptmu_cHDD_lin_quad<<"&"<<ptta_cHDD_lin_quad<<"&"<<ptj_cHDD_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;

  file<<"\\end{tabular}"<<endl<<endl<<endl;
  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_el_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/Eta_el.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_el_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_el_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWB_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_el_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHbox_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_el_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHDD_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_mu_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/Eta_mu.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_mu_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHW_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_mu_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWB_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_mu_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHbox_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_mu_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHDD_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_tau_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/Eta_ta.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cW_quad = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_tau_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_tau_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWB_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_tau_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHbox_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_tau_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHDD_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_j_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/Eta_j.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cW_lin =(n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cW_quad = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cW_lin_quad =(n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_j_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHW_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHW_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHW_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHW_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_j_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWB_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWB_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWB_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWB_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_j_cHbox~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHbox_lin = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHbox_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHbox_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHbox_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_j_cHDD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHDD_lin = (n1-n0)/sqrt(n0);
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHDD_quad = (n1-n0)/sqrt(n0);

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHDD_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHDD_lin_quad = (n1-n0)/sqrt(n0);
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  file<<"\\begin{tabular}{ |p{2.2cm}|p{2.5cm}||p{2.2cm}|p{2.2cm}|p{2.2cm}|p{2.2cm}|  }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{6}{|c|}{Significance for $\\eta$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Wilson coefficient&EFT contributions&$\\eta^{e}$&$\\eta^{\\mu}$&$\\eta^{\\tau}$&$\\eta^j$\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  &SM+lin&"<<etael_cW_lin<<"&"<<etamu_cW_lin<<"&"<<etata_cW_lin<<"&"<<etaj_cW_lin<<"\\\\"<<endl;
  file<<"  $c_W$&SM+quad&"<<etael_cW_quad<<"&"<<etamu_cW_quad<<"&"<<etata_cW_quad<<"&"<<etaj_cW_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<etael_cW_lin_quad<<"&"<<etamu_cW_lin_quad<<"&"<<etata_cW_lin_quad<<"&"<<etaj_cW_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<etael_cHW_lin<<"&"<<etamu_cHW_lin<<"&"<<etata_cHW_lin<<"&"<<etaj_cHW_lin<<"\\\\"<<endl;
  file<<"  $c_{HW}$&SM+quad&"<<etael_cHW_quad<<"&"<<etamu_cHW_quad<<"&"<<etata_cHW_quad<<"&"<<etaj_cHW_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<etael_cHW_lin_quad<<"&"<<etamu_cHW_lin_quad<<"&"<<etata_cHW_lin_quad<<"&"<<etaj_cHW_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<etael_cHWB_lin<<"&"<<etamu_cHWB_lin<<"&"<<etata_cHWB_lin<<"&"<<etaj_cHWB_lin<<"\\\\"<<endl;
  file<<"  $c_{HWB}$&SM+quad&"<<etael_cHWB_quad<<"&"<<etamu_cHWB_quad<<"&"<<etata_cHWB_quad<<"&"<<etaj_cHWB_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<etael_cHWB_lin_quad<<"&"<<etamu_cHWB_lin_quad<<"&"<<etata_cHWB_lin_quad<<"&"<<etaj_cHWB_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<etael_cHbox_lin<<"&"<<etamu_cHbox_lin<<"&"<<etata_cHbox_lin<<"&"<<etaj_cHbox_lin<<"\\\\"<<endl;
  file<<"  $c_{H\\square}$&SM+quad&"<<etael_cHbox_quad<<"&"<<etamu_cHbox_quad<<"&"<<etata_cHbox_quad<<"&"<<etaj_cHbox_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<etael_cHbox_lin_quad<<"&"<<etamu_cHbox_lin_quad<<"&"<<etata_cHbox_lin_quad<<"&"<<etaj_cHbox_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<etael_cHDD_lin<<"&"<<etamu_cHDD_lin<<"&"<<etata_cHDD_lin<<"&"<<etaj_cHDD_lin<<"\\\\"<<endl;
  file<<"  $c_{HDD}$&SM+quad&"<<etael_cHDD_quad<<"&"<<etamu_cHDD_quad<<"&"<<etata_cHDD_quad<<"&"<<etaj_cHDD_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<etael_cHDD_lin_quad<<"&"<<etamu_cHDD_lin_quad<<"&"<<etata_cHDD_lin_quad<<"&"<<etaj_cHDD_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;

  file<<"\\end{tabular}"<<endl<<endl<<endl;
  
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CPV_operators~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
/*  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mjj_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/mjj.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mjj_cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mjj_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mjj_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mll_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/mll.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mll_cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~mll_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double mll_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  file<<"\\begin{tabular}{ |p{2.2cm}|p{2.5cm}||p{2.2cm}|p{2.2cm}|p{2.2cm}|  }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{5}{|c|}{Significance for $m_{jj}$, $m_{ll}$ and $m_{lljj}$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Wilson coefficient&EFT contributions&$m_{jj}$&$m_{ll}$&$m_{lljj}$\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  &SM+lin&"<<mjj_cWtil_lin<<"&"<<mll_cWtil_lin<<"&-\\\\"<<endl;
  file<<"  $c_{\\tilde{W}}$&SM+quad&"<<mjj_cWtil_quad<<"&"<<mll_cWtil_quad<<"&-\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<mjj_cWtil_lin_quad<<"&"<<mll_cWtil_lin_quad<<"&-\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<mjj_cHWtil_lin<<"&"<<mll_cHWtil_lin<<"&-\\\\"<<endl;
  file<<"  $c_{H\\tilde{W}}$&SM+quad&"<<mjj_cHWtil_quad<<"&"<<mll_cHWtil_quad<<"&-\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<mjj_cHWtil_lin_quad<<"&"<<mll_cHWtil_lin_quad<<"&-\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<mjj_cHWBtil_lin<<"&"<<mll_cHWBtil_lin<<"&-\\\\"<<endl;
  file<<"  $c_{H\\tilde{W}B}$&SM+quad&"<<mjj_cHWBtil_quad<<"&"<<mll_cHWBtil_quad<<"&-\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<mjj_cHWBtil_lin_quad<<"&"<<mll_cHWBtil_lin_quad<<"&-\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;


  file<<"\\end{tabular}"<<endl<<endl<<endl;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_el_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/PT_el.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_el_cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_el_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptel_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_mu_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/PT_mu.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_mu_cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_mu_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptmu_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));  

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/PT_ta.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptta_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));    
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_j_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/PT_j.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_j_cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PT_tau_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double ptj_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0)); 
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  file<<"\\begin{tabular}{ |p{2.2cm}|p{2.5cm}||p{2.2cm}|p{2.2cm}|p{2.2cm}|p{2.2cm}|  }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{6}{|c|}{Significance for $p_T$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Wilson coefficient&EFT contributions&$p_T^{e}$&$p_T^{\\mu}$&$p_T^{\\tau}$&$p_T^j$\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  &SM+lin&"<<ptel_cWtil_lin<<"&"<<ptmu_cWtil_lin<<"&"<<ptta_cWtil_lin<<"&"<<ptj_cWtil_lin<<"\\\\"<<endl;
  file<<"  $c_{\\tilde{W}}$&SM+quad&"<<ptel_cW_quad<<"&"<<ptmu_cW_quad<<"&"<<ptta_cW_quad<<"&"<<ptj_cW_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<ptel_cW_lin_quad<<"&"<<ptmu_cW_lin_quad<<"&"<<ptta_cW_lin_quad<<"&"<<ptj_cW_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<ptel_cHWtil_lin<<"&"<<ptmu_cHWtil_lin<<"&"<<ptta_cHWtil_lin<<"&"<<ptj_cHWtil_lin<<"\\\\"<<endl;
  file<<"  $c_{H\\tilde{W}}$&SM+quad&"<<ptel_cHWtil_quad<<"&"<<ptmu_cHWtil_quad<<"&"<<ptta_cHWtil_quad<<"&"<<ptj_cHWtil_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<ptel_cHWtil_lin_quad<<"&"<<ptmu_cHWtil_lin_quad<<"&"<<ptta_cHWtil_lin_quad<<"&"<<ptj_cHWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<ptel_cHWBtil_lin<<"&"<<ptmu_cHWBtil_lin<<"&"<<ptta_cHWBtil_lin<<"&"<<ptj_cHWBtil_lin<<"\\\\"<<endl;
  file<<"  $c_{H\\tilde{W}B}$&SM+quad&"<<ptel_cHWBtil_quad<<"&"<<ptmu_cHWBtil_quad<<"&"<<ptta_cHWBtil_quad<<"&"<<ptj_cHWBtil_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<ptel_cHWBtil_lin_quad<<"&"<<ptmu_cHWBtil_lin_quad<<"&"<<ptta_cHWBtil_lin_quad<<"&"<<ptj_cHWBtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;

  file<<"\\end{tabular}"<<endl<<endl<<endl;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_el_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/Eta_el.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_el_cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_el_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etael_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_mu_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/Eta_mu.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_mu_cHWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_mu_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etamu_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_tau_cWtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/Eta_ta.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_tau_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_tau_cHWB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etata_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_j_cW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  f = TFile::Open("histos4datacards/Eta_j.root");
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_j_cHW~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eta_j_cHWBtil~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWBtil_lin = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWBtil_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

  h1 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM_cHWBtil_int_quad");
  h0 = (TH1F*) f->Get("SR_inclusive_2017/VBS_SSWW_SM");
  n1 = h1->Integral();
  n0 = h0->Integral();
  double etaj_cHWBtil_lin_quad = sqrt(2*n1*log(1+(n1-n0)/n0)-2*(n1-n0));

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  file<<"\\begin{tabular}{ |p{2.2cm}|p{2.5cm}||p{2.2cm}|p{2.2cm}|p{2.2cm}|p{2.2cm}|  }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{6}{|c|}{Significance for $\\eta$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Wilson coefficient&EFT contributions&$\\eta^{e}$&$\\eta^{\\mu}$&$\\eta^{\\tau}$&$\\eta^j$\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  &SM+lin&"<<etael_cWtil_lin<<"&"<<etamu_cWtil_lin<<"&"<<etata_cWtil_lin<<"&"<<etaj_cWtil_lin<<"\\\\"<<endl;
  file<<"  $c_{\\tilde{W}}$&SM+quad&"<<etael_cWtil_quad<<"&"<<etamu_cWtil_quad<<"&"<<etata_cWtil_quad<<"&"<<etaj_cWtil_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<etael_cWtil_lin_quad<<"&"<<etamu_cWtil_lin_quad<<"&"<<etata_cWtil_lin_quad<<"&"<<etaj_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<etael_cHWtil_lin<<"&"<<etamu_cHWtil_lin<<"&"<<etata_cHWtil_lin<<"&"<<etaj_cHWtil_lin<<"\\\\"<<endl;
  file<<"  $c_{H\\tilde{W}}$&SM+quad&"<<etael_cHWtil_quad<<"&"<<etamu_cHWtil_quad<<"&"<<etata_cHWtil_quad<<"&"<<etaj_cHWtil_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<etael_cHWtil_lin_quad<<"&"<<etamu_cHWtil_lin_quad<<"&"<<etata_cHWtil_lin_quad<<"&"<<etaj_cHWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"  &SM+lin&"<<etael_cHWBtil_lin<<"&"<<etamu_cHWBtil_lin<<"&"<<etata_cHWBtil_lin<<"&"<<etaj_cHWBtil_lin<<"\\\\"<<endl;
  file<<"  $c_{H\\tilde{W}B}$&SM+quad&"<<etael_cHWBtil_quad<<"&"<<etamu_cHWBtil_quad<<"&"<<etata_cHWBtil_quad<<"&"<<etaj_cHWBtil_quad<<"\\\\"<<endl;
  file<<"  &SM+lin+quad&"<<etael_cHWBtil_lin_quad<<"&"<<etamu_cHWBtil_lin_quad<<"&"<<etata_cHWBtil_lin_quad<<"&"<<etaj_cHWBtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"\\end{tabular}"<<endl<<endl<<endl;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"cW vs cWtil"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Etas~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  file<<"  \\begin{tabular}{ |p{2.2cm}||p{2.2cm}|p{2.2cm}|  }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{3}{|c|}{Significance for $\\eta$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Observable&$c_{\\tilde{W}}$&$c_W$&\\\\"<<endl;
  file<<"  &$SM+lin+quad$&$SM+lin+quad$&\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $\\eta^{e}$&$SM+lin$&"<<etael_cW_lin_quad<<"&"<<etael_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $\\eta^{\\mu}$&SM+quad&"<<etamu_cW_lin_quad<<"&"<<etamu_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $\\eta^{\\tau}$&SM+lin+quad&"<<etata_cW_lin_quad<<"&"<<etata_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $\\eta^j$&SM+lin+quad&"<<etaj_cW_lin_quad<<"&"<<etaj_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"\\end{tabular}"<<endl<<endl<<endl;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PTs~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


  file<<"  \\begin{tabular}{ |p{2.2cm}||p{2.2cm}|p{2.2cm}|  }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{3}{|c|}{Significance for $p_T$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Observable&$c_{\\tilde{W}}$&$c_W$&\\\\"<<endl;
  file<<"  &$SM+lin+quad$&$SM+lin+quad$&\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $p_T^{e}$&$SM+lin$&"<<ptel_cW_lin_quad<<"&"<<ptel_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $p_T^{\\mu}$&SM+quad&"<<ptmu_cW_lin_quad<<"&"<<ptmu_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $p_T^{\\tau}$&SM+lin+quad&"<<ptta_cW_lin_quad<<"&"<<ptta_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $p_T^j$&SM+lin+quad&"<<ptj_cW_lin_quad<<"&"<<ptj_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"\\end{tabular}"<<endl<<endl<<endl;
  
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~invariant masses~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  file<<"  \\begin{tabular}{ |p{2.2cm}||p{2.2cm}|p{2.2cm}|  }"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  \\multicolumn{3}{|c|}{Significance for $m_{ll}$ and $m_{jj}$ distributions ($\\sigma$)}\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
	
  file<<"  Observable&$c_{\\tilde{W}}$&$c_W$&\\\\"<<endl;
  file<<"  &$SM+lin+quad$&$SM+lin+quad$&\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $m_{ll}$&$SM+lin$&"<<mll_cW_lin_quad<<"&"<<mll_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl;
  file<<"  $m_{jj}$&SM+quad&"<<mjj_cW_lin_quad<<"&"<<mjj_cWtil_lin_quad<<"\\\\"<<endl;
  file<<"  \\hline"<<endl<<endl;
  
  file<<"\\end{tabular}"<<endl<<endl<<endl;
*/
  
  file.close();
  
}
  
  

