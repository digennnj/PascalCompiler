#include "pascal.h"
void assign_lit(const char target[], const char source[])
{
    //outFile << "store " << source << ", " << target << std::endl;
    *cur_out() += "store " + std::string(source) + ", " + std::string(target) + "\n";
}
void assign (const char target[], const char source[])
{
    target = full_name(target);
    source = full_name(source);
     /* Generate code for assignment. */
    Variable *targetVar = lookup(target);
    Variable *sourceVar = lookup(source);
     if (targetVar==NULL) {printSymbolTable(); error("TARGET SYMBOL NOT DEFINED: "+std::string(target));}
     else if (sourceVar==NULL) {printSymbolTable(); error("SOURCE SYMBOL NOT DEFINED FOR "+std::string(target)+": "+std::string(source));}
     else {
          if (targetVar->type != sourceVar->type) {
              if (targetVar->type == REAL) {
                  if (sourceVar->type == INT) {
                    char * temp = convert_to_real(source);
                    //outFile << "store " << temp << ", " << target << std::endl;
                    *cur_out() += "store " +std::string(temp) + ", " +std::string(target) + "\n";
                  }
                  else {error("Can't assign "+type_str(sourceVar->type)+" value to a real");}
              }
              else if (targetVar->type == INT) {
                  if (sourceVar->type == REAL) {
                    char * temp = convert_to_int(source);
                    //outFile << "store " << temp << ", " << target << std::endl;
                    *cur_out() += "store " +std::string(temp) + ", " +std::string(target) + "\n";
                  }
                  else {error("Can't assign "+type_str(sourceVar->type)+" value to a int");}
              }
              else {
                  error("Can't assign "+type_str(sourceVar->type)+" value to a "+type_str(targetVar->type));
              }
          } else {
               //outFile << "store " << source << ", " << target << std::endl;
               *cur_out() += "store " + std::string(source) + ", " + std::string(target) + "\n";
          }
     }
}
