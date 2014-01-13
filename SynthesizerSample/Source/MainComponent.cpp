/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent() 
	: synthAudioSource(state), 
	  keyboard(state, MidiKeyboardComponent::horizontalKeyboard)
{
	synthAudioSource.setInputStream("PlasticZ Power Bass", new MemoryInputStream(BinaryData::BA_Power_wav, BinaryData::BA_Power_wavSize, false));

	audioDeviceManager.initialise(0, 2, nullptr, true);
	audioSourcePlayer.setSource(&synthAudioSource);
	audioDeviceManager.addAudioCallback(&audioSourcePlayer);
	audioDeviceManager.addMidiInputCallback(String::empty, synthAudioSource.getMidiMessageCollector());
	addAndMakeVisible(keyboard);
    setSize (800, 600);
}

MainContentComponent::~MainContentComponent()
{
	audioSourcePlayer.setSource(nullptr);
	audioDeviceManager.removeMidiInputCallback(String::empty, synthAudioSource.getMidiMessageCollector());
	audioDeviceManager.removeAudioCallback(&audioSourcePlayer);
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));
}

void MainContentComponent::resized()
{
	keyboard.setBounds(0, getHeight() - 64, getWidth(), 64);
}
