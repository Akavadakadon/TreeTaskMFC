#include "pch.h"
#include "MyCTreeCtrl.h"

HTREEITEM MyCTreeCtrl::InsertItem(TNode newNode)
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
	HTREEITEM htreeId = CTreeCtrl::InsertItem(newNode.Caption(), parent);
	if (!newNode.Status())
		SetItemStateEx(htreeId, TVIS_EX_DISABLED);
	nodes[newNode.Id()] = { newNode, htreeId };
	this->Expand(parent, TVE_EXPAND);
	return htreeId;
}

TNode MyCTreeCtrl::GetSelectedItem()
{
	HTREEITEM nodeHTreeId = CTreeCtrl::GetSelectedItem();
	auto res = find_if(nodes.begin(), nodes.end(), [nodeHTreeId](std::pair<int, std::pair<TNode, HTREEITEM>> node) {
		auto [id, pair] = node;
		auto [tnode, htreeid] = pair;
		return htreeid == nodeHTreeId;
		});
	TNode resNode = ( * res).second.first;
	return resNode;
}
