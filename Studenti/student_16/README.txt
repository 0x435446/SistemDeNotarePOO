POO - TEMA 2 - Ioana Dragos

-----------------------------------------------------------------------------------------------------------------------------------------

1. Modul de implementare al temei

Tema are la baza clasa interfata IDrawable, care are ca si metoda functia draw, din care s-au derivat restul claselor.
Fiecare obiect este o instanta IDrawable cu un set de coordonate x si y, folosite la reprezentarea in consola.
Zonele jocului sunt imparite in:
-Scoreboard (colt stanga sus): retine scorul curent si il updateaza la sfarsitul jocului pentru utilizatorul curent in ordine crescatoare
in fisierul "score.txt"; La obtinerea unui nou scor maxim, va aparea un text "HIGHSCORE" la un anumit interval de timp.
-ResourceGrid : care afiseaza numrul de sori disponibili pentru achizitionarea de plante( sorii sunt extrasi din cadrul fiecarui sunflower
prin dublu click pe acesta in interiorul Battlefield-ului);
-PlantShop : care afiseaza instante ale clasei Avatar( reprezinta "masti" ale plantelor) generate la intervale presetate de timp. Daca 
utilizatorul da dublu- click pe unul din avatare, are destui sori pentru a-l cumpara si apasa pe teren, pe locul dorit va aparea o planta
cu numele avatarului, iar banii vor fi scazuti din Resource Grid
-Battlefield: care contine instante ale clasei BattleLine in functie de dificultatea aleasa la inceputul jocului si care la randul lor contin
8 instante ale clasei BattleTile. Aceasta din urma este unitatea indivizibila a terenui de lupta si poate contine o planta.

2.Rularea jocului

La rulare, utilizatorul poate cumpara cu numarul de sori pusi la dispozitie plante pentru a le pune pe teren. Fiecarei plante ii este asociata
o anumita functie care intra in vigoare prin apelul functiei "executeFunction". La planta de tip Sunflower aceasta are ca efect generarea
de sori la un interval regulat de timp, pentrua  putea fi extras de user. La PeaShooter, functia este de a trage cu proiectile, generate
tot la un interval regulat de timp.
Fiecare planta are si un anumit numar de hitpoints care, atunci cand planta intra in contact direct cu un Zombie, va scadea.
Exista 3 tipuri de Zombie: Zombie, Bucket Head Zombie si Pole Vaulting Zombie. Acestia se misca de la dreapta la stanga cu o viteza presetata
si sunt generati la un interval random de timp( prin functia rand si cu seed -ul time(0) la functia srand). La intrarea in contact cu planta
se apeleaza functia "eat" pana cand zombie-ul moare( este lovit de proiectilele generate de catre instantele clasei Plant) sau planta
este mancata. Zombie-ul de tip Bucket Head este la fel ca Zombie doar ca are numarul de hipoint-uri mai mare, iar cel Pole Vaulting poate
sari peste prima planta intalnita si continua drumul.

