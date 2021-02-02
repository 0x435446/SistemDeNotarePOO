In vederea implementarii entitatilor ce vor fi afisate pe suprafata, am declarat clasa Entiy, clasa parinte pentru Plant, Zombie si Projectile. 
In aceasta clasa se afla atributele de baza ale tuturor elementelor ce vor fi prezentate pe suprafata de joc, respectiv tipul, viata (hp) si banda asociata (instanta a clasei Lane). 
Tipul fiecarei entitati este ales pe baza valorilor unui enum:
    enum type { PLANT, PLANT_WALLNUT, PLANT_SUNFLOWER, PLANT_PEASHOOTER, PLANT_CHERRY_BOMB, PLANT_SNOW_PEA, ZOMBIE, ZOMBIE_POLE_VAULTING, ZOMBIE_BUCKET_HEAD, ZOMBIE_SUPER_ZOMBIE, PROJECTILE, NONE };


De asemenea, exista clasa Level ce pastreaza un vector al benzilor, fiecare banda putand fi asociata cu o anumita entitate, ce urmeaza a fi plasata pe o anumita pozitie.

De asemenea, exista clase utilitare, precum History, al carei scop este salvarea mesajelor de debug si a scorurilor.
	Mesaje debug - history.txt
	Scoruri - player_scores.txt
			, fisiere aflate la nivelul directorului radacina al proiectului


De asemenea, sunt puse la dispozitie exceptii pentru transmiterea "erorilor" intre diferite componente, spre exemplu exceptii pentru a semnaliza plasarea unei plante pe o pozitie ce este deja ocupata sau in afara suprafetei de joc (ExceptionBadPosition) si erori referitoare la resurse (e.g. daca jucatorul nu a 'colectionat' suficiente resurse inainte de selectarea unei plante - ErrorSuns).


Clasa Entity pune la dispozitie metoda "draw", metoda virtuala la nivelul clasei de baza, ce este suprascrisa in toate componentele ce o extind. Aceasta metoda returneaza un string, reprezentand tipul plantei / zombie / proiectil:


Legenda entitati banda:
	-------- zombie -----------
		"BH" - zombie, bucket head
		"PV" - zombie, pole vaulting
		"S+" - zombie, super zombie
		"ZZ" - zombie, tip "simplu"
	-------- plante -----------
		"P" - planta "simpla" (pea shooter)
		"C" - planta cherry bomb

	-------- proiectile -----------
		"-" - orice proiectil
