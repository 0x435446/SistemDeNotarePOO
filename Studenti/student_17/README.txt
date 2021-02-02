la pornirea jocului se introduce un username, apoi se introduce un nivel ce va
determina numarul de randuri ale terenului de lupta

joc:
implementate 2 mecanisme de tip fabrica pentru resurse si zombie. acestea creeaza
resurse/zombie intr-un mod random in zonele specifice de aparitie a acestor entitati
afisabile. in cazul entitatilor de tip zombie se tine cont de tipul terenului de lupta.

poo:
singleton: terenul de lupta, fabrica de resurse, fabrica de zombie si superzombie
diamond inheritance: superzombie
virtual destructor: plante si plante tragatoare, proiectile, zombie si resurse
metode abstracte la nivelul claselor: plante si proiectile
clasa de exceptii cu operatorul << supraincarcat

am folosit std::string