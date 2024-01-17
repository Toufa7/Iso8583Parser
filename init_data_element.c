#include "parcer.h"

void init (t_data_element *data_element) {

    for (int i = 0; i < 64; i++) {
        data_element[i].data = NULL;
        data_element[i].is_exist = false;
    }
    data_element[0].name = calloc(strlen("Primary account number") + 1, sizeof(char));
    data_element[0].name = "Primary account number";
    data_element[0].type = llvar;
    
    data_element[1].name = calloc(strlen("Processing Code") + 1, sizeof(char));
    data_element[1].name = "Processing Code";
    data_element[1].type = f_6;

    data_element[2].name = calloc(strlen("Amount Transaction") + 1, sizeof(char));
    data_element[2].name = "Amount Transaction";
    data_element[2].type = f_12;

    data_element[3].name = calloc(strlen("Amount, settlement") + 1, sizeof(char));
    data_element[3].name = "Amount, settlement";
    data_element[3].type = f_12;

    data_element[4].name = calloc(strlen("Amount, cardholder billing") + 1, sizeof(char));
    data_element[4].name = "Amount, cardholder billing";
    data_element[4].type = f_12;

    data_element[5].name = calloc(strlen("Transmission date & time") + 1, sizeof(char));
    data_element[5].name = "Transmission date & time";
    data_element[5].type = f_10;

    data_element[6].name = calloc(strlen("Amount, cardholder billing fee") + 1, sizeof(char));
    data_element[6].name = "Amount, cardholder billing fee";
    data_element[6].type = f_8;

    data_element[7].name = calloc(strlen("Conversion rate, settlement") + 1, sizeof(char));
    data_element[7].name = "Conversion rate, settlement";
    data_element[7].type = f_8;

    data_element[8].name = calloc(strlen("Conversion rate, cardholder billi") + 1, sizeof(char));
    data_element[8].name = "Conversion rate, cardholder billi";
    data_element[8].type = f_8;

    data_element[9].name = calloc(strlen("Conversion rate, settlement") + 1, sizeof(char));
    data_element[9].name = "Conversion rate, settlement";
    data_element[9].type = f_8;

    data_element[10].name = calloc(strlen("System trace audit number (STAN)") + 1, sizeof(char));
    data_element[10].name = "System trace audit number (STAN)";
    data_element[10].type = f_8;

    data_element[11].name = calloc(strlen("Time, local transaction (hhmmss)") + 1, sizeof(char));
    data_element[11].name = "Time, local transaction (hhmmss)";
    data_element[11].type = f_8;

    data_element[12].name = calloc(strlen("Date, local transaction (MMDD)") + 1, sizeof(char));
    data_element[12].name = "Date, local transaction (MMDD)";
    data_element[12].type = f_8;

    data_element[13].name = calloc(strlen("Date, expiration") + 1, sizeof(char));
    data_element[13].name = "Date, expiration";
    data_element[13].type = f_8;

    data_element[14].name = calloc(strlen("Date, settlement") + 1, sizeof(char));
    data_element[14].name = "Date, settlement";
    data_element[14].type = f_8;

    data_element[15].name = calloc(strlen("Date, capture") + 1, sizeof(char));
    data_element[15].name = "Date, capture";
    data_element[15].type = f_8;

    data_element[16].name = calloc(strlen("Merchant type/Merchant Category Code") + 1, sizeof(char));
    data_element[16].name = "Merchant type/Merchant Category Code";
    data_element[16].type = f_8;

    data_element[17].name = calloc(strlen("Acquiring institution country code") + 1, sizeof(char));
    data_element[17].name = "Acquiring institution country code";
    data_element[17].type = f_8;

    data_element[18].name = calloc(strlen("PAN extended, country code") + 1, sizeof(char));
    data_element[18].name = "PAN extended, country code";
    data_element[18].type = f_8;

    data_element[19].name = calloc(strlen("Forwarding institution. country code") + 1, sizeof(char));
    data_element[19].name = "Forwarding institution. country code";
    data_element[19].type = f_8;

    data_element[20].name = calloc(strlen("Point of service entry mode") + 1, sizeof(char));
    data_element[20].name = "Point of service entry mode";
    data_element[20].type = f_8;

    data_element[21].name = calloc(strlen("Application PAN sequence number") + 1, sizeof(char));
    data_element[21].name = "Application PAN sequence number";
    data_element[21].type = f_8;

    data_element[22].name = calloc(strlen("Function code (ISO 8583:1993)/Network International identifier (NII)") + 1, sizeof(char));
    data_element[22].name = "Function code (ISO 8583:1993)/Network International identifier (NII)";
    data_element[22].type = f_8;

    data_element[23].name = calloc(strlen("Point of service condition code") + 1, sizeof(char));
    data_element[23].name = "Point of service condition code";
    data_element[23].type = f_8;

    data_element[24].name = calloc(strlen("Point of service capture code") + 1, sizeof(char));
    data_element[24].name = "Point of service capture code";
    data_element[24].type = f_8;

    data_element[25].name = calloc(strlen("Authorizing identification response length") + 1, sizeof(char));
    data_element[25].name = "Authorizing identification response length";
    data_element[25].type = f_8;

    data_element[26].name = calloc(strlen("Amount, transaction fee") + 1, sizeof(char));
    data_element[26].name = "Amount, transaction fee";
    data_element[26].type = f_8;

    data_element[27].name = calloc(strlen("Amount, settlement fee") + 1, sizeof(char));
    data_element[27].name = "Amount, settlement fee";
    data_element[27].type = f_8;

    data_element[28].name = calloc(strlen("Amount, transaction processing fee") + 1, sizeof(char));
    data_element[28].name = "Amount, transaction processing fee";
    data_element[28].type = f_8;

    data_element[29].name = calloc(strlen("Amount, settlement processing fee") + 1, sizeof(char));
    data_element[29].name = "Amount, settlement processing fee";
    data_element[29].type = f_8;

    data_element[30].name = calloc(strlen("Acquiring institution identification code") + 1, sizeof(char));
    data_element[30].name = "Acquiring institution identification code";
    data_element[30].type = f_8;

    data_element[31].name = calloc(strlen("Forwarding institution identification code") + 1, sizeof(char));
    data_element[31].name = "Forwarding institution identification code";
    data_element[31].type = f_8;

    data_element[32].name = calloc(strlen("Primary account number, extended") + 1, sizeof(char));
    data_element[32].name = "Primary account number, extended";
    data_element[32].type = f_8;

    data_element[33].name = calloc(strlen("Track 2 data") + 1, sizeof(char));
    data_element[33].name = "Track 2 data";
    data_element[33].type = f_8;

    data_element[34].name = calloc(strlen("Track 3 data") + 1, sizeof(char));
    data_element[34].name = "Track 3 data";
    data_element[34].type = f_8;

    data_element[35].name = calloc(strlen("Retrieval reference number") + 1, sizeof(char));
    data_element[35].name = "Retrieval reference number";
    data_element[35].type = f_8;

    data_element[36].name = calloc(strlen("Authorization identification response") + 1, sizeof(char));
    data_element[36].name = "Authorization identification response";
    data_element[36].type = f_8;

    data_element[37].name = calloc(strlen("Response code") + 1, sizeof(char));
    data_element[37].name = "Response code";
    data_element[37].type = f_8;

    data_element[38].name = calloc(strlen("Service restriction code") + 1, sizeof(char));
    data_element[38].name = "Service restriction code";
    data_element[38].type = f_8;

    data_element[39].name = calloc(strlen("Card acceptor terminal identification") + 1, sizeof(char));
    data_element[39].name = "Card acceptor terminal identification";
    data_element[39].type = f_8;

    data_element[40].name = calloc(strlen("Card acceptor identification code") + 1, sizeof(char));
    data_element[40].name = "Card acceptor identification code";
    data_element[40].type = f_8;

    data_element[41].name = calloc(strlen("Card acceptor name/location") + 1, sizeof(char));
    data_element[41].name = "Card acceptor name/location";
    data_element[41].type = f_8;

    data_element[42].name = calloc(strlen("Additional response data") + 1, sizeof(char));
    data_element[42].name = "Additional response data";
    data_element[42].type = f_8;

    data_element[43].name = calloc(strlen("Additional response data") + 1, sizeof(char));
    data_element[43].name = "Additional response data";
    data_element[43].type = f_8;

    data_element[44].name = calloc(strlen("Track 1 data") + 1, sizeof(char));
    data_element[44].name = "Track 1 data";
    data_element[44].type = f_8;

    data_element[45].name = calloc(strlen("Additional data - ISO") + 1, sizeof(char));
    data_element[45].name = "Additional data - ISO";
    data_element[45].type = f_8;

    data_element[46].name = calloc(strlen("Additional data - national") + 1, sizeof(char));
    data_element[46].name = "Additional data - national";
    data_element[46].type = f_8;

    data_element[47].name = calloc(strlen("Additional data - private") + 1, sizeof(char));
    data_element[47].name = "Additional data - private";
    data_element[47].type = f_8;

    data_element[48].name = calloc(strlen("Currency code, transaction") + 1, sizeof(char));
    data_element[48].name = "Currency code, transaction";
    data_element[48].type = f_8;

    data_element[49].name = calloc(strlen("Currency code, settlement") + 1, sizeof(char));
    data_element[49].name = "Currency code, settlement";
    data_element[49].type = f_8;

    data_element[50].name = calloc(strlen("") + 1, sizeof(char));
    data_element[50].name = "";
    data_element[50].type = f_8;

    data_element[51].name = calloc(strlen("Currency code, cardholder billing") + 1, sizeof(char));
    data_element[51].name = "Currency code, cardholder billing";
    data_element[51].type = f_8;

    data_element[52].name = calloc(strlen("Personal identification number data") + 1, sizeof(char));
    data_element[52].name = "Personal identification number data";
    data_element[52].type = f_8;

    data_element[53].name = calloc(strlen("Security related control information") + 1, sizeof(char));
    data_element[53].name = "Security related control information";
    data_element[53].type = f_8;

    data_element[54].name = calloc(strlen("Additional amounts") + 1, sizeof(char));
    data_element[54].name = "Additional amounts";
    data_element[54].type = f_8;

    data_element[55].name = calloc(strlen("ICC Data - EMV having multiple tags") + 1, sizeof(char));
    data_element[55].name = "ICC Data - EMV having multiple tags";
    data_element[55].type = f_8;

    data_element[56].name = calloc(strlen("Reserved ISO") + 1, sizeof(char));
    data_element[56].name = "Reserved ISO";
    data_element[56].type = f_8;

    data_element[57].name = calloc(strlen("Reserved national") + 1, sizeof(char));
    data_element[57].name = "Reserved national";
    data_element[57].type = lllvar;

    data_element[58].name = calloc(strlen("Reserved national") + 1, sizeof(char));
    data_element[58].name = "Reserved national";
    data_element[58].type = lllvar;

    data_element[59].name = calloc(strlen("Reserved national") + 1, sizeof(char));
    data_element[59].name = "Reserved national";
    data_element[59].type = lllvar;

    data_element[60].name = calloc(strlen("Reserved national") + 1, sizeof(char));
    data_element[60].name = "Reserved national";
    data_element[60].type = lllvar;

    data_element[61].name = calloc(strlen("Reserved private (Ex: CVV2/Service Code)") + 1, sizeof(char));
    data_element[61].name = "Reserved private (Ex: CVV2/Service Code)";
    data_element[61].type = lllvar;

    data_element[62].name = calloc(strlen("Reserved private (Invoice Number, TPK Key") + 1, sizeof(char));
    data_element[62].name = "Reserved private (Invoice Number, TPK Key";
    data_element[62].type = lllvar;

    data_element[63].name = calloc(strlen("Reserved private") + 1, sizeof(char));
    data_element[63].name = "Reserved private";
    data_element[63].type = lllvar;
}