// Box 101Doc.cpp : implementation of the CBox101Doc class
//

#include "stdafx.h"
#include "Box 101.h"

#include "Box 101Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBox101Doc

IMPLEMENT_DYNCREATE(CBox101Doc, CDocument)

BEGIN_MESSAGE_MAP(CBox101Doc, CDocument)
	//{{AFX_MSG_MAP(CBox101Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBox101Doc construction/destruction

CBox101Doc::CBox101Doc()
{
	// TODO: add one-time construction code here

}

CBox101Doc::~CBox101Doc()
{
}

BOOL CBox101Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	SetTitle ("");
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBox101Doc serialization

void CBox101Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBox101Doc diagnostics

#ifdef _DEBUG
void CBox101Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBox101Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBox101Doc commands
