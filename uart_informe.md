# Práctica 8 Buses de comunicación VI (uart)
###### Andrea Muñiz López
<p></p>

## Programa + explicación

> Declaramos las librerias necesarias

```
#include <Arduino.h>
```

> Dfinimos los pines pertenecientes a RX2 y TX2 de la placa ESP32

```
#define RXD2 16
#define TXD2 17
```

> Función setup()

En esta función inicializamos el Serial 1 a una velocidad de 115200 y el Serial2 a la misma velocidad y además le indicamos el protocolo __SERIAL_8N1__ y los pines donde se encuentran su RXD y TXD.
A continuación escribimos por el monitor lo que queremos enviar del Serial a Serial2.

```
void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial Txd is on pin: " + String(TX));
  Serial.println("Serial Rxd is on pin: " + String(RX));
  Serial.println("Hola, esta es una prueba de funcionamiento");
}
```

> Función bucle

En esta función Serial2 escribe lo que lee en el Serial y a continuación Serial escribe lo que lee del Serial2, por lo que por pantalla se irá escribiendo lo mismo que hemos enviado.

```
void loop() {
  Serial2.print(char(Serial.read()));
  Serial.print(char(Serial2.read()));
  delay(1000);
}
```

***

## Salida de la impresión serie

En la carpeta donde se encuentra este informe, hay un video que muestra la salida del monitor serie.