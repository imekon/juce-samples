#ifndef _APPTOOLBARITEMFACTORY_H
#define _APPTOOLBARITEMFACTORY_H

#include "../JuceLibraryCode/JuceHeader.h"

class AppToolbarItemFactory : public ToolbarItemFactory
{
public:
	AppToolbarItemFactory();

	enum AppToolbarItemIds
	{
		fileNew = 1,
		fileOpen,
		fileSave,
		editCut,
		editCopy,
		editPaste,
		helpAbout
	};

	void getAllToolbarItemIds(Array<int> &ids) override;
	void getDefaultItemSet(Array<int>& ids) override;
	ToolbarItemComponent *createItem(int id) override;

	ToolbarButton *getButton(int id) const { return buttons[id - 1]; }
	const int getButtonCount() const { return 7; }

private:
	ToolbarButton *buttons[7];

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AppToolbarItemFactory)
};
#endif // _APPTOOLBARITEMFACTORY_H
