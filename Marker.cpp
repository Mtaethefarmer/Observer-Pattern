/*************************************
Name: Devone Reynolds
Date: 15 AUG 18
Subject: Observer Pattern
**************************************/
#include "Marker.h"

void Marker::setColor(Color color)
{
  //Set the current color
  _current = color;
  
  //Notify the observers
  emit_signal();
}

std::ostream& operator<<(std::ostream& os, const Marker& mark)
{
  os << mark._current;
  return os;
}