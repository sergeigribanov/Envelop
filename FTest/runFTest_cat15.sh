#
for var in ws_2016-17-18_ttHon0.26_2D_Data_15cat_20032020_woMjj_ptmjj0.5
do
ext=${var}_mgg
dir=${var} 
/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11,cat12,cat13,cat14 --isData 1 -c 15 --ismgg 1 &> fTestRes_${ext}.dat
eosdir=/eos/user/i/ivovtin/www/HHbbgg/fTest/${ext}
mkdir -p ${eosdir}
cp IVAN_${ext}/*png ${eosdir}
cp fTestRes_${ext}.dat ${eosdir}
cp /eos/user/i/ivovtin/www/tmp/index.php ${eosdir}

ext=${var}_mjj
/afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/user/i/ivovtin/HHggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D IVAN_${ext} -d IVAN_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11,cat12,cat13,cat14 --isData 1 -c 15 --ismgg 0 &> fTestRes_${ext}.dat
eosdir=/eos/user/i/ivovtin/www/HHbbgg/fTest/${ext}
mkdir -p ${eosdir}
cp IVAN_${ext}/*png ${eosdir}
cp fTestRes_${ext}.dat ${eosdir}
cp /eos/user/i/ivovtin/www/tmp/index.php ${eosdir}
done
