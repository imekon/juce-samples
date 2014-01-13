#ifndef _SYNTHAUDIOSOURCE_H
#define _SYNTHAUDIOSOURCE_H

#include "../JuceLibraryCode/JuceHeader.h"

class SynthAudioSource : public AudioSource
{
public:
	SynthAudioSource(MidiKeyboardState &state);

	void prepareToPlay(int samples, double rate) override;
	void releaseResources() override;
	void getNextAudioBlock(const AudioSourceChannelInfo &buffer) override;
	void setInputStream(const String &name, InputStream *stream);

	MidiMessageCollector *getMidiMessageCollector() { return &collector; }

private:
	MidiMessageCollector collector;
	MidiKeyboardState &state;
	Synthesiser synth;
};
#endif // _SYNTHAUDIOSOURCE_H
