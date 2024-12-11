#include "Day1.h"
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>


Day1::Day1(std::string path, int dayNum) : 
 Day(path, dayNum)
{}


std::string Day1::SolvePart1()
{
 std::vector<int> numbersLeft;
 std::vector<int> numbersRight;

 numbersLeft.reserve(mLines.size());
 numbersRight.reserve(mLines.size());

 for (int i = 0; i < mLines.size(); i++)
 {
  std::string left = mLines[i].substr(0, mLines[i].find(" "));
  std::string right = mLines[i].substr(mLines[i].rfind(" ")+1, mLines[i].rfind(" ") - mLines[i].length());
  numbersLeft.emplace_back(std::stoi(left));
  numbersRight.emplace_back(std::stoi(right));
 }

 std::sort(numbersLeft.begin(), numbersLeft.end());
 std::sort(numbersRight.begin(), numbersRight.end());

 int totalDistance = 0;

 for(int i = 0; i < numbersLeft.size() && i < numbersRight.size(); i++)
 {
  int L = numbersLeft[i];
  int R = numbersRight[i];
  int diff = L > R ? L-R : R-L;
  totalDistance += diff;
 }

 return std::to_string(totalDistance);
}

std::string Day1::SolvePart2()
{
 std::vector<int> numbersLeft;
 std::vector<int> numbersRight;

 numbersLeft.reserve(mLines.size());
 numbersRight.reserve(mLines.size());

 for (int i = 0; i < mLines.size(); i++)
 {
  std::string left = mLines[i].substr(0, mLines[i].find(" "));
  std::string right = mLines[i].substr(mLines[i].rfind(" ")+1, mLines[i].rfind(" ") - mLines[i].length());
  numbersLeft.emplace_back(std::stoi(left));
  numbersRight.emplace_back(std::stoi(right));
 }

 std::map<int, int> appearances;

 for (int i = 0; i < numbersRight.size();i++)
 {
  appearances[numbersRight[i]]++;
 }

 int result = 0;

 for (int i = 0; i < numbersLeft.size(); i++)
 {
  if (appearances.find(numbersLeft[i]) != appearances.end())
  {
   result += numbersLeft[i] * appearances[numbersLeft[i]];
  }
 }

 return std::to_string(result);
}



