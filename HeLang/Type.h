#pragma once
#include <string>

namespace HeLang {
	namespace Type {
		enum Token
		{
			//End of file(eof)
			token_eof = -1,

			//�ؼ���
			token_def = -2,
			token_extern = -3,

			//��Ҫ(��ʶ��)
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