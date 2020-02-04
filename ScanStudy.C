#include "RooRealVar.h"
#include "RooGenericPdf.h"
#include "RooProdPdf.h"
#include "RooArgSet.h"
#include "RooDataSet.h"
#include "RooGaussModel.h"
#include "RooDecay.h"
#include "RooBMixDecay.h"
#include "RooCategory.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH2D.h"
#include "TIterator.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "RooAddPdf.h"
#include "RooPolynomial.h"
#include "RooWorkspace.h"
#include "TArrow.h"
#include "TStyle.h"
#include "TLine.h"
#include "TTree.h"
#include "TMath.h"
using namespace RooFit ;

void ScanStudy(TString ext){
   gStyle->SetOptStat(0);   
//   TFile *f = TFile::Open("/afs/cern.ch/user/l/lkardapo/WORK/HHggbb/2NEW/CMSSW_10_2_13/src/HiggsAnalysis/bbggLimits2018/WS2DN_ttH/Node_SM/ws_hhbbgg.data_bkg_multipdf.root");
//   RooWorkspace *w_all = (RooWorkspace *)f->Get("w_all");

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

   TTree *tr;
   TFile *ft;
   //int max_ind[12] = {9,9,9,9,9,9,12,12,12,9,12,15};  // FIXME
   int max_ind[12] = {9,9,9,9,9,9,12,15,9,9,15,18};  // FIXME
   for(int cat=0;cat<12;cat++){
      cout<<"cat "<<cat<<": "<<endl;
      double nll[40][max_ind[cat]];
      int minind[40];
      double minnll[40];
      for(int i=0;i<max_ind[cat];i++){	   
	 //ft = new TFile(Form("/afs/cern.ch/user/l/lkardapo/WORK/HHggbb/2NEW/CMSSW_10_2_13/src/HiggsAnalysis/bbggLimits2018/SCAN_"+ext+"/higgsCombinecat%dind%d.MultiDimFit.mH120.root",cat,i));
	 ft = new TFile(Form("/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_10_2_13/src/Envelop/SCAN_"+ext+"/higgsCombinecat%dind%d.MultiDimFit.mH120.root",cat,i));
	 tr = (TTree*)ft->Get("limit");
	 int N = tr->Draw("2*(deltaNLL+nll+nll0):r","Entry$>0","goff");
	 if(N!=40){
	    cout<<"!!!!!  N="<<N<<"  "<<funcname[i]<<Form("  higgsCombinecat%dind%d.MultiDimFit.mH120.root",cat,i)<<endl;
	    tr->Draw("2*(deltaNLL+nll+nll0):r","","goff");
	    for(int j=0;j<40;j++){		 
	       nll[j][i] = (tr->GetV1())[j];
	    }	    
	 }	 		 
	 else{	      
	    for(int j=0;j<40;j++)
	      nll[j][i] = (tr->GetV1())[j];
	 }	 
	 ft->Close();
//	 cout<<"file "<<i<<" is closed"<<endl;
//	 delete ft; delete tr;
//
      }
     
      for(int j=0;j<40;j++){
	 minind[j] = TMath::LocMin(max_ind[cat],nll[j]);
	 minnll[j] = TMath::MinElement(max_ind[cat],nll[j]);    
      }
     
      for (int i=0; i<40; i++){
	 int j;
	 for (j=0; j<i; j++)
	   if (minind[i] == minind[j])
	     break;
	 if (i == j){	      
//	   cout << minind[i] << " "<<funcname[minind[i]]<<endl;
	    cout <<funcname[cat][minind[i]];
	    if(funcname[cat][minind[i]].Length() < 5)
	      cout<<"_";
	    cout<<",";
	 }	 
      }
      cout<<endl;      
   }
   
}
