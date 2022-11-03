<h1>Treści zadań</h1>
<h2>CW2</h2>

<ol>
  <li>Opracować, uruchomić i przetestować program powodujący, że w trakcie, gdy przycisk (button) dołączony do linii PA.1 jest niewciśnięty, dioda LED dołączona do linii PA.0 świeci. Gdy gdy przycisk dołączony do linii PA.1 jest wciśnięty, dioda LED dołączona do linii PA.0 nie świeci. Użyć rozkazów operujących na pojedynczych bitach.</li>
  <li>Opracować i uruchomić program, który powoduje cykliczną (pętla nieskończona) animację świecenia diod LED dołączonych do mikrokontrolera w nastepujący sposób: LED0|LED1|LED2|LED3-	PA0(PortA)|PB0(PortB)|PC0(PortC)|PD0(PortD).
  Sekwencja w animacji jest następująca:
    <ul>
      <li>ON|ON|OFF|OFF - 100ms</li>
      <li>OFF|OFF|ON|ON - 400ms</li>
      <li>OFF|ON|ON|OFF - 100ms</li>
    </ul>
  Do realizacji opóźnienia użyć pętli opóźniających umieszczonych w odpowiednch miejscach w kodzie programu. Poza pętlami opóźnienia używać (w miarę możliwości) rozkazów operujących na pojedynczych bitach.</li>
  <li>Diody podłączone do mikrokontrolera jak w zadaniu 2. Do linii 7  w Port A dołączony jest przycisk "A", natomiast do linii 7 w Port D dołączony jest przycisk "B". Opracować program powodujący, że świecenie diod LED wykonuje następującą cykliczną animację w zależności od stanu przycisków:
    <ul>
      <li>przyciski nieprzyciśnięte:
          <ul>
            <li>ON|ON|OFF|OFF - 500ms</li>
            <li>OFF|OFF|ON|ON - 200ms</li>
          </ul>
      </li>
      <li>przycisk A przyciśnięty (niezależnie od stanu przycisku B) animacja jak w pkt a) z tym, że dioda podłączona do PA0 pozostaje w stanie ON</li>
      <li>przycisk B przyciśnięty (niezależnie od stanu przycisku A) animacja jak w pkt a) z tym, że dioda podłączona do PD0 pozostaje w stanie ON</li>
    </ul>
  Użyć rozkazów operujących na pojedynczych bitach. Użyć pętli opóźniających, identycznie jak wymaga tego zadanie 2. Konstruując program o wariantowym sposobie działania nie używać oddzielnych bloków kodu na realizację poszczególnych wariantów, ponieważ skutkiem takiego sposobu jest niedopuszczalna multiplikacja znaczącej częsci kodu takich bloków!</li>
</ol>

