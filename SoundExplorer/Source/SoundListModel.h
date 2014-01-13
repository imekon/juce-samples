#ifndef _SOUNDLISTMODEL_H
#define _SOUNDLISTMODEL_H

#include "../JuceLibraryCode/JuceHeader.h"
#include "SampleItem.h"

class SoundListModel : public TableListBoxModel
{
public:
	SoundListModel();
	virtual ~SoundListModel();

	enum ColumnIDs
	{
		stateColumn = 1,
		nameColumn,
		formatColumn,
		sizeColumn,
		sampleRateColumn,
		bitsColumn
	};

	void addSample(const String &filename);

	int getNumRows() override;
	void paintRowBackground(Graphics &g, int rowNumber, int width, int height, bool rowIsSelected) override;
	void paintCell(Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;

	SampleItem *getSample(int index) const;

private:
	Array<SampleItem *> samples;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SoundListModel)
};
#endif // _SOUNDLISTMODEL_H
