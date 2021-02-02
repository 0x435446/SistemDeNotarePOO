Aplicatia PvsZ ruleaza fara parametrii de intrare,ofera posibilitatea de a crea sau loga un utilizator ,alegerea nivelului la inceput .
Jocul cuprinde cateva entitati independente unele fata de celelalte atat prin comportament cat si prin atribute nefiind necesara crearea 
unui arbore de derivari foarte dezvoltat ,clasa Entity (iDrawable) este interfata si este folosita pentru interactiunea dintre obiectele de pe mapa .
Entitati : Sun ,Sunflower ,PeaShooter ,Zombie si ZombieB .
Sori apar random la interval dependent de numarul de Sunflowers de pe mapa si valoreaza 35 de puncte.
Scorul se calculeaza in functie de zombii omorati ,20 de puncte fiecare .
Nivelele au fiecare cate un timp in care se spawneaza zombii la intervale de 5-6 secunde pe lane-uri diferite .
Jocul se termina dupa ce au fost omorati toti zombii si timpul de spawnare ramas este 0 sau dupa ce o entitate de tip zombie ajunge la casa .
Coliziunile dintre Sunflower si Zombie ,respectiv PeaSHooter si Zombie vor da abort din cauza unui bug cauzat de stergerea primului element 
din vector cu erase ,fara sa gasesc raspuns pe internet ,caracterul de coliziune se vede foarte bine intre zombie si proiectile ! 
Fiecare planta peashooter are cate un vector de proiectile,astfel daca un zombie se apropie prea mult va ramane un singur proiectil care va fi sters si 
astfel reapare bugul !
 Plantele se iau cu dublu click ,se planteaza cu dublu click doar pe anumite patratele de pe mapa care sa fie pe aceeasi linie cu zombii ,mijlocul unei 
patratele si un pic spre stanga .Daca proiectilele plantelor suprapun alte plante acele vor disparea ca afisare dar obiectul in sine se afla tot acolo ! 


