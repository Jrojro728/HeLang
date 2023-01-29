#include "Reader.h"

namespace HeLang::Reader {
	using Token = ::HeLang::Type::Token;
	int FileReader::GetToken()
	{
		static int LastChar = ' ';

		//跳过空格
		while (isspace(LastChar))
			LastChar = GetChar();

		//关键字或辨识符
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