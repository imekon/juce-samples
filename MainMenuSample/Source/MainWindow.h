#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include "../JuceLibraryCode/JuceHeader.h"

class MainMenuModel;

//==============================================================================
/*
This class implements the desktop window that contains an instance of
our MainContentComponent class.
*/
class MainWindow : public DocumentWindow, public ApplicationCommandTarget
{
public:
	MainWindow(ApplicationCommandManager *commandManager, MainMenuModel *menuModel);

	void closeButtonPressed() override;

	void getAllCommands(Array<CommandID> &commands) override;
	void getCommandInfo(CommandID id, ApplicationCommandInfo &info) override;
	bool perform(const InvocationInfo &info) override;
	ApplicationCommandTarget* getNextCommandTarget() override;

	/* Note: Be careful if you override any DocumentWindow methods - the base
	class uses a lot of them, so by overriding you might break its functionality.
	It's best to do all your work in your content component instead, but if
	you really have to override any DocumentWindow methods, make sure your
	subclass also calls the superclass's method.
	*/

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
};

#endif // _MAINWINDOW_H
