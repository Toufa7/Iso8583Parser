#include "isoParser.h"


int main(void) {
    t_data_element *data_elements = (t_data_element *) calloc(63, sizeof(t_data_element));
    init_data_elements(data_elements);
    check_bitmap(data_elements, "323A40010A418010");
    treat_data_elements(data_elements, "3800000000000000000420050805011392120805042004225132072000001000000115604000800411163011511463331563GAAASDD ERRR1300101B54391001000017654350000000000090300000268410000000300000000000000898100009431000000000000000000 000000000000000036000299");
    // treat_data_elements(data_elements, "");
    for (int i = 0; i < 64; i++) {
        if(data_elements[i].is_exist)
        {
            printf("--> %s = %s\n", data_elements[i].name, data_elements[i].data);
            
        }
    }
}