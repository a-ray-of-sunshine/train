// CourseManage.cpp : implementation file
//

#include "stdafx.h"
#include "train.h"
#include "CourseManage.h"
#include "CourseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseManage dialog


CCourseManage::CCourseManage(CWnd* pParent /*=NULL*/)
	: CDialog(CCourseManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCourseManage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCourseManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCourseManage)
	DDX_Control(pDX, IDC_LIST1, m_CourseList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCourseManage, CDialog)
	//{{AFX_MSG_MAP(CCourseManage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourseManage message handlers

BOOL CCourseManage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CCourseSet *cs = new CCourseSet(reinterpret_cast<CTrainApp*>(AfxGetApp())->m_connector);
	cs->Open();

	LVCOLUMN col;
	col.mask = LVCF_TEXT | LVCF_WIDTH;
	
	// 设置列标题
	CODBCFieldInfo fieldinfo;
	for(int i = 0; i < (signed)cs->m_nFields; i++)
	{
		cs->GetODBCFieldInfo((short)i, fieldinfo);
		col.pszText = fieldinfo.m_strName.GetBuffer(fieldinfo.m_strName.GetLength());
		col.cx = lstrlen(col.pszText) * 10;
		this->m_CourseList.InsertColumn(i, &col);
	}

	// 设置每一列的数据
	TCHAR str[32];
	for(int j = 0; j < cs->GetRecordCount(); j++)
	{
		this->m_CourseList.InsertItem(j, _itot(cs->m_Course_ID, str, 10));
		this->m_CourseList.SetItemText(j, 1, cs->m_Subject);
		this->m_CourseList.SetItemText(j, 2, cs->m_Course_Cname);
		this->m_CourseList.SetItemText(j, 3, cs->m_Course_Ename);
		this->m_CourseList.SetItemText(j, 4, cs->m_Course_Desc);
		this->m_CourseList.SetItemText(j, 5, _itot(cs->m_Course_Duration, str, 10));
		this->m_CourseList.SetItemText(j, 6, cs->m_Course_Book);
		this->m_CourseList.SetItemText(j, 7, _itot(cs->m_Course_Equ, str, 10));
		this->m_CourseList.SetItemText(j, 8, _itot(cs->m_Course_Before, str, 10));
		this->m_CourseList.SetItemText(j, 9, _itot(cs->m_Course_Mark, str, 10));
		this->m_CourseList.SetItemText(j, 10, _itot(cs->m_Dept_ID, str, 10));
		cs->MoveNext();
	}
	
	cs->Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCourseManage::OnOK(void)
{

}