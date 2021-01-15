#include "SoundSource.h"

#include "Sound.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>

namespace myengine
{
	void SoundSource::onInitialize(std::shared_ptr<Sound> sound)
	{
		alGenSources(1, &sid);
		position = getEntity()->getTransform()->getPosition();
		alSource3f(sid, AL_POSITION, position.x, position.y, position.z);
		float newVolume = 1.0f;
		alSourcef(sid, AL_GAIN, newVolume);
		alSourcei(sid, AL_LOOPING, AL_TRUE);
		alSourcei(sid, AL_BUFFER, sound->id);
		alSourcePlay(sid);
	}

	void SoundSource::onTick()
	{
		ALint state = 0;

		position = getEntity()->getTransform()->getPosition();

		alGetSourcei(sid, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
			destroy();
		}
	}

	void SoundSource::onDestroy()
	{
		alDeleteSources(1, &sid);
	}
}