#if !defined(AFX_HELO_H__F7CE7CB2_9607_44FF_93D8_C88C03329A91__INCLUDED_)
#define AFX_HELO_H__F7CE7CB2_9607_44FF_93D8_C88C03329A91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// helo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// helo recordset

class helo : public CRecordset
{
public:
	helo(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(helo)

// Field/Param Data
	//{{AFX_FIELD(helo, CRecordset)
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(helo)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HELO_H__F7CE7CB2_9607_44FF_93D8_C88C03329A91__INCLUDED_)
