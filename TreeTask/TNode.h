#pragma once
#include "pch.h"

class TNode
{
public:
	TNode();
	TNode(int id, int pid, CString caption, int status, CString message);
	//HTREEITEM HTreeId() const;
	int Id() const;
	int Pid() const;
	int Status() const;
	CString Caption() const;
	CString Message() const;
	bool FromLine(CString nodeCStr = _T(" 0: -1:CAP0:1:MESSAGE-0"));
	/*operator HTREEITEM() const
	{
		return Id();
	}*/
	//static std::optional<TNode> FromLine(CString nodeCStr = _T(" 0: -1:CAP0:1:MESSAGE-0"));
private:
	//HTREEITEM hTreeId;
	int id;
	int pid;
	CString caption;
	int status;
	CString message;
};

std::istream& operator>> (std::istream& in, TNode& newNode);
