#pragma once
#include <fstream>

#include "Type.h"

namespace HeLang {
	namespace Reader {
		class FileReader
		{
		public:
			//变量
			::HeLang::Type::TokenValue TempValue;

			//构析函数
			FileReader() { throw "No FileName in"; };
			FileReader(std::string FileName) { _FileReader.open(FileName.c_str(), std::ios::in); FileReaderID += 1; };
			~FileReader() { _FileReader.close(); };

			//函数
			int GetChar() { return _FileReader.get(); };
			int GetToken();
		private:
			std::ifstream _FileReader;
			static int FileReaderID;
		};
	}
}