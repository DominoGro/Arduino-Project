#include <Keyboard.h> // biblioteka do obsługi klawiatury i myszki
#include <LiquidCrystal_I2C.h> // biblioteka do obsługi wyświetlacza LCD z obsługą I2C
#include <Wire.h> // biblioteka pozwalająca na komunikację z urządzeniami I2C
int fotoRez1 = A0; // przypisujemy pin A0 do zmiennej fotoRez1
int fotoRez2 = A1; // przypisujemy pin A1 do zmiennej fotoRez2
int fotoValue1 = 0; // zmienna wykorzystywana do zapisu wartości z fotorezystora 1
int fotoValue2 = 0; // zmienna wykorzystywana do zapisu wartości z fotorezystora 2
int thresholdValue = 7; // wartość graniczna służąca do pomocy
int score = 0; // zmienna do przechowywania wyniku
LiquidCrystal_I2C lcd(0x27, 16, 2); // utworzenie obiektu wyświetlacza LCD 16x2

void setup() {
	Serial.begin(9600); // ustawienie przepływności danyh
	lcd.init(); // inicjalizacja wyświetlacza
	lcd.backlight(); // włączenie podświetlenia wyświetlacza
	lcd.setCursor(0, 0); // zmieniamy pozycje kursora na początek
	lcd.print("Score:"); // wyświetlenie tekstu na wyświetlaczu
	lcd.setCursor(0, 1); // zmieniamy pozycje kursora na początek dolnej lini
	lcd.print(score); // wyświetlamy wartość zmiennej „score” na wyświetlaczu
}
void loop() {
	fotoValue1 = analogRead(fotoRez1); // odczytanie wartości 1 fotorezystora i przypisanie jej do zmiennej
	fotoValue2 = analogRead(fotoRez2); // odczytanie wartości 2 fotorezystora i przypisanie jej do zmiennej
	Keyboard.begin(); // rozpoczęcie symulacji klawiatury lub myszki
	if(fotoValue1 <= thresholdValue) // jeśli wrtość fotorezystora będzie mniejsza lub równa od wartości granicznej to wykonaj instrukcje w nawiasie
	{
		Keyboard.press(32); // wyślij do komputera wciśniecie „SPACJI”(32 dziesiętnie)
		delay(10); // odczekaj 10 milisekund
		Keyboard.release(32); // wyślij do komputera zwolnienie „SPACJI”
		lcd.setCursor(0, 1); // zmień pozycje wyświetlacza na początek 2 linijki
		lcd.print(score); // wyświetl wartość zmiennej „score” na wyświetlaczu
		score += (100 / 3); // zmień wartość zmiennej „score”
	}
	if(fotoValue2 <= thresholdValue) // jeśli wrtość fotorezystora będzie mniejsza lub równa od wartości granicznej to wykonaj instrukcje w nawiasie
	{
		Keyboard.press(217); // wyślij do komputera wciśniecie „Strzałki w dół”(217 dziesiętnie)
		delay(10); // odczekaj 10 milisekund
		Keyboard.release(217); // wyślij do komputera zwolnienie „Strzałki w dół”
		lcd.setCursor(0, 1); // zmień pozycje wyświetlacza na początek 2 linijki
		lcd.print(score); // wyświetl wartość zmiennej „score” na wyświetlaczu
		score += (100 / 3); // zmień wartość zmiennej „score”
	}
delay(40); // odczekaj 40 milisekund
Keyboard.end(); // zakończ symulacje klawiatury lub myszki
}