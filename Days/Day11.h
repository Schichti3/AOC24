#pragma once
#include "Day.h"

class Day11 : public Day
{
 public:
  Day11(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;
 private:
  void Blink(std::string& stones);
};