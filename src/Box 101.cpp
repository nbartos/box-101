// Box 101.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Box 101.h"

#include "MainFrm.h"
#include "Box 101Doc.h"
#include "Box 101View.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//Global Variables
int graph = 1;
CString name[2];
float fs[2], qes[2], qms[2], qts[2], vas[2], xmax[2], ref[2];
int diam[2], pe[2];
float s_vb[2], s_qtc[2];
int s_pm[2], s_nd[2], box[2];
float p_vb[2], p_fb[2], p_dv[2], p_lv[2];
int p_nv[2], p_pm[2], p_nd[2];
float b_vr[2], b_vf[2], b_fb[2], b_dv[2], b_lv[2], b_qtc[2];
int b_nv[2], b_pm[2], b_nd[2];

/////////////////////////////////////////////////////////////////////////////
// CBox101App

BEGIN_MESSAGE_MAP(CBox101App, CWinApp)
	//{{AFX_MSG_MAP(CBox101App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_BOX1_BANDPASS, OnBox1Bandpass)
	ON_COMMAND(ID_BOX1_PORTED, OnBox1Ported)
	ON_COMMAND(ID_BOX1_SEALED, OnBox1Sealed)
	ON_COMMAND(ID_BOX2_BANDPASS, OnBox2Bandpass)
	ON_COMMAND(ID_BOX2_PORTED, OnBox2Ported)
	ON_COMMAND(ID_BOX2_SEALED, OnBox2Sealed)
	ON_UPDATE_COMMAND_UI(ID_BOX1_BANDPASS, OnUpdateBox1Bandpass)
	ON_UPDATE_COMMAND_UI(ID_BOX1_PORTED, OnUpdateBox1Ported)
	ON_UPDATE_COMMAND_UI(ID_BOX1_SEALED, OnUpdateBox1Sealed)
	ON_UPDATE_COMMAND_UI(ID_BOX2_BANDPASS, OnUpdateBox2Bandpass)
	ON_UPDATE_COMMAND_UI(ID_BOX2_PORTED, OnUpdateBox2Ported)
	ON_UPDATE_COMMAND_UI(ID_BOX2_SEALED, OnUpdateBox2Sealed)
	ON_COMMAND(ID_DRIVER1_NEW, OnDriver1New)
	ON_COMMAND(ID_DRIVER2_NEW, OnDriver2New)
	ON_COMMAND(ID_DRIVER1_OPEN, OnDriver1Open)
	ON_COMMAND(ID_DRIVER1_SAVE, OnDriver1Save)
	ON_COMMAND(ID_DRIVER2_OPEN, OnDriver2Open)
	ON_COMMAND(ID_DRIVER2_SAVE, OnDriver2Save)
	ON_COMMAND(ID_GRAPH_RELATIVERESPONSE, OnGraphRelativeresponse)
	ON_COMMAND(ID_GRAPH_COMPARATIVERESPONSE, OnGraphComparativeresponse)
	ON_COMMAND(ID_GRAPH_MAXIMUMSPL, OnGraphMaximumspl)
	ON_COMMAND(ID_GRAPH_PORTVELOCITY, OnGraphPortvelocity)
	ON_COMMAND(ID_GRAPH_POWER, OnGraphPower)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_RELATIVERESPONSE, OnUpdateGraphRelativeresponse)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_COMPARATIVERESPONSE, OnUpdateGraphComparativeresponse)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_MAXIMUMSPL, OnUpdateGraphMaximumspl)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_PORTVELOCITY, OnUpdateGraphPortvelocity)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_POWER, OnUpdateGraphPower)
	ON_COMMAND(ID_DRIVER2_CLEAR, OnDriver2Clear)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBox101App construction

CBox101App::CBox101App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	int i;
	
	for (i = 0; i <= 1; i++)
	{
		name[i] = "";
		fs[i] = 0;
		qes[i] = 0;
		qms[i] = 0;
		qts[i] = 0;
		vas[i] = 0;
		xmax[i] = 0;
		ref[i] = 0;
		diam[i] = 0;
		pe[i] = 0;
		s_vb[i] = 0;
		s_qtc[i] = 0;
		s_pm[i] = 0;
		s_nd[i] = 1;
		box[i] = 0;
		p_vb[i] = 0;
		p_fb[i] = 0;
		p_dv[i] = 0;
		p_lv[i] = 0;
		p_nv[i] = 1;
		p_pm[i] = 0;
		p_nd[i] = 1;
		b_vr[i] = 0;
		b_vf[i] = 0;
		b_fb[i] = 0;
		b_dv[i] = 0;
		b_lv[i] = 0;
		b_qtc[i] = 0;
		b_nv[i] = 1;
		b_pm[i] = 0;
		b_nd[i] = 1;
	}
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBox101App object

CBox101App theApp;

/////////////////////////////////////////////////////////////////////////////
// CBox101App initialization

