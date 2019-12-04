#include <stdio.h>
#include <iostream>
#include <fstream>
#include "symbol_table.h"
extern std::ofstream outFile;
extern char *temp_int();
extern char *temp_real();

char *convert_to_int(const char val[]) {
    char *res = temp_int();
    char *temp = temp_real();
    outFile << "store " << val << ", " << temp << std::endl;
    outFile << "rtoi " << temp << ", " << res << std::endl;
    return res;
}

char *convert_to_real(const char val[]) {
    char *res = temp_real();
    char *temp = temp_int();
    outFile << "store " << val << ", " << temp << std::endl;
    outFile << "itor " << temp << ", " << res << std::endl;
    return res;
}
