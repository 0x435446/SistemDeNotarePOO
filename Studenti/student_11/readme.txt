Salut!
Aici sunt mici instructiuni si explicatii pentru cum a fost gandita o mica varianta a jocului plants vs zombie.
Clasele de baza folosite sunt map, CoreObject. 
Clasa map construieste terenul de joaca o singura data, de asta este implementat sub tip singleton.
Clasa CoreObject este folosita pentru obtinerea claselor, sun, sunflower, peashooter, peaprojectile si zombie, 
fiind declarata sub forma unei interfete.
CoreObjectul porneste cu viata, damage, cost si value. Fiecare entitate derivata din aceasta va avea in constructor 
o anumita parte din aceste caracteristici (exemplu: zombie nu costa nimic sa fie pus in teren).
Pentru initializarea pozitiilor fiecarei plante, functiile au fost apelate in ConsoleInput pentru obtinerea mai eficienta
a coordonatelor de pozitionare. 
Miscarea proiectilelor si a fiecarui zombie se face prin thread-uri diferite, care impart aceeasi zona de memorie.
Aici, initial se dorea actualizarea lui this->x si this->y a zombiilor si a proiectilelor la fiecare mutare a lor, dar nu s-a putut :((
Proiectilul actioneaza asupra unui zombie prin durata de propagare a proiectilului pana la zombie. Ar fi fost ideal sa functioneze.
Asadar, pentru o simulare mai apropiata de jocul adevarat, fiecare zombie are o durata de viata intre 10 si 20 de secunde, ceea ce face 
utilizatorul sa aiba doar sana sa castige, niciodata sa piarda (este implementata aceasta functie, doar trebuie ster/comentat zonele in care apare "castig"
si de aici daca zombie-ul ajunge in zona "HOME" se va afisa in consola " It's Ovah' ".Enjoy
 