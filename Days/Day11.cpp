#include "Day11.h"
#include <algorithm>
#include <iostream>

Day11::Day11(std::string path, int dayNum) : 
 Day(path, dayNum)
{}




void Day11::Blink(std::string& stones)
{
 std::string newStones;
 //Seperating the stones and building the newStones string with the transformed stones
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
   stone = stones.substr(offset, stones.length() - offset);
   offset = nextSpace;
  }
  
  if (stone == "0")
  {
   newStones += "1 ";
   continue; 
  }
  else if (stone.length() % 2 == 0)
  {
   std::string part1 = stone.substr(0, stone.length()/2);
   std::string part2 = stone.substr(stone.length()/2 - 1, stone.length()/2);
   std::cout << part1 << "\n";
   std::cout << part2 << "\n";
   
   //cut leading zeros from the string
   if (part2[0] == '0') 
    part2 = std::to_string(std::stoi(part2));

   newStones += part1 + " " + part2 + " ";
  }
  else
  {
   int stoneNum = std::stoi(stone);
   int multipliedStoneNum = stoneNum * 2024;
   newStones += std::to_string(multipliedStoneNum) + " "; 
  }

 }


 newStones.erase(newStones.length()-1, 1); //deleting trailing space
 stones = newStones;
}

std::string Day11::SolvePart1()
{
 //since the file only has one line anyway
 std::string stones = mLines[0];
 
 for (int count = 0; count < 25; count++)
 {
  Blink(stones);  
 }

 //to count the stones we can just count the spaces since every stone is seperated by a space
 int countedSpaces = std::count(stones.begin(), stones.end(), ' ');
 

 return std::to_string(countedSpaces-1);
}

std::string Day11::SolvePart2()
{
 return "Not implemented yet.";
}
