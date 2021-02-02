La deschiderea aplicatie PVSZ se cer introducerea unui nume si a unei parole care sunt verificate cu datele existente in jucatori.txt.
In cazul in care deja exista numele iar parola este incorecta, se reia autentificarea.
Daca numele este nou, se creeaza un cont nou.
Daca datele coincid cu cele memorate, se incepe jocul de la nivelul corespunzator jucatorului.
Fiecare nivel are un numar de benzi, 1 pentru lvl 1, 3 pentru lvl 2 si 5 de la lvl 3.
Resursele apar la un interval de timp dat in casute aleatoare neocupate si se colecteaza prin dublu clic.
Pentru a planta o planta intai se da dublu clic pe aceasta corespunzator legendei.
Daca sunt suficiente resurse disponibile aceasta apare pe teren in casuta in care se da dublu clic.
Peashooter creeaza noi proiectile Pea iar Sunflower mareste rata cu care apar resursele.
Proiectilele scad viata zombiilor in functie de distanta pana la acestia.
Zombie ataca plantele in functie de distanta si apar pe o banda la intamplare.
Atunci cand un zombie nu este eliminat suficient de rapid acesta reuseste sa ajunga la casa si jocul este pierdut.
Evenimentele se logheaza in log.txt impreuna cu exceptiile.  