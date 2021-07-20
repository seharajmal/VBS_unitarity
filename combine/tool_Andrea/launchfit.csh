set inf='v80'


python createDatacards.py -i PT_j.root -d datacard_PT_j #--ls $oper
python createDatacards.py -i PT_el.root -d datacard_PT_el #--ls $oper
python createDatacards.py -i PT_mu.root -d datacard_PT_mu #--ls $oper
python createDatacards.py -i PT_ta.root -d datacard_PT_ta #--ls $oper
python createDatacards.py -i Eta_j.root -d datacard_Eta_j #--ls $oper
python createDatacards.py -i Eta_el.root -d datacard_Eta_el #--ls $oper
python createDatacards.py -i Eta_mu.root -d datacard_Eta_mu #--ls $oper
python createDatacards.py -i Eta_ta.root -d datacard_Eta_ta #--ls $oper
python createDatacards.py -i mll.root -d datacard_mll #--ls $oper
python createDatacards.py -i mjj.root -d datacard_mjj #--ls $oper

python runCombine.py -y 2017 -d datacard_mjj -m hist #--ls $oper --runSingleCat -m hist

##python getLimitData.py -y 2016 -d $folder/
##python brazilPlot.py -y 2016 -l $folder
