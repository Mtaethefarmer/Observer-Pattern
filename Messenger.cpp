/*************************************
Name: Devone Reynolds
Date: 15 AUG 18
Subject: Observer Pattern
**************************************/
#include "Messenger.h"
#include <iostream>

Messenger::Messenger(Marker& mark):
_marker(mark)
{}

void Messenger::update()
{
    std::cout << "Marker has changed to " << _marker.getColor() <<"."<< std::endl;
}