<h2>CW3</h2>
<ol>
  <li>Do linii 0 i linii 1 Portu B mikrokontrolera dołączone są przyciski (wciśnięcie zwiera linię do 0). Do Portu A dołączona jest linijka LED.
  Opracować program powodujący, że gdy niewciśnięte są obydwa przyciski stan świecenia diod LED jest następujący ON|ON|ON|ON|OFF|OFF|OFF|OFF 
  (lewa skrajna pozycja w zapisie obok odpowiada diodzie umieszczonej po lewej stronie na zl3avr itd.). W każdym innym przypadku stan świecenia diod LED jest następujący |OFF|OFF|OFF|OFF|ON|ON|ON|ON. 
  Użyć rozkazów operujących na bajtach typu MOV, AND, OR, EOR, COM ew CP. Do stwierdzenia, że przyciśnięte są dwa przyciski użyć operacji maskowania, a do rozgałęzienia rozkazów typu BREQ/BRNE. Zaprogramowanie kierunków pracy w porcie niewykorzystującym wszystkich linii ma być wykonane tak, żeby dotychczasowe ustawienia kierunków pracy linii nieużywanych pozostały bez zmiany.</li>
  <li>Do Portu A mikrokontrolera dołączona jest "linijka" diod LED. Opracować, uruchomić i przetestować program powodujący animację świecenia diod LED. 
  Animacja polega na tym, że w każdej chwili świecą DWIE, umieszczone kolejno po sobie na diody LED przy czym, pozycja świecących się diod cyklicznie się zmienia począwszy od dołączonych do PA.0 i PA.1, do diod dołączonych do PA.7 i PA.6, po czym sekwencja powtarza się w pętli nieskończonej. 
  Czas świecenia na każdej pozycji wynosi 20ms. 
  Użyć procedury zawierającej programową pętlę opóźnienia czasowego do wytworzenia opóźnienia. Należy przyjąć, że częstotliwość taktowania AVR wynosi 4 MHz.
  Użyć rozkazów operujących na bajtach typu MOV, AND, OR, EOR, rozkazów rotacji/przesunięć a także ewentualnie rozkazów operujących na pojedynczych bitach tak, żeby zminimalizować rozmiar i czas wykonywania kodu.</li>
  <li>Jak w zadaniu 2 z tym, że do linii 0 w porcie B dołączony jest przycisk "LED0/7 - ON", a do linii 0 w porcie D przycisk "LED3/4 - NEG". 
  Gdy przyciski są zwolnione, animacja trwa, jak w zadaniu 2. Przyciśnięcie któregokolwiek przycisku nie ma wpływu na sekwencję animacji (np. nie skraca sekwencji), lecz w czasie, gdy przycisk "LED0/7 - ON" jest wcisnięty na diodach LED0 i LED7 nie widać efektu animacji - pozostają WŁĄCZONE.  Gdy przycisk "LED3/4 - NEG" jest wcisnięty na diodach LED3 i LED4 efekt animacji jest ODWRÓCONY (dioda, która powinna świecić - nie świeci, i odwrotnie).
  Użyć rozkazów operujących na bajtach typu MOV, AND, OR, EOR, itp. Efekt "wyłączenia LED z wizualizacji animacji" uzyskać metodą maskowania.
  Konstruując program o wariantowym sposobie działania nie używać oddzielnych bloków kodu na realizację poszczególnych wariantów, ponieważ skutkiem takiego sposobu jest niedopuszczalna multiplikacja znaczącej częsci kodu takich bloków!</li>
</ol>

<h2>CW4</h2>

<ol>
  <li>Do portu B  dołączona jest "linijka" diod. Do portu C w w systemie zlr3avr dołączone są zaciski segmentów wyświetlacza 7-segmentowego i uaktywniony jest pierwszy z lewej wskaźnik 7-segmentowy. 
  Po starcie programu stan świecenia diod dołączonych do Port B jest następujący ON|ON|ON|ON|ON|ON|ON|ON| (od lewej dioda podłączona do linii 7 w Port B, itd.). 
  Po starcie programu stan świecenia diod dołączonych do Port C (od lewej dioda podłączona do linii 7 w Port C, itd.) jest następujący ON|OFF|OFF|OFF|OFF|OFF|OFF|OFF. 
  UWAGA! studenci używający systemu zlr3avr zobowiązani są uwzględnić właściwą polaryzację sygnału wymaganą dla włączenie LED z linijki diod i segmentu na wskaźniku 7-segmentowym).
  Do linii 3 w porcie D (linia zgłaszania przerwania zewnętrznego INT1) dołączony jest przycisk (button). Wciśnięcie przycisku oznacza zwarcie linii do masy (logiczne 0).
  Działanie programu: pętla główna programu steruje portem C w ten sposób, że pozycja na której świeci się dioda zmienia się cyklicznie w kierunku od diody dołączonej do PC7 do PC0, co 20 ms. Port B sterowany jest w procedurze obsługi przerwania zewnętrznego INT1. Każdorazowo po przycisnięciu przycisku stan świecenia linijki diod LED podłączonej do PortB zmienia się na przeciwny (te, które świeciły, nie świecą i odwrotnie). Do realizacji opóźnienia 
  wykorzystać procedurę zawierającą pętlę opóźnienia programowego. Przyjąć, że częstotliwość zegara systemowego wynosi 1MHz. Do realizacji przesuwania użyć
  rozkazów przesunięć (ROR).</li>
  <li>Podłączenia i sterowanie Portu C jak w zadaniu 1. Do linii 0 Portu A podłączona jest pojedyncza dioda z linijki diod.
  Do linii INT0 (PD2) i do linii INT1 (PD3) podłączone są przyciski o właściwościach, jak w Zadaniu 1.
  Po starcie programu dioda podłączona do Portu A jest WYŁĄCZONA. Każdorazowo, gdy nastąpi przyciśnięcie przycisku podłączonego do PD2 
  dioda dołączona do Port A zaświeca. Dioda zmienia stan (jeśli świeciła - gaśnie, gdy nie świeciła - zapala się) kiedy przycisnąć przycisk podłączony do PD3. 
  Sterowanie linią PA.0 w obsłudze przerwań. Sterowanie linią PA.0 nie może modyfikować stanu pozostałych linii Port A.</li>
  <li>Podłączenia do Portu B i Portu C jak w zadaniu 1. Podłączenia przycisków do mikrokontrolera jak w zadaniu 2.
  Po starcie programu obydwa zestawy LED pulsują w rytmie: ON|ON|ON|ON|ON|ON|ON|ON| przez 10ms i OFF|OFF|OFF|OFF|OFF|OFF|OFF|OFF| przez 20ms (tryb 0 animacji). 
  Sterowanie portami do których podłączono diody - w pętli głównej programu. Opóźnienia czasowe zrealizować, jak w zadaniu 1.
  Przyciśnięcie przycisku podłączonego do PD2 powoduje, że diody podłączone do PB.7-6 i PB.1-0 są trwale zgaszone (tryb 1 animacji), a świecenie pozostałych diod poddane jest identycznej animacji jak w trybie 0.  Przyciśnięcie przycisku podłączonego do PD3 powoduje zmianę trybu 0->1 i 1->0. 
  Przyciśnięcia przycisków nie mają wpływu na animację diod podłączonych do Port C.
  W wyniku przyciśnięcia któregokolwiek z klawiszy wymagana zmiana wzoru świecenia LED na zestawie LED dołączonym do Portu B następuje bez zwłoki ("natychmiast" - bez oczekiwania na koniec okresu czasu przewidzianego dla bieżącego kroku animacji).
  Użyć jednobitowego parametru, którego wartość zmieniana jest w procedurach obsługi przerwań zewnętrznych (INT0/INT1), a który używany jest w pętli głównej programu do modyfikacji animacji (zmiany trybu).</li>
