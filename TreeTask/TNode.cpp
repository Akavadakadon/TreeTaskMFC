#include "pch.h"
#include "TNode.h"

int TNode::Id() const
{
	return id;
}

int TNode::Pid() const
{
	return pid;
}

int TNode::Status() const
{
	return status;
}

CString TNode::Caption() const
{
	return caption;
}

CString TNode::Message() const
{
	return message;
}


TNode::TNode() :
	id(0), pid(-1), status(1), caption("asd"), message("123")
{

}

TNode::TNode(int id, int pid, CString caption, int status,  CString message):
	id(id), pid(pid), caption(caption), status(status),  message(message)
{

}

void RemoveSpaceOnFirstPos(CString& text)
{
	if (text[0] == (wchar_t)' ')
		text.Delete(0);
}

std::optional<int> GetInt(CString text)
{
	RemoveSpaceOnFirstPos(text);
	int i = 0;
	while (text[i])
	{
		if (iswalpha(text[i]))
			return std::nullopt;
		i++;
	}
	return _ttoi(text);
}

bool TNode::FromLine(CString nodeCStr)
{
	int nTokenPos = 0;
	std::vector<CString> tokens;
	std::vector<int> ints;
	LPCWSTR delimeter = _T(":");
	int id, pid, status;
	CString caption, message;

	CString strToken = nodeCStr.Tokenize(delimeter, nTokenPos);
	tokens.push_back(strToken);
	while (!strToken.IsEmpty())
	{
		strToken = nodeCStr.Tokenize(delimeter, nTokenPos);
		if (strToken!="")
		tokens.push_back(strToken);
	}
	if (tokens.size() != 5)
		return false;
	std::wstringstream  sstream;
	//id
	auto idO = GetInt(tokens[0]);
	if (idO)
		id = *idO;
	else
		return false;
	//pid
	idO = GetInt(tokens[1]);
	if (idO)
		pid = *idO;
	else
		return false;

	//caption
	if(tokens[2].IsEmpty())
		return false;

	//status
	idO = GetInt(tokens[3]);
	if (idO)
		status = *idO;
	else
		return false;

	//message
	if (tokens[4].IsEmpty())
		return false;
	*this = TNode(id, pid, tokens[2], status, tokens[4]);
	return true;
}

std::istream& operator>> (std::istream& in, TNode& newNode)
{
	//int id, pid, status;
	//CString caption, message;
	//std::string str;
	//getline(in, str);
	//if (in >> id >> pid)
	//	if (in >> caption)
	//		if (in >> status)
	//			if (in >> message)
	//				newNode = TNode(numerator, denominator);
	return in;
}

