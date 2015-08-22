# Introduction #

La idea se trata de que el DSP se encargue de RX/TX de los datos a través de los GPIOs de la placa (¿posible? [No por ahora!](http://elinux.org/ECE497_Notes_on_gpio))

ARM y DSP dispondrán de memoria compartida para los datos de configuración de los parámetros de volumen y paneo de cada canal y cada salida (¿como hacer para grabar los datos a HD?)

Los registros de volumen paneo ocuparán 1 Byte de tamaño cada uno (255 valores posibles)

  * 8 canales -> 2 params x 1 Byte x 8 INs x 8 OUTs = 128 KB
  * 16 canales -> 2 params x 1 Byte x 16 INs x 16 OUTs = 512 KB

Por otro lado el ARM con elkernel de linux se encargará de leer los valores de los potenciometros (o wifi a través de aplicación android) y modificar los registros de los parámetros de volúmen/paneo correspondientes.

¿Efectos de audio para el DSP? -> reverb?

**NOTA:** Para evitar problemas de acceso a la memoria compartida, el ARM notificará por interrupción SW al DSP de la existencia de modificación de los datos de volumen/paneos, a lo cual el DSP copiará estos datos en su memoria interna reservada para tal efecto y regresará de la interrupción.

## GPIO Requirements ##

6 min for high freq signals:
  * 1x WDCLK
  * 1x BCLK
  * 4x DATA IN (per ADAT)

12 for controlling:
  * 2x Volume Rotary encoder
  * 2x Channel Rotary Encoder
  * 3x Mux Channel Rotary
  * 1x Channel Page button
  * 2x Mix Up/Down button
  * 1x Pan

## Details ##

Tareas del DSP:

  * Un thread se encargará de hacer Rx/Tx a 64\*Fs MHz (BCLK) con uno de los arrays
  * El otro thread aplicará volumen/paneos y mezclará señales con el otro array. Quizás esto pueda hacerlo el ARM (¿?)

### Cálculo de latencias reales ###

La velocidad del sonido es 340 m/s

Latencia -> L (ms) = D(cm)/34

  * Para un cantante la distancia boca-oido es de unos 10 cm.
  * Para un batería la distancia media es 30 cm
  * Para un guitarra la distancia media son 100 cm

  * Cantante -> L = 0,3 ms =  300 us
  * Batería  -> L =   1 ms = 1000 us
  * Guitarra -> L =   3 ms = 3000 us
  * Máximo   -> L =   5 ms = 5000 ms

Como la Rx y Tx se hace en paralelo, la idea es que la muestra de Tx  esté retrasada N\*T periodos de muestreo siendo Lmin=2T el mejor caso (es necesario 1T para Rx/Tx)

Luego Nmax = L/T - 1

#### Muestreo a 48 KHz ####
T = 1/F = 1/48KHz = 20.9 us

ADAT bit = T/64 = 325 ns
  * Cantante -> Ncan = 13
  * Batería -> Nbat = 46
  * Guitarra -> Ngui = 141
  * Máximo -> Nmax = 237

#### Muestreo a 44.1 KHz ####
T = 1/F = 1/44.1 KHz = 22.7 us

ADAT bit = T/64 = 354 ns

  * Cantante -> Ncan = 12
  * Batería -> Nbat = 42
  * Guitarra -> Ngui = 129
  * Máximo -> Nmax = 216

**NOTA**: Con N=128

  * T = 128/F = 128/44.100 Hz = 3.0 ms
  * T = 128/F = 128/48.000 Hz = 2.7 ms

**NOTA**: Con N=64

  * T = 64/F = 64/44.100 Hz = 1.5 ms
  * T = 64/F = 64/48.000 Hz = 1.4 ms


## Configuracion Digital en la BB ##

No se puede usar SPI porque no hay canales suficientes.

Tenemos que implementar con GPIO e interrupciones la recepción de los 4 canales de datos como si fuera un SPI modificado en modo esclavo


## Algoritmos ##

#### Procesado en cada bit ####
sdgsd


#### Procesado en cada muestra ####
asdasd



## Tamaño necesario ##

S = C canales `*` 16 bits `*` N muestras `*` 2 Arrays

**NOTA** -> Necesitamos 2 arrays de trabajo

  * Uno Para Rx/Tx (1º leemos el dato a Tx y 2º escribimos el dato de Rx)
  * Otro para el procesado de el grupo de N muestras anterior
  * Los bancos se intercambian cada grupo de N muestras.

  * 8 canales y 16 muestras: 512 Bytes
  * 8 canales y 32 muestras: 1 KB
  * 8 canales y 64 muestras: 2 KB
  * 8 canales y 128 muestras: 4 KB

  * 16 canales y 16 muestras: 1 KB
  * 16 canales y 32 muestras: 2 KB
  * 16 canales y 64 muestras: 4 KB
  * 16 canales y 128 muestras: 8 KB

## Panning ##
http://en.wikipedia.org/wiki/Panning_(audio)

http://en.wikipedia.org/wiki/Pan_law
#### Metodo 1 ####
##### Pan left #####
  * L = V
  * R = 0

##### Pan Right #####
  * L = 0
  * R = V

##### Pan Center #####
  * L = R = -3dB `*` V = sqr(2)/2 `*` V  = 0,707 `*` V

#### Metodo 2 ####
  * vol\_L = volume `*` (1.0 - pan);
  * vol\_R = volume `*` (1.0 + pan);
Donde pan va de -1(L) a 1(R)