</ol>

<h2>CW5</h2>

<ol>
  <li>Do PA0 dołączona jest dioda LED. Do PD2 dołączony jest przycisk (button). Wciśnięcie powoduje zwarcie PD2 do masy (stan 0). 
  Zwolnienie przycisku pozostawia linię niepodłączoną. Do portu C w w systemie zlr3avr dołączone są zaciski segmentów wyświetlacza 7-segmentowego i uaktywniony jest pierwszy z lewej wskaźnik 7-segmentowy.
  Program działa tak, że:
  <ul>
    <li>Na zestawie diod dołączonym do Port C w pętli nieskończonej trwa animacja: ON|ON|ON|ON|ON|ON|ON|ON| przez 150ms i OFF|OFF|OFF|OFF|OFF|OFF|OFF|OFF| przez 150ms. Czas odmierzany za pomocą opóźnienia programowego (biblioteka delay).</li>
    <li>wciśnięcie przycisku włącza LED i inicjuje odmierzanie czasu w timerze. LED gaśnie po upływie 0,5 sekundy (każde wciśnięcie w czasie odmierzania czasu powoduje przedłużenie włączenia LED o w/w czas). Przed odmierzaniem czasu i po odmierzeniu czasu timer ma być zastopowany.</li>
  </ul>
  Obsługa linii PA0 w procedurach obsługi przerwań. Użyj trybu CTC, TOP=OCR1A</li>
  <li>Opracować program, który po starcie na wyjściu linii OC1B generuje przebieg, w którym czas trwania 1 wynosi 190ms (faza 1 cyklu), czas trwania 0 wynosi 380ms (faza 2 cyklu). Czas odmierza timer. Użyć trybu PWM. Do sterowania linią OC1B nie używać obsługi przerwań. Faza 1 rozpoczyna się z minimalnym opoźnieniem w stosunku do startu programu, potrzebnym na wykonanie niebędnych konfiguracji. Do OC1B dołączona jest dioda (tylko, jeżeli jest używany zlr3avr). Zastosuj ten tryb, w którym Wartość TOP umieszczona jest w OCR1A.</li>
  <li>Podłączenia urządzeń zewnętrznych jak w Zadaniu 1. Dodatkowo do PA.7 dołączona skrajna lewa dioda z linijki, której lewa skrajna dioda dołączona jest do PA.0. Opracować program, który na PA.0 generuje powtarzalny przebieg, w którym czas trwania 1 wynosi 0,16s, czas trwania 0 początkowo wynosi 0,32s. 
  Czas odmierza timer.Po starcie programu dioda dołączona do PA7 jest WŁĄCZONA. Każdorazowe wciśnięcie przycisku dolączonego do PD2 powoduje skrócenie czasu trwania o 0,08s przy czym okres powtarzania przebiegu nie może być krótszy, niż 0,192s. Po stwierdzeniu, że dalsze skracanie jest niedozwolone) dioda dołączona do PA7 jest gaszona.
  Użyć timera 1 i trybu CTC z wartością szczytową w OCR1A. Należy tak skonstruować zmianę w OCR1A (w odpowiedzi na przyciśnięcie klawisza), że wyeliminowana jest szkodliwa możliwość zmniejszenia wartości OCR1A w warunkach, gdy nowa wartość < TCNT1 (bieżącej wartości w liczniku timera). W przeciwnym razie po takiej zmianie timer nie zarejestruje przekroczenia wartości zawartej w OCR1A i będzie zliczał aż do 2^16.
  W procedurze main wykonywana jest identyczna animacja, jak w zadaniu 1, z tym że czasy włączenia i wyłaczenia LED mają wynosić po 250ms.</li>
