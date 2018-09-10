/*************************************
Name: Devone Reynolds
Date: 15 AUG 18
Subject: Observer Pattern
**************************************/
#ifndef MESSENGER_H
#define MESSENGER_H

#include "Observer.h"
#include "Marker.h"

class Messenger:public Observer
{
  public:
  //Constructor
  //Should contain multiple constructors to satisfy messages for each object
  Messenger(Marker& mark);
  
  //Destructor
  ~Messenger(){};
  
  //Prints state of object
  virtual void update();
  
  private:
  //Reference to the subscribed signal
  //If Messenger had a reference to the Signal class it would not be able to 
  //access member functions of a child class
  Marker& _marker;
};

#endif