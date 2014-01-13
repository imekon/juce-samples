/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SoundListModel.h"
#include "SoundPlayer.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent : public Component, public Button::Listener, public ChangeListener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;
	void buttonClicked(Button *button) override;
	void changeListenerCallback(ChangeBroadcaster *) override;

private:
	SampleItem *currentSample;
	SoundPlayer player;
	SoundListModel listModel;
	TableHeaderComponent *listHeader;
	TableListBox listView;
	TextButton addButton;
	TextButton removeButton;
	TextButton playButton;
	TextButton stopButton;
	ToggleButton loopingButton;

	void addSample();
	void removeSample();
	void playSample();
	void stopSample();

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
