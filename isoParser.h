#ifndef ISOPARSER_H
#define ISOPARSER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    char *primaryBitMap; // 8 bytes
    char *secondaryBitMap; // if (firstBite > 8) {exist}
    
}   t_bitMap;

typedef struct {
    char *mti;
    char *bitMap;
}   t_isoMsgData;


#endif