</ol>

<h2>CW7</h2>

<ol>
  <li>Klawiatura składa się z 8-tu klawiszy zorganizowanych w 2 wiersze i 4 kolumny. Każdy z wierszy dołączony jest do pojedynczej wejściowej linii portu D będącej linią wejściową przerwania zewnętrznego: wiersz 0 do INT0, wiersz 1 do INT1. Kolumny klawiatury dołączone są do 4-ech wyjściowych linii portu D (PD7-4). 
  Do portów A, B i C dołączone są linijki LED.
  Opracować program, który rozpoznaje numer wciśniętego klawisza z pojedynego wiersza klawiatury.
  Program w celu zidentyfkowania, który klawisz został wciśnięty, po rozpoznaniu zdarzenia wciśnięcia jednorazowo wykonuje algorytm multipleksowego (sekwencyjnego) obsługiwania klawiatury.
  Numer klawisza liczony od lewej od 1 ( liczba w zakresie od 1 do 8, zgodnie z opisem na zlr3avr, ew. modelu klawiatury w HAPSIM - należy załadowac plik konfiguracyjny) wyświetlany na 3 diodach z prawej strony linijki LED za pośrednictwem 3-ech starszych bitów w PORTA. 
  Czwarta dioda linijki, licząc od prawej ma pozostawać trwale wyłączona. 
  Ponadto, zliczane są łącznie wywołania obydwu procedur obsługujących zgłoszenie wcisnięcia klawisza. Numer wywołania wyświetlany jest 4-ro bitowo 
  na 4 diodach po lewej stronie linijki LED tak, że skrajna lewa dioda wyświetla najstarszy bit, itd.
  Dodatkowo, w "main" na zestawie diod dołączonym do Port C w pętli nieskończonej trwa animacja: ON|ON|ON|ON|ON|ON|ON|ON| przez 150ms 
  i OFF|OFF|OFF|OFF|OFF|OFF|OFF|OFF| przez 150ms. Czas odmierzany za pomocą opóźnienia programowego (biblioteka delay).
  Obsługa klawiatury (WYŁĄCZNIE!) w procedurach obsługi przerwania zewnętrznego.
  UWAGA! Należy wyeliminować skutki odbić styków klawiszy posługując się metodą, jak w ćwiczeniu nr 5.</li>
  <li>Klawiatura składa się z 16 klawiszy umieszczonych na skrzyżowianiach 4 linii kolumn z 4-ema liniami wierszy. 
  Kolumny klawiatury dołączone są do 4-ech linii portu D (PD7-4). Wiersze dołączone są do 4-ech linii portu D (PD3-0). 
  Ponadto do portu A dołączona linijka LED.
  Należy opracować program, który obsługuje klawiaturę zgodnie z algorytmem "z odwracaniem kierunków linii w porcie" oraz, jeżeli stwierdzone zostanie wciśnięcie klawisza, za pośrednictwem portu A wyświetla na linijce LED kod o postaci: "kod aktywnej kolumny (kod 1z4, 4 starsze bity PortA)|kod aktywnego wiersza (kod 1z4, młodsze bity PortA)".
  Kod wyświetla się do czasu przyciśnięcia innego klawisza. Dodatkowo w procedurze main odbywa się animacja jak w zadaniu 1.
  Czas reakcji na przyciśnięcie klawisza na klawiaturze nie dłuższy niż 50 ms. 
  Obsługa klawiatury w procedurze obsługi przerwania (WYŁĄCZNIE!) od timera. Użyć timera 0.</li>
  <li>Klawiatura i zestawy diod LED podłączone są do mikrokontrolera jak w zadaniu 2. 
  Należy opracować program, który obsługuje klawiaturę metodą multipleksacji z cyklicznym odpytywaniem klawiatury. Czas pomiędzy krokami wykonania algorytmu
  odmierzany timerem. Program, jeżeli stwierdzone zostanie wciśnięcie klawisza, za pośrednictwem portu A wyświetla na linijce LED numer wciśniętego klawisza, zgodny z opisem na modelu klawiatury HAPSIM (wczytać plik konfiguracyjny CW4Z3.xml). Kod wyświetla się do czasu przyciśnięcia innego klawisza. 
  Dodatkowo w procedurze main odbywa się animacja wyświetlania za pośrednictwem Portu C, jak w zadaniu 1.
  Czas reakcji na przyciśnięcie klawisza na klawiaturze nie dłuższy niż 50 ms. 
  Obsługa klawiatury w procedurze obsługi przerwania (WYŁĄCZNIE!) od timera. Użyć timera 0.</li>
