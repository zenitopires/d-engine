#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>

void floatArrayToString(const float arr[], size_t count, char *buffer, size_t bufferSize) {
    size_t offset = 0;
    offset += snprintf(buffer + offset, bufferSize - offset, "[");
    for (size_t i = 0; i < count; i++) {
        // Print each float with 2 decimal places
        offset += snprintf(buffer + offset, bufferSize - offset, "%.2f", arr[i]);
        if (i < count - 1) {
            offset += snprintf(buffer + offset, bufferSize - offset, ", ");
        }
        // Avoid buffer overflow
        if (offset >= bufferSize) {
            break;
        }
    }
    snprintf(buffer + offset, bufferSize - offset, "]");
}

void intArrayToString(const int arr[], size_t count, char *buffer, size_t bufferSize) {
    size_t offset = 0;
    offset += snprintf(buffer + offset, bufferSize - offset, "[");
    for (size_t i = 0; i < count; i++) {
        // Print each float with 2 decimal places
        offset += snprintf(buffer + offset, bufferSize - offset, "%d", arr[i]);
        if (i < count - 1) {
            offset += snprintf(buffer + offset, bufferSize - offset, ", ");
        }
        // Avoid buffer overflow
        if (offset >= bufferSize) {
            break;
        }
    }
    snprintf(buffer + offset, bufferSize - offset, "]");
}



#endif
