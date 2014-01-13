#ifndef _SAMPLEITEM_H
#define _SAMPLEITEM_H

#include "../JuceLibraryCode/JuceHeader.h"

class SampleItem
{
public:
	SampleItem(const String &filename);

	const String &getFilename() const { return filename; }
	const String &getShortname() const { return shortname; }
	const String &getFormatName() const { return formatName; }
	const int getSize() const { return size; }
	const int getSampleRate() const { return sampleRate; }
	const int getBits() const { return bits; }

	const bool isPlaying() const { return playing; }
	inline void setPlaying(bool play) { playing = play; }

private:
	bool playing;
	String filename;
	String shortname;
	String formatName;
	int size;
	int sampleRate;
	int bits;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SampleItem)
};

#endif // _SAMPLEITEM_H
