#include "MainMenuModel.h"

MainMenuModel::MainMenuModel(ApplicationCommandManager *commandManager)
{
	setApplicationCommandManagerToWatch(commandManager);
	this->commandManager = commandManager;
}

StringArray MainMenuModel::getMenuBarNames()
{
	const char *names[] = { "File", "Edit", "Help", nullptr };
	return StringArray(names);
}

PopupMenu MainMenuModel::getMenuForIndex(int, const String &name)
{
	PopupMenu menu;
	createMenu(menu, name);
	return menu;
}

void MainMenuModel::menuItemSelected(int, int)
{

}

void MainMenuModel::createMenu(PopupMenu &menu, const String &name)
{
	if (name == "File")
	{
		createFileMenu(menu);
	}
	else if (name == "Edit")
	{
		createEditMenu(menu);
	}
	else if (name == "Help")
	{
		createHelpMenu(menu);
	}
	else
	{
		jassertfalse;
	}
}

void MainMenuModel::createFileMenu(PopupMenu &menu)
{
	menu.addCommandItem(commandManager, CommandIDs::newProject);
	menu.addCommandItem(commandManager, CommandIDs::open);
	menu.addSeparator();
	menu.addCommandItem(commandManager, CommandIDs::saveDocument);
	menu.addCommandItem(commandManager, CommandIDs::saveDocumentAs);
#if !JUCE_MAC
	menu.addSeparator();
	menu.addCommandItem(commandManager, StandardApplicationCommandIDs::quit);
#endif
}

void MainMenuModel::createEditMenu(PopupMenu &menu)
{
	menu.addCommandItem(commandManager, StandardApplicationCommandIDs::cut);
	menu.addCommandItem(commandManager, StandardApplicationCommandIDs::copy);
	menu.addCommandItem(commandManager, StandardApplicationCommandIDs::paste);
}

void MainMenuModel::createHelpMenu(PopupMenu &menu)
{
	menu.addCommandItem(commandManager, CommandIDs::about);
}

