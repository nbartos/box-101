// Box 101Doc.h : interface of the CBox101Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOX101DOC_H__492F996B_FE30_11D1_8203_0000B45835CE__INCLUDED_)
#define AFX_BOX101DOC_H__492F996B_FE30_11D1_8203_0000B45835CE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CBox101Doc : public CDocument
{
protected: // create from serialization only
	CBox101Doc();
	DECLARE_DYNCREATE(CBox101Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBox101Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBox101Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBox101Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOX101DOC_H__492F996B_FE30_11D1_8203_0000B45835CE__INCLUDED_)
