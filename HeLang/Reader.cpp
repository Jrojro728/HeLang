#include "Reader.h"

namespace HeLang {
	namespace Reader {
		using Token = ::HeLang::Type::Token;
		int FileReader::GetChar()
		{
			int NowChar = _FileReader.get();
			if (NowChar != '\n')
			{
				FileLocation.x += 1;
			}
			else
			{
				FileLocation.y += 1;
			}

			return NowChar;
		}

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

			//数字
			if (isdigit(LastChar) || LastChar == '0')
			{
				std::string NumStr;
				do
				{
					NumStr += LastChar;
					LastChar = GetChar();
				} while (isdigit(LastChar) || LastChar == '0');

				TempValue.NumValue = strtod(NumStr.c_str(), 0);
				return Token::token_number;
			}

			//注释
			if (LastChar == '#')
			{
				do
				{
					LastChar = GetChar();
				} while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

				if (LastChar != EOF)
					return GetToken();
			}

			if (LastChar == EOF)
				return Token::token_eof;

			int ThisChar = LastChar;
			LastChar = GetChar();
			return ThisChar;
		}
	}
}