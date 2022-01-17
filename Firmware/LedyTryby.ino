#include <FastLED.h>    //załączamy bibliotekę FastLED, ponieważ po  
#define LED_PIN 6   //definiujemy Pina z którego bedą wysyłane sygnały, w tym przypadku jest do pin D6
#define NUM_LEDS 124    //podajemy tutaj liczbę ledów, których łącznie jest 124

CRGB leds[NUM_LEDS];    //chcemy aby nasze ledy były definiowane w przestrzeni RGB, w tym przypadku akurat GRB, gdzie trzy jednobajtowe wartości od 0-255 będą definiować kolor ledów 

void setup() {    //w tym voidzie zainicjujemy ledy i ustalimy podstawowe wartości, takie jak jasność ledów, 
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.clear();    //komenda, która czyści ledy, czyli ustawia na nich wartości (0, 0 ,0). czyli kolor czarny - wygaszenie ledów
  FastLED.show();   //komenda, która odświeża ledy, czyli jeżeli za pomocą kodu zmieniliśmy wartość kolorów ledów, to dzięki niej te zmiany "wejdą w życie" 
  Serial.begin(9600);   //ustawiamy szybkość transmisji danych w bitach na sekundę dla szeregowej transmisji danych.
  FastLED.setBrightness(255);   //janość ledów na maksa
  randomSeed(analogRead(0));    //za pomocą tej komendy określamy skąd są pobierane dane do generatora liczb losowych,
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Policja() {    //to jest funkcja, za pomocą której zamieniamy sie w policjantów, a nasz monitor to radiowóz,
for (int i=0; i<NUM_LEDS; i++) {
    leds[(NUM_LEDS/2)+i] = CRGB(0,0, 255); //GRB    w pierwszych trzech linijkach widać, że dzielimy ledy na pół, ponieważ chcemy zacząć kolor od góry
    leds[(NUM_LEDS/2)+i+1] = CRGB(0,0, 255); //GRB    mamy tutaj 3 linijki aby kolor nie szedł tylko z jednego leda na raz ale z trzech
    leds[(NUM_LEDS/2)+i+2] = CRGB(0,0, 255); //GRB    kolor niebieski będzie obiegać monitor ze środka na lewą stronę
    
    leds[(NUM_LEDS/2)-i] = CRGB(0, 255, 00); //GRB    w drugiej połowie odejmujemy zmienną zamiast ją dodawać, co spowoduje że kolor czerwony pójdzie w drugą stronę 
    leds[(NUM_LEDS/2)-i-1] = CRGB(0, 255, 00); //GRB
    leds[(NUM_LEDS/2)-i-2] = CRGB(0, 255, 00); //GRB    
    
    FastLED.show();   //po każdej pętli ledy się aktualizują
    delay(1);
    FastLED.clear();    //po malutkim opóźnieniu ledy sie czyszczą
 } 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RainbowSpin() {    //za pomocą tej funkcji zmieniamy się w fanatyków LGBT i za ekranem kręci się tęcza, która zatacza kółka i z każdą rotacją zmienia kolor na następny kolor w tęczy
// Czerwony
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(0, 255, 0); //GRB
    delay(1);
    FastLED.show();
}
// Pomarańczowy   nie musimy tutaj czyscic ledów bo i tak nowy kolor będzie się nadpisywał na stary
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(80, 255, 0); //GRB
    delay(1);
    FastLED.show();
}
// Żółty
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(150, 255, 0); //GRB
    delay(1);
    FastLED.show();
}
// Zielony
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(255, 0, 0); //GRB
    delay(1);
    FastLED.show();
}
// Niebieski
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(170, 0, 255); //GRB
    delay(1);
    FastLED.show();
}  
// Fioletowy
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(0, 75, 110); //GRB
    delay(1);
    FastLED.show(); 
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void RainbowPong() {    //tutaj jest podobnie tak samo jak w poprzednim RainboSpin, ale w tym przypadku zamiast zataczać pełne koło, to kolor będzie się odbijał jak skończą mu sie ledy
// Czerwony
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(0, 255, 0); //GRB
    delay(2);
    FastLED.show();
}
// Pomarańczowy
for (int i=NUM_LEDS-1; i>0; i-- ) {   //jedyna zmiana w tym trybie to jest w pętli for, co powoduje, że ledy zapalają się od końca do początku
    leds[i] = CRGB(80, 255, 0); //GRB
    delay(2);
    FastLED.show();
}
// Żółty
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(150, 255, 0); //GRB
    delay(2);
    FastLED.show();
}
// Zielony  
for (int i=NUM_LEDS-1; i>0; i-- ) {   //i taką zmianę stosujemy w co drugiej pętli
    leds[i] = CRGB(255, 0, 0); //GRB
    delay(2);
    FastLED.show();
}
// Niebieski
for (int i=0; i<NUM_LEDS; i++ ) {
    leds[i] = CRGB(170, 0, 255); //GRB
    delay(2);
    FastLED.show();
}  
// Fioletowy
for (int i=NUM_LEDS-1; i>0; i-- ) {
    leds[i] = CRGB(0, 75, 110); //GRB
    delay(2);
    FastLED.show();
} 
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Epilepsja() {    //tutaj mamy niebezpieczną pętlę, do której idealnie przydadzą nam się losowe liczby
leds[random(NUM_LEDS)] = CRGB(random(255), random(255), random(255));   //losowa dioda led zapali się na losowy kolor
leds[random(NUM_LEDS)] = CRGB(random(255), random(255), random(255));   //i kolejna zrobi tak samo i tak dalej
leds[random(NUM_LEDS)] = CRGB(random(255), random(255), random(255));   
leds[random(NUM_LEDS)] = CRGB(random(255), random(255), random(255));
leds[random(NUM_LEDS)] = CRGB(random(255), random(255), random(255));
FastLED.show();
delay(20);
FastLED.clear();    //aby nam się szybko nie zapchały ledy to po pięciu takich losowych ledach czyścimy je wszystkie i pojawiają sie na ich miejsce bardzo szybko kolejne, co powoduje efekt migających losowo światełek
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int row1[124] = {0,123,1,122,2,121,3,120,4,119,5,118,6,117,7,116,8,115,9,114,10,113,11,112,12,111,13,110,14,109,15,108,16,107,17,106,18,105,19,104,20,103,21,22,100,23,101,24,102,25,97,26,98,27,99,28,94,29,95,30,96,31,91,32,92,33,93,34,88,35,89,36,90,37,85,38,86,39,87,40,84,41,83,42,82,43,81,44,80,45,79,46,78,47,77,48,76,49,75,50,74,51,73,52,72,53,71,54,70,55,69,56,68,57,67,58,66,59,65,60,64,61,63,62};
//tutaj powyżej zdefinowałem tablicę w taki sposób, aby od początku i od końca ledy szły do środka paska ledów w tym samym tempie
void  PionowaPulsacja() {   //PionowaPulsacja, poniważ kolor idzie zamiast z jednej strony na drugą to do pionowo do górę i w dół

for (int i=(NUM_LEDS-1); i>=0; i--){    //I ostani, mój ulubiony tryb ledów. W tej funkcji są dwa rodzaje pętli, pętlam, w której kolor ledów zmienia się i po wypełnieniu znika stopnionwo
 leds[row1[i]] = CRGB(0, 255, 0); //GRB   oraz taki, w której kolor idzie w postaci dwóch "wężyków" o długości dwudziestu ledów
 leds[row1[i+20]] = CRGB(0, 0, 0); //GRB    ta pętla jest dla wersji z wężykiem i widzmy, że w tej pętli czekamy aż pętla przetworzy się dwadzieścia razy aby zacząć wygaszać ledy
    FastLED.show();
    delay(10); 
}
    for (int i=20; i>0; i--){   //ta pętla jest nam potrzebna aby wyłączyć ledy, które zostaną po tym jak wąż dojedzie, ponieważ bez tej pętli, dwadzieścia ledów z obu stron byłoby zapalone cały czas
 leds[row1[i]] = CRGB(0, 0, 0); //GRB   prościej byłoby użyć po prostu comendy FastLED.clear(), ale to zamiast wyłączyć ledy po kolei, na czym nam zależy, to wyłączyłaby je wszyskie za jednym razem
    FastLED.show();
    delay(10); 
}
  delay(100); 
  
for (int i=0; i<NUM_LEDS; i++){   //w tej pętli, nasze ledy z wczesniej zdefiniowanej tablicy odpowiednio się wszystkie zapalą na dany kolor a w następnej pętli, po kolei zgasną
 leds[row1[i]] = CRGB(0, 255, 0); //GRB
    FastLED.show();
    delay(10); 
}
    for (int i=0; i<NUM_LEDS; i++){
 leds[row1[i]] = CRGB(0, 0, 0); //GRB
    FastLED.show();
    delay(10); 
}
  delay(100); 

for (int i=(NUM_LEDS-1); i>0; i--){   //ta pętla jest ta sama co poprzednia, ale tym razem z góry do dołu
 leds[row1[i]] = CRGB(0, 255, 0); //GRB
    FastLED.show();
    delay(10); 
}
    for (int i=(NUM_LEDS-1); i>0; i--){
 leds[row1[i]] = CRGB(0, 0, 0); //GRB
    FastLED.show();
    delay(10); 
}
  delay(100); 

for (int i=0; i<NUM_LEDS; i++){   //a ta pętla jest ta sama jak pierwsza ale również tym razem akurat z dołu do góry
 leds[row1[i]] = CRGB(0, 255, 0); //GRB
 leds[row1[i-20]] = CRGB(0, 0, 0); //GRB
    FastLED.show();
    delay(10); 
}
for (int i=103; i<NUM_LEDS; i++){   //również zostanie nam wąż o długości 20 ledów i aby je zgasić musimy pamiętać, że chcemy zgasić ledy, które są na górze ekranu, czyli na końcu naszej tabeli i dlatego i nadajemy wartość startową 103
 leds[row1[i]] = CRGB(0, 0, 0); //GRB
    FastLED.show();
    delay(10); 
}
delay(100); 
FastLED.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop() {   //w tej funkcji wywołujemy już nasze wcześniej przygotowane funckje z trybami ledów
    PionowaPulsacja(); //Do wyboru mamy: RainbowSpin(); RainbowPong(); Epilepsja(); Policja(); PionowaPulsacja;
}
