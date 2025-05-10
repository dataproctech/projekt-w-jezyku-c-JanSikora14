# Specyfikacja projektu
Gra kółko i krzyżyk dla dwóch graczy, zaprogramowana w języku c, działająca w terminalu. Gra umożliwia: 
1. Zapis danych w postaci ilości wygranych i przegranych meczy do pliku txt, obsługa nicków
2. Zapisywanie stanu planszy w strukturze tablicy dwuwymiarowej
3. Wybór przez gracza pola na planszy do zaznaczenia
4. Obsługa tur
5. Wykrywanie wygranej i remisu
6. Blokada nadpisania zaznaczonego pola
7. Rysowanie planszy w terminalu
8. Wypisywanie, resetowanie statystyk
9. Możliwość ponownego rozpoczęcia gry
10. Możliwość zakończenia gry w dowolnym momencie

# Funkcjonalności
### Menu
1. Gracz wybiera czy chce:
- rozpocząć grę
- zarządzać statystykami
- wyjść z gry
### Plansza
1. Rozmiar: 3x3
2. Początkowo puste pola
3. Oznaczenia graczy: X i O
4. Numery pól (np. 1–9) do wyboru ruchu
### Sterowanie
1. Gracze wybierają pole, wpisując numer (1–9)
2. Program sprawdza poprawność wyboru:
  - Czy numer mieści się w zakresie
  - Czy pole nie jest już zajęte
### Przebieg gry
1. Gracze pytani są o podanie pseudonimów
2. Gracze wykonują ruchy na zmianę
3. Po każdym ruchu program sprawdza, czy ktoś wygrał lub czy jest remis
4. Wyświetlenie komunikatu o wyniku gry
5. Zapis wyniku gry do pliku
6. Po zakończeniu: zapytanie, czy rozpocząć nową grę
7. Użytkownik może zakończyć grę w dowolnym momencie (np. przez Ctrl+C lub osobną komendę, np. q)
### Zarządzanie statystykami
1. Gracz wybiera czy chce:
  - wyświetlić statystyki
  - zresetować statystyki
2. Program wyświetla statystyki (nick; wygrane; przegrane; remisy)
3. Program czyści plik ze wszystkich danych i przygotowuje go do ponownego użycia
