<h1>Treści zadań</h1>
<h2>CW2</h2>
1. Opracować, uruchomić i przetestować program powodujący, że w trakcie, gdy przycisk (button) dołączony do linii PA.1 jest niewciśnięty, dioda LED dołączona do linii PA.0 świeci. Gdy gdy przycisk dołączony do linii PA.1 jest wciśnięty, dioda LED dołączona do linii PA.0 nie świeci. Użyć rozkazów operujących na pojedynczych bitach.
2. Opracować i uruchomić program, który powoduje cykliczną (pętla nieskończona) animację świecenia diod LED dołączonych do mikrokontrolera w nastepujący sposób: LED0|LED1|LED2|LED3-	PA0(PortA)|PB0(PortB)|PC0(PortC)|PD0(PortD).
Sekwencja w animacji jest następująca:
  a. ON|ON|OFF|OFF - 100ms
  b. OFF|OFF|ON|ON - 400ms
  c. OFF|ON|ON|OFF - 100ms

Do realizacji opóźnienia użyć pętli opóźniających umieszczonych w odpowiednch miejscach w kodzie programu. Poza pętlami opóźnienia używać (w miarę możliwości) rozkazów operujących na pojedynczych bitach.
3. Diody podłączone do mikrokontrolera jak w zadaniu 2. Do linii 7  w Port A dołączony jest przycisk "A", natomiast do linii 7 w Port D dołączony jest przycisk "B". Opracować program powodujący, że świecenie diod LED wykonuje następującą cykliczną animację w zależności od stanu przycisków:
  a. przyciski nieprzyciśnięte:
      - ON|ON|OFF|OFF - 500ms
      - OFF|OFF|ON|ON - 200ms  
  b. przycisk A przyciśnięty (niezależnie od stanu przycisku B)
    animacja jak w pkt a) z tym, że dioda podłączona do PA0 pozostaje w stanie ON
  c. przycisk B przyciśnięty (niezależnie od stanu przycisku A)
    animacja jak w pkt a) z tym, że dioda podłączona do PD0 pozostaje w stanie ON
Użyć rozkazów operujących na pojedynczych bitach. Użyć pętli opóźniających, identycznie jak wymaga tego zadanie 2. Konstruując program o wariantowym sposobie działania nie używać oddzielnych bloków kodu na realizację poszczególnych wariantów, ponieważ skutkiem takiego sposobu jest niedopuszczalna multiplikacja znaczącej częsci kodu takich bloków!

<h2>CW3</h2>

<h2>CW4</h2>

<h2>CW5</h2>

<h2>CW7</h2>

<h2>CW8</h2>

<h2>CW9</h2>

<h1>Punktacja (46/84)</h1>
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
<h2>CW9 (?/12)</h2>
Z1 (?/4):
<br>
Z2 (?/4): 
<br>
Z3 (0/4): 
