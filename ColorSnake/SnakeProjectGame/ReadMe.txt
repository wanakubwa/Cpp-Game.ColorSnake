Projekt gra w wê¿a "snake" autor: Fabian Berda
Projekt zosta³ uwtorzony w Visiual Studio 2015 z wykorzystaniem biblioteki SFML. Instrukcja podpiêcia dodatkowych
bibliotek zawartych w plikach projektu znajduje siê poni¿ej.

Rozgrywka:
W grze "snake" w¹¿ po zjedzeniu kolejnych punktów delikatnie zmienia odcieñ zaczynaj¹c od RGB(0,255,0). Jest to dobrze
zauwa¿alne po zjedzeniu okolo 20 kolorowych kwadratów migaj¹cych na ekranie. Kwadraty pojawiaj¹ siê zgodnie z polem
mo¿liwych ruchów wê¿a tzn. wpasowuj¹ siê w sztucznie utworzon¹ siatkê na rzecz specyficznego ruchu wê¿a.
Dodatkowo w grze znajduje siê UI pokazuj¹ce aktualn¹ liczbê punktów zdobytych od poczatku rozgrywki oraz logo gry.
Rozgrywka koñczy siê w dwóch przypadkach:
-œmierci wê¿a poprzez wyjechanie poza brzegi pola gry lub najechania g³ow¹ na swój ogon czyli próba zjedzenia samego siebie
-wygranej polegaj¹cej na zdobyciu odpowiedniej iloœci punktów bêd¹cej sum¹ wszystkich kwadratów siatki pola gry -1 kwadrat
poniewa¿ g³owa zajmuje na pocz¹tku gry jedno pole przy 0 iloœci punktów
Po zakoñczeniu rozgrywki pojawia siê odpowiednie menu gry (Menu, DedMenu, WinMenu) z ka¿dego mo¿liwe jest ponowne
uruchomienie nowej rozgrywki zaczynaj¹c od wartoœci pocz¹tkowych.

Sterowanie:
W grze wê¿em steruje siê za pomoc¹ klawiszy W,S,A,D reprezentuj¹cych odpowiednio: góra, dó³, lewo, prawo. Mo¿liwe
jest równie¿ sterowanie za pomoc¹ strzalek. W menu mo¿liwe jest proszuszanie za pomoc¹ myszy.

Struktura:
Program posiada dwa g³ówne obiekty steruj¹ce MainGame oraz GameMenager pierwszy odpowiada za wyswietlenie odpowiedniej
sceny w grze zale¿nie od zaistania³ych okolicznoœci. Drugi steruje bezpoœrednio sam¹ rozgrywk¹ u¿ywaj¹c do tego celu innych obiektów.
W pliku nag³ówkowym Settings.h zadeklarowano wszystkie wymiary takie jak:
-Rozmiar okienka gry
-wysokoœæ UI
-Wielkoœæ wê¿a oraz jedzenia

Dodatkowe biblioteki:
Aby program dzia³a³ poprawnie nale¿y umieœciæ w pliku solucji dodatkowe biblioteki SFML. W programie Visiual Studio 2015
nale¿y:
1) Otworzyæ w³aœciwoœci projektu i w zak³adce "C/C++"/General w punkcie "Additional Include Directories" nacisn¹c przycisk 
"Edit" oraz dodaæ (Ctrl-insert) nastêpuj¹c¹ liniê "$(SolutionDir)/../External_Libraries/SFML/include".

2) W zak³adce "Linker"/"General" w punkcie "Additional Include Directories" nacisn¹c przycisk 
"Edit" oraz dodaæ (Ctrl-insert) nastêpuj¹c¹ liniê "$(SolutionDir)/../External_Libraries/SFML/lib"

3) W zak³adce "Linker"/"Input" w punkcie "Additional Dependencies" nacisn¹æ przycisk "Edit" oraz dodaæ:
"
sfml-main-d.lib
sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-audio-d.lib
"
Po zastosowaniu powy¿szej instrukcji program powinien uruchomiæ siê bezb³êdów w trybie graficznym.
