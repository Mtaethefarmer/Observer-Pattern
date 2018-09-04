/*************************************
Name: Devone Reynolds
Date: 15 AUG 18
Subject: Observer Pattern
**************************************/
#include "Signal.h"

typedef std::vector<Observer *>::iterator obsIt; 

void Signal::connect(Observer *obs)
{
  //Add observer to the list
  _obsList.push_back(obs);
}

void Signal::disconnect(Observer *obs)
{
  //For each observer
  for(obsIt it = _obsList.begin(); it != _obsList.end(); it++)
  {
    //Check if it matches the one to be removed
    if (*it == obs)
    {
      //Remove the selected observer
      _obsList.erase(it);
      break;
    }
  }
} 

void Signal::emit_signal()
{
  //For each observer
  for(obsIt it = _obsList.begin(); it != _obsList.end(); it++)
  {
    //Update the observer
    (*it)->update();
  }
}