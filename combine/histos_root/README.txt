Machinery per l'analisi VBS ssWW

---- Codici per la creazione degli istogrammi ----

- Codici "all_obs"
  Chiedono vuole argomento il modello (SM, op_int, op_quad)
  Dai file .root in "data" (output di ExRootAnalysis) creano file .root in "histos/obs" che hanno la struttura:
  Model.root -> (obs_particle1, obs_particle2, ...) 
  dove "obs_particle" sono le distribuzioni dell'osservabile "obs" relative alla particella "particle"
  
- Codici "merge" e "merge_multipart"
  "merge" vuole come argomento l'osservabile e la particella (es: Eta el; PT j1 ...)
  "merge_multipart" vuole come argomento solo l'osservabile
  Da tutti i file .root contenuti in "histos/obs" estrae le distribuzioni dell'osservabile in argomento relative alla  
  particella in argomento e le mette in un unico file .root, contenuto in "histos4datacards". Questo file ha la struttura:
  Obs_particle.root -> (SM, op1_int, op1_quad, SM_op1_int, SM_op1_quad, SM_op1_int_quad, stesso per op2, ...)
  
---- Codici per plottare le distribuzioni ----

- "distributions"
  Disegna una singola distribuzione
  
- "distributions_SMvsEFT"
  Disegna in un solo plot le distribuzioni SM, op_int, op_quad, SM_int_quad relative all'osservabile e all'operatore in 
  argomento
  
---- Codici per plottare likelihood scan e intervalli di confidenza ----  
  
- "LSplot"
  Disegna il likelihood scan di un operatore relativo all'osservabile in argomento e riporta il valore del minimo della
  likelihood e gli estremi degli intervalli di confidenza.

- "LS_all_obs"
  Disegna in un unico plot i likelikood scan di tutte le osservabili in esame per l'operatore in argomento
  
- "ciplots"
  Disegna i plot con gli intervalli di confidenza per ogni osservabile relativamente ad un solo operatore e aggiunge in
  output un file .txt in cui sono già scritte le tabelle con i confidence interval da compilare in LateX.

- "comparing_ci"
  Disegna il plot in cui si mettono a confronto intervalli di confidenza relativi a diverse analisi

---- Altri codici non sempre utili ---- 

- "significanza" e "significanza2"
  Calcola la significanza a mano con due formule differenti. In entrambi i casi in output vi è un file .txt con le tabelle
  da compilare in LateX.
  
- "bin_count"
  L'avevo scritto per fare una verifica automatica del fatto che ci fossero in ogni bin almeno 10 eventi. Riporta l'indice
  dei bin in cui questo non accade, specificando il numero di eventi bin per bin.
