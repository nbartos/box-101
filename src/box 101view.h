// Box 101View.h : interface of the CBox101View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BOX101VIEW_H__492F996D_FE30_11D1_8203_0000B45835CE__INCLUDED_)
#define AFX_BOX101VIEW_H__492F996D_FE30_11D1_8203_0000B45835CE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CBox101View : public CScrollView
{
protected: // create from serialization only
	CBox101View();
	DECLARE_DYNCREATE(CBox101View)

// Attributes
public:
	CBox101Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBox101View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBox101View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBox101View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Box 101View.cpp
inline CBox101Doc* CBox101View::GetDocument()
   { return (CBox101Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOX101VIEW_H__492F996D_FE30_11D1_8203_0000B45835CE__INCLUDED_)
