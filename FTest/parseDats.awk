#!/usr/bin/awk -f 
BEGIN {print "#orders Ber_mgg Exp_mgg Pow_mgg Ber_mjj Exp_mjj Pow_mjj";
    i = 0}
/^Cat/{x=NR+3}(NR<=x){
    if (x == NR) {powMgg[i]=$3; powMjj[i]=$6; i++}
    else if (x == NR+3) {cutName[i]=sprintf("%s %d", tolower($1), $2)}
    else if (x == NR+2) {berMgg[i]=$3; berMjj[i]=$6}
    else if (x == NR+1) {expMgg[i]=$3; expMjj[i]=$6}}
END { for (j = 0; j < i; j++) {
	printf "%s: %d %d %d %d %d %d\n", cutName[j], berMgg[j], expMgg[j], powMgg[j],
	    berMjj[j], expMjj[j], powMjj[j]}}
