TVINSERTSTRUCT tvInsert;
tvInsert.hParent = NULL;
tvInsert.hInsertAfter = NULL;
tvInsert.item.mask = TVIF_TEXT;
tvInsert.item.pszText = _T("United States");

HTREEITEM hCountry = m_TreeCtrl.InsertItem(&tvInsert);

HTREEITEM hPA = m_TreeCtrl.InsertItem(TVIF_TEXT,
	_T("Pennsylvania"), 0, 0, 0, 0, 0, hCountry, NULL);


HTREEITEM hWA = m_TreeCtrl.InsertItem(_T("Washington"),
	0, 0, hCountry, hPA);

m_TreeCtrl.InsertItem(_T("Pittsburgh"), hPA, TVI_SORT);
m_TreeCtrl.InsertItem(_T("Harrisburg"), hPA, TVI_SORT);
m_TreeCtrl.InsertItem(_T("Altoona"), hPA, TVI_SORT);

m_TreeCtrl.InsertItem(_T("Seattle"), hWA, TVI_SORT);
m_TreeCtrl.InsertItem(_T("Kalaloch"), hWA, TVI_SORT);
m_TreeCtrl.InsertItem(_T("Yakima"), hWA, TVI_SORT);
