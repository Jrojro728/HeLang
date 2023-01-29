#pragma once

namespace HeLang {
	namespace Location {
		struct Location
		{
			int x = 0;
			int y = 0;
		};

		struct LocationRange
		{
			Location Start{ 0, 0 };
			Location End{ 0, 0 };
		};
	}
}