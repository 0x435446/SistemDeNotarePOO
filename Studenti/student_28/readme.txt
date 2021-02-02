		--Poo vs Zombies--

	In cadrul acestei teme am reusit sa implementez o clasa CGame din care controlez tot jocul si se poate da start. 
	Clasa CEntities este o interfata pentru CEntity. In CEntities am declarat functiile pure virtuale
pe care le-am implementat ulterior in clasele copil ale clasei CEntity.
	Pentru a intelege elementele care apar pe ecran, trebuie sa mergeti in fiecare clasa iar codul ascii
specific fiecarei entitati este comentat in headerul fiecarei clase.
	
	La inceput, am implementat posibilitatea salvarii datelor fiecarui jucator. Am descris doar ideea de salvare,
aceasta idee putand fi completata de crearea unui fisier in care se salveaza datele si la logare se verifica datele
din respectvul fisier. Daca se gasesc, se reincepe de la levelul atins anterior, daca nu, jocul incepe cu nivelul 1.
	Jocul incepe cu aparitia sorilor in partea de sus a ecranului la pozitii random, iar la dublu click acestia dispar
si scorul creste cu 25.
	Apar si plantele sunflower si peashooter in partea stanga a consolei iar prin dublu click pe ele si apoi dublu 
click la o POZITIE PERMISA, planta fie ataca fie are un efect asupra vitezei de aparitie a sorilor.
	Peashooter trage cu proiectile pea care se misca pe ecran si la interactiunea cu un zombie, scad healthul
zombieului si apoi dispar de pe ecran.
	Apar zombii care se misca spre stanga consolei. La 5 lovituri de pea, un zombie moare. Daca acesta ajunge la o 
planta, dupa 5 muscaturi planta moare. Daca mai multe pea se suprapun creste damage-ul asupra zombie-ului.
	Atunci cand un zombie trece de plante si ajunge la gradina,jocul se termina. Dupa un anumit numar de zombie
si victoria plantelor, se trece la nivelul urmator.
	Exista si un fisier log care salveaza tot ce se intampla pe ecran.

