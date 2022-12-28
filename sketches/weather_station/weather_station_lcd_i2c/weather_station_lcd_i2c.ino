#include "DHT.h"
#include <LiquidCrystal_I2C.h>

// I2C address 0x27, 16 column and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Digital pin connected to the DHT sensor
#define DHTPIN 2
#define DHTTYPE DHT11   // DHT 11

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();  // activate DHT sensor
  lcd.init(); // initialize the lcd
  lcd.backlight();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(5000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();

  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  lcd.setCursor(0, 0);

  // Check if any reads failed and exit early (to try again).
  //if (isnan(h) || isnan(t) || isnan(f)) {
  if (isnan(h) || isnan(t)) {
    lcd.print ("Failed to read from DHT sensor!");
    return;
  }

  // print temperature in Celsius
  lcd.print ("T: ");
  lcd.print (t);
  lcd.print (" deg. C");

  lcd.setCursor(0, 1);

  // print % of humidity
  lcd.print ("H: ");
  lcd.print (h);
  lcd.print (" %");
}
