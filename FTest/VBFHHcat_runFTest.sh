#
for var in ws_run2_ggHHNLO_MjjReg_KL36
do
ext=${var}_mgg
dir=${var} 
##/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11 --isData 1 -c 12 --ismgg 1 &> fTestRes_${ext}.dat
##/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11,cat12 --isData 1 -c 13 --ismgg 1 &> fTestRes_${ext}.dat
/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11,cat12,cat13 --isData 1 -c 14 --ismgg 1 &> fTestRes_${ext}.dat
##/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11,cat12,cat13,cat14,cat15 --isData 1 -c 16 --ismgg 1 &> fTestRes_${ext}.dat
eosdir=/eos/user/i/ivovtin/www/HHbbgg/fTest/${ext}
mkdir -p ${eosdir}
cp IVAN_${ext}/*png ${eosdir}
cp fTestRes_${ext}.dat ${eosdir}
cp /eos/user/i/ivovtin/www/tmp/index.php ${eosdir}

ext=${var}_mjj
##/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11 --isData 1 -c 12 --ismgg 0 &> fTestRes_${ext}.dat
##/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11,cat12 --isData 1 -c 13 --ismgg 0 &> fTestRes_${ext}.dat
/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11,cat12,cat13 --isData 1 -c 14 --ismgg 0 &> fTestRes_${ext}.dat
##/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11,cat12,cat13,cat14,cat15 --isData 1 -c 16 --ismgg 0 &> fTestRes_${ext}.dat
eosdir=/eos/user/i/ivovtin/www/HHbbgg/fTest/${ext}
mkdir -p ${eosdir}
cp IVAN_${ext}/*png ${eosdir}
cp fTestRes_${ext}.dat ${eosdir}
cp /eos/user/i/ivovtin/www/tmp/index.php ${eosdir}
done
