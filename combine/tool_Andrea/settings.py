import collections

#*********************************
#                                *
#       List of channels         *
#                                *
#*********************************
sr_var = 'BDT_output_SM'       
cr_var = sr_var#'countings'        
hist_pre = "h_"                    
### List of histos to include in the root files
histos = { "SR":hist_pre + sr_var + "_SR",
           #"PR":"h_ltau_m_jj_selection_upto_bveto_lepBDTcut",
           #"CRWJ":hist_pre + cr_var + "_wjets_CR",
           #"CRTT":hist_pre + cr_var + "_ttbar_CR",
           #"CRQCD":hist_pre + cr_var + "_QCD_CR",
          
}
### List of regions for which creating the datacards
channels = ["SR_inclusive",
]

leptons = ['inclusive',
]


#*********************************
#                                *
#       List of backgrounds      *
#                                *
#*********************************
      
bkg = ["VBS_SSWW_SM"
]


lssamples_1D = {
    'cW':{    
        'SM': "VBS_SSWW_SM",
        'cW_int': "VBS_SSWW_cW_int",
        'cW_quad': "VBS_SSWW_cW_quad",
    },
    'cHW':{    
        'SM': "VBS_SSWW_SM",
        'cHW_int': "VBS_SSWW_cHW_int",
        'cHW_quad': "VBS_SSWW_cHW_quad",
    },
    'cHWB':{    
        'SM': "VBS_SSWW_SM",
        'cHWB_int': "VBS_SSWW_cHWB_int",
        'cHWB_quad': "VBS_SSWW_cHWB_quad",
    },
    'cHbox':{    
        'SM': "VBS_SSWW_SM",
        'cHbox_int': "VBS_SSWW_cHbox_int",
        'cHbox_quad': "VBS_SSWW_cHbox_quad",
    },    
}

class rateParam(object):
    pass

rateParams = {}

'''
FakeMu_rate_2017 = rateParam()
FakeMu_rate_2017.chs = [#"SR_muon",
                        "CRWJ_muon",
                        "CRTT_muon",
                        "CRQCD_muon",
]
FakeMu_rate_2017.bkg = "Fake"
rateParams["FRest_muon_2017"] = FakeMu_rate_2017


FakeEle_rate_2017 = rateParam()
FakeEle_rate_2017.chs = [#"SR_electron",
                         "CRWJ_electron",
                         "CRTT_electron",
                         "CRQCD_electron",
]
FakeEle_rate_2017.bkg = "Fake"
rateParams["FRest_electron_2017"] = FakeEle_rate_2017
'''
'''
TTDiLep_ele_2017 = rateParam()
TTDiLep_ele_2017.chs = [#"SR_electron",
                        #"CRWJ_electron",
                         "CRTT_electron",
]
TTDiLep_ele_2017.bkg = "TTTo2L2Nu"
rateParams["TTDiLep_electron_2017"] = TTDiLep_ele_2017
TTDiLep_mu_2017 = rateParam()
TTDiLep_mu_2017.chs = [#"SR_muon",
                       #"CRWJ_muon",
                       "CRTT_muon",
]
TTDiLep_mu_2017.bkg = "TTTo2L2Nu"
rateParams["TTDiLep_muon_2017"] = TTDiLep_mu_2017
'''

#*********************************
#                                *
#       List of systematics      *
#                                *
#*********************************

syst = collections.OrderedDict()
#syst["lumi_2016"] = ["lnN", "all", 1.025]
syst["lumi_2017"] = ["lnN", "all", 1.023]
#syst["lumi_2018"] = ["lnN", "all", 1.025]

'''
syst["FR_sys_muon"] = ["lnN", "Fake", 1.15]
syst["FR_sys_electron"] = ["lnN", "Fake", 1.22]
syst["lumi_2018"] = ["lnN", "all", 1.023]
syst["trigger"] = ["lnN", "all", 1.02]
syst["trigSF"] = ["shape", ["sig"]]
syst["trigSF"] = ["lnN", ["sig",sigTTW, sigZ, "QCD", "SingleTop"]]
syst["jes"] = ["shape", ("QCD", "TT_Mtt", "WJets", "sig")]

syst["autoMCstat"] = ["shape", ("VG", "WpWpJJ_QCD", "TVX", "TTTo2L2Nu", "WZ", "OtherWS", "ZZtoLep", "sig")]
syst["PF"] = ["shape", ("QCD", "ST", "TT_Mtt", "WJets", "sig")]
syst["pu"] = ["shape", ("QCD", "ST", "TT_Mtt", "WJets", "sig")]
syst["jes"] = ["shape", ("QCD", "ST", "TT_Mtt", "WJets", "sig")]
syst["jer"] = ["shape", ("QCD", "ST", "TT_Mtt", "WJets", "sig")]


syst["PF"] = ["shape", ("QCD",  "sig")]
syst["pu"] = ["shape", ("QCD",  "sig")]
syst["lep"] = ["shape", ("QCD",  "sig")]
syst["trig"] = ["shape", ("QCD",  "sig")]
syst["jes"] = ["shape", ("QCD",  "sig")]
syst["jer"] = ["shape", ("QCD",  "sig")]
syst["btag"] = ["shape", ("QCD",  "sig")]
syst["mistag"] = ["shape", ("QCD",  "sig")]
syst["pdf_total"] = ["shape", ("QCD",  "sig")]

'''
years = ["2017"]
#years = ["2016","2017","2018"]

