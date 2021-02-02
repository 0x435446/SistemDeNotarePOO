Buna ziua! :)

Tema functioneaza cu click obisnuit, nu neaparat double click.
Jocul incepe cu un click pe NEW GAME, apoi introducerea username ului, este necesar un username unic la inceperea unui nou joc,
	acestia fiind salvati intr un fisier.
Dupa introducerea username ului va fi afisat Campul de lupta in centru, deasupra locul de aparitie al sorilor, care apar la o 
	pozitie si un timp random, fiecare selectie a acestora fiind contorizata in stanga cu +50 la fiecare click pe soare.

In stanga campului de lupta este zona de selectie a plantelor, fiecare cu un cost propriu. Se face click pe o planta apoi pe
	locul unde doriti sa fie plasata in campul de lupta, nu putem pune planta intr un loc unde este deja o planta sau un zombie.

In urma plasarii plantei pe camp aceasta nu va efectua nicio actiune (am implementat partea de shoot_projectiles dar jocul are un
	comportament ciudat asa ca am comentat o), plantele sunt prezente in camp doar prin printarea acestora.

Zombie imediat cu inceperea jocului. Este un singur tip de zombie iar acesta apare pe o pozitie random din teren si apoi se misca
	treptat cu cate o casuta spre capatul stang al campului de lupta, odata trecut jocul terminandu se si astfel afisarea mesajului
	"END GAME".

Nu exista implementare pt coliziune, zombie sa manance planta sau proiectile sa loveasca zombie.