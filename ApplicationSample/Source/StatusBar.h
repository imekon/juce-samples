/*
  ==============================================================================

    StatusBar.h
    Created: 8 Jan 2014 8:29:03pm
    Author:  goodwin

  ==============================================================================
*/

#ifndef STATUSBAR_H_INCLUDED
#define STATUSBAR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class StatusBar : public Component
{
public:
    StatusBar();
    virtual ~StatusBar();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StatusBar)
};


#endif  // STATUSBAR_H_INCLUDED
