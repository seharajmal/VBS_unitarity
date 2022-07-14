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
  
  # Get Parametrization for Interpretation
  
  In order to get the SMEFT model to fit in the interpretation part, we proceed like follows:
  
  - the production part (ggF + 0, 1, 2 jets) can be obtained at NLO using the tools provided and explained [here](https://github.com/ajgilbert/EFT2Obs/blob/ggH-example/docs/HiggsGluonFusion.md)
  - for what concerns the decay part, at the moment we agreed with Simone to get all the decays at LO except Hgammagamma; this way we can use the cards provided by Jonathon and translate the parametrizations obtained from SMEFTsim to SMEFTatNLO using the table available [here](https://arxiv.org/pdf/2012.11343.pdf).
  
  Example for one of Jonathon's cards:
  
  ```source env.sh```
  
  ```./scripts/setup_process.sh H_4j_SMEFT```
  
  ```python scripts/make_config.py -p H_4j_SMEFT -o config_H_4j_SMEFT.json --pars frblock:24,25,26,28,30,32,39,45,46,47,48,49,50,51,54 --def-val 0.01 --def-sm 0 --def-gen 1E-8 --set-inactive frblock:18=1.000000e+03```
  
  ```python scripts/make_reweight_card.py config_H_4j_SMEFT.json cards/H_4j_SMEFT/reweight_card.dat```
  
  ```./scripts/make_gridpack.sh H_4j_SMEFT```
  
  Worked for H-> mu mu
  
  ```./scripts/setup_process.sh H_mumu_SMEFT```
  
  ```python scripts/make_config.py -p H_mumu_SMEFT -o config_SMEFTsim.json --pars frblock:24,25,26,28,30,32,39,45,46,47,48,49,50,51,54 --def-val 0.01 --def-sm 0 --def-gen 1E-8 --set-inactive frblock:18=1.000000e+03```
  
  ```./scripts/make_gridpack.sh H_mumu_SMEFT```
  
  ```export HIGGSPRODMODE=GGF```
  
  ```python scripts/run_gridpack.py --gridpack gridpack_H_mumu_SMEFT.tar.gz -s 1 -e 500 --rivet-ignore-beams -p HiggsDecays -o test-mumu-decay```
  
  ```python scripts/get_scaling.py -c config_SMEFTsim.json -i test-mumu-decay/Rivet_1.yoda --hist "/HiggsDecays/sumWeights" --save txt```
  
  ## Decays @ NLO
  
  ### Haa
  
  remember the custom restrict card based on Simone's one
  
  ```./scripts/setup_process.sh H_aa_SMEFTatNLO```
  
  ```param_card.dat``` has to be copied in the proper place
  
  ```python scripts/make_config.py -p H_aa_SMEFTatNLO -o config_H_aa_SMEFTatNLO.json --pars dim6:2,3,4,5,6,8,9,10 --def-val 0.01 --def-sm 0 --def-gen 1E-8 --set-inactive dim6:1=1.000000e+03```
  
  ```python scripts/make_reweight_card.py config_H_aa_SMEFTatNLO.json cards/H_aa_SMEFTatNLO/reweight_card.dat```
  
  ```./scripts/make_gridpack.sh H_aa_SMEFTatNLO```
  
  ```python scripts/run_gridpack.py --gridpack gridpack_H_aa_SMEFTatNLO.tar.gz -s 1 -e 500 --rivet-ignore-beams -p HiggsDecays -o test-aa-decay```
  
  ```python scripts/get_scaling.py -c config_H_aa_SMEFTatNLO.json -i test-aa-decay/Rivet_1.yoda --hist "/HiggsDecays/sumW" --save txt```
  
  ## Do Something Meaningful
  
  On 15/11 it was decided to produce a simple prorotype of signal sample for H->aa, in order to have something kind of meaningful (not final though) and be able to move to the step of inserting the model in CombineShit.
  
  The idea consists in the following:
  - use 5 parameters (putting together the default ones used by Andrew and the ones studied by the master student): 
    - SMEFT@NLO: cpG, ctp, ctG, cpBB, cpt
  - production: use Andrew instructions for ggF-0jets, hopefully for loop, tree and loop+tree; the Rivet routines, since we're doing it for H->aa, are Simone's ones
  - decay: we will use Jonathon's cards for all the decays except H->aa (SMEFTsim); H->aa will be instead done with SMEFTatNLO; parameters name when producing the parametrization will then have to be translated
  
  ### Production commands
  
  As example we take the 0jets loop case, referring to [this](https://github.com/maxgalli/EFT2Obs/tree/WithHiggsDecay/cards/ggF-SMEFTatNLO-0jet-loop-5pars) folder.
  
  ```./scripts/setup_process.sh ggF-SMEFTatNLO-0jet-loop-5pars```
  
  then it will probably be necessary to run: ```cp MG5_aMC_v2_6_7/ggF-SMEFTatNLO-0jet-loop-3pars/Cards/param_card.dat cards/ggF-SMEFTatNLO-0jet-loop-3pars```
  
  make config file: ```python scripts/make_config.py -p ggF-SMEFTatNLO-0jet-loop-5params -o config_SMEFTatNLO_ggFshape5params.json --pars dim6:8,10 dim62f:15,19,24 --def-val 0.01 --def-sm 0 --def-gen 1E-8 --set-inactive dim6:1=1.000000e+03```
  
  create reweight card: ```python scripts/make_reweight_card.py config_SMEFTatNLO_ggFshape5pars.json cards/ggF-SMEFTatNLO-0jet-loop-5pars/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1 [noborn=QCD]'```
  
  make grid pack: ```./scripts/make_gridpack.sh ggF-SMEFTatNLO-0jet-loop-5pars```
  
  run grid pack (locally): ```python scripts/run_gridpack.py --seed 1 -e 1000 -p Higgs2GGFiducialAndDifferential --gridpack gridpack_ggF-SMEFTatNLO-0jet-loop-5pars.tar.gz -o localtest-ggF-SMEFTatNLO-0jet-loop-5pars```
  
  run grid pack (condor): ```python scripts/launch_jobs.py --gridpack gridpack_ggF-SMEFTatNLO-0jet-loop-5pars.tar.gz -j 20 -s 1 -e 50000 -p Higgs2GGFiducialAndDifferential -o test-ggF-SMEFTatNLO-0jet-loop-5pars --job-mode condor --task-name ggF --sub-opts '+JobFlavour = "longlunch"' --env HIGGSPRODMODE=GGF```
  
  After doing the same with ```ggF-SMEFTatNLO-0jet-tree-5pars``` and ```ggF-SMEFTatNLO-0jet--tree-loop-5pars``` we run:
  
  ```
  mkdir test-ggF-SMEFTatNLO-0jet-5pars
  yodamerge -o test-ggF-SMEFTatNLO-0jet-5pars/RivetFullNoVeto.yoda test-ggF-SMEFTatNLO-0jet-*-5pars/Rivet_*.yoda --add --no-veto-empty
  ```
  
  and then to get the scaling: ```python scripts/get_scaling.py -c config_SMEFTatNLO_ggFshape5pars.json -i test-ggF-SMEFTatNLO-0jet-5pars/RivetFullNoVeto.yoda --hist "/Higgs2GGFiducialAndDifferential/pt_gg" --save txt -o ggF-SMEFTatNLO-0jet-5pars_parametrization```
  
  ### Decays with SMEFTsim
  
  Since I'm an idiot, remember that we'll simplify everything and we we'll run this part with only ```cpG```, ```ctp``` and ```ctG```, so we'll run the produciton again with only these ones.
  
  The three interesting parameters are **probably** ```cHG```, ```cuHRe``` and ```cuGRe``` (corresponding to ```cpG```, ```ctp``` and ```ctG```).
  
  Taking mu mu as an example (see [this](https://github.com/maxgalli/EFT2Obs/tree/WithHiggsDecay/cards/H_mumu_SMEFTsim-3pars) folder):
  
  ```./scripts/setup_process.sh H_mumu_SMEFTsim-3pars```
  
  ```cp MG5_aMC_v2_6_7/H_mumu_SMEFTsim-3pars/Cards/param_card.dat cards/H_mumu_SMEFTsim-3pars```
  
  ```python scripts/make_config.py -p H_mumu_SMEFTsim-3pars -o config_SMEFTsim3pars.json --pars smeft:6,11,15 --def-val 0.01 --def-sm 0 --def-gen 1E-8 --set-inactive smeftcutoff:1=1.000000e+03```
  
  ```python scripts/make_reweight_card.py config_SMEFTsim3pars.json cards/H_mumu_SMEFTsim-3pars/reweight_card.dat```
  
  ```./scripts/make_gridpack.sh H_mumu_SMEFTsim-3pars```
  
  ```export HIGGSPRODMODE=GGF```
  
  local: ```python scripts/run_gridpack.py --gridpack gridpack_H_mumu_SMEFTsim-3pars.tar.gz -s 1 -e 500 --rivet-ignore-beams -p HiggsDecays -o localtest-mumu-decay```
  
  condor: ```python scripts/launch_jobs.py --gridpack gridpack_H_mumu_SMEFTsim-3pars.tar.gz -j 10 -s 1 -e 50000 -p HiggsDecays -o test-mumu-decay --job-mode condor --rivet-ignore-beams --task-name h_mumu_decay --sub-opts '+JobFlavour = "longlunch"' --env HIGGSPRODMODE=GGF```
  
  at the level of the single channel, the many histograms can then be merged using e.g.: ```yodamerge -o test-H_mumu_SMEFTsim-3pars/Rivet.yoda test-H_mumu_SMEFTsim-3pars/Rivet_*.yoda --add --no-veto-empty```
  
  to then merge across multiple decay channels: ```yodamerge -o test-H-decays-SMEFTsim-3pars/Rivet.yoda test-H_*_SMEFTsim-3pars/Rivet.yoda --add --no-veto-empty```
  
  to get the scaling: ```python scripts/get_scaling.py -c config_SMEFTsim3pars.json -i test-H-decays-SMEFTsim-3pars/Rivet.yoda --hist "/HiggsDecays/sumWeights" --save txt -o H_denominator_parametrization.txt```
  
  When there are many diagrams, the process of making the gridpack can take a long time. Look at [these instructions](https://github.com/ajgilbert/EFT2Obs/blob/ggH-example/docs/HiggsGluonFusion.md#make_gridpack) to parallelize.
  
  **For Christ sake remember**: in order not to have fucking Pythia crashing when generating certain kind of events, you have to take care that in the ```pythia8_card.dat``` there is this line ```JetMatching:merge = off``` (not ON!!)!!!!!!!!!!!
  
  Since there are a lot of decay channels, some stupid scripts were done to make the procedure easier:
  - ```scripts/create_SMEFTsim_folder.sh``` loops over Jonathon's folders and creates the updated ones with a different SMEFTsim UFO, removes reweight and param cards (because they will be copied later) and changes the HetMerging business
  - ```scripts/run_all_decays.py``` performs the first four of the steps mentioned above for an arbitrary number of decay channels, which can be changed directly inside the script; job submission will have to be done separately;
      - these are the channels found to take a lot of time to create the gridpack: 4j, 4l, 4tau, jjlv, lltautau, lvlv, jjll
  - ```./scripts/yodamerge_all_decay_channels.sh```: loops over all the ```test-H_{dc}_{mode}-3pars``` and merge the histograms, where {dc} is the decay channel and {mode} can be either SMEFTsim or SMEFTatNLO (we run the decay at NLO for aa)
  
  ### SMEFTatNLO for H->aa decay
  Remember that the ```cpG``` parameter seems to be hardcoded to 0 if ```SMEFTatNLO-NLO``` is imported; for this reason we have to create a ```restrict_NLOCustom.dat``` in which ```ctG``` is set to a non-zero value.
  
  ```./scripts/setup_process.sh H_aa_SMEFTatNLO-3pars```
  
  ```cp MG5_aMC_v2_6_7/H_aa_SMEFTatNLO-3pars/Cards/param_card.dat cards/H_aa_SMEFTatNLO-3pars```
  
  if it was not created after running production part: ```python scripts/make_config.py -p H_aa_SMEFTatNLO-3pars -o config_SMEFTatNLO3pars.json --pars dim6:8 dim62f:19,24 --def-val 0.01 --def-sm 0 --def-gen 1E-8 --set-inactive dim6:1=1.000000e+03```
  
  ```./scripts/make_gridpack.sh H_aa_SMEFTatNLO-3pars```
  
  # Studies suggested by Ilaria
  
  On December 16th 2021, a first meeting with Ilaria was done in order to get suggestions about how to proceed with the interpretation. It was said that the best way to proceed consists in do a preliminary study to understand which are parameters and observables we're insterested in. In order to do this, we have to test:
  - possibly all the production modes
  - as many parameters as possible (so not only three)
  - a certain amount of observables (taking care that they have to be a subset of the ones that are studied in the analyses)
  
  The first step consists in creating a restrict card called ```restrict_IlariaStudies.dat``` that sets to ```9.999999e-01``` all the parameters for the categories DIM6 and DIM62F.
  
  Taking as example the case of ggF, 0jet, loop we illustrate the main steps:
  - create a directory inside ```cards``` that contains ```proc_card.dat```, ```run_card.dat``` and ```pythia8_card.dat``` taken from the ones created before; remember that in ```proc_card.dat``` we have to import the right restrict card and create the directory with the proper name
  - ```./scripts/setup_process.sh ggF-SMEFTatNLO-0jet-loop-IlariaStudies```
  - ```cp MG5_aMC_v2_6_7/ggF-SMEFTatNLO-0jet-loop-IlariaStudies/Cards/param_card.dat cards/ggF-SMEFTatNLO-0jet-loop-IlariaStudies```
  - ```python scripts/make_config.py -p ggF-SMEFTatNLO-0jet-loop-IlariaStudies -o config_SMEFTatNLO_IlariaStudies.json --pars dim6:2,3,4,5,6,7,8,9,10 dim62f:1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,19,22,23,24 --def-val 0.01 --def-sm 0 --def-gen 1E-8 --set-inactive dim6:1=1.000000e+03```
  - make reweight card: ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-0jet-loop-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1 [noborn=QCD]'```
  - ```./scripts/make_gridpack.sh ggF-SMEFTatNLO-0jet-loop-IlariaStudies```
  
  ## ggF
  After the whole business of creating the nine directories inside ```cards``` (combinations of tree, loop, tree-loop and 0jet, 1jet and 2jet - taking care of changing names inside the proc_cards carefully), run the following:
  - ```for TYPE in loop tree tree-loop; do for NJETS in 0jet 1jet 2jet; do ./scripts/setup_process.sh ggF-SMEFTatNLO-$NJETS-$TYPE-IlariaStudies; done; done```
  - ```for TYPE in loop tree tree-loop; do for NJETS in 0jet 1jet 2jet; do cp MG5_aMC_v2_6_7/ggF-SMEFTatNLO-$NJETS-$TYPE-IlariaStudies/Cards/param_card.dat cards/ggF-SMEFTatNLO-$NJETS-$TYPE-IlariaStudies; done; done```
  - make reweight cards:
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-0jet-loop-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1 [noborn=QCD]'```
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-0jet-tree-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1'```
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-0jet-tree-loop-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1 [virt=QCD]'```
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-1jet-loop-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1 [noborn=QCD]' 'change process p p > h j NP=2 QED=1 [noborn=QCD] --add'```
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-1jet-tree-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1' 'change process p p > h j NP=2 QED=1 --add'```
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-1jet-tree-loop-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1 [virt=QCD]' 'change process p p > h j NP=2 QED=1 [virt=QCD] --add'```
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-2jet-loop-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1 [noborn=QCD]' 'change process p p > h j NP=2 QED=1 [noborn=QCD] --add' 'change process pl pl > h j j NP=2 QED=1 [noborn=QCD] --add'```
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-2jet-tree-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1' 'change process p p > h j NP=2 QED=1 --add' 'change process pl pl > h j j NP=2 QED=1 --add'```
    - ```python scripts/make_reweight_card.py config_SMEFTatNLO_IlariaStudies.json cards/ggF-SMEFTatNLO-2jet-tree-loop-IlariaStudies/reweight_card.dat --prepend 'change process p p > h NP=2 QED=1 [virt=QCD]' 'change process p p > h j NP=2 QED=1 [virt=QCD] --add' 'change process pl pl > h j j NP=2 QED=1 [virt=QCD] --add'```
  - make gridpack: ```for TYPE in loop tree tree-loop; do for NJETS in 0jet 1jet 2jet; do ./scripts/make_gridpack.sh ggF-SMEFTatNLO-$NJETS-$TYPE-IlariaStudies; done; done```
  - run gridpack: ```for TYPE in loop tree tree-loop; do for NJETS in 0jet 1jet 2jet; do python scripts/launch_jobs.py --gridpack gridpack_ggF-SMEFTatNLO-$NJETS-$TYPE-IlariaStudies.tar.gz -j 20 -s 1 -e 50000 -p HiggsOnly -o test-ggF-SMEFTatNLO-$NJETS-$TYPE-IlariaStudies --job-mode condor --task-name ggF-SMEFTatNLO-$NJETS-$TYPE-IlariaStudies --sub-opts '+JobFlavour = "testmatch"' --env HIGGSPRODMODE=GGF; done; done```
  - merge:
    - ```for NJETS in 0jet 1jet 2jet; do mkdir test-ggF-SMEFTatNLO-$NJETS-IlariaStudies; done```
    - ```for NJETS in 0jet 1jet 2jet; do yodamerge -o test-ggF-SMEFTatNLO-$NJETS-IlariaStudies/RivetFullNoVeto.yoda test-ggF-SMEFTatNLO-$NJETS-*-IlariaStudies/Rivet_*.yoda --add --no-veto-empty; done```
    - ```mkdir test-ggF-SMEFTatNLO-IlariaStudies```
    - ```yodamerge -o test-ggF-SMEFTatNLO-IlariaStudies/RivetFullNoVeto.yoda test-ggF-SMEFTatNLO-*-IlariaStudies/*.yoda```
  - dump scaling files: ```for VAR in pt_h n_jets y_h pt_j0; do python scripts/get_scaling.py -c config_SMEFTatNLO_IlariaStudies9pars.json -i test-ggF-SMEFTatNLO-IlariaStudies9pars/RivetFullNoVeto.yoda --hist "/HiggsOnly/$VAR" --save txt,json -o ggF-SMEFTatNLO-IlariaStudies-$VAR; done```
  
  # SMEFT + Combine
  
  Notes about writing the model in Combine after generation with MG and EFT2Obs.
