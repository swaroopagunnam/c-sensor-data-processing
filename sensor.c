#include <stdio.h>
#include <stdlib.h>

struct SensorData {
    int id;
    float value;
};

int main() {
    FILE *inputFile, *outputFile;
    struct SensorData sensor;
    int count = 0;
    float sum = 0.0, average;

    inputFile = fopen("data.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d %f", &sensor.id, &sensor.value) != EOF) {
        fprintf(outputFile, "Sensor ID: %d, Value: %.2f\n",
                sensor.id, sensor.value);
        sum += sensor.value;
        count++;
    }

    if (count > 0) {
        average = sum / count;
        fprintf(outputFile, "\nAverage Sensor Value: %.2f\n", average);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Sensor data processed successfully.\n");
    return 0;
}
