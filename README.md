# quiz3-keylorsalgado
# para ejecutar main.c en bash se tiene que ingresar al directorio correspondiente y copilar main.c con el siguiente comando:

gcc -o sensor_update main.c -Wall -Wextra

# ingreasado el comando aparece lo siguiente:
main.c: In function ‘main’:
main.c:38:17: warning: unused variable ‘archivo_salida’ [-Wunused-variable]
   38 |     const char *archivo_salida = "sensor_updated_encrypted.bin";
      |                 ^~~~~~~~~~~~~~
main.c:37:17: warning: unused variable ‘archivo_entrada’ [-Wunused-variable]
   37 |     const char *archivo_entrada = "sensor_encrypted.bin";
      |                 ^~~~~~~~~~~~~~~
# posterior a esto se ejecuta main.c con el siguiente comando:
 ./sensor_update

 # por ultimo nos aparece los datos originales (sensor_encrypted.bi) y los datos actualizados 
 === Datos originales ===
ID: 1
Valor: 25.50
Timestamp: 2023-10-25 12:00:00

=== Datos actualizados ===
ID: 1
Valor: 25.50
Timestamp: 2023-10-25 12:00:00
Temperatura: 30.00

Proceso completado. Archivos generados:
- sensor_updated_encrypted.bin

