#pragma once
#include "Day.h"

class Day14 : public Day
{
 public:
  Day14(std::string path, int dayNum);

  std::string SolvePart1() override;
  std::string SolvePart2() override;

 private:
  struct Robot
  {
   int X;
   int Y;
   int Velocity_X;
   int Velocity_Y;
  };
 int mFieldWidth;
 int mFieldHeight;
 std::vector<Robot> mRobots; 
 void FillRobotsVec();
 void MoveRobots();
 void CountRobotsInQuadrants(int& area1, int& area2, int& area3, int& area4);
 void FillMatrix(std::vector<std::vector<char>>& dest);
};