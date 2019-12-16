Projekt gra w w�a "snake" autor: Fabian Berda
Projekt zosta� uwtorzony w Visiual Studio 2015 z wykorzystaniem biblioteki SFML. Instrukcja podpi�cia dodatkowych
bibliotek zawartych w plikach projektu znajduje si� poni�ej.

Rozgrywka:
W grze "snake" w�� po zjedzeniu kolejnych punkt�w delikatnie zmienia odcie� zaczynaj�c od RGB(0,255,0). Jest to dobrze
zauwa�alne po zjedzeniu okolo 20 kolorowych kwadrat�w migaj�cych na ekranie. Kwadraty pojawiaj� si� zgodnie z polem
mo�liwych ruch�w w�a tzn. wpasowuj� si� w sztucznie utworzon� siatk� na rzecz specyficznego ruchu w�a.
Dodatkowo w grze znajduje si� UI pokazuj�ce aktualn� liczb� punkt�w zdobytych od poczatku rozgrywki oraz logo gry.
Rozgrywka ko�czy si� w dw�ch przypadkach:
-�mierci w�a poprzez wyjechanie poza brzegi pola gry lub najechania g�ow� na sw�j ogon czyli pr�ba zjedzenia samego siebie
-wygranej polegaj�cej na zdobyciu odpowiedniej ilo�ci punkt�w b�d�cej sum� wszystkich kwadrat�w siatki pola gry -1 kwadrat
poniewa� g�owa zajmuje na pocz�tku gry jedno pole przy 0 ilo�ci punkt�w
Po zako�czeniu rozgrywki pojawia si� odpowiednie menu gry (Menu, DedMenu, WinMenu) z ka�dego mo�liwe jest ponowne
uruchomienie nowej rozgrywki zaczynaj�c od warto�ci pocz�tkowych.

Sterowanie:
W grze w�em steruje si� za pomoc� klawiszy W,S,A,D reprezentuj�cych odpowiednio: g�ra, d�, lewo, prawo. Mo�liwe
jest r�wnie� sterowanie za pomoc� strzalek. W menu mo�liwe jest proszuszanie za pomoc� myszy.

Struktura:
Program posiada dwa g��wne obiekty steruj�ce MainGame oraz GameMenager pierwszy odpowiada za wyswietlenie odpowiedniej
sceny w grze zale�nie od zaistania�ych okoliczno�ci. Drugi steruje bezpo�rednio sam� rozgrywk� u�ywaj�c do tego celu innych obiekt�w.
W pliku nag��wkowym Settings.h zadeklarowano wszystkie wymiary takie jak:
-Rozmiar okienka gry
-wysoko�� UI
-Wielko�� w�a oraz jedzenia

Dodatkowe biblioteki:
Aby program dzia�a� poprawnie nale�y umie�ci� w pliku solucji dodatkowe biblioteki SFML. W programie Visiual Studio 2015
nale�y:
1) Otworzy� w�a�ciwo�ci projektu i w zak�adce "C/C++"/General w punkcie "Additional Include Directories" nacisn�c przycisk 
"Edit" oraz doda� (Ctrl-insert) nast�puj�c� lini� "$(SolutionDir)/../External_Libraries/SFML/include".

2) W zak�adce "Linker"/"General" w punkcie "Additional Include Directories" nacisn�c przycisk 
"Edit" oraz doda� (Ctrl-insert) nast�puj�c� lini� "$(SolutionDir)/../External_Libraries/SFML/lib"

3) W zak�adce "Linker"/"Input" w punkcie "Additional Dependencies" nacisn�� przycisk "Edit" oraz doda�:
"
sfml-main-d.lib
sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
sfml-audio-d.lib
"
Po zastosowaniu powy�szej instrukcji program powinien uruchomi� si� bezb��d�w w trybie graficznym.
