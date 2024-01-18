#include "isoParser.h"

void handel_variadic_data(t_data_element *data_element, char *data, int *index) {
    int len;
    char *size = (char *) calloc(4, sizeof(char));
    
    if(data_element->type == llvar) {
        strncpy(size, data + *index, 2);
        len = strtoul(size, NULL, 10);
        data_element->data = (char *) calloc(len + 1, sizeof(char));
        if(*index + 2 < strlen(data)) {
            strncpy (data_element->data, data + (*index + 2), len);
            *index += (len + 2);
        }
    } else {
        strncpy(size, data + *index, 3);
        len = strtoul(size, NULL, 10);
        data_element->data = (char *) calloc(len + 1, sizeof(char));
        if(*index + 3 < strlen(data)) {
            strncpy (data_element->data, data + (*index + 3), len);
            *index += (len + 3);
        }
    }
}

void handel_static_data(t_data_element *data_element, char *data, int *index) {
    int len = data_element->type;
    data_element->data = (char *) calloc(len + 1, sizeof(char));
    if(*index < strlen(data)) {
        strncpy (data_element->data, data + (*index), len);
        *index += len;
    }
}

void treat_data_elements(t_data_element *data_elements, char *data) {
    int index = 0;
    for (int i = 0 ; i < 64; i++) {
        if(data_elements[i].is_exist) {
            if(data_elements[i].type == llvar || data_elements[i].type == lllvar)
                handel_variadic_data(&data_elements[i], data, &index);
            else
                handel_static_data(&data_elements[i], data, &index);
        }
    }
}