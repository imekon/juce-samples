#ifndef _SOUNDPLAYER_H
#define _SOUNDPLAYER_H

#include "../JuceLibraryCode/JuceHeader.h"

class SoundPlayer
{
public:
	SoundPlayer();
	virtual ~SoundPlayer();

	bool loadFile(const String &filename);
	void play(bool looping);
	void stop();
	bool isPlaying() const;

	void addChangeListener(ChangeListener *listener);
	void removeChangeListener(ChangeListener *listener);

private:
	AudioDeviceManager audioDeviceManager;
	AudioFormatManager audioFormatManager;
	AudioSourcePlayer audioSourcePlayer;
	AudioTransportSource audioTransportSource;
	ScopedPointer<AudioFormatReaderSource> currentAudioFile;
	TimeSliceThread thread;
};
#endif // _SOUNDPLAYER_H
