
// SCADAView.cpp : CSCADAView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "SCADA.h"
#endif

#include "SCADADoc.h"
#include "SCADAView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSCADAView

IMPLEMENT_DYNCREATE(CSCADAView, CView)

BEGIN_MESSAGE_MAP(CSCADAView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSCADAView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CSCADAView ����/����

CSCADAView::CSCADAView()
{
	// TODO: �ڴ˴���ӹ������

}

CSCADAView::~CSCADAView()
{
}

BOOL CSCADAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CSCADAView ����

void CSCADAView::OnDraw(CDC* /*pDC*/)
{
	CSCADADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CSCADAView ��ӡ


void CSCADAView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSCADAView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CSCADAView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CSCADAView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CSCADAView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSCADAView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSCADAView ���

#ifdef _DEBUG
void CSCADAView::AssertValid() const
{
	CView::AssertValid();
}

void CSCADAView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSCADADoc* CSCADAView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSCADADoc)));
	return (CSCADADoc*)m_pDocument;
}
#endif //_DEBUG


// CSCADAView ��Ϣ�������
