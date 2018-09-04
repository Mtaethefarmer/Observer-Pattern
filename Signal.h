/*************************************
Name: Devone Reynolds
Date: 15 AUG 18
Subject: Observer Pattern
**************************************/
#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"

class Signal
{
  private:
    //List of all subscribed observers
    std::vector<Observer *> _obsList;
    
  public:
    //Add an observer
    void connect(Observer *obs);
    
    //Delete an observer
    void disconnect(Observer *obs);
    
    //Inform all observers
    void emit_signal();
};

#endif