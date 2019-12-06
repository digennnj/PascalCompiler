#include "pascal.h"
char *convert_to_int(const char val[]) {
    char *res = temp_int();
    char *temp = temp_real();
    //outFile << "store " << val << ", " << temp << std::endl;
    *cur_out() += "store " + std::string(val) + ", " + std::string(temp) + "\n";
    //outFile << "rtoi " << temp << ", " << res << std::endl;
    *cur_out() += "rtoi " + std::string(temp) + ", " + std::string(res) + "\n";
    return res;
}

char *convert_to_real(const char val[]) {
    char *res = temp_real();
    char *temp = temp_int();
    //outFile << "store " << val << ", " << temp << std::endl;
    *cur_out() += "store " + std::string(val) + ", " + std::string(temp) + "\n";
    //outFile << "itor " << temp << ", " << res << std::endl;
    *cur_out() += "itor " + std::string(temp) + ", " + std::string(res) + "\n";
    return res;
}
