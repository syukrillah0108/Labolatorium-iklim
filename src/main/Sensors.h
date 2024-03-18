#include <BH1750.h>
#include <Wire.h>
#include <DHT.h>

BH1750 lightMeter;
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float h,t,l;