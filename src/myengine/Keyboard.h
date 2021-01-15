#include <vector>

#ifndef USE_SDL
#define KEY_A 'a'
#else
#define KEY_A 223
#endif

namespace myengine
{
	struct Keyboard
	{
		/**
		* return true if the specified key are being input
		*/
		bool getKey(int key);

	private:
		friend struct Core;

		std::vector<int> keys;
		std::vector<int> downKeys;
		std::vector<int> upKeys;
	};
}