#pragma once
#include <fstream>

#include "Type.h"

namespace HeLang {
	namespace Reader {
		class FileReader
		{
		public:
			//����
			::HeLang::Type::TokenValue TempValue;

			//��������
			FileReader() { throw "No FileName in"; };
			FileReader(std::string FileName) { _FileReader.open(FileName.c_str(), std::ios::in); FileReaderID += 1; };
			~FileReader() { _FileReader.close(); };

			//����
			int GetChar() { return _FileReader.get(); };
			int GetToken();
		private:
			std::ifstream _FileReader;
			static int FileReaderID;
		};
	}
}