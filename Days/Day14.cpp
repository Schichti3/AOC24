#include "Day14.h"
#include <iostream>
#include <string>
#include <sstream>

Day14::Day14(std::string path, int dayNum) : 
 Day(path, dayNum)
{
 FillRobotsVec();
 mFieldWidth = 101;
 mFieldHeight = 103;
}

void Day14::FillRobotsVec()
{
 mRobots.clear();
 mRobots.reserve(mLines.size());
 for (int i = 0; i < mLines.size(); i++)
 {
  std::string line = mLines[i];
  int offset = 0;

  //get x
  int firstNumPos = line.find("p=")+2;
  int firstCommaPos = line.find(",");
  int secondNumPos = firstCommaPos + 1;
  int firstSpacePos = line.find(" "); 
  int thirdNumPos = line.find("v=")+2;
  int secondCommaPos = line.rfind(",");
  int fourthNumPos = secondCommaPos + 1;
  std::string x = line.substr(firstNumPos, firstCommaPos - firstNumPos);
  std::string y = line.substr(secondNumPos, firstSpacePos - secondNumPos);
  std::string velo_x = line.substr(thirdNumPos, secondCommaPos - thirdNumPos); 
  std::string velo_y = line.substr(fourthNumPos, line.length() - fourthNumPos); 

  Robot newRobot = { std::stoi(x), std::stoi(y), std::stoi(velo_x), std::stoi(velo_y) };
  mRobots.emplace_back(std::move(newRobot));
 }
}

void Day14::MoveRobots()
{
 for (auto robotIt = mRobots.begin(); robotIt != mRobots.end(); robotIt++)
 {
  robotIt->X += robotIt->Velocity_X;
  if (robotIt->X < 0)
  {
   robotIt->X = mFieldWidth - std::abs(robotIt->X);
  }
  else if (robotIt->X >= mFieldWidth)
  {
   robotIt->X = robotIt->X - mFieldWidth;
  }
  robotIt->Y += robotIt->Velocity_Y;
  if (robotIt->Y < 0)
  {
   robotIt->Y = mFieldHeight - std::abs(robotIt->Y);
  }
  else if (robotIt->Y >= mFieldHeight)
  {
   robotIt->Y = robotIt->Y - mFieldHeight;
  }
 } 
}

void Day14::CountRobotsInQuadrants(int& area1, int& area2, int& area3, int& area4)
{
 for (auto robotIt = mRobots.begin(); robotIt != mRobots.end(); robotIt++)
 {
  //area 1 x 0-49 y 0-50
  if (robotIt->X >= 0 && robotIt->X <= 49 &&
      robotIt->Y >= 0 && robotIt->Y <= 50)
  {
   area1++;
  }

  //area 2 x 51-100 y 0-50 
  if (robotIt->X >= 51 && robotIt->X <= 100 &&
      robotIt->Y >= 0 && robotIt->Y <= 50)
  {
   area2++;
  }

  //area 3 x 0-49 y 52-102
  if (robotIt->X >= 0 && robotIt->X <= 49 &&
      robotIt->Y >= 52 && robotIt->Y <= 102)
  {
   area3++;
  }

  //area 4 x 51-100 y 52-102
  if (robotIt->X >= 51 && robotIt->X <= 100 &&
      robotIt->Y >= 52 && robotIt->Y <= 102)
  {
   area4++;
  }
 }
}

std::string Day14::SolvePart1()
{
 //move robots
 for (int seconds = 0; seconds < 100; seconds++)
 {
  MoveRobots();
 }

 int area1RobotCount = 0;
 int area2RobotCount = 0;
 int area3RobotCount = 0;
 int area4RobotCount = 0;

 //count robots in the areas
 CountRobotsInQuadrants(area1RobotCount, area2RobotCount, area3RobotCount, area4RobotCount);
 
 return std::to_string(area1RobotCount * area2RobotCount * area3RobotCount * area4RobotCount);
}

void Day14::FillMatrix(std::vector<std::vector<char>>& dest)
{
 dest.reserve(mFieldHeight);
 //build empty matrix
 for (int i = 0; i < mFieldHeight; i++)
 {
  std::vector<char> row;
  row.reserve(mFieldWidth);
  for (int j = 0; j < mFieldWidth; j++)
  {
   row.emplace_back(' ');
  }
  dest.emplace_back(std::move(row));
 }

 //fill matrix
 for (auto robotIt = mRobots.begin(); robotIt != mRobots.end(); robotIt++)
 {
  dest[robotIt->X][robotIt->Y] = '#';
 } 
}

std::string Day14::SolvePart2()
{
 FillRobotsVec();
 int seconds = 7338; //reached this number by trying out until a christmas tree was visible
 for (int i = 0; i < seconds; i++)
 {
  MoveRobots();
 }
 
 std::vector<std::vector<char>> matrix;
 FillMatrix(matrix);

 std::stringstream ss;
 ss << seconds << "\n\n";
 for (auto matrixIt = matrix.begin(); matrixIt != matrix.end(); matrixIt++)
 {
  for (int i = 0; i < matrixIt->size(); i++)
  {
   ss << matrixIt->at(i);
  }
  if (matrixIt != matrix.end()-1)
  {
   ss << "\n";
  }
 }

 return ss.str();
}
