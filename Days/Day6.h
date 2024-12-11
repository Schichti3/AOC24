#pragma once
#include "Day.h"

class Day6 : public Day
{
 public:
  Day6(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;

 private:
  void MoveGuard(int startX, int startY, char startDirection, std::vector<std::string>& lines);
};