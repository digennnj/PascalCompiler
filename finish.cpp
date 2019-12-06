#include <iostream>
#include <fstream>
extern std::ofstream outFile;

void finish()
{
  outFile << "halt" << std::endl;
}

// void write_methods() 
// {
//   while(!methodFiles.empty()) {

//     outFile <<  << std::endl;
//   }
// }
