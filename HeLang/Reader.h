#pragma once
#include <fstream>

#include "Type.h"
#include "Location.h"

namespace HeLang {
	namespace Reader {
		class FileReader
		{
		public:
			//����
			::HeLang::Type::TokenValue TempValue;
			::HeLang::Location::Location FileLocation;

			//��������
			FileReader() { throw "No FileName in"; };
			FileReader(std::string FileName) { _FileReader.open(FileName.c_str(), std::ios::in); FileReaderID += 1; };
			~FileReader() { _FileReader.close(); };

			//����
			int GetChar();
			int GetToken();
		private:
			std::ifstream _FileReader;
			static int FileReaderID;
		};
	}
}