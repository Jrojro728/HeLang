#include "Reader.h"

namespace HeLang::Reader {
	using Token = ::HeLang::Type::Token;
	int FileReader::GetToken()
	{
		static int LastChar = ' ';

		//�����ո�
		while (isspace(LastChar))
			LastChar = GetChar();

		//�ؼ��ֻ��ʶ��
		if (isalpha(LastChar))
		{
			TempValue.IdentifierString = LastChar;
			while (isalnum((LastChar = GetChar())))
				TempValue.IdentifierString += LastChar;

			if (TempValue.IdentifierString == "def")
				return Token::token_def;
			if (TempValue.IdentifierString == "extern")
				return Token::token_extern;
			return Token::token_identifier;
		}
	}
}