# Node MCU based Rover

Implements the possibility of driving a DY rover through a REST API


## Componentes
* Node MCU board
* Chasis
* Motores DC 6v con reducción
* Batería LiPo 2s
* IC L293D - (doble puente H)

## URLS
/adelante
/atras
/izquierda
/derecha
/frena


Es necesario configurar IP y puerto al que responde el robot, el original responde a 192.168.2.144:444


## To do
* Agregar una cámara IP alimentada a baterías
* Adicionar un relay que encienda y apague esa cámara
* Adicionar sistema pan & titl para la cámara
* Que el sistema se apague al alcanzar el umbral de la bateria de LiPo
