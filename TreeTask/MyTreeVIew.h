#pragma once
#include "pch.h"
#include "TNode.h"

#include <afxwin.h>
#include <CommCtrl.h>


class MyTreeVIew : public CTreeView
{
private:
	std::map<int, std::pair<TNode, HTREEITEM>> nodes;
	CTreeCtrl* treeControl;
public:
	MyTreeVIew();
	HTREEITEM InsertItem(TNode newNode);
	TNode GetSelectedItem();
};