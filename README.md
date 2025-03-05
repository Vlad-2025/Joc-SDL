${\textsf{\color{gold}Work in progress}}$
# Un joc 2D folosind SDL (Simple DirectMedia Layer)

A fost scris urmarind o serie de [tutoriale](https://www.youtube.com/playlist?list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx) de pe YouTube, cu modificari personale.

## De ce SDL?

Pentru ca doream sa vad cum arata programarea de jocuri la un nivel mai de baza decat cea prin intermediul unui motor deja creat, precum Unity sau Unreal Engine, dar nici nu doream sa incep de la zero.

SDL a parut solutia ideala pentru ce doream sa fac, intrucat ofera o interfata intuitiva care ascunde toate implementarile 'low-level' si permite dezvoltarea rapida de programe.

## Ce fel de implementari are proiectul?

Momentan se afla in dezvoltare, dar printre elementele cele mai interesante se numara:
- **Sistem de Componente ale Entitatilor**: (ECS - Entity Component System), care are scopul de a generaliza modalitatea de atribuire a componentelor (cum ar fi texturile, transformarile sau coliziunile) la actori (elemente din joc), pentru a accelera procesul de introducere al entitatilor in joc;
- **Animatii**: putem anima o textura folosind o imagine de tip .PNG care contine toate cadrele animatiei respective, si le parcurgem folosind diferite moduri, in functie de efectul dorit (exista animatii 'Idle'(pentru cand actorul sta pe loc) si animatii 'Walk'(pentru cand actorul se deplaseaza));
- **Harta**: putem crea o harta (sau nivel) prin intermediul unui fisier care contine informatii asupra tipului de 'tile' (numere de 2 cifre) obtinut prin utilizarea unui program dedicat 'pixel-art'-ului, impreuna cu un alt fisier de tip .PNG, care contine tile-urile in sine. Programul extrage tipul de tile dorit din textura in functie de informatia aflata in fisierul .map;
- **Sistem de coliziuni**: am implementat un sistem de coliziuni bazat pe algoritmul 'Axis-Aligned Bounding Box"(AABB), care presupune ca fiecare textura va avea un dreptunghi cat mai mic posibil in jurul sau, care delimiteaza zona de coliziuni cu alte obiecte;
