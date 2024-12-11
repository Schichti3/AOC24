#pragma once
#include "Day.h"


class Day2 : public Day
{
 public:
  Day2(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;
};