#include "isoParser.h"

void check_bitmap(t_data_element *data_elements, char *bitmap) {
    char    num;
    char    index = 0;
    char    *hex = (char *) calloc(3, sizeof(char));

    for (int i = 0; i < BITMAP_SIZE; i += 2) {
        strncpy(hex, bitmap + i, 2);
        num = strtoul(hex, NULL, 16);
        for (int k = 7; k >= 0; k--) {
            if(index == 0 && k == 7)
                continue;
            if(bitcheck(num, k))
                data_elements[index].is_exist = true;
            index++;
        }
    }
}