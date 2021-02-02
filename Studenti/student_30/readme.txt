-In primul rand am facut o clasa Entity in care am declarat 2 functii virtuale(void draw() si void update(std::string).
-Din aceasta clasa "Entity" se vor deriva clasele: Plant, Ground, Proiectile, Zona, Resurse, Scor si Zombie. In aceste clase
vor exista cele 2 functii din "Entity".
-Din clasa "Plant" se deriveaza alte 2 clase: "Sunflower","Peashooter", in aceste clase vom avea un vector de proiectile <Pea*>.
-Din clasa "Proiectile" se deriveaza clasa "Pea";
-Din clasa "Resurse" se va deriva clasa "Sun";
-Din clasa "Zombie" se vor deriva 2 clase: "Zombie_banal" si "BucketHead_Zombie";
-Clasa "Scor" va tine evidenta resurselor de tip Sun, in momentul cand vom apasa pe un obiect de tip Sun, scorul va creste cu 25(uneori
nu merge sa dispara soarele doar prin dublu-click, trebuie apasat de vreo 3-4 ori);
-Clasa "Zona" este clasa unde imi construiesc fiecare zona din joc: zonele unde se bate zombie-ul cu planta, zona unde imi apar resursele,
zona unde vor aparea plantele si zona unde se va afisa scorul.
-Clasa "Ground" e terenul unde se bate zombie-ul cu plantele.
-Evidenta utilizatorilor este tinuta intr-un fisier text "Users.txt".

Am realizat toate clasele, am desenat fiecare entitate, insa nu am facut ca zombie-ul sa sa se lupte cu planta si nici mutarea plantelor pe teren.