BOOL CBox101App::InitInstance()
{	
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Nick Bartos Incorporated"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CBox101Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CBox101View));
	AddDocTemplate(pDocTemplate);

	// Enable DDE Execute open
	EnableShellOpen();
	RegisterShellFileTypes(FALSE);  //.101 I think

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	// Enable drag/drop open
	m_pMainWnd->DragAcceptFiles();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CBox101App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CBox101App commands

void CBox101App::OnBox1Bandpass() 
{
	// TODO: Add your command handler code here
	CBandpass1Dlg d;
	if (d.DoModal() == IDOK)
	{
		b_dv[0] = d.dv;
		b_fb[0] = d.fb;
		b_nd[0] = d.nd;
		b_nv[0] = d.nv;
		b_pm[0] = d.pm;
		b_vf[0] = d.vf;
		b_vr[0] = d.vr;	

		box[0] = 3;
		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnBox1Ported() 
{
	// TODO: Add your command handler code here
	CPorted1Dlg d;
	if (d.DoModal() == IDOK)
	{
		p_dv[0] = d.dv;
		p_fb[0] = d.fb;
		p_nd[0] = d.nd;
		p_nv[0] = d.nv;
		p_pm[0] = d.pm;
		p_vb[0] = d.vb;		

		box[0] = 2;
		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnBox1Sealed() 
{
	// TODO: Add your command handler code here
	CSealed1Dlg d;
	if (d.DoModal() == IDOK)
	{
		s_nd[0] = d.nd;
		s_pm[0] = d.pm;
		s_vb[0] = d.vb;
		
		box[0] = 1;
		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnBox2Bandpass() 
{
	// TODO: Add your command handler code here
	CBandpass2Dlg d;
	if (d.DoModal() == IDOK)
	{
		b_dv[1] = d.dv;
		b_fb[1] = d.fb;
		b_nd[1] = d.nd;
		b_nv[1] = d.nv;
		b_pm[1] = d.pm;
		b_vf[1] = d.vf;
		b_vr[1] = d.vr;	
		
		box[1] = 3;
		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnBox2Ported() 
{
	// TODO: Add your command handler code here
	CPorted2Dlg d;
	if (d.DoModal() == IDOK)
	{
		p_dv[1] = d.dv;
		p_fb[1] = d.fb;
		p_nd[1] = d.nd;
		p_nv[1] = d.nv;
		p_pm[1] = d.pm;
		p_vb[1] = d.vb;
		
		box[1] = 2;
		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnBox2Sealed() 
{
	// TODO: Add your command handler code here
	CSealed2Dlg d;
	if (d.DoModal() == IDOK)
	{
		s_nd[1] = d.nd;
		s_pm[1] = d.pm;
		s_vb[1] = d.vb;

		box[1] = 1;
		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnUpdateBox1Bandpass(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(box[0] == 3);
}

void CBox101App::OnUpdateBox1Ported(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(box[0] == 2);	
}

void CBox101App::OnUpdateBox1Sealed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(box[0] == 1);	
}

void CBox101App::OnUpdateBox2Bandpass(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(box[1] == 3);	
}

void CBox101App::OnUpdateBox2Ported(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(box[1] == 2);	
}

void CBox101App::OnUpdateBox2Sealed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(box[1] == 1);	
}

void CBox101App::OnDriver1New() 
{
	// TODO: Add your command handler code here
	CNewDriver1Dlg d;
	if (d.DoModal() == IDOK)
	{
		diam[0] = d.diam1;
		fs[0] = d.fs1;
		name[0] = d.name1;
		pe[0] = d.pe1;
		qes[0] = d.qes1;
		qms[0] = d.qms1;
		qts[0] = d.qts1;
		vas[0] = d.vas1;
		xmax[0] = d.xmax1;		
		
		if (qes[0] && qms[0] && !qts[0])
			qts[0] = (qes[0] * qms[0]) / (qes[0] + qms[0]);

		if (fs[0] && vas[0] && qes[0])
			ref[0] = 112 + 10 * log10l ((2.7e-8 * (powl (fs[0], 3) * vas[0])) / qes[0]);
		else
			ref[0] = 0;
		
		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnDriver2New() 
{
	// TODO: Add your command handler code here
	CNewDriver2Dlg d;
	if (d.DoModal() == IDOK)
	{
		diam[1] = d.diam1;
		fs[1] = d.fs1;
		name[1] = d.name1;
		pe[1] = d.pe1;
		qes[1] = d.qes1;
		qms[1] = d.qms1;
		qts[1] = d.qts1;
		vas[1] = d.vas1;
		xmax[1] = d.xmax1;	
		
		if (qes[1] && qms[1] && !qts[1])
			qts[1] = (qes[1] * qms[1]) / (qes[1] + qms[1]);

		if (fs[1] && vas[1] && qes[1])
			ref[1] = 112 + 10 * log10l ((2.7e-8 * (powl (fs[1], 3) * vas[1])) / qes[1]);
		else
			ref[1] = 0;
		
		m_pMainWnd->RedrawWindow();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBox101View

IMPLEMENT_DYNCREATE(CBox101View, CScrollView)

BEGIN_MESSAGE_MAP(CBox101View, CScrollView)
	//{{AFX_MSG_MAP(CBox101View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBox101View construction/destruction

CBox101View::CBox101View()
{
	// TODO: add construction code here
}

CBox101View::~CBox101View()
{
}

BOOL CBox101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
		
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBox101View drawing

void CBox101View::OnDraw(CDC* pDC)
{
	CBox101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	pDC->SetMapMode(MM_TEXT);

	float xscale = 1, yscale = 1;
	int i, pe2, pc[2];
	
	float a, b, c, d, e, g, h, y, y1, y2, f1, y4, y3, y5, k1, q1;

	float h2, a1, a2, a3, f9, x, f91, ref1, k, e1, e2;

	char buffer[7];
	
	if (pDC->IsPrinting())
	{
		xscale = 3.5;
		yscale = 3.5;		
	}

	CFont font1;
	font1.CreatePointFont(80, "MS Sans Serif", pDC);
	pDC->SelectObject(font1);
	
	CPen pen0(PS_SOLID, 1, RGB(0, 0, 0));
	CPen pen1(PS_SOLID, 1, RGB(255, 0, 0));
	CPen pen2(PS_SOLID, 1, RGB(0, 0, 255));

	pDC->SetTextColor(RGB (0, 0, 0));
	pDC->SelectObject(pen0);

	if (graph == 1)
	{
		pDC->TextOut(45 * xscale, 100 * yscale, "Relative Response");
		pDC->TextOut(5 * xscale, 259 * yscale, "dB");
		
		pDC->SetTextAlign(TA_RIGHT);		
		pDC->TextOut(42 * xscale, 110 * yscale, "+20");
		pDC->TextOut(42 * xscale, 140 * yscale, "+15");
		pDC->TextOut(42 * xscale, 169 * yscale, "+10");
		pDC->TextOut(42 * xscale, 199 * yscale, "+5");
		pDC->TextOut(42 * xscale, 229 * yscale, "0");
		pDC->TextOut(42 * xscale, 259 * yscale, "-5");
		pDC->TextOut(42 * xscale, 289 * yscale, "-10");
		pDC->TextOut(42 * xscale, 319 * yscale, "-15");
		pDC->TextOut(42 * xscale, 349 * yscale, "-20");
		pDC->TextOut(42 * xscale, 379 * yscale, "-25");
		pDC->SetTextAlign(TA_LEFT);
	}
	
	if (graph == 2)
	{
		pDC->TextOut(45 * xscale, 100 * yscale, "Comparative Response");
		pDC->TextOut(5 * xscale, 259 * yscale, "dB");
		
		pDC->SetTextAlign(TA_RIGHT);
		pDC->TextOut(42 * xscale, 110 * yscale, "115");
		pDC->TextOut(42 * xscale, 140 * yscale, "110");
		pDC->TextOut(42 * xscale, 169 * yscale, "105");
		pDC->TextOut(42 * xscale, 199 * yscale, "100");
		pDC->TextOut(42 * xscale, 229 * yscale, "95");
		pDC->TextOut(42 * xscale, 259 * yscale, "90");
		pDC->TextOut(42 * xscale, 289 * yscale, "85");
		pDC->TextOut(42 * xscale, 319 * yscale, "80");
		pDC->TextOut(42 * xscale, 349 * yscale, "75");
		pDC->TextOut(42 * xscale, 379 * yscale, "70");
		pDC->SetTextAlign(TA_LEFT);
	}

	if (graph == 3)
	{
		pDC->TextOut(45 * xscale, 100 * yscale, "Maximum SPL");
		pDC->TextOut(5 * xscale, 259 * yscale, "dB");
		
		pDC->SetTextAlign(TA_RIGHT);
		pDC->TextOut(42 * xscale, 110 * yscale, "135");
		pDC->TextOut(42 * xscale, 140 * yscale, "130");
		pDC->TextOut(42 * xscale, 169 * yscale, "125");
		pDC->TextOut(42 * xscale, 199 * yscale, "120");
		pDC->TextOut(42 * xscale, 229 * yscale, "115");
		pDC->TextOut(42 * xscale, 259 * yscale, "110");
		pDC->TextOut(42 * xscale, 289 * yscale, "105");
		pDC->TextOut(42 * xscale, 319 * yscale, "100");
		pDC->TextOut(42 * xscale, 349 * yscale, "95");
		pDC->TextOut(42 * xscale, 379 * yscale, "90");
		pDC->SetTextAlign(TA_LEFT);
	}

	if (graph == 4)
	{
		pDC->TextOut(45 * xscale, 100 * yscale, "Port Velocity");
		pDC->TextOut(5 * xscale, 259 * yscale, "%c");
		
		pDC->SetTextAlign(TA_RIGHT);
		pDC->TextOut(42 * xscale, 110 * yscale, "18");
		pDC->TextOut(42 * xscale, 140 * yscale, "16");
		pDC->TextOut(42 * xscale, 169 * yscale, "14");
		pDC->TextOut(42 * xscale, 199 * yscale, "12");
		pDC->TextOut(42 * xscale, 229 * yscale, "10");
		pDC->TextOut(42 * xscale, 259 * yscale, "8");
		pDC->TextOut(42 * xscale, 289 * yscale, "6");
		pDC->TextOut(42 * xscale, 319 * yscale, "4");
		pDC->TextOut(42 * xscale, 349 * yscale, "2");
		pDC->TextOut(42 * xscale, 379 * yscale, "0");
		pDC->SetTextAlign(TA_LEFT);
	}
	
	if (graph == 5)
	{
		pDC->TextOut(45 * xscale, 100 * yscale, "Power");
		pDC->TextOut(5 * xscale, 259 * yscale, "w");
		
		for (i = 0; i <= 1; i++)
		{
			pc[i] = 0;
			if (box[i] == 1)
				pc[i] = pe[i] * s_nd[i];
			if (box[i] == 2)
				pc[i] = pe[i] * p_nd[i];
			if (box[i] == 3)
				pc[i] = pe[i] * b_nd[i];
		}

		pe2 = max (pc[0], pc[1]);		
		
		pDC->SetTextAlign(TA_RIGHT);
		itoa(pe2 * 1.125, buffer, 10);
		pDC->TextOut(42 * xscale, 110 * yscale, buffer);
		itoa(pe2, buffer, 10);
		pDC->TextOut(42 * xscale, 140 * yscale, buffer);
		itoa(pe2 * .875, buffer, 10);
		pDC->TextOut(42 * xscale, 169 * yscale, buffer);
		itoa(pe2 * .75, buffer, 10);
		pDC->TextOut(42 * xscale, 199 * yscale, buffer);
		itoa(pe2 * .625, buffer, 10);
		pDC->TextOut(42 * xscale, 229 * yscale, buffer);
		itoa(pe2 * .5, buffer, 10);
		pDC->TextOut(42 * xscale, 259 * yscale, buffer);
		itoa(pe2 * .375, buffer, 10);
		pDC->TextOut(42 * xscale, 289 * yscale, buffer);
		itoa(pe2 * .25, buffer, 10);
		pDC->TextOut(42 * xscale, 319 * yscale, buffer);
		itoa(pe2 * .125, buffer, 10);
		pDC->TextOut(42 * xscale, 349 * yscale, buffer);
		pDC->TextOut(42 * xscale, 379 * yscale, "0");
		pDC->SetTextAlign(TA_LEFT);
	}

	for (i = 115; i <= 385; i += 30)
	{
		pDC->MoveTo(45 * xscale, i * yscale);
		pDC->LineTo(645 * xscale, i * yscale);
	}

	pDC->SetTextAlign(TA_CENTER);
	pDC->TextOut(345 * xscale, 405 * yscale, "hz");
	
	for (i = 10; i <= 100; i += 10)
	{
		f91 = 45 + 150 * log10l (i / 10) / log10l (2);
		pDC->MoveTo(f91 * xscale, 115 * yscale);
		pDC->LineTo(f91 * xscale, 385 * yscale);
		itoa(i, buffer, 10);
		pDC->TextOut(f91 * xscale, 390 * yscale, buffer); 
	}
	
	pDC->MoveTo(645 * xscale, 115 * yscale);
	pDC->LineTo(645 * xscale, 385 * yscale);
	pDC->TextOut (645 * xscale, 390 * yscale, "160");
	pDC->SetTextAlign(TA_LEFT);

	for (i = 0; i <= 1; i++)
	{
		if (i == 0)
		{
			pDC->SetTextColor(RGB (255, 0, 0));
			pDC->SelectObject(pen1);
			pDC->TextOut(5 * xscale, 5 * yscale, "Driver 1:");
			pDC->TextOut(175 * xscale, 5 * yscale, "Box 1:");
		}
		else
		{
			pDC->SetTextColor(RGB (0, 0, 255));
			pDC->SelectObject(pen2);
			pDC->TextOut(335 * xscale, 5 * yscale, "Driver 2:");
			pDC->TextOut(505 * xscale, 5 * yscale, "Box 2:");
		}		
				
		pDC->TextOut((55 + i * 330) * xscale, 5 * yscale, name[i]); 
	
		pDC->TextOut((5 + i * 330) * xscale, 20 * yscale, "Fs (hz):");
		gcvt(fs[i], 4, buffer);
		pDC->TextOut((55 + i * 330) * xscale, 20 * yscale, buffer);
 
		pDC->TextOut((5 + i * 330) * xscale, 35 * yscale, "Qes:");
		gcvt(qes[i], 4, buffer);
		pDC->TextOut((55 + i * 330) * xscale, 35 * yscale, buffer);

		pDC->TextOut((5 + i * 330) * xscale, 50 * yscale, "Qms:");
		gcvt(qms[i], 4, buffer);
		pDC->TextOut((55 + i * 330) * xscale, 50 * yscale, buffer);

		pDC->TextOut((5 + i * 330) * xscale, 65 * yscale, "Qts:");
		gcvt(qts[i], 4, buffer);
		pDC->TextOut((55 + i * 330) * xscale, 65 * yscale, buffer);

		pDC->TextOut((5 + i * 330) * xscale, 80 * yscale, "Vas (ft^3):");
		gcvt(vas[i], 4, buffer);
		pDC->TextOut((55 + i * 330) * xscale, 80 * yscale, buffer);

		pDC->TextOut((90 + i * 330) * xscale, 20 * yscale, "Xmax (in):");
		gcvt(xmax[i], 4, buffer);
		pDC->TextOut((140 + i * 330) * xscale, 20 * yscale, buffer);

		pDC->TextOut((90 + i * 330) * xscale, 35 * yscale, "Diam (in):");
		itoa(diam[i], buffer, 10);
		pDC->TextOut((140 + i * 330) * xscale, 35 * yscale, buffer);

		pDC->TextOut((90 + i * 330) * xscale, 50 * yscale, "Pe (w):");
		itoa(pe[i], buffer, 10);
		pDC->TextOut((140 + i * 330) * xscale, 50 * yscale, buffer);
	
		pDC->TextOut((90 + i * 330) * xscale, 65 * yscale, "Ref (db):");
		gcvt(ref[i], 4, buffer);
		pDC->TextOut((140 + i * 330) * xscale, 65 * yscale, buffer);
	
	
		if (box[i] == 1)
		{
			if (!s_vb[i] && vas[i] && qts[i])
				s_vb[i] = vas[i] * s_nd[i] / (powl (.707 / qts[i], 2) - 1);

			if (vas[i] && qts[i] && s_vb[i])
				s_qtc[i] = sqrtl (vas[i] * s_nd[i] / s_vb[i] + 1) * qts[i];
			else
				s_qtc[i] = 0;

			if (!s_pm[i] && pe[i])
				s_pm[i] = pe[i] * s_nd[i];
			
			pDC->TextOut((220 + i * 330) * xscale, 5 * yscale, "Sealed");
			
			pDC->TextOut((175 + i * 330) * xscale, 20 * yscale, "Vb (ft^3):");
			gcvt(s_vb[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 20 * yscale, buffer);
			
			pDC->TextOut((175 + i * 330) * xscale, 35 * yscale, "Qtc:");
			gcvt(s_qtc[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 35 * yscale, buffer);

			pDC->TextOut((175 + i * 330) * xscale, 50 * yscale, "Pm (w):");
			itoa(s_pm[i], buffer, 10);
			pDC->TextOut((220 + i * 330) * xscale, 50 * yscale, buffer);

			pDC->TextOut((175 + i * 330) * xscale, 65 * yscale, "Nd:");
			itoa(s_nd[i], buffer, 10);
			pDC->TextOut((220 + i * 330) * xscale, 65 * yscale, buffer);

			if (graph == 1 && fs[i] && qts[i] && vas[i] && s_vb[i])
			{
				h = 1e-20;
				a = vas[i] * s_nd[i] / s_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 10000 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 10000 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 10000 / h2;
				f1 = h2 * fs[i];
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y3 = 20 * log10l (y);
					y4 = 235 - y3 * 6;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}
			
			if (graph == 2 && fs[i] && qts[i] && vas[i] && s_vb[i] && ref[i])
			{
				h = 1e-20;
				a = vas[i] * s_nd[i] / s_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 10000 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 10000 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 10000 / h2;
				f1 = h2 * fs[i];
				ref1 = ref[i] + 10 * log10l (s_nd[i]);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y3 = 20 * log10l (y) + ref1;
					y4 = 805 - y3 * 6;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}

			if (graph == 3 && fs[i] && qts[i] && vas[i] && qes[i] && xmax[i]
				&& diam[i] && s_vb[i] && s_pm[i])
			{
				h = 1e-20;
				a = vas[i] * s_nd[i] / s_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 10000 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 10000 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 10000 / h2;
				f1 = h2 * fs[i];

				e = sqrtl (min(s_pm[i], pe[i] * s_nd[i]));
				k = sqrtl (vas[i] * s_nd[i] * powl (fs[i], 3) / qes[i]) / 753;
				k1 = .3535 * sqrtl (vas[i] * s_nd[i] / fs[i] / qes[i]) / powl (diam[i] - 2, 2);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y1 = y * sqrtl (powl (powl (x, 2) / h - 1, 2) + powl (x / 7, 2) / h) / powl
						(x, 4);
					e1 = xmax[i] * s_nd[i] / k1 / y1 / 39.37;
					e2 = min (e1, e);
					y3 = 20 * log10l (k * y * e2 * 50000);										
					y4 = 925 - y3 * 6;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}

			if (graph == 5 && fs[i] && qts[i] && vas[i] && qes[i] && xmax[i]
				&& diam[i] && s_vb[i] && ref[i] && pe2)
			{
				h = 1e-20;
				a = vas[i] * s_nd[i] / s_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 10000 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 10000 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 10000 / h2;
				f1 = h2 * fs[i];

				e = sqrtl (pe[i] * s_nd[i]);
				k1 = .3535 * sqrtl (vas[i] * s_nd[i] / fs[i] / qes[i]) / powl (diam[i] - 2, 2);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y1 = y * sqrtl (powl (powl (x, 2) / h - 1, 2) + powl (x / 7, 2) / h) / powl
						(x, 4);
					e1 = xmax[i] * s_nd[i] / k1 / y1 / 39.37;
					e2 = min (e1, e);
					y3 = powl (e2, 2);
					y4 = 385 - y3 / pe2 * 240;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}
		}
		
		if (box[i] == 2)
		{
			if (!p_vb[i] && qts[i] && vas[i])
				p_vb[i] = 20 * powl (qts[i], 3.3) * vas[i] * p_nd[i];

			if (!p_fb[i] && vas[i] && fs[i])
				p_fb[i] = powl (vas[i] * p_nd[i] / p_vb[i], .31) * fs[i];
			
			if (!p_dv[i] && xmax[i] && diam[i] && p_fb[i])
				p_dv[i] = ceil (39.37 * sqrtl (p_fb[i] * 5.1e-5 * powl ((diam[i] - 2) / 2, 2)
				* xmax[i] * p_nd[i]));

			if (p_vb[i] && p_dv[i] && p_fb[i])
				p_lv[i] = ((p_nv[i] * 3.14159 * powl (p_dv[i] / 2, 2)) / (1728 * p_vb[i]
				* powl (2 * 3.14159 * p_fb[i] / 13504, 2))) - (.825 * sqrtl (p_nv[i] *
				3.14159 * powl (p_dv[i] / 2, 2)));
			else
				p_lv[i] = 0;

			if (!p_pm[i] && pe[i])
				p_pm[i] = pe[i] * p_nd[i];
			
			pDC->TextOut((220 + i * 330) * xscale, 5 * yscale, "Ported");
		
			pDC->TextOut((175 + i * 330) * xscale, 20 * yscale, "Vb (ft^3):");
			gcvt(p_vb[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 20 * yscale, buffer);

			pDC->TextOut((175 + i * 330) * xscale, 35 * yscale, "Fb (hz):");
			gcvt(p_fb[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 35 * yscale, buffer);

			pDC->TextOut((175 + i * 330) * xscale, 50 * yscale, "Nv:");
			itoa(p_nv[i], buffer, 10);
			pDC->TextOut((220 + i * 330) * xscale, 50 * yscale, buffer);

			pDC->TextOut((175 + i * 330) * xscale, 65 * yscale, "Dv (in):");
			gcvt(p_dv[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 65 * yscale, buffer);
			
			pDC->TextOut((175 + i * 330) * xscale, 80 * yscale, "Lv (in):");
			gcvt(p_lv[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 80 * yscale, buffer);

			pDC->TextOut((255 + i * 330) * xscale, 20 * yscale, "Pm (w):");
			itoa(p_pm[i], buffer, 10);
			pDC->TextOut((295 + i * 330) * xscale, 20 * yscale, buffer);

			pDC->TextOut((255 + i * 330) * xscale, 35 * yscale, "Nd:");
			itoa(p_nd[i], buffer, 10);
			pDC->TextOut((295 + i * 330) * xscale, 35 * yscale, buffer);
			
			if (graph == 1 && fs[i] && qts[i] && vas[i] && p_vb[i] && p_fb[i])
			{
				h = p_fb[i] / fs[i];
				a = vas[i] * p_nd[i] / p_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 7 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 7 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 7 / h2;
				f1 = h2 * fs[i];
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y3 = 20 * log10l (y);
					y4 = 235 - y3 * 6;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}
			
			if (graph == 2 && fs[i] && qts[i] && vas[i] && ref[i] && p_vb[i] &&
				p_fb[i])
			{
				h = p_fb[i] / fs[i];
				a = vas[i] * p_nd[i] / p_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 7 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 7 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 7 / h2;
				f1 = h2 * fs[i];
				ref1 = ref[i] + 10 * log10l (p_nd[i]);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y3 = 20 * log10l (y) + ref1;
					y4 = 805 - y3 * 6;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}

			if (graph == 3 && fs[i] && qts[i] && vas[i] && qes[i] && xmax[i]
				&& diam[i] && p_vb[i] && p_fb[i] && p_pm[i])
			{
				h = p_fb[i] / fs[i];
				a = vas[i] * p_nd[i] / p_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 7 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 7 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 7 / h2;
				f1 = h2 * fs[i];

				e = sqrtl (min(p_pm[i], pe[i] * p_nd[i]));
				k = sqrtl (vas[i] * p_nd[i] * powl (fs[i], 3) / qes[i]) / 753;
				k1 = .3535 * sqrtl (vas[i] * p_nd[i] / fs[i] / qes[i]) / powl (diam[i] - 2, 2);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y1 = y * sqrtl (powl (powl (x, 2) / h - 1, 2) + powl (x / 7, 2) / h) / powl
						(x, 4);
					e1 = xmax[i] * p_nd[i] / k1 / y1 / 39.37;
					e2 = min (e1, e);
					y3 = 20 * log10l (k * y * e2 * 50000);										
					y4 = 925 - y3 * 6;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}
			
			if (graph == 4 && fs[i] && qts[i] && vas[i] && qes[i] && xmax[i]
				&& diam[i] && p_vb[i] && p_fb[i] && p_pm[i])
			{
				h = p_fb[i] / fs[i];
				a = vas[i] * p_nd[i] / p_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 7 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 7 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 7 / h2;
				f1 = h2 * fs[i];

				e = sqrtl (min(p_pm[i], pe[i] * p_nd[i]));
				k = sqrtl (vas[i] * p_nd[i] * powl (fs[i], 3) / qes[i]) / 753;
				k1 = .3535 * sqrtl (vas[i] * p_nd[i] / fs[i] / qes[i]) / powl (diam[i] - 2, 2);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y1 = y * sqrtl (powl (powl (x, 2) / h - 1, 2) + powl (x / 7, 2) / h) / powl
						(x, 4);
					e1 = xmax[i] * p_nd[i] / k1 / y1 / 39.37;
					e2 = min (e1, e);
					y2 = k * h2 * e2 * y / fs[i] / powl (x, 3);
					y3 = 485 * y2 / (p_nv[i] * powl (p_dv[i], 2));								
					y4 = 385 - y3 * 15;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}

			if (graph == 5 && fs[i] && qts[i] && vas[i] && qes[i] && xmax[i]
				&& diam[i] && p_vb[i] && p_fb[i] && ref[i])
			{
				h = p_fb[i] / fs[i];
				a = vas[i] * p_nd[i] / p_vb[i];
				h2 = sqrtl (h);
				a1 = h2 / 7 + 1 / qts[i] / h2;
				a2 = 1 / qts[i] / 7 + (a + 1 + powl (h, 2)) / h;
				a3 = h2 / qts[i] + 1 / 7 / h2;
				f1 = h2 * fs[i];

				e = sqrtl (pe[i] * p_nd[i]);
				k1 = .3535 * sqrtl (vas[i] * p_nd[i] / fs[i] / qes[i]) / powl (diam[i] - 2, 2);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					x = f9 / f1;
					y = powl (x, 4) / sqrtl (powl (powl (x, 4) - a2 * powl (x, 2) + 1, 2) + powl
						(a1 * powl (x, 3) - a3 * x, 2));
					y1 = y * sqrtl (powl (powl (x, 2) / h - 1, 2) + powl (x / 7, 2) / h) / powl
						(x, 4);
					e1 = xmax[i] * p_nd[i] / k1 / y1 / 39.37;
					e2 = min (e1, e);
					y3 = powl (e2, 2);
					y4 = 385 - y3 / pe2 * 240;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}
		}
	
		if (box[i] == 3)
		{
			if (qts[i] && fs[i])
			{
				f1 = (fs[i] + 10) * qts[i] / fs[i];
				q1 = sqrtl (f1 * (f1 + .7206));

				if (!b_fb[i])
					b_fb[i] = q1 * fs[0] / qts[0];
				if (!b_vf[i] && vas[i])
					b_vf[i] = powl (1.4 * qts[i], 2) * vas[i] * b_nd[i];
				if (!b_vr[i] && vas[i])
					b_vr[i] = vas[i] * b_nd[i] / (powl (q1 / qts[i], 2) - 1);
			}
			
			if (b_vf[i] && b_dv[i] && b_fb[i])
				b_lv[i] = ((b_nv[i] * 3.14159 * powl (b_dv[i] / 2, 2)) / (1728 * b_vf[i]
				* powl (2 * 3.14159 * b_fb[i] / 13504, 2))) - (.825 * sqrtl (b_nv[i] *
				3.14159 * powl (b_dv[i] / 2, 2)));
			else
				b_lv[i] = 0;

			if (b_vr[i] && vas[i] && qts[i])
				b_qtc[i] = sqrtl (vas[i] * b_nd[i] / b_vr[i] + 1) * qts[i];
			else
				b_qtc[i] = 0;
		
			if (!b_pm[i] && pe[i])
				b_pm[i] = pe[i] * b_nd[i];
			
			pDC->TextOut((220 + i * 330) * xscale, 5 * yscale, "Bandpass");
			
			pDC->TextOut((175 + i * 330) * xscale, 20 * yscale, "Vr (ft^3):");
			gcvt(b_vr[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 20 * yscale, buffer);
			
			pDC->TextOut((175 + i * 330) * xscale, 35 * yscale, "Qtc (Vr):");
			gcvt(b_qtc[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 35 * yscale, buffer);

			pDC->TextOut((175 + i * 330) * xscale, 50 * yscale, "Vf (ft^3):");
			gcvt(b_vf[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 50 * yscale, buffer);

			pDC->TextOut((175 + i * 330) * xscale, 65 * yscale, "Fb (hz):");
			gcvt(b_fb[i], 4, buffer);
			pDC->TextOut((220 + i * 330) * xscale, 65 * yscale, buffer);

			pDC->TextOut((175 + i * 330) * xscale, 80 * yscale, "Nv:");
			itoa(b_nv[i], buffer, 10);
			pDC->TextOut((220 + i * 330) * xscale, 80 * yscale, buffer);
		
			pDC->TextOut((255 + i * 330) * xscale, 20 * yscale, "Dv (in):");
			gcvt(b_dv[i], 4, buffer);
			pDC->TextOut((295 + i * 330) * xscale, 20 * yscale, buffer);
		
			pDC->TextOut((255 + i * 330) * xscale, 35 * yscale, "Lv (in):");
			gcvt(b_lv[i], 4, buffer);
			pDC->TextOut((295 + i * 330) * xscale, 35 * yscale, buffer);

			pDC->TextOut((255 + i * 330) * xscale, 50 * yscale, "Pm (w):");
			itoa(b_pm[i], buffer, 10);
			pDC->TextOut((295 + i * 330) * xscale, 50 * yscale, buffer);

			pDC->TextOut((255 + i * 330) * xscale, 65 * yscale, "Nd:");
			itoa(b_nd[i], buffer, 10);
			pDC->TextOut((295 + i * 330) * xscale, 65 * yscale, buffer);

			if (graph == 1 && fs[i] && qts[i] && vas[i] && b_vr[i] && b_vf[i]
				&& b_fb[i])
			{
				e = (vas[i] * b_nd[i] / b_vr[i] + 1) * powl (fs[i], 2);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					a = powl (b_fb[i], -2) * powl (f9, 4);
					b = ((1/10000 + (fs[i] / b_fb[i]) / qts[i]) / b_fb[i]) * 
						powl (f9, 3);
					c = (((1 + vas[i] * b_nd[i] / b_vr[i] + vas[i] * b_nd[i] / 
						b_vf[i]) * fs[i] / b_fb[i] + (1/ qts[i]) / 10000) *
						fs[i] / b_fb[i] + 1) * powl (f9, 2);
					d = ((1 / qts[i] + (fs[i] / b_fb[i]) / 10000 * (vas[i] *
						b_nd[i] / b_vr[i] + 1)) * fs[i]) * f9;
					g = a - c + e;
					h = -b + d;
					y = 20 * log10l (powl (f9, 2) / sqrtl (powl (g, 2) + powl (h, 2)));
					y4 = 235 - y * 6;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}
			
			if (graph == 2 && fs[i] && qts[i] && vas[i] && ref[i] && b_vr[i] &&
				b_vf[i] && b_fb[i])
			{
				e = (vas[i] * b_nd[i] / b_vr[i] + 1) * powl (fs[i], 2);
				y5 = 0;

				for (f9 = 10; f9 <= 160; f9 += .2)
				{
					a = powl (b_fb[i], -2) * powl (f9, 4);
					b = ((1/10000 + (fs[i] / b_fb[i]) / qts[i]) / b_fb[i]) * 
						powl (f9, 3);
					c = (((1 + vas[i] * b_nd[i] / b_vr[i] + vas[i] * b_nd[i] / 
						b_vf[i]) * fs[i] / b_fb[i] + (1/ qts[i]) / 10000) *
						fs[i] / b_fb[i] + 1) * powl (f9, 2);
					d = ((1 / qts[i] + (fs[i] / b_fb[i]) / 10000 * (vas[i] *
						b_nd[i] / b_vr[i] + 1)) * fs[i]) * f9;
					g = a - c + e;
					h = -b + d;
					y = 20 * log10l (powl (f9, 2) / sqrtl (powl (g, 2) + powl (h, 2)));
					y4 = 805 - (y + ref[i] + 10 * log10l (b_nd[i])) * 6;
					f91 = 45 + 150 * log10l (f9 / 10) / log10l (2);
					
					if (y5 <= 115 || y5 >= 385)
						pDC->MoveTo(f91 * xscale, y4 * yscale);

					if (y4 > 115 && y4 < 385)
						pDC->LineTo(f91 * xscale, y4 * yscale);

					y5 = y4;
				}
			}
		}		
	}
}

void CBox101View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = 665;
	sizeTotal.cy = 425;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CBox101View printing

BOOL CBox101View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CBox101View diagnostics

#ifdef _DEBUG
void CBox101View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CBox101View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CBox101Doc* CBox101View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBox101Doc)));
	return (CBox101Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBox101View message handlers

/////////////////////////////////////////////////////////////////////////////
// COpendriver1

IMPLEMENT_DYNAMIC(COpendriver1, CFileDialog)

COpendriver1::COpendriver1(BOOL bOpenFileDialog, LPCTSTR lpszDefExt, LPCTSTR lpszFileName,
		DWORD dwFlags, LPCTSTR lpszFilter, CWnd* pParentWnd) :
		CFileDialog(bOpenFileDialog, lpszDefExt, lpszFileName, dwFlags, lpszFilter, pParentWnd)
{
}

BEGIN_MESSAGE_MAP(COpendriver1, CFileDialog)
	//{{AFX_MSG_MAP(COpendriver1)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CBox101App::OnDriver1Open() 
{
	// TODO: Add your command handler code here
	
	COpendriver1 d(TRUE, "101", 0, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST |
		OFN_HIDEREADONLY, "Box 101 Driver Files (*.101)|*.101||");
	
	if (d.DoModal () == IDOK)
	{
		CString file_name = d.GetPathName();

		FILE *stream;
		char buffer[31];
		int i = -1;

		stream = fopen (file_name, "r");
		
		do
		{
			i++;
			(buffer[i]) = fgetc(stream);
		} while ((buffer[i]) != '\n');

		(buffer[i]) = '\0';

		name[0] = CString (buffer, strlen(buffer));
				
		fscanf(stream, "%f\n", &fs[0]);
		fscanf(stream, "%f\n", &qes[0]);
		fscanf(stream, "%f\n", &qms[0]);
		fscanf(stream, "%f\n", &qts[0]);
		fscanf(stream, "%f\n", &vas[0]);
		fscanf(stream, "%f\n", &xmax[0]);
		fscanf(stream, "%i\n", &diam[0]);
		fscanf(stream, "%i\n", &pe[0]);
		fscanf(stream, "%f\n", &ref[0]);
		
		fclose(stream);

		delete stream;

		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnDriver1Save() 
{
	// TODO: Add your command handler code here
	
	COpendriver1 d(FALSE, "101", 0, OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
		"Box 101 Driver Files (*.101)|*.101||");
	
	if (d.DoModal() == IDOK)
	{
		CString file_name = d.GetPathName();

		FILE *stream;

		stream = fopen (file_name, "w");
		
		fprintf(stream, "%s\n", name[0]);
		fprintf(stream, "%f\n", fs[0]);
		fprintf(stream, "%f\n", qes[0]);
		fprintf(stream, "%f\n", qms[0]);
		fprintf(stream, "%f\n", qts[0]);
		fprintf(stream, "%f\n", vas[0]);
		fprintf(stream, "%f\n", xmax[0]);
		fprintf(stream, "%i\n", diam[0]);
		fprintf(stream, "%i\n", pe[0]);
		fprintf(stream, "%f\n", ref[0]);

		fclose(stream);

		delete stream;
	}
}



void CBox101App::OnDriver2Open() 
{
	// TODO: Add your command handler code here
	
	COpendriver1 d(TRUE, "101", 0, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST |
		OFN_HIDEREADONLY, "Box 101 Driver Files (*.101)|*.101||");
	
	if (d.DoModal () == IDOK)
	{
		CString file_name = d.GetPathName();

		FILE *stream;
		char buffer[31];
		int i = -1;

		stream = fopen (file_name, "r");
		
		do
		{
			i++;
			(buffer[i]) = fgetc(stream);
		} while ((buffer[i]) != '\n');

		(buffer[i]) = '\0';

		name[1] = CString (buffer, strlen(buffer));
				
		fscanf(stream, "%f\n", &fs[1]);
		fscanf(stream, "%f\n", &qes[1]);
		fscanf(stream, "%f\n", &qms[1]);
		fscanf(stream, "%f\n", &qts[1]);
		fscanf(stream, "%f\n", &vas[1]);
		fscanf(stream, "%f\n", &xmax[1]);
		fscanf(stream, "%i\n", &diam[1]);
		fscanf(stream, "%i\n", &pe[1]);
		fscanf(stream, "%f\n", &ref[1]);

		fclose(stream);

		delete stream;

		m_pMainWnd->RedrawWindow();
	}
}

void CBox101App::OnDriver2Save() 
{
	// TODO: Add your command handler code here
	
	COpendriver1 d(FALSE, "101", 0, OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
		"Box 101 Driver Files (*.101)|*.101||");
	
	if (d.DoModal() == IDOK)
	{
		CString file_name = d.GetPathName();

		FILE *stream;

		stream = fopen (file_name, "w");
		
		fprintf(stream, "%s\n", name[1]);
		fprintf(stream, "%f\n", fs[1]);
		fprintf(stream, "%f\n", qes[1]);
		fprintf(stream, "%f\n", qms[1]);
		fprintf(stream, "%f\n", qts[1]);
		fprintf(stream, "%f\n", vas[1]);
		fprintf(stream, "%f\n", xmax[1]);
		fprintf(stream, "%i\n", diam[1]);
		fprintf(stream, "%i\n", pe[1]);
		fprintf(stream, "%f\n", ref[1]);

		fclose(stream);

		delete stream;
	}
}


void CBox101App::OnGraphRelativeresponse() 
{
	// TODO: Add your command handler code here
	graph = 1;

	m_pMainWnd->RedrawWindow();
}

void CBox101App::OnGraphComparativeresponse() 
{
	// TODO: Add your command handler code here
	graph = 2;

	m_pMainWnd->RedrawWindow();
}

void CBox101App::OnGraphMaximumspl() 
{
	// TODO: Add your command handler code here
	graph = 3;

	m_pMainWnd->RedrawWindow();
}

void CBox101App::OnGraphPortvelocity() 
{
	// TODO: Add your command handler code here
	graph = 4;

	m_pMainWnd->RedrawWindow();
}

void CBox101App::OnGraphPower() 
{
	// TODO: Add your command handler code here
	graph = 5;

	m_pMainWnd->RedrawWindow();
}


void CBox101App::OnUpdateGraphRelativeresponse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(graph == 1);	
}

void CBox101App::OnUpdateGraphComparativeresponse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(graph == 2);	
}

void CBox101App::OnUpdateGraphMaximumspl(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(graph == 3);	
}

void CBox101App::OnUpdateGraphPortvelocity(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(graph == 4);	
}

void CBox101App::OnUpdateGraphPower(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(graph == 5);	
}
/////////////////////////////////////////////////////////////////////////////
// CBandpass1Dlg dialog


CBandpass1Dlg::CBandpass1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBandpass1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBandpass1Dlg)
	dv = b_dv[0];
	fb = b_fb[0];
	nd = b_nd[0];
	nv = b_nv[0];
	pm = b_pm[0];
	vf = b_vf[0];
	vr = b_vr[0];
	//}}AFX_DATA_INIT
}


void CBandpass1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBandpass1Dlg)
	DDX_Text(pDX, IDE_B_DV1, dv);
	DDV_MinMaxFloat(pDX, dv, 0.f, 100.f);
	DDX_Text(pDX, IDE_B_FB1, fb);
	DDV_MinMaxFloat(pDX, fb, 0.f, 200.f);
	DDX_Text(pDX, IDE_B_ND1, nd);
	DDV_MinMaxInt(pDX, nd, 1, 8);
	DDX_Text(pDX, IDE_B_NV1, nv);
	DDV_MinMaxInt(pDX, nv, 1, 100);
	DDX_Text(pDX, IDE_B_PM1, pm);
	DDV_MinMaxInt(pDX, pm, 0, 10000);
	DDX_Text(pDX, IDE_B_VF1, vf);
	DDV_MinMaxFloat(pDX, vf, 0.f, 100.f);
	DDX_Text(pDX, IDE_B_VR1, vr);
	DDV_MinMaxFloat(pDX, vr, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBandpass1Dlg, CDialog)
	//{{AFX_MSG_MAP(CBandpass1Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBandpass1Dlg message handlers
/////////////////////////////////////////////////////////////////////////////
// CBandpass2Dlg dialog


CBandpass2Dlg::CBandpass2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBandpass2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBandpass2Dlg)
	dv = b_dv[1];
	fb = b_fb[1];
	nd = b_nd[1];
	nv = b_nv[1];
	pm = b_pm[1];
	vf = b_vf[1];
	vr = b_vr[1];
	//}}AFX_DATA_INIT
}


void CBandpass2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBandpass2Dlg)
	DDX_Text(pDX, IDE_B_DV2, dv);
	DDV_MinMaxFloat(pDX, dv, 0.f, 100.f);
	DDX_Text(pDX, IDE_B_FB2, fb);
	DDV_MinMaxFloat(pDX, fb, 0.f, 200.f);
	DDX_Text(pDX, IDE_B_ND2, nd);
	DDV_MinMaxInt(pDX, nd, 1, 8);
	DDX_Text(pDX, IDE_B_NV2, nv);
	DDV_MinMaxInt(pDX, nv, 1, 100);
	DDX_Text(pDX, IDE_B_PM2, pm);
	DDV_MinMaxInt(pDX, pm, 0, 10000);
	DDX_Text(pDX, IDE_B_VF2, vf);
	DDV_MinMaxFloat(pDX, vf, 0.f, 100.f);
	DDX_Text(pDX, IDE_B_VR2, vr);
	DDV_MinMaxFloat(pDX, vr, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBandpass2Dlg, CDialog)
	//{{AFX_MSG_MAP(CBandpass2Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBandpass2Dlg message handlers
/////////////////////////////////////////////////////////////////////////////
// CSealed1Dlg dialog


CSealed1Dlg::CSealed1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSealed1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSealed1Dlg)
	nd = s_nd[0];
	pm = s_pm[0];
	vb = s_vb[0];
	//}}AFX_DATA_INIT
}


void CSealed1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSealed1Dlg)
	DDX_Text(pDX, IDE_S_ND1, nd);
	DDV_MinMaxInt(pDX, nd, 1, 8);
	DDX_Text(pDX, IDE_S_PM1, pm);
	DDV_MinMaxInt(pDX, pm, 0, 10000);
	DDX_Text(pDX, IDE_S_VB1, vb);
	DDV_MinMaxFloat(pDX, vb, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSealed1Dlg, CDialog)
	//{{AFX_MSG_MAP(CSealed1Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSealed1Dlg message handlers
/////////////////////////////////////////////////////////////////////////////
// CSealed2Dlg dialog


CSealed2Dlg::CSealed2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSealed2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSealed2Dlg)
	nd = s_nd[1];
	pm = s_pm[1];
	vb = s_vb[1];
	//}}AFX_DATA_INIT
}


void CSealed2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSealed2Dlg)
	DDX_Text(pDX, IDE_S_ND2, nd);
	DDV_MinMaxInt(pDX, nd, 1, 8);
	DDX_Text(pDX, IDE_S_PM2, pm);
	DDV_MinMaxInt(pDX, pm, 0, 10000);
	DDX_Text(pDX, IDE_S_VB2, vb);
	DDV_MinMaxFloat(pDX, vb, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSealed2Dlg, CDialog)
	//{{AFX_MSG_MAP(CSealed2Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSealed2Dlg message handlers
/////////////////////////////////////////////////////////////////////////////
// CPorted1Dlg dialog


CPorted1Dlg::CPorted1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPorted1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPorted1Dlg)
	dv = p_dv[0];
	fb = p_fb[0];
	nd = p_nd[0];
	nv = p_nv[0];
	pm = p_pm[0];
	vb = p_vb[0];
	//}}AFX_DATA_INIT
}


void CPorted1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPorted1Dlg)
	DDX_Text(pDX, IDE_P_DV1, dv);
	DDV_MinMaxFloat(pDX, dv, 0.f, 100.f);
	DDX_Text(pDX, IDE_P_FB1, fb);
	DDV_MinMaxFloat(pDX, fb, 0.f, 200.f);
	DDX_Text(pDX, IDE_P_ND1, nd);
	DDV_MinMaxInt(pDX, nd, 1, 8);
	DDX_Text(pDX, IDE_P_NV1, nv);
	DDV_MinMaxInt(pDX, nv, 1, 100);
	DDX_Text(pDX, IDE_P_PM1, pm);
	DDV_MinMaxInt(pDX, pm, 0, 10000);
	DDX_Text(pDX, IDE_P_VB1, vb);
	DDV_MinMaxFloat(pDX, vb, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPorted1Dlg, CDialog)
	//{{AFX_MSG_MAP(CPorted1Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPorted1Dlg message handlers
/////////////////////////////////////////////////////////////////////////////
// CPorted2Dlg dialog


CPorted2Dlg::CPorted2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPorted2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPorted1Dlg)
	dv = p_dv[1];
	fb = p_fb[1];
	nd = p_nd[1];
	nv = p_nv[1];
	pm = p_pm[1];
	vb = p_vb[1];
	//}}AFX_DATA_INIT
}


void CPorted2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPorted1Dlg)
	DDX_Text(pDX, IDE_P_DV2, dv);
	DDV_MinMaxFloat(pDX, dv, 0.f, 100.f);
	DDX_Text(pDX, IDE_P_FB2, fb);
	DDV_MinMaxFloat(pDX, fb, 0.f, 200.f);
	DDX_Text(pDX, IDE_P_ND2, nd);
	DDV_MinMaxInt(pDX, nd, 1, 8);
	DDX_Text(pDX, IDE_P_NV2, nv);
	DDV_MinMaxInt(pDX, nv, 1, 100);
	DDX_Text(pDX, IDE_P_PM2, pm);
	DDV_MinMaxInt(pDX, pm, 0, 10000);
	DDX_Text(pDX, IDE_P_VB2, vb);
	DDV_MinMaxFloat(pDX, vb, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPorted2Dlg, CDialog)
	//{{AFX_MSG_MAP(CPorted2Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPorted2Dlg message handlers
/////////////////////////////////////////////////////////////////////////////
// CNewDriver1Dlg dialog


CNewDriver1Dlg::CNewDriver1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewDriver1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewDriver1Dlg)
	diam1 = diam[0];
	fs1 = fs[0];
	name1 = name[0];
	pe1 = pe[0];
	qes1 = qes[0];
	qms1 = qms[0];
	qts1 = qts[0];
	vas1 = vas[0];
	xmax1 = xmax[0];
	//}}AFX_DATA_INIT
}


void CNewDriver1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewDriver1Dlg)
	DDX_Text(pDX, IDE_DIAM1, diam1);
	DDV_MinMaxInt(pDX, diam1, 0, 100);
	DDX_Text(pDX, IDE_FS1, fs1);
	DDV_MinMaxFloat(pDX, fs1, 0.f, 200.f);
	DDX_Text(pDX, IDE_NAME1, name1);
	DDV_MaxChars(pDX, name1, 13);
	DDX_Text(pDX, IDE_PE1, pe1);
	DDV_MinMaxInt(pDX, pe1, 0, 2000);
	DDX_Text(pDX, IDE_QES1, qes1);
	DDV_MinMaxFloat(pDX, qes1, 0.f, 100.f);
	DDX_Text(pDX, IDE_QMS1, qms1);
	DDV_MinMaxFloat(pDX, qms1, 0.f, 100.f);
	DDX_Text(pDX, IDE_QTS1, qts1);
	DDV_MinMaxFloat(pDX, qts1, 0.f, 100.f);
	DDX_Text(pDX, IDE_VAS1, vas1);
	DDV_MinMaxFloat(pDX, vas1, 0.f, 1000.f);
	DDX_Text(pDX, IDE_XMAX1, xmax1);
	DDV_MinMaxFloat(pDX, xmax1, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewDriver1Dlg, CDialog)
	//{{AFX_MSG_MAP(CNewDriver1Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewDriver1Dlg message handlers
/////////////////////////////////////////////////////////////////////////////
// CNewDriver2Dlg dialog


CNewDriver2Dlg::CNewDriver2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewDriver2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewDriver2Dlg)
	diam1 = diam[1];
	fs1 = fs[1];
	name1 = name[1];
	pe1 = pe[1];
	qes1 = qes[1];
	qms1 = qms[1];
	qts1 = qts[1];
	vas1 = vas[1];
	xmax1 = xmax[1];
	//}}AFX_DATA_INIT
}


