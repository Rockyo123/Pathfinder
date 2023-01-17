#include <iostream>
#include <image.h>
#include "deque.hpp"
#include<stdlib.h>

#include "lib/image.h"


//find if pixel is a goal
bool goal(size_t r, size_t c, size_t width, size_t height)
{
  if(r == 0 || c == 0 || r == height-1 || c == width -1)
  {
      return true;
  }
  return false;
}

//find if pixel is in frontier
bool inFrontier(std::vector<size_t> s, Deque<std::vector<size_t>> PixDeq)
{
  while(!(PixDeq.isEmpty()))
  {
    if(s[0] == PixDeq.back()[0] && s[1] == PixDeq.back()[1])
    {
      return true;
    }
    PixDeq.popBack();
  }
  return false;
}

//find if pixel is in explored
bool inExplored(std::vector<size_t> s, std::vector<std::vector<size_t>> exp)
{
  for(size_t i = 0; i < exp.size(); i++)
  {
    if(s[0] == exp[i][0] && s[1] == exp[i][1])
    {
      return true;
    }
  }
  return false;
}


int main(size_t argc, char *argv[])
{
  //reads in image file into im
  Image<Pixel> im = readFromFile(argv[1]);
  
  //finding start point of maze
  size_t width = im.width();
  size_t height = im.height();
  size_t r;
  size_t c;
  
  bool found = false;
  for(size_t i = 0; i < width; i++)
  {
    for(size_t j = 0; j < height; j++)
    {
      if (im(i,j) == RED)
      {
        //multiple red squares
        if(found)
        {
          std::cout <<"Error: multiple red squares found" << std::endl;
          exit(EXIT_FAILURE);
        }
        r = i;
        c= j;
        found = true;
        //if start is goal, change color, writeToFile
        if(i == 0 || j == 0 || i == width-1 || j == height -1)
        {
          im(i,j) = GREEN;
          writeToFile(im, argv[2]);
          exit(EXIT_SUCCESS);
        }

      }
      //other colors than black red and white
      if(im(i,j) != RED && im(i,j) != BLACK && im(i,j) != WHITE)
      {
        std::cout <<"Error: Maze must only have black, red, and white squares" << std::endl;
        exit(EXIT_FAILURE);
      }
    }
  }
   //start search for exit
  std::vector<std::vector<size_t>> explored;
  Deque<std::vector<size_t>> frontier;

  frontier.pushBack({r, c});

  std::vector<size_t> s;

  while(1)
  {
    //no exit
    if(frontier.isEmpty())
    {
      std::cout << "No Solution Found" << std::endl;
      writeToFile(im, argv[2]);
      exit(EXIT_SUCCESS);
    }
    s = frontier.back();
    frontier.popBack();
    explored.push_back({s[0], s[1]});


    std::vector<size_t> s_up = {s[0]-1, s[1]};
    std::vector<size_t> s_down = {s[0]+1, s[1]};
    std::vector<size_t> s_left = {s[0], s[1]-1};
    std::vector<size_t> s_right ={s[0],s[1]+1}; 

    //up in path
    if(im(s_up[0],s_up[1]) == WHITE)
    {
      if(!(inExplored({s_up[0], s_up[1]}, explored)) && !(inFrontier({s_up[0], s_up[1]}, frontier)))
      {
        //if s is goal, change color, writeToFile
        if(goal(s_up[0], s_up[1], width, height))
        {       
          im(s_up[0],s_up[1]) = GREEN;
          break;
        }
        //not goal, add to frontier
        frontier.pushFront(s_up);
      }
    }

    //down in path
    if(im(s_down[0],s_down[1]) == WHITE)
    {
      if(!(inExplored({s_down[0], s_down[1]}, explored)) && !(inFrontier({s_down[0], s_down[1]}, frontier)))
      {
        //if s is goal, change color, writeToFile
        if(goal(s_down[0], s_down[1], width, height))
        {       
          im(s_down[0],s_down[1]) = GREEN;
          break;
        }
        //not goal, add to frontier
        frontier.pushFront(s_down);
      }
    }

    //left in path
    if(im(s_left[0],s_left[1]) == WHITE)
    {
      if(!(inExplored({s_left[0], s_left[1]}, explored)) && !(inFrontier({s_left[0], s_left[1]}, frontier)))
      {
      //if s is goal, change color, writeToFile
      if(goal(s_left[0], s_left[1], width, height))
      {       
        im(s_left[0],s_left[1]) = GREEN;
        break;
      }
      //not goal, add to frontier
      frontier.pushFront(s_left);
      }
    }

    //right in path
    if(im(s_right[0],s_right[1]) == WHITE)
    {
      if(!(inExplored({s_right[0], s_right[1]}, explored)) && !(inFrontier({s_right[0], s_right[1]}, frontier)))
      {
        //if s is goal, change color, writeToFile
        if(goal(s_right[0], s_right[1], width, height))
        {       
          im(s_right[0],s_right[1]) = GREEN;
          break;
        }
        //not goal, add to frontier
        frontier.pushFront(s_right);
      }
    }
  }
  //writes completed image to file
  std::cout << "\nsolution found" <<std::endl;
  writeToFile(im, argv[2]);
  exit(EXIT_SUCCESS); 
} 

