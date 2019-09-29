#ifndef CHESSDEMO_H
#define CHESSDEMO_H

#include <QtWidgets/QWidget>
#include "ui_chessdemo.h"

class ChessDemo : public QWidget
{
	Q_OBJECT

public:
	ChessDemo(QWidget *parent = 0);
	~ChessDemo();

private:
	// ���ӿ�� �߶�
	int m_nGridWidth;
	int m_nGridHeight;

	// �����������
	int m_nGridPosX;
	int m_nGridPosY;

	// �������
	int m_nClickedPosX;
	int m_nClickedPosY;

public:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	

private:
	Ui::ChessDemoClass ui;
};

#endif // CHESSDEMO_H
