#include "writeexcel.h"
#include <QFileDialog>
#include <QAxObject>
#include <QtMath>

WriteExcel::WriteExcel(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//exportToExcel();
	testExcel();
}

WriteExcel::~WriteExcel()
{

}


void WriteExcel::testExcel()
{
	// �½�����
	QVector<int> vx;
	QVector<double> vy;

	// ����sinֵ
	for (int i = 0; i < 128; i++)
	{
		double x = 2 * M_PI * i / 128.0;
		double y = qSin(x);

		vx.push_back(i);
		vy.push_back(y);
	}

	exportCoordinateData(QString::fromLocal8Bit("�޵�.xlsx"), vx, vy);

}


template <typename T1, typename T2>
void WriteExcel::exportCoordinateData(QString path, QVector<T1> &x, QVector<T2> &y)
{
	// ·���ǿ�
	if (path.isEmpty() && !path.contains(".xlsx", Qt::CaseSensitive))
		return;

	QAxObject *excel = new QAxObject(this);
	if (excel == NULL)
		return;
	nullptr;

	// ����excel�ؼ�
	excel->setControl("Excel.Application");
	excel->dynamicCall("SetVisible (bool Visible)", "false");
	excel->setProperty("DisplayAlerts", false);

	// ��ȡ������
	QAxObject *workbooks = excel->querySubObject("WorkBooks");
	workbooks->dynamicCall("Add");

	// ��ȡ��ǰ������
	QAxObject *workbook = excel->querySubObject("ActiveWorkBook");
	QAxObject *worksheets = workbook->querySubObject("Sheets");
	// sheet1
	QAxObject *worksheet = worksheets->querySubObject("Item(int)", 1);

	// ��Ԫ��
	QAxObject *cellA, *cellB;

	// ���ñ���
	int cellrow = 1;
	QString A = "A" + QString::number(cellrow);
	QString B = "B" + QString::number(cellrow);
	cellA = worksheet->querySubObject("Range(QVariant, QVariant)", A);
	cellB = worksheet->querySubObject("Range(QVariant, QVariant)", B);
	cellA->dynamicCall("SetValue(const QVariant&)", QVariant("x"));
	cellB->dynamicCall("SetValue(const QVariant&)", QVariant("y"));
	cellrow++;

	for (QVector<double>::size_type ix = 0; ix != x.size(); ix++)
	{
		A = "A" + QString::number(cellrow);
		B = "B" + QString::number(cellrow);

		// ��ȡ��Ԫ��
		cellA = worksheet->querySubObject("Range(QVariant, QVariant)", A);
		cellB = worksheet->querySubObject("Range(QVariant, QVariant)", B);

		// ���õ�Ԫ���ֵ
		cellA->dynamicCall("SetValue(const QVariant&)", QVariant(x[ix]));
		cellB->dynamicCall("SetValue(const QVariant&)", QVariant(y[ix]));
		cellrow++;
	}
	
	// ���沢�ر�
	workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(path));
	workbook->dynamicCall("Close()");
	excel->dynamicCall("Quit()");

	delete excel;
}


bool WriteExcel::exportToExcel()
{
	QString filepath = QFileDialog::getSaveFileName(this, tr("Save orbit"), ".", tr("Microsoft Office 2007 (*.xlsx)"));//��ȡ����·��
	if (!filepath.isEmpty()){
		QAxObject *excel = new QAxObject(this);
		excel->setControl("Excel.Application");//����Excel�ؼ�
		excel->dynamicCall("SetVisible (bool Visible)", "false");//����ʾ����
		excel->setProperty("DisplayAlerts", false);//����ʾ�κξ�����Ϣ�����Ϊtrue��ô�ڹر��ǻ�������ơ��ļ����޸ģ��Ƿ񱣴桱����ʾ

		QAxObject *workbooks = excel->querySubObject("WorkBooks");//��ȡ����������
		workbooks->dynamicCall("Add");//�½�һ��������
		QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//��ȡ��ǰ������
		QAxObject *worksheets = workbook->querySubObject("Sheets");//��ȡ��������
		QAxObject *worksheet = worksheets->querySubObject("Item(int)", 1);//��ȡ�������ϵĹ�����1����sheet1

		QAxObject *cellA, *cellB, *cellC, *cellD;

		//���ñ���
		int cellrow = 1;
		QString A = "A" + QString::number(cellrow);//����Ҫ�����ĵ�Ԫ����A1
		QString B = "B" + QString::number(cellrow);
		QString C = "C" + QString::number(cellrow);
		QString D = "D" + QString::number(cellrow);
		cellA = worksheet->querySubObject("Range(QVariant, QVariant)", A);//��ȡ��Ԫ��
		cellB = worksheet->querySubObject("Range(QVariant, QVariant)", B);
		cellC = worksheet->querySubObject("Range(QVariant, QVariant)", C);
		cellD = worksheet->querySubObject("Range(QVariant, QVariant)", D);
		cellA->dynamicCall("SetValue(const QVariant&)", QVariant(QString::fromLocal8Bit("��ˮ��")));//���õ�Ԫ���ֵ
		cellB->dynamicCall("SetValue(const QVariant&)", QVariant(QString::fromLocal8Bit("�û���")));
		cellC->dynamicCall("SetValue(const QVariant&)", QVariant(QString::fromLocal8Bit("���")));
		cellD->dynamicCall("SetValue(const QVariant&)", QVariant(QString::fromLocal8Bit("����")));
		cellrow++;

		int rows = 12;
		for (int i = 0; i < rows; i++){
			QString A = "A" + QString::number(cellrow);//����Ҫ�����ĵ�Ԫ����A1
			QString B = "B" + QString::number(cellrow);
			QString C = "C" + QString::number(cellrow);
			QString D = "D" + QString::number(cellrow);
			cellA = worksheet->querySubObject("Range(QVariant, QVariant)", A);//��ȡ��Ԫ��
			cellB = worksheet->querySubObject("Range(QVariant, QVariant)", B);
			cellC = worksheet->querySubObject("Range(QVariant, QVariant)", C);
			cellD = worksheet->querySubObject("Range(QVariant, QVariant)", D);
			cellA->dynamicCall("SetValue(const QVariant&)", QVariant(1));//���õ�Ԫ���ֵ
			cellB->dynamicCall("SetValue(const QVariant&)", QVariant(2));
			cellC->dynamicCall("SetValue(const QVariant&)", QVariant(3));
			cellD->dynamicCall("SetValue(const QVariant&)", QVariant(4));
			cellrow++;
		}

		workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filepath));//������filepath��ע��һ��Ҫ��QDir::toNativeSeparators��·���е�"/"ת��Ϊ"\"����Ȼһ�����治�ˡ�
		workbook->dynamicCall("Close()");//�رչ�����
		excel->dynamicCall("Quit()");//�ر�excel
		delete excel;
		excel = NULL;
	}
	return true;
}