</ol>

<h2>CW8</h2>

<ol>
  <li>Wyświetlacz LCD programowany jest do pracy w trybie 4bitowym, tryb wyświetlania: 2 linie, format znaku 5x8 pikseli, a następnie na wyświetlaczu wyświetla się nazwisko studenta. W celu wyświetlenia łańcucha tekstowego nazwiska należy w programie umieścić sekwencję wywołań funkcji przesyłającej pojedynczy znak do LCD tak, żeby każda kolejna litera pojedynczo wpisywana była do LCD zaczynając od pierwszej litery nazwiska, a kończąc na ostatniej. LCD obsługiwany przez PORTA - przesyłanie kodów, i 2 linie z portu B (EN-Enable, RS-register select). 
	Opcja wykonania programu: znak wyświetla się z lewej strony wyświetlacza, niewidoczny kursor, znak na pozycji kursora pulsuje</li>
  <li>Wyświetlacz LCD pracuje w trybie 4 bitowym. Obsługa LCD poprzez PortA: komunikacja - bity 4-7, EN(Enable) - bit 1, RS(register select) - bit 0.
    Do PD.2 i PD.3 dołączone są przyciski (po przyciśnięciu zwarcie do masy - logiczne 0). Przycisk A do PD.2, przycisk B do PD.3.
  Po starcie programu wyświelacz nic nie wyświetla. Każde wciśnięcie przycisku A wyświetla na LCD pojedynczy kolejny znak z imienia studenta. Tekst imienia
   zapisany w tablicy umieszczonej w pamięci programu. Sposób utworzenia tablicy z tekstem musi zapewniać, że końcowym elementem tablicy jest bajt=0x00.
  Po osiągnięciu końca napisu, dalsze przyciśnięcia przycisku A nie powodują żadnego skutku. Do stwierdzenia osiągnięcia końca napisu należy wykorzystać
  wiedzę o wartości ostatniego elementu tablicy. Każde wciśnięcie przycisku B czyści LCD. Obsługa przycisków w przerwaniach zewnętrznych. 
  Należy zastosować technikę eliminacji skutków odbić styków przycisków, jak w ćwiczeniu nr 5.
  Ponadto, w procedurze "main" na zestawie diod dołączonym do Port C w pętli nieskończonej trwa animacja: ON|ON|ON|ON|ON|ON|ON|ON| przez 150ms 
  i OFF|OFF|OFF|OFF|OFF|OFF|OFF|OFF| przez 150ms. Czas odmierzany za pomocą opóźnienia programowego (biblioteka delay).
  Opcja wykonania programu: napis pojawia się z lewej strony wyświetlacza</li>
  <li>Konfiguracja LCD jak powyżej. Do PD.2 i PD.3 dołączone są przyciski (po przyciśnięciu zwarcie do masy - logiczne 0). 
  Przycisk A do PD.2, przycisk B do PD.3. W PAMIĘCI DANYCH umieszczono 5-bajtową tablicę zawierającą następującą sekwencję bajtów: 02 F1 38 BA 97.
  Po starcie programu wyświelacz nic nie wyświetla. Każde wciśnięcie przycisku A wyświetla na LCD (po zamianie na odpowiadający kod ASCII) parę znaków
  reprezentujących obydwa półbajty kolejnego bajtu z tablicy. Do zamiany należy użyć tablicy transkodującej z kodu szestnastkowego na  kod ASCII (cyfry 0-F, 
  cyfry symbolizowane literami używają wielkich liter). Tablica transkodująca w PAMIĘCI PROGRAMU. Bajty tablicy mają być wyświetlone tak, 
  żeby pomiędzy parami cyfr kolejnych bajtów występowały spacje, a układ napisu zgodny był z powyżej umieszczonym zapisem zawartości tablicy bajtów (od lewej do prawej).
  Każde wciśnięcie przycisku B czyści LCD i przygotowuje do wyświetlenia zawartości tablicy od początku.Obsługa przycisków w przerwaniach zewnętrznych. P
  Ponadto, w procedurze main świecenie zestawu diod dołączonych do PortC poddawane jest animacji, jak w Zadaniu 2.
  Opcja wykonania programu: napis pojawia się z prawej strony wyświetlacza</li>
