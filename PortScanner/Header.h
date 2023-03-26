/* 
 * ------------------------
 * Port Scanner Header
 * ------------------------
 * Project done by Manittas
 * ------------------------
 */

#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <arpa/inet.h>

// Struct to save the IP and the Ports range
typedef struct {
    char IP[16];
    int first_port;
    int last_port;
} arguments_t;

void scanner(void);

#endif // HEADER_H