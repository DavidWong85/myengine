#include "SoundSource.h"
#include "Sound.h"

namespace myengine
{
	void SoundSource::onInitialize(std::shared_ptr<Sound> sound)
	{
		alGenSources(1, &sid);
		//alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		//alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		float newVolume = 0.1f;
		alSourcef(sid, AL_GAIN, newVolume);
		alSourcei(sid, AL_BUFFER, sound->id);
		alSourcePlay(sid);
	}

	void SoundSource::onTick()
	{
		ALint state = 0;

		alGetSourcei(sid, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
			//destroy();
		}
	}

	void SoundSource::onDestroy()
	{
		alDeleteSources(1, &sid);
	}
}