#pragma once
#include "Day.h"


class Day4 : public Day
{
 public:
  Day4(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;

 private:
  bool IsXMASHorizontalForwards(int vertIndex, int horIndex, const std::vector<std::string>& lines);
  bool IsXMASHorizontalBackwards(int vertIndex, int horIndex, const std::vector<std::string>& lines);
  bool IsXMASVerticalDownwards(int vertIndex, int horIndex, const std::vector<std::string>& lines);
  bool IsXMASVerticalUpwards(int vertIndex, int horIndex, const std::vector<std::string>& lines);
  bool IsXMASDiagonalDownwardsLtoR(int vertIndex, int horIndex, const std::vector<std::string>& lines);
  bool IsXMASDiagonalUpwardsRtoL(int vertIndex, int horIndex, const std::vector<std::string>& lines);
  bool IsXMASDiagonalDownwardsRtoL(int vertIndex, int horIndex, const std::vector<std::string>& lines);
  bool IsXMASDiagonalUpwardsLtoR(int vertIndex, int horIndex, const std::vector<std::string>& lines);

  bool MASinXFormatCheck(int vertIndex, int horIndex, const std::vector<std::string>& lines);
};