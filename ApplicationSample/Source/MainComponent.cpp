/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
	addAndMakeVisible(toolbar);
	addAndMakeVisible(statusBar);
	toolbar.addDefaultItems(factory);
	for (int i = 0; i < factory.getButtonCount(); ++i)
	{
		factory.getButton(i + 1)->addListener(this);
	}
    setSize (500, 400);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));
}

void MainContentComponent::buttonClicked(Button *button)
{
	AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Toolbar", "Button pressed", "OK");
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	toolbar.setBounds(getLocalBounds().removeFromTop(24));
	statusBar.setBounds(getLocalBounds().removeFromBottom(24));
}
