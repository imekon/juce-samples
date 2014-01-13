#include "SampleItem.h"

SampleItem::SampleItem(const String &filename)
{
	this->filename = filename;

	File file(filename);
	if (file.exists())
	{
		shortname = file.getFileNameWithoutExtension();
		FileInputStream *stream = new FileInputStream(file);
		WavAudioFormat format;
		AudioFormatReader *reader = format.createReaderFor(stream, false);
		if (reader)
		{
			formatName = reader->getFormatName();
			sampleRate = (int)reader->sampleRate;
			size = (int)reader->lengthInSamples;
			bits = reader->bitsPerSample;
			delete reader;
		}
		else
		{
			sampleRate = 0;
			size = 0;
			bits = 0;
		}
	}

	playing = false;
}


