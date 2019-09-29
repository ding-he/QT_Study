#include "tcpsever.h"

TCPSever::TCPSever(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// ��ʼ��TCP Sever����
	m_pTcpClient = NULL;
	m_pTcpSever = new QTcpServer(this);

	// ����
	quint16 localPort = 7000;
	m_pTcpSever->listen(QHostAddress::Any, localPort);
	setWindowTitle(QStringLiteral("[Sever port : %1]").arg(localPort));

	// ��ʼ��ť������
	ui.buttonSend->setEnabled(false);

	// signal - slot
	connect(m_pTcpSever, &QTcpServer::newConnection, this, &TCPSever::NewTcpConnection);
	connect(ui.buttonSend, &QPushButton::clicked, this, &TCPSever::onButtonSendClicked);
	connect(ui.buttonExit, &QPushButton::clicked, this, &TCPSever::onButtonExitClicked);

}

TCPSever::~TCPSever()
{

}


void TCPSever::NewTcpConnection()
{
	// ȡ���ͻ�������
	m_pTcpClient = m_pTcpSever->nextPendingConnection();

	// �ͻ��˵�IP��port
	m_strIP = m_pTcpClient->peerAddress().toString();
	m_nPort = m_pTcpClient->peerPort();

	ui.textRecv->append(QStringLiteral("[%1 : %2] �ɹ�����...\n").arg(m_strIP).arg(m_nPort));

	ui.buttonSend->setEnabled(true);

	// ���������ź�
	connect(m_pTcpClient, &QTcpSocket::readyRead, this, &TCPSever::RecvTcpData);

}


void TCPSever::onButtonSendClicked()
{
	QString str;
	str = ui.textSend->toPlainText();
	// ��������
	m_pTcpClient->write(str.toUtf8());

	// ���
	ui.textSend->clear();
}


void TCPSever::onButtonExitClicked()
{
	if (m_pTcpClient != NULL)
	{
		m_pTcpClient->disconnectFromHost();
		ui.textRecv->append(QStringLiteral("[%1 : %2] �˳�����...\n").arg(m_strIP).arg(m_nPort));
	}
}


void TCPSever::RecvTcpData()
{
	// ��������
	QByteArray arr = m_pTcpClient->readAll();

	// ׷�ӵ���ʾ��
	ui.textRecv->append(QStringLiteral("[%1 : %2] %3\n").arg(m_strIP).arg(m_nPort).arg(QString(arr)));
}
