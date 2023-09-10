# cerradura
Control de cerradura por RFID
-----------------------------------------------------------------------------------------

El proyecto "Sistema de Control de Acceso con RFID y Buzzer" se enfoca en el desarrollo de un sistema de seguridad y acceso utilizando tecnología RFID (Radio-Frequency Identification) implementado a través de un microcontrolador Arduino. Este sistema permite autorizar o denegar el acceso a un área específica según la tarjeta RFID presentada al lector, emitiendo señales audibles mediante un buzzer y controlando la apertura de un portón.

-----------------------------------------------------------------------------------------

**Características Principales:**

**Lector RFID:** El proyecto utiliza un lector RFID MFRC522 para la identificación de tarjetas RFID.

**Autenticación Segura:** Se ha implementado una clave de autenticación para garantizar que solo las tarjetas autorizadas tengan acceso.

**Interacción Auditiva:** Un buzzer se utiliza para proporcionar retroalimentación auditiva. Emitirá pitidos para indicar si la tarjeta es válida o si se ha producido un error en la lectura.

**Control del Portón:** El sistema tiene la capacidad de controlar la apertura y cierre de un portón mediante la activación de un electroimán. El portón se abre cuando se presenta una tarjeta válida y se cierra después de un tiempo determinado.

-----------------------------------------------------------------------------------------
**Esquemático:**
![Esquemático](https://github.com/Alcario/cerradura/blob/main/Esquematico.png)
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
