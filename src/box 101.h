// Box 101.h : main header file for the BOX 101 application
//

#if !defined(AFX_BOX101_H__492F9965_FE30_11D1_8203_0000B45835CE__INCLUDED_)
#define AFX_BOX101_H__492F9965_FE30_11D1_8203_0000B45835CE__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBox101App:
// See Box 101.cpp for the implementation of this class
//

class CBox101App : public CWinApp
{
public:
	CBox101App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBox101App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBox101App)
	afx_msg void OnAppAbout();
	afx_msg void OnBox1Bandpass();
	afx_msg void OnBox1Ported();
	afx_msg void OnBox1Sealed();
	afx_msg void OnBox2Bandpass();
	afx_msg void OnBox2Ported();
	afx_msg void OnBox2Sealed();
	afx_msg void OnUpdateBox1Bandpass(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBox1Ported(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBox1Sealed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBox2Bandpass(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBox2Ported(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBox2Sealed(CCmdUI* pCmdUI);
	afx_msg void OnDriver1New();
	afx_msg void OnDriver2New();
	afx_msg void OnDriver1Open();
	afx_msg void OnDriver1Save();
	afx_msg void OnDriver2Open();
	afx_msg void OnDriver2Save();
	afx_msg void OnGraphRelativeresponse();
	afx_msg void OnGraphComparativeresponse();
	afx_msg void OnGraphMaximumspl();
	afx_msg void OnGraphPortvelocity();
	afx_msg void OnGraphPower();
	afx_msg void OnUpdateGraphRelativeresponse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGraphComparativeresponse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGraphMaximumspl(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGraphPortvelocity(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGraphPower(CCmdUI* pCmdUI);
	afx_msg void OnDriver2Clear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// COpendriver1 dialog

class COpendriver1 : public CFileDialog
{
	DECLARE_DYNAMIC(COpendriver1)

public:
	COpendriver1(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);

protected:
	//{{AFX_MSG(COpendriver1)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CBandpass1Dlg dialog

class CBandpass1Dlg : public CDialog
{
// Construction
public:
	CBandpass1Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBandpass1Dlg)
	enum { IDD = IDD_BANDPASS1 };
	float	dv;
	float	fb;
	int		nd;
	int		nv;
	int		pm;
	float	vf;
	float	vr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBandpass1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBandpass1Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// CBandpass2Dlg dialog

class CBandpass2Dlg : public CDialog
{
// Construction
public:
	CBandpass2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBandpass2Dlg)
	enum { IDD = IDD_BANDPASS2 };
	float	dv;
	float	fb;
	int		nd;
	int		nv;
	int		pm;
	float	vf;
	float	vr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBandpass2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBandpass2Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// CSealed1Dlg dialog

class CSealed1Dlg : public CDialog
{
// Construction
public:
	CSealed1Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSealed1Dlg)
	enum { IDD = IDD_SEALED1 };
	int		nd;
	int		pm;
	float	vb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSealed1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSealed1Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// CSealed2Dlg dialog

class CSealed2Dlg : public CDialog
{
// Construction
public:
	CSealed2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSealed2Dlg)
	enum { IDD = IDD_SEALED2 };
	int		nd;
	int		pm;
	float	vb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSealed2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSealed2Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// CPorted1Dlg dialog

class CPorted1Dlg : public CDialog
{
// Construction
public:
	CPorted1Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPorted1Dlg)
	enum { IDD = IDD_PORTED1 };
	float	dv;
	float	fb;
	int		nd;
	int		nv;
	int		pm;
	float	vb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPorted1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPorted1Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// CPorted2Dlg dialog

class CPorted2Dlg : public CDialog
{
// Construction
public:
	CPorted2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPorted2Dlg)
	enum { IDD = IDD_PORTED2 };
	float	fb;
	int		nd;
	int		nv;
	int		pm;
	float	vb;
	float	dv;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPorted2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPorted2Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// CNewDriver1Dlg dialog

class CNewDriver1Dlg : public CDialog
{
// Construction
public:
	CNewDriver1Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewDriver1Dlg)
	enum { IDD = IDD_NEWDRIVER1 };
	int		diam1;
	float	fs1;
	CString	name1;
	int		pe1;
	float	qes1;
	float	qms1;
	float	qts1;
	float	vas1;
	float	xmax1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewDriver1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewDriver1Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/////////////////////////////////////////////////////////////////////////////
// CNewDriver2Dlg dialog

class CNewDriver2Dlg : public CDialog
{
// Construction
public:
	CNewDriver2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewDriver2Dlg)
	enum { IDD = IDD_NEWDRIVER2 };
	int		diam1;
	float	fs1;
	CString	name1;
	int		pe1;
	float	qes1;
	float	qms1;
	float	qts1;
	float	vas1;
	float	xmax1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewDriver2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewDriver2Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOX101_H__492F9965_FE30_11D1_8203_0000B45835CE__INCLUDED_)
