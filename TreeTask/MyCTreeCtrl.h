#pragma once
#include "pch.h"
#include "TNode.h"

#include <afxwin.h>
#include <CommCtrl.h>

class MyCTreeCtrl : public CTreeCtrl
{
private:
	std::map<int, std::pair<TNode,HTREEITEM>> nodes;
public:
	using CTreeCtrl::InsertItem;
	HTREEITEM InsertItem(TNode newNode);
	using CTreeCtrl::GetSelectedItem;
	TNode GetSelectedItem();
};
