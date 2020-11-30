# PCPP2020
Repozytorium do projektu C++

Projekt gry komputerowej dla jednego gracza.  
Gra będzie posiadała wygląd 2D z kamerą top-down. Gracz będzie miał możliwość wyboru
postaci oraz mapy. Sterowanie myszką oraz klawiaturą. Celem gry byłoby przetrwanie np. 10 fal 
nadchodzących przeciwników. Gracz będzie wyposażony w pistolet, który w późniejszych etapach 
będzie mógł ulepszać w sklepie za zdobyte podczas gry kredyty. Różnego rodzaju przeciwnicy (jedni strzelający, 
inni tylko chodzący) z każdą falą będą coraz silniejsi i będzie ich coraz więcej. Gracz będzie miał
ograniczoną ilość życia i amunicji, którą będzie musiał podnosić z pokonanych przeciwników aby przetrwać.

Podział pracy:  
Mateusz Oryl - gracz, przeciwnicy, broń, poziom trudności, wypadanie rzeczy z przeciwników  
Hubert Dziedziura - mapy, menu, sklep, interakcje z przeszkodami, tekstury postaci, przeciwników, broni, mapy

Technologie użyte do projektu:
Biblioteka SFML


Stan gry na 18.10.2020:
- możliwość włączenia okna
- szkielet projektu

Stan gry na 03.11.2020:
- poruszanie graczem za pomocą WASD
- mapa i kolizje ze ścianami
- prototyp przeciwników
- poruszanie się przeciwników w strone gracza
- interakcje przeciwników z graczem i ścianami

TODO na 17.11.2020:
- menu z podstawowymi funkcjami
- stworzenie prototypu broni
- możliwość zabijania przeciwników

Stan gry na 17.11.2020:
- funkcjonalne menu
- gracz ma możliwość strzelania do przeciwników
- przeciwnicy "umierają" po trafieniu pociskiem
- pociski znikają po trafieniu w przeciwnika lub w przeszkodę

TODO na 01.12.2020:
- nowa mapa
- wypadanie przedmiotów z przeciwników
- przygotowanie pierwszego poziomu
- dodanie możliwości umierania gracza

Stan gry na 01.12.2020:
- wypadanie przedmiotów z przeciwników
- przygotowanie pierwszych dwóch poziomów gry
- po przejściu każdego poziomu uruchamia się sklep, w którym można kupić ulepszenia broni i postaci
- ulepszony wygląd menu i sklepu

TODO na 15.12.2020:
- stworzenie wszystkich 10 poziomów
- dodanie zakończenia gry, podliczenie punktów i statystyk
