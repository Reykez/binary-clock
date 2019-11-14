# binary-clock
Binary clock using Arduino Nano &amp; ESP8266

# PL 
Zegarek binarny wykorzystujący Arduino Nano & ESP8266

### KONFIGURACJA
W pliku esp8266.ino, w liniach 9 i 10 należy podać SSID oraz hasło sieci WIFI, do której zegarek będzie łączył się w celu aktualizacji godziny. **Bez połączenia z siecią, zegarek nie działa**.
```c
const char* ssid = "Siec-Kowalski";
const char* password = "simplepassword123";
```

### POŁĄCZENIE
Arduino Nano zasilane będzie poprzez kabel USB, a ESP8266 z Arduino Nano, poprzez połączenie 5V i masy. ESP komunikuje się z arduino przy pomocy I2C. Do realizacji tego połączenia należy podłączyć port *D1 z A5* oraz *D2 z A4*. Wszystkie LEDy połączone są do masy przy pomocy rezystorów 440Ω, oraz do portów D2-D13 i A0-A3 Arduino Nano, oraz pozostały led wskazujący 2^1 godziny połączony z portem D7 na ESP8266.

![schematic1](https://user-images.githubusercontent.com/44320848/68903484-9d323680-073b-11ea-8f2d-5b03e0188d32.png)

### WGRYWANIE KODU
Plik 'esp8266.ino' po konfiguracji zostaje wgrany na płytkę Wemos'a D1 Mini ESP8266.
Plik 'nano.ini' zostaje wgrany na płytkę arduino nano.

### OBUDOWA
Gotowe modele .STL przeznaczone do druku oraz plik projektu w FreeCAD'zie znajdują się w folderze models.
Łączny czas wydruku przy warstwie 0.3mm to około 5 godzin.
Plik 'stand.stl' jest opcjonalny, i należy go wydrukować podwójnie.
Całość należy skręcić czterema śrubami M4 20mm.

![75388208_596220997786736_7961682598600638464_n](https://user-images.githubusercontent.com/44320848/68903996-0a929700-073d-11ea-8511-7c841a544c0e.jpg)
![73372189_803674540065883_3925195372300861440_n](https://user-images.githubusercontent.com/44320848/68903999-0bc3c400-073d-11ea-8b3c-2f9098ea71fc.jpg)
