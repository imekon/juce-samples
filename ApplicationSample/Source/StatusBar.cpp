/*
  ==============================================================================

    StatusBar.cpp
    Created: 8 Jan 2014 8:29:03pm
    Author:  goodwin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "StatusBar.h"

//==============================================================================
StatusBar::StatusBar()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

StatusBar::~StatusBar()
{
}

void StatusBar::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

	g.fillAll(Colours::grey);   // clear the background
}

void StatusBar::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
