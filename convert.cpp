#include "pascal.h"
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
