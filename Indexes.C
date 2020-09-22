void Indexes(TString path, TString MultidimFitFile = "higgsCombineTest.MultiDimFit.mH120.root"){
   TFile *f = new TFile(path+"/Node_SM/ws_hhbbgg.data_bkg_multipdf.root");
   RooWorkspace *w_bias = (RooWorkspace*)f->Get("w_bias");
   int NCAT=12;
   int max_ind[12];
   cout<<"max_ind = [";
   for(int i=0;i<NCAT;i++){
      cout<<((RooMultiPdf*)w_bias->pdf(Form("roomultipdf_cat%d",i)))->getNumPdfs();
      max_ind[i] = ((RooMultiPdf*)w_bias->pdf(Form("roomultipdf_cat%d",i)))->getNumPdfs();
      //if(i<11) cout<<",";}
      if(i<NCAT-1) cout<<",";}
   cout<<"]"<<endl;

   TFile *f2 = new TFile(path + "/" + MultidimFitFile.Data());
   TTree *tr = (TTree*)f2->Get("limit");
   tr->Draw("pdf_index_cat0:pdf_index_cat1:pdf_index_cat2:pdf_index_cat3:pdf_index_cat4:pdf_index_cat5:pdf_index_cat6:pdf_index_cat7:pdf_index_cat8:pdf_index_cat9:pdf_index_cat10:pdf_index_cat11","","PARA goff");
   //tr->Draw("pdf_index_cat0:pdf_index_cat1:pdf_index_cat2:pdf_index_cat3:pdf_index_cat4:pdf_index_cat5:pdf_index_cat6:pdf_index_cat7:pdf_index_cat8:pdf_index_cat9:pdf_index_cat10:pdf_index_cat11:pdf_index_cat12:pdf_index_cat13:pdf_index_cat14:pdf_index_cat15","","PARA goff");
   cout << "POINT 0" << endl;
   tr->Print();
   cout << "POINT 1" << endl;
   double tmpVar = (tr->GetVal(0))[0];
   cout << "POINT 2" << endl;
   double ind[12] = {
      (tr->GetVal(0))[0], (tr->GetVal(1))[0], (tr->GetVal(2))[0], (tr->GetVal(3))[0], (tr->GetVal(4))[0], (tr->GetVal(5))[0],
      (tr->GetVal(6))[0], (tr->GetVal(7))[0], (tr->GetVal(8))[0], (tr->GetVal(9))[0], (tr->GetVal(10))[0], (tr->GetVal(11))[0]};
   cout << "POINT 3" << endl;
   //double ind[16] = {
  //    (tr->GetVal(0))[0], (tr->GetVal(1))[0], (tr->GetVal(2))[0], (tr->GetVal(3))[0], (tr->GetVal(4))[0], (tr->GetVal(5))[0],
  //    (tr->GetVal(6))[0], (tr->GetVal(7))[0], (tr->GetVal(8))[0], (tr->GetVal(9))[0], (tr->GetVal(10))[0], (tr->GetVal(11))[0],
  //    (tr->GetVal(12))[0], (tr->GetVal(13))[0],(tr->GetVal(14))[0],(tr->GetVal(15))[0]
  // };
   cout<<"bestfit_ind = [";
   for(int i=0;i<NCAT;i++){
      cout<<ind[i];
      if(i<NCAT-1) cout<<",";
   }
   cout<<"]"<<endl;

   
   for(int i=0;i<NCAT;i++){
      TString st(((RooMultiPdf*)w_bias->pdf(Form("roomultipdf_cat%d",i)))->getPdf(ind[i])->GetName());     
//      cout<<st(st.Last('_')+1,st.Length()); // 1D case
      cout<<st(st.First('_')+1,9); // 2D case

      if(i<NCAT-1) cout<<" , ";
   }
   cout<<endl;
   int MaxInd = TMath::MaxElement(NCAT,max_ind);
   //cout<<"TString funcname[16]["<<MaxInd<<"]={"<<endl;   
   cout<<"TString funcname[12]["<<MaxInd<<"]={"<<endl;   
   for(int i=0;i<NCAT;i++){
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
      if(i<NCAT-1) cout<<" , ";
      cout<<endl;
   }
   cout<<" };"<<endl;

      
}
