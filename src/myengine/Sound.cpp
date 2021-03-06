#include "Sound.h"
#include "Exception.h"
#include "../contrib/common/stb_vorbis.h"

namespace myengine
{
	void Sound::onLoad(const std::string path)
	{
		alGenBuffers(1, &id);

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;
		loadOgg(path + ".ogg", bufferData, format, freq);
		bufferData.resize(bufferData.size() - bufferData.size() % 4);
		alBufferData(id, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);
	}

	void Sound::loadOgg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(fileName.c_str(), &channels, &sampleRate, &output);
		
		if (samples == -1)
		{
			throw Exception("Failed to open file `" + fileName + "'");
		}

		if (channels == 1)
		{
			format = AL_FORMAT_MONO16;
		}
		else
		{
			format = AL_FORMAT_STEREO16;
		}

		freq = sampleRate;

		buffer.resize(samples * 2);
		memcpy(&buffer.at(0), output, buffer.size());

		free(output);
	}
}