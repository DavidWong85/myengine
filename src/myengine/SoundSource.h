#include "Component.h"

#include <AL/al.h>
#include <memory>

namespace myengine
{
	struct Sound;
	struct SoundSource : public Component
	{
		void onInitialize(std::shared_ptr<Sound> sound);
		void onTick();
		void onDestroy();
	private:
		ALuint sid;
	};
}