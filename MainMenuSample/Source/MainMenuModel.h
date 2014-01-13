#ifndef _MAINMENUMODEL_H
#define _MAINMENUMODEL_H

#include "../JuceLibraryCode/JuceHeader.h"

namespace CommandIDs
{
	enum Commands
	{
		newProject = 0x200010,
		open = 0x200020,
		saveDocument = 0x200030,
		saveDocumentAs = 0x200040,

		about = 0x201000,
	};
}

class MainMenuModel : public MenuBarModel
{
public:
	MainMenuModel(ApplicationCommandManager *commandManager);
	StringArray getMenuBarNames() override;
	PopupMenu getMenuForIndex(int topLevelIndex, const String &name) override;
	void menuItemSelected(int id, int topLevelIndex) override;

private:
	ApplicationCommandManager *commandManager;
	void createMenu(PopupMenu &menu, const String &name);
	void createFileMenu(PopupMenu &menu);
	void createEditMenu(PopupMenu &menu);
	void createHelpMenu(PopupMenu &menu);

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainMenuModel)
};
#endif // _MAINMENUMODEL_H
