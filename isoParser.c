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

int main(int ac, char *av[]) {
    if (ac != 2)
        return (ft_error("Please provide ISO Message\n"));


    t_data_element *data_element = (t_data_element *) (64, sizeof(t_data_element));
    t_isoMsgData *a = malloc(sizeof(t_isoMsgData));

    init(data_element);    
    a->mti = substr(av[1], 0, 4);
    a->bitMap = substr(av[1], 4, strlen(av[1]) - 4);
    mtiParser(a->mti);
}

