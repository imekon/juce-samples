#include "MainComponent.h"
#include "MainMenuModel.h"
#include "MainWindow.h"

MainWindow::MainWindow(ApplicationCommandManager *commandManager, MainMenuModel *menuModel) : DocumentWindow("Application Sample",
	Colours::lightgrey,
	DocumentWindow::allButtons)
{
#if ! JUCE_MAC
	setMenuBar(menuModel);
#endif

	commandManager->registerAllCommandsForTarget(this);

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

void MainWindow::getAllCommands(Array<CommandID> &commands)
{
	const CommandID ids[] =
	{
		CommandIDs::newProject,
		CommandIDs::open,
		CommandIDs::saveDocument,
		CommandIDs::saveDocumentAs,
		StandardApplicationCommandIDs::cut,
		StandardApplicationCommandIDs::copy,
		StandardApplicationCommandIDs::paste,
		CommandIDs::about
#if ! JUCE_MAC
		,
		StandardApplicationCommandIDs::quit
#endif
	};

	commands.addArray(ids, numElementsInArray(ids));
}

void MainWindow::getCommandInfo(CommandID id, ApplicationCommandInfo &info)
{
	switch (id)
	{
	case CommandIDs::newProject:
		info.setInfo("New", "Creates a new project", "file", 0);
		info.defaultKeypresses.add(KeyPress('n', ModifierKeys::commandModifier, 0));
		break;

	case CommandIDs::open:
		info.setInfo("Open...", "Open an existing project", "file", 0);
		info.defaultKeypresses.add(KeyPress('o', ModifierKeys::commandModifier, 0));
		break;

	case CommandIDs::saveDocument:
		info.setInfo("Save", "Save project", "file", 0);
		info.defaultKeypresses.add(KeyPress('s', ModifierKeys::commandModifier, 0));
		break;

	case CommandIDs::saveDocumentAs:
		info.setInfo("Save As...", "Save project as", "file", 0);
		break;

	case StandardApplicationCommandIDs::cut:
		info.setInfo("Cut", "Cut", "edit", 0);
		info.defaultKeypresses.add(KeyPress('x', ModifierKeys::commandModifier, 0));
		break;

	case StandardApplicationCommandIDs::copy:
		info.setInfo("Copy", "Copy", "edit", 0);
		info.defaultKeypresses.add(KeyPress('c', ModifierKeys::commandModifier, 0));
		break;

	case StandardApplicationCommandIDs::paste:
		info.setInfo("Paste", "Paste", "edit", 0);
		info.defaultKeypresses.add(KeyPress('v', ModifierKeys::commandModifier, 0));
		break;

	case CommandIDs::about:
		info.setInfo("About...", "Help about", "help", 0);
		break;

	case StandardApplicationCommandIDs::quit:
		info.setInfo("Quit", "Exit application", "file", 0);
		info.defaultKeypresses.add(KeyPress('x', ModifierKeys::altModifier, 0));
		break;

	default:
		break;
	}
}

bool MainWindow::perform(const InvocationInfo &info)
{
	switch (info.commandID)
	{
	case CommandIDs::newProject:
		AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Main Menu Sample", "You selected New", "OK");
		break;

	case CommandIDs::open:
		AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Main Menu Sample", "You selected Open", "OK");
		break;

	case CommandIDs::saveDocumentAs:
		AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Main Menu Sample", "You selected Save As", "OK");
		break;

	case CommandIDs::saveDocument:
		AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Main Menu Sample", "You selected Save", "OK");
		break;

	case StandardApplicationCommandIDs::cut:
		AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Main Menu Sample", "You selected Cut", "OK");
		break;

	case StandardApplicationCommandIDs::copy:
		AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Main Menu Sample", "You selected Copy", "OK");
		break;

	case StandardApplicationCommandIDs::paste:
		AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Main Menu Sample", "You selected Paste", "OK");
		break;

	case CommandIDs::about:
		AlertWindow::showMessageBox(AlertWindow::InfoIcon, "Main Menu Sample", "This is a sample showing a main menu", "OK");
		break;

	case StandardApplicationCommandIDs::quit:
		if (AlertWindow::showOkCancelBox(AlertWindow::QuestionIcon, "Main Menu Sample", "Are you sure you want to quit?", "OK", "Cancel"))
		{
			JUCEApplication::getInstance()->systemRequestedQuit();
		}
		break;

	default:
		break;
	}
	return true;
}

ApplicationCommandTarget *MainWindow::getNextCommandTarget()
{
	return nullptr;
}
