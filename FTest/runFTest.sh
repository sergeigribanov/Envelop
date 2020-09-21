#
for var in ws_run2_ttHon0.26_2D_SM_ggHHonly_04062020
do
ext=${var}_mgg
dir=${var} 
/afs/cern.ch/user/s/segriban/test_Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/user/s/segriban/test_Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D SERGEI_${ext} -d SERGEI_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11 --isData 1 -c 12 --ismgg 1 &> fTestRes_${ext}.dat
eosdir=/afs/cern.ch/user/s/segriban/test_Hggbb/www/HHbbgg/fTest/${ext}
mkdir -p ${eosdir}
cp SERGEI_${ext}/*png ${eosdir}
cp fTestRes_${ext}.dat ${eosdir}
tail -n 48 fTestRes_${ext}.dat > fTestTmpRes_${ext}.dat
cp /afs/cern.ch/user/s/segriban/test_Hggbb/www/tmp/index.php ${eosdir}

ext=${var}_mjj
/afs/cern.ch/user/s/segriban/test_Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/flashggFinalFit/Background/bin/fTest -i /afs/cern.ch/user/s/segriban/test_Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D SERGEI_${ext} -d SERGEI_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11 --isData 1 -c 12 --ismgg 0 &> fTestRes_${ext}.dat
eosdir=/afs/cern.ch/user/s/segriban/test_Hggbb/www/HHbbgg/fTest/${ext}
mkdir -p ${eosdir}
cp SERGEI_${ext}/*png ${eosdir}
cp fTestRes_${ext}.dat ${eosdir}
tail -n 48 fTestRes_${ext}.dat > fTestTmpRes_${ext}.dat
cp /afs/cern.ch/user/s/segriban/test_Hggbb/www/tmp/index.php ${eosdir}
done

paste fTestTmpRes_${var}_mgg.dat fTestTmpRes_${var}_mjj.dat | ./parseDats.awk


#for var in std_2D_ttHoff std_2D_ttHon
#do
#ext0=2D_Y2_BS
#ext=${ext0}_${var}_mgg
#dir=${ext0}/ws_2016-17_${var} 
#./bin/fTest -i /afs/cern.ch/work/i/ivovtin/public/ForLeonid/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D SERGEI_${ext} -d SERGEI_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11 --isData 1 -c 12 --ismgg 1 &> fTestRes_${ext}.dat
#mkdir ${eosdir}
#cp SERGEI_${ext}/*png ${eosdir}
#cp fTestRes_${ext}.dat ${eosdir}
#cp /eos/user/l/lkardapo/www/tmp/index.php ${eosdir}
#
#ext=${ext0}_${var}_mjj
#./bin/fTest -i /afs/cern.ch/work/i/ivovtin/public/ForLeonid/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D SERGEI_${ext} -d SERGEI_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11 --isData 1 -c 12 --ismgg 0 &> fTestRes_${ext}.dat
#mkdir ${eosdir}
#cp SERGEI_${ext}/*png ${eosdir}
#cp fTestRes_${ext}.dat ${eosdir}
#cp /eos/user/l/lkardapo/www/tmp/index.php ${eosdir}
#done






#for var in new_1D_ttHoff new_1D_ttHon std_1D_ttHoff std_1D_ttHon
#do
#ext0=1D_Y3
#ext=${ext0}_${var}
#dir=${ext0}/ws_2016-17_${var} 
#./bin/fTest -i /afs/cern.ch/work/i/ivovtin/public/ForLeonid/${dir}/Node_SM/ws_hhbbgg.data_bkg.root --saveMultiPdf CMS-HGG_multipdf_${ext}.root  -D SERGEI_${ext} -d SERGEI_${ext}/res.dat -f cat0,cat1,cat2,cat3,cat4,cat5,cat6,cat7,cat8,cat9,cat10,cat11 --isData 1 -c 12 --ismgg 1 &> fTestRes_${ext}.dat
#eosdir=/eos/user/l/lkardapo/www/HHbbgg/fTest/${ext}
#mkdir ${eosdir}
#cp SERGEI_${ext}/*png ${eosdir}
#cp fTestRes_${ext}.dat ${eosdir}
#cp /eos/user/l/lkardapo/www/tmp/index.php ${eosdir}
#done
#
#
#
#
#
#
