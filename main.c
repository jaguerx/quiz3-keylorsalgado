#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    float valor;
    char timestamp[20];
} Sensor;

typedef struct {
    int id;
    float valor;
    char timestamp[20];
    float temperatura;
} SensorActualizado;

void encrypt_file(const char *input_filename, const char *output_filename, unsigned char key) {
    FILE *input = fopen(input_filename, "rb");
    FILE *output = fopen(output_filename, "wb");
    if (!input || !output) {
        perror("Error al abrir archivos");
        exit(1);
    }

    int c;
    while ((c = fgetc(input)) != EOF) {
        fputc(c ^ key, output);
    }

    fclose(input);
    fclose(output);
}


int main() {
    const char *archivo_entrada = "sensor_encrypted.bin";
    const char *archivo_salida = "sensor_updated_encrypted.bin";
    const unsigned char clave = 0xAB;
    
    // 1. Desencriptar archivo original
    encrypt_file("sensor_encrypted.bin", "temp_original.bin", clave);
    
    // 2. Leer estructura original
    FILE *temp_original = fopen("temp_original.bin", "rb");
    if (!temp_original) {
        perror("Error al abrir archivo temporal original");
        return 1;
    }
    
    Sensor sensor_original;
    fread(&sensor_original, sizeof(Sensor), 1, temp_original);
    fclose(temp_original);
    
    // 3. Mostrar datos originales
    printf("=== Datos originales ===\n");
    printf("ID: %d\n", sensor_original.id);
    printf("Valor: %.2f\n", sensor_original.valor);
    printf("Timestamp: %s\n\n", sensor_original.timestamp);
    
    // 4. Crear estructura actualizada
    SensorActualizado sensor_actualizado;
    sensor_actualizado.id = sensor_original.id;
    sensor_actualizado.valor = sensor_original.valor;
    strncpy(sensor_actualizado.timestamp, sensor_original.timestamp, 20);
    sensor_actualizado.temperatura = 30.0f;
    
    // 5. Guardar estructura actualizada
    FILE *temp_actualizado = fopen("temp_actualizado.bin", "wb");
    if (!temp_actualizado) {
        perror("Error al crear archivo temporal actualizado");
        return 1;
    }
    fwrite(&sensor_actualizado, sizeof(SensorActualizado), 1, temp_actualizado);
    fclose(temp_actualizado);
    
    // 6. Encriptar archivo actualizado
    encrypt_file("temp_actualizado.bin", "sensor_updated_encrypted.bin", clave);
    
    // 7. Verificación
    encrypt_file("sensor_updated_encrypted.bin", "temp_verificado.bin", clave);
    
    FILE *temp_verificado = fopen("temp_verificado.bin", "rb");
    if (!temp_verificado) {
        perror("Error al abrir archivo temporal verificado");
        return 1;
    }
    
    SensorActualizado sensor_verificado;
    fread(&sensor_verificado, sizeof(SensorActualizado), 1, temp_verificado);
    fclose(temp_verificado);
    
    printf("=== Datos actualizados ===\n");
    printf("ID: %d\n", sensor_verificado.id);
    printf("Valor: %.2f\n", sensor_verificado.valor);
    printf("Timestamp: %s\n", sensor_verificado.timestamp);
    printf("Temperatura: %.2f\n\n", sensor_verificado.temperatura);
    
    // 8. Limpieza
    remove("temp_original.bin");
    remove("temp_actualizado.bin");
    remove("temp_verificado.bin");
    
    printf("Proceso completado. Archivos generados:\n");
    printf("- sensor_updated_encrypted.bin\n");
    
    return 0;
}
    