</ol>

<h2>CW9</h2>

<ol>
  <li>Wyświetlacz LCD skonfigurowany jest do wyświetlania 2 linii, format znaku 5x8. Interfejs 4-bitowy. Komunikacja PA7-4, EN - PA1, RS - PA0.
  Program przyjmuje z klawiatury matrycowej liczbę składająca  się z max 16 cyfr szestanstkowych (blokada pobierania, przy próbie wprowadzenia większej liczby cyfr). 
  Wyświetla liczbę, w miarę wprowadzania kolejnych cyfr, na wyświetlaczu LCD począwszy od lewej. Każde wprowadzenie znaku przesuwa kursor w prawo.
  Wprowadzenie kolejnego znaku umieszcza go na dotychczasowej pozycji kursora.
  Wyświetlana liczba jest numerem klawisza w zakresie 0-15 zgodnie z opisem podanym poniżej:
    <table>
      <tr><td>S1<->0</td>	<td>S2<->4</td>	<td>S3<->8</td>		<td>S4<->12</td></tr>
      <tr><td>S5<->1</td>	<td>S6<->5</td>	<td>S7<->9</td>		<td>S8<->13</td></tr>
      <tr><td>S9<->2</td>	<td>S10<->6</td>	<td>S11<->10</td>	<td>S12<->14</td></tr>
      <tr><td>S13<->3</td>	<td>S14<->7</td>	<td>S15<->11</td>	<td>S16<->15</td></tr>
    </table>
  Ponadto, linia PD2 ("Clear") w obsłudze przerwania INT0 (reakcja na zbocze opadające) wywołuje wczyszczenie wyświetlacza (kursor do lewego rogu). Na stanowisku zl3avr stan "0" należy podać podłączając na chwilę za pomocą przewodu wejście PD2 do GND. Zamiany binarnego/integer numeru klawisza na kod ASCII (wymagany przez LCD) dokonać używając tablicy transkodowania. Tablica transkodowania ma być umieszczona w pamięci programu.
  Czas reakcji na przyciśnięcie klawisza na klawiaturze nie dłuższy niż 40 ms. Czas odmierzany timerem. Odczyt klawiatury realizowany multipleksowo w obsłudze przerwania od timera (1 kolumna aktywowana w danej instancji obsługi przerwania). 
  Klawiatura dołączona do portu B. Kolumny PB7-4, wiersze PB3-0.</li>
  <li>Wyświetlacz LCD skonfigurowany jest do wyświetlania 2 linii, format znaku 5x8. Interfejs 4-bitowy. Komunikacja PA7-4, EN - PA1, RS - PA0.
  Program przyjmuje z klawiatury matrycowej liczbę dziesiętną (cyfry 0-9) i wyświetla tę liczbę, w miarę wprowadzania kolejnych cyfr, na wyświetlaczu LCD.
  Na zl3avr cyfry (i funkcje) odpowiadające poszczególnym klawiszom są następujące:
    <table>
      <tr><td>S1<->3</td>	<td>S2<->NC</td>	<td>S3<->NC</td>		<td>S4<->CLEAR</td></tr>
      <tr><td>S5<->6</td>	<td>S6<->2</td>	<td>S7<->NC</td>		<td>S8<->NC</td></tr>
      <tr><td>S9<->8</td>	<td>S10<->5</td>	<td>S11<->1</td>	<td>S12<->NC</td></tr>
      <tr><td>S13<->9</td>	<td>S14<->7</td>	<td>S15<->4</td>	<td>S16<->0</td></tr>
    </table>
  Po starcie program wyświetli pobierane znaki w górnej linii zaczynając od: lewej.
  Każde wprowadzenie znaku przesuwa kursor w prawo. Wprowadzenie kolejnego znaku umieszcza go na dotychczasowej pozycji kursora (jak w Z1).
  Po osiągnięciu przez kursor ostatniej wyświetlanej pozycji w górnej linii kursor zatrzymuje się, natomiast każde wprowadzenie kolejnego znaku przesuwa dotychczasową treść (całą zawartość wyświetlacza) o 1 pozycję w kierunku przeciwnym niż kierunek, w którym dotąd następowało wprowadzanie znaków.
  Program reaguje na przyciśnięcie klawisza "Clear" wyczyszczeniem wyświetlacza (kursor do pozycji początkowej, jak po starcie programu). 
  Przyciśnięcia pozostałych klawiszy klawiatury są ignorowane. 
  Ponadto, przytrzymywanie klawisza "Clear" ponad 1s (dla testowania na emulatorze skrócić 10 krotnie) czyści wyświetlacz i przełącza do wyświetlania w 2-iej linii.
  Zamiana kodu binarnego/integer na ASCII, jak w zadaniu 1. Czas reakcji na przyciśnięcie klawisza na klawiaturze nie dłuższy niż 40 ms. Czas odmierzany timerem.
  Odczyt klawiatury realizowany multipleksowo w obsłudze przerwania od timera. Klawiatura dołączona do portu B. Kolumny PB7-4, wiersze PB3-0.</li>
  <li>Program i połaczenia, jak w zadaniu 2. Poszczegółnym klawiszom na zl3avr odpowiadają następujące znaki i funkcje:
    <table>
      <tr><td>S1<->3</td>	<td>S2<->Enter</td>	<td>S3<->Left</td>		<td>S4<->NC</td></tr>
      <tr><td>S5<->6</td>	<td>S6<->2</td>	<td>S7<->Right</td>		<td>S8<->Down</td></tr>
      <tr><td>S9<->8</td>	<td>S10<->5</td>	<td>S11<->1</td>	<td>S12<->Up</td></tr>
      <tr><td>S13<->9</td>	<td>S14<->7</td>	<td>S15<->4</td>	<td>S16<->CLEAR</td></tr>
    </table>
  Działanie klawisza "Clear", jak w zadaniu 2. 
  Działanie pozostałych klawiszy funkcyjnych, jak w poniższym opisie:
    <ul>
      <li>przycisnięcie klawisza "Up" powoduje przeniesienie wprowadzania tekstu do górnej linii (chyba, że obecnie już jest ustawione wprowadzanie do górnej linii). Kursor na pierwszej, dotąd niezapisanej, pozycji w linii</li>
      <li>przycisnięcie klawisza "Down" powoduje przeniesienie wprowadzania tekstu do dolnej linii (chyba, że obecnie już jest ustawione wprowadzanie do dolnej linii). Kursor na pierwszej, dotąd niezapisanej, pozycji w linii</li>
      <li>przycisnięcia klawisza "Left" powoduje przesunięcie treści obecnie aktywnej linii w lewo o 1 pozycję</li>
      <li>przycisnięcia klawisza "Right" powoduje przesunięcie treści obecnie aktywnej linii w prawo o 1 pozycję</li>
      <li>na przyciśnięcie klawisza "Enter" program nie reaguje</li>
    <ul>
  </li>
</ol>

<h1>Punktacja (49/84)</h1>
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
<h2>CW9 (3/12)</h2>
Z1 (1/4): Działa, zastrzeżenia: użyto typ int (16bit) bez uzasadnienia, eliminacja skutków odbić w ISR INT0 - brak/źle, przed czytaniem z PIN klawiatury niezbędne opóźnienie (~3us), kody klawiszy niezgodne z wymaganiem zadania
<br>
Z2 (2/4): Działa, zastrzeżenia: uwagi jak do Z1, kody klawiszy niezgodne z wymaganiem zadania, nie należy powtarzać kroków przeprogramowujących kierunek przesuwania tekstu, nie działa/nie działa poprawnie "long clear"
<br>
Z3 (0/4): BRAK
