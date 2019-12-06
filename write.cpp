#include "pascal.h"
void write_expr(char id_name[])
{
    id_name = full_name(id_name);
   //outFile << "write " << id_name << std::endl;
   *cur_out() += std::string("write ") + std::string(id_name) + "\n";
}
