#pragma once
#include "Day.h"


class Day3 : public Day
{
 public:
  Day3(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;
};