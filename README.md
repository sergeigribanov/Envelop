# FTest and functions for Envelop

Use this link to get Expected Limits package: https://github.com/ivovtin/bbggLimits2018/tree/run2_analysis  <br />

## Getting the code
Clone it locally:<br />
```
git clone https://github.com/[YOURNAME]/Envelop
```
## Using FTest
```
CMSSW_8_1_0 release
```
For FTest use this code: https://github.com/cms-analysis/flashggFinalFit/tree/topic-migrate-to-cmssw_747 <br />
In this directory replace the file fTest.cpp from the directory: flashggFinalFit/Background/test/ to the the same file from: https://github.com/ivovtin/Envelop/blob/master/FTest/fTest.cpp <br /> 
To comil the project go to flashggFinalFit/Background <br /> and type
```
make
```

1) To run FTest use:
```
./runFTest.sh 
```
2) Check fit plots from FTest. Results of the FTest will be stored at fTestRes_${ext}.dat file. <br />
4) While using bbggLimits2018 create a new workspace with orders received from the FTest. <br />

## Reducing the number of functions at the Envelop (important for 2D method)

```
CMSSW_10_2_13 release
```
Use this branch: https://github.com/ivovtin/HiggsAnalysis-CombinedLimit/tree/nckw_option_to_remove_const_offset from CombinedLimit <br />
1) Type:
```
./Indexes.sh ws_2016-17-18_ttHon0.26_2D_31012020
```
Then find a combination of functions that gives a minimum of NLL, array of maximum index values, and the array of indices with a combination of functions for Asimov, etc. <br />
2) Then rewrite all the results to submitSCAN.py and ScanStudy.C <br />
3) Run scanning:
```
./runScan.sh
```
4) Then run ScanStudy.C to do for minimization <br />
```
root -l -b -q 'ScanStudy.C+("ws_2016-17-18_ttHon0.26_2D_31012020")'
```
5) Check the output of the program by using
```
./job.sh
```
6)Put obtained functions to [Envelopejson](https://github.com/ivovtin/bbggLimits2018/blob/run2_analysis/jsonsForEnvelope/Env_json_2D_ttHon0.26_31012020.dat)<br />
