#pragma once
#include <string>
#include <vector>

class Day
{
 public:
  Day(std::string path);
  virtual std::string SolvePart1() = 0;
  virtual std::string SolvePart2() = 0;
 protected:
  std::string mPath;
  std::vector<std::string> mLines;
};