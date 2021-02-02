Toate entitatile au fost create cu toate functionaltatile mai putin abilitati.
Log.log a fost folosit pentru a retine Level-ul si Score-ul, din punctul meu de vedere ar fi fost inutil sa scriu cand fiecare zombii moare sau cand fiecare planta trage pentru ca la un nivel mai avansat s ar fi umplut foarte rapid de aceleasi actiuni
User-ul se verifica prin existenta unui director cu numele lui in PvZ_Salvari creat in C (nu toata lumea are D)
Daca directorul nu exista se va creea unul si player ul va fi coniderat nou plecand de la level 1 si scor 0
Daca user ul exista se va continua cu verficarea parolei
Pentru simplitate parola va fi regasita in directorul user ului intr un document "Parola.password"
Fiecare user are directorul lui in care va exista parola si fisierul "Log.log" in care se retin Level-ul si Score-ul acestuia
Un bug vizibil important care trebuie rezolvat tine de miscarea shot-urilor(lipsa acesteia) deja create in lipsa zombiilor
Diagrama Claselor a fost deja creata si aranjata in proiect
Din lipsa timpului nu am putut implementa abilitatile chiar daca ar fi fost foarte usor sa fac asta
Asemenea din lipsa timpului, nu am implementat salvarea in timpul jocului, insa se putea face foarte usor doar prin crearea unui alt fisier text "Save.save" 
In el as fi pus wstring ul Map (indiferent care ar fi fost el) timpul score-ul resursele si NumberOfZombiesLeft calculat ca (NumberOfZombiesInLevel-ZombiesKilled)
Pentru Recover citeam fiserul puneam fiecare variabila la locul ei si iteram mapa si stiind deja semnele in Drawable as fi creat cate un obiect specific pt fiecare semn 
Dupa s-ar fi continuat lupta

Inca o Problema ar fi ca nu se afiseaza ceea ce scrii cand introduci de la tastatura Username si parola
pentru a face asta corect va trebuie sa 
Scrii numele pe care il vrei
sa apesti enter (chiar daca nu apare ca s a mutat cursorul, el se va muta cand vei incepe sa scrii
apoi sa scrii parola pe care o vrei
sa apesi enter
si alta tasta

in caz de user existent si parola gresita se repeta pasii
scrii parola pe care o vrei
sa apesi enter
si alta tasta