void CNewDriver2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewDriver2Dlg)
	DDX_Text(pDX, IDE_DIAM2, diam1);
	DDV_MinMaxInt(pDX, diam1, 0, 100);
	DDX_Text(pDX, IDE_FS2, fs1);
	DDV_MinMaxFloat(pDX, fs1, 0.f, 200.f);
	DDX_Text(pDX, IDE_NAME2, name1);
	DDV_MaxChars(pDX, name1, 13);
	DDX_Text(pDX, IDE_PE2, pe1);
	DDV_MinMaxInt(pDX, pe1, 0, 2000);
	DDX_Text(pDX, IDE_QES2, qes1);
	DDV_MinMaxFloat(pDX, qes1, 0.f, 100.f);
	DDX_Text(pDX, IDE_QMS2, qms1);
	DDV_MinMaxFloat(pDX, qms1, 0.f, 100.f);
	DDX_Text(pDX, IDE_QTS2, qts1);
	DDV_MinMaxFloat(pDX, qts1, 0.f, 100.f);
	DDX_Text(pDX, IDE_VAS2, vas1);
	DDV_MinMaxFloat(pDX, vas1, 0.f, 1000.f);
	DDX_Text(pDX, IDE_XMAX2, xmax1);
	DDV_MinMaxFloat(pDX, xmax1, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewDriver2Dlg, CDialog)
	//{{AFX_MSG_MAP(CNewDriver2Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewDriver2Dlg message handlers

void CBox101App::OnDriver2Clear() 
{
	// TODO: Add your command handler code here
	name[1] = "";
	fs[1] = 0;
	qes[1] = 0;
	qms[1] = 0;
	qts[1] = 0;
	vas[1] = 0;
	xmax[1] = 0;
	ref[1] = 0;
	diam[1] = 0;
	pe[1] = 0;
	s_vb[1] = 0;
	s_qtc[1] = 0;
	s_pm[1] = 0;
	s_nd[1] = 1;
	box[1] = 0;
	p_vb[1] = 0;
	p_fb[1] = 0;
	p_dv[1] = 0;
	p_lv[1] = 0;
	p_nv[1] = 1;
	p_pm[1] = 0;
	p_nd[1] = 1;
	b_vr[1] = 0;
	b_vf[1] = 0;
	b_fb[1] = 0;
	b_dv[1] = 0;
	b_lv[1] = 0;
	b_qtc[1] = 0;
	b_nv[1] = 1;
	b_pm[1] = 0;
	b_nd[1] = 1;

	m_pMainWnd->RedrawWindow();
}