'''
splityearjes=False
#splityearjes=True
if(splityearjes):
    for y in ys:
        #if(y=="2016"):syst["jer"+y] = ["shape", [ sigTTW]] #No QCD : low stat
        if(y=="2016"):syst["jes"+y] = ["shape", ["sig", sigZ, sigTTW, "SingleTop" ]] #No QCD : low stat
        if(y!="2016"):syst["jer"+y] = ["shape", ["sig", sigZ, sigTTW, "SingleTop"]] #No QCD : low stat
if(not splityearjes):
    syst["jes"] = ["shape", ["sig", sigTTW, sigZ, "SingleTop"]] #No QCD : low stat
    syst["jer"] = ["shape", ["sig", sigTTW, sigZ, "SingleTop"]] #No QCD : low stat
'''

#*********************************
#                                *
#         List of signals        *
#                                *
#*********************************

VBS_SSWW_cW_int = ("cW_int")
VBS_SSWW_cW_quad = ("cW_quad")
VBS_SSWW_cHW_int = ("cHW_int")
VBS_SSWW_cHW_quad = ("cHW_quad")
VBS_SSWW_cHWB_int = ("cHWB_int")
VBS_SSWW_cHWB_quad = ("cHWB_quad")
VBS_SSWW_cHbox_int = ("cHbox_int")
VBS_SSWW_cHbox_quad = ("cHbox_quad")

VBS_SSWW_SM_cHbox_int = ("SM_cHbox_int")
VBS_SSWW_SM_cHbox_quad = ("SM_cHbox_quad")
VBS_SSWW_SM_cHbox_int_quad = ("SM_cHbox_int_quad")

VBS_SSWW_SM_cHW_int = ("SM_cHW_int")
VBS_SSWW_SM_cHW_quad = ("SM_cHW_quad")
VBS_SSWW_SM_cHW_int_quad = ("SM_cHW_int_quad")

VBS_SSWW_SM_cHWB_int = ("SM_cHWB_int")
VBS_SSWW_SM_cHWB_quad = ("SM_cHWB_quad")
VBS_SSWW_SM_cHWB_int_quad = ("SM_cHWB_int_quad")

VBS_SSWW_SM_cW_int = ("SM_cW_int")
VBS_SSWW_SM_cW_quad = ("SM_cW_quad")
VBS_SSWW_SM_cW_int_quad = ("SM_cW_int_quad")

VBS_SSWW_SM_cHDD_int = ("SM_cHDD_int")
VBS_SSWW_SM_cHDD_quad = ("SM_cHDD_quad")
VBS_SSWW_SM_cHDD_int_quad = ("SM_cHDD_int_quad")


sigpoints = [

#VBS_SSWW_cW_int ,
#VBS_SSWW_cW_quad ,
#VBS_SSWW_cHW_int ,
#VBS_SSWW_cHW_quad ,
#VBS_SSWW_cHWB_int ,
#VBS_SSWW_cHWB_quad ,
#VBS_SSWW_cHbox_int ,
#VBS_SSWW_cHbox_quad ,
   
#VBS_SSWW_SM_cHbox_int,
#VBS_SSWW_SM_cHbox_quad,
#VBS_SSWW_SM_cHbox_int_quad,

#VBS_SSWW_SM_cHW_int,
#VBS_SSWW_SM_cHW_quad,
#VBS_SSWW_SM_cHW_int_quad,

#VBS_SSWW_SM_cHWB_int,
#VBS_SSWW_SM_cHWB_quad,
#VBS_SSWW_SM_cHWB_int_quad,

#VBS_SSWW_SM_cW_int,
#VBS_SSWW_SM_cW_quad,
#VBS_SSWW_SM_cW_int_quad,

#VBS_SSWW_SM_cHDD_int,
#VBS_SSWW_SM_cHDD_quad,
VBS_SSWW_SM_cHDD_int_quad,

   
]
