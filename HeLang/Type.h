#pragma once
#include <string>

namespace HeLang {
	namespace Type {
		enum Token
		{
			//End of file(eof)
			token_eof = -1,

			//关键字
			token_def = -2,
			token_extern = -3,

			//主要(辨识符)
			token_identifier = -4,
			token_number = -5
		};

		struct TokenValue
		{
			 std::string IdentifierString;
			 double NumValue;
		};
	}
}