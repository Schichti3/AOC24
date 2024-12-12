#include "Day11.h"
#include <algorithm>
#include <iostream>
#include <string_view>

Day11::Day11(std::string path, int dayNum) : 
 Day(path, dayNum)
{}

std::vector<unsigned long long> Day11:: GetStones(std::string& stones)
{
 std::vector<unsigned long long> output;
 int offset = 0;
 while (offset != stones.npos)
 {
  int nextSpace = stones.find(" ", offset);
  std::string stone;
  if (nextSpace != stones.npos)
  {
   stone = stones.substr(offset, nextSpace - offset);
   offset = nextSpace + 1;
  }
  else
  {
   stone =  stones.substr(offset, stones.length() - offset);
   offset = nextSpace;
  }
  output.push_back(std::stoi(stone));
 }
 
 return output;
} 

void Day11::Blink(std::vector<unsigned long long>& stones)
{
 int vecSize = stones.size();
 for (int i = 0; i < vecSize; i++)
 {
  std::string stoneString = std::to_string(stones[i]);
  if (stones[i] == 0)
  {
   stones[i] = 1;
  }
  else if (stoneString.length() % 2 == 0)
  {
   stones[i] = std::stoull(stoneString.substr(0, stoneString.length()/2));
   stones.push_back(std::stoull(stoneString.substr(stoneString.length()/2, stoneString.length()/2)));
  }
  else
  {
   stones[i] = stones[i] * 2024; 
  }
 }
}

std::string Day11::SolvePart1()
{
 //since the file only has one line anyway
 std::string stones = mLines[0];
 std::vector<unsigned long long> stonesVec = GetStones(stones); 
 for (int count = 0; count < 25; count++)
 {
  Blink(stonesVec);  
 }

 return std::to_string(stonesVec.size());
}

std::string Day11::SolvePart2()
{
//  //since the file only has one line anyway
 //std::string stones = mLines[0];
 //std::vector<unsigned long long> stonesVec = GetStones(stones); 
 //for (int count = 0; count < 75; count++)
 //{
  //Blink(stonesVec);  
 //}

 //return std::to_string(stonesVec.size());
 return "Not implemented yet.";
}
