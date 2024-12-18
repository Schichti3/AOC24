#include "Day.h"
#include <fstream>
#include <iostream>

Day::Day(std::string path, int dayNum) : 
 mPath(path),
 mDayNumber(dayNum)
{
 std::ifstream inputFile(mPath);
 std::string line;

 while (std::getline(inputFile, line)) 
 {
  mLines.push_back(line);
 }

 inputFile.close();
}

std::string Day::SolvePart1()
{
 return "Not implemented.";
}

std::string Day::SolvePart2()
{
 return "Not implemented.";
}

int Day::GetDayNumber()
{
 return mDayNumber;   
}