#pragma once
#include "Day.h"


class Day1 : public Day
{
 public:
  Day1(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;
};