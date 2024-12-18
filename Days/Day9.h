#pragma once
#include "Day.h"
#include <map>

class Day9 : public Day
{
 public:
  Day9(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;

 private:
  
  void DecompressInput(std::map<int, int>& files, std::map<int, int>& freeSpaces);
  void CompressPart1(const std::map<int, int> files, const std::map<int, int> freeSpaces, std::map<int, int>& dest);
  void CompressPart2(const std::map<int, int> files, const std::map<int, int> freeSpaces, std::vector<int>& dest);
  unsigned long long GetCheckSum(const std::map<int, int>& compressed);
  void PrintCompressed(const std::map<int, int>& compressed);
};