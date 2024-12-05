#include "Day.h"
#include <fstream>
#include <iostream>

Day::Day(std::string path) : 
 mPath(path)
{
 std::ifstream inputFile(mPath);
 std::string line;

 while (std::getline(inputFile, line)) 
 {
  mLines.push_back(line);
 }

 inputFile.close();
}
