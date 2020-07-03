#!/bin/bash
#

#for var in new_ptmgg_ptmjj_dR_2D_ttHon_mjj80 new_ptmgg_ptmjj_dR_2D_ttHon_newbound new_ptmgg_ptmjj_dR_2D_ttHon_newbound_mjj80
for var in ws_run2_ggHHNLO_MjjReg_KL36
do
#python submitSCAN.py -n ${var} -o SCAN_${var} -d ${PWD}/WS_FROM_IVAN/ws_2016-17_${var} 
python submitSCAN.py -n ${var} -o SCAN_${var} -d /afs/cern.ch/work/i/ivovtin/Hggbb/CMSSW_8_1_0/src/HiggsAnalysis/bbggLimits2018/${var} 
done
