# Si parte con gli istogrammi in output da ExRootAnalysis nella cartella "data"
#osservabili usate per ora: PT, Eta, mll, mjj


cd build;
make clean;
make;
make install;
cd ..;

# da ogni distribuzione nell'output da ExRootAnalysis ottengo diversi istogrammi, uno per tipo di particella

./all_pt SM;
./all_pt cW_int;
./all_pt cW_quad;
./all_pt cHW_int;
./all_pt cHW_quad;
./all_pt cHWB_int;
./all_pt cHWB_quad;
./all_pt cHbox_int;
./all_pt cHbox_quad;
./all_pt cHDD_int;
./all_pt cHDD_quad;


./all_mll SM;
./all_mll cW_int;
./all_mll cW_quad;
./all_mll cHW_int;
./all_mll cHW_quad;
./all_mll cHWB_int;
./all_mll cHWB_quad;
./all_mll cHbox_int;
./all_mll cHbox_quad;
./all_mll cHDD_int;
./all_mll cHDD_quad;

./all_Eta SM;
./all_Eta cW_int;
./all_Eta cW_quad;
./all_Eta cHW_int;
./all_Eta cHW_quad;
./all_Eta cHWB_int;
./all_Eta cHWB_quad;
./all_Eta cHbox_int;
./all_Eta cHbox_quad;
./all_Eta cHDD_int;
./all_Eta cHDD_quad;

./all_mjj SM;
./all_mjj cW_int;
./all_mjj cW_quad;
./all_mjj cHW_int;
./all_mjj cHW_quad;
./all_mjj cHWB_int;
./all_mjj cHWB_quad;
./all_mjj cHbox_int;
./all_mjj cHbox_quad;
./all_mjj cHDD_int;
./all_mjj cHDD_quad;

# costruisco le distribuzioni SM + contributi EFT 

cd histos/mll;
/home/nyykki/root/bin/hadd -f SM_cW_int.root SM.root cW_int.root;
/home/nyykki/root/bin/hadd -f SM_cW_quad.root SM.root cW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cW_int_quad.root SM.root cW_int.root cW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHW_int.root SM.root cHW_int.root;
/home/nyykki/root/bin/hadd -f SM_cHW_quad.root SM.root cHW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHW_int_quad.root SM.root cHW_int.root cHW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_int.root SM.root cHWB_int.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_quad.root SM.root cHWB_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_int_quad.root SM.root cHWB_int.root cHWB_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_int.root SM.root cHbox_int.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_quad.root SM.root cHbox_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_int_quad.root SM.root cHbox_int.root cHbox_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_int.root SM.root cHDD_int.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_quad.root SM.root cHDD_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_int_quad.root SM.root cHDD_int.root cHDD_quad.root;

cd ..;

cd Eta;
/home/nyykki/root/bin/hadd -f SM_cW_int.root SM.root cW_int.root;
/home/nyykki/root/bin/hadd -f SM_cW_quad.root SM.root cW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cW_int_quad.root SM.root cW_int.root cW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHW_int.root SM.root cHW_int.root;
/home/nyykki/root/bin/hadd -f SM_cHW_quad.root SM.root cHW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHW_int_quad.root SM.root cHW_int.root cHW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_int.root SM.root cHWB_int.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_quad.root SM.root cHWB_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_int_quad.root SM.root cHWB_int.root cHWB_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_int.root SM.root cHbox_int.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_quad.root SM.root cHbox_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_int_quad.root SM.root cHbox_int.root cHbox_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_int.root SM.root cHDD_int.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_quad.root SM.root cHDD_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_int_quad.root SM.root cHDD_int.root cHDD_quad.root;

cd ..;

cd PT;
/home/nyykki/root/bin/hadd -f SM_cW_int.root SM.root cW_int.root;
/home/nyykki/root/bin/hadd -f SM_cW_quad.root SM.root cW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cW_int_quad.root SM.root cW_int.root cW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHW_int.root SM.root cHW_int.root;
/home/nyykki/root/bin/hadd -f SM_cHW_quad.root SM.root cHW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHW_int_quad.root SM.root cHW_int.root cHW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_int.root SM.root cHWB_int.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_quad.root SM.root cHWB_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_int_quad.root SM.root cHWB_int.root cHWB_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_int.root SM.root cHbox_int.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_quad.root SM.root cHbox_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_int_quad.root SM.root cHbox_int.root cHbox_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_int.root SM.root cHDD_int.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_quad.root SM.root cHDD_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_int_quad.root SM.root cHDD_int.root cHDD_quad.root;

cd ..;

cd mjj;
/home/nyykki/root/bin/hadd -f SM_cW_int.root SM.root cW_int.root;
/home/nyykki/root/bin/hadd -f SM_cW_quad.root SM.root cW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cW_int_quad.root SM.root cW_int.root cW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHW_int.root SM.root cHW_int.root;
/home/nyykki/root/bin/hadd -f SM_cHW_quad.root SM.root cHW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHW_int_quad.root SM.root cHW_int.root cHW_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_int.root SM.root cHWB_int.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_quad.root SM.root cHWB_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHWB_int_quad.root SM.root cHWB_int.root cHWB_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_int.root SM.root cHbox_int.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_quad.root SM.root cHbox_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHbox_int_quad.root SM.root cHbox_int.root cHbox_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_int.root SM.root cHDD_int.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_quad.root SM.root cHDD_quad.root;
/home/nyykki/root/bin/hadd -f SM_cHDD_int_quad.root SM.root cHDD_int.root cHDD_quad.root;

cd ../..;

# costruisco istogrammi compatibili con combine

cd histos4datacards;
./merge_multipart mll;
./merge_multipart mjj;
./merge Eta el;
./merge Eta mu;
./merge Eta ta;
./merge Eta j;
./merge PT el;
./merge PT ta;
./merge PT mu;
./merge PT j;


















