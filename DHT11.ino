#include "DHT.h"//Libreria Dht11
DHT dht11;//Nombre de la variable que funcionara con la libreria

void setup()
{
  Serial.begin(9600);//Inicializar comunicacion serial 
  Serial.println();//salto de linea en el monitor serial
  Serial.println("Estado\tHumedad (%)\tTemperatura (C)\tTemperatura (F)");
  dht11.setup(2); // configurar el pin 2 como entrada de la señal del sensor 
}

void loop()
{
  delay(dht11.getMinimumSamplingPeriod());//Retardo necesario entre cada medicion
  float Humedad = dht11.getHumidity();//Almacenar la humedad en una variable flotante
  float Temperatura = dht11.getTemperature();//Almacenar la temperatura en una variable flotante
  Serial.print(dht11.getStatusString());//Imprimir en el monitor serial si existe comunicacion entre el sensor y el arduino
  Serial.print("\t");//Tabular resultados en el monitor serial
  Serial.print(Humedad);//Imprimir en el monitor serial el valor de la Humedad
  Serial.print("\t\t");//Tabular resultados en el monitor serial
  Serial.print(Temperatura);//Imprimir en el monitor serial el valor de la Temperatura
  Serial.print("\t\t");//Tabular resultados en el monitor serial
  Serial.println(dht11.toFahrenheit(Temperatura));
}

