#pragma once
#include <stdio.h>
#include <log.h>

#ifdef DEBUG
    #define debug_msg(msg, ...) log_debug(msg, ##__VA_ARGS__)
#else
    #define debug_msg(msg, ...) ((void)0)
#endif

#define error_msg(msg, ...) log_error(msg, ##__VA_ARGS__)
#define info_msg(msg, ...) log_info(msg, ##__VA_ARGS__)

void floatArrayToString(const float arr[], size_t count, char *buffer, size_t bufferSize);
void intArrayToString(const int arr[], size_t count, char *buffer, size_t bufferSize);
