#include "TFile.h"
#include "TDirectory.h"
#include "TTree.h"
#include "TChain.h"
#include "TH2D.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TLegend.h"
#include "TF1.h"
#include "TString.h"
#include "TFitResult.h"
#include "TFitResultPtr.h"
#include "TMath.h"
#include "TLine.h"
#include "TGraph.h"

#include <iostream>

void envAllN(TString ext,int cat, int N){
   float rr = 0.25;
   float epsilon = 0.02;

   
   gROOT->SetStyle("Plain");
   gStyle->SetOptStat(0);
   gStyle->SetGridStyle(2);
   gStyle->SetGridWidth(2);
   gStyle->SetGridColor(kGray);
   
   TChain* trall = new TChain("trall","");
   trall->Add(Form("/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_10_2_13/src/Envelop/SCAN_"+ext+"/higgsCombinecat%dindAll.MultiDimFit.mH120.root/limit",cat));

   TChain* tr0 = new TChain("tr0","tr0");
   TChain* tr[N];
   for(int i=0;i<N;i++){
      tr[i] = new TChain("tr","tr");
      tr[i]->Add(Form("/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_10_2_13/src/Envelop/SCAN_"+ext+"/higgsCombinecat%dind%d.MultiDimFit.mH120.root/limit",cat,i));
   }
   
   float dNLL,r; double NLL,NLL_0; int ind;
//   float dNLL,r; double NLL,NLL_0;

   trall->SetBranchAddress("deltaNLL",&dNLL);
   trall->SetBranchAddress("nll",&NLL);
   trall->SetBranchAddress("nll0",&NLL_0);
   trall->SetBranchAddress("r",&r);
   trall->SetBranchAddress(Form("pdf_index_cat%d",cat),&ind);

   for(int i=0;i<N;i++){
      tr[i]->SetBranchAddress("deltaNLL",&dNLL);
      tr[i]->SetBranchAddress("nll",&NLL);
      tr[i]->SetBranchAddress("nll0",&NLL_0);
      tr[i]->SetBranchAddress("r",&r);
   }
   
   TGraph * grall = new TGraph(1);
   TGraph * grI = new TGraph(1);
   
   TGraph *gr[N];
   for(int i=0;i<N;i++)
     gr[i] = new TGraph(1);

   grall->GetXaxis()->SetLabelSize(0);
   grall->GetXaxis()->SetTickSize(0);   
   
   grI->SetTitle(";r;index         ");
   grI->SetMinimum(0.);
   grI->SetMaximum((float)N+0.5);   
   grI->GetYaxis()->SetNdivisions(4);
   grI->GetYaxis()->SetLabelSize(0.04*(1-rr)/rr);
   grI->GetXaxis()->SetLabelSize(0.04*(1-rr)/rr);
   grI->GetXaxis()->SetTitleSize(0.04*(1-rr)/rr);
   grI->GetYaxis()->SetTitleSize(0.04*(1-rr)/rr);
   grI->GetYaxis()->SetTitleOffset(0.3);
   grI->GetXaxis()->SetTitleOffset(1.0);
   grI->GetXaxis()->SetLabelOffset(0.03);
   
   grall->SetLineColor(13);
   grall->SetLineWidth(4);

   int color[10] = {kRed,kGreen,kBlue,kYellow,kViolet,kBlack,kGreen+3,kCyan,kPink-6,kViolet+7}; 
   int style[10] = {10,9,8,7,6,5,4,3,2,1}; 
   for(int i=0;i<N;i++){	
      gr[i]->SetLineColor(color[i%10]);
      gr[i]->SetLineWidth(2);
      gr[i]->SetLineStyle(style[i/10]);
      
   }
   grI->SetMarkerStyle(20);   
   grall->SetTitle(Form("Envelope study, category %d;;#Delta 2*NLL",cat));

   int cur_ind = -1;
   double minNLL[40][N];
   double grAll_min=1e5, grAll_max=-1e5;
   int scorNLL[N];
   for(int i=0;i<=N;i++) scorNLL[i]=0;
   int min_ind[N];
   int N_skipAll=0;
   int N_skip[N];
   for(int i=0;i<=N;i++) N_skip[i]=0;

   for(int i=1;i<=40;i++){
//      if(ind !=0 && in){
//	 
//      }

      trall->GetEntry(i);
      double minNLL0 = -1e5;
      if(dNLL+NLL+NLL_0>1e5)
	N_skipAll++;
      else{	   
	 grall->SetPoint(i-1-N_skipAll,r,2*(dNLL+NLL+NLL_0));
	 minNLL0 = 2*(dNLL+NLL+NLL_0);
	 if(2*(dNLL+NLL+NLL_0)>grAll_max) grAll_max = 2*(dNLL+NLL+NLL_0);
	 if(2*(dNLL+NLL+NLL_0)<grAll_min) grAll_min = 2*(dNLL+NLL+NLL_0);
      }      
      for(int j=0;j<N;j++){
	 tr[j]->GetEntry(i);
	 if(dNLL+NLL+NLL_0>1e5){	      
	    N_skip[j]++;
	    minNLL[i-1][j]=1e5;
	 }	 
	 else{	      
	    gr[j]->SetPoint(i-1-N_skip[j],r,2*(dNLL+NLL+NLL_0));
	    minNLL[i-1][j] = 2*(dNLL+NLL+NLL_0) - minNLL0;
	 }	 
      }
      grI->SetPoint(i-1,r,ind);

      TMath::Sort(N,minNLL[i-1],min_ind,false);
      scorNLL[ind]+=100;
      for(int j=0;j<TMath::Min(N,5);j++)
	scorNLL[min_ind[j]]+=(TMath::Min(N,5)-j);
   }

   TH2D *haxI = new TH2D("haxI",Form("Envelope study, category %d;;#Delta 2*NLL",cat),10,-1.2,4.2,10,-0.05*N,N*1.05);
   haxI->SetTitle(";r;index         ");
   haxI->SetMinimum(0.);
   haxI->SetMaximum((float)N+0.5);   
   haxI->GetYaxis()->SetNdivisions(4);
   haxI->GetYaxis()->SetLabelSize(0.04*(1-rr)/rr);
   haxI->GetXaxis()->SetLabelSize(0.04*(1-rr)/rr);
   haxI->GetXaxis()->SetTitleSize(0.04*(1-rr)/rr);
   haxI->GetYaxis()->SetTitleSize(0.04*(1-rr)/rr);
   haxI->GetYaxis()->SetTitleOffset(0.3);
   haxI->GetXaxis()->SetTitleOffset(1.0);
   haxI->GetXaxis()->SetLabelOffset(0.03);
   
//   TCanvas * c1 = new TCanvas("c1","c1",1200,900);
   TCanvas cc("cc","cc",1200,900);
   cc.Range(0,0,1,1);

   TPad PadBot("PadBoy", "tp_PadTop", 0., 0., 1., rr*(1-epsilon) );
   PadBot.cd();
   gPad->SetTicky();
   gPad->SetGridx();
   gPad->SetGridy();
   
   PadBot.SetTopMargin(0);
   PadBot.SetBottomMargin(0.3);

   haxI->Draw("axis");
   grI->Draw("p");
   cc.cd();
   PadBot.Draw();

   
   TPad PadTop("PadTop", "tp_PadTop", 0., rr-epsilon, 1., 1.);
   PadTop.cd();
   gPad->SetTickx();
   gPad->SetTicky();
   gPad->SetGridx();
   gPad->SetGridy();
   
   PadTop.SetBottomMargin(epsilon);
      
   double min = grAll_min-0.1*(grAll_max-grAll_min);
   double max = grAll_max+0.7*(grAll_max-grAll_min);

   
   TH2D *hax = new TH2D("hax",Form("NLL scan, category %d;;2 #Delta NLL",cat),10,-1.2,4.2,10,min,max);
   hax->GetXaxis()->SetLabelSize(0);
   hax->GetXaxis()->SetTickSize(0);   

   hax->Draw("axis");
   grall->Draw("l same");
   
   for(int j=0;j<N;j++)
     gr[j]->Draw("l same");      
   
//   gr1->Print();
/*   TString funcname[12][5]={
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Ber2" , "Exp1" , "Pow1" , "none" } , 
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Exp1" , "Pow1" , "none" , "none" } , 
     { "Ber1" , "Ber2" , "Exp1" , "Pow1" , "none" } , 
     { "Ber1" , "Ber2" , "Ber3" , "Exp1" , "Pow1" }
   };

*/

TString funcname[12][18]={
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Ber2_Ber1" , "Ber2_Exp1" , "Ber2_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Ber2_Ber1" , "Ber2_Exp1" , "Ber2_Pow1" , "Ber3_Ber1" , "Ber3_Exp1" , "Ber3_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Ber2_Ber1" , "Ber2_Exp1" , "Ber2_Pow1" , "Ber3_Ber1" , "Ber3_Exp1" , "Ber3_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" , "none" , "none" , "none" } , 
{ "Ber1_Ber1" , "Ber1_Exp1" , "Ber1_Pow1" , "Ber2_Ber1" , "Ber2_Exp1" , "Ber2_Pow1" , "Ber3_Ber1" , "Ber3_Exp1" , "Ber3_Pow1" , "Ber4_Ber1" , "Ber4_Exp1" , "Ber4_Pow1" , "Exp1_Ber1" , "Exp1_Exp1" , "Exp1_Pow1" , "Pow1_Ber1" , "Pow1_Exp1" , "Pow1_Pow1" }
 };

   TMath::Sort(N,scorNLL,min_ind);
   TLegend* leg = new TLegend (0.12,0.52,0.55,0.89);
   leg->SetBorderSize(0);
   leg->AddEntry(grall,"index is free","l");
   for(int j=0;j<TMath::Min(N,5);j++)
     leg->AddEntry(gr[min_ind[j]],Form("ind=%d, ",min_ind[j])+funcname[cat][min_ind[j]],"l");
//   leg->AddEntry(gr0,"index = 0","l");
//   leg->AddEntry(gr1,"index = 1","l");
//   leg->AddEntry(gr2,"index = 2","l");
   
   leg->Draw();
   cc.cd();
   PadTop.Draw();	

//   for(int i=0;i<N;i++){
//      cout<<"scorNLL["<<i<<"] = "<<scorNLL[i]<<endl;
//   }
   
   cc.SaveAs(Form("/eos/user/i/ivovtin/www/HHbbgg/envelope/"+ext+"/NLLscan_cat%d.png",cat));
}
