#ifndef ISOPARSER_H
#define ISOPARSER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>


#define BITMAP_SIZE 16

#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))

enum data_element_type { f_1 = 1 , f_2, f_3, f_4, f_5, f_6, f_7, f_8, f_10 = 10, f_12 = 12, f_15 = 15, f_16, f_17, f_25 = 25, f_40 = 40, b_8, llvar, lllvar};

typedef struct {
    char *primaryBitMap; // 8 bytes
    char *secondaryBitMap; // if (firstBite > 8) {exist}
    
}   t_bitMap;

typedef struct {
    char *mti;
    char *bitMap;
}   t_isoMsgData;

typedef struct data_element {
    char *                  name;
    char *                  data;
    bool                    is_exist;
    enum data_element_type  type;
} t_data_element;

void init_data_elements (t_data_element *data_element);
void check_bitmap (t_data_element *data_elements, char *bitmap);
void treat_data_elements(t_data_element *data_elements, char *data);

#endif