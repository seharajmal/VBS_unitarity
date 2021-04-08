Codice SM.nb
Genera diagrammi e ampiezze dei processi VBS ssWW nel caso SM per poi calcolarle per diverse combinazioni di polarizzazioni 
degli stati iniziali e finali (+-+-, ++++, 0000, 0+0+,0++0, +--+; le altre non le ho calcolate perchè per questioni 
di simmetria dovrebbero risultare uguali ad alcune di queste. Lo avrei verificato dopo essermi accertata del funzionamento
del codice e della correttezza dei risultati).

Codice SMEFT.nb
Fa la stessa cosa nel caso SMEFT.

process: ho definito il processo
top: ho definito i tipi di grafico che intendo includere (0 loop, 2 gambe esterne entranti e due uscenti)
insertFields: ho assegnato alle gambe esterne i campi SM
paint: ho disegnato i grafici
VBSamp: ho creato le ampiezze associate ai grafici e le ho calcolate
Unabbr: l'output di VBSamp è scritto in una forma compatta con espressioni tipo 'Abbr' o 'Subexpr'; per capire la forma dell'ampiezza è
	necessario rimuovere le abbreviazioni -> una volta fatto compaiono esplicitamente i prodotti scalari fra i vari quadrivettori 'Pair[a,b]'
ToComponents: nell'output del comando CalcFeynAmp l'oggetto più piccolo che compare è un quadrivettore, quindi non vengono svolti i prodotti 
	scalari -> per farlo è necessario passare alle componenti dei quadrivettori, e si può fare col pacchetto VecSet, che include il comando 
	ToComponents. Nel pacchetto sono definiti i vettori di polarizzazione e i quadrimomenti delle particelle, quindi ToComponents svolge i 
	prodotti scalari richiamando le definizioni nel pacchetto (https://github.com/vsht/formcalc-mirror/blob/master/tools/VecSet.m).

In realtà anche con ToComponents il calcolo non viene effettuato esplicitamente, e compaiono oggetti della forma 
"VecSet`Private`rep[Pair][VecE[i, p], VecK[j]]". Sia la funzione rep[Pair] che i vari quadrivettori VecE[i,p] e VecK[i] sono definiti nel 
pacchetto. Ho rinominato tutte le funzioni rep[Pair] con lettere (M, Q, A, Z...) giusto per scrivere l'ampiezza in una forma meno caotica:

Amp[{{V[3], VecK[1], MW, -Charge}, {V[3], VecK[2], 
     MW, -Charge}} -> {{V[3], VecK[3], MW, -Charge}, {V[3], VecK[4], 
     MW, -Charge}}][-1/
   SW2 4 Alfa \[Pi] (A C - 2 M N + D O + 
      SW2 (D (4 G H - O S + O U + 4 F Y) - 
         4 (C F Q + G M Q - O Q R + A G Z + F N Z - O W Z)) Den[T, 
        0] + D MW2 O Den[T, MH2] + 
      CW2 (D (4 G H - O S + O U + 4 F Y) - 
         4 (C F Q + G M Q - O Q R + A G Z + F N Z - O W Z)) Den[T, 
        MZ2] - SW2 (4 L (D H + B M) + 4 (H N + B O) R + A C (S - T) - 
         4 C (B F + H W) - 4 A (R Y + L Z)) Den[U, 0] + 
      A C MW2 Den[U, MH2] + 
      CW2 (-4 L (D H + B M) - 4 (H N + B O) R + A C (-S + T) + 
         4 C (B F + H W) + 4 A (R Y + L Z)) Den[U, MZ2])]
 
e poi ogni singolo pezzo l'ho calcolato a mano.


