#pragma once


#include "pch.h"
#include "TNode.h"
using namespace std;

class TFileReader
{
public:
	static optional<vector<TNode>> ReadNodesFromFile(CString path)
	{
		std::ifstream fStream;
		bool res = FileExists(fStream, path);
		if (!res)
			return nullopt;
		std::vector<TNode> nodes;
		std::string str;
		while (fStream)
		{
			getline(fStream, str);
			CString cStr(str.c_str());
			TNode node;
			if (node.FromLine(cStr))
				nodes.push_back(node);
		}
		return nodes;
	}

private:
	static bool FileExists(std::ifstream& fStream,const CString& path) {
		fStream.open(path.GetString());
		return fStream.good();
	}

};

