#include "Resource.h"

#include <AL/al.h>

#include <vector>
#include <string>

namespace myengine
{
	struct SoundSource;
	struct Sound : public Resource
	{
		friend struct ::myengine::SoundSource;
		/**
		* load audio file
		*/
		void onLoad(const std::string path);
		/**
		* set buffer data
		*/
		void loadOgg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq);

	private:
		ALuint id;
	};
}