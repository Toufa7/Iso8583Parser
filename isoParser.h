#ifndef ISOPARSER_H
#define ISOPARSER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *primaryBitMap; // 8 bytes
    char *secondaryBitMap; // if (firstBite > 8) {exist}
    
}   t_bitMap;

typedef struct {
    char *mti;
    char *bitMap;
}   t_isoMsgData;

enum data_element_type { f_1, f_2, f_3, f_4, f_5, f_6, f_7, f_8, f_10, f_12, f_16, f_17, f_25, b_8, lllvar, llvar};

typedef struct data_element {
    char *                  name;
    char *                  data;
    bool                    is_exist;
    enum data_element_type  type;
} t_data_element;



void    init(t_data_element *data_element);



#endif