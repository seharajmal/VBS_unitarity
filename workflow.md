This set of instructions serves as a guide for "dummies" to reproduce everything is presented in the paper.
Here is a summary of Costanza's thesis to guide the whole work.



# Computation of helicity amplitudes in Mathematica


# MC simulation 
step 1: after producing gridpack in the genproductions/bin/Madgraph5_aMCatNLO or if you already have the gridpack you can copy it in this directory.

step 2: make directory and untar gridpack into that directory.

mkdir work

cd work

tar xf ../*.xz

step 3: assign vlaues to mentioned varaiables according to your need.

NEVENTS=10000
RANDOMSEED=12345
NCPU=1

step 4: run gridpack to produce LHE files

./runcmsgrid.sh $NEVENTS $RANDOMSEED $NCPU

detailed information is available here : https://twiki.cern.ch/twiki/bin/view/Main/CMSDAS2018_GEN_Draft


# From LHE to histograms


## Plotting tool
Inspired from [this prototype](https://github.com/acappati/mg5tut_apr21_plots).


# Statistical analysis
