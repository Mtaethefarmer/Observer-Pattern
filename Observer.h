/*************************************
Name: Devone Reynolds
Date: 15 AUG 18
Subject: Observer Pattern
**************************************/
#ifndef OBSERVER_H
#define OBSERVER_H

class Observer 
{
  public:
  virtual ~Observer() = default;
  //Keeps track of the object's state
  virtual void update() = 0;
};

#endif