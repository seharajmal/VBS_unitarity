# Understanding EFTs

## Resources
- [master thesis](https://cds.cern.ch/record/2730137/files/CERN%20THESIS%202020%20109.pdf) of the ETH guy
- [Introduction to EFTs](https://arxiv.org/pdf/1804.05863.pdf), paper from a school in 2017 (see in partocular pp 74-81)
- [SMEFT@NLO](https://feynrules.irmp.ucl.ac.be/wiki/SMEFTatNLO), see ```definitions.pdf``` for the naming conventions
- [Eleni's presentation](https://indico.cern.ch/event/1018653/contributions/4627408/attachments/2357065/4022594/LHCHWG_SMEFT.pdf), useful to compare with the SMEFT@NLO naming convention table mentioned above
- other useful indications concerning operators choices can be found in Ilaria's [presentation](https://indico.cern.ch/event/1030068/contributions/4408848/attachments/2332266/3974824/Higgs2021_Brivio.pdf) and [slides](https://indico.cern.ch/event/1071746/contributions/4597086/attachments/2337957/3985238/hcomb_smeft_211102.pdf) from STXS guys
- [Jonathon's talk](https://indico.cern.ch/event/1133134/timetable/) at Higgs workshop + other [talk](https://indico.cern.ch/event/1154425/#b-459522-higgs-combination-and) from STXS guys 
- [The Higgs Width in the SMEFT](https://arxiv.org/pdf/1906.06949.pdf), paper mentioned by Ilaria for the parametrization of the Higgs width without having to simulate 
- [The Standard Model as an EFT](https://arxiv.org/pdf/1706.08945.pdf), paper by Ilaria
- [EFT Approach to LHC Data](https://arxiv.org/pdf/1505.00046.pdf), paper
- [Dimension 6 Terms in the SM Lagrangian](https://arxiv.org/pdf/1008.4884.pdf), paper
- [Modifications of the Properties of the Higgs Boson](https://arxiv.org/pdf/hep-ph/0601212.pdf), paper
- [SMEFTsim guide](https://arxiv.org/pdf/2012.11343.pdf)

# MC Simulation for EFT Studies

## MadGraph usage

### Resources:
- Ken Mimasu [tutorial](https://indico.cern.ch/event/1043867/contributions/4385917/attachments/2253894/3823970/smeftatnlo.pdf)
- Delphi [tutorial](https://twiki.cern.ch/twiki/bin/view/CMSPublic/MadgraphTutorial)
-  [long presentation](https://indico.cern.ch/event/555228/sessions/203428/attachments/1315471/1970459/tutorial-CMSandATLAS-2016.pdf) with tutorial found online
- another [2021 tutorial](https://indico.cern.ch/event/962610/?showDate=all&showSession=19) with details about grid pack
- [Youtube playlist](https://www.youtube.com/playlist?list=PLhkiT_RYTEU3rDXsSnEwpviJmU0xu4b8K) from a 2019 school

The main workflow consists in 

- process (where initial and final state particles are specified)
- output
- launch

Es:
```
import model HEL_UFO

# Definitions
define ell+ = e+ mu+ ta+
define ell- = e- mu- ta-
define j2 = g u c d s u~ c~ d~ s~

generate p p > h ell+ ell- / j2 ell+ ell- vl vl~ a h w+ w- NP<=1 @0                                                                                                                                                  
add process p p > h vl vl~ / j2 ell+ ell- vl vl~ a h w+ w- NP<=1 @1

output zh-HEL
```
this can be done either interactively (typing the commands in the session opened with ```bin/mg5_aMC```) or by saving the previous code in a card called e.g. ```proc_card.dat``` and running ```/bin/mg5_aMC proc_card.dat```.

In the interactive mode there are a few useful commands like e.g. ```display particles``` or ```display diagrams```, to run before the ```output ...``` command.

After running the output command, a directory ```zh-HEL``` is created. This contains:

- a ```Cards``` directory:
  - ```proc_card_mg5.dat```: commands used to generate the process folder
  - ```run_card.dat```: set up run parameters (e.g. CM energy, number of events, etc.)
  - ```param_card.dat```: model parameters (in e.g. the case of SMEFTatNLO it is from here that we are able to tweak the Wilson coefficients)
  - ```pythia8_card.dat```: controls the showering (**only at LO!!**), optional
  - ```madanalysis5_(parton|hadron)_card.dat```: analysis settings, optional

Now, from inside ```zh-HEL```, we can run ```bin/madevent``` and then ```launch name_chosen_for_run``` to launch the event generation. This creates a folder ```MyRun``` inside ```Events```, containing the results (an LHE file). This ```lhe``` file is human readable (xml) and contains the following main information:
- <header>: metadata
- <init>: sample information
- <event>: event weight (remember total cross section is proportional to the sum of the weights)
  - NB: the information inside this section usually contain, beside the weight, (E, px, py, pz) and PID 
  
Pythia can be used to decay particles (see details in the presentation)
  
Coupling Orders: they are used to specify the desired Feynman diagrams: for SM we have ```QCD``` and ```QED``` flags, for SMEFT (both SMEFTatNLO and SMEFTsim) we use NP for the order of lambda (the new physics scale).
  
### SMEFT@NLO ([link](http://feynrules.irmp.ucl.ac.be/wiki/SMEFTatNLO))

  UFO models are just Python modules that can be imported. They have to be placed inside the ```models``` directory in order to be seen and they are imported with e.g. ```import model SMEFTatNLO```. Restrictions cards can be written and placed inside the model folder; in this case, for a restriction card ```restrict_X.dat``` placed inside ```SMEFTatNLO```, we will import with ```import model SMEFTatNLO-X```.
  
  In SMEFT theory, many of the Wilson coefficients are not used, and the model we are testing don't even need them. In order to turn off parameters that we don't need, the best way consists in setting them to 0 inside the restriction card.
  
  **Reweight** ([link](https://cp3.irmp.ucl.ac.be/projects/madgraph/wiki/Reweight)): in some cases, it can be computaitonally more efficient to study interferences of EFT models with SM by following a procedure that consists in first producing a sample with SM and then reweight the events tuning the Wilson coefficients that we want to study.
  Let's explain it using the example from the tutorial:
  
  - first we create a restriction card where only the Wilson coefficients we want to run are different from 0 (ctG, ctu1, ctu8)
  - we then run the process generation with ```generate p p > t t~ QCD=2 QED=0 NP=2```
  - before running ```launch SM``` we tweak the datacard by setting these two parameters to 0, in order to generate a SM sample (without reweighting, we would simply leave the parameters tweaked in this way)
  - once we have our SM sample, we can create a ```reweight_card.dat``` inside ```ouput_directory/Cards``` from the already present ```reweight_card_default.dat``` and add the following lines to the first section
  ```
change process p p > t t~ QCD=2 QED=0 NP^2==2

launch --rwgt_name=SMxctG
set ctG 1.
set ctu1 0.
set ctu8 0.

launch --rwgt_name=SMxctu1
set ctG 0.
set ctu1 1.
set ctu8 0.

launch --rwgt_name=SMxctu8                                                                                                                                                                                           
set ctG 0.
set ctu1 0.
set ctu8 1.
  ```
- from inside ```bin/madevent``` we can then run ```reweight SM```
  
### NLO, for real
  Overall, the main thing worth noting is that NLO is applied when running ```generate ...``` by simply adding the flag ```[QCD]``` at the end. Tips and best practices are listed in [this presentation](https://indico.cern.ch/event/1043867/contributions/4385917/attachments/2253894/3847784/smeftatnlo_pt2.pdf).
  To launch the process, the binary to use is ```bin/aMCatNLO``` instead of ```bin/madevent```.
  

## EFT2Obs ([link](https://github.com/ajgilbert/EFT2Obs))
  
  - cherry-pick [this commit](https://github.com/simonepigazzini/EFT2Obs/commit/f7e24e808902ca1534d51b6fbf4be533803e4c0f) from Simone (just in case)
  - in master, refer to ```cards/ggF-SMEFTatNLO```; run ```cp setup/SMEFTatNLO__restrict_ggFshape.dat MG5_aMC_v2_6_7/models/SMEFTatNLO/restrict_ggFshape.dat```
  - run ```./scripts/setup_process_NLO.sh ggF-SMEFTatNLO```
  - proceeding with what is already in master:
      - ```./scripts/setup_process_NLO.sh ggF-SMEFTatNLO```: does not create any ```shower_card.dat```
      - ```python scripts/make_config.py -p ggF-SMEFTatNLO -o config_ggF.json --pars dim6:8 dim62f:19,24 --def-val 0.01 --def-sm 0.0 --def-gen 0.0```
      - ```python scripts/make_param_card.py -p ggF-SMEFTatNLO -c config_ggF.json -o cards/ggF-SMEFTatNLO/param_card.dat```
      - ```python scripts/make_reweight_card.py config_ggF.json cards/ggF-SMEFTatNLO/reweight_card.dat --prepend 'change mode NLO'```
      - ```./scripts/make_gridpack_NLO.sh ggF-SMEFTatNLO```: failes, since there is no shower card
  - final recipe to run ```ggF-SMEFTatNLO``` how it is already in master
      - copy the restrict card inside ```SMEFTatNLO```
      - ```./scripts/setup_process.sh ggF-SMEFTatNLO```
      - make config file: ```python scripts/make_config.py -p ggF-SMEFTatNLO -o config_ggF.json --pars dim6:8 dim62f:19,24 --def-val 0.01 --def-sm 0.0 --def-gen 0.0```
      - don't modify the run card, since the one in master is already fine
      - don't run the script to edit the param card, as the one in master is ok
      - prepend "change mode NLO" to the reweight card
      - ```./scripts/make_gridpack.sh ggF-SMEFTatNLO```
      - ```python scripts/run_gridpack.py --gridpack gridpack_ggF-SMEFTatNLO.tar.gz -s 1 -e 1000 -p Higgs2GGFiducialAndDifferential -o test-ggF-SMEFTatNLO``` (it uses Simone's plugin)
      - ```yodamerge -o test-ggF-SMEFTatNLO/Rivet.yoda test-ggF-SMEFTatNLO/Rivet_*```
      - ```python scripts/get_scaling.py -c config_ggF.json -i test-ggF-SMEFTatNLO/Rivet.yoda --hist "/Higgs2GGFiducialAndDifferential/pt_gg" --save json,txt,tex --translate-tex resources/translate_tex.json```
      - ```python scripts/makePlot.py --hist Higgs2GGFiducialAndDifferential_pt_gg.json -c config_ggF.json --x-title "p_{T}{H} [GeV]" --ratio 0.9,1.95 --draw cpg=0.005:2 ctp=0.005:4 ctg=0.005:12```
  
  ## Instructions to investigate decays
  
  ```bin/mg5_aMC```
  ```
  MG5_aMC>import model SMEFTatNLO-ggFshape
  MG5_aMC>generate p p > H QED=1 NP=0 [noborn=QCD]
  MG5_aMC>output ggF-decay
  ```
  ```cd ggF-decay```
  to run the NLO generation without decay, ```param_card``` and ```reweight_card``` and ```run_card``` can be copied from EFT2Obs
  
  ## LesHouches Files
  
  This weird file format seems to be explained [here](http://home.thep.lu.se/~torbjorn/preprints/cern0603.pdf).
  
  PDG index scheme for MC generators is reported [here](https://pdg.lbl.gov/2019/reviews/rpp2019-rev-monte-carlo-numbering.pdf).
  
 
