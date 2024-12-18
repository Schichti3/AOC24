#pragma once
#include <string>
#include <vector>

class Day
{
 public:
  Day(std::string path, int dayNum);
  virtual std::string SolvePart1();
  virtual std::string SolvePart2();
  int GetDayNumber();
 protected:
  std::string mPath;
  std::vector<std::string> mLines;
 private:
  int mDayNumber;
};