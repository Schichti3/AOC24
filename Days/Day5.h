#pragma once
#include "Day.h"
#include <map>

struct OrderingRule
{
 int EarlierPage;
 int LaterPage;
};

class Day5 : public Day
{
 public:
  Day5(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;

 private:
  std::vector<OrderingRule> ExtractOrderingRules(std::vector<std::string>& lines);
  std::vector<std::vector<int>> ExtractUpdates(std::vector<std::string>& lines);
};