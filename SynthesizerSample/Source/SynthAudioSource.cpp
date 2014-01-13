#include "SynthAudioSource.h"

SynthAudioSource::SynthAudioSource(MidiKeyboardState &keyboardState) : state(keyboardState)
{
	for (int i = 0; i < 16; i++)
	{
		synth.addVoice(new SamplerVoice());
	}
}

void SynthAudioSource::prepareToPlay(int samples, double rate)
{
	collector.reset(rate);
	synth.setCurrentPlaybackSampleRate(rate);
}

void SynthAudioSource::releaseResources()
{

}

void SynthAudioSource::getNextAudioBlock(const AudioSourceChannelInfo &buffer)
{
	buffer.clearActiveBufferRegion();
	MidiBuffer incoming;
	collector.removeNextBlockOfMessages(incoming, buffer.numSamples);
	state.processNextMidiBuffer(incoming, 0, buffer.numSamples, true);
	synth.renderNextBlock(*buffer.buffer, incoming, 0, buffer.numSamples);
}

void SynthAudioSource::setInputStream(const String &name, InputStream *stream)
{
	WavAudioFormat format;
	ScopedPointer<AudioFormatReader> reader = format.createReaderFor(stream, true);
	BigInteger allNotes;
	allNotes.setRange(0, 128, true);
	synth.clearSounds();
	synth.addSound(new SamplerSound(name, *reader, allNotes, 60, 0.1, 0.1, 10.0));
}
