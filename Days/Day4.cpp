#include "Day4.h"


Day4::Day4(std::string path) : 
 Day(path)
{}


bool Day4::IsXMASHorizontalForwards(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (horIndex <= lines[vertIndex].size()-4)
 {
  if (lines[vertIndex][horIndex] == 'X' &&
      lines[vertIndex][horIndex+1] == 'M' &&
      lines[vertIndex][horIndex+2] == 'A' &&
      lines[vertIndex][horIndex+3] == 'S')
  {
   return true;
  }
 }

 return false;
}

bool Day4::IsXMASHorizontalBackwards(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (horIndex >= 3)
 {
  if (lines[vertIndex][horIndex] == 'X' &&
      lines[vertIndex][horIndex-1] == 'M' &&
      lines[vertIndex][horIndex-2] == 'A' &&
      lines[vertIndex][horIndex-3] == 'S')
  {
   return true;
  }
 }

 return false;
}

bool Day4::IsXMASVerticalDownwards(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (vertIndex <= lines.size()-4)
 {
  if (lines[vertIndex][horIndex] == 'X' &&
      lines[vertIndex+1][horIndex] == 'M' &&
      lines[vertIndex+2][horIndex] == 'A' &&
      lines[vertIndex+3][horIndex] == 'S')
  {
   return true;
  }
 }

 return false;
}

bool Day4::IsXMASVerticalUpwards(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (vertIndex >= 3)
 {
  if (lines[vertIndex][horIndex] == 'X' &&
      lines[vertIndex-1][horIndex] == 'M' &&
      lines[vertIndex-2][horIndex] == 'A' &&
      lines[vertIndex-3][horIndex] == 'S')
  {
   return true;
  }
 }

 return false; 
}

bool Day4::IsXMASDiagonalDownwardsLtoR(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (horIndex <= lines[vertIndex].size()-4 && vertIndex <= lines.size()-4)
 {
  if (lines[vertIndex][horIndex] == 'X' &&
      lines[vertIndex+1][horIndex+1] == 'M' &&
      lines[vertIndex+2][horIndex+2] == 'A' &&
      lines[vertIndex+3][horIndex+3] == 'S')
  {
   return true;
  }
 }

 return false; 
}

bool Day4::IsXMASDiagonalUpwardsRtoL(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (horIndex >= 3 && vertIndex >= 3)
 {
  if (lines[vertIndex][horIndex] == 'X' &&
      lines[vertIndex-1][horIndex-1] == 'M' &&
      lines[vertIndex-2][horIndex-2] == 'A' &&
      lines[vertIndex-3][horIndex-3] == 'S')
  {
   return true;
  }
 }

 return false; 
}

bool Day4::IsXMASDiagonalDownwardsRtoL(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (horIndex >= 3 && vertIndex <= lines.size()-4)
 {
  if (lines[vertIndex][horIndex] == 'X' &&
      lines[vertIndex+1][horIndex-1] == 'M' &&
      lines[vertIndex+2][horIndex-2] == 'A' &&
      lines[vertIndex+3][horIndex-3] == 'S')
  {
   return true;
  }
 }

 return false; 
}

bool Day4::IsXMASDiagonalUpwardsLtoR(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (horIndex <= lines[vertIndex].size()-4 && vertIndex >= 3)
 {
  if (lines[vertIndex][horIndex] == 'X' &&
      lines[vertIndex-1][horIndex+1] == 'M' &&
      lines[vertIndex-2][horIndex+2] == 'A' &&
      lines[vertIndex-3][horIndex+3] == 'S')
  {
   return true;
  }
 }

 return false; 
}


std::string Day4::SolvePart1()
{
 int xmasCount = 0;

 for (int i = 0; i < mLines.size(); i++)
 {
  std::string line = mLines[i];
  for(int j = 0; j < line.size(); j++)
  {
   if (IsXMASHorizontalForwards(i, j, mLines)) 
    xmasCount++;
   if (IsXMASHorizontalBackwards(i, j, mLines)) 
    xmasCount++;
   if (IsXMASVerticalDownwards(i, j, mLines)) 
    xmasCount++;
   if (IsXMASVerticalUpwards(i, j, mLines)) 
    xmasCount++;
   if (IsXMASDiagonalDownwardsLtoR(i, j, mLines)) 
    xmasCount++;
   if (IsXMASDiagonalUpwardsRtoL(i, j, mLines)) 
    xmasCount++;
   if (IsXMASDiagonalDownwardsRtoL(i, j, mLines)) 
    xmasCount++;
   if (IsXMASDiagonalUpwardsLtoR(i, j, mLines)) 
    xmasCount++;
  }
 }

 return std::to_string(xmasCount);
}


bool Day4::MASinXFormatCheck(int vertIndex, int horIndex, const std::vector<std::string>& lines)
{
 if (horIndex <= lines[vertIndex].size()-3 && vertIndex <= lines.size()-3)
 {
  if (((lines[vertIndex][horIndex] == 'M' &&
      lines[vertIndex+1][horIndex+1] == 'A' &&
      lines[vertIndex+2][horIndex+2] == 'S') ||
      (lines[vertIndex][horIndex] == 'S' &&
      lines[vertIndex+1][horIndex+1] == 'A' &&
      lines[vertIndex+2][horIndex+2] == 'M')) &&

      ((lines[vertIndex][horIndex+2] == 'M' &&
      lines[vertIndex+1][horIndex+1] == 'A' &&
      lines[vertIndex+2][horIndex] == 'S') ||
      (lines[vertIndex][horIndex+2] == 'S' &&
      lines[vertIndex+1][horIndex+1] == 'A' &&
      lines[vertIndex+2][horIndex] == 'M')) )
  {
   return true;
  }
 }

 return false; 
}

std::string Day4::SolvePart2()
{
 int actualXFormatMASCount = 0;

 for (int i = 0; i < mLines.size(); i++)
 {
  std::string line = mLines[i];
  for(int j = 0; j < line.size(); j++)
  {
   if(MASinXFormatCheck(i, j, mLines))
    actualXFormatMASCount++;
  }
 }
 return std::to_string(actualXFormatMASCount);
}
