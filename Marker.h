/*************************************
Name: Devone Reynolds
Date: 15 AUG 18
Subject: Observer Pattern
**************************************/
#ifndef MARKER_H
#define MARKER_H

#include "Signal.h"
#include "iostream"

//Seletectable Colors
enum Color{WHITE, BLACK, RED, BLUE, YELLOW};

class Marker: public Signal
{
  public:
  //Default constructor
  Marker(Color color = Color::WHITE){_current = color;};
  
  //Destructor
  ~Marker(){};
  
  //Getter
  Color getColor(){return _current;};
  
  //Setter
  void setColor(Color color);

  //Overload the output operator
  friend std::ostream& operator<<(std::ostream& os, const Marker& mark);
  
  private:
  //Current color selected.
  Color _current;
};

#endif