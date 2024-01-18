#include "./isoParser.h"

#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitcheck(byte,nbit) ((byte) &   (1<<(nbit)))


char *substr(char *str , int s, int len) {
    char *sub = malloc(sizeof(char) * (len + 1));
    int i = 0 , l = 0;
    while (str[i]) {
        if (i >= s && l < len){
            sub[l] = str[i];
            l++;
        }
        i++;
    }
    sub[l] = '\0';
    return (sub);
}

int ft_error(char *msg) {
    return (write(2, msg, strlen(msg)));
}


void    mtiParser(char *mti) {
    // ISO Version
    printf("%d: ", atoi(mti) / 1000);
    switch ((atoi(mti) / 1000))
    {
        case 0:
            printf("ISO 1987 Version\n");
            break;
        case 1:
            printf("ISO 1993 Version\n");
            break;
        case 2:
            printf("ISO 2003 Version\n");
            break;
        default:
            printf("Unknown Version\n");
            break;
    }
    // Message Class
    printf("%d: ", ((atoi(mti) / 100) % 10));
    switch (((atoi(mti) / 100) % 10))
    {
        case 1:
            printf("Authorization message\n");
            break;
        case 2:
            printf("Financial messages\n");
            break;
        case 3:
            printf("File actions message\n");
            break;
        case 4:
            printf("Reversal and chargeback messages \n");
            break;
        case 5:
            printf("Reconciliation message\n");
            break;
        case 6:
            printf("Administrative message\n");
            break;
        case 7:
            printf("Fee collection messages\n");
            break;
        case 8:
            printf("Network management message\n");
            break;
        default:
            printf("Unknown Message Class\n");
            break;
    }

    // Message Function
    printf("%d: ", ((atoi(mti) / 10) % 10));
    switch (((atoi(mti) / 10) % 10))
    {
        case 0:
            printf("Request\n");
            break;
        case 1:
            printf("Request response\n");
            break;
        case 2:
            printf("Advice\n");
            break;
        case 3:
            printf("Advice response\n");
            break;
        case 4:
            printf("Notification\n");
            break;
        case 5:
            printf("Notification acknowledgement\n");
            break;
        case 6:
            printf("Instruction\n");
            break;
        case 7:
            printf("Instruction acknowledgement \n");
            break;
        default:
            printf("Unknown Message Origin\n");
            break;
    }

    // Checking message origin
    printf("%d: ", (atoi(mti) % 10));
    switch ((atoi(mti) % 10))
    {
        case 0:
            printf("Acquirer\n");
            break;
        case 1:
            printf("Acquirer repeat\n");
            break;
        case 2:
            printf("Issuer\n");
            break;
        case 3:
            printf("Issuer repeat\n");
            break;
        case 4:
            printf("Other\n");
            break;
        default:
            printf("Unknown Message Origin\n");
            break;
    }

}

// void convertBinary(char *bitMap, char *data, t_data_element *data_element) {
//     char *bin = calloc(strlen(bitMap), sizeof(char));
//     for (size_t i = 0;i < strlen(bitMap); i++){
//         int value = isdigit(bitMap[i]) ? bitMap[i] - '0' : toupper(bitMap[i]) - 'A' + 10;
//         for (int j = 3; j >= 0; j--)
//         {
//             if ((value >> j) & 1)
//                 strcat(bin, "1");
//             else
//                 strcat(bin, "0");
//         }
//     }
//     printf("****************** [Binary] ***********************\n");
//     printf("%s\n", bin);
//     for (int i = 0; i < strlen(bin); i++){
//         if (bin[i] == '1') {
//             printf("%d - %s - %d\n", i + 1, data_element[i - 1].name, data_element[i - 1].type );
//             data_element[i].is_exist = true;
//         }
//     }
// }

bool checkInput(char *av) {
    for (int i = 0; i < strlen(av); i++) {
        if (!((av[i] >= '0' && av[i] <= '9') || (av[i] >= 'A' && av[i] <= 'F')))
            return (false);
    }
    return (true);
}

int main(int ac, char *av[]) {
    if (ac != 2)
        return (ft_error("Please provide ISO Message\n"));
    if (!checkInput(av[1]))
        return (ft_error("Invalid Format\n"));

    t_data_element  *data_element;
    t_isoMsgData    *input;
    int             len;

    data_element = calloc(64, sizeof(t_data_element));
    input = malloc(sizeof(t_isoMsgData));
    init(data_element);

    len = (av[1][4] >= '0' && av[1][4] <= '7') ? 16 : 32;
    input->mti = substr(av[1], 0, 4);
    input->bitMap = substr(av[1], 4, len);
    input->data = substr(av[1], len + 4, strlen(av[1]) - (len + 4));
    mtiParser(input->mti);
    // convertBinary(input->bitMap, input->data, data_element);
}

