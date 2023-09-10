# cerradura
Control de cerradura por RFID
-----------------------------------------------------------------------------------------
El fin de este proyecto es controlar un electroimán por medio de llaves magnéticas.

Este control almacena las tarjetas en una variable llamada "CardNumber", las cuales están concetenadas por los caracteres " - ", al momento de leer una tarjeta se realiza un indexOf en la variable anteriormente detallada para saber si la tarjeta leida es conocida. En caso de coincidir se desactiva el electroimán y se activa un pitido por medio del buzzer para dar aviso de que la lectura fue correcta. En caso de que el valor leido no es correcto se emiten tres pitidos.

-----------------------------------------------------------------------------------------
El **listado de componentes** empleados es el siguiente:

**Control:**
  1 x Arduino Nano

**Potencia:**
  1 x Módulo relé
  1 x Opto acoplador PC817

**Actuadores:**
  1 x Electroimán
  1 x Buzzer

**Sensor:**
  1 x RFID-RC522

**Semiconductores:**
  1 x Transistor BC337
  1 x LM7805

**Capacitores:**
  3 x 0,1 uF
  1 x 0,22 uF
  2 x 1.000 uF

**Resistencias:**
  2 x 10k
  1 x 1k
  1 x 220
