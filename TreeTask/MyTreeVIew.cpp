#include "pch.h"
#include "MyTreeVIew.h"

MyTreeVIew::MyTreeVIew()
{
	treeControl = &this->GetTreeCtrl();
}


HTREEITEM MyTreeVIew::InsertItem(TNode newNode)
{
	bool checkIfIdExists, checkIfParentExists;
	HTREEITEM parent = TVI_ROOT;
	checkIfIdExists = nodes.find(newNode.Id()) != nodes.end();
	if (checkIfIdExists)
		return false;
	if (newNode.Pid() == -1)
		checkIfParentExists = true;
	else
	{
		checkIfParentExists = nodes.find(newNode.Pid()) != nodes.end();
		if (!checkIfParentExists)
			return false;
		parent = nodes[newNode.Pid()].second;
	}
	HTREEITEM htreeId = treeControl->InsertItem(newNode.Caption(), parent);
	if (!newNode.Status())
		treeControl->SetItemStateEx(htreeId, TVIS_EX_DISABLED);
	nodes[newNode.Id()] = { newNode, htreeId };
	treeControl->Expand(parent, TVE_EXPAND);
	return htreeId;
}

TNode MyTreeVIew::GetSelectedItem()
{
	HTREEITEM nodeHTreeId = treeControl->GetSelectedItem();
	auto res = find_if(nodes.begin(), nodes.end(), [nodeHTreeId](std::pair<int, std::pair<TNode, HTREEITEM>> node) {
		auto [id, pair] = node;
		auto [tnode, htreeid] = pair;
		return htreeid == nodeHTreeId;
		});
	TNode resNode = (*res).second.first;
	return resNode;
}

