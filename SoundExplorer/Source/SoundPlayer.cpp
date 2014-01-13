#include "SoundPlayer.h"

SoundPlayer::SoundPlayer() : thread("audio file player")
{
	thread.startThread(3);
	audioDeviceManager.initialise(0, 2, nullptr, true);
	audioFormatManager.registerBasicFormats();
	audioDeviceManager.addAudioCallback(&audioSourcePlayer);
	audioSourcePlayer.setSource(&audioTransportSource);
}

SoundPlayer::~SoundPlayer()
{
	stop();

	audioTransportSource.setSource(nullptr);
	audioSourcePlayer.setSource(nullptr);
	audioDeviceManager.removeAudioCallback(&audioSourcePlayer);
}

bool SoundPlayer::loadFile(const String &filename)
{
	File file(filename);
	if (!file.exists())
	{
		return false;
	}

	AudioFormatReader *reader = audioFormatManager.createReaderFor(file);
	if (reader == nullptr)
	{
		return false;
	}

	audioTransportSource.stop();
	audioTransportSource.setSource(nullptr);
	currentAudioFile = new AudioFormatReaderSource(reader, true);
	audioTransportSource.setSource(currentAudioFile, 32768, &thread, reader->sampleRate);

	return true;
}

void SoundPlayer::play(bool looping)
{
	if (!audioTransportSource.isPlaying())
	{
		audioTransportSource.setPosition(0);
		audioTransportSource.start();
		audioTransportSource.setLooping(looping);
	}
}

void SoundPlayer::stop()
{
	if (audioTransportSource.isPlaying())
	{
		audioTransportSource.stop();
	}
}

bool SoundPlayer::isPlaying() const
{
	return audioTransportSource.isPlaying();
}

void SoundPlayer::addChangeListener(ChangeListener *listener)
{
	audioTransportSource.addChangeListener(listener);
}

void SoundPlayer::removeChangeListener(ChangeListener *listener)
{
	audioTransportSource.removeChangeListener(listener);
}

