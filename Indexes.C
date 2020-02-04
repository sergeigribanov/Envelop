void Indexes(TString path, TString MultidimFitFile = "higgsCombineTest.MultiDimFit.mH120.root"){
   TFile *f = new TFile(path+"/Node_SM/ws_hhbbgg.data_bkg_multipdf.root");
   RooWorkspace *w_bias = (RooWorkspace*)f->Get("w_bias");
   int max_ind[12];
   cout<<"max_ind = [";
   for(int i=0;i<12;i++){
      cout<<((RooMultiPdf*)w_bias->pdf(Form("roomultipdf_cat%d",i)))->getNumPdfs();
      max_ind[i] = ((RooMultiPdf*)w_bias->pdf(Form("roomultipdf_cat%d",i)))->getNumPdfs();
      if(i<11) cout<<",";}
   cout<<"]"<<endl;

   TFile *f2 = new TFile(MultidimFitFile.Data());
   TTree *tr = (TTree*)f2->Get("limit");
   tr->Draw("pdf_index_cat0:pdf_index_cat1:pdf_index_cat2:pdf_index_cat3:pdf_index_cat4:pdf_index_cat5:pdf_index_cat6:pdf_index_cat7:pdf_index_cat8:pdf_index_cat9:pdf_index_cat10:pdf_index_cat11","","PARA goff");
   double ind[12] = {
      (tr->GetVal(0))[0], (tr->GetVal(1))[0], (tr->GetVal(2))[0], (tr->GetVal(3))[0], (tr->GetVal(4))[0], (tr->GetVal(5))[0],
      (tr->GetVal(6))[0], (tr->GetVal(7))[0], (tr->GetVal(8))[0], (tr->GetVal(9))[0], (tr->GetVal(10))[0], (tr->GetVal(11))[0]
   };
   cout<<"bestfit_ind = [";
   for(int i=0;i<12;i++){
      cout<<ind[i];
      if(i<11) cout<<",";
   }
   cout<<"]"<<endl;

   
   for(int i=0;i<12;i++){
      TString st(((RooMultiPdf*)w_bias->pdf(Form("roomultipdf_cat%d",i)))->getPdf(ind[i])->GetName());     
//      cout<<st(st.Last('_')+1,st.Length()); // 1D case
      cout<<st(st.First('_')+1,9); // 2D case

      if(i<11) cout<<" , ";
   }
   cout<<endl;
   int MaxInd = TMath::MaxElement(12,max_ind);
   cout<<"TString funcname[12]["<<MaxInd<<"]={"<<endl;   
   for(int i=0;i<12;i++){
      cout<<"{ ";
      for(int j=0;j<MaxInd;j++){
	 TString st("");
	 if(j<max_ind[i]){	      
	    st = ((RooMultiPdf*)w_bias->pdf(Form("roomultipdf_cat%d",i)))->getPdf(j)->GetName();
	    st = st.ReplaceAll("bern","Ber");
	    st = st.ReplaceAll("exp","Exp");
	    st = st.ReplaceAll("pow","Pow");
	 }	 
	 else
	   st = "none";
//	 cout<<"\""<<st(st.Last('_')+1,st.Length())<<"\""; // 1D 
	 cout<<"\""<<st(st.First('_')+1,9)<<"\""; // 2D 
	 if(j<MaxInd-1) cout<<" , ";
      }
      cout<<" }";
      if(i<11) cout<<" , ";
      cout<<endl;
   }
   cout<<" };"<<endl;

      
}
