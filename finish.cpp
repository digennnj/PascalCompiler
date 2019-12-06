#include "pascal.h"
void finish()
{
  //outFile << "halt" << std::endl;
  *cur_out() += std::string("halt") + "\n";
  outFile << *cur_out();
  for (auto it = completedFunctions.begin(); it!=completedFunctions.end(); it++) {
      std::string functionBody = **it;
      outFile << "\n" << functionBody;
  }
}
