/*************************************
Name: Devone Reynolds
Date: 3 SEP 18
Subject: Observer Pattern

An example of the Observer Pattern

UML Diagram:
https://upload.wikimedia.org/wikipedia/commons/thumb/a/a8/Observer_w_update.svg/854px-Observer_w_update.svg.png
**************************************/

#include "Marker.h"
#include "Messenger.h"

int main()
{
    // Create a white dry erase marker
    Marker DryErase(Color::WHITE);

    // Create a message that prints out the new state of the marker when it
    // changes
    Messenger message(DryErase);

    // Connect the message
    // The message will subscribe to this marker
    DryErase.connect(&message);

    // Broadcast state change manually
    DryErase.emit_signal();

    // Change to a more effective color
    // The message will print out the change to the console
    DryErase.setColor(Color::BLACK);
    DryErase.setColor(Color::BLUE);

    // Unsubscribe the message
    DryErase.disconnect(&message);

    // Change to a better color
    // Since the message does not know it cannot print anything to the console,
    // but the dry erase still changes color
    DryErase.setColor(Color::RED);
    DryErase.setColor(Color::YELLOW);

    return 0;
}