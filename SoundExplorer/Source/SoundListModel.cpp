#include "SoundListModel.h"

SoundListModel::SoundListModel()
{
}

SoundListModel::~SoundListModel()
{
	for (int i = 0; i < samples.size(); ++i)
	{
		delete samples[i];
	}
}

void SoundListModel::addSample(const String &filename)
{
	SampleItem *item = new SampleItem(filename);
	samples.add(item);
}

int SoundListModel::getNumRows()
{
	return samples.size();
}

SampleItem *SoundListModel::getSample(int index) const
{
	return samples[index];
}

void SoundListModel::paintRowBackground(Graphics &g, int, int width, int height, bool rowIsSelected)
{
	if (rowIsSelected)
	{
		g.setColour(Colours::aliceblue);
		g.fillRect(0, 0, width, height);
	}
}

void SoundListModel::paintCell(Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
	SampleItem *item = samples[rowNumber];

	if (columnId != stateColumn)
	{
		String text;
		Justification justification = Justification::left;

		switch (columnId)
		{
		case nameColumn:
			text = item->getShortname();
			break;

		case formatColumn:
			text = item->getFormatName();
			break;

		case sampleRateColumn:
			text = String(item->getSampleRate());
			justification = Justification::right;
			break;

		case sizeColumn:
			text = String(item->getSize());
			justification = Justification::right;
			break;

		case bitsColumn:
			text = String(item->getBits());
			justification = Justification::right;
			break;
		}

		if (rowIsSelected)
		{
			g.setColour(Colours::aliceblue);
			g.fillRect(0, 0, width, height);
		}
		g.setColour(Colours::black);
		g.drawText(text, 0, 0, width, height, justification, true);
	}
	else
	{
		g.setColour(Colours::blue);
		if (item->isPlaying())
		{
			Path path;
			path.startNewSubPath(5.0f, 5.0f);
			path.lineTo(15.0f, 10.0f);
			path.lineTo(5.0f, 15.0f);
			path.lineTo(5.0f, 5.0f);
			g.fillPath(path);
		}
	}
}
