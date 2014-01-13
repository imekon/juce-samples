#include "MainComponent.h"
#include "MainWindow.h"

MainWindow::MainWindow() : DocumentWindow("Synthesizer Demo",
	Colours::lightgrey,
	DocumentWindow::allButtons)
{
	setContentOwned(new MainContentComponent(), true);
	setResizable(true, true);
	centreWithSize(getWidth(), getHeight());
	setVisible(true);
}

void MainWindow::closeButtonPressed()
{
	// This is called when the user tries to close this window. Here, we'll just
	// ask the app to quit when this happens, but you can change this to do
	// whatever you need.
	JUCEApplication::getInstance()->systemRequestedQuit();
}
