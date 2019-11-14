# binary-clock
Binary clock using Arduino Nano &amp; ESP8266

# PL 
Zegarek binarny wykorzystujący Arduino Nano & ESP8266

#### KONFIGURACJA
W pliku esp8266.ino, w liniach 9 i 10 należy podać SSID oraz hasło sieci WIFI, do której zegarek będzie łączył się w celu aktualizacji godziny. **Bez połączenia z siecią, zegarek nie działa**.
```
const char* ssid = "Siec-Kowalski";
const char* password = "simplepassword123";
```
