#include "Day6.h"
#include <algorithm>

Day6::Day6(std::string path, int dayNum) : 
 Day(path, dayNum)
{}

void Day6::MoveGuard(int startX, int startY, char startDirection, std::vector<std::string>& lines)
{
 int currentPosX = startX;
 int currentPosY = startY;
 int maxX = lines[0].size();
 int maxY = lines.size();
 char direction = startDirection;
 while(currentPosX >= 0 && currentPosX < maxX &&
       currentPosY >= 0 && currentPosY < maxY)
 {
  switch (direction)
  {
   case '^':
    lines[currentPosY][currentPosX] = 'X';
    if (lines[currentPosY-1][currentPosX] == '#')
    {
     direction = '>';
     break;
    }
    currentPosY--;
   break;
   case '>':
    lines[currentPosY][currentPosX] = 'X';
    if (lines[currentPosY][currentPosX+1] == '#')
    {
     direction = 'v';
     break;
    }
    currentPosX++;
   break;
   case 'v':
    lines[currentPosY][currentPosX] = 'X';
    if (lines[currentPosY+1][currentPosX] == '#')
    {
     direction = '<';
     break;
    }
    currentPosY++;
   break;
   case '<':
    lines[currentPosY][currentPosX] = 'X';
    if (lines[currentPosY][currentPosX-1] == '#')
    {
     direction = '^';
     break;
    }
    currentPosX--;
   break;
  }  
 }
}

std::string Day6::SolvePart1()
{
 char startDirection = ' ';
 int startX = 0;
 int startY = 0;
 for (int i = 0; i < mLines.size(); i++)
 {
  if (mLines[i].find_first_not_of(".#")!= mLines[i].npos)
  {
   int directionIndex = mLines[i].find_first_not_of(".#");
   startDirection = mLines[i][directionIndex];
   startY = i; 
   startX = directionIndex;
   break;
  }
 }
 
 MoveGuard(startX, startY, startDirection, mLines);

 //count X
 int result = 0;
 for (int i = 0; i < mLines.size(); i++)
 {
  result += std::count(mLines[i].begin(), mLines[i].end(), 'X'); 
 }
 return std::to_string(result);
}

std::string Day6::SolvePart2()
{
 return "Not implemented yet.";
}
