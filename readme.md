<h1>Punktacja</h1>
<h2>CW2 (9.5/12)</h2>
Z1 (4/4): OK
<br>
Z2 (3.5/4): Działa, zastrzeżenia: kolejne kroki bez potrzeby powtarzają ustawienie stanów już ustawionych w kroku poprzednim
<br>
Z3 (2/4): Nie działa zgodnie z warunkami zadania.
Gdy (co najmniej) jeden z przycisków wciśnięty LED nie jest włączony trwale (występują krótkotrwałe wyłączenia)
Braki komentarzy
<h2>CW3 (8/12)</h2>
Z1 (2/4): Działa, zastrzeżenia: zorganizowanie rozgałęzień skutkuje nadmiarem kodu
CP nie zadziała poprawnie, jeżeli będą w użyciu także inne linie w rej PIN (niespełnione wymaganie użycia operacji selektywnych!)
Przeorganizowując skoki można było zaoszczędzić 1 instrukcję OUT
<br>
Z2 (3/4): Działa, zastrzeżenia: nie użyto procedury (było wymagane)
<br>
Z3 (3/4): Działa, zastrzeżenia: niewłaściwa reakcja (brak reakcji) na klawisz "LED3/4.."
<h2>CW4 (7.5/12)</h2>
Z1 (2.5/4): Działa, źle dobrane wartości w procedurze opóźnienia, nie stosowano konsekwentnie selektywnych operacji na bitach
<br>
Z2 (2.5/4): Działa, zastrzeżenia jak w Z1
<br>
Z3 (2.5/4): Działa, zastrzeżenia j/w
<h2>CW5 (5/12)</h2>
Z1 (3/4): Działa, zastrzeżenia do kodu programu
<br>
Z2 (2/4): Działa, źle dobrana ilość taktów zegara po preskalerze, wymagana optymalizacja kodu
<br>
Z3 (0/4): Nie działa zgodnie z wymaganiami zadania, wymagana optymalizacja kodu
<h2>CW7 (10/12)</h2>
Z1 (2.5/4): Działa, zastrzeżenia: brak eliminacji/źle eliminacja skutków odbić.
Nie stosowano konsekwentnie selektywnego ustawiania/zerowania pozostawiającego bez zmian stany nieużywanych bitów/linii,
<br>
Z2 (4/4): OK
<br>
Z3 (3.5/4): Działa, zastrzeżenia: brak opóźnienia pomiędzy wysterowaniem linii kolumn a odczytem linii wierszy.
Lepszym rozwiązaniem jest aktywacja kolejnej kolumny na koniec ISR
<h2>CW8 (6/12)</h2>
Z1 (3/4): Działa, zastrzeżenia: tak znaczne opóźnienia w ISR są niedopuszczalne
<br>
Z2 (1/4): Działa, zastrzeżenia: typ integer (16bit) użyty bez uzasadnienia. 
Brak/źle eliminacji skutków odbić.
Tekst nie wyświetlany z właściwej strony LCD/w niewłaściwej linii.
Po CLEAR nie wyświetla zgodnie z wymaganiem/zmienia sposób wyświetlania
<br>
Z3 (2/4): Działa, zastrzeżenia: typ integer (16bit) użyty bez uzasadnienia.
Brak/źle eliminacji skutków odbić.
Po przyciśnięciu CLEAR zmienia sposób wyświetlania, 
