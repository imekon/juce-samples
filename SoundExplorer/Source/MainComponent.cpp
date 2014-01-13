/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
	currentSample = nullptr;

	listHeader = new TableHeaderComponent();

	listHeader->addColumn(" ", SoundListModel::stateColumn, 30);
	listHeader->addColumn("Name", SoundListModel::nameColumn, 100);
	listHeader->addColumn("Format", SoundListModel::formatColumn, 70);
	listHeader->addColumn("Size", SoundListModel::sizeColumn, 70);
	listHeader->addColumn("Sample Rate", SoundListModel::sampleRateColumn, 100);
	listHeader->addColumn("Bits", SoundListModel::bitsColumn, 35);

	listView.setHeader(listHeader);
	listView.setModel(&listModel);

	addButton.setButtonText("Add...");
	removeButton.setButtonText("Remove");
	playButton.setButtonText("Play");
	stopButton.setButtonText("Stop");
	loopingButton.setButtonText("Looping");

	addAndMakeVisible(listView);

	addAndMakeVisible(addButton);
	addAndMakeVisible(removeButton);
	addAndMakeVisible(playButton);
	addAndMakeVisible(stopButton);
	addAndMakeVisible(loopingButton);

	addButton.addListener(this);
	removeButton.addListener(this);
	playButton.addListener(this);
	stopButton.addListener(this);
	loopingButton.addListener(this);

	player.addChangeListener(this);

    setSize (800, 600);
}

MainContentComponent::~MainContentComponent()
{
	addButton.removeListener(this);
	removeButton.removeListener(this);
	playButton.removeListener(this);
	stopButton.removeListener(this);
	loopingButton.removeListener(this);

	player.removeChangeListener(this);
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));
}

void MainContentComponent::buttonClicked(Button *button)
{
	if (button == &addButton)
	{
		addSample();
	}
	else if (button == &removeButton)
	{
		removeSample();
	}
	else if (button == &playButton)
	{
		playSample();
	}
	else if (button == &stopButton)
	{
		stopSample();
	}
}

void MainContentComponent::addSample()
{
	FileChooser chooser("Samples", File::getCurrentWorkingDirectory(), "*.wav", true);
	if (chooser.browseForFileToOpen())
	{
		listModel.addSample(chooser.getResult().getFullPathName());
		listView.updateContent();
	}
}

void MainContentComponent::removeSample()
{

}

void MainContentComponent::playSample()
{
	int row = listView.getSelectedRow(0);
	if (row == -1)
	{
		return;
	}
	if (currentSample != nullptr)
	{
		currentSample->setPlaying(false);
	}
	currentSample = listModel.getSample(row);
	player.loadFile(currentSample->getFilename());
	player.play(loopingButton.getToggleState());
	currentSample->setPlaying(true);
	listView.repaint();
}

void MainContentComponent::stopSample()
{
	player.stop();
}

void MainContentComponent::resized()
{
	listView.setBounds(10, 10, getWidth() - 20, getHeight() - 50);

	addButton.setBounds(10, getHeight() - 32, 70, 24);
	removeButton.setBounds(90, getHeight() - 32, 70, 24);
	playButton.setBounds(170, getHeight() - 32, 70, 24);
	stopButton.setBounds(250, getHeight() - 32, 70, 24);
	loopingButton.setBounds(330, getHeight() - 32, 70, 24);
}

void MainContentComponent::changeListenerCallback(ChangeBroadcaster *)
{
	if (currentSample != nullptr)
	{
		currentSample->setPlaying(player.isPlaying());
		listView.repaint();
	}
}