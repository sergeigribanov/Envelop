max_ind=(9 9 9 9 9 9 12 15 9 9 15 18);
#max_ind=(3 3 3 3 3 3 4 3 3 3 4 5);
ext=ws_2016-17-18_ttHon0.26_2D_31012020

mkdir -p /eos/user/i/ivovtin/www/HHbbgg/envelope/${ext}
cp /eos/user/i/ivovtin/www/tmp/index.php /eos/user/i/ivovtin/www/HHbbgg/envelope/${ext}
for var in {0..11}
do
root -l -b -q 'envAllN.C+("'${ext}'",'$var','${max_ind[$var]}')'
done


#for var in {3..10}
#do
#root -l -b -q "SlicePicCorr.C+($var)"
#done
