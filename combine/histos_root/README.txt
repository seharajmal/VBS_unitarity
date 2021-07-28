Codici per ricavare i file .root contententi gli istogrammi con cui si creano le datacard per combine

data: 
Contiene gli output di Madgraph/ExRootAnalysis (è necessaria la libreria LibExRootAnalysis.so per lavorare coi file in output da ExRootAnalysis). 
Sono file "model.root" contenenti le distribuzioni di alcune osservabili (Px, Py, Pz, PT, Eta, Phi) senza distinzione fra particelle. Per creare gli 
istogrammi relativi alla distribuzione di una certa osservabile per una particella specifica uso gli eseguibili "all_obs"

./all_obs model

("model" specifica i contributi EFT contenuti nel sample che sto considerando: SM = solo Standard Model, cW_int = solo contributi del termine d'interferenza
dell'operatore Qw, cW_quad = analogo per termine quadratico ...)

Dando in input il nome di un file contenuto in "data", mi restituisce un file "model.root" contenente le distribuzioni dell'osservabile "obs" per diverse
particelle (si trovano nelle cartelle histos/obs). 

histos/obs:
Contiene gli output di "all_obs" e i file ottenuti con hadd a partire dagli output di "all_obs".

histos4datacards:
Contiene i file .root compatibili coi tool di Andrea per le analisi con combine. 
Si ottengono usando "merge" o "merge_multipart":

Es:
./merge Eta el 
prende da tutti i file in histos/Eta gli istogrammi relativi all'eta degli elettroni, mettendoli in un unico file .root, contenuto in histos4datacards.

Per ricavare la significance uso i codici di Andrea.
